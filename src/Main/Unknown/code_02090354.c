#include "Main/Unknown/code_02090354.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_020483e4.h"
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

void CreateSmanTop(void *mapObjectList) {
    MapObjectModel *mapObjectModelNsbmd;
    mapObjectModelNsbmd = CreateMapObjectModelNsbmd(mapObjectList, gSmanTopNsbmdName);
    gSmanTop = mapObjectModelNsbmd;
    SetMapObjectModelPolygonId(mapObjectModelNsbmd, 0x3f);
}

void SetupDrawSmanTop(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gSmanTop);
}

void DrawSmanTop(void *mapObjectList, Sman *sman) {
    s32 commandArg;
    MtxFx33 matrix;
    s32 topOffset[3];
    commandArg = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandArg, 1);
    NNS_G3dGeBufferOP_N(0x19, SetViewRotatedMatrixPos(&sman->mMapObject.mPos), 0xc);
    topOffset[1] = sman->mTopHeight >> 4;
    topOffset[0] = 0;
    topOffset[2] = 0;
    NNS_G3dGeBufferOP_N(0x1c, topOffset, 3);
    NNS_G3dGeBufferOP_N(0x1b, &sman->mMapObject.mScale, 3);
    MTX_RotZ33_(&matrix, gPairsByAngle[((u16) sman->mAngleZ >> 4) * 2],
                gPairsByAngle[((u16) sman->mAngleZ >> 4) * 2 + 1]);
    NNS_G3dGeBufferOP_N(0x1a, &matrix, 9);
    DrawMapObjectModel(mapObjectList, gSmanTop, sman);
}

void CreateSmanBottom(void *mapObjectList) {
    MapObjectModel *mapObjectModelNsbmd;
    mapObjectModelNsbmd = CreateMapObjectModelNsbmd(mapObjectList, gSmanBottomNsbmdName);
    gSmanBottom = mapObjectModelNsbmd;
    SetMapObjectModelPolygonId(mapObjectModelNsbmd, 0x3f);
}

void SetupDrawSmanBottom(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gSmanBottom);
}

void DrawSmanBottom(void *mapObjectList, Sman *sman) {
    s32 commandArg;
    s32 scale[3];
    s32 bottomScale;
    commandArg = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandArg, 1);
    NNS_G3dGeBufferOP_N(0x19, SetViewRotatedMatrixPos(&sman->mMapObject.mPos), 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &sman->mMapObject.mScale, 3);
    bottomScale = sman->mBottomScale;
    scale[0] = bottomScale;
    scale[1] = bottomScale;
    scale[2] = bottomScale;
    NNS_G3dGeBufferOP_N(0x1b, scale, 3);
    DrawMapObjectModel(mapObjectList, gSmanBottom, sman);
}

void InitSmanObjects(SmanList *smanList) {
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
        sman->mTopStartHeight = MUL_FIXED12_NO_ROUND(sman->mMapObject.mScale.y, 0xf333);
        sman->mTopLowHeight = MUL_FIXED12_NO_ROUND(sman->mMapObject.mScale.y, 0x2000);
        sman->mTopHeight = sman->mTopStartHeight;
    }
}

