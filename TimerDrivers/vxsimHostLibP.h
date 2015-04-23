/* vxsimHostLibP.h - private Host/VxSim interface header */

/*
 * Copyright (c) 2004-2007 Wind River Systems, Inc.
 *
 * The right to copy, distribute or otherwise make use of this software
 * may be licensed only pursuant to the terms of an applicable Wind River
 * license agreement. No license to Wind River intellectual property rights
 * is granted herein. All rights not licensed by Wind River are reserved
 * by Wind River.
 */

/*
modification history
--------------------
01r,05sep07,elp  modified vxsimHostWdbPipeInit() (CQ:WIND103423).
01q,20aug07,dbt  Added fd parameter to vxsimHostPassfsFileStatGet()
		 routine (CQ:WIND00101812).
01p,16aug07,elp  moved header files inclusion from vxsimHostLib.h,
		 moved existing prototypes from vxsimHostArchLib.h,
		 removed internal passfs structure references.
01o,10aug07,elp  added missing vxsimLoadDllEx() and vxsimHostCpuVarsInit().
01n,15jul07,elp  added vxsimUsrSvcRegister(), vxsimUsrSvcCall().
01m,27jun07,elp  added vxsimHostSimnetBufSend().
01l,23apr07,elp  fixed mmu api names.
01k,13feb07,elp  added sio API.
01j,07feb07,elp  added ipi level to vxsimHostIpiEmit().
01i,18jan07,elp  added interrupt pending calls, removed useless SMP calls.
01h,07nov06,elp  added SMP support
01g,19oct06,elp  updated vxsimBootStrategyGet() moved vxsimHostWdbPipe*
		 routines from public header.
01f,15sep05,elp  added passFs 64 bits operations (SPR #111187).
01e,29jun05,jmp  reworked vxsimHostModel() to no longer return a host side
                 address.
01d,29sep04,jmp  added vxsimBootStrategyGet().
01c,09sep04,jmp  updated vxsimHostRename() prototype (SPR #97903).
01b,03may04,dbt  Added vxsimHostIntLock() API.
01a,29may04,jeg  written.
*/

#ifndef __INCvxsimHostLibPh
#define __INCvxsimHostLibPh

#include <sys/stat.h>
#include <utime.h>
#include <regs.h>
#include <vxsimHostLib.h>
#include <drv/end/simnetEnd.h>

typedef void *	SIO_ID;

/* DLL load option */

#define VXSIM_HOST_DLL_LOAD_ON_CPU0	0
#define VXSIM_HOST_DLL_LOAD_ON_ALL_CPU	1

/* user service max name length */

#define VXSIM_HOST_USR_SVC_MAX_NAME_LEN	50

/* user service register option */

#define VXSIM_HOST_USR_SVC_ON_CPU0	0x1

extern STATUS	vxsimHostClose		(int fd);
extern STATUS	vxsimHostPassfsDirRead	(char *	path,  void ** pDirFd,
					 char * pEntryName);
extern STATUS   vxsimHostPassfsDelete	(char * name);
extern int	vxsimHostErrnoGet	(void);
extern void	vxsimHostExit 		(void);
extern STATUS   vxsimHostPassfsClose	(int fileFd, void * dirFd);
extern STATUS	vxsimHostPassfsStatGet	(char * path, void * pVolumeDesc,
					 struct statfs * pStatfs);
extern STATUS	vxsimHostFtruncate	(int fd, int length); 
extern void 	vxsimHostIfInit		(void * pHostInfo);
extern STATUS 	vxsimHostLseek		(int fd, int offset, int whence);
extern STATUS	vxsimHostPassfsMkdir	(char *path);
extern STATUS	vxsimHostPassfsOpen	(char *name, int flags, int mode);
extern STATUS	vxsimHostOpen		(char *name, int flags, int mode);
extern void *	vxsimHostOpendir	(char *dirname);
extern void	vxsimHostPowerDown	(void);
extern void 	vxsimHostPrintf		(const char * fmt, ...);
extern STATUS	vxsimHostRead		(int fd, char *buf, int len);
extern STATUS	vxsimHostPassfsRename	(char * path, int * pFileFd,
					 void * dirFd, int mode, int flags,
					 char * newPath);
