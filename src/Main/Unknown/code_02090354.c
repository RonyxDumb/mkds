#include "Main/Unknown/code_02090354.h"
#include "Main/System/ArchiveFiles.h"
#include "Main/Unknown/code_0207ffa4.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0207e000.h"
#include "Main/Unknown/code_0207f000.h"
#include "Main/Unknown/code_0207ff5c.h"
#include "Main/Unknown/code_02080b1c.h"
#include "Main/Unknown/code_0208eb10.h"
#include "Main/Unknown/code_02048000.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_02056d40.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020ee684.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "00/code_02181f98.h"
#include "01/code_021956dc.h"
#include "code_021458c4.h"
#include "code_02146cbc.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/code_020917d0.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_0207e654.h"

void sman_loadTopModel(void *a) {
    void *mapObjectModelNsbmd;
    mapObjectModelNsbmd = mobj_loadBillboardModel(a, aSman_top_nsbmd);
    sman_sTopModel = mapObjectModelNsbmd;
    mobj_setModelPolygonIdAll(mapObjectModelNsbmd, 0x3f);
}

void sman_applyTopMaterial(void *a) {
    mobj_bbModelApplyMaterial(a, sman_sTopModel);
}

void sman_renderTop(void *mapObjectList, Sman *sman) {
    s32 c;
    s32 matrix[9];
    s32 topOffset[3];
    c = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &c, 1);
    NNS_G3dGeBufferOP_N(0x19, bbm_getYBillboardAtPos(&sman->mMapObject.mPos), 0xc);
    topOffset[1] = sman->mTopHeight >> 4;
    topOffset[0] = 0;
    topOffset[2] = 0;
    NNS_G3dGeBufferOP_N(0x1c, topOffset, 3);
    NNS_G3dGeBufferOP_N(0x1b, &sman->mMapObject.mScale, 3);
    MTX_RotZ33_(matrix, FX_SinCosTable_[((u16) sman->mAngleZ >> 4) * 2],
                FX_SinCosTable_[((u16) sman->mAngleZ >> 4) * 2 + 1]);
    NNS_G3dGeBufferOP_N(0x1a, matrix, 9);
    mobj_renderModel(mapObjectList, sman_sTopModel, sman);
}

void sman_loadBottomModel(void *a) {
    void *mapObjectModelNsbmd;
    mapObjectModelNsbmd = mobj_loadBillboardModel(a, aSman_bottom_ns);
    sman_sBottomModel = mapObjectModelNsbmd;
    mobj_setModelPolygonIdAll(mapObjectModelNsbmd, 0x3f);
}

void sman_applyBottomMaterial(void *a) {
    mobj_bbModelApplyMaterial(a, sman_sBottomModel);
}

void sman_renderBottom(void *mapObjectList, Sman *sman) {
    s32 c;
    s32 scale[3];
    s32 bottomScale;
    c = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &c, 1);
    NNS_G3dGeBufferOP_N(0x19, bbm_getYBillboardAtPos(&sman->mMapObject.mPos), 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &sman->mMapObject.mScale, 3);
    bottomScale = sman->mBottomScale;
    scale[0] = bottomScale;
    scale[1] = bottomScale;
    scale[2] = bottomScale;
    NNS_G3dGeBufferOP_N(0x1b, scale, 3);
    mobj_renderModel(mapObjectList, sman_sBottomModel, sman);
}

void sman_globalLogicInit(SmanList *smanList) {
    s32 index;
    Sman *sman;
    if (smanList == NULL) {
        return;
    }
    index = 0;
    while (index < smanList->mSmanCount && (sman = smanList->mSmans[index]) != NULL) {
        sman->mTopRiseProgress = 0x1000;
        sman->mBottomScale = 0x1000;
        index++;
        sman->mTopStartHeight = ((s64) sman->mMapObject.mScale.y * 0xf333) >> 12;
        sman->mTopLowHeight = ((s64) sman->mMapObject.mScale.y * 0x2000) >> 12;
        sman->mTopHeight = sman->mTopStartHeight;
    }
}

