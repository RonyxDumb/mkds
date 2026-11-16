#pragma once

#include "types.h"
#include "code_0212bcac.h"

// Object gSeqVariableReadings: a signed halfword at 0x00, a signed halfword at 0x02, a signed word at 0x04 and four
// bytes at 0x08; sndvar_getVarField4 and sndvar_getVarField4IsZero read the word at 0x04,
// sndvar_update reads and writes all of them, and ResetSeqVariableReadings writes all of them.
typedef struct SeqVariableReading {
    /* 00 */ s16 mValue;
    /* 02 */ s16 mPrevValue;
    /* 04 */ s32 mSinceChangeFrames;
    /* 08 */ u8 mVariableNo[4];
} SeqVariableReading;

extern SeqVariableReading gSeqVariableReadings[];

void ResetSeqVariableReadings(void);
void sndvar_update(NNSSndSeqPlayer **handle);
u32 sndvar_getVarField4IsZero(u32 slot);
u32 sndvar_getVarField4(u32 slot);