void UpdateSman(void *mapObjectList, Sman *sman) {
    SoundStartParams soundRequest;
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
            if (sman->mMapObject.mCourseMapRow->mUnk_28 > 0) {
                if (sman->mTopHeight < 0) {
                    ParkMapObject(&sman->mMapObject);
                }
            } else if (sman->mTopHeight < sman->mTopLowHeight) {
                sman->mTopHeight = sman->mTopLowHeight;
                sman->mTopHeightPerFrame = 0;
                sman->mState = 2;
                falloffIndex = 2;
                if ((sman->mMapObject.mDistanceSquaredAndFlags & 4) == 0) {
                    if (sman->mMapObject.mFarDistanceSquared != gSoundFalloffs[2].mUnk_20) {
                        if (sman->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
                            falloffIndex = 3;
                        } else {
                            falloffIndex = 4;
                        }
                    }
                    soundRequest.mSoundId = 0x162;
                    soundRequest.mPositionSource = &sman->mMapObject.mPos;
                    soundRequest.mFalloffIndex = falloffIndex;
                    soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&sman->mMapObject.mPos);
                    StartSoundFromParams(&soundRequest);
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
void CreateSmanKindData(void) {
    CreateMapObjectKindDataWithSound(CollideKartWithSman, CollideItemObjectWithSman, NULL, 0, 1, 0x161);
}

static inline BOOL func_02090940_inline(void) {
    BOOL isFilledTopRank;
    enum { K0 } cup;
    enum { L0 } engineClass;
    for (cup = 0; cup < 8; cup++) {
        for (engineClass = 0; engineClass < 4; engineClass++) {
            if (IsGrandPrixRecordFilled(cup, engineClass) != 0 && GetGrandPrixRecordCupRank(cup, engineClass) == 0) {
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

void *CreateSmanTopDrawList(void) {
    return CreateMapObjectDrawList2(CreateSmanTop, DrawSmanTop, SetupDrawSmanTop);
}

void *CreateSmanBottomDrawList(void) {
    return CreateMapObjectDrawList2(CreateSmanBottom, DrawSmanBottom, SetupDrawSmanBottom);
}

void *CreateSmanUpdateList(void) {
    return CreateMapObjectUpdateList(InitSmanObjects, UpdateSman, NULL);
}

static inline BOOL func_02090cf8_inline(s32 cup, s32 engineClass) {
    if (IsGrandPrixRecordFilled(cup, engineClass) != 0 && GetGrandPrixRecordCupRank(cup, engineClass) == 0) {
        return TRUE;
    }
    return FALSE;
}

u32 SetAndWriteSecretMessageFlags(void) {
    u32 setFlagBits;
    setFlagBits = 0;
    if (GetCurrentSceneNumber() == 10) {
        setFlagBits = SetSecretMessageFlags();
        WriteBackupFirstBlockWrapper();
        WaitThreadFunctionsDone();
        if (gBackupAccess->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    return setFlagBits;
}

u32 SetSecretMessageFlagsWrapper(void) {
    return SetSecretMessageFlags();
}

// Sets the backup flags and kart appear limit earned by top-rank records; returns one bit per new secret message.
u32 SetSecretMessageFlags(void) {
    u32 setFlagBits;
    u32 limitRaiseBit;
    BOOL isLimitRaised;
    setFlagBits = 0;
    setFlagBits = setFlagBits | SetSecretMessageFlagsPerEngineClass();
    setFlagBits = setFlagBits | SetSecretMessageFlagsFromCups3And7();
    limitRaiseBit = 0;
    isLimitRaised = FALSE;
    if (GetKartAppearLimit() < 2) {
        if ((IsGrandPrixRecordFilled(3, 1) != 0 && GetGrandPrixRecordCupRank(3, 1) == 0) ? 1 : 0) {
            RaiseKartAppearLimit(2);
            isLimitRaised = TRUE;
        }
    }
    if (isLimitRaised != FALSE) {
        limitRaiseBit = 0x200;
    }
    isLimitRaised = FALSE;
    if (GetKartAppearLimit() < 3) {
        BOOL isFilledTopRank;
        if (IsGrandPrixRecordFilled(3, 2) != 0 && GetGrandPrixRecordCupRank(3, 2) == 0) {
            isFilledTopRank = TRUE;
        } else {
            isFilledTopRank = FALSE;
        }
        if (isFilledTopRank != FALSE) {
            goto l1;
        }
        if (IsGrandPrixRecordFilled(7, 2) != 0 && GetGrandPrixRecordCupRank(7, 2) == 0) {
            isFilledTopRank = TRUE;
        } else {
            isFilledTopRank = FALSE;
        }
        if (isFilledTopRank != FALSE) {
        l1:
            RaiseKartAppearLimit(3);
            isLimitRaised = TRUE;
        }
    }
    if (isLimitRaised != FALSE) {
        limitRaiseBit = 0x400;
    }
    isLimitRaised = FALSE;
    if (GetKartAppearLimit() < 4) {
        if ((IsGrandPrixRecordFilled(3, 3) != 0 && GetGrandPrixRecordCupRank(3, 3) == 0) ? 1 : 0) {
            if ((IsGrandPrixRecordFilled(7, 3) != 0 && GetGrandPrixRecordCupRank(7, 3) == 0) ? 1 : 0) {
                RaiseKartAppearLimit(4);
                isLimitRaised = TRUE;
            }
        }
    }
    if (isLimitRaised != FALSE) {
        limitRaiseBit = 0x800;
    }
    return setFlagBits | limitRaiseBit;
}

u32 SetSecretMessageFlagsPerEngineClass(void) {
    enum { K0 } engineClass;
    u32 setFlagBits;
    u32 lastGroupBit;
    u32 newBit;
    s32 j4;
    s32 j8;
    s32 j12;
    setFlagBits = 0;
    for (engineClass = 0; engineClass < 4; engineClass++) {
        newBit = 0;
        if (IsBackupFlagSet(engineClass) == 0) {
            if (func_02090cf8_inline(0, engineClass) != FALSE && func_02090cf8_inline(1, engineClass) != FALSE) {
                SetBackupFlag(engineClass);
                newBit = 1;
            }
        }
        setFlagBits = setFlagBits | newBit;
        newBit = 0;
        j4 = engineClass + 4;
        if (IsBackupFlagSet(j4) == 0) {
            if (func_02090cf8_inline(2, engineClass) != FALSE) {
                SetBackupFlag(j4);
                newBit = 2;
            }
        }
        setFlagBits = setFlagBits | newBit;
        newBit = 0;
        j8 = engineClass + 8;
        if (IsBackupFlagSet(j8) == 0) {
            if (func_02090cf8_inline(4, engineClass) != FALSE && func_02090cf8_inline(5, engineClass) != FALSE) {
                SetBackupFlag(j8);
                newBit = 4;
            }
        }
        setFlagBits = setFlagBits | newBit;
        newBit = 0;
        j12 = engineClass + 12;
        if (IsBackupFlagSet(j12) == 0) {
            if (func_02090cf8_inline(6, engineClass) != FALSE) {
                SetBackupFlag(j12);
                newBit = 8;
            }
        }
        setFlagBits = setFlagBits | newBit;
    }
    lastGroupBit = 0;
    if (IsBackupFlagSet(0x10) == 0) {
        if (func_02090cf8_inline(3, 2) != FALSE && func_02090cf8_inline(7, 2) != FALSE) {
            SetBackupFlag(0x10);
            lastGroupBit = 0x10;
        }
    }
    return setFlagBits | lastGroupBit;
}

u32 SetSecretMessageFlagsFromCups3And7(void) {
    u32 setFlagBits;
    BOOL t;
    setFlagBits = 0;
    t = FALSE;
    if (IsBackupFlagSet(0x14) == 0) {
        if ((IsGrandPrixRecordFilled(3, 0) != 0 && GetGrandPrixRecordCupRank(3, 0) == 0) ? 1 : 0) {
            SetBackupFlag(0x14);
            t = TRUE;
        }
    }
    if (t != FALSE) {
        setFlagBits = setFlagBits | 0x20;
    }
    t = FALSE;
    if (IsBackupFlagSet(0x15) == 0) {
        if ((IsGrandPrixRecordFilled(7, t) != 0 && GetGrandPrixRecordCupRank(7, t) == 0) ? 1 : 0) {
            SetBackupFlag(0x15);
            t = TRUE;
        }
    }
    if (t != FALSE) {
        setFlagBits = setFlagBits | 0x40;
    }
    t = FALSE;
    if (IsBackupFlagSet(0x16) == 0) {
        if ((IsGrandPrixRecordFilled(7, 1) != 0 && GetGrandPrixRecordCupRank(7, 1) == 0) ? 1 : 0) {
            SetBackupFlag(0x16);
            t = TRUE;
        }
    }
    if (t != FALSE) {
        setFlagBits = setFlagBits | 0x80;
    }
    t = FALSE;
    if (IsBackupFlagSet(0x17) == 0) {
        BOOL isFilledTopRank;
        if (IsGrandPrixRecordFilled(3, 3) != 0 && GetGrandPrixRecordCupRank(3, 3) == 0) {
            isFilledTopRank = TRUE;
        } else {
            isFilledTopRank = FALSE;
        }
        if (isFilledTopRank != FALSE) {
            goto l1;
        }
        if (IsGrandPrixRecordFilled(7, 3) != 0 && GetGrandPrixRecordCupRank(7, 3) == 0) {
            isFilledTopRank = TRUE;
        } else {
            isFilledTopRank = FALSE;
        }
        if (isFilledTopRank != FALSE) {
        l1:
            SetBackupFlag(0x17);
            t = TRUE;
        }
    }
    if (t != FALSE) {
        setFlagBits = setFlagBits | 0x100;
    }
    return setFlagBits;
}

// Returns 0 none, 1 the staff roll, 2 the true staff roll (all records top rank); both need cup 3 or 7 finished.
s32 GetStaffRollKindAfterGp(void) {
    MenuShared *p;
    s32 result;
    s32 n;
    s32 engineClass;
    BOOL c;
    BOOL f;
    result = 0;
    p = gMenuShared;
    engineClass = p->mEngineIndex;
    n = p->mCupIndex;
    if (p->mMirrorMode != 0) {
        engineClass = 3;
    }
    c = FALSE;
    f = func_02090940_inline();
    if (f != FALSE) {
        if (n == 3 || n == 7) {
            if (gMenuShared->mCupRankIndex == 0) {
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
            if (IsGrandPrixRecordFilled(n, engineClass) != 0 && GetGrandPrixRecordCupRank(n, engineClass) <= 2) {
                f = TRUE;
            } else {
                f = FALSE;
            }
            if (f != FALSE) {
                if (gMenuShared->mCupRankIndex <= 2) {
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

BOOL IsAllGrandPrixRecordsTopRank(void) {
    return func_02090940_inline();
}

void LoadStaffGhostTime(void *heap) {
    LoadFileIntoHeap(gStaffGhostTimeBinName, heap, (void **) &gStaffGhostTime);
}

// TRUE when the time is smaller than entry a - 1 of the staff ghost times.
BOOL IsTimeLessThanStaffGhostTime(u32 entryNumber, MinuteSecondMillisecondTime *time) {
    return time->mSecond * 1000 + time->mMinute * 60000 + time->mMillisecond < gStaffGhostTime[entryNumber - 1];
}

void SetupKartKillerCursor(KartKillerCursor *kartKillerCursor, u32 kartIndex) {
    Kart *kart;
    kart = GetKart(kartIndex);
    kartKillerCursor->mKillerKartIndex = kartIndex;
    SetupPointLinkCursor(&kartKillerCursor->mPointLinkCursor, kartIndex,
                         (RacePointLink *) gKartItems[kartIndex].mItemLink.mLink);
    kartKillerCursor->mEndCount = 0;
    kartKillerCursor->mEndCountHoldTimer = 0;
    kart->mTurnAngle = 0;
    EndKartDrift(kart);
}

void ResetKartKillerCursorTo(KartKillerCursor *kartKillerCursor, RacePointLink *link) {
    if (link == kartKillerCursor->mPointLinkCursor.mPreviousLink) {
        return;
    }
    SetupPointLinkCursor(&kartKillerCursor->mPointLinkCursor, kartKillerCursor->mKillerKartIndex, link);
}

BOOL AdvanceKartKillerCursor(KartKillerCursor *kartKillerCursor) {
    AdvanceKartKillerAlongPointLinks(kartKillerCursor);
    return AdvanceKartKillerEndCount(kartKillerCursor);
}

// Holds the kart at a fixed speed, steers it toward the point link ahead, and moves the cursor on once the kart is past
// that link or close to it.
void AdvanceKartKillerAlongPointLinks(KartKillerCursor *kartKillerCursor) {
    Kart *kart;
    Vec3 position;
    s32 isPastOrNearLink;
    kart = GetKart(kartKillerCursor->mKillerKartIndex);
    position = kart->mPos;
    kartKillerCursor->mAngleToLinkDegrees = ComputeAngleToPositionDegrees(
        kartKillerCursor->mPointLinkCursor.mLink->mPoint, &position, &kart->mUnk_12c, &kart->mUnk_138);
    if ((kart->mUnk_48 & 0x40000000) != 0 && kart->mSurfaceVariant == 1) {
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
        AdvancePointLinkCursorToFirstNext(&kartKillerCursor->mPointLinkCursor);
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
    kart = GetKart(kartKillerCursor->mKillerKartIndex);
    angleToLinkDegrees = kartKillerCursor->mAngleToLinkDegrees;
    if ((kart->mUnk_44 & KART_44_ON_GROUND) != 0) {
        turnFactor = 0x19a;
    } else {
        turnFactor = 0x52;
    }
    targetHeadingAngle = kart->mHeadingAngle + (s16) MUL_FIXED12_ROUNDED(angleToLinkDegrees, 0xb6);
    entryIndex = *(volatile s32 *) &kart->mEntryIndex;
    padBits = gInputSlots[entryIndex].mBits;
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
    kart->mHeadingAngle = kart->mHeadingAngle + MUL_FIXED12_NO_ROUND(angleDifference, turnFactor);
}

BOOL AdvanceKartKillerEndCount(KartKillerCursor *kartKillerCursor) {
    BOOL limitReached;
    BOOL isCounting;
    Kart *kart;
    limitReached = FALSE;
    isCounting = FALSE;
    kartKillerCursor->mEndCountHoldTimer = kartKillerCursor->mEndCountHoldTimer - 1;
    if (kartKillerCursor->mEndCountHoldTimer <= 0) {
        kartKillerCursor->mEndCountHoldTimer = 0;
    } else {
        isCounting = TRUE;
    }
    kart = GetKart(kartKillerCursor->mKillerKartIndex);
    if ((kart->mUnk_44 & 0xc0) != 0) {
        isCounting = TRUE;
        kartKillerCursor->mEndCountHoldTimer = 5;
    }
    if (isCounting != FALSE) {
        kartKillerCursor->mEndCount = kartKillerCursor->mEndCount + 1;
        if (kartKillerCursor->mEndCount >= 0x78) {
            kartKillerCursor->mEndCount = 0;
            limitReached = TRUE;
        }
    } else if (kartKillerCursor->mEndCountHoldTimer <= 0) {
        kartKillerCursor->mEndCount = 0;
    }
    return limitReached;
}

// Stores one of three sets of battle item entry tables and callbacks; any value other than 1 or 2 takes the third set.
void SetupBattleItemEntries(void) {
    switch (gRaceSetup->mCpuDifficulty) {
        case CPU_DIFFICULTY_EASY:
            gBattleHeldItemEntries = gBattleEasyHeldItemEntries;
            gBattleItemInUseEntries = gBattleEasyItemInUseEntries;
            gThrowItemCircleKindCallback = EasyThrowItemRandomAfterInUse;
            gUseItemCircleKindCallback = UseItemAfterInUse;
            gThrowItemNotCircleKindCallback = ThrowItemRandomAfterInUse;
            gUseItemNotCircleKindCallback = UseItemAfterInUseAtNearTargetAhead;
            gThrowItemTrailKindCallback = ThrowItemRandomAfterInUseOrBehindNearTarget;
            gThrowItemNotTrailKindCallback = UseItemBehindAfterInUseOrNearTarget;
            return;
        case CPU_DIFFICULTY_NORMAL:
            gBattleHeldItemEntries = gBattleNormalHeldItemEntries;
            gBattleItemInUseEntries = gBattleNormalItemInUseEntries;
            gThrowItemCircleKindCallback = ThrowItemRandomAfterInUseOrAtNearTarget;
            gUseItemCircleKindCallback = NormalUseItemAfterInUseAtNearTargetAheadDot;
            gThrowItemNotCircleKindCallback = ThrowItemRandomAfterInUse;
            gUseItemNotCircleKindCallback = UseItemAfterInUseAtNearTargetAhead;
            gThrowItemTrailKindCallback = ThrowItemRandomAfterInUseOrBehindNearTarget;
            gThrowItemNotTrailKindCallback = UseItemBehindAfterInUseOrNearTarget;
            return;
        case CPU_DIFFICULTY_HARD:
            gBattleHeldItemEntries = gBattleHardHeldItemEntries;
            gBattleItemInUseEntries = gBattleHardItemInUseEntries;
            gThrowItemCircleKindCallback = ThrowItemAtNearTarget;
            gUseItemCircleKindCallback = UseItemAfterInUseAtNearTargetAheadDot;
            gThrowItemNotCircleKindCallback = ThrowItemAtNearTargetAfterInUseEveryCall;
            gUseItemNotCircleKindCallback = HardUseItemAfterInUseAtNearTargetAhead;
            gThrowItemTrailKindCallback = ThrowItemAtNearTargetAheadDotAfterInUse;
            gThrowItemNotTrailKindCallback = ThrowItemBehindNearTargetAfterInUseEveryCall;
            return;
        default:
            gBattleHeldItemEntries = gBattleHardHeldItemEntries;
            gBattleItemInUseEntries = gBattleHardItemInUseEntries;
            gThrowItemCircleKindCallback = ThrowItemAtNearTarget;
            gUseItemCircleKindCallback = UseItemAfterInUseAtNearTargetAheadDot;
            gThrowItemNotCircleKindCallback = ThrowItemAtNearTargetAfterInUseEveryCall;
            gUseItemNotCircleKindCallback = HardUseItemAfterInUseAtNearTargetAhead;
            gThrowItemTrailKindCallback = ThrowItemAtNearTargetAheadDotAfterInUse;
            gThrowItemNotTrailKindCallback = ThrowItemBehindNearTargetAfterInUseEveryCall;
            return;
    }
}
