#pragma once

#include "types.h"
#include "Main/Graphics/nsbmd_render_obj.h"

// A shadow model: the model, its polygon id and alpha, and a flag that says if it is drawn.
typedef struct ShadowModel {
    /* 00 */ Nsbmd mNsbmd;
    /* 6c */ u16 mPolygonId;
    /* 6e */ u16 mAlpha;
// Bit 0: the shadow is drawn.
    /* 70 */ u16 mFlags;
    /* 72 */ u8 mUnk_72[2];
} ShadowModel;

void DrawShadowModel(ShadowModel *shadowModel, u32 unusedParam1, u32 unusedParam2);

// ShadowModel.mAlpha that InitShadowModel and InitShadowModelFromResMdl set (0x1f is fully opaque).
#define KART_SHADOW_ALPHA 0xd
