/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define sSurroundDecay SDK_data_0380796c
#define CalcSurroundDecay FUN_037fba94
#include "nitro/snd/common/channel.h"
#include <nitro/hw/ARM7/ioreg_SND.h>
extern int sSurroundDecay;
#pragma thumb off
int CalcSurroundDecay(int volume, int pan)
{
    if (pan < 24) {
        volume *= sSurroundDecay * (pan + 40) + ((32767 - sSurroundDecay) << 6);
        volume >>= 15 + 6;
    } else if (pan > 104) {
        volume *= -sSurroundDecay * (pan - 40) + ((32767 + sSurroundDecay) << 6);
        volume >>= 15 + 6;
    }

    return volume;
}
