/* A skeleton of a device driver in VxWorks
 * Date: 12-02-2014
 * Vineeth Kartha*/

#include<vxWorks.h>
#include<taskLib.h>
#include<iosLib.h>
#include<stdio.h>
#include<semLib.h>
#include<ioLib.h>
#define DRVNAME "/myDrv"

static int myDrv;
int status;

static int drvnum=0;

typedef struct
{
	DEV_HDR my_header;
	BOOL available;
	char drvBuffer[64];
}MY_DEV;

MY_DEV pdev;

STATUS my_create(char *name,...)
{
	MY_DEV *dev=&pdev;
	if(myDrv<0)
	{
		printf("call myDriver() First\n");
		return(ERROR);
	}
	printf("in function my_create()\n");
	status=iosDevAdd(&(dev->my_header),name,myDrv);
	return(status);
}

int my_open(MY_DEV *dev, ...)
{
	if(dev->available)
	{
		printf("In my_open() \n");
		dev->available=FALSE;
		return((int)dev);
	}
	else
	{
		printf("Already one instance of myDrv is open\n");
		return(ERROR);
	}
}

STATUS my_close(char* name,...)
{
	if(pdev.available)
	{
		printf("No device is opene to be closed\n");
		return(ERROR);
	}
	else
	{
		pdev.available=TRUE;
		printf("in my_close()\n");
		return(OK);
	}
}

STATUS my_read(MY_DEV *dev, char *buff, int nbytes)
{
	int i;
	printf("In my_read()\n");
	for(i=0;i<nbytes;i++)
	{
		buff[i]=dev->drvBuffer[i];
	}
	buff[i]='\0';
}

STATUS my_write(MY_DEV *dev, char *buff, int nbytes)
{
	int i;
	printf("In my_write()\n");
	for(i=0;i<nbytes;i++)
	{
		dev->drvBuffer[i]=buff[i];
	}
}

STATUS my_ioctl(MY_DEV *pdev, int request,int arg)
{
	printf("in my_ioctl()\n");
	printf("Request %d\n",request);
	switch(request)
	{
	case 64:
		printf("Option implementi\n");
		break;
	}
}

STATUS myDriver()
{

	/*Checking if an instance is already created*/
	if(myDrv>0)
		return(OK);
	
	myDrv=iosDrvInstall(my_create,(FUNCPTR)0,my_open,my_close,my_read,my_write,my_ioctl);
	printf("Driver installed\n");
	
	if(myDrv>0)
	{
		my_create(DRVNAME);//Adding the driver
		pdev.available=TRUE;//setting the initial value of available to true
		return(OK);
	}
	else
	{
		printf("Device creation failed\n");
		return(ERROR);
	}

}