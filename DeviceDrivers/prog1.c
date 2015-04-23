/* Testing the serial driver /tyCo/0 */
/* date :11-2-2014*/
/* Vineeth kartha*/
#include<vxWorks.h>
#include<ioLib.h>
#include<stdio.h>

int serial_test()
{
int fd=0;
int size=0;
char my_dev[]="/tyCo/0";
char msg[]="hello\n";

fd=open(my_dev,O_RDWR,0);// Here the permission is Read only but I am still able to write to that device driver
size=write(fd,msg,sizeof(msg));
printf("The size of the message written is %d",size);
close(fd);
return 0;
}
