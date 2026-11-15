#include "Main/Kart/kart_name_tag_draw.h"
#include "Main/Race/results_gp.h"
#include "03/Net/essid_packet_steps.h"
#include "Main/Graphics/kart_entry_name_texture.h"
#include "Main/Kart/kart_name_tags.h"

#include "arena_cache_init.h"
#include "animation_lookup.h"
#include "model_material_set.h"
#include "vram_load_3d_graphics.h"
#include "cpu_copy_fill.h"
#include "thread_scheduler.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/System/result_archive_path.h"
#include "Main/Kart/kart_models_entry.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Kart/kart_model_path.h"
#include "Main/Kart/kart_palette_stem_tables.h"
#include "Main/Graphics/g3d_anm_function_pointers.h"
#include "Main/Kart/kart_effect_param_tables.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/System/heap.h"
#include "Main/Kart/karts.h"
#include "geometry_engine_setup.h"
#include "Main/System/heap_call.h"
#include "Main/Race/race.h"
#include "registers.h"
#include "Main/Graphics/model_animation_looping.h"
#include "frame_texture_vram_alloc.h"

const char gKartEmblemTextureName[16] = "kart_emblem";
const u16 gKartPaletteColors[8] = {0x280, 0x7d48, 0x35f, 0x1f, 0x48cc, 0x7ac0, 0x11be, 0x6c1b};

void DrawKartNameTagLineVertices(s32 texWidthFixed, s32 texHeightFixed, u32 color) {
    u16 heightTexCoord;
    u16 widthTexCoord;
    u16 vertexZ;
    heightTexCoord = (texHeightFixed << 8) >> 16;
    widthTexCoord = (texWidthFixed << 8) >> 16;
    reg_G3_TEXCOORD = 0x60006;
    vertexZ = gKartNameTagLineVertices[2];
    reg_G3_VTX_16 = gKartNameTagLineVertices[0] | gKartNameTagLineVertices[1] << 16;
    reg_G3_VTX_16 = vertexZ;
    reg_G3_TEXCOORD = heightTexCoord << 16 | 6;
    vertexZ = gKartNameTagLineVertices[5];
    reg_G3_VTX_16 = gKartNameTagLineVertices[3] | gKartNameTagLineVertices[4] << 16;
    reg_G3_VTX_16 = vertexZ;
    reg_G3_TEXCOORD = widthTexCoord | heightTexCoord << 16;
    vertexZ = gKartNameTagLineVertices[8];
    reg_G3_VTX_16 = gKartNameTagLineVertices[6] | gKartNameTagLineVertices[7] << 16;
    reg_G3_VTX_16 = vertexZ;
    reg_G3_TEXCOORD = widthTexCoord | 0x60000;
    vertexZ = gKartNameTagLineVertices[11];
    reg_G3_VTX_16 = gKartNameTagLineVertices[9] | gKartNameTagLineVertices[10] << 16;
    reg_G3_VTX_16 = vertexZ;
}

#pragma thumb on

