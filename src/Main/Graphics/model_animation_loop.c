#include "Main/Graphics/model_animation_loop.h"
#include "Main/Graphics/model_animation_loop_modes.h"
#include "Main/Graphics/model_animation.h"
#include "Main/Kart/kart_palette_stem_tables.h"
#include "Main/Kart/kart_effect_param_tables.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/Kart/kart_name_tags.h"
#include "registers.h"

const u16 gKartNameTagQuadVertices[12] = {0xf000, 0x2000, 0, 0xf000, 0, 0, 0x1000, 0, 0, 0x1000, 0x2000, 0};
const u32 gKartNameTagColorQuadTexture[8] = {0x55555555, 1, 1, 1, 1, 1, 1, 1};
const u32 gKartNameTagMaskedPalette[8] = {0x1f, 0x22e03fb, 0x3fb0000, 0x22e, 0x22e03fb, 0, 0, 0};
const u32 gKartNameTagMaskedTexture[128] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x77000000, 0x00000007, 0x04440000, 0x00000000, 0x00011100, 0x00000000, 0x00000000, 0x00000000,
    0x87700000, 0x00000077, 0x44544000, 0x00000000, 0x00112110, 0x00000000, 0x00000000, 0x00000000,
    0x89700000, 0x00000079, 0x46564000, 0x00000000, 0x00132310, 0x00000000, 0x00000000, 0x00000000,
    0x88777700, 0x00077778, 0x45554444, 0x11000444, 0x11122211, 0x00000001, 0x00000000, 0x00000000,
    0x88888700, 0x00078888, 0x55555554, 0x21000455, 0x22222222, 0x00000001, 0x00000000, 0x00000000,
    0x88887700, 0x00077888, 0x55555544, 0x11000445, 0x12222222, 0x00000001, 0x00000000, 0x00000000,
    0x88877000, 0x00007788, 0x55555440, 0x10000044, 0x11222221, 0x00000000, 0x00000000, 0x00000000,
    0x88897000, 0x00007988, 0x55555640, 0x10000046, 0x13222223, 0x00000000, 0x00000000, 0x00000000,
    0x79887000, 0x00007889, 0x56465540, 0x10000045, 0x12231322, 0x00000000, 0x00000000, 0x00000000,
    0x77987000, 0x00007897, 0x64446540, 0x10000045, 0x12311132, 0x00000000, 0x00000000, 0x00000000,
    0x07777000, 0x00007777, 0x44044440, 0x10000044, 0x11110111, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
};

void ResetModelAnimationWithLoopFlag(ModelAnimationFrameLoop *modelAnimation, s32 frameCountFixed, u16 loopFlag) {
    modelAnimation->mLoopMode = loopFlag == 0 ? MODEL_ANIMATION_LOOP_MODE_CLAMP : MODEL_ANIMATION_LOOP_MODE_WRAP;
    modelAnimation->mDone = 0;
    modelAnimation->mFrameIndexFixedPerCall = FIXED12_UNIT;
    modelAnimation->mFrameCountFixed = frameCountFixed;
    modelAnimation->mFrameIndexFixed = 0;
    modelAnimation->mLoopsDone = 0;
    modelAnimation->mLoopCount = 0;
}

void ApplyModelAnimationLoopMode(ModelAnimationFrameLoop *modelAnimation) {
    s32 frameIndex;
    switch (modelAnimation->mLoopMode) {
        case MODEL_ANIMATION_LOOP_MODE_WRAP:
            if (modelAnimation->mFrameIndexFixed >= modelAnimation->mFrameCountFixed) {
                modelAnimation->mFrameIndexFixed = modelAnimation->mFrameIndexFixed - modelAnimation->mFrameCountFixed;
            } else if (modelAnimation->mFrameIndexFixed <= 0) {
                frameIndex = modelAnimation->mFrameIndexFixed;
                modelAnimation->mFrameIndexFixed = modelAnimation->mFrameCountFixed - 0x1000 + frameIndex;
            }
            break;
        case MODEL_ANIMATION_LOOP_MODE_CLAMP:
            if (modelAnimation->mFrameIndexFixed >= modelAnimation->mFrameCountFixed - 0x1000) {
                modelAnimation->mFrameIndexFixed = modelAnimation->mFrameCountFixed - 0x1000;
                modelAnimation->mFrameIndexFixedPerCall = 0;
                modelAnimation->mDone = 1;
            }
            break;
        case MODEL_ANIMATION_LOOP_MODE_LOOP_COUNT:
            if (modelAnimation->mLoopsDone >= modelAnimation->mLoopCount) {
                return;
            }
            if (modelAnimation->mFrameIndexFixed >= modelAnimation->mFrameCountFixed) {
                modelAnimation->mFrameIndexFixed = modelAnimation->mFrameIndexFixed - modelAnimation->mFrameCountFixed;
                modelAnimation->mLoopsDone++;
            } else if (modelAnimation->mFrameIndexFixed <= 0) {
                frameIndex = modelAnimation->mFrameIndexFixed;
                modelAnimation->mFrameIndexFixed = modelAnimation->mFrameCountFixed - 0x1000 + frameIndex;
                modelAnimation->mLoopsDone++;
            }
            if (modelAnimation->mLoopsDone >= modelAnimation->mLoopCount) {
                modelAnimation->mFrameIndexFixed = modelAnimation->mFrameCountFixed - 0x1000;
                modelAnimation->mFrameIndexFixedPerCall = 0;
                modelAnimation->mDone = 1;
            }
            break;
    }
}