void sman_update(void *a, Sman *sman) {
    Unk0210b7a8 soundRequest;
    s32 falloffIndex;
    switch (sman->mState) {
        case 0:
            sman->mAngleZEnabled = 1;
            break;
        case 1:
            sman->mTopHeight = sman->mTopHeight + sman->mTopHeightPerFrame;
            sman->mTopHeightPerFrame = sman->mTopHeightPerFrame - 0x400;
            if (sman->mTopHeightPerFrame < -0x6000) {
                sman->mTopHeightPerFrame = -0x6000;
            }
            if (sman->mMapObject.mCourseMapRow->field28 > 0) {
                if (sman->mTopHeight < 0) {
                    mobj_setInvisible(&sman->mMapObject);
                }
            } else if (sman->mTopHeight < sman->mTopLowHeight) {
                sman->mTopHeight = sman->mTopLowHeight;
                sman->mTopHeightPerFrame = 0;
                sman->mState = 2;
                falloffIndex = 2;
                if ((sman->mMapObject.mDistanceSquaredAndFlags & 4) == 0) {
                    if (sman->mMapObject.mFarDistanceSquared != gSfxParams[2].field20) {
                        if (sman->mMapObject.mFarDistanceSquared == gSfxParams[3].field20) {
                            falloffIndex = 3;
                        } else {
                            falloffIndex = 4;
                        }
                    }
                    soundRequest.mSoundId = 0x162;
                    soundRequest.mPositionSource = &sman->mMapObject.mPos;
                    soundRequest.field8 = falloffIndex;
                    soundRequest.mDistanceSquared = mobj_calcXZCamDist(&sman->mMapObject.mPos);
                    func_0210b7a8(&soundRequest);
                }
            }
            sman->mAngleZEnabled = 0;
            break;
        case 2:
            sman->mStateFrames = sman->mStateFrames + 1;
            if (sman->mStateFrames >= 0x12b) {
                sman->mStateFrames = 0;
                sman->mTopHeightPerFrame = ((sman->mTopStartHeight - sman->mTopLowHeight) * 0x40) / 0x1000;
                sman->mState = 3;
            }
            sman->mAngleZEnabled = 0;
            break;
        case 3:
            if (sman->mTopRiseProgress >= 0x1000) {
                sman->mTopRiseProgress = 0x1000;
                sman->mTopHeight = sman->mTopStartHeight;
            } else {
                sman->mTopRiseProgress = sman->mTopRiseProgress + 0x40;
                sman->mTopHeight = sman->mTopHeight + sman->mTopHeightPerFrame;
            }
            sman->mStateFrames = sman->mStateFrames + 1;
            if (sman->mStateFrames > 10) {
                sman->mBottomScale = sman->mBottomScale + 0x40;
                if (sman->mBottomScale >= 0x1000) {
                    sman->mStateFrames = 0;
                    sman->mBottomScale = 0x1000;
                    sman->mMapObject.mFlags = sman->mMapObject.mFlags & ~1;
                    sman->mState = 0;
                }
            }
            sman->mAngleZEnabled = 1;
            break;
    }
    if (sman->mAngleZEnabled == 0) {
        return;
    }
    sman->mAngleZ = sman->mAngleZ + sman->mAngleZPerFrame;
    if (sman->mAngleZ >= 0) {
        if (sman->mAngleZPerFrame < 0) {
            sman->mAngleZPerFrame = -0xf0;
        } else {
            sman->mAngleZPerFrame = sman->mAngleZPerFrame - 8;
        }
    } else {
        if (sman->mAngleZPerFrame >= 0) {
            sman->mAngleZPerFrame = 0xf0;
        } else {
            sman->mAngleZPerFrame = sman->mAngleZPerFrame + 8;
        }
    }
}

// Creates the kind record of Sman with two functions that put it into state 1 when their third argument points to 1.
void sman_setupConfig(void) {
    mobj_createConfigEx(sman_onDriverCollide, sman_onItemCollide, NULL, 0, 1, 0x161);
}

static inline BOOL func_02090940_inline(void) {
    BOOL isFilledTopRank;
    enum { K0 } cup;
    enum { L0 } engineClass;
    for (cup = 0; cup < 8; cup++) {
        for (engineClass = 0; engineClass < 4; engineClass++) {
            if (savd_getIsCupPlayed(cup, engineClass) != 0 && savd_getCupTrophy(cup, engineClass) == 0) {
                isFilledTopRank = TRUE;
            } else {
                isFilledTopRank = FALSE;
            }
            if (isFilledTopRank == FALSE) {
                return FALSE;
            }
        }
    }
    return TRUE;
}

void *sman_setupTopRenderPart(void) {
    return mobj_createRenderPart2d(sman_loadTopModel, sman_renderTop, sman_applyTopMaterial);
}

