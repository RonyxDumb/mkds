#pragma once

#include "types.h"
#include "texture_resource_type.h"
#include "model_draw_state.h" // NNSG3dRenderObj
#include "model_material_set.h" // NNSG3dResFileHeader, NNSG3dResMdl
#include "sound_archive_load.h"

typedef struct MtxFx43 MtxFx43;

// A loaded model resource file with its texture, kept in the list gResFileEntries.
typedef struct ResFileEntry {
    /* 00 */ void *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ NNSG3dResFileHeader *mFile;
    /* 0c */ NNSG3dResTex *mTexture;
} ResFileEntry;

// A model: a render object with its model resource, then the cull mode swap flag, the draw kind and the file entry.
typedef struct Nsbmd {
    union {
        NNSG3dRenderObj mRenderObj;
        struct {
            /* 00 */ u8 mUnk_00[4];
            /* 04 */ NNSG3dResMdl *mResMdl;
            /* 08 */ u8 mUnk_08[0x4c];
        };
    };
    /* 54 */ s32 mCullModesSwapped;
    /* 58 */ s32 mDrawKind;
    /* 5c */ ResFileEntry mResFileEntry;
} Nsbmd;

void InitKartEffectTables(void *heap);
void ReleaseAllResFiles(void);
void SetNsbmdCullModeAll(Nsbmd *nsbmd, u32 cullMode);
void SetNsbmdPolygonIdLightEmiAll(Nsbmd *nsbmd, u32 polygonId, u32 light, u32 color);
void SetNsbmdEmiAll(Nsbmd *nsbmd, u32 color);
void SetNsbmdLightEnableFlagAll(Nsbmd *nsbmd, u32 light);
void SetNsbmdPolygonIdAll(Nsbmd *nsbmd, u32 polygonId);
void DrawNsbmd(Nsbmd *nsbmd);
void DrawNsbmdWithMatrix(Nsbmd *object, MtxFx43 *matrix, const Vec3 *scale);
void SetNsbmdSecondDrawMaterial(Nsbmd *nsbmd, u8 alpha, u8 polygonId);
void SetNsbmdFirstDrawMaterial(Nsbmd *nsbmd, u8 alpha);
NNSG3dResMdl *InitNsbmdWithTextureInfoCopy(void *heap, Nsbmd *nsbmd, NNSG3dResFileHeader *modelFile,
                                           NNSG3dResFileHeader *textureFile);
NNSG3dResMdl *InitNsbmdWithoutCullSwap(Nsbmd *nsbmd, NNSG3dResFileHeader *file);
NNSG3dResMdl *InitNsbmdWithTextureFile(Nsbmd *nsbmd, NNSG3dResFileHeader *modelFile, NNSG3dResFileHeader *textureFile);
NNSG3dResMdl *InitNsbmd(Nsbmd *nsbmd, NNSG3dResFileHeader *file);
void InitNsbmdRenderObjWrapper(Nsbmd *nsbmd, NNSG3dResMdl *resMdl);
void SetNsbmdCullModeUnmirrored(Nsbmd *nsbmd);
void SetNsbmdCullModeMirrored(Nsbmd *nsbmd);
void InitNsbmdRenderObj(Nsbmd *nsbmd, NNSG3dResMdl *resMdl, u32 allowCullSwap);
u32 UploadResTexture(NNSG3dResTex *texture);
void AddResFileEntry(ResFileEntry *entry, NNSG3dResFileHeader *modelFile, NNSG3dResFileHeader *textureFile);

extern const Vec3 gKartEffectVec3UnitY;
extern const Vec3 gKartEffectVec3Zero;
