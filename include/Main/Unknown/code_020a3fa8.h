#pragma once

#include "types.h"
#include "Main/MapObjects/balloon.h" // Balloon
#include "code_02146d78.h"
#include "Main/MapObjects/attractor.h" // MapObject

// The balloons of one kart (0x38 bytes, one per kart index in the kind 0x69 object; Standings.mKartBalloons points at
// the first): the list of its Balloon objects with the state that makes, inflates and holds them.
typedef struct KartBalloons {
    // Frames left before the next balloon is made (state 0); 30 after a balloon is finished with none left to make, 0
    // when one is gone.
    /* 00 */ s32 mSpawnTimer;
    // Balloons state 1 still makes: from the course row's word or 1; counted down by each balloon made.
    /* 04 */ s32 mRemainingSpawnCount;
    /* 08 */ s32 mSwing;
    /* 0c */ s32 mSwingPerFrame;
    // The kart's balloons in order; the one being inflated is at the index equal to the kart's count.
    /* 10 */ Balloon *mBalloons[8];
    // Frame index every balloon of this kart is created with (Balloon.mNsbtpFrameIndex): the course row's word when it
    // is non-zero, else team index 0 gives 1, team index 1 gives 3, any other value the kart index. Never stepped.
    /* 30 */ u16 mBalloonNsbtpFrameIndex;
    /* 32 */ u8 mUnk_32[0x2];
    // Switched on by UpdateKartBalloons for this kart (0 to 4); the hit callbacks also store 4.
    /* 34 */ s32 mState;
} KartBalloons;

// Object of map object kind 0x69: steps the balloons of every kart. A MapObject first, then mStartTimer, eight
// KartBalloons and the balloon offsets; 0x364 bytes, the size in its kind descriptor.
typedef struct KartBalloonsObject {
    /* 000 */ MapObject mMapObject;
    // Frames left before the first balloons are made: the update does nothing until it reaches 0, then puts every entry
    // in state 1. Starts at 0x3c, or 0xffff when gRace.mUseChainCameras is non-zero.
    /* 0a0 */ s32 mStartTimer;
    // One KartBalloons entry per kart index (the first mKartCount are used).
    /* 0a4 */ KartBalloons mKartBalloons[8];
    // Sideways offsets of one kart's balloons, indexed [balloon count - 1][balloon index]: 0xc00 apart, centred on the
    // kart; added to the local kart's sway offset.
    /* 264 */ s32 mBalloonOffsets[8][8];
} KartBalloonsObject;

void UpdateKartBalloons(void *mapObjectList, KartBalloonsObject *kartBalloonsObject);
