/* prjConfig.c - dynamicaly generated configuration file */


/*
GENERATED: Thu Mar 27 09:31:21  IST IST 2014
DO NOT EDIT - file is regenerated whenever the project changes.
This file contains the non-BSP system initialization code
for Create a bootable VxWorks image (custom configured).
*/


/* includes */

#include <vxWorks.h>
#include <config.h>
#include <adrSpaceLib.h>
#include <aio.h>
#include <aioSysDrv.h>
#include <applUtilLib.h>
#include <auxv.h>
#include <cacheLib.h>
#include <classLib.h>
#include <configNet.h>
#include <coprocLib.h>
#include <cplusLib.h>
#include <cpuPwrLib.h>
#include <cpuPwrMgr.h>
#include <dbgLib.h>
#include <drv/erf/erfLib.h>
#include <drv/manager/device.h>
#include <drv/timer/timerDev.h>
#include <drv/wdb/wdbPipePktDrv.h>
#include <drv/wdb/wdbVioDrv.h>
#include <edrLib.h>
#include <end.h>
#include <endLib.h>
#include <envLib.h>
#include <eventLib.h>
#include <excLib.h>
#include <fcntl.h>
#include <fioLib.h>
#include <fsEventUtilLib.h>
#include <fsMonitor.h>
#include <ftpLib.h>
#include <hashLib.h>
#include <hookLib.h>
#include <hostLib.h>
#include <hwif/vxbus/vxBus.h>
#include <hwif/vxbus/vxbPlbLib.h>
#include <intLib.h>
#include <ioLib.h>
#include <iosLib.h>
#include <iosScLib.h>
#include <jobQueueLib.h>
#include <ledLib.h>
#include <loadElfLib.h>
#include <loadLib.h>
#include <logLib.h>
#include <lstLib.h>
#include <m2IfLib.h>
#include <math.h>
#include <memLib.h>
#include <moduleLib.h>
#include <mqPxShow.h>
#include <msgQLib.h>
#include <muxLib.h>
#include <net/mbuf.h>
#include <netBufLib.h>
#include <netDrv.h>
#include <netLib.h>
#include <netdb.h>
#include <objLib.h>
#include <pipeDrv.h>
#include <pmLib.h>
#include <private/adrSpaceLibP.h>
#include <private/cplusLibP.h>
#include <private/cpuPwrLibP.h>
#include <private/excLibP.h>
#include <private/ftpLibP.h>
#include <private/funcBindP.h>
#include <private/isrLibP.h>
#include <private/jobLibP.h>
#include <private/kernelBaseLibP.h>
#include <private/kernelLibP.h>
#include <private/moduleHookLibP.h>
#include <private/mqPxLibP.h>
#include <private/nbioLogLibP.h>
#include <private/offsetsP.h>
#include <private/pgMgrLibP.h>
#include <private/pgPoolLibP.h>
#include <private/pgPoolPhysLibP.h>
#include <private/pgPoolVirtLibP.h>
#include <private/poolLibP.h>
#include <private/rtpLibP.h>
#include <private/sdLibP.h>
#include <private/semPxLibP.h>
#include <private/shellLibP.h>
#include <private/sigLibP.h>
#include <private/syscallLibP.h>
#include <private/taskLibP.h>
#include <private/taskMemLibP.h>
#include <private/timerLibP.h>
#include <private/tlsLibP.h>
#include <private/trgLibP.h>
#include <private/vmLibP.h>
#include <private/vxMemProbeLibP.h>
#include <private/vxdbgRtpLibP.h>
#include <private/workQLibP.h>
#include <private/wvFileUploadPathLibP.h>
#include <private/wvTsfsUploadPathLibP.h>
#include <private/wvUploadPathP.h>
#include <pthread.h>
#include <ptyDrv.h>
#include <qPriBMapLib.h>
#include <rBuffLib.h>
#include <rawFsLib.h>
#include <rebootLib.h>
#include <remLib.h>
#include <romfsLib.h>
#include <rtpLib.h>
#include <sched.h>
#include <sdLib.h>
#include <selectLib.h>
#include <semLib.h>
#include <semPxShow.h>
#include <setLib.h>
#include <shellConfigLib.h>
#include <shellInterpLib.h>
#include <shellLib.h>
#include <shlLib.h>
#include <sigLib.h>
#include <sigevent.h>
#include <sioLib.h>
#include <stdio.h>
#include <string.h>
#include <symLib.h>
#include <sys/mman.h>
#include <sysLib.h>
#include <sysSymTbl.h>
#include <syscallLib.h>
#include <syscallTbl.h>
#include <sysctlLib.h>
#include <taskHookLib.h>
#include <taskLib.h>
#include <taskVarLib.h>
#include <tickLib.h>
#include <time.h>
#include <timexLib.h>
#include <trgLib.h>
#include <ttyLib.h>
#include <tyLib.h>
#include <unistd.h>
#include <unldLib.h>
#include <usrConfig.h>
#include <usrLib.h>
#include <version.h>
#include <vmLib.h>
#include <vxAtomicLib.h>
#include <vxBusLib.h>
#include <vxLib.h>
#include <vxbTimerLib.h>
#include <wait.h>
#include <wdLib.h>
#include <wdb/wdb.h>
#include <wdb/wdbBpLib.h>
#include <wdb/wdbCommIfLib.h>
#include <wdb/wdbLib.h>
#include <wdb/wdbLibP.h>
#include <wdb/wdbMbufLib.h>
#include <wdb/wdbRpcLib.h>
#include <wdb/wdbRtIfLib.h>
#include <wdb/wdbRtpLibP.h>
#include <wdb/wdbSvcLib.h>
#include <wdb/wdbUdpLib.h>
#include <wdb/wdbVioLib.h>
#include <wvLib.h>
#include <wvTmrLib.h>
#include <xbdRamDisk.h>


