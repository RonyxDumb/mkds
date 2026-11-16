#pragma once

#include "types.h"

// Two words.
typedef struct NNSG2dCellVramTransferData {
    /* 00 */ u32 mSrcDataOffset;
    /* 04 */ u32 mSzByte;
} NNSG2dCellVramTransferData;

// Element of an animation sequence: mPContent is the address of the record of the frame, mFrames how long it lasts.
typedef struct NNSG2dAnimFrameData {
    /* 00 */ u32 mPContent;
    /* 04 */ u16 mFrames;
    /* 06 */ u16 mPad16;
} NNSG2dAnimFrameData;

// Values of NNSG2dAnimSequenceData.mPlayMode and NNSG2dCellAnimation.mOverriddenPlayMode (0 there means use the
// sequence's own mode). The ping-pong modes turn around at each end of the sequence.
#define G2D_PLAY_MODE_FROM_SEQUENCE 0
#define G2D_PLAY_MODE_FORWARD 1
#define G2D_PLAY_MODE_FORWARD_LOOP 2
#define G2D_PLAY_MODE_PING_PONG 3
#define G2D_PLAY_MODE_PING_PONG_LOOP 4

// Low byte of NNSG2dAnimSequenceData.mAnimType.
#define G2D_ANIM_TYPE_MASK 0xff

// An animation sequence: its frame count, loop start frame, animation type, play mode and array of frames.
typedef struct NNSG2dAnimSequenceData {
    /* 00 */ u16 mNumFrames;
    /* 02 */ u16 mLoopStartFrameIdx;
    /* 04 */ u32 mAnimType;
    /* 08 */ u32 mPlayMode;
    /* 0c */ NNSG2dAnimFrameData *mPAnmFrameArray;
} NNSG2dAnimSequenceData;

typedef struct NNSG2dAnimDataSRT NNSG2dAnimDataSRT;

// Header of an animation bank: mPSequenceArrayHead, mPFrameArrayHead and mPAnimContents are offsets from the start that
// NNS_G2dUnpackNAN turns into addresses. mPSequenceArrayHead holds mNumSequences sequences.
typedef struct AnimBank {
    /* 00 */ u16 mNumSequences;
    /* 02 */ u16 mNumTotalFrames;
    /* 04 */ NNSG2dAnimSequenceData *mPSequenceArrayHead;
    /* 08 */ NNSG2dAnimFrameData *mPFrameArrayHead;
    /* 0c */ NNSG2dAnimDataSRT *mPAnimContents;
} AnimBank;

// Header of the VRAM transfer data of a cell bank: mPCellTransferDataArray is an offset from the start of this
// header that NNS_G2dUnpackNCE turns into the address of the table of NNSG2dCellVramTransferData, one per cell.
typedef struct NNSG2dVramTransferData {
    /* 00 */ u32 mSzByteMax;
    /* 04 */ NNSG2dCellVramTransferData *mPCellTransferDataArray;
} NNSG2dVramTransferData;

// A cell bank: its cell count and attributes, the array of cells, the mapping mode and the VRAM transfer data.
// mPCellDataArrayHead is an offset and mPVramTransferData is an offset when not 0, until NNS_G2dUnpackNCE turns them
// into addresses.
typedef struct NNSG2dCellDataBank {
    /* 00 */ u16 mNumCells;
    /* 02 */ u16 mCellBankAttr;
    /* 04 */ u32 mPCellDataArrayHead;
    /* 08 */ u32 mMappingMode;
    /* 0c */ NNSG2dVramTransferData *mPVramTransferData;
} NNSG2dCellDataBank;

NNSG2dAnimSequenceData *NNS_G2dGetAnimSequenceByIdx(AnimBank *bank, u32 idx);
void NNS_G2dUnpackNAN(AnimBank *bank);
