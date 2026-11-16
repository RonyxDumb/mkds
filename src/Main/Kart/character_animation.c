#include "Main/Kart/character_animation.h"
#include "Main/Item/item_in_use.h"
#include "model_draw_state.h"
#include "Main/Kart/karts.h"
#include "Main/Graphics/model_animation_loop_mode.h"
#include "Main/Graphics/model_animation.h"
#include "Main/Kart/kart_model_path.h"
#include "ITCM/model_draw_and_irq_handler.h"
#include "Main/Race/race_clock.h"
#include "Main/Race/race_hud_sub_screen_item_box_cells.h"
#include "Main/Sound/seq_row.h"
#include "Main/Kart/kart_palette_stem_tables.h"
#include "Main/Kart/kart_effect_param_tables.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "model_texture_bind.h"
#include "render_object_callback_link.h"
#include "model_material_set.h"
#include "print_memory_multibyte_write.h"
#include "Main/Kart/kart_participant_record.h"
#include "Main/Kart/kart_ai_item_use.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Graphics/nsbmd_draw.h"
#include "Main/System/init_after_startup.h"
#include "Main/Menu/menu_screens_work.h"

const s32 gCharacterFaceFrames[2] = {0, 0x1000};
const KartAiItemUseEntry gRaceItemInUseEntries[14] = {{UseItemAfterInUseByCircleKind, 1, 0x5, 0x10},
                                                      {UseItemAfterInUseByCircleKind, 1, 0x8, 0x5},
                                                      {UseItemAfterInUseByTrailKind, 2, 0x1, 0x14},
                                                      {RaceItemInUseNop, 0, 0x3, 0xa},
                                                      {RaceItemInUseNop, 0, 0x3, 0xa},
                                                      {RaceItemInUseNop, 0, 0x3, 0xa},
                                                      {RaceItemInUseNop, 0, 0x3, 0xa},
                                                      {RaceItemInUseNop, 2, 0x3, 0xa},
                                                      {RaceItemInUseNop, 2, 0x3, 0xa},
                                                      {UseItemAfterInUseByTrailKind, 1, 0x1, 0x14},
                                                      {RaceItemInUseNop, 2, 0x3, 0xa},
                                                      {RaceItemInUseNop, 2, 0x3, 0xa},
                                                      {RaceItemInUseNop, 2, 0x3, 0xa},
                                                      {RaceItemInUseNop, 2, 0x3, 0xa}};
const KartAiItemUseEntry gRaceNormalHeldItemEntries[18] = {{UseItemByRankOrEveryCall, 1, 0x0, 0x34},
                                                           {UseItemByRankAfterHeld, 1, 0x0, 0x34},
                                                           {UseItemByRankOrEveryCall, 2, 0x0, 0x34},
                                                           {UseItemByRankAfterHeld, 2, 0x0, 0x34},
                                                           {UseItemAfterHeldIfTurnUnder20, 0, 0x0, 0xa},
                                                           {UseItemIfTurnUnder20ResetHeldTimer, 0, 0x5, 0xa},
                                                           {UseItemByRankAfterHeld, 2, 0x0, 0x34},
                                                           {UseItemAfterHeld, 0, 0x0, 0xa},
                                                           {UseItemAfterHeld, 0, 0x0, 0xa},
                                                           {TrailOrCircleUseItemAfterHeld, 1, 0x0, 0xa},
                                                           {TrailOrCircleUseItemAfterHeld, 1, 0x0, 0xa},
                                                           {TrailOrCircleUseItemAfterHeld, 1, 0x0, 0xa},
                                                           {UseItemAfterHeld, 0, 0x0, 0xa},
                                                           {UseItemIfTurnUnder20ResetHeldTimer, 0, 0x0, 0xa},
                                                           {UseItemAfterHeld, 0, 0x0, 0xa},
                                                           {UseItemAfterHeld, 0, 0x0, 0xa},
                                                           {UseItemAfterHeld, 0, 0x0, 0xa},
                                                           {UseItemAfterHeld, 0, 0x0, 0xa}};