/* imports */

IMPORT char etext [];                   /* defined by loader */
IMPORT char end [];                     /* defined by loader */
IMPORT char edata [];                   /* defined by loader */

/* forward declarations */

IMPORT STATUS adrSpaceShellCmdInit (void);
IMPORT u_short checksum (u_short *, int);
IMPORT STATUS dbgShellCmdInit ();
IMPORT STATUS usrFsShellCmdInit ();
IMPORT STATUS edrShellCmdInit ();
IMPORT void memRtpLibInit (UINT heapSize,UINT heapOptions);
extern STATUS moduleShellCmdInit (void);
IMPORT STATUS hostnameSetup (char * );
IMPORT STATUS objInfoInit (void);
extern void clockLibInit (void);
IMPORT void usrKernelIntStkProtect(void);
extern STATUS usrRtpLibInit();
IMPORT STATUS rtpShowShellCmdInit (void);
IMPORT void windScInit (void);
IMPORT void mmanScLibInit (void);
extern void usrPosixScInit (void);
IMPORT void sdScInit (void);
IMPORT void shlScLibInit (void);
IMPORT STATUS sockScLibInit (void);
IMPORT STATUS sysctlScLibInit (void);
IMPORT void semBCreateLibInit (void);
IMPORT void semCCreateLibInit (void);
IMPORT void semMCreateLibInit (void);
IMPORT STATUS sdShowShellCmdInit (void);
extern int sigeventLibInit (void);
extern char * startupScriptFieldSplit (char * field);
IMPORT STATUS symShellCmdInit ();
IMPORT void taskCreateLibInit (void);
IMPORT STATUS taskShellCmdInit ();
extern STATUS unloadShellCmdInit (void);
IMPORT STATUS vmShowShellCmdInit (void);
IMPORT STATUS vxIpiLibInit (void);
IMPORT void usrWdbInit (void);


/* BSP_STUBS */



/* configlettes */

