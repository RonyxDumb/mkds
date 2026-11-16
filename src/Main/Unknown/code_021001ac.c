#include "Main/Unknown/code_021001ac.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_0205a548.h"
#include "Main/Unknown/code_020681f0.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020f8e78.h"
#include "Main/Unknown/code_020f9c40.h"
#include "Main/Unknown/code_020fe4b4.h"

#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f8000.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_02100de4.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_020ed578.h"
#include "Main/Unknown/code_020ed588.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f813c.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_02100700.h"
#include "Main/Unknown/code_02100704.h"
#include "Main/Unknown/unk_0215a000.h"
#include "Main/Unknown/code_0205a000.h"
#include "Main/Unknown/code_020f8e3c.h"
#include "Main/Unknown/code_02100b78.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02100b84.h"
#include "Main/Unknown/code_02100dd8.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020d8474.h"
#include "Main/Unknown/code_020e6a74.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_021025d8.h"
#include "01/code_021a2034.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_02077bc0.h"

void func_02102668(Unk02102668 *inUse) {
    inUse->field170 = 0x1u;
}

void ittrsa_21025D8(Unk021025d8 *teresa) {
    UnkFunc *const *stateTable;
    teresa->field154 = 0x13;
    teresa->field158 = 0;
    stateTable = (UnkFunc *const *) ittrsa_sStates;
    teresa->field15C = 0;
    teresa->field160 = 0xe;
    sm_init(teresa->field12C, stateTable, 7, teresa);
    teresa->field140 = 8;
    teresa->field144 = 0;
    FreeItemObjectCollisionSlot((s32) teresa);
    teresa->field24C = 0;
    teresa->field250 = 0xffffffff;
    teresa->field254 = 0x12;
    teresa->field258 = 0xffffffff;
    teresa->field25C = 0x12;
    teresa->field260 = 0xffffffff;
    teresa->field264 = 0xffffffff;
    teresa->field268 = 0;
    teresa->field26C = 0;
    teresa->field270 = 0;
}

static inline u32 func_02101f7c_inline_2(RandomState64 *random, u32 range) {
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    if (range == 0) {
        return random->mValue >> 32;
    }
    return ((random->mValue >> 32) * range) >> 32;
}

static inline s32 func_02101f7c_inline(KartItems *kartItems, RaceSetup *raceSetup, s32 teamIndex, u16 kartIndex) {
    KartItems *entry;
    Kart *kart;
    BOOL v2;
    s32 l;

    l = 1;
    v2 = TRUE;
    entry = &kartItems[kartIndex];
    kart = entry->mKart;
    if (kart->mState < KART_STATE_PUSH_FLIP && (kart->field7C & 0x400020) == 0) {
        v2 = FALSE;
    }
    if (v2 == FALSE && (kart->field4C & 0x10000800) == 0) {
        l = 0;
    }
    if (l | ((kart->field4C & 0x40) ? 1 : 0)) {
        v2 = FALSE;
    } else if (teamIndex != -1 && teamIndex == raceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex) {
        v2 = FALSE;
    } else {
        v2 = FALSE;
        if (entry->mHeldItem.mItemInfoIndex != 0x13 && entry->mHeldItem.mObjectStartFramesLeft == 0) {
            v2 = entry->mHeldItem.mItemInfoIndex != 0x10;
        }
    }
    return v2;
}

void PickItemTeresaKartByRank(ItemTeresa *teresa, s32 teamIndex) {
    u16 cumulativeWeights[7];
    u16 candidateKarts[7];
    u32 kartCount;
    RaceProgress *raceProgress;
    u32 rankBehind;
    u16 kartIndex;
    u16 randomValue;
    RandomState64 *random;
    u16 index;
    s32 candidateCount;
    u16 weightSum;
    u16 *weightCursor;
    u32 rankAhead;
    KartItems *v2;
    RaceSetup *v3;
    KartItems *kartItems;
    RaceSetup *raceSetup;

    kartCount = gRaceMultiConfig->mKartCount;
    weightSum = candidateCount = 0;
    weightCursor = data_0215a154;
    rankBehind = rankAhead =
        rstat_getPlace((u16) ((teresa->field0.field78 & 0x8000) == 0 ? (u16) (teresa->field0.field78 & ~0xff00) : 8));
    if (teresa->field148 != FALSE) {
        raceProgress = gRaceStatus;
        kartItems = it_sDriverItemStatus;
        raceSetup = gRaceMultiConfig;
        do {
            if (rankAhead > 1) {
                rankAhead = (u16) (rankAhead - 1);
                kartIndex = raceProgress->mKartAtRank[(u8) rankAhead - 1];
                if (func_02101f7c_inline(kartItems, raceSetup, teamIndex, kartIndex) != 0) {
                    weightSum = weightSum + *weightCursor;
                    candidateKarts[candidateCount] = kartIndex;
                    cumulativeWeights[candidateCount] = weightSum;
                    candidateCount++;
                }
                weightCursor++;
            }
            if (rankBehind < kartCount) {
                rankBehind = (u16) (rankBehind + 1);
                kartIndex = raceProgress->mKartAtRank[(u8) rankBehind - 1];
                if (func_02101f7c_inline(kartItems, raceSetup, teamIndex, kartIndex) != 0) {
                    weightSum = weightSum + *weightCursor;
                    candidateKarts[candidateCount] = kartIndex;
                    cumulativeWeights[candidateCount] = weightSum;
                    candidateCount++;
                }
                weightCursor++;
            }
        } while (rankBehind < kartCount || rankAhead > 1);
    } else {
        raceProgress = gRaceStatus;
        v2 = it_sDriverItemStatus;
        v3 = gRaceMultiConfig;
        do {
            if (rankBehind < kartCount) {
                rankBehind = (u16) (rankBehind + 1);
                kartIndex = raceProgress->mKartAtRank[(u8) rankBehind - 1];
                if (func_02101f7c_inline(v2, v3, teamIndex, kartIndex) != 0) {
                    weightSum = weightSum + *weightCursor;
                    candidateKarts[candidateCount] = kartIndex;
                    cumulativeWeights[candidateCount] = weightSum;
                    candidateCount++;
                }
                weightCursor++;
            }
            if (rankAhead > 1) {
                rankAhead = (u16) (rankAhead - 1);
                kartIndex = raceProgress->mKartAtRank[(u8) rankAhead - 1];
                if (func_02101f7c_inline(v2, v3, teamIndex, kartIndex) != 0) {
                    weightSum = weightSum + *weightCursor;
                    candidateKarts[candidateCount] = kartIndex;
                    cumulativeWeights[candidateCount] = weightSum;
                    candidateCount++;
                }
                weightCursor++;
            }
        } while (rankBehind < kartCount || rankAhead > 1);
    }
    random = &raceProgress->mRandom;
    randomValue = weightSum == 0 ? 0 : func_02101f7c_inline_2(random, weightSum);
    for (index = 0; index < candidateCount; index++) {
        if (randomValue < cumulativeWeights[index]) {
            teresa->mPickedKartIndex = candidateKarts[index];
            return;
        }
    }
}