const KartAiItemUseEntry gRaceHardHeldItemEntries[18] = {{UseItemByTargetOrRankOrEveryCall, 1, 0x0, 0x34},
                                                         {UseItemByTargetOrRankAfterHeld, 1, 0x0, 0x34},
                                                         {UseItemByTargetOrRankOrEveryCall, 2, 0x0, 0x34},
                                                         {UseItemByTargetOrRankAfterHeld, 2, 0x0, 0x34},
                                                         {UseItemAfterHeldIfTurnUnder20, 0, 0x0, 0xa},
                                                         {UseItemIfTurnUnder20ResetHeldTimer, 0, 0x5, 0xa},
                                                         {UseItemByTargetOrRankAfterHeld, 2, 0x0, 0x34},
                                                         {UseItemAfterHeld, 0, 0x0, 0xa},
                                                         {UseItemAfterHeld, 0, 0x0, 0xa},
                                                         {TrailOrCircleUseItemAfterHeld, 1, 0x0, 0xa},
                                                         {TrailOrCircleUseItemAfterHeld, 1, 0x0, 0xa},
                                                         {TrailOrCircleUseItemAfterHeld, 1, 0x0, 0xa},
                                                         {UseItemAfterHeld, 0, 0x0, 0xa},
                                                         {UseItemIfTurnUnder20ResetHeldTimer, 0, 0x0, 0xa},
                                                         {UseItemAfterHeld, 0, 0x0, 0xa},
                                                         {UseItemAfterHeld, 0, 0x0, 0xa},
                                                         {UseItemAfterHeld, 0, 0x0, 0xa},
                                                         {UseItemAfterHeld, 0, 0x0, 0xa}};
const KartAiItemUseEntry gRaceEasyHeldItemEntries[18] = {{UseItemByRankAfterHeld, 1, 0xf, 0x34},
                                                         {UseItemByRankAfterHeld, 1, 0xf, 0x34},
                                                         {UseItemByRankAfterHeld, 2, 0xf, 0x34},
                                                         {UseItemByRankAfterHeld, 2, 0xf, 0x34},
                                                         {UseItemAfterHeldIfTurnUnder20, 0, 0x0, 0xa},
                                                         {UseItemIfTurnUnder20ResetHeldTimer, 0, 0x5, 0xa},
                                                         {UseItemByRankAfterHeld, 2, 0xf, 0x34},
                                                         {UseItemAfterHeld, 0, 0xf, 0xa},
                                                         {UseItemAfterHeld, 0, 0xf, 0xa},
                                                         {TrailOrCircleUseItemAfterHeld, 1, 0xf, 0xa},
                                                         {TrailOrCircleUseItemAfterHeld, 1, 0xf, 0xa},
                                                         {TrailOrCircleUseItemAfterHeld, 1, 0xf, 0xa},
                                                         {UseItemAfterHeld, 0, 0x0, 0xa},
                                                         {UseItemIfTurnUnder20ResetHeldTimer, 0, 0x0, 0xa},
                                                         {UseItemAfterHeld, 0, 0xf, 0xa},
                                                         {UseItemAfterHeld, 0, 0xf, 0xa},
                                                         {UseItemAfterHeld, 0, 0xf, 0xa},
                                                         {UseItemAfterHeld, 0, 0xf, 0xa}};
const CharacterAnimationRow gCharacterNsbcaStems[4] = {{0, "drive", 0}, {1, "spin", 1}, {2, "win", 1}, {3, "lose", 1}};
s32 gNearPlayerRankKartCount = 2;
s32 gMinKartDistanceSquared = -1;
const s16 gFinishResultByRank[7][8] = {{0, 2, 0, 0, 0, 0, 0, 0}, {0, 1, 2, 0, 0, 0, 0, 0}, {0, 0, 1, 2, 0, 0, 0, 0},
                                       {0, 0, 1, 1, 2, 0, 0, 0}, {0, 0, 0, 1, 1, 2, 0, 0}, {0, 0, 0, 1, 1, 2, 2, 0},
                                       {0, 0, 0, 1, 1, 1, 2, 2}};