void InitKartNameTagsAndDistanceOrder(void) {
    void *heap;
    BOOL isGrandPrix;
    u16 kartIndex;
    s32 objectCount;
    BOOL createsObject;
    BOOL isEntryIndexHumanGhostOrPeer;
    u32 playerKind;
    KartNameTag *kartObject;
    s32 entryIndex;
    BOOL isEntryHumanGhostOrPeer;
    heap = GetHeap(GetCurrentHeapCall());
    if (gRaceSetup->mMode == MODE_GRAND_PRIX) {
        isGrandPrix = TRUE;
    } else {
        isGrandPrix = FALSE;
    }
    gKartNameTags = HeapAlloc(heap, sizeof(*gKartNameTags));
    gKartNameTags->mUnk_184 = 0;
    gKartNameTags->mEmblemPlttData = NULL;
    if (IsRaceAwardOrStaffRoll() != 0) {
        gKartNameTags->mNameTagCount = 0;
    } else if (isGrandPrix == FALSE) {
        gKartNameTags->mNameTagCount = gRaceSetup->mKartCount - 1;
        for (kartIndex = 0; (u32) kartIndex < gRaceSetup->mKartCount; kartIndex++) {
            if (gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mKind == PLAYER_KIND_GHOST &&
                gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mGhostRecordIndex == GHOST_RECORD_INDEX_COURSE) {
                gKartNameTags->mNameTagCount = gKartNameTags->mNameTagCount - 1;
            }
        }
    } else {
        gKartNameTags->mNameTagCount = gRaceSetup->mHumanAndPeerKartCount;
        entryIndex = gRaceSetup->mEntryIndex;
        isEntryIndexHumanGhostOrPeer = FALSE;
        if (entryIndex != -1) {
            playerKind = GetCurrentEntry(entryIndex)->mPlayer.mKind;
            if (playerKind <= 3 && ((1 << playerKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) != 0) {
                isEntryIndexHumanGhostOrPeer = TRUE;
            }
            if (isEntryIndexHumanGhostOrPeer != FALSE) {
                gKartNameTags->mNameTagCount = gKartNameTags->mNameTagCount - 1;
            }
        }
    }
    gKartDistanceLimitsSquared = &gOtherCameraDistanceLimitsSquared;
    InitKartEmblemPointers();
    for (kartIndex = 0; (u32) kartIndex < gRaceSetup->mKartCount; kartIndex++) {
        gKartNameTags->mStartOrderIndex[kartIndex] = kartIndex;
        gKartNameTags->mKartIndicesByDistanceAlongView[kartIndex] = kartIndex;
        gKartNameTags->mKartIndicesByDistance[kartIndex] = kartIndex;
        gKartNameTags->mAlongViewOrderOffset[kartIndex] = 0;
        gKartNameTags->mDistanceSquaredOrderOffset[kartIndex] = 0;
        gKartNameTags->mSortedDistanceAlongView[kartIndex] = 0;
        gKartNameTags->mSortedDistanceSquared[kartIndex] = 0;
        gKartNameTags->mAlongViewOrderIndex[kartIndex] = kartIndex;
        gKartNameTags->mKartIndicesByDistance[kartIndex] = kartIndex;
        gKartNameTags->mDistanceAlongViewWithMargin[kartIndex] = 0;
        gKartNameTags->mNameTagByKart[kartIndex] = NULL;
        gKartNameTags->mNameTagBeyondTwoNearest[kartIndex] = 0;
    }
    if (gKartNameTags->mNameTagCount > 0) {
        objectCount = 0;
        for (kartIndex = 0; (u32) kartIndex < gRaceSetup->mKartCount; kartIndex++) {
            createsObject = FALSE;
            if (isGrandPrix == FALSE) {
                if (kartIndex != gRaceSetup->mEntryIndex) {
                    if (gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mKind != PLAYER_KIND_GHOST ||
                        gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mGhostRecordIndex != GHOST_RECORD_INDEX_COURSE) {
                        createsObject = TRUE;
                    }
                }
            } else {
                isEntryHumanGhostOrPeer = FALSE;
                playerKind = gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mKind;
                if (playerKind <= 3 && ((1 << playerKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) != 0) {
                    isEntryHumanGhostOrPeer = TRUE;
                }
                if (isEntryHumanGhostOrPeer != FALSE && kartIndex != gRaceSetup->mEntryIndex) {
                    createsObject = TRUE;
                }
            }
            if (createsObject != FALSE) {
                gKartNameTags->mNameTagByKart[kartIndex] =
                    HeapAlloc(heap, sizeof(*gKartNameTags->mNameTagByKart[kartIndex]));
                kartObject = gKartNameTags->mNameTagByKart[kartIndex];
                InitKartNameTag(kartObject, kartIndex, heap);
                gKartNameTags->mNameTags[objectCount] = kartObject;
                objectCount++;
            } else {
                gKartNameTags->mNameTagByKart[kartIndex] = NULL;
            }
        }
    }
    reg_G3_MTX_MODE = 0;
    G3i_OrthoW_(0x60000, 0xfffa0000, 0xfff80000, 0x80000, 0, 0x1000, 0x200, 1, &gKartNameTagProjection);
}

void InitKartNameTag(KartNameTag *kartObject, u16 kartIndex, void *heap) {
    kartObject->mTexPlttEntries = HeapAlloc(heap, sizeof(KartNameTagTexPlttEntries));
    kartObject->mPos = gKartNameTagInitialPos;
    kartObject->mKartIndex = kartIndex;
    kartObject->mTexPlttEntries->mEntries[0] = gKartNameTagEmblemTexPltt;
    kartObject->mTexPlttEntries->mEntries[1] = gKartNameTagEntryNameTexPltt;
    kartObject->mTexPlttEntries->mEntries[2] = gKartNameTagColorQuadTexPltt;
    kartObject->mTexPlttEntries->mEntries[3] = gKartNameTagMaskedTexPltt;
    kartObject->mApplyXOffset = TRUE;
    kartObject->mFadeState = KART_NAME_TAG_FADE_NONE;
    kartObject->mFadeStopped = TRUE;
    kartObject->mAlpha = 0;
    kartObject->mKartPaletteColor = COLOR15_WHITE;
    kartObject->mFadeLevel = 0;
    kartObject->mFadeLevelPerCall = 0;
}

void SetTextureSizeFromBits(TexPlttEntry *texPlttEntry) {
    u16 texHeightBits;
    u16 texWidthBits;
    s32 texWidth;
    s32 texHeight;
    texHeightBits = texPlttEntry->mTexImageParam >> 23 & 7;
    texWidthBits = texPlttEntry->mTexImageParam >> 20 & 7;
    switch (texWidthBits) {
        case 0:
            texWidth = 8;
            break;
        case 1:
            texWidth = 0x11;
            break;
        case 2:
            texWidth = 0x21;
            break;
        case 3:
            texWidth = 0x41;
            break;
        case 4:
            texWidth = 0x80;
            break;
        case 5:
            texWidth = 0x100;
            break;
        case 6:
            texWidth = 0x200;
            break;
        case 7:
            texWidth = 0x400;
            break;
    }
    switch (texHeightBits) {
        case 0:
            texHeight = 8;
            break;
        case 1:
            texHeight = 0x11;
            break;
        case 2:
            texHeight = 0x21;
            break;
        case 3:
            texHeight = 0x41;
            break;
        case 4:
            texHeight = 0x80;
            break;
        case 5:
            texHeight = 0x100;
            break;
        case 6:
            texHeight = 0x200;
            break;
        case 7:
            texHeight = 0x400;
            break;
    }
    texPlttEntry->mTexWidthFixed = TO_FIXED12(texWidth);
    texPlttEntry->mTexHeightFixed = TO_FIXED12(texHeight);
}

u16 GetKartPaletteColor(int kartIndex) {
    if (gRaceSetup->mMode == MODE_WIFI) {
        return gRegionPaletteColors[gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mRegion];
    }
    if (gRaceSetup->mUseTeams != 0) {
        return gTeamPaletteColors[gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex];
    }
    if (GetKartModelsEntry(kartIndex)->mCharacterIndex == CHARACTER_HEYHO) {
        return GetHeyhoPalette(kartIndex)->mColor;
    }
    return gKartPaletteColors[kartIndex];
}

void UploadKartNameTagTextures(void) {
    u16 nameTagIndex;
    void *heap;
    KartNameTag *kartObject;
    KartNameTagTexPlttEntries *texPlttEntries;
    TexPlttEntry *entryNameTexPltt;
    TexPlttEntry *fourthTexPltt;
    heap = GetHeap(GetCurrentHeapCall());
    UploadKartEmblems();
    gKartNameTagsUnusedWord = 0;
    gKartEmblemPlltBuffer = HeapAllocAligned(heap, 0x20, -4);
    gKartEntryNameTexBuffer = HeapAllocAligned(heap, 0x100, -4);
    gKartEntryNamePlltBuffer = HeapAllocAligned(heap, 8, -4);
    gKartNameTagMaskedTexBuffer = HeapAllocAligned(heap, 0x200, -4);
    for (nameTagIndex = 0; nameTagIndex < gKartNameTags->mNameTagCount; nameTagIndex++) {
        kartObject = gKartNameTags->mNameTags[nameTagIndex];
        texPlttEntries = kartObject->mTexPlttEntries;
        entryNameTexPltt = &texPlttEntries->mEntries[1];
        fourthTexPltt = &texPlttEntries->mEntries[3];
        texPlttEntries->mEntries[0].mTexByteCount = KART_EMBLEM_TEX_BYTES;
        texPlttEntries->mEntries[0].mPlttByteCount = KART_EMBLEM_PLTT_BYTES;
        texPlttEntries->mEntries[0].mPlttData = gKartNameTags->mEmblemPlttData;
        kartObject->mKartPaletteColor = GetKartPaletteColor(kartObject->mKartIndex);
        SetupKartEmblemTexture(&texPlttEntries->mEntries[0], kartObject->mKartIndex);
        SetupKartEntryNameTexture(entryNameTexPltt, kartObject->mKartIndex);
        SetPaletteKartColor(&texPlttEntries->mEntries[2], kartObject->mKartIndex);
        SetupKartNameTagMaskedTexture(fourthTexPltt, kartObject->mKartIndex);
        UploadTextureAndPalette(&texPlttEntries->mEntries[0]);
        UploadTextureAndPalette(entryNameTexPltt);
        UploadTextureAndPalette(&kartObject->mTexPlttEntries->mEntries[2]);
        if (fourthTexPltt->mTexData != NULL) {
            UploadTextureAndPalette(fourthTexPltt);
        }
    }
    HeapFree(heap, gKartNameTagMaskedTexBuffer);
    HeapFree(heap, gKartEntryNamePlltBuffer);
    HeapFree(heap, gKartEntryNameTexBuffer);
    HeapFree(heap, gKartEmblemPlltBuffer);
}

void SetupKartEmblemTexture(TexPlttEntry *texPlttEntry, u16 kartIndex) {
    u16 *plttBuffer;
    void *emblemTex;
    u16 firstColor;
    plttBuffer = gKartEmblemPlltBuffer;
    emblemTex = gKartNameTags->mEmblemTex[kartIndex];
    MI_CpuCopy8(gKartNameTags->mEmblemPltt[kartIndex], plttBuffer, texPlttEntry->mPlttByteCount);
    firstColor = 0x7fff;
    if (gRaceSetup->mUseTeams != 0) {
        firstColor = gTeamPaletteColors[gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex];
    }
    *plttBuffer = firstColor;
    DC_FlushRange(plttBuffer, texPlttEntry->mPlttByteCount);
    DC_FlushRange(emblemTex, texPlttEntry->mTexByteCount);
    texPlttEntry->mPlttData = plttBuffer;
    texPlttEntry->mTexData = emblemTex;
}

#pragma thumb off

#pragma thumb on

void SetupKartEntryNameTexture(TexPlttEntry *texPlttEntry, u32 kartIndex) {
    u16 kartPaletteColor;
    u16 *plttBuffer;
    u8 *texBuffer;
    texBuffer = gKartEntryNameTexBuffer;
    plttBuffer = gKartEntryNamePlltBuffer;
    *plttBuffer = (0x00007c00u);
    kartPaletteColor = GetKartPaletteColor(kartIndex);
    plttBuffer[1] = kartPaletteColor;
    plttBuffer[2] = 0;
    plttBuffer[3] = 0x1f;
    DC_FlushRange(plttBuffer, 8);
    MI_CpuFill8(texBuffer, 0, texPlttEntry->mTexByteCount);
    RenderKartEntryNameToTexture(kartIndex, texBuffer, 1, 2);
    DC_FlushRange(texBuffer, 0x100);
    texPlttEntry->mTexData = texBuffer;
    texPlttEntry->mPlttData = plttBuffer;
}

void SetPaletteKartColor(TexPlttEntry *texPlttEntry, u32 kartIndex) {
    u16 kartPaletteColor;
    u16 *plttData;
    plttData = texPlttEntry->mPlttData;
    kartPaletteColor = GetKartPaletteColor(kartIndex);
    plttData[1] = kartPaletteColor;
    DC_FlushRange(plttData, 8);
}

#pragma thumb off

#pragma thumb on

void SetupKartNameTagMaskedTexture(TexPlttEntry *texPlttEntry, u16 kartIndex) {
    u8 *pixels;
    s32 nibbleLimit;
    u32 pixelIndex;
    TexPlttEntry *texPlttEntryAlias;
    u8 pixelPair;
    u32 highNibbleBits;
    u8 highNibble;
    u8 lowNibble;
    texPlttEntryAlias = texPlttEntry;
    if (gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mLowestGrandPrixRecordValue != 0) {
        pixels = gKartNameTagMaskedTexBuffer;
        nibbleLimit = 7;
        switch (gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mLowestGrandPrixRecordValue) {
            case GP_LOWEST_RECORD_SECOND_BEST:
                nibbleLimit = 4;
                break;
            case GP_LOWEST_RECORD_BEST:
                nibbleLimit = -1;
                break;
        }
        MI_CpuCopy8(texPlttEntryAlias->mTexData, pixels, texPlttEntryAlias->mTexByteCount);
        if (nibbleLimit > 0) {
            for (pixelIndex = 0; pixelIndex < texPlttEntryAlias->mTexByteCount; pixelIndex++) {
                pixelPair = pixels[pixelIndex];
                highNibbleBits = pixelPair & 0xf0;
                highNibble = highNibbleBits >> 4;
                lowNibble = pixelPair & 0xf;
                if (lowNibble < nibbleLimit) {
                    pixelPair = highNibbleBits;
                }
                if (highNibble < nibbleLimit) {
                    pixelPair = pixelPair & 0xf;
                }
                pixels[pixelIndex] = pixelPair;
            }
        }
        DC_FlushRange(pixels, texPlttEntryAlias->mTexByteCount);
        texPlttEntryAlias->mTexData = pixels;
    } else {
        texPlttEntryAlias->mTexData = NULL;
    }
}

void InitKartEmblemPointers(void) {
    u16 kartIndex;
    Nclr *nclr;
    NNSG3dResTex *texture;
    char *path;
    u8 *emblemPltt;
    u8 *emblemTex;
    for (kartIndex = 0; (u32) kartIndex < gRaceSetup->mKartCount; kartIndex++) {
        gKartNameTags->mEmblemTex[kartIndex] = NULL;
        gKartNameTags->mEmblemPltt[kartIndex] = NULL;
        if (gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mHasEmblem == 0 || gRaceSetup->mUseTeams != 0) {
            if (gRaceSetup->mUseTeams != 0) {
                path = BuildTeamEmblemNsbtxPath(gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex == 1 ? 1 : 0);
            } else {
                path = BuildEmblemNsbtxPath(gRaceSetup->mCurrentEntries[kartIndex].mCharacterIndex);
            }
            texture = NNS_G3dGetTex(GetKartModelFile(path));
            emblemPltt = OFFSET_PTR(u8, texture, texture->mPlttInfo.mOfsPlttData);
            emblemTex = OFFSET_PTR(u8, texture, texture->mTexInfo.mOfsTex);
            gKartNameTags->mEmblemTex[kartIndex] = emblemTex;
            gKartNameTags->mEmblemPltt[kartIndex] = emblemPltt;
        } else {
            emblemTex = gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mEmblemData;
            LoadNclrData(&nclr, GetKartModelFile("emblem_s_b.NCLR"));
            emblemPltt = nclr->mBytes;
            gKartNameTags->mEmblemTex[kartIndex] = emblemTex;
            gKartNameTags->mEmblemPltt[kartIndex] = emblemPltt;
        }
    }
}

void UploadKartEmblems(void) {
    u16 kartIndex;
    for (kartIndex = 0; (u32) kartIndex < gRaceSetup->mKartCount; kartIndex++) {
        UploadKartEmblem(kartIndex, gKartNameTags->mEmblemTex[kartIndex], gKartNameTags->mEmblemPltt[kartIndex]);
    }
}

// Replaces the pixels and palette of the kart_emblem texture of the model of kart a.
void UploadKartEmblem(u32 kartIndex, void *texData, void *plttData) {
    NNSG3dResMdl *kartModelResMdl;
    NNSG3dResMat *matBlock;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResMatData *material;
    s32 textureIndex;
    u32 texOffset;
    u32 plttOffset;
    kartModelResMdl = GetKartModelResMdl(kartIndex);
    textureIndex =
        NNS_G3dGetResDictIdxByName(&OFFSET_PTR(NNSG3dResMat, kartModelResMdl, kartModelResMdl->mOfsMat)->mDict,
                                   (const u32 *) gKartEmblemTextureName);
    matBlock = OFFSET_PTR(NNSG3dResMat, kartModelResMdl, kartModelResMdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &matBlock->mDict, matBlock->mDict.mOfsEntry);
    material = OFFSET_PTR(NNSG3dResMatData, matBlock, *DICT_ENTRY(u32, entries, textureIndex));
    texOffset = (material->mTexImageParam & 0xffff) << 3;
    plttOffset = material->mTexPlttBase << 4;
    DC_FlushRange(texData, KART_EMBLEM_TEX_BYTES);
    DC_FlushRange(plttData, KART_EMBLEM_PLTT_BYTES);
    GX_BeginLoadTex();
    GX_LoadTex(texData, texOffset, KART_EMBLEM_TEX_BYTES);
    GX_EndLoadTex();
    GX_BeginLoadTexPltt();
    GX_LoadTexPltt(plttData, plttOffset, 0x20);
    GX_EndLoadTexPltt();
}

void UploadTextureAndPalette(TexPlttEntry *texPlttEntry) {
    u16 texFormatBits;
    u32 texOffset;
    texFormatBits = texPlttEntry->mTexImageParam >> 26 & 7;
    texOffset = (NNS_GfdDefaultFuncAllocTexVram(texPlttEntry->mTexByteCount, 0, 0) & 0xffff) << 3;
    texPlttEntry->mTexImageParam = texPlttEntry->mTexImageParam & 0xffff0000;
    GX_BeginLoadTex();
    GX_LoadTex(texPlttEntry->mTexData, texOffset, texPlttEntry->mTexByteCount);
    GX_EndLoadTex();
    texPlttEntry->mTexImageParam = texPlttEntry->mTexImageParam | (texOffset >> 3 & 0xffff);
    if (texPlttEntry->mPlttByteCount != 0) {
        texPlttEntry->mPlttOffset =
            (NNS_GfdDefaultFuncAllocPlttVram(texPlttEntry->mPlttByteCount, texFormatBits == 2, 0) & 0xffff) << 3;
        GX_BeginLoadTexPltt();
        GX_LoadTexPltt(texPlttEntry->mPlttData, texPlttEntry->mPlttOffset, texPlttEntry->mPlttByteCount);
        GX_EndLoadTexPltt();
    }
    SetTextureSizeFromBits(texPlttEntry);
}

#pragma thumb off