extern STATUS 	vxsimHostReboot		(int startType);
extern STATUS	vxsimHostPassfsRmdir	(char * path);
extern STATUS 	vxsimHostPassfsFileStatGet (char * path, int fd,
					 void * pVolumeDesc,
					 struct stat * pStat);
extern STATUS 	vxsimHostTimerInit 	(int sysVirtualTimeDef,
					int auxVirtualTimeDef);

extern void	vxsimHostTimerDisable	(int clk);
extern STATUS	vxsimHostTimerTimestampEnable	(int tsRollOverIntNum);
extern STATUS	vxsimHostTimerTimestampDisable	(void);
extern UINT32	vxsimHostTimerTimestampFreqGet	(void);
extern UINT32	vxsimHostTimerTimestampGet	(void);
extern STATUS	vxsimHostPassfsUnlink	(char *path);
extern int	vxsimHostPassfsCreate	(char * name, int flags);
extern STATUS	vxsimHostPassfsTimeSet	(char * path,
					 struct utimbuf * pTime);
extern STATUS	vxsimHostWrite		(int fd, char *buf, int len);
extern void	vxsimHostDbg		(char * format, ...);
extern STATUS	vxsimHostCurrentPathGet	(char * buf, int size);
extern char *	vxsimHostModel		(char * sysModelStr,
					 int sysModelStrMaxLen);
extern STATUS	vxsimHostStat		(char * path, struct stat * pStat);
extern UINT32	vxsimHostTimeGet	(void);
extern int	vxsimHostIntPendingGet	(void);
extern STATUS	vxsimHostSysNvRamGet	(char *	string, int strLen, int	offset,
					 int nvRamSize);
extern STATUS	vxsimHostSysNvRamSet	(char *	string, int strLen, int	offset,
					 int nvRamSize);
extern void *	vxsimHostShMemInit	(void * smMemAddr, int smMemSize,
					 int * smLevel);
extern STATUS	vxsimHostBusIntGen	(int smLevel, int smBusInt);
extern STATUS	vxsimHostSimnetAttach	(char * subnetName, char * ipAddr,
					 int netType, void ** ppNetCfg,
					 int * pIntId);
extern void	vxsimHostSimnetDetach	(void ** ppNetCfg);
extern void	vxsimHostSimnetIntClear (int fd);
extern void	vxsimHostSimnetIntEnable (void * pNetCfg, int intId,
					  BOOL enable);
extern int	vxsimHostSimnetPhysAddrLenGet (void * ppNetCfg);
extern void	vxsimHostSimnetPhysAddrGet (void * ppNetCfg, UINT8 * enetAddr,
					    int len);
extern STATUS	vxsimHostSimnetPhysAddrSet (void * ppNetCfg, UINT8 * enetAddr,
					    int len);
extern void	vxsimHostSimnetBrdAddrGet (void * ppNetCfg, UINT8 * enetAddr,
					   int len);
extern int	vxsimHostSimnetPktReceive (void * ppNetCfg, SIMNET_PKT * pPkt);
extern SIMNET_PKT *	vxsimHostSimnetPktGet (void * ppNetCfg, int len);
extern STATUS	vxsimHostSimnetPktSend (void * ppNetCfg, SIMNET_PKT * pPkt);
extern STATUS	vxsimHostSimnetBufSend (void * ppNetCfg, char * pBuf,
					size_t bufSize);
extern STATUS	vxsimHostSimnetPromiscModeSet (void * pNetCfg, BOOL promisc);
extern STATUS	vxsimHostSimnetMCastModeSet (void * pNetCfg, BOOL mcast);
extern STATUS	vxsimHostSimnetParamGet (void * pNetCfg, int param, 
					 UCHAR * buf, int len);
