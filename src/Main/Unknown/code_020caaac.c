#include "Main/Unknown/code_020caaac.h"
#include "registers.h"

#include "Main/Unknown/code_020caae8.h"
#include "code_0214a390.h"
#include "Main/Unknown/code_020cab58.h"
#include "Main/Unknown/code_020cab74.h"
#include "Main/Unknown/code_020cab8c.h"
#include "Main/Unknown/code_020caba4.h"

#pragma thumb on

void WriteEmblemChoisesScreenMap(void) {
    WriteEmblemChoisesTiles();
    WriteEmblemChoisesSelectedTiles(MoveEmblemChoisesIndex(0));
}

#pragma thumb off

u32 GetSubDispcntBits(void) {
    return (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
}

u32 EmblemChoisesWriteSubDispcntBits(u32 bits) {
    u32 value0 = bits;
    u32 registerValue;
    registerValue = reg_GXS_DB_DISPCNT;
    registerValue = (registerValue) & ~(0x1f00u);
    value0 = (registerValue) | ((value0 << 8));
    reg_GXS_DB_DISPCNT = value0;
    return value0;
}

void EmblemChoisesWriteSubBg0Offset(u32 offsetX, u32 offsetY) {
    reg_G2S_DB_BG0OFS = (offsetX & 0x1ff) | ((offsetY << 16) & 0x1ff0000);
}

void WriteSubBlendBrightness(u32 plane1, u32 plane2, u32 ev1, u32 ev2, s32 brightness) {
    G2x_SetBlendBrightnessExt_(&reg_G2S_DB_BLDCNT, plane1, plane2, ev1, ev2, brightness);
}

void EmblemChoisesWriteSubBlendAlpha(u32 plane1, u32 plane2, u32 ev1, u32 ev2) {
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, plane1, plane2, ev1, ev2);
}
