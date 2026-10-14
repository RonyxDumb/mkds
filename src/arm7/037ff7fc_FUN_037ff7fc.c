/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SND_SetChannelVolume FUN_037fbc88
#define SetChannelVolume FUN_037ff7fc
#include <nitro/snd/common/command.h>

#include <nitro/misc.h>
#include <nitro/os.h>
#include <nitro/pxi.h>
#include <nitro/mi.h>

#include <nitro/snd/common/seq.h>
#include <nitro/snd/common/capture.h>
#include <nitro/snd/common/work.h>
#include <nitro/snd/common/global.h>
#include <nitro/snd/common/util.h>
#include <nitro/snd/common/alarm.h>
#include <nitro/snd/common/main.h>

#pragma thumb off
void SetChannelVolume (u32 chBitMask, int volume, SNDChannelDataShift shift)
    {
        int ch;

        for (ch = 0; ch < SND_CHANNEL_NUM && chBitMask != 0; ch++, chBitMask >>= 1) {
            if ((chBitMask & 0x01) == 0)
                continue;
            SND_SetChannelVolume(ch, volume, shift);
        }
    }
