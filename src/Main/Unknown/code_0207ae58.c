#include "Main/Unknown/code_0207ae58.h"
#include "Main/Item/ItemInUse.h"
#include "Main/Unknown/code_0207a14c.h"
#include "Main/Unknown/code_02087cfc.h"
#include "Main/Unknown/code_02087d0c.h"
#include "Main/Kart/KartResourcePaths.h"
#include "ITCM/code_01ff8000.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_020c70ec.h"
#include "Main/Unknown/code_021112fc.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0200fe74.h"
#include "code_020109c4.h"
#include "code_02012b30.h"
#include "code_02134398.h"
#include "Main/Unknown/code_020681f0.h"

char *GetCharacterNsbcaPath(u16 characterIndex, s32 animationIndex) {
    char *dirPath = cklcr_getCharacterFolderPath(characterIndex);
    const char *pName = cklcr_getCharacterModelName(characterIndex, 1);

    snprintf(aCharacterMarioP_mr_lose_nsbca, 0x100, aSS_S_nsbca, dirPath, pName,
             gCharacterNsbcaStems[animationIndex].mUnk_00);
    return aCharacterMarioP_mr_lose_nsbca;
}

// Returns 0 for the driving animation and 1 for the other three (the ones that loop).
u32 GetCharacterAnimationLoopFlag(int animationIndex) {
    return gCharacterAnimationLoopFlags[animationIndex].mUnk_00;
}

void ClearCharacterTurnAndNextAnimation(struct KartModelsEntry *kartModelsEntry) {
    CharacterAnimationState *animationState;

    kartModelsEntry->mTurnFrameOffset = 0;
    animationState = (CharacterAnimationState *) &kartModelsEntry->mTurnFrameOffset;
    animationState->mNextAnimationPending = FALSE;
    animationState->mNextAnimationIndex = 0;
}

