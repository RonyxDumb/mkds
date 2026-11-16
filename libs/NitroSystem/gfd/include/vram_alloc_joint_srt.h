#pragma once

#include "types.h"
#include "model_draw_state.h"

void NNSi_G3dGetJointScaleBasic(NNSG3dJntAnmResult *pResult, const s32 *scale, const u8 *cmd, u32 srtflag);
void NNSi_G3dSendJointSRTBasic(const NNSG3dJntAnmResult *result);
s32 CompressedTextureHandler(u32 texKey);
u32 TextureHandler(u32 szByte, BOOL is4x4comp, u32 opt);
s32 FreePlttVram_(u32 plttKey);
u32 PaletteHandler(u32 szByte, BOOL b4Pltt, u32 opt);