char g_SomeNsbcaFormatBuffer[256];

char *FormatCharacterEmblemNsbcaPath(u16 characterIndex, s32 animationIndex) {
    char *dirPath = FormatCharacterPath(characterIndex);
    const char *pName = FormatCharacterEmblemName(characterIndex, 1);

    _snprintf(g_SomeNsbcaFormatBuffer, 0x100, "%s%s_%s.nsbca", dirPath, pName,
             gCharacterNsbcaStems[animationIndex].mStem);
    return g_SomeNsbcaFormatBuffer;
}

// Returns 0 for the driving animation and 1 for the other three (the ones that loop).
u32 GetRacerAnimationIndex(int animationIndex) {
    return gCharacterNsbcaStems[animationIndex].mLoopFlag;
}

void StructAD00Sub_SomeFn_2(struct KartModelsEntry *kartModelsEntry) {
    CharacterAnimationState *animationState;

    kartModelsEntry->mAnimationState.mTurnFrameOffset = 0;
    animationState = &kartModelsEntry->mAnimationState;
    animationState->mNextAnimationPending = FALSE;
    animationState->mNextAnimationIndex = 0;
}

// Steps the turn offset of the driving animation, or the playing animation and its hand-over to the next one.
void StructMQRacerEntry_SomeFn_20(Kart *kart) {
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
        if (g_GlobalCO->mRaceKind != RACE_KIND_STAFF_ROLL) {
            animationState->mTurnFrameOffset += turnFrameStep;
            if (animationState->mTurnFrameOffset > turnFrameLimit) {
                animationState->mTurnFrameOffset = turnFrameLimit;
            }
        }
    } else if ((bits48 & KART_DRIVE_TURN_RIGHT) != 0) {
        if (g_GlobalCO->mRaceKind != RACE_KIND_STAFF_ROLL) {
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
        StructAM_SomeFn_MaybeMoveNextFrame(characterAnimation);
        if (animationState->mNextAnimationPending == FALSE) {
            return;
        }
        if (characterAnimation->mHead.mDone != 1) {
            return;
        }
        StructAM_SetSomeValueAt(characterAnimation, characterAnimation->mCurrentIndex, 1);
        StructAM_SomeFn_MaybeForceLoadBlock(modelsEntry->mCharacterAnimation, animationState->mNextAnimationIndex);
        faceAnimation = modelsEntry->mFaceAnimation;
        faceAnimation->mHead.mFrameIndex = gCharacterFaceFrames[0];
        faceAnimation->mAnmObjs[faceAnimation->mCurrentIndex]->mFrame = faceAnimation->mHead.mFrameIndex;
        animationState->mNextAnimationPending = FALSE;
    } else {
        characterAnimation->mHead.mFrameIndex = animationState->mTurnFrameOffset + animationState->mMiddleFrame;
        StructAM_SomeFn_5(characterAnimation);
    }
}

void StructAD00Sub_SomeFn_1(struct KartModelsEntry *kartModelsEntry, s32 faceFrameIndex) {
    ModelAnimation *faceAnimation = kartModelsEntry->mFaceAnimation;

    faceAnimation->mHead.mFrameIndex = gCharacterFaceFrames[faceFrameIndex];
    faceAnimation->mAnmObjs[faceAnimation->mCurrentIndex]->mFrame = faceAnimation->mHead.mFrameIndex;
}

