#pragma once

#include "types.h"
#include "Main/Unknown/code_020e0680.h"

// Object holding a pointer at 0x0 and two vectors.
typedef struct Unk020e04b0 {
    /* 00 */ Unk020e005c *field0;
    /* 04 */ Vec3 field4;
    /* 10 */ Vec3 field10;
} Unk020e04b0;

// Object holding a pointer at 0x0 and a vector at 0x4.
typedef struct Unk020e0448 {
    /* 00 */ Unk020e3ef4 *field0;
    /* 04 */ Vec3 field4;
} Unk020e0448;

void kblock_update(void *a0, Unk020e005c *koopaBlock);
void *kblock_setupLogicPart(void);
void *kblock_setupRenderPart(void);
void *kblock_setupConfig(void);
s32 sub_20E0448(Unk020e0448 *link);
BOOL sub_20E04B0(Unk020e04b0 *link, Vec3 *outPosition, Vec3 *outVelocity);
void sub_20E0538(Unk020e04b0 *link, Vec3 *outPosition);
void sub_20E0584(Unk020e005c *object, Vec3 *position, Vec3 *velocity, Unk020e04b0 *link);
