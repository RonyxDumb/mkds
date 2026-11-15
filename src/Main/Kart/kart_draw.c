#include "Main/Kart/kart_draw.h"
#include "ITCM/g3d_draw_and_irq_handler.h"
#include "Main/Kart/karts.h"
#include "Main/Item/item_in_use.h"
#include "model_draw_blend.h"
#include "Main/Kart/shadow_model_draw.h"
#include "Main/Kart/kart_contact_effect_release.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/Graphics/light_color.h"
#include "Main/Sound/start_sound_from_params.h"
#include "fx_mtx33.h"
#include "vector_math.h"

void SetKartSoundDistanceSquaredAndChange(Kart *kart) {
    kart->mSoundSource.mDistanceSquared = GetKartCameraDistanceSquared(kart->mIndex);
    AdvanceSoundDistanceSquaredChange(&kart->mSoundDistanceSquaredChange, GetKartCameraDistanceSquared(kart->mIndex));
}

static inline void SendGxCommandOneValue(u32 command, s32 value) {
    NNS_G3dGeBufferOP_N(command, &value, 1);
}

static inline void SendGxCommandThreeValues(u32 command, s32 valueX, s32 valueY, s32 valueZ) {
    Vec3 vector;

    vector.x = valueX;
    vector.y = valueY;
    vector.z = valueZ;
    NNS_G3dGeBufferOP_N(command, &vector, 3);
}

static inline void ShiftVec3RightByFour(Vec3 *destination, const Vec3 *source) {
    destination->x = source->x >> 4;
    destination->y = source->y >> 4;
    destination->z = source->z >> 4;
}

void DrawKart(Kart *kart) {
    u32 hasKartFlag;
    u32 kartFlags;
    u32 kartStatus;
    KartModelsEntry *modelsEntry;
    KartTireTranslations *tireTranslations;
    s32 killerItemShown;
    s32 tireScale;
    MtxFx33 spinMatrix;
    MtxFx33 rotationMatrix;
    Vec3 translation;

    kartFlags = kart->mEffectFlags;
    hasKartFlag = (kartFlags & KART_EFFECT_TUMBLING) != 0;
    kartStatus = kart->mEntryFlags;
    modelsEntry = kart->mKartModelsEntry;
    if ((kartStatus & (KART_ENTRY_HIDDEN | KART_ENTRY_NOT_DRAWN | KART_ENTRY_NOT_DRAWN_PARKED)) != 0 ||
        (kartFlags & (KART_EFFECT_KILLER | KART_EFFECT_OUT_OF_VIEW | KART_EFFECT_BLINK_HIDDEN)) != 0) {
        killerItemShown = 0;
        if ((kartStatus & (KART_ENTRY_HIDDEN | KART_ENTRY_NOT_DRAWN | KART_ENTRY_NOT_DRAWN_PARKED)) == 0 &&
            (kartFlags & (KART_EFFECT_OUT_OF_VIEW | KART_EFFECT_BLINK_HIDDEN)) == 0) {
            killerItemShown = DrawKartKillerItem(kart);
        }
        SetKartKillerEffectShown(kart->mIndex, killerItemShown);
        kart->mVisible = 0;
        return;
    }
    if ((kartStatus & (KART_ENTRY_GHOST | KART_ENTRY_TRANSLUCENT | KART_ENTRY_PARKED)) != 0) {
        kart->mVisible = ~kart->mVisible;
        if (kart->mVisible == 0) {
            return;
        }
    } else {
        kart->mVisible = KART_VISIBLE_ALL;
    }
    SendGxCommandOneValue(0x14, 0x1e);
    if (hasKartFlag != 0) {
        ShiftVec3RightByFour(&kart->mRotationRow3, kart->mPosSource);
        NNS_G3dGeBufferOP_N(0x19, &kart->mRotationRow0, 0xc);
        NNS_G3dGeBufferOP_N(0x1b, &kart->mScale, 3);
        SendGxCommandThreeValues(0x1b, kart->mModelScaleX, kart->mModelScaleY, kart->mModelScaleZ);
        DrawShadowWithoutMatrix(modelsEntry->mShadowModel);
        SendGxCommandOneValue(0x14, 0x1e);
    }
    NNS_G3dGeBufferOP_N(0x19, kart->mDrawMatrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &kart->mScale, 3);
    SendGxCommandOneValue(0x13, 0x1d);
    SendGxCommandThreeValues(0x1b, kart->mModelScaleX, kart->mModelScaleY, kart->mModelScaleZ);
    if (hasKartFlag == 0) {
        DrawShadowWithoutMatrix(modelsEntry->mShadowModel);
    }
    SendLight01Color(&modelsEntry->mCourseColorBlend.mColor);
    if (modelsEntry->mKartModelHidden == 0) {
        SetKartModelTireAlpha(modelsEntry, modelsEntry->mFarFromCamera == FALSE);
        SendGxCommandOneValue(0x13, 0x1c);
        SendGxCommandThreeValues(0x1b, kart->mOffsetCycleAmount.x, kart->mOffsetCycleAmount.y, 0x1000);
        DrawNsbmd(modelsEntry->mModels[1]);
        if (modelsEntry->mModels[2] != NULL) {
            tireTranslations = kart->mKartModelsEntry->mTireTranslations;
            tireScale = kart->mKartModelsEntry->mKartOffsetData->mFirstTiresScale;
            SendGxCommandOneValue(0x14, 0x1c);
            NNS_G3dGeBufferOP_N(0x1c, &tireTranslations->mThirdTireX, 3);
            MTX_RotX33_(&spinMatrix, SIN_OF_ANGLE(kart->mTireSpinAngle), COS_OF_ANGLE(kart->mTireSpinAngle));
            NNS_G3dGeBufferOP_N(0x1a, &spinMatrix, 9);
            DrawNsbmd(modelsEntry->mModels[2]);
            if (tireTranslations->mThirdTireX != 0) {
                SendGxCommandThreeValues(0x1c, tireTranslations->mFourthTireX, 0, 0);
                DrawNsbmd(modelsEntry->mModels[2]);
            }
            SendGxCommandOneValue(0x14, 0x1c);
            NNS_G3dGeBufferOP_N(0x1c, tireTranslations, 3);
            SendGxCommandThreeValues(0x1b, tireScale, tireScale, tireScale);
            NNS_G3dGeBufferOP_N(0x11, NULL, 0);
            MTX_RotY33_(&rotationMatrix, SIN_OF_ANGLE(kart->mTireTurnAngle), COS_OF_ANGLE(kart->mTireTurnAngle));
            NNS_G3dGeBufferOP_N(0x1a, &rotationMatrix, 9);
            NNS_G3dGeBufferOP_N(0x1a, &spinMatrix, 9);
            DrawNsbmd(modelsEntry->mModels[2]);
            if (tireTranslations->mFirstTireX != 0) {
                SendGxCommandOneValue(0x12, 1);
                SendGxCommandThreeValues(0x1c, tireTranslations->mSecondTireX, 0, 0);
                NNS_G3dGeBufferOP_N(0x1a, &rotationMatrix, 9);
                NNS_G3dGeBufferOP_N(0x1a, &spinMatrix, 9);
                DrawNsbmd(modelsEntry->mModels[2]);
            }
        }
    }
    if (modelsEntry->mCharacterHidden != 0) {
        return;
    }
    translation = modelsEntry->mKartOffsetData->mCharacterOffsets[modelsEntry->mCharacterIndex];
    translation.y = translation.y + (kart->mModelOffsetY + kart->mOffsetCycleAmount.z);
    SendGxCommandOneValue(0x14, 0x1d);
    NNS_G3dGeBufferOP_N(0x1c, &translation, 3);
    DrawNsbmd(modelsEntry->mModels[0]);
}

