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
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02087918.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_02077bc0.h"
#include "code_021471bc.h"
#include "registers.h"

void UpdateKartViewDistancesAndOutOfView(void) {
    Vec3 cameraToKartWhole;
    Vec3 cameraToKart;
    s32 kartIndex;
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
    for (kartIndex = 0; kartIndex < gRaceSetup->mKartCount; kartIndex++) {
        GetKart(kartIndex);
        gKartNameTags->mNameTagBeyondTwoNearest[kartIndex] = 0;
        kart = GetKart(kartIndex);
        margin = kart->mRadius * 3;
        modelsEntry = kart->mKartModelsEntry;
        VEC_Subtract(kart->mPosSource, &viewFrustum->mCameraPos, &cameraToKart);
        distanceAlongView = VEC_DotProduct(&cameraToKart, &viewFrustum->mViewDirection);
        gKartNameTags->mDistanceAlongViewWithMargin[kartIndex] = distanceAlongView + margin;
        gKartNameTags->mAlongViewOrderIndex[kart->mIndex] =
            gKartNameTags->mStartOrderIndex[kart->mIndex] + gKartNameTags->mAlongViewOrderOffset[kart->mIndex];
        gKartNameTags->mSortedDistanceAlongView[gKartNameTags->mAlongViewOrderIndex[kart->mIndex]] = distanceAlongView;
        VEC_Subtract(kart->mPosSource, &viewFrustum->mCameraPos, &cameraToKartWhole);
        cameraToKartWhole.x = FROM_FIXED12(cameraToKartWhole.x);
        cameraToKartWhole.y = FROM_FIXED12(cameraToKartWhole.y);
        cameraToKartWhole.z = FROM_FIXED12(cameraToKartWhole.z);
        distanceSquared = cameraToKartWhole.x * cameraToKartWhole.x + cameraToKartWhole.y * cameraToKartWhole.y +
                          cameraToKartWhole.z * cameraToKartWhole.z;
        gKartNameTags->mDistanceSquared[kartIndex] = distanceSquared;
        SetKartNameTagSortedDistanceSquared(gKartNameTags->mStartOrderIndex[kart->mIndex] +
                                                gKartNameTags->mDistanceSquaredOrderOffset[kart->mIndex],
                                            distanceSquared);
        if (kart->mIndex != gRaceSetup->mEntryIndex) {
            isWithinFalloff = TRUE;
            if (distanceSquared > gSoundFalloffs[0].mFarDistanceSquared) {
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
                modelsEntry->mKartModelHidden = modelsEntry->mCharacterHidden = modelsEntry->mFarFromCamera = TRUE;
                modelsEntry->mShadowModel->mFlags &= ~1;
                kart->mEffectFlags |= KART_EFFECT_OUT_OF_VIEW;
            } else {
                isBeyondPlanes = FALSE;
                marginWhole = FROM_FIXED12(margin);
                if (VEC_DotProduct(&cameraToKartWhole, &viewFrustum->mLeftPlaneNormal) - marginWhole > 0) {
                    isBeyondPlanes = TRUE;
                } else if (VEC_DotProduct(&cameraToKartWhole, &viewFrustum->mRightPlaneNormal) - marginWhole > 0) {
                    isBeyondPlanes = TRUE;
                }
                if (isBeyondPlanes != FALSE) {
                    kart->mEffectFlags |= KART_EFFECT_OUT_OF_VIEW;
                } else {
                    kart->mEffectFlags &= ~KART_EFFECT_OUT_OF_VIEW;
                    modelsEntry->mKartModelHidden = modelsEntry->mCharacterHidden = modelsEntry->mFarFromCamera = FALSE;
                    modelsEntry->mShadowModel->mFlags |= 1;
                    if (distanceSquared > gKartDistanceLimitsSquared->z) {
                        kart->mEffectFlags |= KART_EFFECT_OUT_OF_VIEW;
                        modelsEntry->mKartModelHidden = modelsEntry->mCharacterHidden = modelsEntry->mFarFromCamera =
                            TRUE;
                        modelsEntry->mShadowModel->mFlags &= ~1;
                    } else if (distanceSquared > gKartDistanceLimitsSquared->y) {
                        modelsEntry->mKartModelHidden = modelsEntry->mFarFromCamera = TRUE;
                        modelsEntry->mShadowModel->mFlags &= ~1;
                    } else if (distanceSquared > gKartDistanceLimitsSquared->x) {
                        modelsEntry->mFarFromCamera = TRUE;
                        modelsEntry->mShadowModel->mFlags &= ~1;
                    }
                }
            }
        }
    }
    if (GetCurrentCameraKind() != 3) {
        objectCount = 0;
        for (orderIndex = gKartNameTags->mAlongViewOrderIndex[gRaceSetup->mEntryIndex] + 1;
             orderIndex < gRaceSetup->mKartCount; orderIndex++) {
            KartNameTag *kartObject;
            kartObject = gKartNameTags->mNameTagByKart[gKartNameTags->mKartIndicesByDistanceAlongView[orderIndex]];
            if (kartObject != NULL) {
                if (objectCount >= 2) {
                    gKartNameTags->mNameTagBeyondTwoNearest[kartObject->mKartIndex] = 1;
                }
                objectCount++;
            }
        }
    } else {
        objectCount = 0;
        for (orderIndex = 0; orderIndex < gRaceSetup->mKartCount; orderIndex++) {
            KartNameTag *kartObject;
            kartObject = gKartNameTags->mNameTagByKart[gKartNameTags->mKartIndicesByDistanceAlongView[orderIndex]];
            if (kartObject != NULL) {
                if (gKartNameTags
                        ->mSortedDistanceAlongView[gKartNameTags->mAlongViewOrderIndex[kartObject->mKartIndex]] >= 0) {
                    if (objectCount >= 2) {
                        gKartNameTags->mNameTagBeyondTwoNearest[kartObject->mKartIndex] = 1;
                    }
                    objectCount++;
                }
            }
        }
    }
}