#include <sysComms.c>
#include </home/kartha/WindRiver/vxworks-6.6/target/src/hwif/util/hwMemLib.c>
#include </home/kartha/WindRiver/vxworks-6.6/target/src/hwif/util/vxbDelayLib.c>
#include </home/kartha/WindRiver/vxworks-6.6/target/src/hwif/util/vxbTimerLib.c>
#include </home/kartha/WindRiver/vxworks-6.6/target/src/hwif/vxbus/vxBus.c>
#include </home/kartha/WindRiver/vxworks-6.6/target/src/hwif/vxbus/vxbArchAccess.c>
#include </home/kartha/WindRiver/vxworks-6.6/target/src/hwif/vxbus/vxbPlb.c>
#include </home/kartha/WindRiver/vxworks-6.6/target/src/hwif/vxbus/vxbPlbAccess.c>
#include </home/kartha/WindRiver/vxworks-6.6/target/src/hwif/vxbus/vxbShow.c>
#include <cplusdiabLang.c>
#include <edrStub.c>
#include <intrinsics.c>
#include <ipnet/ipcom_config.c>
#include <ipnet/ipcom_ipd_config.c>
#include <ipnet/ipnet_config.c>
#include <ipnet/ipnet_radvd_config.c>
#include <ipnet/iptcp_config.c>
#include <net/coreip/apps/usrFtp.c>
#include <net/coreip/apps/usrNetHostTblCfg.c>
#include <net/coreip/usrBootLine.c>
#include <net/coreip/usrNetApplUtil.c>
#include <net/coreip/usrNetBoot.c>
#include <net/coreip/usrNetDaemon.c>
#include <net/coreip/usrNetEndLib.c>
#include <net/coreip/usrNetRemoteCfg.c>
#include <net/coreip/usrNetSysctl.c>
#include <sysClkInit.c>
#include <usrBanner.c>
#include <usrBreakpoint.c>
#include <usrCache.c>
#include <usrCoprocs.c>
#include <usrCplus.c>
#include <usrEdrInit.c>
#include <usrHwSysctl.c>
#include <usrKernel.c>
#include <usrKernelStack.c>
#include <usrLoadSym.c>
#include <usrMmuInit.c>
#include <usrPassFs.c>
#include <usrPmInit.c>
#include <usrPosixSc.c>
#include <usrRomfs.c>
#include <usrRtpAppInitBootline.c>
#include <usrScript.c>
#include <usrSemLib.c>
#include <usrSerial.c>
#include <usrShell.c>
#include <usrStartup.c>
#include <usrStatTbl.c>
#include <usrSysSymTbl.c>
#include <usrSysctl.c>
#include <usrTextProtect.c>
#include <usrWdbBanner.c>
#include <usrWdbBp.c>
#include <usrWdbCore.c>
#include <usrWdbGopher.c>
#include <usrWindview.c>
#include <wdbPipe.c>


/******************************************************************************
*
* usrInit - pre-kernel initialization
*/

void usrInit (int startType)
    {
    sysStart (startType);               /* clear BSS and set up the vector table base address. */
    cacheLibInit (USER_I_CACHE_MODE, USER_D_CACHE_MODE); /* include cache support */
    excVecInit ();                      /* exception handling */
    sysHwInit ();                       /* call the BSPs sysHwInit routine during system startup */
    usrCacheEnable ();                  /* optionally enable caches */
    objOwnershipInit ();                /* object management ownership */
    objInfoInit ();                     /* object management routines that requires lookup in a 			list of objects, such as the objNameToId() routine. */
    objLibInit ((FUNCPTR)FUNCPTR_OBJ_MEMALLOC_RTN,					    FUNCPTR_OBJ_MEMFREE_RTN,					    OBJ_MEM_POOL_ID, 						    OBJ_LIBRARY_OPTIONS); /* object management */
    vxMemProbeInit ();                  /* Initialize vxMemProbe exception handler support */
    wvLibInit ();                       /* low-level kernel instrumentation needed by System Viewer */
    classListLibInit ();                /* object class list management */
    semLibInit ();                      /* semaphore support infrastructure */
                                        /* mutex semaphores */
                                        /* mutex semaphore creation routine */
    classLibInit ();                    /* object class management */
    kernelBaseInit ();                  /* required component DO NOT REMOVE. */
                                        /* __thread variables support */
    usrKernelInit (VX_GLOBAL_NO_STACK_FILL); /* context switch and interrupt handling (DO NOT REMOVE). */
    }



/******************************************************************************
*
* usrNetAppInit - 
*/

void usrNetAppInit (void)
    {
    usrFtpInit();                       /* File Transfer Protocol (FTP) library */
    }



/******************************************************************************
*
* usrNetHostInit - 
*/

void usrNetHostInit (void)
    {
    usrNetHostTblSetup ();              /* host table support */
    hostnameSetup (pTgtName);           /* assign local hostname to target */
    }



/******************************************************************************
*
* usrNetRemoteInit - 
*/

void usrNetRemoteInit (void)
    {
    remLibInit(RSH_STDERR_SETUP_TIMEOUT); /* Remote Command Library */
    remLibSysctlInit();                 /* Network sysctl tree support for remlib */
                                        /* Allows access to file system on boot host */
    usrNetRemoteCreate ();              /* Allows access to file system on boot host */
    }



/******************************************************************************
*
* usrNetworkInit - Initialize the network subsystem
*/

