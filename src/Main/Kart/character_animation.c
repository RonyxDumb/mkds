#include "Main/Kart/character_animation.h"
#include "Main/Item/item_in_use.h"
#include "code_02010c84.h"
#include "Main/Kart/karts.h"
#include "Main/Graphics/model_animation_loop_mode.h"
#include "Main/Graphics/model_animation.h"
#include "Main/Kart/kart_model_path.h"
#include "ITCM/code_01ff8000.h"
#include "Main/Race/race_clock.h"
#include "Main/Race/race_hud_sub_screen_item_box_cells.h"
#include "Main/Sound/seq_row.h"
#include "Main/MapObjects/data_02155000.h"
#include "Main/MapObjects/data_02165000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "code_0200fe74.h"
#include "code_020109c4.h"
#include "code_02012b30.h"
#include "code_02134398.h"
#include "Main/Kart/kart_participant_record.h"
#include "Main/Kart/code_0208fd8c.h"
#include "Main/Kart/point_link_cursor.h"

const s32 gCharacterFaceFrames[2] = {0, 0x1000};
const KartAiItemUseEntry gRaceItemInUseEntries[14] = {{UseItemAfterInUseByCircleKind, 1, 0x5, 0x10}, {UseItemAfterInUseByCircleKind, 1, 0x8, 0x5}, {UseItemAfterInUseByTrailKind, 2, 0x1, 0x14}, {(KartAiItemHandler) RaceItemInUseReturnArgument, 0, 0x3, 0xa}, {(KartAiItemHandler) RaceItemInUseReturnArgument, 0, 0x3, 0xa}, {(KartAiItemHandler) RaceItemInUseReturnArgument, 0, 0x3, 0xa}, {(KartAiItemHandler) RaceItemInUseReturnArgument, 0, 0x3, 0xa}, {(KartAiItemHandler) RaceItemInUseReturnArgument, 2, 0x3, 0xa}, {(KartAiItemHandler) RaceItemInUseReturnArgument, 2, 0x3, 0xa}, {UseItemAfterInUseByTrailKind, 1, 0x1, 0x14}, {(KartAiItemHandler) RaceItemInUseReturnArgument, 2, 0x3, 0xa}, {(KartAiItemHandler) RaceItemInUseReturnArgument, 2, 0x3, 0xa}, {(KartAiItemHandler) RaceItemInUseReturnArgument, 2, 0x3, 0xa}, {(KartAiItemHandler) RaceItemInUseReturnArgument, 2, 0x3, 0xa}};
const KartAiItemUseEntry gRaceNormalHeldItemEntries[18] = {{UseItemByRankOrEveryCall, 1, 0x0, 0x34}, {UseItemByRankAfterHeld, 1, 0x0, 0x34}, {UseItemByRankOrEveryCall, 2, 0x0, 0x34}, {UseItemByRankAfterHeld, 2, 0x0, 0x34}, {UseItemAfterHeldIfTurnUnder20, 0, 0x0, 0xa}, {UseItemIfTurnUnder20ResetHeldTimer, 0, 0x5, 0xa}, {UseItemByRankAfterHeld, 2, 0x0, 0x34}, {UseItemAfterHeld, 0, 0x0, 0xa}, {UseItemAfterHeld, 0, 0x0, 0xa}, {TrailOrCircleUseItemAfterHeld, 1, 0x0, 0xa}, {TrailOrCircleUseItemAfterHeld, 1, 0x0, 0xa}, {TrailOrCircleUseItemAfterHeld, 1, 0x0, 0xa}, {UseItemAfterHeld, 0, 0x0, 0xa}, {UseItemIfTurnUnder20ResetHeldTimer, 0, 0x0, 0xa}, {UseItemAfterHeld, 0, 0x0, 0xa}, {UseItemAfterHeld, 0, 0x0, 0xa}, {UseItemAfterHeld, 0, 0x0, 0xa}, {UseItemAfterHeld, 0, 0x0, 0xa}};
const KartAiItemUseEntry gRaceHardHeldItemEntries[18] = {{UseItemByTargetOrRankOrEveryCall, 1, 0x0, 0x34}, {UseItemByTargetOrRankAfterHeld, 1, 0x0, 0x34}, {UseItemByTargetOrRankOrEveryCall, 2, 0x0, 0x34}, {UseItemByTargetOrRankAfterHeld, 2, 0x0, 0x34}, {UseItemAfterHeldIfTurnUnder20, 0, 0x0, 0xa}, {UseItemIfTurnUnder20ResetHeldTimer, 0, 0x5, 0xa}, {UseItemByTargetOrRankAfterHeld, 2, 0x0, 0x34}, {UseItemAfterHeld, 0, 0x0, 0xa}, {UseItemAfterHeld, 0, 0x0, 0xa}, {TrailOrCircleUseItemAfterHeld, 1, 0x0, 0xa}, {TrailOrCircleUseItemAfterHeld, 1, 0x0, 0xa}, {TrailOrCircleUseItemAfterHeld, 1, 0x0, 0xa}, {UseItemAfterHeld, 0, 0x0, 0xa}, {UseItemIfTurnUnder20ResetHeldTimer, 0, 0x0, 0xa}, {UseItemAfterHeld, 0, 0x0, 0xa}, {UseItemAfterHeld, 0, 0x0, 0xa}, {UseItemAfterHeld, 0, 0x0, 0xa}, {UseItemAfterHeld, 0, 0x0, 0xa}};
const KartAiItemUseEntry gRaceEasyHeldItemEntries[18] = {{UseItemByRankAfterHeld, 1, 0xf, 0x34}, {UseItemByRankAfterHeld, 1, 0xf, 0x34}, {UseItemByRankAfterHeld, 2, 0xf, 0x34}, {UseItemByRankAfterHeld, 2, 0xf, 0x34}, {UseItemAfterHeldIfTurnUnder20, 0, 0x0, 0xa}, {UseItemIfTurnUnder20ResetHeldTimer, 0, 0x5, 0xa}, {UseItemByRankAfterHeld, 2, 0xf, 0x34}, {UseItemAfterHeld, 0, 0xf, 0xa}, {UseItemAfterHeld, 0, 0xf, 0xa}, {TrailOrCircleUseItemAfterHeld, 1, 0xf, 0xa}, {TrailOrCircleUseItemAfterHeld, 1, 0xf, 0xa}, {TrailOrCircleUseItemAfterHeld, 1, 0xf, 0xa}, {UseItemAfterHeld, 0, 0x0, 0xa}, {UseItemIfTurnUnder20ResetHeldTimer, 0, 0x0, 0xa}, {UseItemAfterHeld, 0, 0xf, 0xa}, {UseItemAfterHeld, 0, 0xf, 0xa}, {UseItemAfterHeld, 0, 0xf, 0xa}, {UseItemAfterHeld, 0, 0xf, 0xa}};
const CharacterAnimationRow gCharacterNsbcaStems[4] = {{0, "drive", 0}, {1, "spin", 1}, {2, "win", 1}, {3, "lose", 1}};
s32 data_usa_021658bc = 2;
s32 gMinKartDistanceSquared = -1;
const s32 gFinishResultByRank[28] = {0x20000, 0, 0, 0, 0x10000, 2, 0, 0, 0, 0x20001, 0, 0, 0, 0x10001, 2, 0, 0, 0x10000, 0x20001, 0, 0, 0x10000, 0x20001, 2, 0, 0x10000, 0x10001, 0x20002};
char gCharacterNsbcaPathBuffer[256];

