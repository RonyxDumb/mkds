/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts FUN_037faf70
#define OS_RestoreInterrupts FUN_037faf84
#define OSi_PreviousVCount SDK_data_038078a0
#define OSi_VFrameCount SDK_data_038078a4
#define OSi_GetVFrame FUN_037fa920
#include <nitro.h>
extern s32 OSi_PreviousVCount;
extern s32 OSi_VFrameCount;
#pragma thumb off
s32 OSi_GetVFrame (s32 vcount)
{
    OSIntrMode enabled = OS_DisableInterrupts();

    if (vcount < OSi_PreviousVCount) {
        OSi_VFrameCount++;
    }

    OSi_PreviousVCount = vcount;

    (void)OS_RestoreInterrupts(enabled);
    return OSi_VFrameCount;
}