void usrNetworkInit (void)
    {
    usrNetApplUtilInit ();              /* Stack and Application Logging Utility */
    usrNetBoot ();                      /* Copy boot parameters for futher use by network */
    netBufLibInitialize (NETBUF_LEADING_CLSPACE_DRV); /* Network Buffer Library */
    netBufPoolInit ();                  /* netBufLib Generic Pool */
    linkBufPoolInit ();                 /* Network Buffer Library */
    nullBufPoolInit ();                 /* Minimal clusterless network pool implementation for IPCOM */
    jobQueueLibInit();                  /* jobQueueLib prioritized work deferral mechanism */
    usrNetDaemonInit(NET_JOB_NUM_CFG,                        NET_TASK_PRIORITY, NET_TASK_OPTIONS,                        NET_TASK_STACKSIZE); /* Network Daemon Support */
    usrNetmaskGet ();                   /* Extracts netmask value from address field */
    usrNetSysctlInit();                 /* Networking System control support */
    usrNetHostInit ();                  /* initialize host table */
    rtpHostLibInit ();                  /* network sysctl tree support for host tables */
    rtpGetaddrinfoInit ();              /* network sysctl tree support for RTP getaddrinfo() */
    muxLibInit();                       /* MUX network interface library */
    usrNetRemoteInit ();                /* initialize network remote I/O access */
    usrNetEndLibInit();                 /* Support for network devices using MUX/END interface */
    ipcom_create ();                    /* VxWorks IPCOM */
    netSysctlInit (TRUE);               /* Integrates IPNet sysctl nodes into VxWorks sysctl tree. */
    sysNetIfConfig ();                  /* initialize VxSim additional network interfaces */
    usrNetAppInit ();                   /* initialize network application protocols */
    }



/******************************************************************************
*
* usrLoaderInit - The target loader initialization sequence
*/

void usrLoaderInit (void)
    {
    moduleLibInit ();                   /* Support library for module entities */
    loadElfInit ();                     /* ELF loader */
    loadLibInit (STORE_ABS_SYMBOLS);    /* Allows modules to be downloaded into running targets */
    unldLibInit ();                     /* Permits removal of dynamically downloaded modules */
    moduleHookLibInit ();               /* Pluggable hooks to extend the loader/unloader behavior */
    }



/******************************************************************************
*
* usrWindviewInit - 
*/

void usrWindviewInit (void)
    {
    windviewConfig ();                  /* initialize and control event logging */
    wvTmrRegister ((UINTFUNCPTR) sysTimestamp,					(UINTFUNCPTR) sysTimestampLock,	        				(FUNCPTR) sysTimestampEnable,					(FUNCPTR) sysTimestampDisable,					(FUNCPTR) sysTimestampConnect,					(UINTFUNCPTR) sysTimestampPeriod,					(UINTFUNCPTR) sysTimestampFreq); /* bsp specific timestamp routines  */
    rBuffLibInit ();                    /* System Viewer ring of buffers for event logging  */
    wdbTsfsDrv ("/tgtsvr");             /* virtual file system based on the WDB agent */
    wvTsfsUploadPathLibInit ();         /* initialize path for the upload through TSFS socket  */
    wvFileUploadPathLibInit ();         /* initialize path for the upload to file  */
    }



/******************************************************************************
*
* usrShowInit - enable object show routines
*/

void usrShowInit (void)
    {
    taskShowInit ();                    /* task show routine */
    classShowInit ();                   /* class show routine */
    memShowInit ();                     /* memory show routine */
    taskHookShowInit ();                /* task hook show routine */
    semShowInit ();                     /* semaphore show routine */
    msgQShowInit ();                    /* message queue show routine */
    wdShowInit ();                      /* watchdog timer show routine */
    symShowInit ();                     /* Routines to display information about symbols and symbol tables */
    vmShowInit ();                      /* VM library show routine */
    mqPxShowInit ();                    /* POSIX message queue show routine */
    semPxShowInit ();                   /* POSIX semaphore show routine */
                                        /* task floating point registers */
    trgShowInit ();                     /* trigger show routine */
    rBuffShowInit ();                   /* rBuff show routine */
    stdioShowInit ();                   /* stdio show routine */
    edrShowInit ();                     /* ED&R show routines */
                                        /* handle show routines */
    timerShowInit();                    /* This is a utility that will allow the user to display a snap shot of the selected timer. Requires INCLUDE_POSIX_TIMERS */
    adrSpaceShowInit();                 /* Address Space Allocator Show Routines: display 			information on the system address space allocator. */
    pgMgrShowInit();                    /* Page manager show routines: display information on 			page managers. */
    pgPoolShowInit();                   /* Generic page pool allocator show routines: display 			information on page pools. */
    rtpShowInit ();                     /* Display information on RTP. */
    sdShowInit ();                      /* Display information on Shared Data. */
    shlShowInit ();                     /* Display information on Shared Libraries */
    coprocShowInit ();                  /* task coprocessor registers */
    }



