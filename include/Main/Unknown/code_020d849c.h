#pragma once

#include "types.h"
#include "Main/Unknown/code_020e005c.h"
#include "Main/Unknown/code_02042044.h"

// Object of 0x38 bytes whose first 0x24 bytes are an GroupFollower (pwex_update,
// pwex_init, pw_reverse).
typedef struct GroupFollowerWithSpeeds {
    /* 00 */ GroupFollower field0;
    /* 24 */ s32 mSpeedPerEntryUnit;
    /* 28 */ s32 mDefaultSpeed;
    /* 2c */ s32 mFromSpeed;
    /* 30 */ s32 field30;
    /* 34 */ s32 mToSpeed;
} GroupFollowerWithSpeeds;

// An Segment (pw_setupPoint and pw_interpolateXZLinearY), then three words.
typedef struct SegmentProgress {
    /* 00 */ Segment field0;
    /* 54 */ s32 field54;
    /* 58 */ s32 field58;
    /* 5c */ s32 field5C;
} SegmentProgress;

void pw_reverse(GroupFollower *follower);
void pwex_init(GroupFollowerWithSpeeds *follower, u16 entryValue, s32 entryIndex);
s32 pwex_update(GroupFollowerWithSpeeds *follower);
void pwex_20D84C0(SegmentProgress *segmentProgress, s32 a);
BOOL pwex_20D849C(SegmentProgress *segmentProgress);
