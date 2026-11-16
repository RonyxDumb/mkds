#include "Main/Unknown/code_02086058.h"

#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_02147288.h"
#include "code_02147cd8.h"
#include "g3imm.h"
#include "Main/Unknown/code_0203c598.h"
#include "Main/Unknown/code_02086e8c.h"
#include "Main/Unknown/code_02087934.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_020738f4.h"
#include "Main/Unknown/code_020d50e0.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/code_0210cf9c.h"
#include "Main/Item/ItemInUse.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02087918.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_02077bc0.h"
#include "code_021471bc.h"
#include "registers.h"

void func_02086a04(void) {
    Vec3 cameraToKartWhole;
    Vec3 cameraToKart;
    s32 i;
    ViewFrustum *viewFrustum;
    KartModelsEntry *modelsEntry;
    s32 margin;
    u32 distanceSquared;
    Kart *kart;
    BOOL isBeyondPlanes;
    s32 distanceAlongView;
    s32 marginWhole;
    BOOL isWithinFalloff;
    BOOL isSourceEnabled;
    u16 objectCount;
    s32 orderIndex;
    viewFrustum = GetViewFrustum();
    for (i = 0; i < gRaceMultiConfig->mKartCount; i++) {
        driver_getById(i);
        data_0217aed0->mNameTagBeyondTwoNearest[i] = 0;
        kart = driver_getById(i);
        margin = kart->mRadius * 3;
        modelsEntry = kart->mKartModelsEntry;
        VEC_Subtract(kart->mPosSource, &viewFrustum->mCameraPos, &cameraToKart);
        distanceAlongView = VEC_DotProduct(&cameraToKart, &viewFrustum->mViewDirection);
        data_0217aed0->mDistanceAlongViewWithMargin[i] = distanceAlongView + margin;
        data_0217aed0->mAlongViewOrderIndex[kart->mIndex] =
            data_0217aed0->field24[kart->mIndex] + data_0217aed0->mAlongViewOrderOffset[kart->mIndex];
        data_0217aed0->mSortedDistanceAlongView[data_0217aed0->mAlongViewOrderIndex[kart->mIndex]] = distanceAlongView;
        VEC_Subtract(kart->mPosSource, &viewFrustum->mCameraPos, &cameraToKartWhole);
        cameraToKartWhole.x = cameraToKartWhole.x >> 12;
        cameraToKartWhole.y = cameraToKartWhole.y >> 12;
        cameraToKartWhole.z = cameraToKartWhole.z >> 12;
        distanceSquared = cameraToKartWhole.x * cameraToKartWhole.x + cameraToKartWhole.y * cameraToKartWhole.y +
                          cameraToKartWhole.z * cameraToKartWhole.z;
        data_0217aed0->mDistanceSquared[i] = distanceSquared;
        data_0217aed0->mSortedDistanceSquared[(u16) (data_0217aed0->field24[kart->mIndex] +
                                                     data_0217aed0->mDistanceSquaredOrderOffset[kart->mIndex])] =
            distanceSquared;
        if (kart->mIndex != gRaceMultiConfig->mEntryIndex) {
            isWithinFalloff = TRUE;
            if (distanceSquared > gSfxParams[0].field20) {
                isWithinFalloff = FALSE;
            }
            if (kart->mSoundSource.mSourceFlags & 1) {
                isSourceEnabled = TRUE;
            } else {
                isSourceEnabled = FALSE;
            }
            if ((isWithinFalloff != FALSE && isSourceEnabled == FALSE) ||
                (isWithinFalloff == FALSE && isSourceEnabled != FALSE)) {
                SetSoundSourceFlagBit(&kart->mSoundSource, 2, 1);
            }
            if (distanceAlongView < 0) {
                modelsEntry->field58 = modelsEntry->field5C = modelsEntry->field60 = TRUE;
                modelsEntry->mShadowModel->mFlags &= ~1;
                kart->field4C |= KART_4C_OUT_OF_VIEW;
            } else {
                isBeyondPlanes = FALSE;
                marginWhole = margin >> 12;
                if (VEC_DotProduct(&cameraToKartWhole, &viewFrustum->field20) - marginWhole > 0) {
                    isBeyondPlanes = TRUE;
                } else if (VEC_DotProduct(&cameraToKartWhole, &viewFrustum->field2C) - marginWhole > 0) {
                    isBeyondPlanes = TRUE;
                }
                if (isBeyondPlanes != FALSE) {
                    kart->field4C |= KART_4C_OUT_OF_VIEW;
                } else {
                    kart->field4C &= ~KART_4C_OUT_OF_VIEW;
                    modelsEntry->field58 = modelsEntry->field5C = modelsEntry->field60 = FALSE;
                    modelsEntry->mShadowModel->mFlags |= 1;
                    if (distanceSquared > gKartDistanceLimitsSquared->z) {
                        kart->field4C |= KART_4C_OUT_OF_VIEW;
                        modelsEntry->field58 = modelsEntry->field5C = modelsEntry->field60 = TRUE;
                        modelsEntry->mShadowModel->mFlags &= ~1;
                    } else if (distanceSquared > gKartDistanceLimitsSquared->y) {
                        modelsEntry->field58 = modelsEntry->field60 = TRUE;
                        modelsEntry->mShadowModel->mFlags &= ~1;
                    } else if (distanceSquared > gKartDistanceLimitsSquared->x) {
                        modelsEntry->field60 = TRUE;
                        modelsEntry->mShadowModel->mFlags &= ~1;
                    }
                }
            }
        }
    }
    if (race_getCameraField250() != 3) {
        objectCount = 0;
        for (orderIndex = data_0217aed0->mAlongViewOrderIndex[gRaceMultiConfig->mEntryIndex] + 1;
             orderIndex < gRaceMultiConfig->mKartCount; orderIndex++) {
            KartNameTag *kartObject;
            kartObject = data_0217aed0->mNameTagByKart[data_0217aed0->mKartIndicesByDistanceAlongView[orderIndex]];
            if (kartObject != NULL) {
                if (objectCount >= 2) {
                    data_0217aed0->mNameTagBeyondTwoNearest[kartObject->mKartIndex] = 1;
                }
                objectCount++;
            }
        }
    } else {
        objectCount = 0;
        for (orderIndex = 0; orderIndex < gRaceMultiConfig->mKartCount; orderIndex++) {
            KartNameTag *kartObject;
            kartObject = data_0217aed0->mNameTagByKart[data_0217aed0->mKartIndicesByDistanceAlongView[orderIndex]];
            if (kartObject != NULL) {
                if (data_0217aed0
                        ->mSortedDistanceAlongView[data_0217aed0->mAlongViewOrderIndex[kartObject->mKartIndex]] >= 0) {
                    if (objectCount >= 2) {
                        data_0217aed0->mNameTagBeyondTwoNearest[kartObject->mKartIndex] = 1;
                    }
                    objectCount++;
                }
            }
        }
    }
}