char *BuildCharacterNsbcaPath(u16 characterIndex, s32 animationIndex) {
    char *dirPath = BuildCharacterDirPath(characterIndex);
    const char *pName = LookupCharacterPOrEName(characterIndex, 1);

    snprintf(gCharacterNsbcaPathBuffer, 0x100, "%s%s_%s.nsbca", dirPath, pName,
             gCharacterNsbcaStems[animationIndex].mStem);
    return gCharacterNsbcaPathBuffer;
}

// Returns 0 for the driving animation and 1 for the other three (the ones that loop).
u32 GetCharacterAnimationLoopFlag(int animationIndex) {
    return gCharacterNsbcaStems[animationIndex].mLoopFlag;
}

void ClearCharacterTurnAndNextAnimation(struct KartModelsEntry *kartModelsEntry) {
    CharacterAnimationState *animationState;

    kartModelsEntry->mAnimationState.mTurnFrameOffset = 0;
    animationState = &kartModelsEntry->mAnimationState;
    animationState->mNextAnimationPending = FALSE;
    animationState->mNextAnimationIndex = 0;
}

// Steps the turn offset of the driving animation, or the playing animation and its hand-over to the next one.
void AdvanceKartCharacterAnimation(Kart *kart) {
    s32 turnFrameStep;
    KartModelsEntry *modelsEntry;
    CharacterAnimationState *animationState;
    ModelAnimation *characterAnimation;
    s32 turnFrameLimit;
    u32 bits48;
    ModelAnimation *faceAnimation;

    modelsEntry = kart->mKartModelsEntry;
    animationState = &modelsEntry->mAnimationState;
    characterAnimation = modelsEntry->mCharacterAnimation;
    turnFrameLimit = animationState->mMiddleFrame;
    turnFrameStep = (kart->mMotionFlags & KART_MOTION_DRIFTING) != 0 ? 0x2000 : 0x1000;
    bits48 = kart->mDriveFlags;
    if ((bits48 & KART_DRIVE_TURN_LEFT) != 0) {
        if (gRaceSetup->mRaceKind != RACE_KIND_STAFF_ROLL) {
            animationState->mTurnFrameOffset += turnFrameStep;
            if (animationState->mTurnFrameOffset > turnFrameLimit) {
                animationState->mTurnFrameOffset = turnFrameLimit;
            }
        }
    } else if ((bits48 & KART_DRIVE_TURN_RIGHT) != 0) {
        if (gRaceSetup->mRaceKind != RACE_KIND_STAFF_ROLL) {
            turnFrameLimit *= -1;
            animationState->mTurnFrameOffset -= turnFrameStep;
            if (animationState->mTurnFrameOffset < turnFrameLimit) {
                animationState->mTurnFrameOffset = turnFrameLimit;
            }
        }
    } else if (animationState->mTurnFrameOffset != 0) {
        if (animationState->mTurnFrameOffset > 0) {
            animationState->mTurnFrameOffset -= turnFrameStep;
            if (animationState->mTurnFrameOffset < 0) {
                animationState->mTurnFrameOffset = 0;
            }
        } else {
            animationState->mTurnFrameOffset += turnFrameStep;
            if (animationState->mTurnFrameOffset > 0) {
                animationState->mTurnFrameOffset = 0;
            }
        }
    }
    if (characterAnimation->mCurrentIndex != 0) {
        AdvanceModelAnimation(characterAnimation);
        if (animationState->mNextAnimationPending == FALSE) {
            return;
        }
        if (characterAnimation->mHead.mDone != 1) {
            return;
        }
        SetModelAnimationEntryLoopMode(characterAnimation, characterAnimation->mCurrentIndex, 1);
        StartModelAnimationBlend(modelsEntry->mCharacterAnimation, animationState->mNextAnimationIndex);
        faceAnimation = modelsEntry->mFaceAnimation;
        faceAnimation->mHead.mFrameIndex = gCharacterFaceFrames[0];
        faceAnimation->mAnmObjs[faceAnimation->mCurrentIndex]->mFrame = faceAnimation->mHead.mFrameIndex;
        animationState->mNextAnimationPending = FALSE;
    } else {
        characterAnimation->mHead.mFrameIndex = animationState->mTurnFrameOffset + animationState->mMiddleFrame;
        AdvanceModelAnimationBlend(characterAnimation);
    }
}