/******************************************************************************
*
* usrSymTblInit - Enable onboard symbol tables
*/

void usrSymTblInit (void)
    {
    usrSysSymTblInit ();                /* initialize system symbol table */
    usrLoadSyms ();                     /* prefered method for loading symbol table on VxSim. */
    usrStatTblInit ();                  /* Table of error strings for perror() */
    }



/******************************************************************************
*
* usrShellCmdInit - The kernel shell commands initialization sequence
*/

void usrShellCmdInit (void)
    {
    taskShellCmdInit ();                /* List of commands for the shell command interpreter related to tasks. */
    dbgShellCmdInit ();                 /* List of commands for the shell command interpreter related to debugging. */
    symShellCmdInit ();                 /* List of commands for the shell command interpreter related to symbol access. */
    usrFsShellCmdInit ();               /* List of commands for the shell command interpreter related to file system. */
    edrShellCmdInit ();                 /* List of commands for the shell command interpreter related to ED&R. */
    vmShowShellCmdInit ();              /* Virtual Memory show commands for the shell command interpreter.  */
    adrSpaceShellCmdInit ();            /* Address space commands for the shell command interpreter.  */
    sdShowShellCmdInit ();              /* Shared data show commands for the shell command interpreter.  */
    moduleShellCmdInit();               /* Target loader commands for the shell command interpreter. */
    unloadShellCmdInit();               /* Unloader commands for the shell command interpreter.  */
    rtpShellCmdInit ();                 /* List of commands for the shell command interpreter related to processes. */
    rtpShowShellCmdInit ();             /* List of process show commands for the shell command interpreter.  */
    shlShellCmdInit ();                 /* List of SHL commands for the shell command interpreter */
    }



/******************************************************************************
*
* usrShellInit - The kernel shell initialization sequence
*/

void usrShellInit (void)
    {
    shellLibInit ();                    /* Handles the shell core files */
    dbgInit ();                         /* Breakpoints and stack tracer on target. Not needed for remote debugging with tornado. */
    vxdbgRtpLibInit ();                 /* Initialize process debugging library. */
    usrBanner ();                       /* Display the WRS banner on startup */
    ledModeRegister (viLedLibInit);     /* Editing mode similar to the Vi editing mode */
    ledModeRegister (emacsLedLibInit);  /* Editing mode similar to the emacs editing mode */
    shellInterpRegister (shellInterpCInit); /* The C interpreter for the kernel shell */
    shellInterpRegister (shellInterpCmdInit); /* The command interpreter for the kernel shell */
    usrShellCmdInit ();                 /* The kernel shell commands initialization sequence */
    usrStartupScript (startupScriptFieldSplit (sysBootParams.startupScript)); /* Initial kernel shell script run at VxWorks startup */
    usrShell ();                        /* Interpreter for interactive development, prototyping, debugging and testing */
    }



/******************************************************************************
*
* usrToolsInit - software development tools
*/

void usrToolsInit (void)
    {
    timexInit ();                       /* utility to measure function execution time */
    usrLoaderInit ();                   /* The target loader initialization sequence */
    usrSymTblInit ();                   /* Enable onboard symbol tables */
    trgLibInit ();                      /* triggering for system and user events */
    usrWdbInit ();                      /* WDB agent is initialized when kernel has been initialized. It then can debug whole system and supports task and system mode. */
    usrWindviewInit ();                 /* usrWindviewInit */
    tlsLoadLibInit ();                  /* __thread variables loader support */
    usrShowInit ();                     /* enable object show routines */
    usrRtpLibInit ();                   /* List of commands for the shell C interpreter related to RTPs. */
    usrShellInit ();                    /* The kernel shell initialization sequence */
    }



/******************************************************************************
*
* usrKernelCoreInit - core kernel facilities
*/

void usrKernelCoreInit (void)
    {
    eventLibInit ();                    /* VxWorks events */
    semDeleteLibInit ();                /* semaphore deletion routines */
                                        /* binary semaphores */
                                        /* counting semaphores */
                                        /* reader/writer semaphores */
    semOpenInit ();                     /* open/close/unlink semaphore modules */
    msgQLibInit ();                     /* message queues */
    msgQOpenInit ();                    /* open/close/unlink message queue modules */
    wdLibInit ();                       /* watchdog timers */
    taskOpenInit ();                    /* open/close/unlink task modules */
    taskHookInit ();                    /* user callouts on task creation/deletion/context switch */
                                        /* binary semaphore creation routine */
                                        /* counting semaphore creation routine */
                                        /* reader/writer semaphore creation routine */
    taskCreateLibInit ();               /* Capability to dynamically instantiate and delete tasks */
    msgQCreateLibInit ();               /* message queue creation and deletion library */
    wdCreateLibInit ();                 /* watchdog timers creation and deletion library */
    wdbTaskHookInit ();                 /* task hooks debug support */
    }