void PickItemTeresaKartBattle(ItemTeresa *teresa, s32 teamIndex) {
    RaceProgress *raceProgress;
    RandomState64 *random;
    s32 endIndex;
    s32 rowIndex;
    u32 kartCount;
    s32 skippedKartIndex;
    KartItems *kartItems;
    RaceSetup *raceSetup;
    s32 kartIndex;
    KartItems *entry;
    Kart *kart;
    s32 l;
    s32 n;
    u8 *row;

    raceProgress = gRaceStatus;
    random = &raceProgress->mRandom;
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    raceSetup = gRaceMultiConfig;
    rowIndex = (u16) (((u64) (u32) (random->mValue >> 32) * 8) >> 32);
    endIndex = rowIndex + 8;
    kartCount = raceSetup->mKartCount;
    skippedKartIndex =
        (u16) ((teresa->field0.field78 & 0x8000) == 0 ? (u16) (teresa->field0.field78 & ~0xff00) : 8);
    if (rowIndex >= endIndex) {
        return;
    }
    kartItems = it_sDriverItemStatus;
    row = &data_0215a164[rowIndex];
    do {
        kartIndex = *row;
        if (kartIndex < kartCount && kartIndex != skippedKartIndex) {
            entry = &kartItems[kartIndex];
            kart = entry->mKart;
            n = l = 1;
            if (kart->mState < KART_STATE_PUSH_FLIP && (kart->field7C & 0x400020) == 0) {
                n = 0;
            }
            if (n == 0 && (kart->field4C & 0x10000800) == 0) {
                l = 0;
            }
            if (l | ((kart->field4C & 0x40) ? 1 : 0)) {
                l = 0;
            } else if (teamIndex != -1 && teamIndex == raceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex) {
                l = 0;
            } else {
                l = 0;
                if (entry->mHeldItem.mItemInfoIndex != 0x13 && entry->mHeldItem.mObjectStartFramesLeft == 0) {
                    l = entry->mHeldItem.mItemInfoIndex != 0x10;
                }
            }
            if (l != 0) {
                teresa->mPickedKartIndex = kartIndex;
                return;
            }
        }
        rowIndex++;
        row++;
    } while (rowIndex < endIndex);
}

void ittrsa_2101D18(Unk02101d18 *inUse, ItemTeresa *teresa) {
    Kart *kart;

    kart = inUse->field10;
    driver_startTeresaEffect(kart);
    sub_20F8E3C((u32) kart, 0xf6);
    SetActiveItem(inUse->fieldC, 0x10);
    light_init(&teresa->field0.mColorBlend, 1);
    if (inUse->fieldC->mFlags & 0x20) {
        teresa->field148 = FALSE;
    } else {
        teresa->field148 = TRUE;
    }
    sm_gotoState(teresa->field12C, 0);
    teresa->field24C = TRUE;
}

void ittrsa_2101C84(ItemTeresa *teresa) {
    Kart *kart;
    Vec3 *kartDrawMatrixPos;
    Vec3 offset;

    sm_execute(teresa->field12C);
    VEC_Subtract(&teresa->field0.mPos, &teresa->field0.mPrevPos, &teresa->field0.mVelocity);
    if (teresa->field0.fieldD0 != &teresa->field0.mDrawPos) {
        return;
    }
    kart = teresa->mKart;
    if (kart == NULL) {
        return;
    }
    kartDrawMatrixPos = &kart->mDrawMatrixPos;
    VEC_Subtract(&teresa->field0.mPos, kartDrawMatrixPos, &offset);
    MTX_MultVec33(&offset, bbm_getBillboardMtx(), &offset);
    VEC_Add(kartDrawMatrixPos, &offset, &teresa->field0.mDrawPos);
}

