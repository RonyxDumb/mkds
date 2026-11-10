#include "Main/Unknown/code_020cba30.h"
#include "registers.h"
#include "00/code_02181f98.h"
#include "code_0214a390.h"

void SetMenuEntryKind(u32 entryKind) {
    gMenuShared->mMenuEntryKind = entryKind;
}

void SetUnfilledNotEliminated(u32 value) {
    gMenuShared->mUnfilledNotEliminated = value;
}

void WriteMainBlendAlpha(u32 firstPlane, u32 secondPlane, u32 firstCoefficient, u32 secondCoefficient) {
    G2x_SetBlendAlpha_(&reg_G2_BLDCNT, firstPlane, secondPlane, firstCoefficient, secondCoefficient);
}

void MenuWriteSubBlendAlpha(u32 firstPlane, u32 secondPlane, u32 firstCoefficient, u32 secondCoefficient) {
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, firstPlane, secondPlane, firstCoefficient, secondCoefficient);
}