void UpdateKartNameTags(void) {
    Vec3 objectPosition;
    s32 tagIndex;
    s32 distance;
    s32 alphaScale;
    KartNameTag *kartObject;
    Vec3 *posSource;
    Kart *kart;
    if (GetCurrentCameraKind() == 0) {
        gKartDistanceLimitsSquared = &gChaseDistanceLimitsSquared;
    } else {
        gKartDistanceLimitsSquared = &gOtherCameraDistanceLimitsSquared;
    }
    UpdateKartViewDistancesAndOutOfView();
    tagIndex = 0;
    while (tagIndex < gKartNameTags->mNameTagCount) {
        kartObject = gKartNameTags->mNameTags[tagIndex];
        kart = GetKart(kartObject->mKartIndex);
        posSource = kart->mPosSource;
        objectPosition = *posSource;
        distance = gKartNameTags->mDistanceAlongViewWithMargin[kartObject->mKartIndex];
        alphaScale = 0x1000;
        if (distance > 0) {
            if (gKartNameTags->mDistanceSquared[kartObject->mKartIndex] < 0x9c400 || GetCurrentCameraKind() == 3) {
                distance -= 0x14000;
                kartObject->mFadeLevelPerCall = 1;
                kartObject->mUnk_14 = 1;
                if (distance < 0) {
                    distance = 0;
                }
                alphaScale = MUL_FIXED12_ROUNDED(distance, 0x44);
            } else {
                kartObject->mFadeLevelPerCall = -1;
                kartObject->mUnk_14 = 2;
            }
        }
        if (gKartNameTags->mNameTagBeyondTwoNearest[kartObject->mKartIndex] != 0 ||
            (GetKart(kartObject->mKartIndex)->mEntryFlags & KART_ENTRY_REMOVED_PARKED_OR_TERESA) != 0 ||
            (GetAbsoluteValue(posSource->y - GetKart(gRaceSetup->mEntryIndex)->mPos.y) > 0x96000 &&
             GetCurrentCameraKind() != 3)) {
            kartObject->mFadeLevelPerCall = -1;
        }
        if (kartObject->mFadeStopped != FALSE) {
            if (GetRaceElapsedFrames() - 0x3c > 0) {
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
            kartObject->mAlpha = MUL_FIXED12_ROUNDED(kartObject->mFadeLevel, alphaScale);
        }
        objectPosition.y += 0xf000;
        kartObject->mPos.x = objectPosition.x >> 4;
        kartObject->mPos.y = objectPosition.y >> 4;
        kartObject->mPos.z = objectPosition.z >> 4;
        tagIndex += 1;
    }
    SortKartsByDistanceAlongViewOnePass();
    SortKartsByDistanceOnePass();
}

void SortKartsByDistanceAlongViewOnePass(void) {
    u16 *kartIndices;
    s16 *orderOffset;
    u16 sortIndex;
    s32 *distancesAlongView;
    s32 previousIndex;
    s32 previousDistance;
    s32 distance;
    u16 savedKartIndex;
    distancesAlongView = gKartNameTags->mSortedDistanceAlongView;
    for (sortIndex = 1; (u32) sortIndex < gRaceSetup->mKartCount; sortIndex++) {
        previousIndex = sortIndex - 1;
        previousDistance = distancesAlongView[previousIndex];
        distance = distancesAlongView[sortIndex];
        if (previousDistance > distance) {
            kartIndices = gKartNameTags->mKartIndicesByDistanceAlongView;
            orderOffset = gKartNameTags->mAlongViewOrderOffset;
            distancesAlongView[previousIndex] = distance;
            distancesAlongView[sortIndex] = previousDistance;
            orderOffset[kartIndices[sortIndex]]--;
            orderOffset[kartIndices[previousIndex]]++;
            savedKartIndex = kartIndices[sortIndex];
            kartIndices[sortIndex] = kartIndices[previousIndex];
            kartIndices[previousIndex] = savedKartIndex;
        }
    }
}

void SortKartsByDistanceOnePass(void) {
    u16 *kartIndices;
    s16 *orderOffset;
    u16 sortIndex;
    u32 *distancesSquared;
    s32 previousIndex;
    u32 previousDistanceSquared;
    u32 distanceSquared;
    u16 savedKartIndex;
    distancesSquared = gKartNameTags->mSortedDistanceSquared;
    for (sortIndex = 1; (u32) sortIndex < gRaceSetup->mKartCount; sortIndex++) {
        previousIndex = sortIndex - 1;
        previousDistanceSquared = distancesSquared[previousIndex];
        distanceSquared = distancesSquared[sortIndex];
        if (previousDistanceSquared > distanceSquared) {
            kartIndices = gKartNameTags->mKartIndicesByDistance;
            orderOffset = gKartNameTags->mDistanceSquaredOrderOffset;
            distancesSquared[previousIndex] = distanceSquared;
            distancesSquared[sortIndex] = previousDistanceSquared;
            orderOffset[kartIndices[sortIndex]]--;
            orderOffset[kartIndices[previousIndex]]++;
            savedKartIndex = kartIndices[sortIndex];
            kartIndices[sortIndex] = kartIndices[previousIndex];
            kartIndices[previousIndex] = savedKartIndex;
        }
    }
}

void DrawKartNameTags(MtxFx43 *viewMatrix) {
    s32 sortIndex;
    s16 alpha;
    s32 screenY;
    s32 screenX;
    s32 depth;
    Vec3 viewPos;
    MtxFx44 *projectionMatrix;
    KartNameTag *kartObject;
    BOOL isProjected;
    if (GetCurrentCameraKind() != 0 && GetCurrentCameraKind() != 3) {
        return;
    }
    reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 8;
    reg_G3_SPE_EMI = 0x4210;
    reg_G3_DIF_AMB = 0x42100000;
    reg_G3_MTX_MODE = 0;
    G3_LoadMtx44(&gKartNameTagProjection);
    reg_G3_MTX_MODE = 3;
    reg_G3_MTX_IDENTITY = 0;
    for (sortIndex = gRaceSetup->mKartCount - 1; sortIndex >= 0; sortIndex--) {
        kartObject = gKartNameTags->mNameTagByKart[gKartNameTags->mKartIndicesByDistanceAlongView[sortIndex]];
        if (kartObject == NULL) {
            continue;
        }
        if (gKartNameTags->mSortedDistanceAlongView[sortIndex] <= 0) {
            continue;
        }
        alpha = kartObject->mAlpha;
        if (alpha == 0) {
            continue;
        }
        if ((GetKart(gKartNameTags->mKartIndicesByDistanceAlongView[sortIndex])->mEntryFlags &
             (KART_ENTRY_REMOVED | KART_ENTRY_HIDDEN | KART_ENTRY_SCALING_IN)) != 0) {
            continue;
        }
        MTX_MultVec43(&kartObject->mPos, viewMatrix, &viewPos);
        if (viewPos.z >= 0) {
            isProjected = FALSE;
        } else {
            projectionMatrix = GetProjectionMatrix();
            screenX =
                DOT2_FIXED12(viewPos.x, projectionMatrix->mUnk_00[0].x, viewPos.z, projectionMatrix->mUnk_00[2].x);
            screenY =
                DOT2_FIXED12(viewPos.y, projectionMatrix->mUnk_00[1].y, viewPos.z, projectionMatrix->mUnk_00[2].y);
            depth = -((const Vec3 *) &viewPos)->z;
            screenX = FX_Div(screenX, depth);
            screenY = FX_Div(screenY, depth);
            screenX = (((s64) screenX << 19) + 0x800) >> 12;
            screenY = MUL_FIXED12_ROUNDED(screenY, 0x60000);
            isProjected = TRUE;
        }
        if (isProjected == FALSE) {
            continue;
        }
        if (kartObject->mTexPlttEntries->mEntries[3].mTexData != NULL) {
            DrawKartNameTagTexture(&kartObject->mTexPlttEntries->mEntries[3], kartObject, viewMatrix, data_021659a8,
                                   data_021659a0, alpha, screenX, screenY, data_021659bc, data_021659b0,
                                   DrawKartNameTagQuadVertices);
        }
        DrawKartNameTagTexture(&kartObject->mTexPlttEntries->mEntries[2], kartObject, viewMatrix, data_021659cc, 0x9000,
                               alpha, screenX, screenY, data_021659d0, 0, DrawKartNameTagLineVertices);
        DrawKartNameTagTexture(&kartObject->mTexPlttEntries->mEntries[1], kartObject, viewMatrix, 0x21000, 0xa000,
                               alpha, screenX, screenY, data_021659a4, 0x199a, DrawKartNameTagQuadVertices);
        DrawKartNameTagTexture(&kartObject->mTexPlttEntries->mEntries[0], kartObject, viewMatrix, data_021659c8,
                               data_021659c4, alpha, screenX, screenY, data_021659ac, data_021659b8,
                               DrawKartNameTagColoredVertices);
    }
}

static inline s32 GetKartNameTagPolygonIdBits(KartNameTag *kartObject) {
    return (kartObject->mKartIndex + 11) << 24;
}

void DrawKartNameTagTexture(TexPlttEntry *texPlttEntry, KartNameTag *kartObject, MtxFx43 *viewMatrix, s32 scaleX,
                            s32 scaleY, s16 alpha, s32 screenX, s32 screenY, s32 xOffset, s32 yOffset,
                            UnkFunc *drawVertices) {
    MtxFx43 quadMatrix;
    s32 texWidthFixed;
    s32 texHeightFixed;
    s32 unusedValue;
    reg_G3_TEXIMAGE_PARAM = texPlttEntry->mTexImageParam;
    if (texPlttEntry->mPlttByteCount != 0) {
        reg_G3_PLTT_BASE = texPlttEntry->mPlttOffset >> (4 - ((texPlttEntry->mTexImageParam >> 26 & 7) == 2));
    }
    MTX_Identity43_(&quadMatrix);
    quadMatrix.mRows[3] = kartObject->mPos;
    MTX_Concat43(&quadMatrix, viewMatrix, &quadMatrix);
    quadMatrix.mRows[3].x = screenX;
    if (kartObject->mUnk_10 == TRUE) {
        quadMatrix.mRows[3].x = screenX + (MUL_FIXED12_ROUNDED(xOffset, scaleX) + 0x1e000);
    }
    quadMatrix.mRows[3].y = 0x5000 + screenY + MUL_FIXED12_ROUNDED(yOffset, scaleY);
    quadMatrix.mRows[3].z = 0;
    texWidthFixed = texPlttEntry->mTexWidthFixed;
    texHeightFixed = texPlttEntry->mTexHeightFixed;
    quadMatrix.mRows[1].y = scaleY;
    quadMatrix.mRows[0].x = scaleX;
    quadMatrix.mRows[0].y = 0;
    quadMatrix.mRows[0].z = 0;
    quadMatrix.mRows[1].x = 0;
    quadMatrix.mRows[1].z = 0;
    quadMatrix.mRows[2].z = 0;
    quadMatrix.mRows[2].y = 0;
    quadMatrix.mRows[2].x = 0;
    reg_G3_POLYGON_ATTR = (GetKartNameTagPolygonIdBits(kartObject) | 0xc0) | (alpha << 16);
    reg_G3_MTX_MODE = 2;
    G3_LoadMtx43(&quadMatrix);
    reg_G3_BEGIN_VTXS = 1;
    reg_G3_COLOR = 0x7fff;
    drawVertices(texWidthFixed, texHeightFixed, kartObject->mKartPaletteColor);
    reg_G3_END_VTXS = 0;
}

u32 GetKartCameraDistanceSquared(int kartIndex) {
    return gKartNameTags->mDistanceSquared[kartIndex];
}

u16 GetKartPaletteColorFromTable(int index) {
    return gKartPaletteColors[index];
}

u16 *GetKartIndicesByDistance(void) {
    return gKartNameTags->mKartIndicesByDistance;
}