void func_0208677c(void) {
    Vec3 objectPosition;
    s32 i;
    s32 x;
    s32 alphaScale;
    KartNameTag *kartObject;
    Vec3 *posSource;
    Kart *kart;
    if (race_getCameraField250() == 0) {
        gKartDistanceLimitsSquared = &data_02155a3c;
    } else {
        gKartDistanceLimitsSquared = &data_02155a48;
    }
    func_02086a04();
    i = 0;
    while (i < data_0217aed0->mNameTagCount) {
        kartObject = data_0217aed0->mNameTags[i];
        kart = driver_getById(kartObject->mKartIndex);
        posSource = kart->mPosSource;
        objectPosition = *posSource;
        x = data_0217aed0->mDistanceAlongViewWithMargin[kartObject->mKartIndex];
        alphaScale = 0x1000;
        if (x > 0) {
            if (data_0217aed0->mDistanceSquared[kartObject->mKartIndex] < 0x9c400 || race_getCameraField250() == 3) {
                x -= 0x14000;
                kartObject->mFadeLevelPerCall = 1;
                kartObject->field14 = 1;
                if (x < 0) {
                    x = 0;
                }
                alphaScale = ((s64) x * 0x44 + 0x800) >> 12;
            } else {
                kartObject->mFadeLevelPerCall = -1;
                kartObject->field14 = 2;
            }
        }
        if (data_0217aed0->mNameTagBeyondTwoNearest[kartObject->mKartIndex] != 0 ||
            (driver_getById(kartObject->mKartIndex)->field7C & 0x402020) != 0 ||
            (math_abs(posSource->y - driver_getById(gRaceMultiConfig->mEntryIndex)->mPos.y) > 0x96000 &&
             race_getCameraField250() != 3)) {
            kartObject->mFadeLevelPerCall = -1;
        }
        if (kartObject->mFadeStopped != FALSE) {
            if (rstat_getFrameCounter() - 0x3c > 0) {
                kartObject->mFadeStopped = FALSE;
            }
        } else if (kartObject->mFadeLevelPerCall != 0) {
            kartObject->mFadeLevel = kartObject->mFadeLevel + kartObject->mFadeLevelPerCall;
            if (kartObject->mFadeLevel > 0x1e) {
                kartObject->mFadeLevel = 0x1e;
                kartObject->mFadeLevelPerCall = 0;
            } else if (kartObject->mFadeLevel < 0) {
                kartObject->mFadeLevel = 0;
                kartObject->mFadeLevelPerCall = 0;
            }
        }
        if (alphaScale >= 0x1000) {
            kartObject->mAlpha = kartObject->mFadeLevel;
        } else {
            kartObject->mAlpha = (s32) (((s64) kartObject->mFadeLevel * alphaScale + 0x800) >> 12);
        }
        objectPosition.y += 0xf000;
        kartObject->mPos.x = objectPosition.x >> 4;
        kartObject->mPos.y = objectPosition.y >> 4;
        kartObject->mPos.z = objectPosition.z >> 4;
        i += 1;
    }
    func_020866b4();
    func_020865ec();
}