void sub_2101964(ItemTeresa *teresa, s32 a) {
    Kart *kart;
    Vec3 *position;
    Camera *camera;
    Vec3 *cameraSide;
    s32 delta[3];
    s32 k;
    BOOL m;
    s32 s;
    s32 c;
    s32 t;
    s32 n;

    kart = teresa->mKart;
    camera = race_getCamera();
    position = &teresa->field0.mPos;
    k = m = TRUE;
    if (kart->mState < KART_STATE_PUSH_FLIP && (kart->field7C & 0x400020) == 0) {
        k = 0;
    }
    if (k == 0 && (kart->field4C & 0x10000800) == 0) {
        m = FALSE;
    }
    if (m != FALSE) {
        if (teresa->field144 == FALSE && (teresa->field0.mFlags & 0x8000000) && teresa->field24C != FALSE) {
            teresa->field144 = TRUE;
            sub_20FE694(0xb, teresa->field0.mId, 1, teresa->mState & 0xff);
        } else {
            teresa->field144 = TRUE;
        }
    }
    ((Vec3 *) delta)->x = position->x - (&teresa->field0.mVelocity)->x;
    delta[2] = position->z - (&teresa->field0.mVelocity)->z;
    if (teresa->field144 != FALSE) {
        VEC_Add(&teresa->mKartDrawMatrixPos, &teresa->mKartVelocity, &teresa->mKartDrawMatrixPos);
        teresa->mKartVelocity.x = ((s64) teresa->mKartVelocity.x * 0xeb8) >> 12;
        teresa->mKartVelocity.y = ((s64) teresa->mKartVelocity.y * 0xeb8) >> 12;
        teresa->mKartVelocity.z = ((s64) teresa->mKartVelocity.z * 0xeb8) >> 12;
        *position = teresa->mKartDrawMatrixPos;
    } else {
        *position = kart->mDrawMatrixPos;
        VEC_Subtract(position, &teresa->mKartDrawMatrixPos, &teresa->mKartVelocity);
        teresa->mKartDrawMatrixPos = *position;
        position->y -= kart->mHopHeight;
    }
    VEC_Add(position, (Vec3 *) &teresa->mOffsetX, position);
    cameraSide = &camera->mSide;
    if (teresa->field15C != FALSE) {
        s = 0xccd;
        c = 0x800;
    } else {
        s = 0x800;
        c = 0x400;
    }
    if (a != 0) {
        n = ((s64) * (s32 *) kart->mPhysicalParam * kart->mScale.z + 0x800) >> 12;
        position->x += (s32) (((s64) -n * cameraSide->x) >> 12);
        position->z += (s32) (((s64) -n * cameraSide->z) >> 12);
    }
    delta[0] -= position->x;
    delta[2] -= position->z;
    t = ((s64) cameraSide->x * delta[0] + (s64) cameraSide->z * delta[2]) >> 12;
    delta[0] = ((s64) cameraSide->x * t) >> 12;
    delta[2] = ((s64) cameraSide->z * t) >> 12;
    delta[0] = ((s64) delta[0] * s) >> 12;
    delta[2] = ((s64) delta[2] * s) >> 12;
    if (delta[0] > c) {
        delta[0] = c;
    } else if (delta[0] < -c) {
        delta[0] = -c;
    }
    if (delta[2] > c) {
        delta[2] = c;
    } else if (delta[2] < -c) {
        delta[2] = -c;
    }
    teresa->mOffsetX = delta[0] + (s32) teresa->mOffsetX;
    teresa->mOffsetZ = delta[2] + (s32) teresa->mOffsetZ;
}

void EnterItemTeresaState0(ItemTeresa *teresa) {
    teresa->mKart = driver_getById((u16) (teresa->field0.field78 & ~0xff00));
    teresa->mKartDrawMatrixPos = teresa->mKart->mDrawMatrixPos;
    teresa->mKartVelocity = teresa->mKart->mVelocity;
    *(Vec3 *) &teresa->mOffsetX =
        (Vec3){0, (s32) (((s64) * (s32 *) teresa->mKart->mPhysicalParam * teresa->mKart->mScale.z + 0x800) >> 12), 0};
    teresa->mOffsetVelocityY = 0;
    teresa->field0.mAlpha = 0x1f;
    if (teresa->mKart->field48 & 1) {
        teresa->field0.fieldD0 = &teresa->field0.mDrawPos;
    }
}

void sub_210174C(ItemTeresa *teresa) {
    Vec3 v;
    Vec3 s;
    Vec3 *q;

    if (teresa->mPointIndex >= 0xb) {
        return;
    }
    if (pwex_20D849C(&teresa->field1A4.field0) != FALSE) {
        do {
            teresa->mPointIndex++;
            if (teresa->mPointIndex >= 0xb) {
                return;
            }
        } while (PushSegmentPoint(&teresa->field1A4, &data_0215a1c0[teresa->mPointIndex]) != 0);
    }
    pwex_interpolateXYZ(&teresa->field1A4, &s);
    pwex_20D84C0(&teresa->field1A4.field0, s.y);
    if (teresa->field0.fieldD0 == &teresa->field0.mDrawPos) {
        v = (Vec3){s.x};
    } else {
        s32 f = s.x;

        q = bbm_getBillboardRightVec();
        v.x = ((s64) q->x * f) >> 12;
        v.y = ((s64) q->y * f) >> 12;
        v.z = ((s64) q->z * f) >> 12;
    }
    v.y += s.z;
    VEC_Subtract(&v, (Vec3 *) &teresa->mOffsetX, &s);
    VEC_MultAdd(0x4f6, &s, (Vec3 *) &teresa->mOffsetX, (Vec3 *) &teresa->mOffsetX);
}