/******************************************************************************
*
* usrKernelExtraInit - extended kernel facilities
*/

void usrKernelExtraInit (void)
    {
    hashLibInit ();                     /* hash library */
    symLibInit ();                      /* Set of routines to manipulate symbols and symbol tables */
    taskVarInit ();                     /* allow global variables to be made private to a task */
    envLibInit (ENV_VAR_USE_HOOKS);     /* unix compatable environment variables */
    sigInit (POSIX_SIGNAL_MODE);        /* signals */
    sigeventLibInit ();                 /* Kernel signal event support.  Required for SIGEV_THREAD support in RTP. */
    mqPxLibInit (MQ_HASH_SIZE);         /* POSIX message queues */
    pthreadLibInit ();	                 /* Support for POSIX threads in the kernel */
    semPxLibInit ();                    /* POSIX semaphores */
    sigqueueInit (NUM_SIGNAL_QUEUES);   /* queued signals */
    clockLibInit ();                    /* POSIX clocks */
    timerLibInit ();                    /* POSIX timers */
    timerOpenInit ();                   /* open/close/unlink timer modules */
    intVecTableWriteProtect ();         /* write-protect vector table */
    syscallHookLibInit ();              /* Add hook routines to be called on system calls. */
    }



/******************************************************************************
*
* usrIosCoreInit - core I/O system
*/

void usrIosCoreInit (void)
    {
    selectInit (NUM_FILES);             /* select */
    iosInit (NUM_DRIVERS, NUM_FILES, "/null"); /* Basic IO system component */
    iosPathLibInit ();                  /* File System IO component */
    iosRmvLibInit ();                   /* Removable IO component */
    iosPxLibInit (IOS_POSIX_PSE52_MODE); /* POSIX IO component */
    iosRtpLibInit ();                   /* RTP IO component */
                                        /* Miscellaneous IO component */
    tyLibInit (TYLIB_XOFF_PCNT, TYLIB_XON_PCNT, 				TYLIB_WRT_THRESHLD); /* Allows communication between processes */
    ttyDrv ();                          /* terminal driver */
    usrSerialInit ();                   /* SIO component */
    coprocLibInit();                    /* generalized coprocessor support */
    }



/******************************************************************************
*
* usrIosExtraInit - extended I/O system
*/

void usrIosExtraInit (void)
    {
    excShowInit ();                     /* exception show routines */
    jobLibInit (JOB_TASK_STACK_SIZE);   /* miscellaneous support task */
    excInit (MAX_ISR_JOBS);             /* interrupt-level job facility */
    logInit (consoleFd, MAX_LOG_MSGS);  /* message logging */
    nbioLogInit (consoleFd, INIT_NBIO_MSGS); /* non-blocking message logging */
    pipeDrv ();                         /* pipes */
    aioPxLibInit (MAX_LIO_CALLS);       /* POSIX asynchronous IO */
    aioSysInit (MAX_AIO_SYS_TASKS, 				AIO_TASK_PRIORITY, AIO_TASK_STACK_SIZE); /* provides AIO functionality to non-AIO drivers */
    stdioInit ();                       /* buffered IO library */
    fioLibInit ();                      /* formatting for printf, scanf, etc. */
    floatInit ();                       /* allow printf and others to format floats correctly */
    erfLibInit (ERF_MAX_USR_CATEGORIES, ERF_MAX_USR_TYPES); /* Event Reporting Framework */
    devInit (DEVICE_MANAGER_MAX_NUM_DEVICES); /* Device Manager */
    xbdInit ();                         /* Extended Block Device */
    fsMonitorInit ();                   /* File System Monitor */
    fsEventUtilLibInit ();              /* File System Event Utilities */
    rawFsInit (NUM_RAWFS_FILES);        /* Raw block device file system interface */
    ptyDrv ();                          /* Allows communication between processes */
    usrRomfsConfig ();                  /* Read-only memory based file system */
    xbdRamDiskDevCreate (RAM_DISK_BLK_SIZE,                                                     RAM_DISK_SIZE,                                                         FALSE,                                                                 RAM_DISK_DEV_NAME); /* Create an XBD based RAM disk */
    usrBootLineParse (BOOT_LINE_ADRS);  /* parse some boot device configuration info  */
    usrPassFsInit (PASSFS_CACHE);       /* direct access to host filesystem */
    virtualDiskInit ();                 /* VxSim virtual disk to emulate a VxWorks disk driver. */
    }