void StructAD00Sub_SomeFn_0(struct KartModelsEntry *kartModelsEntry, s32 animationIndex, s32 useBlend) {
    if (useBlend != 0) {
        StructAM_SomeFn_MaybeForceLoadBlock(kartModelsEntry->mCharacterAnimation, animationIndex);
    } else {
        StructAM_SomeFn_MaybeLoadFrame(kartModelsEntry->mCharacterAnimation, (u16) animationIndex);
    }
}

static inline s32 KartAnimationGetCurrentTeamIndex(u32 entryIndex) {
    return *(vs32 *) &g_GlobalCO->mCurrentEntries[entryIndex].mPlayer.mTeamIndex;
}

// Starts the win or lose animation of a kart that has finished, from the race result; nothing for the middle results.
void StructMQRacerEntry_SomeFn_37(Kart *kart) {
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
    value = g_GlobalCO->mKartCount;

    bits7c = kart->mEntryFlags;
    if ((bits7c & KART_ENTRY_HAS_CHARACTER_ANIMATION) == 0) {
        return;
    }
    mode = g_GlobalCO->mMode;
    if (mode == MODE_BATTLE) {
        return;
    }
    if (mode == MODE_MISSION_RUN) {
        return;
    }
    if (mode != MODE_BATTLE && g_GlobalCO->mRuleKind == RULE_KIND_WIN_COUNT) {
        value = g_GlobalMV->mKartAtRank[0];
        if (g_GlobalCO->mUseTeams != 0) {
            if (KartAnimationGetCurrentTeamIndex(value) != KartAnimationGetCurrentTeamIndex(kart->mIndex)) {
                finishResult = FINISH_RESULT_LOST;
            } else {
                finishResult = FINISH_RESULT_WON;
                kart->mEntryFlags |= KART_ENTRY_WINNER;
                isRuleKindWinner = flag;
            }
        } else if (kart->mIndex != value) {
            finishResult = FINISH_RESULT_LOST;
        } else {
            finishResult = FINISH_RESULT_WON;
            kart->mEntryFlags |= KART_ENTRY_WINNER;
            isRuleKindWinner = flag;
        }
    } else if (mode == MODE_TIME_ATTACK) {
        if ((bits7c & KART_ENTRY_GHOST) == 0) {
            if (IsRaceNewRecordTaFinishRecord() != 0 || GetLastTimeTrialWasRecord() != 0) {
                finishResult = FINISH_RESULT_WON;
            } else {
                finishResult = FINISH_RESULT_LOST;
            }
        }
    } else if (value > 1) {
        finishResult = gFinishResultByRank[value - 2][GetSomeRacerFlags(kart->mIndex) - 1];
    }
    if (finishResult == FINISH_RESULT_WON) {
        KartModelsEntry *modelsEntry = kart->mKartModelsEntry;
        animationState = &modelsEntry->mAnimationState;
        StructAM_SetSomeValueAt(modelsEntry->mCharacterAnimation, (u16) finishResult, 1);
        StructMQRacerEntry_SomeFn_32(kart, KART_CHARACTER_ANIMATION_ALTERNATE, 1);
        if (isRuleKindWinner != 0) {
            kart->mEntryFlags |= KART_ENTRY_RESULT_WON;
        } else {
            animationState->mAnimationChangeTimerSet = TRUE;
            localRandom = &g_GlobalMV->mLocalRandom;
            localRandom->mValue = localRandom->mMultiplier * localRandom->mValue + localRandom->mIncrement;
            animationState->mAnimationChangeTimer = (u32) (((localRandom->mValue >> 32) * 200) >> 32);
            animationState->mAnimationChangeTimer += 0x96;
        }
    } else if (finishResult == FINISH_RESULT_LOST) {
        kart->mEntryFlags |= KART_ENTRY_RESULT_LOST;
        StructMQRacerEntry_SomeFn_32(kart, KART_CHARACTER_ANIMATION_LOST, 1);
    }
    if ((kart->mEntryFlags & KART_ENTRY_SELECTED) != 0) {
        normalizedResult = FINISH_RESULT_NEITHER;
        if (finishResult != FINISH_RESULT_WON) {
            if (finishResult == FINISH_RESULT_LOST) {
                normalizedResult = FINISH_RESULT_LOST;
            }
        } else {
            normalizedResult = FINISH_RESULT_WON;
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
    if ((kart->mEntryFlags & KART_ENTRY_HIDDEN) != 0 ||
        modelsEntry->mCharacterAnimation->mCurrentIndex == KART_CHARACTER_ANIMATION_ALTERNATE) {
        StructMQRacerEntry_SomeFn_32(kart, 0, 1);
    } else if (modelsEntry->mCharacterAnimation->mCurrentIndex == 0) {
        StructMQRacerEntry_SomeFn_32(kart, KART_CHARACTER_ANIMATION_ALTERNATE, 1);
    }
    localRandom = &g_GlobalMV->mLocalRandom;
    localRandom->mValue = localRandom->mMultiplier * localRandom->mValue + localRandom->mIncrement;
    animationState->mAnimationChangeTimer = (u32) (((localRandom->mValue >> 32) * 200) >> 32);
    animationState->mAnimationChangeTimer += 0x96;
}

void StructMQRacerEntry_SomeFn_67(Kart *kart) {
    KartModelsEntry *modelsEntry = kart->mKartModelsEntry;
    Nsbmd *firstModel = modelsEntry->mModels[0];
    ModelAnimation *faceAnimation = modelsEntry->mFaceAnimation;
    NNSG3dResMdl *resMdl = firstModel->mResMdl;

    ModelBlock_SomeMatFn_4(resMdl, 2);
    ModelBlock_SomeTexPltFn_9(resMdl);
    if (faceAnimation != NULL && modelsEntry->mFaceAnimationRemoved == FALSE) {
        StructML_SomeFn_2(&firstModel->mRenderObj, faceAnimation->mAnmObjs[0]);
        modelsEntry->mFaceAnimationRemoved = TRUE;
    }
    ModelBlock_SomeMatFn(resMdl, KART_MODEL_COLORS_DARK);
    resMdl = modelsEntry->mModels[1]->mResMdl;
    ModelBlock_SomeMatFn_4(resMdl, 2);
    ModelBlock_SomeTexPltFn_9(resMdl);
    ModelBlock_SomeMatFn(resMdl, KART_MODEL_COLORS_DARK);
    if (modelsEntry->mModels[2] != NULL) {
        resMdl = modelsEntry->mModels[2]->mResMdl;
        ModelBlock_SomeMatFn_4(resMdl, 2);
        ModelBlock_SomeTexPltFn_9(resMdl);
        ModelBlock_SomeMatFn(resMdl, KART_MODEL_COLORS_DARK);
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

    ModelBlock_SomeMatFn_4(resMdl, 0);
    ModelBlock_SomeTexPltFn_10(resMdl, firstModel->mResFileEntry.mTexture);
    if (faceAnimation != NULL && modelsEntry->mFaceAnimationRemoved != FALSE) {
        StructML_SomeFn_3(&firstModel->mRenderObj, faceAnimation->mAnmObjs[0]);
        modelsEntry->mFaceAnimationRemoved = FALSE;
    }
    ModelBlock_SomeMatFn(resMdl, 0);
    secondModel = modelsEntry->mModels[1];
    resMdl = secondModel->mResMdl;
    ModelBlock_SomeMatFn_4(resMdl, 0);
    ModelBlock_SomeTexPltFn_10(resMdl, secondModel->mResFileEntry.mTexture);
    ModelBlock_SomeMatFn(resMdl, 0);
    thirdModel = modelsEntry->mModels[2];
    if (thirdModel != NULL) {
        thirdResMdl = thirdModel->mResMdl;
        ModelBlock_SomeMatFn_4(thirdResMdl, 0);
        ModelBlock_SomeTexPltFn_10(thirdResMdl, thirdModel->mResFileEntry.mTexture);
        ModelBlock_SomeMatFn(thirdResMdl, 0);
    }
    modelsEntry->mStarModelsSet = FALSE;
}

void StructMQRacerEntry_SomeFn_36(Kart *kart) {
    KartModelsEntry *modelsEntry = kart->mKartModelsEntry;
    NNSG3dResMdl *resMdl;

    if (modelsEntry->mStarModelsSet != FALSE) {
        return;
    }
    resMdl = modelsEntry->mModels[0]->mResMdl;
    ModelBlock_SomeMatFn_4(resMdl, 2);
    ModelBlock_SomeMatFn(resMdl, 3);
    resMdl = modelsEntry->mModels[1]->mResMdl;
    ModelBlock_SomeMatFn_4(resMdl, 2);
    ModelBlock_SomeMatFn(resMdl, 3);
}

void StructMQRacerEntry_SomeFn_2(Kart *kart) {
    KartModelsEntry *modelsEntry = kart->mKartModelsEntry;
    NNSG3dResMdl *resMdl;

    if (modelsEntry->mStarModelsSet != FALSE) {
        return;
    }
    resMdl = modelsEntry->mModels[0]->mResMdl;
    ModelBlock_SomeMatFn_4(resMdl, 0);
    ModelBlock_SomeMatFn(resMdl, 0);
    resMdl = modelsEntry->mModels[1]->mResMdl;
    ModelBlock_SomeMatFn_4(resMdl, 0);
    ModelBlock_SomeMatFn(resMdl, 0);
}

// Plays animation a once, then goes on to animation b.
void StructMQRacerEntry_SomeFn_7(Kart *kart, s32 animationIndex, s32 nextAnimationIndex) {
    KartModelsEntry *modelsEntry = kart->mKartModelsEntry;
    ModelAnimation *characterAnimation;
    CharacterAnimationState *animationState = &modelsEntry->mAnimationState;

    characterAnimation = modelsEntry->mCharacterAnimation;
    if (animationState->mNextAnimationPending != FALSE && characterAnimation->mCurrentIndex != 0) {
        StructAM_SetSomeValueAt(characterAnimation, characterAnimation->mCurrentIndex, 1);
    }
    animationState->mNextAnimationPending = TRUE;
    animationState->mNextAnimationIndex = nextAnimationIndex;
    StructAM_SomeFn_MaybeForceLoadBlock(kart->mKartModelsEntry->mCharacterAnimation, animationIndex);
    StructAM_SetSomeValueAt(characterAnimation, (u16) animationIndex, 0);
}

void StructAD00Sh_SomeFn(ShadowModel *shadowModel, void *resFile, u32 polygonId) {
    NNSG3dResMdl *resMdl;

    StructML_SomeFn(&shadowModel->mNsbmd, resFile);
    resMdl = shadowModel->mNsbmd.mResMdl;
    shadowModel->mPolygonId = polygonId;
    shadowModel->mAlpha = KART_SHADOW_ALPHA;
    shadowModel->mFlags |= 1;
    ModelBlock_SomeTexPltFn_8(resMdl, 0, 3);
    NNS_G3dMdlSetMdlLightEnableFlag(resMdl, 0, 0);
}

NNSG3dResMdl *StructAD00Sh_SomeFn_2(ShadowModel *shadowModel, NNSG3dResFileHeader *resFileHeader, u32 polygonId) {
    NNSG3dResMdl *resMdl;

    StructML_LoadModel2(&shadowModel->mNsbmd, resFileHeader);
    resMdl = shadowModel->mNsbmd.mResMdl;
    shadowModel->mPolygonId = polygonId;
    shadowModel->mAlpha = KART_SHADOW_ALPHA;
    shadowModel->mFlags |= 1;
    ModelBlock_SomeTexPltFn_8(resMdl, 0, 3);
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