extern STATUS	vxsimHostSimnetParamSet (void * pNetCfg, int param,
					 UCHAR * buf, int len);

extern STATUS	vxsimHostNetAddIfGet (int index, char ** ppDevice, int * pUnit,
				      char ** ppDevStr, char ** ppIpAddr,
				      char ** ppIpMask);
extern void	vxsimHostVirtualMemInfoGet
					(VIRT_ADDR * pVxsimVirtMemBaseAddr,
					 UINT32 * pVxsimVirtMemSize);

extern UINT32	vxsimBootStrategyConvert (UINT32 bootStrategy);
extern STATUS	vxsimHostLseek64 (int fd, INT64 * pOffset, int whence);
extern STATUS	vxsimHostFtruncate64 (int fd, INT64 * length);
extern STATUS   vxsimHostWdbPipeInit    (void * inputBuffer,
					 int * pHostTargetFd,
					 int * pTargetHostFd,
					 int * pIntVecNum,
					 int pipePktMtu,
					 UINT32 * pPktSize);
extern void	vxsimHostWdbPipeModeSet	(int pipeFd, int newMode);
extern void	vxsimHostWdbPipeFlush	(int pipeFd);
extern STATUS	vxsimHostWdbPipeRead	(int pipeFd, void * inputBuffer,
					int * pSize);
extern STATUS	vxsimHostWdbPipeWrite	(int pipeFd, void * buffer, int len);
extern STATUS	vxsimHostWdbPipePoll	(void);
extern void	vxsimHostSleep		(UINT32 duration);

extern SIO_ID	vxsimHostSioDevFind (char * name);
extern int	vxsimHostSioIntVecGet (SIO_ID sioId);
extern int	vxsimHostSioWrite (SIO_ID sioId, char * buf, int len);
extern int	vxsimHostSioRead (SIO_ID sioId, char * buf, int len);
extern STATUS	vxsimHostSioOpen (SIO_ID sioId);
extern STATUS 	vxsimHostSioClose (SIO_ID sioId);
extern STATUS	vxsimHostSioModeSet (SIO_ID sioId, int mode);
extern STATUS	vxsimHostSioBaudRateSet (SIO_ID sioId, int baudRate);

#if CPU==SIMNT
extern STATUS	vxsimHostVxWorksInstrCacheFlush (void * address, UINT32 size);
extern int	vxsimHostTimerRateGet (int clk);
extern STATUS	vxsimHostTimerRateSet (int clk, int ticksPerSecond);
extern void	vxsimHostTimerEnable (int clk);
extern void	vxsimHostDebugBreak (void);
#else
extern int	vxsimHostGetgid (void);
extern void	vxsimHostTimerEnable (int clk, int ticksPerSecond);
#endif /* CPU==SIMNT */

#ifdef _WRS_VX_SMP
extern STATUS	vxsimHostCpuEnable (int cpuNum, INSTR * startFunc,
				    ULONG stackPtr);	
extern STATUS	vxsimHostIpiEmit (cpuset_t processor, UINT8 ipiLvl);
#endif /* _WRS_VX_SMP */

extern STATUS	vxsimHostUsrSvcRegister (UINT32 * pUsrSvcNum,
					 char * usrSvcName, char usrSvcFlags);
extern STATUS	vxsimHostUsrSvcCall (UINT32 * pResult, UINT32 svcNum, 
				     UINT32 arg0, UINT32 arg1, UINT32 arg2,
				     UINT32 arg3, UINT32 arg4, UINT32 arg5,
				     UINT32 arg6, UINT32 arg7, UINT32 arg8,
				     UINT32 arg9);
extern STATUS	vxsimHostDllLoadEx (char * dllName, UINT32 options);
extern void	vxsimHostCpuVarsInit (void);


#endif	/* __INCvxsimHostLibPh */