void func_020866b4(void) {
    u16 *kartIndices;
    s16 *orderOffset;
    u16 i;
    s32 *distancesAlongView;
    s32 previousIndex;
    s32 previousDistance;
    s32 distance;
    u16 savedKartIndex;
    distancesAlongView = data_0217aed0->mSortedDistanceAlongView;
    for (i = 1; (u32) i < gRaceMultiConfig->mKartCount; i++) {
        previousIndex = i - 1;
        previousDistance = distancesAlongView[previousIndex];
        distance = distancesAlongView[i];
        if (previousDistance > distance) {
            kartIndices = data_0217aed0->mKartIndicesByDistanceAlongView;
            orderOffset = data_0217aed0->mAlongViewOrderOffset;
            distancesAlongView[previousIndex] = distance;
            distancesAlongView[i] = previousDistance;
            orderOffset[kartIndices[i]]--;
            orderOffset[kartIndices[previousIndex]]++;
            savedKartIndex = kartIndices[i];
            kartIndices[i] = kartIndices[previousIndex];
            kartIndices[previousIndex] = savedKartIndex;
        }
    }
}

void func_020865ec(void) {
    u16 *kartIndices;
    s16 *orderOffset;
    u16 i;
    u32 *distancesSquared;
    s32 previousIndex;
    u32 previousDistanceSquared;
    u32 distanceSquared;
    u16 savedKartIndex;
    distancesSquared = data_0217aed0->mSortedDistanceSquared;
    for (i = 1; (u32) i < gRaceMultiConfig->mKartCount; i++) {
        previousIndex = i - 1;
        previousDistanceSquared = distancesSquared[previousIndex];
        distanceSquared = distancesSquared[i];
        if (previousDistanceSquared > distanceSquared) {
            kartIndices = data_0217aed0->mKartIndicesByDistance;
            orderOffset = data_0217aed0->mDistanceSquaredOrderOffset;
            distancesSquared[previousIndex] = distanceSquared;
            distancesSquared[i] = previousDistanceSquared;
            orderOffset[kartIndices[i]]--;
            orderOffset[kartIndices[previousIndex]]++;
            savedKartIndex = kartIndices[i];
            kartIndices[i] = kartIndices[previousIndex];
            kartIndices[previousIndex] = savedKartIndex;
        }
    }
}

void driver_renderLabels(MtxFx43 *viewMatrix) {
    s32 i;
    s16 alpha;
    s32 screenY;
    s32 screenX;
    s32 depth;
    Vec3 viewPos;
    MtxFx43 *projectionMatrix;
    KartNameTag *kartObject;
    BOOL isProjected;
    if (race_getCameraField250() != 0 && race_getCameraField250() != 3) {
        return;
    }
    reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 8;
    reg_G3_SPE_EMI = 0x4210;
    reg_G3_DIF_AMB = 0x42100000;
    reg_G3_MTX_MODE = 0;
    G3_LoadMtx44(&PlayerLabelProjMtx);
    reg_G3_MTX_MODE = 3;
    reg_G3_MTX_IDENTITY = 0;
    for (i = gRaceMultiConfig->mKartCount - 1; i >= 0; i--) {
        kartObject = data_0217aed0->mNameTagByKart[data_0217aed0->mKartIndicesByDistanceAlongView[i]];
        if (kartObject == NULL) {
            continue;
        }
        if (data_0217aed0->mSortedDistanceAlongView[i] <= 0) {
            continue;
        }
        alpha = kartObject->mAlpha;
        if (alpha == 0) {
            continue;
        }
        if ((driver_getById(data_0217aed0->mKartIndicesByDistanceAlongView[i])->field7C & 0xe0) != 0) {
            continue;
        }
        MTX_MultVec43(&kartObject->mPos, viewMatrix, &viewPos);
        if (viewPos.z >= 0) {
            isProjected = FALSE;
        } else {
            projectionMatrix = cam_getProjectionMtx();
            screenX =
                ((s64) viewPos.x * projectionMatrix->field0[0].x + (s64) viewPos.z * projectionMatrix->field0[2].z) >>
                12;
            screenY =
                ((s64) viewPos.y * projectionMatrix->field0[1].z + (s64) viewPos.z * projectionMatrix->field0[3].x) >>
                12;
            depth = -((const Vec3 *) &viewPos)->z;
            screenX = FX_Div(screenX, depth);
            screenY = FX_Div(screenY, depth);
            screenX = (((s64) screenX << 19) + 0x800) >> 12;
            screenY = ((s64) screenY * 0x60000 + 0x800) >> 12;
            isProjected = TRUE;
        }
        if (isProjected == FALSE) {
            continue;
        }
        if (kartObject->mTexPlttEntries->mEntries[3].mTexData != NULL) {
            DrawKartNameTagTexture(&kartObject->mTexPlttEntries->mEntries[3], kartObject, viewMatrix, data_021659a8,
                                   data_021659a0, alpha, screenX, screenY, data_021659bc, data_021659b0, func_02087ab0);
        }
        DrawKartNameTagTexture(&kartObject->mTexPlttEntries->mEntries[2], kartObject, viewMatrix, data_021659cc, 0x9000,
                               alpha, screenX, screenY, data_021659d0, 0, func_0208784c);
        DrawKartNameTagTexture(&kartObject->mTexPlttEntries->mEntries[1], kartObject, viewMatrix, 0x21000, 0xa000,
                               alpha, screenX, screenY, data_021659a4, 0x199a, func_02087ab0);
        DrawKartNameTagTexture(&kartObject->mTexPlttEntries->mEntries[0], kartObject, viewMatrix, data_021659c8,
                               data_021659c4, alpha, screenX, screenY, data_021659ac, data_021659b8, func_02087918);
    }
}