void SetCharacterFaceFrameIndex(struct KartModelsEntry *kartModelsEntry, s32 faceFrameIndex) {
    ModelAnimation *faceAnimation = kartModelsEntry->mFaceAnimation;

    faceAnimation->mHead.mFrameIndex = gCharacterFaceFrames[faceFrameIndex];
    faceAnimation->mAnmObjs[faceAnimation->mCurrentIndex]->mFrame = faceAnimation->mHead.mFrameIndex;
}

void SetCharacterAnimation(struct KartModelsEntry *kartModelsEntry, s32 animationIndex, s32 useBlend) {
    if (useBlend != 0) {
        StartModelAnimationBlend(kartModelsEntry->mCharacterAnimation, animationIndex);
    } else {
        SetModelAnimation(kartModelsEntry->mCharacterAnimation, (u16) animationIndex);
    }
}

static inline s32 KartAnimationGetCurrentTeamIndex(u32 entryIndex) {
    return *(vs32 *) &gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mTeamIndex;
}

// Starts the win or lose animation of a kart that has finished, from the race result; nothing for the middle results.
void StartKartWinOrLoseAnimation(Kart *kart) {
    u32 finishResult;
    u16 value;
    s32 isRuleKindWinner;
    s32 mode;
    BOOL flag;
    s32 normalizedResult;
    CharacterAnimationState *animationState;
    RandomState64 *localRandom;
    u32 bits7c;

    flag = TRUE;
    finishResult = flag;
    isRuleKindWinner = 0;
    value = gRaceSetup->mKartCount;

    bits7c = kart->mEntryFlags;
    if ((bits7c & KART_ENTRY_HAS_CHARACTER_ANIMATION) == 0) {
        return;
    }
    mode = gRaceSetup->mMode;
    if (mode == MODE_BATTLE) {
        return;
    }
    if (mode == MODE_MISSION_RUN) {
        return;
    }
    if (mode != MODE_BATTLE && gRaceSetup->mRuleKind == 1) {
        value = gRaceProgress->mKartAtRank[0];
        if (gRaceSetup->mUseTeams != 0) {
            if (KartAnimationGetCurrentTeamIndex(value) != KartAnimationGetCurrentTeamIndex(kart->mIndex)) {
                finishResult = 2;
            } else {
                finishResult = 0;
                kart->mEntryFlags |= KART_ENTRY_WINNER;
                isRuleKindWinner = flag;
            }
        } else if (kart->mIndex != value) {
            finishResult = 2;
        } else {
            finishResult = 0;
            kart->mEntryFlags |= KART_ENTRY_WINNER;
            isRuleKindWinner = flag;
        }
    } else if (mode == MODE_TIME_ATTACK) {
        if ((bits7c & KART_ENTRY_GHOST) == 0) {
            if (IsRaceNewRecordTaFinishRecord() != 0 || IsRaceNewRecordTaBestLapRecord() != 0) {
                finishResult = 0;
            } else {
                finishResult = 2;
            }
        }
    } else if (value > 1) {
        finishResult = ((s16 *) &gFinishResultByRank[(value - 2) * 4])[GetKartRank(kart->mIndex) - 1];
    }
    if (finishResult == 0) {
        KartModelsEntry *modelsEntry = kart->mKartModelsEntry;
        animationState = &modelsEntry->mAnimationState;
        SetModelAnimationEntryLoopMode(modelsEntry->mCharacterAnimation, (u16) finishResult, 1);
        SetKartCharacterAnimation(kart, 2, 1);
        if (isRuleKindWinner != 0) {
            kart->mEntryFlags |= KART_ENTRY_RESULT_WON;
        } else {
            animationState->mAnimationChangeTimerSet = TRUE;
            localRandom = &gRaceProgress->mLocalRandom;
            localRandom->mValue = localRandom->mMultiplier * localRandom->mValue + localRandom->mIncrement;
            animationState->mAnimationChangeTimer = (u32) (((localRandom->mValue >> 32) * 200) >> 32);
            animationState->mAnimationChangeTimer += 0x96;
        }
    } else if (finishResult == 2) {
        kart->mEntryFlags |= KART_ENTRY_RESULT_LOST;
        SetKartCharacterAnimation(kart, 3, 1);
    }
    if ((kart->mEntryFlags & KART_ENTRY_SELECTED) != 0) {
        normalizedResult = 1;
        if (finishResult != 0) {
            if (finishResult == 2) {
                normalizedResult = 2;
            }
        } else {
            normalizedResult = 0;
        }
        SetEntryKartFinishResult(normalizedResult);
    }
}

