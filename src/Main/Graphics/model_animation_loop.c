#include "Main/Graphics/model_animation_loop.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Graphics/model_animation.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02165000.h"
#include "registers.h"

void ResetModelAnimationWithLoopFlag(ModelAnimationFrameLoop *modelAnimation, s32 frameCountFixed, u16 loopFlag) {
    modelAnimation->mLoopMode = loopFlag == 0 ? MODEL_ANIMATION_LOOP_MODE_CLAMP : MODEL_ANIMATION_LOOP_MODE_WRAP;
    modelAnimation->mDone = 0;
    modelAnimation->mFrameStep = 0x1000;
    modelAnimation->mFrameCountFixed = frameCountFixed;
    modelAnimation->mFrameIndex = 0;
    modelAnimation->mLoopsDone = 0;
    modelAnimation->mLoopCount = 0;
}

void ApplyModelAnimationLoopMode(ModelAnimationFrameLoop *modelAnimation) {
    s32 frameIndex;
    switch (modelAnimation->mLoopMode) {
        case MODEL_ANIMATION_LOOP_MODE_WRAP:
            if (modelAnimation->mFrameIndex >= modelAnimation->mFrameCountFixed) {
                modelAnimation->mFrameIndex = modelAnimation->mFrameIndex - modelAnimation->mFrameCountFixed;
            } else if (modelAnimation->mFrameIndex <= 0) {
                frameIndex = modelAnimation->mFrameIndex;
                modelAnimation->mFrameIndex = modelAnimation->mFrameCountFixed - 0x1000 + frameIndex;
            }
            break;
        case MODEL_ANIMATION_LOOP_MODE_CLAMP:
            if (modelAnimation->mFrameIndex >= modelAnimation->mFrameCountFixed - 0x1000) {
                modelAnimation->mFrameIndex = modelAnimation->mFrameCountFixed - 0x1000;
                modelAnimation->mFrameStep = 0;
                modelAnimation->mDone = 1;
            }
            break;
        case MODEL_ANIMATION_LOOP_MODE_LOOP_COUNT:
            if (modelAnimation->mLoopsDone >= modelAnimation->mLoopCount) {
                return;
            }
            if (modelAnimation->mFrameIndex >= modelAnimation->mFrameCountFixed) {
                modelAnimation->mFrameIndex = modelAnimation->mFrameIndex - modelAnimation->mFrameCountFixed;
                modelAnimation->mLoopsDone++;
            } else if (modelAnimation->mFrameIndex <= 0) {
                frameIndex = modelAnimation->mFrameIndex;
                modelAnimation->mFrameIndex = modelAnimation->mFrameCountFixed - 0x1000 + frameIndex;
                modelAnimation->mLoopsDone++;
            }
            if (modelAnimation->mLoopsDone >= modelAnimation->mLoopCount) {
                modelAnimation->mFrameIndex = modelAnimation->mFrameCountFixed - 0x1000;
                modelAnimation->mFrameStep = 0;
                modelAnimation->mDone = 1;
            }
            break;
    }
}

void AdvanceModelAnimationFrame(ModelAnimationFrameLoop *modelAnimation) {
    modelAnimation->mDone = 0;
    modelAnimation->mFrameIndex = modelAnimation->mFrameIndex + modelAnimation->mFrameStep;
    ApplyModelAnimationLoopMode(modelAnimation);
}

void DrawKartNameTagQuadVertices(s32 texWidthFixed, s32 texHeightFixed) {
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
