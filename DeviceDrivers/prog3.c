/* A program to check the working of /myDrv
 * Date: 21-02-2014
 * Vineeth Kartha*/

#include<vxWorks.h>
#include"lcdDrv.c"
#include<taskLib.h>
#include<iosLib.h>
#include<stdio.h>

int main_test()
{
	int fd;
	char msg[]="Testing my driver";
	char buf[64];
	myDriver();
	//lcdDriver();
	fd=open("/myDrv",O_RDWR,0666);
	write(fd,msg,sizeof(msg));
	read(fd,buf,64);
	printf("\n\n%s\n\n",buf);
	close(fd);
	return 0;
}