BOOL sub_2101618(ItemTeresa *teresa, s32 a, s32 nextState) {
    s32 stateFrames;
    s32 fadeStartFrame;
    s32 fadeStep;

    stateFrames = teresa->mStateFrames;
    if (teresa->field15C != FALSE) {
        fadeStartFrame = -7;
        fadeStep = race_getFrameCounterModulo8() > 2;
        sub_210174C(teresa);
    } else {
        if (nextState < 7) {
            teresa->mOffsetVelocityY += 0x133;
            fadeStartFrame = 0x1c;
            fadeStep = 6;
        } else {
            fadeStartFrame = 0x14;
            fadeStep = 2;
            if (teresa->mOffsetVelocityY < 0) {
                teresa->mOffsetVelocityY += 0x2cd;
            } else {
                teresa->mOffsetVelocityY += 0x8f;
            }
        }
        teresa->mOffsetY += teresa->mOffsetVelocityY;
    }
    sub_2101964(teresa, a);
    if (stateFrames > fadeStartFrame) {
        if (teresa->field0.mAlpha > 0) {
            teresa->field0.mAlpha -= fadeStep;
        }
        if (stateFrames >= (teresa->field15C != FALSE ? 0x37 : 0x28)) {
            if (nextState < 7) {
                if (teresa->mState == 0) {
                    teresa->mSavedOffsetY = teresa->mOffsetY;
                    teresa->mSavedOffsetVelocityY = teresa->mOffsetVelocityY;
                }
                teresa->mNextState = nextState;
                teresa->mNextStateRequested = 1;
            }
            return TRUE;
        }
    }
    return FALSE;
}

s32 sub_21014A0(ItemTeresa *teresa, s32 a, s32 nextState) {
    s32 stateFrames;
    u16 factor;

    stateFrames = teresa->mStateFrames;
    if (teresa->field15C != FALSE) {
        sub_210174C(teresa);
    } else if (teresa->field26C != FALSE) {
        factor = gItemTeresaFrameScales[stateFrames];
        teresa->mOffsetX = ((s64) teresa->mOffsetX * factor) >> 12;
        teresa->mOffsetZ = ((s64) teresa->mOffsetZ * factor) >> 12;
    } else {
        teresa->mOffsetY += teresa->mOffsetVelocityY;
        teresa->mOffsetVelocityY += 0x133;
        factor = gItemTeresaFrameScales[stateFrames];
        teresa->mOffsetX = ((s64) teresa->mOffsetX * factor) >> 12;
        teresa->mOffsetZ = ((s64) teresa->mOffsetZ * factor) >> 12;
    }
    sub_2101964(teresa, a);
    if (stateFrames > 7) {
        if (teresa->field0.mAlpha < 0x1f) {
            teresa->field0.mAlpha += 6;
        }
        if (stateFrames == 0x27) {
            if (teresa->field15C == FALSE) {
                teresa->mOffsetVelocityX = teresa->mOffsetX;
                teresa->mOffsetVelocityZ = teresa->mOffsetZ;
            }
        } else if (stateFrames == 0x28) {
            if (teresa->field15C == FALSE) {
                teresa->mOffsetVelocityX = teresa->mOffsetX - teresa->mOffsetVelocityX;
                teresa->mOffsetVelocityZ = teresa->mOffsetZ - teresa->mOffsetVelocityZ;
            }
            teresa->mNextState = nextState;
            teresa->mNextStateRequested = 1;
            teresa->field26C = FALSE;
        }
    }
    return stateFrames;
}

void UpdateItemTeresaState0(ItemTeresa *teresa) {
    sub_2101618(teresa, 0, (teresa->field0.mFlags & 0x8000000) ? 1 : 2);
    if (!(teresa->field0.mFlags & 0x8000000)) {
        return;
    }
    if (teresa->field24C != FALSE) {
        return;
    }
    if (teresa->field144 != FALSE) {
        return;
    }
    if (teresa->field264 == 0xffffffff) {
        return;
    }
    if (teresa->field264 == 0 || teresa->field264 == 7) {
        teresa->field144 = TRUE;
        teresa->field264 = -1;
    }
}

void EnterItemTeresaState1(ItemTeresa *teresa) {
    if (teresa->field24C == FALSE) {
        return;
    }
    PickItemTeresaKartByRank(teresa, -1);
    sub_20FE694(0xb, teresa->field0.mId, 0, teresa->mPickedKartIndex & 0xff);
    teresa->field250 = teresa->mPickedKartIndex;
    teresa->field24C = FALSE;
}

void UpdateItemTeresaState1(ItemTeresa *teresa) {
    s32 stateFrames;

    if (teresa->field250 == 0xffffffff) {
        return;
    }
    stateFrames = teresa->mStateFrames;
    if (teresa->field24C == FALSE && stateFrames < 0x28) {
        return;
    }
    teresa->field268 = stateFrames - 0x28;
    teresa->mPickedKartIndex = teresa->field250;
    teresa->mNextState = 2;
    teresa->mNextStateRequested = 1;
}

