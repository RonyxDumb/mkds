#pragma once

#include "types.h"

typedef struct Kart Kart;

// Stack frame of driver_2068494 from its stack offset 0: a halfword and four vectors.
typedef struct Unk02068494 {
    /* 00 */ s16 field0;
    /* 02 */ u8 field2[2];
    /* 04 */ Vec3 field4;
    /* 10 */ Vec3 field10;
    /* 1c */ Vec3 field1C;
    /* 28 */ Vec3 field28;
} Unk02068494;

void driver_handleDriftingPhases(Kart *kart);
void driver_setDriftLeftRightCount(Kart *kart, s32 charge);
void driver_2068494(Kart *kart, s32 b, s32 c);
void StructMQRacerEntry_SomeFn_25(Kart *kart, s32 b);
void StructMQRacerEntry_SomeFn_15(Kart *kart);
void driver_emitKillVoice(Kart *kart);
void StructMQRacerEntry_SomeFn_10(Kart *kart);
void driver_2068A64(Kart *kart, s32 b, s32 c);
void driver_killForMg(Kart *kart);
void StructMQRacerEntry_SomeFn_53(Kart *kart);
