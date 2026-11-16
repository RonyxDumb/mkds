#pragma once

#include "types.h"

typedef struct Unk020e43a8 Unk020e43a8;

// 0x28-byte object built from a table.
typedef struct Unk020e4610 {
    /* 00 */ u32 field0;
    /* 04 */ u32 field4;
    /* 08 */ u32 field8;
    /* 0c */ u32 fieldC;
    /* 10 */ u32 field10;
    /* 14 */ u32 field14;
    /* 18 */ u32 field18;
    /* 1c */ u32 field1C;
    /* 20 */ u32 field20;
    /* 24 */ u32 field24;
} Unk020e4610;

extern Unk020e4610 *rotobj_sLogicPart;

// 0x2c-byte object built from a table.
typedef struct Unk020e466c {
    /* 00 */ u32 field0;
    /* 04 */ u32 field4;
    /* 08 */ u32 field8;
    /* 0c */ u32 fieldC;
    /* 10 */ u32 field10;
    /* 14 */ u32 field14;
    /* 18 */ u32 field18;
    /* 1c */ u32 field1C;
    /* 20 */ u32 field20;
    /* 24 */ u32 field24;
    /* 28 */ u32 field28;
} Unk020e466c;

// 0x40-byte object built from a table.
typedef struct Unk020e46c8 {
    /* 00 */ u32 field0;
    /* 04 */ u32 field4;
    /* 08 */ u32 field8;
    /* 0c */ u32 fieldC;
    /* 10 */ u32 field10;
    /* 14 */ u32 field14;
    /* 18 */ u32 field18;
    /* 1c */ u32 field1C;
    /* 20 */ u32 field20;
    /* 24 */ u32 field24;
    /* 28 */ u32 field28;
    /* 2c */ u32 field2C;
    /* 30 */ u32 field30;
    /* 34 */ u32 field34;
    /* 38 */ u32 field38;
    /* 3c */ u32 field3C;
} Unk020e46c8;

void rotcyl_update(u32 unused, Unk020e43a8 *object);
Unk020e4610 *rotcyl_setupLogicPart(void);
Unk020e466c *rotcyl_setupRenderPart(void);
Unk020e46c8 *rotcyl_setupRotBridgeConfig(void);
Unk020e46c8 *rotcyl_setupRotRoomConfig(void);
Unk020e46c8 *rotcyl_setupGearConfig(void);
void puku_init(Unk020e43a8 *pukupuku, Vec3 *position);