/******************************************************************************
*
* usrScInit - The system call initialization sequence
*/

void usrScInit (void)
    {
    usrPosixScInit ();                  /* system call handlers for POSIX based calls */
    sockScLibInit ();                   /* System call support for socket API */
    memRtpLibInit (RTP_HEAP_INIT_SIZE,RTP_HEAP_DEFAULT_OPTIONS); /* Initializes memory parameters to pass to RTP */
    windScInit ();                      /* system call handlers for WIND kernel  */
    mmanScLibInit ();                   /* system call handlers for memory management */
    sdScInit ();                        /* system call handlers for shared data */
    shlScLibInit ();                    /* system call handlers for shared libraries */
    iosScLibInit ();                    /* IOS system calls */
    sysctlScLibInit ();                 /* System call support for sysctl() */
    }



/******************************************************************************
*
* usrRoot - entry point for post-kernel initialization
*/

void usrRoot (char *pMemPoolStart, unsigned memPoolSize)
    {
    usrKernelCoreInit ();               /* core kernel facilities */
    cpuPwrFrameWorkInit (                   CPU_PWR_TASK_P_STATE,                   CPU_PWR_ISR_P_STATE,                    CPU_PWR_UTIL_PERIOD1,                   CPU_PWR_UTIL_PERIOD2,                   CPU_PWR_HIGH_THRESHOLD,                 CPU_PWR_LOW_THRESHOLD                   ); /* CPU Power management framework Component */
    cpuPwrLightMgrInit();               /* CPU Power Light utilization manager Component */
    poolLibInit();                      /* memory pools of fixed size items */
    memInit (pMemPoolStart, memPoolSize, 				 MEM_PART_DEFAULT_OPTIONS); /* full featured memory allocator */
    memPartLibInit (pMemPoolStart, memPoolSize); /* core memory partition manager */
    memInfoInit ();                     /* memory allocator info routines */
    rtpHookLibInit (RTP_HOOK_TBL_SIZE); /* Add hook routines to be called on RTP operations. */
    usrSysctlInit();                    /* System control function */
    usrHwSysctlInit();                  /* System control hardware info registration */
    rtpLibInit (RTP_HOOK_TBL_SIZE, SYSCALL_HOOK_TBL_SIZE, 				    RTP_SIGNAL_QUEUE_SIZE, 				    TASK_USER_EXC_STACK_OVERFLOW_SIZE, 				    TASK_USER_EXEC_STACK_OVERFLOW_SIZE, 				    TASK_USER_EXEC_STACK_UNDERFLOW_SIZE, 				    RTP_FD_NUM_MAX); /* Real Time Process. */
    sdLibInit (SD_HOOK_TBL_SIZE);       /* provide data sharing between RTPs or kernel */
    shlLibInit ();                      /* provide sharing of code between RTPs */
    pgPoolLibInit();                    /* Generic Page Pool Allocator */
    pgPoolVirtLibInit();                /* Page Pool Allocator for Virtual Space */
    pgPoolPhysLibInit();                /* Page Pool Allocator for Physical Space */
                                        /* basic MMU component */
    usrMmuInit ((VIRT_ADDR) pMemPoolStart, memPoolSize); /* MMU global map support */
    usrTextProtect ();                  /* write-protect program text */
    usrPmInit ();                       /* reboot-safe protected memory region manager */
    usrEdrInit ();                      /* reboot-safe protected error log */
    edrSystemDebugModeInit ();          /* a flag indicating the system is in 'debug' mode */
    pgMgrLibInit();                     /* Page Manager Library */
    usrKernelIntStkProtect();           /* insert underflow and overflow guard pages on interrupt stack */
    taskStackGuardPageEnable();         /* insert underflow and overflow guard pages to kernel task stacks */
    taskStackNoExecEnable();            /* enable non-executable kernel task stacks */
    sysClkInit ();                      /* System clock component */
    vxIpiLibInit ();                    /* Inter Processor Interrupts for SMP and AMP */
    edrStubInit ();                     /* protected error log stub initialization */
                                        /* Modified definitions for generalized coprocessor */
    setLibInit ();                      /* sets of unspecified item types */
    usrIosCoreInit ();                  /* core I/O system */
    usrKernelExtraInit ();              /* extended kernel facilities */
    usrIosExtraInit ();                 /* extended I/O system */
    sockLibInit ();                     /* Socket API */
    usrNetworkInit ();                  /* Initialize the network subsystem */
    selTaskDeleteHookAdd ();            /* selectInit, part 2, install task delete hook */
    cplusCtorsLink ();                  /* run compiler generated initialization functions at system startup */
    usrCplusLibInit ();                 /* Basic support for C++ applications */
    cplusDemanglerInit ();              /* Support library for kernel shell and loader: provides human readable forms of C++ identifiers */
    usrScInit ();                       /* The system call initialization sequence */
    usrToolsInit ();                    /* software development tools */
    usrAppInit ();                      /* call usrAppInit() (in your usrAppInit.c project file) after startup. */
    usrRtpAppInitBootline ();           /* Launch RTP from a string-encoded list in the boot parameters. */
    }



