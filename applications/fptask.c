#include<vxWorks.h>
#include<taskLib.h>

void task1(float,float);

void main()
{
	int t1;
	t1=taskSpawn("t1",101,VX_NO_STACK_FILL,2000,(FUNCPTR)task1,1.1,2.2,0,0,0,0,0,0,0,0);
	
}

void task1(float a, float b)
{
	printf("\n %f\n",(b/a));
}