void AdvanceKartAnimationChangeTimer(Kart *kart) {
    CharacterAnimationState *animationState = &kart->mKartModelsEntry->mAnimationState;
    RandomState64 *localRandom;
    KartModelsEntry *modelsEntry;

    if (animationState->mAnimationChangeTimerSet == FALSE) {
        return;
    }
    animationState->mAnimationChangeTimer--;
    if (animationState->mAnimationChangeTimer > 0) {
        return;
    }
    modelsEntry = kart->mKartModelsEntry;
    if ((kart->mEntryFlags & KART_ENTRY_HIDDEN) != 0 || modelsEntry->mCharacterAnimation->mCurrentIndex == 2) {
        SetKartCharacterAnimation(kart, 0, 1);
    } else if (modelsEntry->mCharacterAnimation->mCurrentIndex == 0) {
        SetKartCharacterAnimation(kart, 2, 1);
    }
    localRandom = &gRaceProgress->mLocalRandom;
    localRandom->mValue = localRandom->mMultiplier * localRandom->mValue + localRandom->mIncrement;
    animationState->mAnimationChangeTimer = (u32) (((localRandom->mValue >> 32) * 200) >> 32);
    animationState->mAnimationChangeTimer += 0x96;
}

void StartKartStarModels(Kart *kart) {
    KartModelsEntry *modelsEntry = kart->mKartModelsEntry;
    Nsbmd *firstModel = modelsEntry->mModels[0];
    ModelAnimation *faceAnimation = modelsEntry->mFaceAnimation;
    NNSG3dResMdl *resMdl = firstModel->mResMdl;

    NNS_G3dMdlSetMdlPolygonModeAll(resMdl, 2);
    NNS_G3dReleaseMdlTex(resMdl);
    if (faceAnimation != NULL && modelsEntry->mFaceAnimationRemoved == FALSE) {
        NNS_G3dRenderObjRemoveAnmObj(&firstModel->mRenderObj, faceAnimation->mAnmObjs[0]);
        modelsEntry->mFaceAnimationRemoved = TRUE;
    }
    SetKartModelMaterialColors(resMdl, 2);
    resMdl = modelsEntry->mModels[1]->mResMdl;
    NNS_G3dMdlSetMdlPolygonModeAll(resMdl, 2);
    NNS_G3dReleaseMdlTex(resMdl);
    SetKartModelMaterialColors(resMdl, 2);
    if (modelsEntry->mModels[2] != NULL) {
        resMdl = modelsEntry->mModels[2]->mResMdl;
        NNS_G3dMdlSetMdlPolygonModeAll(resMdl, 2);
        NNS_G3dReleaseMdlTex(resMdl);
        SetKartModelMaterialColors(resMdl, 2);
    }
    modelsEntry->mStarModelsSet = TRUE;
}