void EnterItemTeresaState2(ItemTeresa *teresa) {
    s32 *offset;
    Camera *camera;
    RaceSetup *raceSetup;
    void (*pickFunction)(ItemTeresa *, s32);
    int ownerKartIndex;

    offset = &teresa->mOffsetX;
    camera = race_getCamera();
    if (!(teresa->field0.mFlags & 0x8000000)) {
        raceSetup = gRaceMultiConfig;
        pickFunction = (raceSetup->mMode == MODE_BATTLE) ? PickItemTeresaKartBattle : PickItemTeresaKartByRank;
        if (raceSetup->mUseTeams != 0) {
            if ((teresa->field0.field78 & 0x8000) == 0) {
                ownerKartIndex = (u16) (teresa->field0.field78 & ~0xff00);
            } else {
                ownerKartIndex = 8;
            }
            pickFunction(teresa, raceSetup->mCurrentEntries[(u16) ownerKartIndex].mPlayer.mTeamIndex);
            if (teresa->mPickedKartIndex == 8) {
                pickFunction(teresa, -1);
            }
        } else {
            pickFunction(teresa, -1);
        }
    }
    if (teresa->field0.fieldD0 == &teresa->field0.mDrawPos) {
        teresa->field0.mPos = teresa->field0.mDrawPos;
        teresa->field0.fieldD0 = &teresa->field0.mPos;
    }
    if (teresa->mPickedKartIndex < 8) {
        teresa->mKart = driver_getById(teresa->mPickedKartIndex);
        teresa->mKartDrawMatrixPos = teresa->mKart->mDrawMatrixPos;
        teresa->mKartVelocity = teresa->mKart->mVelocity;
        teresa->field144 = FALSE;
        sub_20F8E3C((u32) teresa->mKart, 0xf4);
        if (teresa->mKart->field48 & 1) {
            teresa->field0.fieldD0 = &teresa->field0.mDrawPos;
        }
    }
    offset[0] = ((s64) camera->mSide.x * -0xa000) >> 12;
    offset[2] = ((s64) camera->mSide.z * -0xa000) >> 12;
    offset[0] += (s32) (((s64) camera->mForward.x * -0x11000) >> 12);
    offset[2] += (s32) (((s64) camera->mForward.z * -0x11000) >> 12);
    teresa->mOffsetVelocityY = -teresa->mOffsetVelocityY;
    teresa->mStallFrames = 0;
}

s32 sub_2101014(ItemTeresa *teresa) {
    KartItems *pickedKartItems;
    Kart *kart;
    HeldItem *heldItem;
    s32 a;
    s32 b;
    enum { K0 } itemInfoIndex;

    pickedKartItems = &it_sDriverItemStatus[(u16) teresa->mPickedKartIndex];
    kart = pickedKartItems->mKart;
    heldItem = &pickedKartItems->mHeldItem;
    if (heldItem->mItemInfoIndex == 0x13 || heldItem->mObjectStartFramesLeft != 0) {
        return 0xf;
    }
    if (heldItem->mItemInfoIndex == 0x10) {
        return 0xf;
    }
    if (teresa->field144 != FALSE) {
        return 0xf;
    }
    a = b = 1;
    if (kart->mState < KART_STATE_PUSH_FLIP && (kart->field7C & 0x400020) == 0) {
        a = 0;
    }
    if (a == 0 && (kart->field4C & 0x10000800) == 0) {
        b = 0;
    }
    if (b | ((kart->field4C & 0x40) ? 1 : 0)) {
        return 0xf;
    }
    if (teresa->field0.mFlags & 0x8000000) {
        teresa->mItemInfoIndex = heldItem->mItemInfoIndex;
        teresa->mItemCount = heldItem->mObjectCount;
        sub_205A5B0(((u8 *) gStruct217AA18)[teresa->mPickedKartIndex & 0xff]);
    } else {
        it_stealSlotItem(heldItem, &teresa->mItemInfoIndex, &teresa->mItemCount);
    }
    StructMQRacerEntry_SomeFn_10(kart);
    itemInfoIndex = teresa->mItemInfoIndex;
    return it_sItemConfigs[itemInfoIndex].mObjectKind;
}

void UpdateItemTeresaState2(ItemTeresa *teresa) {
    u32 framesLeft;
    BOOL k;

    if (teresa->mPickedKartIndex == 8) {
        if (teresa->mStateFrames > 0x6e) {
            teresa->mItemObjectKind = 0xf;
            teresa->mNextState = (teresa->field0.mFlags & 0x8000000) ? 4 : 5;
            teresa->mNextStateRequested = 1;
        }
    } else {
        framesLeft = 0x28 - sub_21014A0(teresa, 1, 3);
        if (teresa->mItemObjectKind == 0xe) {
            if (teresa->field24C != FALSE) {
                if (framesLeft == 0xa) {
                    teresa->mItemObjectKind = sub_2101014(teresa);
                    teresa->mItemModelAlpha = 0;
                    if (teresa->field0.mFlags & 0x8000000) {
                        sub_20FE694(0xb, teresa->field0.mId, 2,
                                      ((teresa->mItemInfoIndex << 2) | teresa->mItemCount) & 0xff);
                    }
                }
            } else if (framesLeft <= 0xa) {
                if (teresa->field258 != -1) {
                    teresa->mItemInfoIndex = teresa->field254;
                    teresa->mItemCount = teresa->field258;
                    teresa->field254 = 0x12;
                    teresa->field258 = -1;
                    if (teresa->mItemInfoIndex == 0x13) {
                        teresa->mItemObjectKind = 0xf;
                    } else {
                        teresa->mItemObjectKind = it_sItemConfigs[teresa->mItemInfoIndex].mObjectKind;
                        sub_205A5B0(((u8 *) gStruct217AA18)[teresa->mPickedKartIndex & 0xff]);
                    }
                    teresa->mItemModelAlpha = 0;
                    k = TRUE;
                } else {
                    k = FALSE;
                }
                if (k == FALSE && framesLeft == 1) {
                    teresa->mStateFrames--;
                    teresa->field26C = TRUE;
                    teresa->mStallFrames++;
                    if (teresa->mStallFrames > 0x3c) {
                        teresa->field254 = 0x13;
                        teresa->field258 = 0;
                    }
                }
            }
        }
    }
    if (!(teresa->field0.mFlags & 0x8000000)) {
        return;
    }
    if (teresa->field24C != FALSE) {
        return;
    }
    if (teresa->field144 != FALSE) {
        return;
    }
    if (teresa->field264 == 0xffffffff) {
        return;
    }
    if (teresa->field264 == 2 || teresa->field264 == 7) {
        teresa->field144 = TRUE;
        teresa->field264 = -1;
    }
}

