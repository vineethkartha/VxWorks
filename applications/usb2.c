#include<usb/usbOsal.h>
#include<usb/usbHst.h>
USBHST_STATUS usbdInit(void)
{
	printf("\n In USBDINIT()\n");
	return USBHST_SUCCESS;
}

USBHST_STATUS usbUhcdInit(void)
{
	printf("\n In USBDINIT()\n");
	return USBHST_SUCCESS;
}