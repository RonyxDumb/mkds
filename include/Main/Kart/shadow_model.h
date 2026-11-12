#pragma once

#include "types.h"
#include "Main/Graphics/nsbmd_render_obj.h"

// Object DrawShadowModel works on.
typedef struct ShadowModel {
    /* 00 */ Nsbmd mNsbmd;
    /* 6c */ u16 mPolygonId;
    /* 6e */ u16 mAlpha;
// Bit 0: the shadow is drawn.
    /* 70 */ u16 mFlags;
    /* 72 */ u8 mUnk_72[2];
} ShadowModel;

void DrawShadowModel(ShadowModel *shadowModel, u32 unusedParam1, u32 unusedParam2);
