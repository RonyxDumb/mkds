#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_0210b000.h" // Unk0210b7a8
#include "code_0212bcac.h"

// 0x28-byte part at 0xa0 and 0xc8 of Unk020a826c: the four words at 0x00 go to sub_210B734 or sub_210B760 with
// the value at 0x1c, 0x0c holds mobj_calcXZCamDist's result for the vector at 0x10, 0x24 is set to 0, 1
// or 2 (mobj0008_updateInstanceLogic); mobj0008_20A8ED8 writes the vector at 0x10 and the word at 0x20.
typedef struct Unk020a826c_a0 {
    /* 00 */ Unk0210b7a8 field0;
    /* 10 */ Vec3 mSourcePos;
    /* 1c */ NNSSndSeqPlayer **mSndHandleSlot;
    /* 20 */ BOOL field20;
    /* 24 */ s32 field24;
} Unk020a826c_a0;

// Object of mobj0008_updateInstanceLogic: the shared MapObject part, two Unk020a826c_a0 and a value at 0xf0 (0 to 6) that
// selects what mobj0008_updateInstanceLogic does.
typedef struct Unk020a826c {
    /* 000 */ MapObject field0;
    /* 0a0 */ Unk020a826c_a0 fieldA0;
    /* 0c8 */ Unk020a826c_a0 fieldC8;
    /* 0f0 */ s32 mState;
} Unk020a826c;

void mobj0008_updateInstanceLogic(void *a, Unk020a826c *p);
