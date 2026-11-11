#pragma once

#include "types.h"

// Two words.
typedef struct NNSG2dCellVramTransferData {
    /* 00 */ u32 mSrcDataOffset;
    /* 04 */ u32 mSzByte;
} NNSG2dCellVramTransferData;

// Element of an animation sequence: mUnk_00 is the address of the record of the frame, mUnk_04 how long it lasts.
typedef struct Unk02022188 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
} Unk02022188;

// 16 bytes: mUnk_00 elements of 8 bytes at mUnk_0c.
typedef struct NNSG2dAnimSequenceData {
    /* 00 */ u16 mNumFrames;
    /* 02 */ u16 mLoopStartFrameIdx;
    /* 04 */ u32 mAnimType;
    /* 08 */ u32 mPlayMode;
    /* 0c */ Unk02022188 *mPAnmFrameArray;
} NNSG2dAnimSequenceData;

typedef struct Unk020229c8 Unk020229c8;

// Header of an animation bank: mUnk_04, mUnk_08 and mUnk_0c are offsets from the start that NNS_G2dUnpackNAN turns
// into addresses. mUnk_04 holds mUnk_00 sequences.
typedef struct Unk02021db0 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ NNSG2dAnimSequenceData *mUnk_04;
    /* 08 */ Unk02022188 *mUnk_08;
    /* 0c */ Unk020229c8 *mUnk_0c;
} Unk02021db0;

// Header of the VRAM transfer data of a cell bank: mUnk_04 is an offset from the start of this header that
// NNS_G2dUnpackNCE turns into the address of the table of NNSG2dCellVramTransferData, one per cell.
typedef struct NNSG2dVramTransferData {
    /* 00 */ u32 mSzByteMax;
    /* 04 */ NNSG2dCellVramTransferData *mPCellTransferDataArray;
} NNSG2dVramTransferData;

// Header of a cell bank: mUnk_04 and mUnk_0c are offsets from the start that NNS_G2dUnpackNCE turns into addresses.
// mUnk_04 holds mUnk_00 entries (16 bytes, or 8 bytes without bit 0 of mUnk_02, see NNS_G2dGetCellDataByIdx).
typedef struct Unk02021dc8 {
    /* 00 */ u16 mNumCells;
    /* 02 */ u16 mCellBankAttr;
    /* 04 */ u32 mPCellDataArrayHead;
    /* 08 */ u32 mUnk_08;
    /* 0c */ NNSG2dVramTransferData *mPVramTransferData;
} Unk02021dc8;

NNSG2dAnimSequenceData *NNS_G2dGetAnimSequenceByIdx(Unk02021db0 *bank, u32 idx);
void NNS_G2dUnpackNAN(Unk02021db0 *bank);
