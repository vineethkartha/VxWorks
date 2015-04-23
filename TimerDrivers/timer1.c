
#include "vxWorks.h"
#include <stdio.h>
#include "sysLib.h"
#include "intLib.h"
#include "taskLib.h"
#include <private/vxsimHostLibP.h>
#include<time.h>

#define	SYS_VIRTUAL_TIME 0	/* 1=sys is virtual, 0=strict realtime  */
#define	AUX_VIRTUAL_TIME 0

#define SYS_CLK_RATE_DEFAULT	50
#define AUX_CLK_RATE_DEFAULT	50
#define SYS_CLK_RATE_MIN 10
#define SYS_CLK_RATE_MAX 100
#define SIG_ALARM 0

typedef void (*CLK_FUNCPTR) (int arg);

LOCAL CLK_FUNCPTR	timerRoutine; /* timers interruption routine     */
LOCAL int       timerArg;		 /* timers interruption routine arg */
LOCAL BOOL      timerConnected = FALSE; /* timers IT connected */
LOCAL BOOL      timerRunning =FALSE;   /* timers enabled	    */

LOCAL BOOL Running=FALSE;
LOCAL FUNCPTR ClkRtn	= NULL; 
LOCAL int sysClkArg		= 0;
LOCAL   UINT32	tps = 50;
LOCAL BOOL	timerIsInitialized = FALSE;

time_t currTime;
struct tm *localTime;

void unixTimerInit (void)
    {
    	if (!timerIsInitialized)
    	{
    		vxsimHostTimerInit (SYS_VIRTUAL_TIME, AUX_VIRTUAL_TIME);
    		timerIsInitialized = TRUE;
    	}
    	else
    		printf("\ntimer is already initialised\n");
    }

void sysClkInt (int src)
{
	CLK_FUNCPTR	clkRtn = NULL;	/* clock handler */
	int clkArg = 0;	/* clock handler argument */
	if (src == SIG_ALARM)
	{
	   	clkRtn = timerRoutine;
	   	clkArg = timerArg;
	}
	if (ClkRtn != NULL)
		(* ClkRtn) (sysClkArg);
}

void sysClkEnable (void)
{
    unixTimerInit ();
    if (!timerRunning)
    {
    	vxsimHostTimerEnable(0,tps);
    	timerRunning = TRUE;
	}
}

void sysClkDisable (void)
{
   	if (timerRunning)
   	{
   		
   		vxsimHostTimerDisable (0);
   		timerRunning = FALSE;
   	}
}

STATUS sysClkRateSet(int ticksPerSecond)
{
    BOOL running = FALSE;
    if (ticksPerSecond < SYS_CLK_RATE_MIN || ticksPerSecond > SYS_CLK_RATE_MAX)
    	return (ERROR);
    tps = ticksPerSecond;
    running = timerRunning;
    if (running)
	{
    	sysClkDisable ();		
    	sysClkEnable ();		
	}
    return (OK);
}

int sysClkRateGet()
{
	return tps;
}
STATUS sysClkConnect(FUNCPTR routine,int arg)
{
	int key;
	key = intCpuLock ();
	timerRoutine = (CLK_FUNCPTR)routine;    
	timerArg = arg;
	return OK;
}