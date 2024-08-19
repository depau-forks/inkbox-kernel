
#include <linux/delay.h>
#include <linux/kernel.h>
#include <linux/power/ntx_charger_type.h>

#include "ntx_charger_misc.h"



static ntx_charger_get_moist_lvl gcb_moist_detect_fn = 0;
int ntx_charger_register_moist_detector(ntx_charger_get_moist_lvl moist_detect_cb)
{
	gcb_moist_detect_fn = moist_detect_cb;
	return 0;
}

int ntx_charger_moist_detector_exist(void)
{
	return (gcb_moist_detect_fn) ? 1 : 0 ;
}

int ntx_charger_moist_detect(unsigned int dwDetectFlags)
{
	int iRet;

	if(gcb_moist_detect_fn) {
		iRet = gcb_moist_detect_fn(dwDetectFlags);
	}
	else {
		pr_debug("gcb_moist_detect_fn not registered !\n");
		iRet = 0 ;
	}
	return iRet;
}

static ntx_charger_get_type gcb_cc_detector = 0;
static ntx_charger_get_type gcb_gadget_detector = 0;

int ntx_charger_register_cc_detector(ntx_charger_get_type cc_ctype_cb)
{
	gcb_cc_detector = cc_ctype_cb;
	return 0;

}
int ntx_charger_register_gadget_detector(ntx_charger_get_type gadget_ctype_cb)
{
	gcb_gadget_detector = gadget_ctype_cb;
	return 0;
}

int ntx_charger_cc_detect(int iTimeout_ms)
{
	if(gcb_cc_detector) {
		msleep(iTimeout_ms);
		return gcb_cc_detector();
	}
	return -1;
}

int ntx_charger_gadget_detect(int iTimeout_ms)
{
	int ret = -1, charge_type = NO_CHARGER_PLUGGED;

	if(gcb_gadget_detector) {
		//msleep(iTimeout_ms);
		ret = gcb_gadget_detector();
		switch(ret) {
			case 0:
				charge_type = DCP_CHARGER;
				break;
			case 1:
				charge_type = SDP_CHARGER;
				break;
			case -1:
			default:
				charge_type = NO_CHARGER_PLUGGED;
				break;
		}
	}

	return charge_type;
}