void EnterItemTeresaState3(Unk02100dd8 *teresa) {
    teresa->field19C = 0x0u;
}

void UpdateItemTeresaState3(ItemTeresa *teresa) {
    if (teresa->mItemModelAlpha < 0x1f) {
        teresa->mItemModelAlpha += 5;
    }
    teresa->mOffsetVelocityX = ((s64) teresa->mOffsetVelocityX * 0xf85) >> 12;
    teresa->mOffsetVelocityZ = ((s64) teresa->mOffsetVelocityZ * 0xf85) >> 12;
    if (teresa->mStateFrames == 0x12) {
        if (teresa->field19C == 0) {
            teresa->field19C = -0x1ae;
            teresa->field1A0 = teresa->mOffsetVelocityY;
        }
        teresa->mOffsetVelocityY += teresa->field19C;
        teresa->mOffsetY += teresa->mOffsetVelocityY;
        sub_2101964(teresa, 1);
        if (teresa->field19C >= 0 && teresa->mOffsetVelocityY >= teresa->field1A0) {
            return;
        }
        teresa->mStateFrames--;
        if (teresa->field19C >= 0) {
            return;
        }
        if (teresa->mOffsetVelocityY < -0xc00) {
            teresa->field19C = 0x133;
            return;
        }
        if (teresa->mOffsetVelocityY <= 0) {
            return;
        }
        if (teresa->mOffsetVelocityY >= -teresa->field19C) {
            return;
        }
        sub_20F8E3C((u32) teresa->mKart, 0xf5);
    } else {
        teresa->mOffsetX += teresa->mOffsetVelocityX;
        teresa->mOffsetZ += teresa->mOffsetVelocityZ;
        sub_2101618(teresa, 1, (teresa->field0.mFlags & 0x8000000) ? 4 : 5);
        if (!(teresa->field0.mFlags & 0x8000000)) {
            return;
        }
        if (teresa->field24C != FALSE) {
            return;
        }
        if (teresa->field144 != FALSE) {
            return;
        }
        if (teresa->field264 == 0xffffffff) {
            return;
        }
        if (teresa->field264 - 2 <= 1) {
            teresa->field144 = TRUE;
            teresa->field264 = -1;
        }
    }
}

void EnterItemTeresaState4(ItemTeresa *teresa) {
    teresa->field268 = ((teresa->field0.mFlags & 0x10000000) ? 0xf : 0) - teresa->field268;
    teresa->field24C = FALSE;
}

void UpdateItemTeresaState4(ItemTeresa *teresa) {
    teresa->field268--;
    if (teresa->field268 >= 0) {
        return;
    }
    teresa->field24C = (teresa->field0.mFlags & 0x10000000) == 0;
    teresa->mNextState = 5;
    teresa->mNextStateRequested = 1;
}

void SetItemTeresaPosPointerToDrawPos(ItemTeresa *teresa) {
    teresa->field0.fieldD0 = &teresa->field0.mDrawPos;
}

void func_02100b54(ItemTeresa *teresa) {
    if (teresa->field0.fieldD0 == &teresa->field0.mDrawPos) {
        teresa->field0.mPos = teresa->field0.mDrawPos;
        teresa->field0.fieldD0 = &teresa->field0.mPos;
    }
}

void EnterItemTeresaState5(ItemTeresa *teresa) {
    int ownerKartIndex;
    KartItems *ownerKartItems;
    void (*positionFunction)(ItemTeresa *);

    if ((teresa->field0.field78 & 0x8000) == 0) {
        ownerKartIndex = (u16) (teresa->field0.field78 & ~0xff00);
    } else {
        ownerKartIndex = 8;
    }
    ownerKartItems = &it_sDriverItemStatus[(u16) ownerKartIndex];
    teresa->mKart = ownerKartItems->mKart;
    teresa->field144 = FALSE;
    if (teresa->field24C != FALSE) {
        if (ownerKartItems->mActiveItem == 0x10) {
            teresa->mKartDrawMatrixPos = teresa->mKart->mDrawMatrixPos;
            teresa->mKartVelocity = teresa->mKart->mVelocity;
            teresa->mOffsetX = 0;
            teresa->mOffsetZ = 0;
        } else {
            teresa->field144 = TRUE;
            if (teresa->field0.mFlags & 0x8000000) {
                sub_20FE694(0xb, teresa->field0.mId, 1, 5);
            }
            teresa->mOffsetX = 0;
            teresa->mOffsetZ = 0;
        }
    }
    if (teresa->mItemObjectKind == 0xf) {
        InitSegmentPoints(&teresa->field1A4, data_0215a1c0, data_0215a1c0[0].y);
        teresa->mPointIndex = 3;
        teresa->field15C = TRUE;
    } else {
        teresa->mOffsetVelocityY = -teresa->mSavedOffsetVelocityY;
        teresa->mOffsetY = teresa->mSavedOffsetY;
    }
    if (teresa->field144 == FALSE) {
        sub_20F8E3C((u32) teresa->mKart, 0xf7);
    }
    teresa->mStallFrames = 0;
    positionFunction = (teresa->mKart->field48 & 1) ? SetItemTeresaPosPointerToDrawPos : func_02100b54;
    positionFunction(teresa);
}