void StopKartStarModels(Kart *kart) {
    KartModelsEntry *modelsEntry = kart->mKartModelsEntry;
    Nsbmd *firstModel = modelsEntry->mModels[0];
    ModelAnimation *faceAnimation = modelsEntry->mFaceAnimation;
    NNSG3dResMdl *resMdl = firstModel->mResMdl;
    Nsbmd *secondModel;
    NNSG3dResMdl *thirdResMdl;
    Nsbmd *thirdModel;

    NNS_G3dMdlSetMdlPolygonModeAll(resMdl, 0);
    NNS_G3dBindMdlTex(resMdl, firstModel->mResFileEntry.mTexture);
    if (faceAnimation != NULL && modelsEntry->mFaceAnimationRemoved != FALSE) {
        NNS_G3dRenderObjAddAnmObj(&firstModel->mRenderObj, faceAnimation->mAnmObjs[0]);
        modelsEntry->mFaceAnimationRemoved = FALSE;
    }
    SetKartModelMaterialColors(resMdl, 0);
    secondModel = modelsEntry->mModels[1];
    resMdl = secondModel->mResMdl;
    NNS_G3dMdlSetMdlPolygonModeAll(resMdl, 0);
    NNS_G3dBindMdlTex(resMdl, secondModel->mResFileEntry.mTexture);
    SetKartModelMaterialColors(resMdl, 0);
    thirdModel = modelsEntry->mModels[2];
    if (thirdModel != NULL) {
        thirdResMdl = thirdModel->mResMdl;
        NNS_G3dMdlSetMdlPolygonModeAll(thirdResMdl, 0);
        NNS_G3dBindMdlTex(thirdResMdl, thirdModel->mResFileEntry.mTexture);
        SetKartModelMaterialColors(thirdResMdl, 0);
    }
    modelsEntry->mStarModelsSet = FALSE;
}

void SetKartModelsGrayColors(Kart *kart) {
    KartModelsEntry *modelsEntry = kart->mKartModelsEntry;
    NNSG3dResMdl *resMdl;

    if (modelsEntry->mStarModelsSet != FALSE) {
        return;
    }
    resMdl = modelsEntry->mModels[0]->mResMdl;
    NNS_G3dMdlSetMdlPolygonModeAll(resMdl, 2);
    SetKartModelMaterialColors(resMdl, 3);
    resMdl = modelsEntry->mModels[1]->mResMdl;
    NNS_G3dMdlSetMdlPolygonModeAll(resMdl, 2);
    SetKartModelMaterialColors(resMdl, 3);
}

void ResetKartModelsCourseColors(Kart *kart) {
    KartModelsEntry *modelsEntry = kart->mKartModelsEntry;
    NNSG3dResMdl *resMdl;

    if (modelsEntry->mStarModelsSet != FALSE) {
        return;
    }
    resMdl = modelsEntry->mModels[0]->mResMdl;
    NNS_G3dMdlSetMdlPolygonModeAll(resMdl, 0);
    SetKartModelMaterialColors(resMdl, 0);
    resMdl = modelsEntry->mModels[1]->mResMdl;
    NNS_G3dMdlSetMdlPolygonModeAll(resMdl, 0);
    SetKartModelMaterialColors(resMdl, 0);
}