/******************************************************************************
*
* usrWdbInit - the WDB target agent
*/

void usrWdbInit (void)
    {
    wdbConfig ();                       /* software agent to support the tornado tools */
    wdbMemLibInit ();                   /* read/write target memory */
    wdbTaskModeInit (WDB_SPAWN_STACK_SIZE,						 WDB_TASK_PRIORITY,						 WDB_TASK_OPTIONS,						 WDB_STACK_SIZE,						 WDB_MAX_RESTARTS,						 WDB_RESTART_TIME); /* A breakpoint stops one task, while others keep running. */
    wdbEventLibInit ();                 /* asynchronous event handling needed for breakpoints etc. */
    wdbEvtptLibInit ();                 /* support library for breakpoints and other asynchronous events. */
    wdbRtpLibInit (WDB_RTP_PRIORITY);   /* RTP operations: creation, deletion, ... */
    wdbDirectCallLibInit ();            /* call arbitrary functions directly from WDB */
    wdbCtxLibInit ();                   /* create/delete/manipulate tasks */
    wdbRegsLibInit ();                  /* get/set registers */
    wdbTaskRegLibInit ();               /* Coprocessor support for task in WDB */
    usrWdbGopherInit ();                /* information gathering language used by many tools */
    wdbCtxExitLibInit ();               /* ability to notify the host when a task exits */
    wdbExcLibInit ();                   /* notify the host when an exception occurs */
    wdbFuncCallLibInit ();              /* asynchronous function calls */
    wdbVioLibInit ();                   /* low-level virtual I/O handling */
    wdbVioDrv ("/vio");                 /* vxWorks driver for accessing virtual I/O */
    usrWdbBp ();                        /* core breakpoint library */
    wdbBpSyncLibInit ();                /* Breakpoint synchronization component */
    wdbTaskBpLibInit ();                /* task-mode breakpoint library */
    wdbRtpBpLibInit ();                 /* task-mode RTP breakpoint library */
    wdbRtpCtrlLibInit ();               /* Allow to stop real time processes when they are launched */
    wdbCtxStartLibInit ();              /* ability to notify the host when a task starts */
    wdbUserEvtLibInit ();               /* ability to send user events to the host */
    usrWdbBanner ();                    /* print banner to console after the agent is initialized */
    wdbMdlSymSyncLibInit ();            /* Synchronize modules and symbols between the target server and a target */
    }



/******************************************************************************
*
* hardWareInterFaceBusInit - bus-subsystem initialization
*/

void hardWareInterFaceBusInit (void)
    {
    vxbLibInit();                       /* vxBus Library Initialization */
    plbRegister();                      /* Processor Local Bus */
    }



/******************************************************************************
*
* hardWareInterFaceInit - Hardware Interface Pre-Kernel Initialization
*/

void hardWareInterFaceInit (void)
    {
    hwMemLibInit(); hwMemPoolCreate(&hwMemPool[0], HWMEM_POOL_SIZE); /* Pre-Kernel Memory Allocation */
    hardWareInterFaceBusInit();         /* vxBus subsystem */
    vxbInit();                          /* vxBus Library Activation */
    vxbTimerLibInit();                  /* vxBus Timer Support */
    }



/******************************************************************************
*
* vxbDevInit - Device initalization post kernel
*/

STATUS vxbDevInit (void)
    {
    return(vxbDevInitInternal ());      /* vxbus device intialization */
    }



/******************************************************************************
*
* vxbDevConnect - vxBus Device Connect post kernel
*/

STATUS vxbDevConnect (void)
    {
    return (vxbDevConnectInternal ());  /* vxbus device connection */
    }