void UpdateItemTeresaState5(ItemTeresa *teresa) {
    s32 ownerKartIndex;
    KartItems *ownerKartItems;
    u32 framesLeft;
    BOOL k;
    s32 startOffsetX;
    s32 startOffsetZ;

    if ((teresa->field0.field78 & 0x8000) == 0) {
        ownerKartIndex = (u16) (teresa->field0.field78 & ~0xff00);
    } else {
        ownerKartIndex = 8;
    }
    ownerKartItems = &it_sDriverItemStatus[(u16) ownerKartIndex];
    if (teresa->field24C != FALSE && ownerKartItems->mActiveItem != 0x10 && teresa->mItemCount != -0x40) {
        teresa->field144 = TRUE;
        if (teresa->field0.mFlags & 0x8000000) {
            sub_20FE694(0xb, teresa->field0.mId, 1, 5);
        }
    } else {
        framesLeft = 0x28 - sub_21014A0(teresa, teresa->field15C == FALSE ? 1 : 0, 6);
        if (framesLeft < 7) {
            if (teresa->mItemModelAlpha > 0) {
                teresa->mItemModelAlpha -= 5;
            }
            if (framesLeft == 1) {
                if (teresa->field24C == FALSE) {
                    if (teresa->field260 == -1) {
                        k = FALSE;
                    } else {
                        teresa->mItemInfoIndex = teresa->field25C;
                        teresa->mItemCount = teresa->field260;
                        teresa->field25C = 0x12;
                        teresa->field260 = -1;
                        k = TRUE;
                    }
                    if (k == FALSE) {
                        teresa->mStateFrames--;
                        teresa->field26C = TRUE;
                        teresa->mStallFrames++;
                        if (teresa->mStallFrames > 0x3c) {
                            teresa->field25C = 0x13;
                            teresa->field260 = -0x40;
                            teresa->mItemObjectKind = 0xe;
                        }
                        goto skip;
                    }
                }
                ownerKartItems->mActiveItem = 0x13;
                if (teresa->mItemInfoIndex != 0x13) {
                    if (teresa->field24C == FALSE) {
                        func_0205a548(((u8 *) gStruct217AA18)[ownerKartItems->mKartIndex & 0xff],
                                      teresa->mItemInfoIndex, teresa->mItemCount);
                    } else {
                        SetHeldItemWithCount(&ownerKartItems->mHeldItem, teresa->mItemInfoIndex, teresa->mItemCount);
                    }
                    teresa->mItemInfoIndex = 0x13;
                    teresa->mItemCount = -0x40;
                    teresa->mItemObjectKind = 0xe;
                    sub_20F8E3C((u32) ownerKartItems->mKart, 0xf8);
                } else {
                    teresa->mItemCount = -0x40;
                    teresa->mItemObjectKind = 0xe;
                }
                if ((teresa->field0.mFlags & 0x8000000) && teresa->field24C != FALSE) {
                    sub_20FE694(
                        0xb, teresa->field0.mId, 3,
                        ((ownerKartItems->mHeldItem.mItemInfoIndex << 2) | ownerKartItems->mHeldItem.mObjectCount) &
                            0xff);
                }
            }
        }
    }
skip:
    if (teresa->field15C == FALSE && teresa->field144 != FALSE) {
        startOffsetX = teresa->mOffsetX;
        startOffsetZ = teresa->mOffsetZ;
        sub_21014A0(teresa, 1, 6);
        teresa->mOffsetVelocityX = teresa->mOffsetX - startOffsetX;
        teresa->mOffsetVelocityZ = teresa->mOffsetZ - startOffsetZ;
        teresa->mNextState = 6;
        teresa->mNextStateRequested = 1;
        teresa->field26C = FALSE;
    }
    if (!(teresa->field0.mFlags & 0x8000000)) {
        return;
    }
    if (teresa->field24C != FALSE) {
        return;
    }
    if (teresa->field144 != FALSE) {
        return;
    }
    if (teresa->field264 == 0xffffffff) {
        return;
    }
    if (teresa->field264 == 5 || teresa->field264 == 7) {
        teresa->field144 = TRUE;
        teresa->field264 = -1;
    }
}

u32 EnterItemTeresaState6(u32 value) {
    return value;
}

void UpdateItemTeresaState6(ItemTeresa *teresa) {
    BOOL hasItem;
    s32 ownerKartIndex;

    hasItem = teresa->mItemInfoIndex != 0x13;
    if (teresa->field15C == FALSE) {
        teresa->mOffsetVelocityX = ((s64) teresa->mOffsetVelocityX * 0xf85) >> 12;
        teresa->mOffsetVelocityZ = ((s64) teresa->mOffsetVelocityZ * 0xf85) >> 12;
        teresa->mOffsetX += teresa->mOffsetVelocityX;
        teresa->mOffsetZ += teresa->mOffsetVelocityZ;
    }
    if (hasItem != FALSE) {
        if (teresa->mItemModelAlpha < 0x1f) {
            teresa->mItemModelAlpha += 8;
        }
    }
    if (sub_2101618(teresa, teresa->field15C == FALSE ? 1 : 0, 7) != FALSE) {
        if (hasItem != FALSE) {
            if ((teresa->field0.field78 & 0x8000) == 0) {
                ownerKartIndex = (u16) (teresa->field0.field78 & ~0xff00);
            } else {
                ownerKartIndex = 8;
            }
            ((void (*)(s32 param_1, s32 param_2, s32 param_3)) RemoveReservedItemObjects)(
                teresa->mItemInfoIndex, teresa->mItemCount, (u16) ownerKartIndex);
        }
        it_itemsetDestroyItem(it_sItemsets + teresa->field0.mKind, &teresa->field0);
    }
    if (!(teresa->field0.mFlags & 0x8000000)) {
        return;
    }
    if (teresa->field24C != FALSE) {
        return;
    }
    if (teresa->field144 != FALSE) {
        return;
    }
    if (teresa->field264 == 0xffffffff) {
        return;
    }
    if (teresa->field264 - 5 <= 1) {
        teresa->field144 = TRUE;
        teresa->field264 = -1;
    }
}

