#ifndef ntx_charger_misc_h //[
#define ntx_charger_misc_h

#include <linux/power/ntx_charger_type.h>


#define NTX_MOIST_DETFLAG_FORCE_MAN_DETECT	0x00000001
#define NTX_MOIST_DETFLAG_FORCE_AUTO_DETECT	0x00000002 
#define NTX_MOIST_DETFLAG_FORCE_PERIOD_DETECT	0x00000004 // 
#define NTX_MOIST_DETFLAG_FORCE_DIS_DETECT	0x40000000 // disable moist detection . 
#define NTX_MOIST_DETFLAG_WAIT_FORCE_DET	0x80000000

//#define NTX_MOIST_DETECT_LVL 2 // moist level to judge moist detected . 
#define NTX_MOIST_INDETECT_LVL (-2) // moist level to judge moist indetected . 
typedef int (*ntx_charger_get_moist_lvl)(unsigned int dwDetectFlags);
int ntx_charger_register_moist_detector(ntx_charger_get_moist_lvl moist_detect);
int ntx_charger_moist_detect(unsigned int dwDetectFlags);
int ntx_charger_moist_detector_exist(void);

typedef int (*ntx_charger_get_type)(void);

int ntx_charger_register_cc_detector(ntx_charger_get_type cc_ctype_cb);
int ntx_charger_register_gadget_detector(ntx_charger_get_type gadget_ctype_cb);

int ntx_charger_cc_detect(int iTimeout_ms);
int ntx_charger_gadget_detect(int iTimeout_ms);



#endif //] ntx_charger_misc_h

