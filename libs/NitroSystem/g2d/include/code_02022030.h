#pragma once

#include "types.h"
#include "g2d_NAN_load.h" // Unk02021dc8, Unk02021e40

// 0x1c bytes: NNSi_G2dSrtcSetInitialValue clears everything after the first word and sets field4 and field8 to
// 0x1000. NNSi_G2dSrtcSetSRTScale, NNSi_G2dSrtcSetSRTRotZ and NNSi_G2dSrtcSetTrans set a member and a bit of field12
// when field0 is 1.
typedef struct Unk02022438 {
    /* 00 */ u32 field0;
    /* 04 */ s32 field4;
    /* 08 */ s32 field8;
    /* 0c */ s16 fieldC;
    /* 0e */ s16 fieldE;
    /* 10 */ u16 field10;
    /* 12 */ u16 field12;
    /* 14 */ u8 field14[8];
} Unk02022438;

typedef struct NNSG2dCallBackFunctor {
    /* 00 */ u32 mType;
    /* 04 */ u32 mParam;
    /* 08 */ UnkFunc *mFunc;
    /* 0c */ u16 mFrameIdx;
} NNSG2dCallBackFunctor;

typedef struct Unk020224e0_s {
    /* 00 */ u16 field0;
    /* 02 */ u16 field2;
    /* 04 */ u16 field4;
} Unk020224e0_s;

typedef struct GXOamAttr {
    /* 00 */ u16 field0[4];
} GXOamAttr;

// Cell of a cell bank: the count, the attribute entries, then the bounds (absent when bit 0 of the bank's field2 is
// clear).
typedef struct Unk020224e0_c {
    /* 00 */ u16 field0;
    /* 02 */ u16 field2;
    /* 04 */ Unk020224e0_s *field4;
    /* 08 */ s16 field8;
    /* 0a */ s16 fieldA;
    /* 0c */ s16 fieldC;
    /* 0e */ s16 fieldE;
} Unk020224e0_c;

typedef struct Unk02022030 {
    /* 00 */ Unk02021e40 *field0;
    /* 04 */ u32 field4;
    /* 08 */ u32 field8;
    /* 0c */ s32 fieldC;
    /* 10 */ s32 field10;
    /* 14 */ u32 field14;
    /* 18 */ Unk02021dc8 *field18;
    /* 1c */ NNSG2dCallBackFunctor mCallbackFunctor;
    /* 2c */ Unk020224e0_c *field2C;
    /* 30 */ Unk02021dc8 *field30;
    /* 34 */ s32 field34;
    /* 38 */ Unk02022438 field38;
} Unk02022030;

// Seen through field0 of the element NNS_G2dTickAnimCtrl steps over: a word, then a halfword.
typedef struct Unk02022188 {
    /* 00 */ u32 field0;
    /* 04 */ u16 field4;
    /* 06 */ u16 field6;
} Unk02022188;

// Record at the first word of the element: ApplyCurrentAnimResult_ reads these members, except when the low byte of
// field4 of the header is 2 (then Unk020229b4).
typedef struct Unk020229c8 {
    /* 00 */ u16 field0;
    /* 02 */ u16 field2;
    /* 04 */ s32 field4;
    /* 08 */ s32 field8;
    /* 0c */ s16 fieldC;
    /* 0e */ s16 fieldE;
} Unk020229c8;

typedef struct Unk020229b4 {
    /* 00 */ u16 field0;
    /* 02 */ u16 field2;
    /* 04 */ s16 field4;
    /* 06 */ s16 field6;
} Unk020229b4;

void NNS_G2dBindAnimCtrl(Unk02022030 *pAnimCtrl, Unk02021dc8 *pAnimSequence);
void NNS_G2dResetAnimCtrlState(Unk02022030 *pAnimCtrl);
