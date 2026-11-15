#pragma once

#include "types.h"

// The constants every setup of a RandomState64 stores in mMultiplier and mIncrement.
#define RANDOM_STATE64_MULTIPLIER 0x5d588b656c078965
#define RANDOM_STATE64_INCREMENT 0x269ec3

// Three 64-bit words: x, a and c of x = x * a + c (x = x * [8] + [0x10] in TallyPickedCourse). GetRaceRandom and
// GetMapObjectRandom return one; ConnectionWork has one at 0x1ee8, RaceProgress three and WiFiSession one at 0x1954.
typedef struct RandomState64 {
    /* 00 */ u64 mValue;
    /* 08 */ u64 mMultiplier;
    /* 10 */ u64 mIncrement;
} RandomState64;

typedef struct MapObject MapObject;

RandomState64 *GetRaceRandom(void);
RandomState64 *GetMapObjectRandom(void);
void SetRaceRandomPointers(void);
void UnparkMapObject(MapObject *mapObject);
void ParkMapObject(MapObject *mapObject);

extern const u16 gParkMapObjectFlag;
extern const u16 gParkMapObjectLastFlag;
extern const u16 gParkMapObjectFourthFlag;
extern const u16 gParkMapObjectThirdFlag;
extern const u16 gParkMapObjectSecondFlag;
extern struct RandomState64 *gMapObjectRandom;
extern struct RandomState64 *gRaceRandom;
