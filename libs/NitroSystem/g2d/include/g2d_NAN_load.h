#pragma once

#include "types.h"

// Two words.
typedef struct NNSG2dCellVramTransferData {
    /* 00 */ u32 mSrcDataOffset;
    /* 04 */ u32 mSzByte;
} NNSG2dCellVramTransferData;

// Element of an animation sequence: mUnk_00 is the address of the record of the frame, mUnk_04 how long it lasts.
typedef struct NNSG2dAnimFrameData {
    /* 00 */ u32 mPContent;
    /* 04 */ u16 mFrames;
    /* 06 */ u16 mPad16;
} NNSG2dAnimFrameData;

// 16 bytes: mUnk_00 elements of 8 bytes at mUnk_0c.
typedef struct NNSG2dAnimSequenceData {
    /* 00 */ u16 mNumFrames;
    /* 02 */ u16 mLoopStartFrameIdx;
    /* 04 */ u32 mAnimType;
    /* 08 */ u32 mPlayMode;
    /* 0c */ NNSG2dAnimFrameData *mPAnmFrameArray;
} NNSG2dAnimSequenceData;

typedef struct NNSG2dAnimDataSRT NNSG2dAnimDataSRT;

// Header of an animation bank: mUnk_04, mUnk_08 and mUnk_0c are offsets from the start that NNS_G2dUnpackNAN turns
// into addresses. mUnk_04 holds mUnk_00 sequences.
typedef struct AnimBank {
    /* 00 */ u16 mNumSequences;
    /* 02 */ u16 mNumTotalFrames;
    /* 04 */ NNSG2dAnimSequenceData *mPSequenceArrayHead;
    /* 08 */ NNSG2dAnimFrameData *mPFrameArrayHead;
    /* 0c */ NNSG2dAnimDataSRT *mPAnimContents;
} AnimBank;

// Header of the VRAM transfer data of a cell bank: mUnk_04 is an offset from the start of this header that
// NNS_G2dUnpackNCE turns into the address of the table of NNSG2dCellVramTransferData, one per cell.
typedef struct NNSG2dVramTransferData {
    /* 00 */ u32 mSzByteMax;
    /* 04 */ NNSG2dCellVramTransferData *mPCellTransferDataArray;
} NNSG2dVramTransferData;

// Header of a cell bank: mUnk_04 and mUnk_0c are offsets from the start that NNS_G2dUnpackNCE turns into addresses.
// mUnk_04 holds mUnk_00 entries (16 bytes, or 8 bytes without bit 0 of mUnk_02, see NNS_G2dGetCellDataByIdx).
typedef struct NNSG2dCellDataBank {
    /* 00 */ u16 mNumCells;
    /* 02 */ u16 mCellBankAttr;
    /* 04 */ u32 mPCellDataArrayHead;
    /* 08 */ u32 mUnk_08;
    /* 0c */ NNSG2dVramTransferData *mPVramTransferData;
} NNSG2dCellDataBank;

NNSG2dAnimSequenceData *NNS_G2dGetAnimSequenceByIdx(AnimBank *bank, u32 idx);
void NNS_G2dUnpackNAN(AnimBank *bank);
