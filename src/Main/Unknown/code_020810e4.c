#include "Main/Unknown/code_020810e4.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/unk_0217a000.h"

void rptc_stopElectricEffect(u32 kartIndex) {
    u32 value0 = kartIndex;
    u32 recordSize;
    u32 value2;
    u32 kartEffects;
    u32 effect;
    u32 zero;
    value2 = (u32) &rptc_sDriverEffects;
    recordSize = 0x58u;
    value2 = *(const u32 *) ((value2) + (0));
    kartEffects = (value0) * (recordSize) + (value2);
    value0 = *(const u32 *) ((kartEffects) + (48));
    effect = value0;
    zero = 0u;
    if (effect == zero) {
    }
    if (effect == zero) {
        return;
    }
    ptcm_killEmitterDirect((Unk0201ca6c *) value0);
    value0 = 0u;
    *(u32 *) ((kartEffects) + (48)) = value0;
}