// Steps the turn offset of the driving animation, or the playing animation and its hand-over to the next one.
void AdvanceKartCharacterAnimation(Kart *kart) {
    s32 turnFrameStep;
    KartModelsEntry *modelsEntry;
    CharacterAnimationState *animationState;
    KartModelAnimationView *characterAnimation;
    s32 turnFrameLimit;
    u32 bits48;
    KartModelAnimationView *faceAnimation;

    modelsEntry = kart->mKartModelsEntry;
    animationState = (CharacterAnimationState *) &modelsEntry->mTurnFrameOffset;
    characterAnimation = modelsEntry->mCharacterAnimation;
    turnFrameLimit = animationState->mMiddleFrame;
    turnFrameStep = (kart->mUnk_44 & KART_44_DRIFTING) != 0 ? 0x2000 : 0x1000;
    bits48 = kart->mUnk_48;
    if ((bits48 & KART_48_TURN_LEFT) != 0) {
        if (gRaceMultiConfig->mRaceKind != RACE_KIND_STAFF_ROLL) {
            animationState->mTurnFrameOffset += turnFrameStep;
            if (animationState->mTurnFrameOffset > turnFrameLimit) {
                animationState->mTurnFrameOffset = turnFrameLimit;
            }
        }
    } else if ((bits48 & KART_48_TURN_RIGHT) != 0) {
        if (gRaceMultiConfig->mRaceKind != RACE_KIND_STAFF_ROLL) {
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
    if (characterAnimation->mUnk_1a != 0) {
        anim_update(characterAnimation);
        if (animationState->mNextAnimationPending == FALSE) {
            return;
        }
        if (characterAnimation->mUnk_02 != 1) {
            return;
        }
        anim_setLoop(characterAnimation, characterAnimation->mUnk_1a, 1);
        anim_setAnimWithBlend(modelsEntry->mCharacterAnimation, animationState->mNextAnimationIndex);
        faceAnimation = modelsEntry->mFaceAnimation;
        faceAnimation->mUnk_0c = gCharacterFaceFrames[0];
        *faceAnimation->mUnk_1c[faceAnimation->mUnk_1a] = faceAnimation->mUnk_0c;
        animationState->mNextAnimationPending = FALSE;
    } else {
        characterAnimation->mUnk_0c = animationState->mTurnFrameOffset + animationState->mMiddleFrame;
        anim_updateBlend((ModelAnimation *) characterAnimation);
    }
}

void driver_setFaceExpression(struct KartModelsEntry *kartModelsEntry, s32 faceFrameIndex) {
    KartModelAnimationView *faceAnimation = kartModelsEntry->mFaceAnimation;

    faceAnimation->mUnk_0c = gCharacterFaceFrames[faceFrameIndex];
    *faceAnimation->mUnk_1c[faceAnimation->mUnk_1a] = faceAnimation->mUnk_0c;
}

void driver_setAnim(struct KartModelsEntry *kartModelsEntry, s32 animationIndex, s32 useBlend) {
    if (useBlend != 0) {
        anim_setAnimWithBlend(kartModelsEntry->mCharacterAnimation, animationIndex);
    } else {
        anim_setAnim(kartModelsEntry->mCharacterAnimation, (u16) animationIndex);
    }
}

static inline s32 func_0207b44c_inline(u32 entryIndex) {
    return *(vs32 *) &gRaceMultiConfig->mCurrentEntries[entryIndex].mPlayer.mTeamIndex;
}

// Starts the win or lose animation of a kart that has finished, from the race result; nothing for the middle results.
void StartKartWinOrLoseAnimation(Kart *kart) {
    u32 finishResult;
    u16 b;
    s32 isRuleKindWinner;
    s32 mode;
    BOOL c;
    s32 normalizedResult;
    CharacterAnimationState *animationState;
    RandomState64 *localRandom;
    u32 bits7c;

    c = TRUE;
    finishResult = c;
    isRuleKindWinner = 0;
    b = gRaceMultiConfig->mKartCount;

    bits7c = kart->mUnk_7c;
    if ((bits7c & 0x10) == 0) {
        return;
    }
    mode = gRaceMultiConfig->mMode;
    if (mode == MODE_BATTLE) {
        return;
    }
    if (mode == MODE_MISSION_RUN) {
        return;
    }
    if (mode != MODE_BATTLE && gRaceMultiConfig->mRuleKind == 1) {
        b = gRaceStatus->mKartAtRank[0];
        if (gRaceMultiConfig->mUseTeams != 0) {
            if (func_0207b44c_inline(b) != func_0207b44c_inline(kart->mIndex)) {
                finishResult = 2;
            } else {
                finishResult = 0;
                kart->mUnk_7c |= 0x2000000;
                isRuleKindWinner = c;
            }
        } else if (kart->mIndex != b) {
            finishResult = 2;
        } else {
            finishResult = 0;
            kart->mUnk_7c |= 0x2000000;
            isRuleKindWinner = c;
        }
    } else if (mode == MODE_TIME_ATTACK) {
        if ((bits7c & 4) == 0) {
            if (IsRaceNewRecordTaFinishRecord() != 0 || IsRaceNewRecordTaBestLapRecord() != 0) {
                finishResult = 0;
            } else {
                finishResult = 2;
            }
        }
    } else if (b > 1) {
        finishResult = ((s16 *) &gFinishResultByRank[(b - 2) * 4])[rstat_getPlace(kart->mIndex) - 1];
    }
    if (finishResult == 0) {
        KartModelsEntry *modelsEntry = kart->mKartModelsEntry;
        animationState = (CharacterAnimationState *) &modelsEntry->mTurnFrameOffset;
        anim_setLoop(modelsEntry->mCharacterAnimation, (u16) finishResult, 1);
        driver_2068A64(kart, 2, 1);
        if (isRuleKindWinner != 0) {
            kart->mUnk_7c |= 0x10000;
        } else {
            animationState->mAnimationChangeTimerSet = TRUE;
            localRandom = &gRaceStatus->mLocalRandom;
            localRandom->mValue = localRandom->mMultiplier * localRandom->mValue + localRandom->mIncrement;
            animationState->mAnimationChangeTimer = (u32) (((localRandom->mValue >> 32) * 200) >> 32);
            animationState->mAnimationChangeTimer += 0x96;
        }
    } else if (finishResult == 2) {
        kart->mUnk_7c |= 0x20000;
        driver_2068A64(kart, 3, 1);
    }
    if ((kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0) {
        normalizedResult = 1;
        if (finishResult != 0) {
            if (finishResult == 2) {
                normalizedResult = 2;
            }
        } else {
            normalizedResult = 0;
        }
        func_021112fc(normalizedResult);
    }
}

void AdvanceKartAnimationChangeTimer(Kart *kart) {
    CharacterAnimationState *animationState = (CharacterAnimationState *) &kart->mKartModelsEntry->mTurnFrameOffset;
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
    if ((kart->mUnk_7c & 0x40) != 0 || modelsEntry->mCharacterAnimation->mUnk_1a == 2) {
        driver_2068A64(kart, 0, 1);
    } else if (modelsEntry->mCharacterAnimation->mUnk_1a == 0) {
        driver_2068A64(kart, 2, 1);
    }
    localRandom = &gRaceStatus->mLocalRandom;
    localRandom->mValue = localRandom->mMultiplier * localRandom->mValue + localRandom->mIncrement;
    animationState->mAnimationChangeTimer = (u32) (((localRandom->mValue >> 32) * 200) >> 32);
    animationState->mAnimationChangeTimer += 0x96;
}

void driver_enableStarToonMode(Kart *kart) {
    KartModelsEntry *modelsEntry = kart->mKartModelsEntry;
    Nsbmd *firstModel = modelsEntry->mModels[0];
    KartModelAnimationView *faceAnimation = modelsEntry->mFaceAnimation;
    NNSG3dResMdl *resMdl = firstModel->mResMdl;

    NNS_G3dMdlSetMdlPolygonModeAll(resMdl, 2);
    NNS_G3dReleaseMdlTex(resMdl);
    if (faceAnimation != NULL && modelsEntry->mFaceAnimationRemoved == FALSE) {
        NNS_G3dRenderObjRemoveAnmObj((NNSG3dRenderObj *) firstModel, (NNSG3dAnmObj *) faceAnimation->mUnk_1c[0]);
        modelsEntry->mFaceAnimationRemoved = TRUE;
    }
    ConfigureFullNSBMDColors(resMdl, 2);
    resMdl = modelsEntry->mModels[1]->mResMdl;
    NNS_G3dMdlSetMdlPolygonModeAll(resMdl, 2);
    NNS_G3dReleaseMdlTex(resMdl);
    ConfigureFullNSBMDColors(resMdl, 2);
    if (modelsEntry->mModels[2] != NULL) {
        resMdl = modelsEntry->mModels[2]->mResMdl;
        NNS_G3dMdlSetMdlPolygonModeAll(resMdl, 2);
        NNS_G3dReleaseMdlTex(resMdl);
        ConfigureFullNSBMDColors(resMdl, 2);
    }
    modelsEntry->mStarModelsSet = TRUE;
}

void driver_disableStarToonMode(Kart *kart) {
    KartModelsEntry *modelsEntry = kart->mKartModelsEntry;
    Nsbmd *firstModel = modelsEntry->mModels[0];
    KartModelAnimationView *faceAnimation = modelsEntry->mFaceAnimation;
    NNSG3dResMdl *resMdl = firstModel->mResMdl;
    Nsbmd *secondModel;
    NNSG3dResMdl *thirdResMdl;
    Nsbmd *thirdModel;

    NNS_G3dMdlSetMdlPolygonModeAll(resMdl, 0);
    NNS_G3dBindMdlTex(resMdl, firstModel->mResFileEntry.mTexture);
    if (faceAnimation != NULL && modelsEntry->mFaceAnimationRemoved != FALSE) {
        NNS_G3dRenderObjAddAnmObj((NNSG3dRenderObj *) firstModel, (NNSG3dAnmObj *) faceAnimation->mUnk_1c[0]);
        modelsEntry->mFaceAnimationRemoved = FALSE;
    }
    ConfigureFullNSBMDColors(resMdl, 0);
    secondModel = modelsEntry->mModels[1];
    resMdl = secondModel->mResMdl;
    NNS_G3dMdlSetMdlPolygonModeAll(resMdl, 0);
    NNS_G3dBindMdlTex(resMdl, secondModel->mResFileEntry.mTexture);
    ConfigureFullNSBMDColors(resMdl, 0);
    thirdModel = modelsEntry->mModels[2];
    if (thirdModel != NULL) {
        thirdResMdl = thirdModel->mResMdl;
        NNS_G3dMdlSetMdlPolygonModeAll(thirdResMdl, 0);
        NNS_G3dBindMdlTex(thirdResMdl, thirdModel->mResFileEntry.mTexture);
        ConfigureFullNSBMDColors(thirdResMdl, 0);
    }
    modelsEntry->mStarModelsSet = FALSE;
}

void driver_enableSlipStreamToonMode(Kart *kart) {
    KartModelsEntry *modelsEntry = kart->mKartModelsEntry;
    NNSG3dResMdl *resMdl;

    if (modelsEntry->mStarModelsSet != FALSE) {
        return;
    }
    resMdl = modelsEntry->mModels[0]->mResMdl;
    NNS_G3dMdlSetMdlPolygonModeAll(resMdl, 2);
    ConfigureFullNSBMDColors(resMdl, 3);
    resMdl = modelsEntry->mModels[1]->mResMdl;
    NNS_G3dMdlSetMdlPolygonModeAll(resMdl, 2);
    ConfigureFullNSBMDColors(resMdl, 3);
}

void driver_disableSlipStreamToonMode(Kart *kart) {
    KartModelsEntry *modelsEntry = kart->mKartModelsEntry;
    NNSG3dResMdl *resMdl;

    if (modelsEntry->mStarModelsSet != FALSE) {
        return;
    }
    resMdl = modelsEntry->mModels[0]->mResMdl;
    NNS_G3dMdlSetMdlPolygonModeAll(resMdl, 0);
    ConfigureFullNSBMDColors(resMdl, 0);
    resMdl = modelsEntry->mModels[1]->mResMdl;
    NNS_G3dMdlSetMdlPolygonModeAll(resMdl, 0);
    ConfigureFullNSBMDColors(resMdl, 0);
}

// Plays animation a once, then goes on to animation b.
void driver_setAnimation(Kart *kart, s32 animationIndex, s32 nextAnimationIndex) {
    KartModelsEntry *modelsEntry = kart->mKartModelsEntry;
    KartModelAnimationView *characterAnimation;
    CharacterAnimationState *animationState = (CharacterAnimationState *) &modelsEntry->mTurnFrameOffset;

    characterAnimation = modelsEntry->mCharacterAnimation;
    if (animationState->mNextAnimationPending != FALSE && characterAnimation->mUnk_1a != 0) {
        anim_setLoop(characterAnimation, characterAnimation->mUnk_1a, 1);
    }
    animationState->mNextAnimationPending = TRUE;
    animationState->mNextAnimationIndex = nextAnimationIndex;
    anim_setAnimWithBlend(kart->mKartModelsEntry->mCharacterAnimation, animationIndex);
    anim_setLoop(characterAnimation, (u16) animationIndex, 0);
}

void InitShadowModelFromResMdl(Nsbmd *nsbmd, void *resFile, u32 polygonId) {
    ShadowModel *shadowModel = (ShadowModel *) nsbmd;
    NNSG3dResMdl *resMdl;

    model_initFromResMdl(nsbmd, resFile);
    resMdl = nsbmd->mResMdl;
    shadowModel->mPolygonId = polygonId;
    shadowModel->mAlpha = 0xd;
    shadowModel->mFlags |= 1;
    NNS_G3dMdlSetMdlPolygonMode(resMdl, 0, 3);
    NNS_G3dMdlSetMdlLightEnableFlag(resMdl, 0, 0);
}

NNSG3dResMdl *InitShadowModel(void *model, NNSG3dResFileHeader *resFileHeader, u32 polygonId) {
    ShadowModel *shadowModel = model;
    NNSG3dResMdl *resMdl;

    model_initFromNsbmd(shadowModel, resFileHeader);
    resMdl = shadowModel->mNsbmd.mResMdl;
    shadowModel->mPolygonId = polygonId;
    shadowModel->mAlpha = 0xd;
    shadowModel->mFlags |= 1;
    NNS_G3dMdlSetMdlPolygonMode(resMdl, 0, 3);
    NNS_G3dMdlSetMdlLightEnableFlag(resMdl, 0, 0);
    return shadowModel->mNsbmd.mResMdl;
}

// Draws the shadow with matrix b; when c is not NULL its three words are sent after the matrix.
void DrawShadowWithMatrix(void *model, const void *matrix, Vec3 *extraVector) {
    ShadowModel *shadowModel = model;
    s32 v;
    Vec3 copiedVector;

    if ((shadowModel->mFlags & 1) == 0) {
        return;
    }
    v = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &v, 1);
    NNS_G3dGeBufferOP_N(0x19, matrix, 0xc);
    if (extraVector != NULL) {
        s32 z = extraVector->z;
        s32 y = extraVector->y;
        s32 x = extraVector->x;
        copiedVector.x = x;
        copiedVector.y = y;
        copiedVector.z = z;
        NNS_G3dGeBufferOP_N(0x1b, &copiedVector, 3);
    }
    model_configShadowPass1(shadowModel, shadowModel->mAlpha);
    gModelRenderFuncs[shadowModel->mNsbmd.mDrawKind](shadowModel);
    model_configShadowPass2(shadowModel, shadowModel->mAlpha, shadowModel->mPolygonId);
    gModelRenderFuncs[shadowModel->mNsbmd.mDrawKind](shadowModel);
}

void driver_renderShadow(ShadowModel *shadowModel) {
    if ((shadowModel->mFlags & 1) == 0) {
        return;
    }
    model_configShadowPass1(shadowModel, shadowModel->mAlpha);
    gModelRenderFuncs[shadowModel->mNsbmd.mDrawKind](shadowModel);
    model_configShadowPass2(shadowModel, shadowModel->mAlpha, shadowModel->mPolygonId);
    gModelRenderFuncs[shadowModel->mNsbmd.mDrawKind](shadowModel);
}
