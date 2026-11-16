#include "Main/Menu/menu_entry_kind.h"
#include "registers.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "display_blend_affine_setup.h"
#include "Main/Menu/menu_shared_clear.h"

void SetSinglePlayerMenuTarget(u32 entryKind) {
    g_GlobalB488->mMenuEntryKind = entryKind;
}

void SetB488_B5(u32 value) {
    g_GlobalB488->mUnfilledNotEliminated = value;
}

void EnableAlphaSetBldcntBldalphaTop(u32 firstPlane, u32 secondPlane, u32 firstCoefficient, u32 secondCoefficient) {
    G2x_SetBlendAlpha_(&reg_G2_BLDCNT, firstPlane, secondPlane, firstCoefficient, secondCoefficient);
}

void EnableAlphaSetBldcntBldalphaSub(u32 firstPlane, u32 secondPlane, u32 firstCoefficient, u32 secondCoefficient) {
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, firstPlane, secondPlane, firstCoefficient, secondCoefficient);
}