// Plays animation a once, then goes on to animation b.
void StartKartCharacterAnimationOnce(Kart *kart, s32 animationIndex, s32 nextAnimationIndex) {
    KartModelsEntry *modelsEntry = kart->mKartModelsEntry;
    ModelAnimation *characterAnimation;
    CharacterAnimationState *animationState = &modelsEntry->mAnimationState;

    characterAnimation = modelsEntry->mCharacterAnimation;
    if (animationState->mNextAnimationPending != FALSE && characterAnimation->mCurrentIndex != 0) {
        SetModelAnimationEntryLoopMode(characterAnimation, characterAnimation->mCurrentIndex, 1);
    }
    animationState->mNextAnimationPending = TRUE;
    animationState->mNextAnimationIndex = nextAnimationIndex;
    StartModelAnimationBlend(kart->mKartModelsEntry->mCharacterAnimation, animationIndex);
    SetModelAnimationEntryLoopMode(characterAnimation, (u16) animationIndex, 0);
}

void InitShadowModelFromResMdl(ShadowModel *shadowModel, void *resFile, u32 polygonId) {
    NNSG3dResMdl *resMdl;

    InitNsbmdRenderObjWrapper(&shadowModel->mNsbmd, resFile);
    resMdl = shadowModel->mNsbmd.mResMdl;
    shadowModel->mPolygonId = polygonId;
    shadowModel->mAlpha = 0xd;
    shadowModel->mFlags |= 1;
    NNS_G3dMdlSetMdlPolygonMode(resMdl, 0, 3);
    NNS_G3dMdlSetMdlLightEnableFlag(resMdl, 0, 0);
}

NNSG3dResMdl *InitShadowModel(ShadowModel *shadowModel, NNSG3dResFileHeader *resFileHeader, u32 polygonId) {
    NNSG3dResMdl *resMdl;

    InitNsbmd(&shadowModel->mNsbmd, resFileHeader);
    resMdl = shadowModel->mNsbmd.mResMdl;
    shadowModel->mPolygonId = polygonId;
    shadowModel->mAlpha = 0xd;
    shadowModel->mFlags |= 1;
    NNS_G3dMdlSetMdlPolygonMode(resMdl, 0, 3);
    NNS_G3dMdlSetMdlLightEnableFlag(resMdl, 0, 0);
    return shadowModel->mNsbmd.mResMdl;
}

// Draws the shadow with matrix b; when c is not NULL its three words are sent after the matrix.
void DrawShadowWithMatrix(ShadowModel *shadowModel, const void *matrix, Vec3 *extraVector) {
    s32 value;
    Vec3 copiedVector;

    if ((shadowModel->mFlags & 1) == 0) {
        return;
    }
    value = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &value, 1);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    if (extraVector != NULL) {
        s32 vectorZ = extraVector->z;
        s32 vectorY = extraVector->y;
        s32 vectorX = extraVector->x;
        copiedVector.x = vectorX;
        copiedVector.y = vectorY;
        copiedVector.z = vectorZ;
        NNS_G3dGeBufferOP_N(0x1b, &copiedVector, 3);
    }
    SetNsbmdFirstDrawMaterial(&shadowModel->mNsbmd, shadowModel->mAlpha);
    gNsbmdDrawFunctions[shadowModel->mNsbmd.mDrawKind](shadowModel);
    SetNsbmdSecondDrawMaterial(&shadowModel->mNsbmd, shadowModel->mAlpha, shadowModel->mPolygonId);
    gNsbmdDrawFunctions[shadowModel->mNsbmd.mDrawKind](shadowModel);
}

void DrawShadowWithoutMatrix(ShadowModel *shadowModel) {
    if ((shadowModel->mFlags & 1) == 0) {
        return;
    }
    SetNsbmdFirstDrawMaterial(&shadowModel->mNsbmd, shadowModel->mAlpha);
    gNsbmdDrawFunctions[shadowModel->mNsbmd.mDrawKind](shadowModel);
    SetNsbmdSecondDrawMaterial(&shadowModel->mNsbmd, shadowModel->mAlpha, shadowModel->mPolygonId);
    gNsbmdDrawFunctions[shadowModel->mNsbmd.mDrawKind](shadowModel);
}
