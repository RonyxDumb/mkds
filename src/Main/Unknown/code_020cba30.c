#include "Main/Unknown/code_020cba30.h"
#include "registers.h"
#include "00/code_02181f98.h"
#include "code_0214a390.h"

void SetMenuEntryKind(u32 entryKind) {
    data_0217b488->mMenuEntryKind = entryKind;
}

void func_020cbaa8(u32 value) {
    data_0217b488->mUnk_10 = value;
}

void WriteMainBlendAlpha(u32 firstPlane, u32 secondPlane, u32 firstCoefficient, u32 secondCoefficient) {
    G2x_SetBlendAlpha_(&reg_G2_BLDCNT, firstPlane, secondPlane, firstCoefficient, secondCoefficient);
}

void MenuWriteSubBlendAlpha(u32 firstPlane, u32 secondPlane, u32 firstCoefficient, u32 secondCoefficient) {
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, firstPlane, secondPlane, firstCoefficient, secondCoefficient);
}