void *sman_setupBottomRenderPart(void) {
    return mobj_createRenderPart2d(sman_loadBottomModel, sman_renderBottom, sman_applyBottomMaterial);
}

void *sman_setupLogicPart(void) {
    return mobj_createLogicPart(sman_globalLogicInit, sman_update, NULL);
}

static inline BOOL func_02090cf8_inline(s32 cup, s32 engineClass) {
    if (savd_getIsCupPlayed(cup, engineClass) != 0 && savd_getCupTrophy(cup, engineClass) == 0) {
        return TRUE;
    }
    return FALSE;
}

u32 unlock_updateUnlocks(void) {
    u32 setFlagBits;
    setFlagBits = 0;
    if (scproc_getCurrentScene() == 10) {
        setFlagBits = unlock_tryUnlock();
        savd_flushNksy();
        bgwkr_waitForCompletion();
        if (gSaveCore->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    return setFlagBits;
}

u32 unlock_tryUnlock2(void) {
    return unlock_tryUnlock();
}

u32 unlock_tryUnlock(void) {
    u32 setFlagBits;
    u32 q;
    BOOL t;
    setFlagBits = 0;
    setFlagBits = setFlagBits | unlock_tryUnlockCups();
    setFlagBits = setFlagBits | unlock_tryUnlockCharacters();
    q = 0;
    t = FALSE;
    if (savd_getKartUnlockLevel() < 2) {
        if ((savd_getIsCupPlayed(3, 1) != 0 && savd_getCupTrophy(3, 1) == 0) ? 1 : 0) {
            savd_setKartUnlockLevel(2);
            t = TRUE;
        }
    }
    if (t != FALSE) {
        q = 0x200;
    }
    t = FALSE;
    if (savd_getKartUnlockLevel() < 3) {
        BOOL isFilledTopRank;
        if (savd_getIsCupPlayed(3, 2) != 0 && savd_getCupTrophy(3, 2) == 0) {
            isFilledTopRank = TRUE;
        } else {
            isFilledTopRank = FALSE;
        }
        if (isFilledTopRank != FALSE) {
            goto l1;
        }
        if (savd_getIsCupPlayed(7, 2) != 0 && savd_getCupTrophy(7, 2) == 0) {
            isFilledTopRank = TRUE;
        } else {
            isFilledTopRank = FALSE;
        }
        if (isFilledTopRank != FALSE) {
        l1:
            savd_setKartUnlockLevel(3);
            t = TRUE;
        }
    }
    if (t != FALSE) {
        q = 0x400;
    }
    t = FALSE;
    if (savd_getKartUnlockLevel() < 4) {
        if ((savd_getIsCupPlayed(3, 3) != 0 && savd_getCupTrophy(3, 3) == 0) ? 1 : 0) {
            if ((savd_getIsCupPlayed(7, 3) != 0 && savd_getCupTrophy(7, 3) == 0) ? 1 : 0) {
                savd_setKartUnlockLevel(4);
                t = TRUE;
            }
        }
    }
    if (t != FALSE) {
        q = 0x800;
    }
    return setFlagBits | q;
}

u32 unlock_tryUnlockCups(void) {
    enum { K0 } engineClass;
    u32 setFlagBits;
    u32 q;
    u32 newBit;
    s32 j4;
    s32 j8;
    s32 j12;
    setFlagBits = 0;
    for (engineClass = 0; engineClass < 4; engineClass++) {
        newBit = 0;
        if (savd_isUnlockBitSet(engineClass) == 0) {
            if (func_02090cf8_inline(0, engineClass) != FALSE && func_02090cf8_inline(1, engineClass) != FALSE) {
                savd_setUnlockBit(engineClass);
                newBit = 1;
            }
        }
        setFlagBits = setFlagBits | newBit;
        newBit = 0;
        j4 = engineClass + 4;
        if (savd_isUnlockBitSet(j4) == 0) {
            if (func_02090cf8_inline(2, engineClass) != FALSE) {
                savd_setUnlockBit(j4);
                newBit = 2;
            }
        }
        setFlagBits = setFlagBits | newBit;
        newBit = 0;
        j8 = engineClass + 8;
        if (savd_isUnlockBitSet(j8) == 0) {
            if (func_02090cf8_inline(4, engineClass) != FALSE && func_02090cf8_inline(5, engineClass) != FALSE) {
                savd_setUnlockBit(j8);
                newBit = 4;
            }
        }
        setFlagBits = setFlagBits | newBit;
        newBit = 0;
        j12 = engineClass + 12;
        if (savd_isUnlockBitSet(j12) == 0) {
            if (func_02090cf8_inline(6, engineClass) != FALSE) {
                savd_setUnlockBit(j12);
                newBit = 8;
            }
        }
        setFlagBits = setFlagBits | newBit;
    }
    q = 0;
    if (savd_isUnlockBitSet(0x10) == 0) {
        if (func_02090cf8_inline(3, 2) != FALSE && func_02090cf8_inline(7, 2) != FALSE) {
            savd_setUnlockBit(0x10);
            q = 0x10;
        }
    }
    return setFlagBits | q;
}

u32 unlock_tryUnlockCharacters(void) {
    u32 setFlagBits;
    BOOL t;
    setFlagBits = 0;
    t = FALSE;
    if (savd_isUnlockBitSet(0x14) == 0) {
        if ((savd_getIsCupPlayed(3, 0) != 0 && savd_getCupTrophy(3, 0) == 0) ? 1 : 0) {
            savd_setUnlockBit(0x14);
            t = TRUE;
        }
    }
    if (t != FALSE) {
        setFlagBits = setFlagBits | 0x20;
    }
    t = FALSE;
    if (savd_isUnlockBitSet(0x15) == 0) {
        if ((savd_getIsCupPlayed(7, t) != 0 && savd_getCupTrophy(7, t) == 0) ? 1 : 0) {
            savd_setUnlockBit(0x15);
            t = TRUE;
        }
    }
    if (t != FALSE) {
        setFlagBits = setFlagBits | 0x40;
    }
    t = FALSE;
    if (savd_isUnlockBitSet(0x16) == 0) {
        if ((savd_getIsCupPlayed(7, 1) != 0 && savd_getCupTrophy(7, 1) == 0) ? 1 : 0) {
            savd_setUnlockBit(0x16);
            t = TRUE;
        }
    }
    if (t != FALSE) {
        setFlagBits = setFlagBits | 0x80;
    }
    t = FALSE;
    if (savd_isUnlockBitSet(0x17) == 0) {
        BOOL isFilledTopRank;
        if (savd_getIsCupPlayed(3, 3) != 0 && savd_getCupTrophy(3, 3) == 0) {
            isFilledTopRank = TRUE;
        } else {
            isFilledTopRank = FALSE;
        }
        if (isFilledTopRank != FALSE) {
            goto l1;
        }
        if (savd_getIsCupPlayed(7, 3) != 0 && savd_getCupTrophy(7, 3) == 0) {
            isFilledTopRank = TRUE;
        } else {
            isFilledTopRank = FALSE;
        }
        if (isFilledTopRank != FALSE) {
        l1:
            savd_setUnlockBit(0x17);
            t = TRUE;
        }
    }
    if (t != FALSE) {
        setFlagBits = setFlagBits | 0x100;
    }
    return setFlagBits;
}

s32 unlock_hasUnlockedTrueStaffRoll(void) {
    Unk0217b488 *p;
    s32 result;
    s32 n;
    s32 engineClass;
    BOOL c;
    BOOL f;
    result = 0;
    p = gStruct217B488;
    engineClass = p->mEngineIndex;
    n = p->mCupIndex;
    if (p->mMirrorMode != 0) {
        engineClass = 3;
    }
    c = FALSE;
    f = func_02090940_inline();
    if (f != FALSE) {
        if (n == 3 || n == 7) {
            if (gStruct217B488->mCupRankIndex == 0) {
                c = TRUE;
            }
        }
    }
    if (c != FALSE) {
        result = 2;
    } else {
        c = FALSE;
        if (n == 3 || n == 7) {
            if (n == 7) {
                n = 3;
            } else {
                n = 7;
            }
            if (savd_getIsCupPlayed(n, engineClass) != 0 && savd_getCupTrophy(n, engineClass) <= 2) {
                f = TRUE;
            } else {
                f = FALSE;
            }
            if (f != FALSE) {
                if (gStruct217B488->mCupRankIndex <= 2) {
                    c = TRUE;
                }
            }
        }
        if (c != FALSE) {
            result = 1;
        }
    }
    return result;
}

BOOL unlock_hasUnlockedTrueTitleScreen(void) {
    return func_02090940_inline();
}

void unlock_loadStaffGhostTime(void *heap) {
    arc_loadFile(aDataGhostStaff, heap, (void **) &unlock_sStaffGhostTime);
}

// TRUE when the time is smaller than entry a - 1 of the staff ghost times.
BOOL unlock_isFasterThanStaffGhost(u32 entryNumber, void *timeArg) {
    MinuteSecondMillisecondTime *time = timeArg;
    return time->mSecond * 1000 + time->mMinute * 60000 + time->mMillisecond < unlock_sStaffGhostTime[entryNumber - 1];
}

void SetupKartKillerCursor(KartKillerCursor *kartKillerCursor, u32 kartIndex) {
    Kart *kart;
    kart = driver_getById(kartIndex);
    kartKillerCursor->mKillerKartIndex = kartIndex;
    SetupPointLinkCursor(&kartKillerCursor->mPointLinkCursor, kartIndex,
                         (Unk02080b1c_00 *) it_sDriverItemStatus[kartIndex].field1F0.mLink);
    kartKillerCursor->field26 = 0;
    kartKillerCursor->field28 = 0;
    kart->mTurnAngle = 0;
    driver_endDrift(kart);
}

void kill_recalculateRoute(KartKillerCursor *kartKillerCursor, Unk02080b1c_00 *link) {
    if (link == kartKillerCursor->mPointLinkCursor.mPreviousLink) {
        return;
    }
    SetupPointLinkCursor(&kartKillerCursor->mPointLinkCursor, kartKillerCursor->mKillerKartIndex, link);
}

s32 func_0209081c(KartKillerCursor *kartKillerCursor) {
    AdvanceKartKillerAlongPointLinks(kartKillerCursor);
    return func_020905a8(kartKillerCursor);
}

// Holds the kart at a fixed speed, steers it toward the point link ahead, and moves the cursor on once the kart is past
// that link or close to it.
void AdvanceKartKillerAlongPointLinks(KartKillerCursor *kartKillerCursor) {
    Kart *kart;
    Vec3 position;
    s32 isPastOrNearLink;
    kart = driver_getById(kartKillerCursor->mKillerKartIndex);
    position = kart->mPos;
    kartKillerCursor->mAngleToLinkDegrees = ComputeAngleToPositionDegrees(
        kartKillerCursor->mPointLinkCursor.mLink->field18, &position, &kart->field12C, &kart->field138);
    if ((kart->field48 & 0x40000000) != 0 && kart->mSurfaceVariant == 1) {
        isPastOrNearLink = IsPastPointLink(&kartKillerCursor->mPointLinkCursor, &position);
    } else {
        isPastOrNearLink = IsPastPointLink(&kartKillerCursor->mPointLinkCursor, &position);
        if (isPastOrNearLink == 0) {
            isPastOrNearLink = IsWithinPointLinkDistance(&kartKillerCursor->mPointLinkCursor, &position);
        }
    }
    kart->mForwardSpeed = 0xa800;
    kart->mSpeedLimitGoal = kart->mForwardSpeed;
    kart->mSpeedLimit = kart->mSpeedLimitGoal;
    if (isPastOrNearLink != 0) {
        AdvancePointLinkCursorToFirstNext((u32) kartKillerCursor);
    } else {
        TurnKartKillerTowardPointLink(kartKillerCursor);
    }
}

// Turns the kart toward the point link ahead; the left and right keys first nudge the heading.
void TurnKartKillerTowardPointLink(KartKillerCursor *kartKillerCursor) {
    Kart *kart;
    s32 angleToLinkDegrees;
    s32 turnFactor;
    u16 padBits;
    u16 targetHeadingAngle;
    s32 angleDifference;
    s32 angleDifferenceAbs;
    s32 entryIndex;
    kart = driver_getById(kartKillerCursor->mKillerKartIndex);
    angleToLinkDegrees = kartKillerCursor->mAngleToLinkDegrees;
    if ((kart->field44 & KART_44_ON_GROUND) != 0) {
        turnFactor = 0x19a;
    } else {
        turnFactor = 0x52;
    }
    targetHeadingAngle = kart->mHeadingAngle + (s16) (((s64) angleToLinkDegrees * 0xb6 + 0x800) >> 12);
    entryIndex = *(volatile s32 *) &kart->mEntryIndex;
    padBits = data_0217562a[entryIndex].mBits;
    if ((u16) (padBits & PAD_KEY_LEFT) != 0) {
        kart->mHeadingAngle = kart->mHeadingAngle + 0xa0;
    } else if ((u16) (padBits & PAD_KEY_RIGHT) != 0) {
        kart->mHeadingAngle = kart->mHeadingAngle - 0xa0;
    }
    angleDifference = targetHeadingAngle - kart->mHeadingAngle;
    angleDifferenceAbs = angleDifference;
    angleDifferenceAbs = (angleDifferenceAbs < 0) ? -angleDifferenceAbs : angleDifferenceAbs;
    if (angleDifferenceAbs > 0x7fff) {
        if (angleDifference > 0) {
            angleDifference = -(0xffff - angleDifference);
        } else {
            angleDifference = angleDifference + 0xffff;
        }
    }
    kart->mHeadingAngle = kart->mHeadingAngle + (s32) (((s64) angleDifference * turnFactor) >> 12);
}

s32 func_020905a8(KartKillerCursor *kartKillerCursor) {
    BOOL limitReached;
    BOOL isCounting;
    Kart *kart;
    limitReached = FALSE;
    isCounting = FALSE;
    kartKillerCursor->field28 = kartKillerCursor->field28 - 1;
    if (kartKillerCursor->field28 <= 0) {
        kartKillerCursor->field28 = 0;
    } else {
        isCounting = TRUE;
    }
    kart = driver_getById(kartKillerCursor->mKillerKartIndex);
    if ((kart->field44 & 0xc0) != 0) {
        isCounting = TRUE;
        kartKillerCursor->field28 = 5;
    }
    if (isCounting != FALSE) {
        kartKillerCursor->field26 = kartKillerCursor->field26 + 1;
        if (kartKillerCursor->field26 >= 0x78) {
            kartKillerCursor->field26 = 0;
            limitReached = TRUE;
        }
    } else if (kartKillerCursor->field28 <= 0) {
        kartKillerCursor->field26 = 0;
    }
    return limitReached;
}

// Stores one of three sets of battle item entry tables and callbacks; any value other than 1 or 2 takes the third set.
void mgenit_setupFunctions(void) {
    switch (gRaceMultiConfig->mCpuDifficulty) {
        case CPU_DIFFICULTY_EASY:
            gBattleHeldItemEntries = data_021561d0;
            gBattleItemInUseEntries = data_02155fd8;
            gThrowItemCircleKindCallback = func_0208fafc;
            gUseItemCircleKindCallback = UseItemAfterInUse;
            gThrowItemNotCircleKindCallback = func_0208f9ac;
            gUseItemNotCircleKindCallback = func_0208f6d4;
            gThrowItemTrailKindCallback = func_0208f4e8;
            gThrowItemNotTrailKindCallback = UseItemBehindAfterInUseOrNearTarget;
            return;
        case CPU_DIFFICULTY_NORMAL:
            gBattleHeldItemEntries = data_021562a8;
            gBattleItemInUseEntries = data_02156128;
            gThrowItemCircleKindCallback = func_0208fba0;
            gUseItemCircleKindCallback = func_0208f810;
            gThrowItemNotCircleKindCallback = func_0208f9ac;
            gUseItemNotCircleKindCallback = func_0208f6d4;
            gThrowItemTrailKindCallback = func_0208f4e8;
            gThrowItemNotTrailKindCallback = UseItemBehindAfterInUseOrNearTarget;
            return;
        case CPU_DIFFICULTY_HARD:
            gBattleHeldItemEntries = data_02156380;
            gBattleItemInUseEntries = data_02156080;
            gThrowItemCircleKindCallback = ThrowItemAtNearTarget;
            gUseItemCircleKindCallback = func_0208f8ac;
            gThrowItemNotCircleKindCallback = func_0208fa50;
            gUseItemNotCircleKindCallback = func_0208f754;
            gThrowItemTrailKindCallback = func_0208f5c4;
            gThrowItemNotTrailKindCallback = func_0208f434;
            return;
        default:
            gBattleHeldItemEntries = data_02156380;
            gBattleItemInUseEntries = data_02156080;
            gThrowItemCircleKindCallback = ThrowItemAtNearTarget;
            gUseItemCircleKindCallback = func_0208f8ac;
            gThrowItemNotCircleKindCallback = func_0208fa50;
            gUseItemNotCircleKindCallback = func_0208f754;
            gThrowItemTrailKindCallback = func_0208f5c4;
            gThrowItemNotTrailKindCallback = func_0208f434;
            return;
    }
}
