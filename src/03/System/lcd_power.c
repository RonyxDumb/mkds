#include "03/System/lcd_power.h"
#include "03/unk_021da000.h"
#include "pm.h"

void UpdateLcdPower(void) {
    if (gLcdOff != 0) {
        if (((*(u16 *) 0x27fffa8 & 0x8000) >> 15) == 0) {
            if (PM_SetLCDPower(1) != 0) {
                gLcdOff = 0;
            }
        }
    } else if (((*(u16 *) 0x27fffa8 & 0x8000) >> 15) != 0) {
        if (PM_SetLCDPower(0) != 0) {
            gLcdOff = 1;
        }
    }
}
