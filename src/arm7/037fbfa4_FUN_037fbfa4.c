/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SinTable SDK_data_03806f1c
#define SND_SinIdx FUN_037fbfa4
#include <nitro/snd/common/util.h>
#include <nitro/snd/common/channel.h>
    #include <nitro/os.h>
extern const s8 SinTable[SND_SIN_TABLE_SIZE + 1];
#pragma thumb off
    s8 SND_SinIdx (int index)
    {
        SDK_MINMAX_ASSERT(index, 0, SND_SIN_PERIOD - 1);

        if (index < SND_SIN_TABLE_SIZE) {
            return SinTable[index];
        }
        if (index < SND_SIN_TABLE_SIZE * 2) {
            return SinTable[SND_SIN_TABLE_SIZE - (index - SND_SIN_TABLE_SIZE)];
        }
        if (index < SND_SIN_TABLE_SIZE * 3) {
            return (s8)(-SinTable[index - SND_SIN_TABLE_SIZE * 2]);
        }
        return (s8)(-SinTable[SND_SIN_TABLE_SIZE - (index - SND_SIN_TABLE_SIZE * 3)]);
    }
