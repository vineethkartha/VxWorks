/*
TODO -	Remove the template modification history and begin a new history
	starting with version 01a and growing the history upward with
	each revision.

*/

#include "vxWorks.h"

#include "LPC2148timer.h"
//#include "drv/timer/timestampDev.h"

/* defines */

#define TIMESTAMP_HZ	1000000			 /* timestamp counter freq */

/* The default is to assume memory mapped I/O */

#ifndef LPC_READ
#define LPC_READ(reg, result) \
	(result = *reg)
#endif /*TEMPLATE_READ*/

#ifndef LPC_WRITE
#define LPC_WRITE(reg, data) \
	(*reg = data)
#endif /*TEMPLATE_WRITE*/

#define SYS_CLK_RATE_MIN 50
#define SYS_CLK_RATE_MAX 100
typedef void (*CLK_FUNCPTR) (int arg);
/* locals */
LOCAL CLK_FUNCPTR	timerRoutine [2]; /* timers interruption routine     */
LOCAL int       timerArg [2];		 /* timers interruption routine arg */
LOCAL BOOL      timerConnected [2] = {FALSE, FALSE}; /* timers IT connected */
LOCAL BOOL      timerRunning [2] = {FALSE, FALSE};   /* timers enabled	    */
LOCAL int       timerTicksPerSecond [2] = {50,50};
LOCAL FUNCPTR sysClkRoutine	= NULL; /* routine to call on clock tick */
LOCAL int sysClkArg		= 0; /* its argument */
LOCAL BOOL sysClkRunning	= FALSE;
LOCAL int sysClkTicksPerSecond	= 60;

LOCAL FUNCPTR sysAuxClkRoutine	= NULL;
LOCAL int sysAuxClkArg		= 0;
LOCAL BOOL sysAuxClkRunning	= FALSE;
LOCAL int sysAuxClkTicksPerSecond = 100;

#ifdef INCLUDE_TIMESTAMP

LOCAL BOOL	sysTimestampRunning	= FALSE; /* running flag */
LOCAL int	sysTimestampPeriodValue	= 0;	 /* Max counter value */
LOCAL FUNCPTR	sysTimestampRoutine	= NULL;  /* routine to call on intr */
LOCAL int	sysTimestampArg		= 0;     /* arg for routine */

      void	sysTimestampInt (void);		 /* forward declaration */

#endif  /* INCLUDE_TIMESTAMP */


/*******************************************************************************
*
* sysClkInt - interrupt level processing for system clock
*
* This routine handles an auxiliary clock interrupt.  It acknowledges the
* interrupt and calls the routine installed by sysClkConnect().
*/

void sysClkInt (void)
    {
    /* TODO - acknowledge the interrupt if needed */

    /* call system clock service routine */

    if (sysClkRoutine != NULL)
	(* sysClkRoutine) (sysClkArg);
    }


/*******************************************************************************
*
* sysClkConnect - connect a routine to the system clock interrupt
*
* This routine specifies the interrupt service routine to be called at each
* clock interrupt.  Normally, it is called from usrRoot() in usrConfig.c to 
* connect usrClock() to the system clock interrupt.
*
* RETURN: OK, or ERROR if the routine cannot be connected to the interrupt.
*
* SEE ALSO: intConnect(), usrClock(), sysClkEnable()
*/

STATUS sysClkConnect(FUNCPTR routine,int arg)
    {
    static BOOL beenHere = FALSE;
    int key;
    key=intCpuLock();
    intCpuUnlock(key);

    return (OK);
    }


/*******************************************************************************
*
* sysClkDisable - turn off system clock interrupts
*
* This routine disables system clock interrupts.
*
* RETURNS: N/A
*
* SEE ALSO: sysClkEnable()
*/

void sysClkDisable (void)
    {
    if (sysClkRunning)
	{
	/* TODO - disable system timer interrupts */
	
	sysClkRunning = FALSE;
	}
    }


/*******************************************************************************
*
* sysClkEnable - turn on system clock interrupts
*
* This routine enables system clock interrupts.
*
* RETURNS: N/A
*
* SEE ALSO: sysClkConnect(), sysClkDisable(), sysClkRateSet()
*/

void sysClkEnable (void)
    {
    static BOOL connected = FALSE;

    if (!connected)
	{
	/* TODO - connect sysClkInt to appropriate interrupt */

	connected = TRUE;
	}

    if (!sysClkRunning)
	{
	/*
	 * TODO - start system timer interrupts at a
	 * at a frequency of sysClkTicksPerSecond
	 */
	
	sysClkRunning = TRUE;
	}
    }


/*******************************************************************************
*
* sysClkRateGet - get the system clock rate
*
* This routine returns the system clock rate.
*
* RETURNS: The number of ticks per second of the system clock.
*
* SEE ALSO: sysClkEnable(), sysClkRateSet()
*/

int sysClkRateGet (void)
    {
    return (sysClkTicksPerSecond);
    }


/*******************************************************************************
*
* sysClkRateSet - set the system clock rate
*
* This routine sets the interrupt rate of the system clock.
* It is called by usrRoot() in usrConfig.c.
*
* RETURNS: OK, or ERROR if the tick rate is invalid or the timer cannot be set.
*
* SEE ALSO: sysClkEnable(), sysClkRateGet()
*/

