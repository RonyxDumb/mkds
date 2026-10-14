/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define sVolumeTable SDK_data_02152de4
#define SND_CalcChannelVolume Maybe_helper_0218f4
#include "SND_util.h"
#include "nitro/types.h"
#include "code32.h"
extern const u8 sVolumeTable[724];
#pragma thumb off
u16 SND_CalcChannelVolume(s32 x) {
    // directly using s32 doesn't match
    int decibels = (int)x;
    if (decibels < -723)
        decibels = -723;
    else if (decibels > 0)
        decibels = 0;

    u32 resultLo = sVolumeTable[decibels + 723];
    u32 resultHi;

    if (decibels < -240) {
        resultHi = 3;
    } else {
        if (decibels < -120) {
            resultHi = 2;
        } else {
            if (decibels < -60) {
                resultHi = 1;
            } else {
                resultHi = 0;
            }
        }
    }

    return (u16)((resultHi << 8u) | resultLo);
}
