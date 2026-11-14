#include "Main/Kart/kart_name_tags.h"

#include "Main/MapObjects/data_02155000.h"
#include "Main/MapObjects/data_0217a000.h"
#include "fx_mtx43.h"
#include "code_02147cd8.h"
#include "g3imm.h"
#include "Main/Race/race_elapsed_frames.h"
#include "Main/Kart/kart_name_tag_draw.h"
#include "Main/Graphics/model_animation_loop.h"
#include "Main/Race/race.h"
#include "Main/Kart/camera.h"
#include "Main/Kart/kart_state0_return.h"
#include "Main/MapObjects/view_frustum.h"
#include "code_02012b30.h"
#include "Main/Sound/sound_sources.h"
#include "Main/Item/item_in_use.h"
#include "Main/Kart/kart_name_tag_colored.h"
#include "Main/MapObjects/data_02165000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Kart/karts.h"
#include "registers.h"

u16 gKartNameTagLineVertices[12] = {0xf400, 0x2000, 0, 0xf000, 0, 0, 0x1000, 0, 0, 0x1000, 0x2000, 0};
TexPlttEntry gKartNameTagEmblemTexPltt = {0xd200000, 0, 0, {0, 0}, NULL, NULL, {0, 0, 0, 0}, 0, 0, 0};
TexPlttEntry gKartNameTagColorQuadTexPltt = {
    0x28100000,   0x20, 8, {0, 0}, (void *) gKartNameTagColorQuadTexture, (void *) gKartNameTagColorQuadPalette,
    {0, 0, 0, 0}, 0,    0, 0};
TexPlttEntry gKartNameTagEntryNameTexPltt = {0x28b00000, 0x100, 8, {0, 0}, NULL, NULL, {0, 0, 0, 0}, 0, 0, 0};
TexPlttEntry gKartNameTagMaskedTexPltt = {
    0x2cb00000,   0x200, 0x20, {0, 0}, (void *) gKartNameTagMaskedTexture, (void *) gKartNameTagMaskedPalette,
    {0, 0, 0, 0}, 0,     0,    0};

s32 gKartNameTagEntry3YOffset = 0x3b33;
s32 gKartNameTagEntry3ScaleX = 0x20000;
s32 gKartNameTagEntry3ScaleY = 0x8971;
s32 gKartNameTagEntry1XOffset = 0x571;
s32 gKartNameTagEntry2XOffset = 0x59a;
s32 gKartNameTagEntry2ScaleX = 0x30000;
s32 gKartNameTagEntry0ScaleX = 0xa385;
s32 gKartNameTagEntry0ScaleY = 0xa385;
s32 gKartNameTagColorQuadScaleX = 0x12e1;
s32 gKartNameTagEntry3XOffset = 0x733;
s32 gKartNameTagEntry0YOffset = 0x1c00;
s32 gKartNameTagColorQuadScaleY = 0x119a;
s32 gKartNameTagEntry0XOffset = 0x52ac;
const u16 gTeamPaletteColors[2] = {0x7cc1, 0x43f};
const u16 gRegionPaletteColors[4] = {0x43f, 0x7cc1, 0x1a80, 0};
const u16 gKartNameTagColorQuadPalette[4] = {0, 0, 0x7fff, 0x7fff};
const Vec3 gChaseDistanceLimitsSquared = {0x57e40, 0x9c400, 0x19c990};
const Vec3 gOtherCameraDistanceLimitsSquared = {0x225510, 0x317040, 0x3d0900};
u8 *gKartEntryNameTexBuffer;
u8 *gKartNameTagMaskedTexBuffer;
u16 *gKartEmblemPlltBuffer;
u16 *gKartEntryNamePlltBuffer;
KartNameTags *gKartNameTags;
const Vec3 *gKartDistanceLimitsSquared;
s32 gKartNameTagsUnusedWord;
MtxFx44 gKartNameTagProjection;

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
    reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~(REG_G3X_DISP3DCNT_GO_MASK | REG_G3X_DISP3DCNT_RO_MASK)) | 8;
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
                DOT2_FIXED12(viewPos.x, projectionMatrix->mRows[0].x, viewPos.z, projectionMatrix->mRows[2].x);
            screenY =
                DOT2_FIXED12(viewPos.y, projectionMatrix->mRows[1].y, viewPos.z, projectionMatrix->mRows[2].y);
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
            DrawKartNameTagTexture(&kartObject->mTexPlttEntries->mEntries[3], kartObject, viewMatrix,
                                   gKartNameTagEntry3ScaleX, gKartNameTagEntry3ScaleY, alpha, screenX, screenY,
                                   gKartNameTagEntry3XOffset, gKartNameTagEntry3YOffset, DrawKartNameTagQuadVertices);
        }
        DrawKartNameTagTexture(&kartObject->mTexPlttEntries->mEntries[2], kartObject, viewMatrix,
                               gKartNameTagEntry2ScaleX, 0x9000, alpha, screenX, screenY, gKartNameTagEntry2XOffset, 0,
                               DrawKartNameTagLineVertices);
        DrawKartNameTagTexture(&kartObject->mTexPlttEntries->mEntries[1], kartObject, viewMatrix, 0x21000, 0xa000,
                               alpha, screenX, screenY, gKartNameTagEntry1XOffset, 0x199a, DrawKartNameTagQuadVertices);
        DrawKartNameTagTexture(&kartObject->mTexPlttEntries->mEntries[0], kartObject, viewMatrix,
                               gKartNameTagEntry0ScaleX, gKartNameTagEntry0ScaleY, alpha, screenX, screenY,
                               gKartNameTagEntry0XOffset, gKartNameTagEntry0YOffset, DrawKartNameTagColoredVertices);
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