STATUS sysClkRateSet
    (
    int ticksPerSecond	    /* number of clock interrupts per second */
    )
    {
    if (ticksPerSecond < SYS_CLK_RATE_MIN || ticksPerSecond > SYS_CLK_RATE_MAX)
	return (ERROR);

    /* TODO - return ERROR if rate is not supported */

    sysClkTicksPerSecond = ticksPerSecond;

    if (sysClkRunning)
	{
	sysClkDisable ();
	sysClkEnable ();
	}

    return (OK);
    }


#ifdef  INCLUDE_TIMESTAMP

/*
 * TODO - This is an example timestamp driver.  It must be modified to
 * work with the specific hardware in use.  There is an application note
 * on creating a timestamp driver that is very useful.
 */

/*******************************************************************************
*
* sysTimestampInt - timestamp timer interrupt handler
*
* This rountine handles the timestamp timer interrupt.  A user routine is
* called, if one was connected by sysTimestampConnect().
*
* RETURNS: N/A
*
* SEE ALSO: sysTimestampConnect()
*/

void sysTimestampInt (void)
    {
    if (sysTimestampRunning && sysTimestampRoutine != NULL)
	(*sysTimestampRoutine)(sysTimestampArg);
    }

/*******************************************************************************
*
* sysTimestampConnect - connect a user routine to the timestamp timer interrupt
*
* This routine specifies the user interrupt routine to be called at each
* timestamp timer interrupt.  It does not enable the timestamp timer itself.
*
* RETURNS: OK, or ERROR if sysTimestampInt() interrupt handler is not used.
*/

STATUS sysTimestampConnect
    (
    FUNCPTR routine,    /* routine called at each timestamp timer interrupt */
    int arg     /* argument with which to call routine */
    )
    {
    sysTimestampRoutine = NULL;
    sysTimestampArg = arg;
    sysTimestampRoutine = routine;

    return OK;
    }

/*******************************************************************************
*
* sysTimestampEnable - initialize and enable the timestamp timer
*
* This routine connects the timestamp timer interrupt and initializes the
* counter registers.  If the timestamp timer is already running, this routine
* merely resets the timer counter.
*
* The rate of the timestamp timer should be set explicitly within the BSP,
* in the sysHwInit() routine.  This routine does not intialize the timer
* rate.
*
* RETURNS: OK, or ERROR if hardware cannot be enabled.
*/

STATUS sysTimestampEnable (void)
    {
    static BOOL connected = FALSE;

    if (!connected)
	{
	/* TODO - connect sysTimestampInt to the appropriate interrupt */

	connected = TRUE;
	}

    if (!sysTimestampRunning)
	{
	/* TODO - setup the counter registers and start the counter */

	sysTimestampRunning = TRUE;
	}

    return (OK);
    }

/*******************************************************************************
*
* sysTimestampDisable - disable the timestamp timer
*
* This routine disables the timestamp timer.  Interrupts are not disabled,
* although the tick counter will not increment after the timestamp timer
* is disabled, thus interrupts will no longer be generated.
*
* RETURNS: OK, or ERROR if timer cannot be disabled.
*/

STATUS sysTimestampDisable (void)
    {
    if (sysTimestampRunning)
        sysTimestampRunning = FALSE;

    return (OK);
    }

/*******************************************************************************
*
* sysTimestampPeriod - get the timestamp timer period
*
* This routine returns the period of the timestamp timer in ticks.
* The period, or terminal count, is the number of ticks to which the timestamp
* timer will count before rolling over and restarting the counting process.
*
* RETURNS: The period of the timestamp timer in counter ticks.
*/

UINT32 sysTimestampPeriod (void)
    {
    /* TODO - this is example code, it must be replaced. */

    sysTimestampPeriodValue = TIMESTAMP_HZ / sysClkTicksPerSecond;

    return (sysTimestampPeriodValue);
    }

/*******************************************************************************
*
* sysTimestampFreq - get the timestamp timer clock frequency
*
* This routine returns the frequency of the timer clock, in ticks per second.
*
* RETURNS: The timestamp timer clock frequency, in ticks per second.
*/

UINT32 sysTimestampFreq (void)
    {
    /* TODO - this is example code, it must be replaced. */

    return (TIMESTAMP_HZ);
    }

/*******************************************************************************
*
* sysTimestamp - get the timestamp timer tick count
*
* This routine returns the current value of the timestamp timer tick counter.
* The tick count can be converted to seconds by dividing by the return of
* sysTimestampFreq().
*
* This routine should be called with interrupts locked.  If interrupts are
* not already locked, sysTimestampLock() should be used instead.
*
* RETURNS: The current timestamp timer tick count.
*
* SEE ALSO: sysTimestampLock()
*/

UINT32 sysTimestamp (void)
    {
    UINT32 count = 0;

    /* TODO - read the timestamp timer value */

    return (count);
    }

/*******************************************************************************
*
* sysTimestampLock - get the timestamp timer tick count
*
* This routine returns the current value of the timestamp timer tick counter.
* The tick count can be converted to seconds by dividing by the return of
* sysTimestampFreq().
*
* This routine locks interrupts for cases where it is necessary to stop the
* tick counter in order to read it, or when two independent counters must
* be read.  If interrupts are already locked, sysTimestamp() should be
* used instead.
*
* RETURNS: The current timestamp timer tick count.
*
* SEE ALSO: sysTimestamp()
*/

UINT32 sysTimestampLock (void)
    {
    UINT32 result;
    int oldLevel;

    /*
     * TODO - If interrupt lockout is not needed, then don't do it. Just
     * return the value from sysTimestamp().
     */

    oldLevel = intLock ();

    result = sysTimestamp ();

    intUnlock (oldLevel);

    return (result);
    }

#endif  /* INCLUDE_TIMESTAMP */