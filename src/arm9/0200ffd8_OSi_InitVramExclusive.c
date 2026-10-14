/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OSi_vramExclusive SDK_data_02170284
#define OSi_vramLockId SDK_data_02170288
#include "OS_vramExclusive.h"
#include "OS_system.h"
#include "code32.h"
extern u32 OSi_vramExclusive;
extern u16 OSi_vramLockId[9];
void OSi_InitVramExclusive(void)
{
    OSi_vramExclusive = 0x0000;

    for (s32 i = 0; i < 9; i++)
    {
        OSi_vramLockId[i] = 0;
    }
}