static inline s32 func_02086098_inline(KartNameTag *kartObject) {
    return (kartObject->mKartIndex + 11) << 24;
}

void DrawKartNameTagTexture(TexPlttEntry *texPlttEntry, KartNameTag *kartObject, MtxFx43 *viewMatrix, s32 scaleX,
                            s32 scaleY, s16 alpha, s32 screenX, s32 screenY, s32 xOffset, s32 yOffset,
                            UnkFunc *drawVertices) {
    MtxFx43 quadMatrix;
    s32 texWidthFixed;
    s32 texHeightFixed;
    s32 z;
    reg_G3_TEXIMAGE_PARAM = texPlttEntry->field0;
    if (texPlttEntry->mPlttByteCount != 0) {
        reg_G3_PLTT_BASE = texPlttEntry->mPlttOffset >> (4 - ((texPlttEntry->field0 >> 26 & 7) == 2));
    }
    MTX_Identity43_(&quadMatrix);
    quadMatrix.field0[3] = kartObject->mPos;
    MTX_Concat43(&quadMatrix, viewMatrix, &quadMatrix);
    quadMatrix.field0[3].x = screenX;
    if (kartObject->field10 == TRUE) {
        quadMatrix.field0[3].x = screenX + ((s32) (((s64) xOffset * scaleX + 0x800) >> 12) + 0x1e000);
    }
    quadMatrix.field0[3].y = 0x5000 + screenY + (s32) (((s64) yOffset * scaleY + 0x800) >> 12);
    quadMatrix.field0[3].z = 0;
    texWidthFixed = texPlttEntry->mTexWidthFixed;
    texHeightFixed = texPlttEntry->mTexHeightFixed;
    quadMatrix.field0[1].y = scaleY;
    quadMatrix.field0[0].x = scaleX;
    quadMatrix.field0[0].y = 0;
    quadMatrix.field0[0].z = 0;
    quadMatrix.field0[1].x = 0;
    quadMatrix.field0[1].z = 0;
    quadMatrix.field0[2].z = 0;
    quadMatrix.field0[2].y = 0;
    quadMatrix.field0[2].x = 0;
    reg_G3_POLYGON_ATTR = (func_02086098_inline(kartObject) | 0xc0) | (alpha << 16);
    reg_G3_MTX_MODE = 2;
    G3_LoadMtx43(&quadMatrix);
    reg_G3_BEGIN_VTXS = 1;
    reg_G3_COLOR = 0x7fff;
    drawVertices(texWidthFixed, texHeightFixed, kartObject->mKartPaletteColor);
    reg_G3_END_VTXS = 0;
}

u32 GetKartCameraDistanceSquared(int kartIndex) {
    u32 value0 = kartIndex;
    u32 value1;
    value1 = (u32) &data_0217aed0;
    value1 = *(const u32 *) ((value1) + (0));
    value0 = (value1) + ((value0 << 2));
    value0 = *(const u32 *) ((value0) + (292));
    return value0;
}

u16 func_0208606c(int index) {
    return data_02155a64[index];
}

u16 *GetKartIndicesByDistance(void) {
    return data_0217aed0->mKartIndicesByDistance;
}
