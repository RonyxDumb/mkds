#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx43
#include "Main/MapObjects/data_0217a000.h"
#include "code_021479b4.h"

// 0x24-byte entry: the word at 0x00 and the halfword at 0x08 are tested by DrawKartNameTagTexture and
// UploadTextureAndPalette, the words at 0x1c and 0x20 are passed to the function given to DrawKartNameTagTexture.
typedef struct TexPlttEntry {
    /* 00 */ u32 mTexImageParam;
    /* 04 */ s32 mTexByteCount;
    /* 08 */ u16 mPlttByteCount;
    /* 0a */ u8 mUnk_0a[2];
    /* 0c */ void *mTexData;
    /* 10 */ void *mPlttData;
    /* 14 */ u8 mUnk_14[4];
    /* 18 */ u32 mPlttOffset;
    /* 1c */ s32 mTexWidthFixed;
    /* 20 */ s32 mTexHeightFixed;
} TexPlttEntry;

// Four entries.
typedef struct KartNameTagTexPlttEntries {
    /* 00 */ TexPlttEntry mEntries[4];
} KartNameTagTexPlttEntries;

// The name tag over a kart in a race: emblem, entry name and a line down to the kart.
typedef struct KartNameTag {
    /* 00 */ Vec3 mPos;
    /* 0c */ u16 mKartIndex;
    /* 0e */ u8 mUnk_0e[2];
    /* 10 */ BOOL mApplyXOffset;
    /* 14 */ s32 mFadeState;
    /* 18 */ BOOL mFadeStopped;
    /* 1c */ KartNameTagTexPlttEntries *mTexPlttEntries;
    /* 20 */ s16 mFadeLevelPerCall;
    /* 22 */ s16 mFadeLevel;
    /* 24 */ s16 mAlpha;
    /* 26 */ u16 mKartPaletteColor;
} KartNameTag;

typedef void (*KartNameTagVertexFunc)(s32 texWidthFixed, s32 texHeightFixed, u32 color);

void DrawKartNameTagTexture(TexPlttEntry *texPlttEntry, KartNameTag *kartObject, MtxFx43 *viewMatrix, s32 scaleX,
                            s32 scaleY, s16 alpha, s32 screenX, s32 screenY, s32 xOffset, s32 yOffset,
                            KartNameTagVertexFunc drawVertices);

u16 *GetKartIndicesByDistance(void);
u16 GetKartPaletteColorFromTable(int index);
u32 GetKartCameraDistanceSquared(int kartIndex);
void DrawKartNameTags(MtxFx43 *viewMatrix);
void SortKartsByDistanceOnePass(void);
void SortKartsByDistanceAlongViewOnePass(void);
void UpdateKartNameTags(void);
void UpdateKartViewDistancesAndOutOfView(void);

extern s32 gKartNameTagLineScaleX;
extern s32 gKartNameTagEmblemScaleX;
extern s32 gKartNameTagEmblemScaleY;
extern s32 gKartNameTagColorQuadScaleX;
extern s32 gKartNameTagMaskedXOffset;
extern s32 gKartNameTagEmblemYOffset;
extern s32 gKartNameTagColorQuadScaleY;
extern s32 gKartNameTagMaskedYOffset;
extern s32 gKartNameTagEmblemXOffset;
extern s32 gKartNameTagMaskedScaleX;
extern s32 gKartNameTagNameXOffset;
extern s32 gKartNameTagMaskedScaleY;
extern s32 gKartNameTagLineXOffset;

extern const Vec3 gChaseDistanceLimitsSquared;
extern const Vec3 gOtherCameraDistanceLimitsSquared;

extern u8 *gKartEntryNameTexBuffer;
extern u16 *gKartEntryNamePlltBuffer;
extern u8 *gKartNameTagMaskedTexBuffer;
extern struct KartNameTags *gKartNameTags;
extern u16 *gKartEmblemPlltBuffer;
extern const Vec3 *gKartDistanceLimitsSquared;
extern s32 gKartNameTagsUnusedWord;
extern MtxFx44 gKartNameTagProjection;

extern const u16 gKartNameTagColorQuadPalette[4];

extern u16 gKartNameTagLineVertices[12];
extern TexPlttEntry gKartNameTagColorQuadTexPltt;
extern TexPlttEntry gKartNameTagEmblemTexPltt;
extern TexPlttEntry gKartNameTagEntryNameTexPltt;
extern TexPlttEntry gKartNameTagMaskedTexPltt;

// Values of KartNameTag.mFadeState: no fade, fading in near the camera, fading out.
#define KART_NAME_TAG_FADE_NONE 0
#define KART_NAME_TAG_FADE_IN 1
#define KART_NAME_TAG_FADE_OUT 2
// A name tag fades in when the squared distance to the camera is below this; the highest fade level it reaches.
#define KART_NAME_TAG_FADE_IN_DISTANCE_SQUARED 0x9c400
#define KART_NAME_TAG_FADE_LEVEL_MAX 0x1e