BOOL DrawKartKillerItem(Kart *kart) {
    KartModelsEntry *modelsEntry;
    ModelAnimation *killerItemNsbca;
    BOOL drawn;
    s32 frame;
    s32 commandValue;
    s32 offsetScale;
    s32 radiusFactor;
    Vec3 position;
    Vec3 scale;
    MtxFx43 matrix;

    modelsEntry = kart->mKartModelsEntry;
    drawn = modelsEntry->mKartModelHidden == 0;
    if (drawn != FALSE) {
        offsetScale = kart->mRadius + 0x5000;
        matrix = *kart->mDrawMatrix;
        VEC_MultAdd(offsetScale, &kart->mRotationRow1, kart->mPosSource, &position);
        matrix.mRows[3].x = position.x >> 4;
        matrix.mRows[3].y = position.y >> 4;
        matrix.mRows[3].z = position.z >> 4;
        radiusFactor = kart->mRadiusFactor;
        scale.x = MUL_FIXED12_NO_ROUND(kart->mScale.x, radiusFactor);
        scale.y = MUL_FIXED12_NO_ROUND(kart->mScale.y, radiusFactor);
        scale.z = MUL_FIXED12_NO_ROUND(kart->mScale.z, radiusFactor);
        commandValue = 0x1e;
        NNS_G3dGeBufferOP_N(0x14, &commandValue, 1);
        NNS_G3dGeBufferOP_N(0x19, &matrix, 0xc);
        NNS_G3dGeBufferOP_N(0x1b, &scale, 3);
        SendLight01Color(&modelsEntry->mCourseColorBlend.mColor);
        SetKillerItemKartIndex(kart->mIndex);
        frame = kart->mKartModelsEntry->mKillerItemAnimation.mFrameIndex;
        killerItemNsbca = GetKillerItemNsbca();
        killerItemNsbca->mHead.mFrameIndex = frame;
        killerItemNsbca->mAnmObjs[killerItemNsbca->mCurrentIndex]->mFrame = killerItemNsbca->mHead.mFrameIndex;
        DrawNsbmd(GetKillerItem());
        DrawShadowWithoutMatrix(GetKillerItemS());
    }
    return drawn;
}
