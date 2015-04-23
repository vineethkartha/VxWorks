/* LCD Device Driver for VxWorks 6.6
 * Date: 20-03-2014*/

#include<vxWorks.h>
#include<taskLib.h>
#include<iosLib.h>
#include<stdio.h>
#include<semLib.h>
#include<sysLib.h>
#include<ioLib.h>

/*Address bases*/
#define gpio1 1
#define gpio2 2
#define gpio3 3
#define gpio4 4
#define gpio5 5
#define gpio6 6
#define gpio7 7
#define gpio8 8

#define en 9
#define rw 10
#define rs 11

/*IOCTL COMMADS*/
#define CLEAR 1

#define DRVNAME "/Lcd"

int status;
int drvnum;

typedef struct 
{
	DEV_HDR lcdHeader;
	char data[8];
	BOOL EN;
	BOOL RW;
	BOOL RS;
}LCDDRV;

LCDDRV pdev;

STATUS lcdCreate(char *name, ...)
{
	LCDDRV *dev=&pdev;
	printf("\n In LCD driver create()\n");
	status=iosDevAdd(&(dev->lcdHeader),name,drvnum);
	return(status);
}

STATUS lcdOpen(LCDDRV *dev,...)
{
	sysOutByte(rw,0);
	sysOutByte(rs,0);
	sysOutByte(gpio1,0);
	sysOutByte(gpio2,0);
	sysOutByte(gpio3,1);
	sysOutByte(gpio4,1);
	sysOutByte(gpio5,1);
	sysOutByte(gpio6,0);
	sysOutByte(gpio7,0);
	sysOutByte(gpio8,0);
	sysOutByte(en,1);;
	sysOutByte(en,0);
	
	
	sysOutByte(rw,0);
	sysOutByte(rs,0);
	sysOutByte(gpio1,1);
	sysOutByte(gpio2,1);
	sysOutByte(gpio3,1);
	sysOutByte(gpio4,1);
	sysOutByte(gpio5,0);
	sysOutByte(gpio6,0);
	sysOutByte(gpio7,0);
	sysOutByte(gpio8,0);
	sysOutByte(en,1);;
	sysOutByte(en,0);
	
	return OK;
}

STATUS lcdWrite(LCDDRV *dev, char *buff, int nbytes)
{
	int i=0;
	printf("\n In write\n");
	sysOutByte(rw,0);
	sysOutByte(rs,1);
	for(i=0;i<(nbytes-8);i++)
	{
		sysOutByte(gpio1,buff[i]);
		sysOutByte(gpio2,buff[i+1]);
		sysOutByte(gpio3,buff[i+2]);
		sysOutByte(gpio4,buff[i+3]);
		sysOutByte(gpio5,buff[i+4]);
		sysOutByte(gpio6,buff[i+5]);
		sysOutByte(gpio7,buff[i+6]);
		sysOutByte(gpio8,buff[i+7]);
		sysOutByte(en,1);
		sysOutByte(en,0);
	}
}

STATUS lcdioctl(LCDDRV *dev ,int func,int arg)
{
	switch(func)
	{
	case CLEAR:
		sysOutByte(rw,0);
		sysOutByte(rs,0);
		sysOutByte(gpio1,1);
		sysOutByte(gpio2,0);
		sysOutByte(gpio3,0);
		sysOutByte(gpio4,0);
		sysOutByte(gpio5,0);
		sysOutByte(gpio6,0);
		sysOutByte(gpio7,0);
		sysOutByte(gpio8,0);
		sysOutByte(en,1);;
		sysOutByte(en,0);		
		break;
	}
	return OK;
}

STATUS lcdDriver()
{

	/*Checking if an instance is already created*/
	if(drvnum>0)
		return(OK);
	
	drvnum=iosDrvInstall(lcdCreate,(FUNCPTR)0,lcdOpen,0,0,lcdWrite,lcdioctl);
	printf("Driver installed\n");
	
	if(drvnum>0)
	{
		lcdCreate(DRVNAME);//Adding the driver
		return(OK);
	}
	else
	{
		printf("Device creation failed\n");
		return(ERROR);
	}

}