void AdvanceModelAnimationFrame(ModelAnimationFrameLoop *modelAnimation) {
    modelAnimation->mDone = 0;
    modelAnimation->mFrameIndexFixed = modelAnimation->mFrameIndexFixed + modelAnimation->mFrameIndexFixedPerCall;
    ApplyModelAnimationLoopMode(modelAnimation);
}

void DrawKartNameTagQuadVertices(s32 texWidthFixed, s32 texHeightFixed, u32 color) {
    u32 heightTexCoord;
    reg_G3_TEXCOORD = 0;
    reg_G3_VTX_16 = gKartNameTagQuadVertices[0] | gKartNameTagQuadVertices[1] << 16;
    reg_G3_VTX_16 = gKartNameTagQuadVertices[2];
    heightTexCoord = (u16) ((texHeightFixed << 8) >> 16);
    reg_G3_TEXCOORD = heightTexCoord << 16;
    reg_G3_VTX_16 = gKartNameTagQuadVertices[3] | gKartNameTagQuadVertices[4] << 16;
    reg_G3_VTX_16 = gKartNameTagQuadVertices[5];
    reg_G3_TEXCOORD = (u16) ((texWidthFixed << 8) >> 16) | heightTexCoord << 16;
    reg_G3_VTX_16 = gKartNameTagQuadVertices[6] | gKartNameTagQuadVertices[7] << 16;
    reg_G3_VTX_16 = gKartNameTagQuadVertices[8];
    reg_G3_TEXCOORD = (u16) ((texWidthFixed << 8) >> 16);
    reg_G3_VTX_16 = gKartNameTagQuadVertices[9] | gKartNameTagQuadVertices[10] << 16;
    reg_G3_VTX_16 = gKartNameTagQuadVertices[11];
}

void ColoredDrawKartNameTagQuadVertices(s32 texWidthFixed, s32 texHeightFixed) {
    u32 heightTexCoord;
    reg_G3_TEXCOORD = 0;
    reg_G3_VTX_16 = gKartNameTagQuadVertices[0] | gKartNameTagQuadVertices[1] << 16;
    reg_G3_VTX_16 = gKartNameTagQuadVertices[2];
    heightTexCoord = (u16) ((texHeightFixed << 8) >> 16);
    reg_G3_TEXCOORD = heightTexCoord << 16;
    reg_G3_VTX_16 = gKartNameTagQuadVertices[3] | gKartNameTagQuadVertices[4] << 16;
    reg_G3_VTX_16 = gKartNameTagQuadVertices[5];
    reg_G3_TEXCOORD = (u16) ((texWidthFixed << 8) >> 16) | heightTexCoord << 16;
    reg_G3_VTX_16 = gKartNameTagQuadVertices[6] | gKartNameTagQuadVertices[7] << 16;
    reg_G3_VTX_16 = gKartNameTagQuadVertices[8];
    reg_G3_TEXCOORD = (u16) ((texWidthFixed << 8) >> 16);
    reg_G3_VTX_16 = gKartNameTagQuadVertices[9] | gKartNameTagQuadVertices[10] << 16;
    reg_G3_VTX_16 = gKartNameTagQuadVertices[11];
}

void DrawKartNameTagColorQuad(u32 color) {
    s32 scaleY;
    s32 scaleX;
    reg_G3_COLOR = color;
    scaleY = gKartNameTagColorQuadScaleY;
    scaleX = gKartNameTagColorQuadScaleX;
    reg_G3_MTX_SCALE = scaleX;
    reg_G3_MTX_SCALE = scaleY;
    reg_G3_MTX_SCALE = 0x1333;
    reg_G3_VTX_16 = gKartNameTagQuadVertices[0] | gKartNameTagQuadVertices[1] << 16;
    reg_G3_VTX_16 = gKartNameTagQuadVertices[2];
    reg_G3_VTX_16 = gKartNameTagQuadVertices[3] | gKartNameTagQuadVertices[4] << 16;
    reg_G3_VTX_16 = gKartNameTagQuadVertices[5];
    reg_G3_VTX_16 = gKartNameTagQuadVertices[6] | gKartNameTagQuadVertices[7] << 16;
    reg_G3_VTX_16 = gKartNameTagQuadVertices[8];
    reg_G3_VTX_16 = gKartNameTagQuadVertices[9] | gKartNameTagQuadVertices[10] << 16;
    reg_G3_VTX_16 = gKartNameTagQuadVertices[11];
}
