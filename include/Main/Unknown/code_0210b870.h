#pragma once

#include "types.h"

struct MapObjectSound;

// The four words of data_0216ca48, read as one 16-byte object.
typedef struct Unk0216ca48 {
    /* 00 */ u32 field0;
    /* 04 */ void *field4;
    /* 08 */ u32 field8;
    /* 0c */ u32 fieldC;
} Unk0216ca48;

#include "Main/Unknown/code_0206bcb0.h" // Kart

extern Unk0216ca48 data_0216ca48;

void nullsub_13(void);
void sub_210B874(struct MapObjectSound *mapSound, s32 fixedValue);
int sub_210B8BC(void *soundSource, s32 fixedValue);
void func_0210b8f4(void *position, s32 distanceSquared);
void func_0210b924(void *position, s32 distanceSquared);
void sub_210B98C(struct MapObjectSound *mapSound, s32 soundId);
void sub_210BA38(struct MapObjectSound *mapSound, s32 soundId);
void func_0210ba78(void *mapSound, s32 baseSoundId);
u32 sub_210BAC0(void);
