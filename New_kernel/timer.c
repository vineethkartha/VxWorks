    /* sampleCTimer.c - sample C timer library */ 
     
    /* Copyright 1994 Wind River Systems, Inc. */ 
    #include "copyright_wrs.h" 
     
    /* 
    modification history 
    -------------------- 
    01a,23mar94,dzb  written. 
    */ 
     
    /* 
    DESCRIPTION 
    This library contains sample routines to manipulate the timer functions on 
    the sample C chip with a board-independent interface.  This library handles 
    the timestamp timer facility. 
     
    To include the timestamp timer facility, the macro INCLUDE_TIMESTAMP must be 
    defined.

    NOTE:  This module provides an example of a VxWorks timestamp timer driver 
    implemented by reading the system clock timer counter.  It illustrates the 
    structures and routines discussed in the Appendix, "Creating a VxWorks 
    Timestamp Driver."  This module is only a template. In its current form,  
    it will not compile. 
    */ 
     
    #ifdef  INCLUDE_TIMESTAMP 
     
    #include "drv/timer/timestampDev.h" 
    #include "drv/timer/sampleCTimer.h" 
     
    /* Locals */  
     
    LOCAL BOOL    sysTimestampRunning = FALSE;      /* running flag */ 
     
    /*************************************************************************** 
    *     * sysTimestampConnect - connect a user routine to the timestamp timer 
    *                         interrupt 
    * 
    * This routine specifies the user interrupt routine to be called at each 
    * timestamp timer interrupt.  It does not enable the timestamp timer itself. 
    * 
    * RETURNS: OK, or ERROR if sysTimestampInt() interrupt handler is not used. 
    */ 
      
    STATUS sysTimestampConnect 
        ( 
        FUNCPTR routine,    /* routine called at each timestamp timer interrupt */ 
        int arg             /* argument with which to call routine */ 
        ) 
        { 
        /* ERROR indicates that the system clock tick specifies a rollover event */ 
     
        return (ERROR); 
        } 
     
    /*************************************************************************** 
    * 
    * sysTimestampEnable - initialize and enable the timestamp timer 
    * 
    * This routine connects the timestamp timer interrupt and initializes the 
    * counter registers.  If the timestamp timer is already running, this routine 
    * merely resets the timer counter. 
    * 
    * Set the rate of the timestamp timer input clock explicitly within the 
    * BSP, in the sysHwInit() routine.  This routine does not initialize 
    * the timer clock rate. 
    * 
    * RETURNS: OK, or ERROR if the timestamp timer cannot be enabled. 
    */

    STATUS sysTimestampEnable (void) 
        { 
        if (sysTimestampRunning) 
            return (OK); 
         
        sysTimestampRunning = TRUE; 
     
        sysClkEnable ();            /* ensure the system clock is running */ 
      
        return (OK); 
        } 
     
    /*************************************************************************** 
    * sysTimestampDisable - disable the timestamp timer 
    * 
    * This routine disables the timestamp timer.  Interrupts are not disabled. 
    * However, the tick counter does not increment after the timestamp timer 
    * is disabled, ensuring that interrupts are no longer generated. 
    * 
    * RETURNS: OK, or ERROR if the timestamp timer cannot be disabled. 
    */ 
      
    STATUS sysTimestampDisable (void) 
        { 
        sysTimestampRunning = FALSE; 
     
        return (ERROR); 
        } 
     
    /*************************************************************************** 
    * 
    * sysTimestampPeriod - get the timestamp timer period 
    * 
    * This routine returns the period of the timer in timestamp ticks. 
    * The period, or terminal count, is the number of ticks to which the 
    * timestamp timer counts before rolling over and restarting the counting 
    * process. 
    * 
    * RETURNS: The period of the timer in timestamp ticks. 
    */ 
      
    UINT32 sysTimestampPeriod (void) 
        { 
        /* return the system clock period in timestamp ticks */ 
     
        return (sysTimestampFreq ()/sysClkRateGet ())        
        } 
     
    /*************************************************************************** 
    * 
    * sysTimestampFreq - get the timestamp timer clock frequency 
    * 
    * This routine returns the frequency of the timer clock, in ticks per second. 
    * The rate of the timestamp timer should be set explicitly in the BSP, 
    * in the sysHwInit() routine. 
    * 
    * RETURNS: The timestamp timer clock frequency, in ticks per second. 
    */ 
      
    UINT32 sysTimestampFreq (void) 
        { 
        UINT32 timerFreq; 
     
        /* 
         * Return the timestamp tick output frequency here. 
         * This value can be determined from the following equation: 
         *     timerFreq = clock input frequency / prescaler 
         *  
         * When possible, read the clock input frequency and prescaler values 
         * directly from chip registers. 
         */ 
      
        return (timerFreq); 
        } 
     
    /*************************************************************************** 
    * 
    * sysTimestamp - get the timestamp timer tick count 
    * 
    * This routine returns the current value of the timestamp timer tick counter. 
    * The tick count can be converted to seconds by dividing by the return of 
    * sysTimestampFreq(). 
    * 
    * Call this routine with interrupts locked.  If interrupts are 
    * not already locked, use sysTimestampLock() instead. 
    * 
    * RETURNS: The current timestamp timer tick count. 
    * SEE ALSO: sysTimestampLock() 
    */ 
      
    UINT32 sysTimestamp (void) 
        { 
        /* return the system clock timer tick count here */ 
        } 
     
    /*************************************************************************** 
    * 
    * sysTimestampLock - get the timestamp timer tick count 
    * 
    * This routine returns the current value of the timestamp timer tick counter. 
    * The tick count can be converted to seconds by dividing by the return of 
    * sysTimestampFreq(). 
    * 
    * This routine locks interrupts for cases where it is necessary to stop the 
    * tick counter before reading it, or when two independent counters must 
    * be read.  If interrupts are already locked, use sysTimestamp() instead. 
    * 
    * RETURNS: The current timestamp timer tick count. 
    * 
    * SEE ALSO: sysTimestamp() 
    */ 
      
    UINT32 sysTimestampLock (void) 
        { 
        /* 
         * Return the system clock timer tick count here. 
         * Interrupts do *not* need to be locked in this routine if 
         * the counter does not need to be stopped to be read. 
         */ 
        } 
     
    #endif  /* INCLUDE_TIMESTAMP */

