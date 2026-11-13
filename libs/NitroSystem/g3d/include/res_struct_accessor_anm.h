#pragma once

#include "types.h"
#include "code_02013740.h"

NNSG3dResDictTexPatAnmData *NNSi_G3dGetTexPatAnmDataByIdx(const NNSG3dResTexPatAnm *pPatAnm, u32 idx);

NNSG3dResTexPatAnmFV *NNSi_G3dGetTexPatAnmFV(const NNSG3dResTexPatAnm *pPatAnm, u32 idx, u32 frame);

const u32 *NNSi_G3dGetTexPatAnmPlttNameByIdx(const NNSG3dResTexPatAnm *pPatAnm, u8 plttIdx);
const u32 *NNSi_G3dGetTexPatAnmTexNameByIdx(const NNSG3dResTexPatAnm *pPatAnm, u8 texIdx);

extern u32 data_02161924[1];
extern u32 data_02161928[2];
extern Vec3 data_02161930[3];