void ittrsa_210050C(ItemTeresa *teresa) {
    int ownerKartIndex;
    KartItems *ownerKartItems;

    if ((teresa->field0.field78 & 0x8000) == 0) {
        ownerKartIndex = (u16) (teresa->field0.field78 & ~0xff00);
    } else {
        ownerKartIndex = 8;
    }
    ownerKartItems = &it_sDriverItemStatus[(u16) ownerKartIndex];
    if (ownerKartItems->mActiveItem != 0x10) {
        return;
    }
    if (teresa->mItemCount != -0x40) {
        ownerKartItems->mActiveItem = 0x13;
    }
}

void ittrsa_21004C4(void *cursor, ItemTeresa *teresa, void *toData) {
    CopyItemObjectData(cursor, teresa, toData);
    if (teresa == NULL) {
        return;
    }
    if (toData == NULL) {
        return;
    }
    sub_20FE8AC(teresa->field0.mKind);
}

void ittrsa_210045C(ItemTeresa *teresa) {
    int ownerKartIndex;

    sub_20F8E78(teresa);
    light_init(&teresa->field0.mColorBlend, 1);
    sm_gotoState(teresa->field12C, 0);
    if ((teresa->field0.field78 & 0x8000) == 0) {
        ownerKartIndex = (u16) (teresa->field0.field78 & ~0xff00);
    } else {
        ownerKartIndex = 8;
    }
    SetActiveItem(&it_sDriverItemStatus[(u16) ownerKartIndex], 0x10);
}

void sub_21003E8(ItemTeresa *teresa, u32 sel, s32 value) {
    switch (sel) {
        case 0:
            teresa->field250 = value;
            if (teresa->field250 == gRaceMultiConfig->mEntryIndex) {
                teresa->field24C = TRUE;
            }
            break;
        case 1:
            teresa->field264 = value;
            break;
        case 2:
            teresa->field254 = value >> 2;
            teresa->field258 = value & 3;
            break;
        case 3:
            teresa->field25C = value >> 2;
            teresa->field260 = value & 3;
            break;
    }
}

void ittrsa_21001AC(ItemTeresa *teresa, s32 c, NsbmdModel *model) {
    s32 a;
    s32 itemModelAlpha;
    s32 b;
    s32 polygonId;
    u16 drawAlpha;
    s32 scale[3];
    s32 scaleX;
    s32 scaleY;
    s32 scaleZ;
    NsbmdModel *itemModel;
    s32 index;
    s32 itemCount;

    if (teresa->field0.mAlpha <= 0) {
        return;
    }
    a = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &a, 1);
    NNS_G3dGeBufferOP_N(0x19, bbm_getBillboardAtPos(teresa->field0.fieldD0), 0xc);
    scaleZ = teresa->field0.mScale.z;
    scaleY = teresa->field0.mScale.y;
    scaleX = teresa->field0.mScale.x;
    scale[0] = scaleX;
    scale[1] = scaleY;
    scale[2] = scaleZ;
    NNS_G3dGeBufferOP_N(0x1b, scale, 3);
    if (teresa->mItemObjectKind < 0xe && teresa->mState >= 3) {
        itemModel = GetItemModel(teresa->mItemObjectKind);
        itemModelAlpha = teresa->mItemModelAlpha;
        itemCount = teresa->mItemCount;
        if (teresa->field0.mAlpha < 0x1f) {
            if (teresa->field0.mAlpha < itemModelAlpha) {
                itemModelAlpha = teresa->field0.mAlpha;
            }
        }
        if (itemModelAlpha > 0x1f) {
            itemModelAlpha = 0x1f;
        }
        if (itemModelAlpha < 1) {
            itemModelAlpha = 1;
        }
        NNS_G3dGeBufferOP_N(0x11, NULL, 0);
        itemModel->field14 = itemModel->field14 & ~0x1f0000;
        itemModel->field14 = itemModel->field14 | ((u16) itemModelAlpha << 16);
        bbm_applyMaterial(itemModel);
        index = 0;
        itemModel->mFrameIndex = 0;
        while (index < itemCount) {
            NNS_G3dGeBufferOP_N(0x1c, &data_0215a190[itemCount == 2 ? 1 - index : index + 1], 3);
            polygonId = mobj_getCyclicPolygonId();
            itemModel->field14 = itemModel->field14 & ~0x3f000000;
            itemModel->field14 = itemModel->field14 | (polygonId << 24);
            bbm_render(itemModel, &teresa->field0.mPos, 1, 0x1f);
            index++;
        }
        b = 1;
        NNS_G3dGeBufferOP_N(0x12, &b, 1);
        if (itemModelAlpha != 0x1f) {
            itemModel->field14 = itemModel->field14 & ~0x1f0000;
            itemModel->field14 = itemModel->field14 | 0x1f0000;
        }
    }
    polygonId = mobj_getCyclicPolygonId();
    model->field14 = model->field14 & ~0x3f000000;
    model->field14 = model->field14 | (polygonId << 24);
    drawAlpha = teresa->field0.mAlpha;
    model->field14 = model->field14 & ~0x1f0000;
    model->field14 = model->field14 | (drawAlpha << 16);
    sub_20ED588(&teresa->field0, model);
}
