#include "Main/Kart/kart_call.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Race/race.h"
#include "Main/Kart/karts.h"
#include "Main/Kart/kart_effects.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "model_material_set.h"
#include "model_draw_state.h"
#include "animation_lookup.h"
#include "matrix_3x3_basic.h"
#include "matrix_4x3_basic.h"
#include "fixed_vector_math.h"

const Vec3 gCourseModelDrawScale = {0x1000, 0x1000, 0x1000};
const u32 g_str_KillerItem[4] = {0x6c6c694b, 0x74497265, 0x6d65, 0};

// Copies row 1 of the matrix at 0x120 (mRotationMatrix), the kart's up direction, to the out vector. The camera takes
// it as its up while KART_DRIVE_BOOST_SURFACE_HELD is set in mDriveFlags and the world up (0, 0x1000, 0) otherwise; the
// steering code removes this component from vectors. The kart has two more matrices (0x150 and 0x184), built from this
// one for drawing.
void StructMQRacerEntry_GetVec555(const Kart *kart, Vec3 *upDirection) {
    const MtxFx43 *matrix;

    matrix = &kart->mRotationMatrix;
    upDirection->x = matrix->mRows[1].x;
    upDirection->y = matrix->mRows[1].y;
    upDirection->z = matrix->mRows[1].z;
}

// Copies row 2 of the matrix at 0x120 (mRotationMatrix), the kart's forward direction, to the out vector. The camera
// follows it, and its mSavedKartForward holds a copy taken when the camera is set up. The kart has two more matrices
// (0x150 and 0x184), built from this one for drawing.
void GetMQRacerVector333(const Kart *kart, Vec3 *forward) {
    const MtxFx43 *matrix;

    matrix = &kart->mRotationMatrix;
    forward->x = matrix->mRows[2].x;
    forward->y = matrix->mRows[2].y;
    forward->z = matrix->mRows[2].z;
}

void RespawnKartAndToggleEventFlag(Kart *kart) {
    if ((kart->mEntryFlags & KART_ENTRY_WIFI_PEER) != 0) {
        return;
    }
    kart->mSlotFunctions[6](kart);
    if ((kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) != 0) {
        kart->mParticipantRecordData->mEventToggleFlags ^= KART_EVENT_RESPAWN;
    }
}

void KartAiRespawnKartAndToggleEventFlag(Kart *kart) {
    u32 flagBits;

    flagBits = kart->mEntryFlags & KART_ENTRY_WIFI_PEER;
    if (flagBits != 0) {
        return;
    }
    if (flagBits == 0) {
        kart->mSlotFunctions[6](kart);
        if ((kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) != 0) {
            kart->mParticipantRecordData->mEventToggleFlags ^= KART_EVENT_RESPAWN;
        }
    }
    if (g_GlobalCO->mMode == MODE_BATTLE) {
        kart->mDriveFlags &= ~KART_DRIVE_OBJECTS_SKIP;
    }
}

void StructMLFnPtr(NNSG3dRS *renderState) {
    u32 killerItemKartIndex;
    MtxFx33 rotationMatrix;
    MtxFx43 positionMatrix;
    Vec3 effectPosition;
    Vec3 offset;
    MtxFx43 inverseViewMatrix;
    s32 offsetScale;
    MtxFx43 *currentViewMatrix;
    Kart *kart;
    s32 killerItemDictIndex;

    killerItemKartIndex = GetKillerItemKartIndex();
    killerItemDictIndex = Dict_SomeFn_0(&renderState->mRenderObj->mResMdl->mNodeInfo, g_str_KillerItem);
    if (killerItemDictIndex !=
        ((renderState->mFlag & NNS_G3D_RSFLAG_CURRENT_NODEDESC_VALID) != 0 ? renderState->mCurrentNodeDesc : -1)) {
        return;
    }
    currentViewMatrix = GetCurrentViewMatrix();
    NNS_G3dGetCurrentMtx(&positionMatrix, &rotationMatrix);
    MTX_Inverse43(currentViewMatrix, &inverseViewMatrix);
    MTX_Concat43(&positionMatrix, &inverseViewMatrix, &positionMatrix);
    MTX_Concat33(&rotationMatrix, &inverseViewMatrix.mAxes, &rotationMatrix);
    effectPosition = positionMatrix.mRows[3];
    offset = rotationMatrix.mRows[2];
    kart = GetRacerMQEntry(killerItemKartIndex);
    offsetScale = MUL_FIXED12_ROUNDED(kart->mRadiusFactor, -0xd000) >> 4;
    offset.x = MUL_FIXED12_NO_ROUND(offset.x, offsetScale);
    offset.y = MUL_FIXED12_NO_ROUND(offset.y, offsetScale);
    offset.z = MUL_FIXED12_NO_ROUND(offset.z, offsetScale);
    VecFx32_Add(&effectPosition, &offset, &effectPosition);
    PlaceKartKillerEffect(killerItemKartIndex, &effectPosition);
    renderState->mCbVecFunc[6] = NULL;
    renderState->mCbVecTiming[6] = 0;
}
