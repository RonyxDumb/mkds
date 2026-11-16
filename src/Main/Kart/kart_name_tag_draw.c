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
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Kart/kart_model_path.h"
#include "Main/Kart/kart_palette_stem_tables.h"
#include "Main/Graphics/animation_function_pointers.h"
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

const char g_str_kart_emblem[16] = "kart_emblem";
const u16 g_DefaultRacerIndicatorColors[8] = {0x280, 0x7d48, 0x35f, 0x1f, 0x48cc, 0x7ac0, 0x11be, 0x6c1b};

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

void CreateGlobalAED0_from_thumb(void) {
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
    heap = ExecutionContext_GetHeapHandle(GetActiveExecutionContext());
    if (g_GlobalCO->mMode == MODE_GRAND_PRIX) {
        isGrandPrix = TRUE;
    } else {
        isGrandPrix = FALSE;
    }
    g_GlobalAED0 = Mem_AllocateHeap(heap, sizeof(*g_GlobalAED0));
    g_GlobalAED0->mUnk_184 = 0;
    g_GlobalAED0->mEmblemPlttData = NULL;
    if (IsAwardOrStaffRoll_0() != 0) {
        g_GlobalAED0->mNameTagCount = 0;
    } else if (isGrandPrix == FALSE) {
        g_GlobalAED0->mNameTagCount = g_GlobalCO->mKartCount - 1;
        for (kartIndex = 0; (u32) kartIndex < g_GlobalCO->mKartCount; kartIndex++) {
            if (g_GlobalCO->mCurrentEntries[kartIndex].mPlayer.mKind == PLAYER_KIND_GHOST &&
                g_GlobalCO->mCurrentEntries[kartIndex].mPlayer.mGhostRecordIndex == GHOST_RECORD_INDEX_COURSE) {
                g_GlobalAED0->mNameTagCount = g_GlobalAED0->mNameTagCount - 1;
            }
        }
    } else {
        g_GlobalAED0->mNameTagCount = g_GlobalCO->mHumanAndPeerKartCount;
        entryIndex = g_GlobalCO->mEntryIndex;
        isEntryIndexHumanGhostOrPeer = FALSE;
        if (entryIndex != -1) {
            playerKind = GetCurrentEntry(entryIndex)->mPlayer.mKind;
            if (playerKind <= 3 && ((1 << playerKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) != 0) {
                isEntryIndexHumanGhostOrPeer = TRUE;
            }
            if (isEntryIndexHumanGhostOrPeer != FALSE) {
                g_GlobalAED0->mNameTagCount = g_GlobalAED0->mNameTagCount - 1;
            }
        }
    }
    gKartDistanceLimitsSquared = &gOtherCameraDistanceLimitsSquared;
    LoadEmblemDataInAED0_from_thumb();
    for (kartIndex = 0; (u32) kartIndex < g_GlobalCO->mKartCount; kartIndex++) {
        g_GlobalAED0->mStartOrderIndex[kartIndex] = kartIndex;
        g_GlobalAED0->mKartIndicesByDistanceAlongView[kartIndex] = kartIndex;
        g_GlobalAED0->mKartIndicesByDistance[kartIndex] = kartIndex;
        g_GlobalAED0->mAlongViewOrderOffset[kartIndex] = 0;
        g_GlobalAED0->mDistanceSquaredOrderOffset[kartIndex] = 0;
        g_GlobalAED0->mSortedDistanceAlongView[kartIndex] = 0;
        g_GlobalAED0->mSortedDistanceSquared[kartIndex] = 0;
        g_GlobalAED0->mAlongViewOrderIndex[kartIndex] = kartIndex;
        g_GlobalAED0->mKartIndicesByDistance[kartIndex] = kartIndex;
        g_GlobalAED0->mDistanceAlongViewWithMargin[kartIndex] = 0;
        g_GlobalAED0->mNameTagByKart[kartIndex] = NULL;
        g_GlobalAED0->mNameTagBeyondTwoNearest[kartIndex] = 0;
    }
    if (g_GlobalAED0->mNameTagCount > 0) {
        objectCount = 0;
        for (kartIndex = 0; (u32) kartIndex < g_GlobalCO->mKartCount; kartIndex++) {
            createsObject = FALSE;
            if (isGrandPrix == FALSE) {
                if (kartIndex != g_GlobalCO->mEntryIndex) {
                    if (g_GlobalCO->mCurrentEntries[kartIndex].mPlayer.mKind != PLAYER_KIND_GHOST ||
                        g_GlobalCO->mCurrentEntries[kartIndex].mPlayer.mGhostRecordIndex != GHOST_RECORD_INDEX_COURSE) {
                        createsObject = TRUE;
                    }
                }
            } else {
                isEntryHumanGhostOrPeer = FALSE;
                playerKind = g_GlobalCO->mCurrentEntries[kartIndex].mPlayer.mKind;
                if (playerKind <= 3 && ((1 << playerKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) != 0) {
                    isEntryHumanGhostOrPeer = TRUE;
                }
                if (isEntryHumanGhostOrPeer != FALSE && kartIndex != g_GlobalCO->mEntryIndex) {
                    createsObject = TRUE;
                }
            }
            if (createsObject != FALSE) {
                g_GlobalAED0->mNameTagByKart[kartIndex] =
                    Mem_AllocateHeap(heap, sizeof(*g_GlobalAED0->mNameTagByKart[kartIndex]));
                kartObject = g_GlobalAED0->mNameTagByKart[kartIndex];
                StructAER_SomeFn_from_thumb(kartObject, kartIndex, heap);
                g_GlobalAED0->mNameTags[objectCount] = kartObject;
                objectCount++;
            } else {
                g_GlobalAED0->mNameTagByKart[kartIndex] = NULL;
            }
        }
    }
    reg_G3_MTX_MODE = 0;
    G3i_OrthoW_(0x60000, 0xfffa0000, 0xfff80000, 0x80000, 0, 0x1000, 0x200, 1, &g_SomeMatrix4x4);
}

void StructAER_SomeFn_from_thumb(KartNameTag *kartObject, u16 kartIndex, void *heap) {
    kartObject->mTexPlttEntries = Mem_AllocateHeap(heap, sizeof(KartNameTagTexPlttEntries));
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

void StructAERSubSub_SomeFn_1_from_thumb(TexPlttEntry *texPlttEntry) {
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

u16 GetVsRacerIndicatorColor_from_thumb(int kartIndex) {
    if (g_GlobalCO->mMode == MODE_WIFI) {
        return g_NetRacerIndicatorColors[g_GlobalCO->mCurrentEntries[kartIndex].mPlayer.mRegion];
    }
    if (g_GlobalCO->mUseTeams != 0) {
        return g_TeamRacerIndicatorColors[g_GlobalCO->mCurrentEntries[kartIndex].mPlayer.mTeamIndex];
    }
    if (GetAD00SubRacer(kartIndex)->mCharacterIndex == CHARACTER_HEYHO) {
        return GetHeyhoColorPaletteDataForRacer_from_thumb(kartIndex)->mColor;
    }
    return g_DefaultRacerIndicatorColors[kartIndex];
}

void UploadKartNameTagTextures(void) {
    u16 nameTagIndex;
    void *heap;
    KartNameTag *kartObject;
    KartNameTagTexPlttEntries *texPlttEntries;
    TexPlttEntry *entryNameTexPltt;
    TexPlttEntry *fourthTexPltt;
    heap = ExecutionContext_GetHeapHandle(GetActiveExecutionContext());
    UploadKartEmblems();
    gKartNameTagsUnusedWord = 0;
    g_TempBuffer1_0x20 = Mem_AllocateHeapAligned(heap, 0x20, -4);
    g_TempBuffer2_0x100 = Mem_AllocateHeapAligned(heap, 0x100, -4);
    g_TempBuffer3_0x8 = Mem_AllocateHeapAligned(heap, 8, -4);
    g_TempBuffer4_0x200 = Mem_AllocateHeapAligned(heap, 0x200, -4);
    for (nameTagIndex = 0; nameTagIndex < g_GlobalAED0->mNameTagCount; nameTagIndex++) {
        kartObject = g_GlobalAED0->mNameTags[nameTagIndex];
        texPlttEntries = kartObject->mTexPlttEntries;
        entryNameTexPltt = &texPlttEntries->mEntries[1];
        fourthTexPltt = &texPlttEntries->mEntries[3];
        texPlttEntries->mEntries[0].mTexByteCount = KART_EMBLEM_TEX_BYTES;
        texPlttEntries->mEntries[0].mPlttByteCount = KART_EMBLEM_PLTT_BYTES;
        texPlttEntries->mEntries[0].mPlttData = g_GlobalAED0->mEmblemPlttData;
        kartObject->mKartPaletteColor = GetVsRacerIndicatorColor_from_thumb(kartObject->mKartIndex);
        StructAERSubSub_Fn1_Sub1_from_thumb(&texPlttEntries->mEntries[0], kartObject->mKartIndex);
        StructAERSubSub_Fn1_Sub2_from_thumb(entryNameTexPltt, kartObject->mKartIndex);
        StructAERSubSub_Fn1_Sub3_from_thumb(&texPlttEntries->mEntries[2], kartObject->mKartIndex);
        StructAERSubSub_Fn1_Sub4_from_thumb(fourthTexPltt, kartObject->mKartIndex);
        StructAERSubSub_SomeFn_from_thumb(&texPlttEntries->mEntries[0]);
        StructAERSubSub_SomeFn_from_thumb(entryNameTexPltt);
        StructAERSubSub_SomeFn_from_thumb(&kartObject->mTexPlttEntries->mEntries[2]);
        if (fourthTexPltt->mTexData != NULL) {
            StructAERSubSub_SomeFn_from_thumb(fourthTexPltt);
        }
    }
    Mem_FreeHeap(heap, g_TempBuffer4_0x200);
    Mem_FreeHeap(heap, g_TempBuffer3_0x8);
    Mem_FreeHeap(heap, g_TempBuffer2_0x100);
    Mem_FreeHeap(heap, g_TempBuffer1_0x20);
}

void StructAERSubSub_Fn1_Sub1_from_thumb(TexPlttEntry *texPlttEntry, u16 kartIndex) {
    u16 *plttBuffer;
    void *emblemTex;
    u16 firstColor;
    plttBuffer = g_TempBuffer1_0x20;
    emblemTex = g_GlobalAED0->mEmblemTex[kartIndex];
    Mem_CpuCopy8(g_GlobalAED0->mEmblemPltt[kartIndex], plttBuffer, texPlttEntry->mPlttByteCount);
    firstColor = 0x7fff;
    if (g_GlobalCO->mUseTeams != 0) {
        firstColor = g_TeamRacerIndicatorColors[g_GlobalCO->mCurrentEntries[kartIndex].mPlayer.mTeamIndex];
    }
    *plttBuffer = firstColor;
    Arm_FlushRange(plttBuffer, texPlttEntry->mPlttByteCount);
    Arm_FlushRange(emblemTex, texPlttEntry->mTexByteCount);
    texPlttEntry->mPlttData = plttBuffer;
    texPlttEntry->mTexData = emblemTex;
}

#pragma thumb off

#pragma thumb on

void StructAERSubSub_Fn1_Sub2_from_thumb(TexPlttEntry *texPlttEntry, u32 kartIndex) {
    u16 kartPaletteColor;
    u16 *plttBuffer;
    u8 *texBuffer;
    texBuffer = g_TempBuffer2_0x100;
    plttBuffer = g_TempBuffer3_0x8;
    *plttBuffer = (0x00007c00u);
    kartPaletteColor = GetVsRacerIndicatorColor_from_thumb(kartIndex);
    plttBuffer[1] = kartPaletteColor;
    plttBuffer[2] = 0;
    plttBuffer[3] = 0x1f;
    Arm_FlushRange(plttBuffer, 8);
    Mem_CpuFill8(texBuffer, 0, texPlttEntry->mTexByteCount);
    RenderKartEntryNameToTexture(kartIndex, texBuffer, 1, 2);
    Arm_FlushRange(texBuffer, 0x100);
    texPlttEntry->mTexData = texBuffer;
    texPlttEntry->mPlttData = plttBuffer;
}

void StructAERSubSub_Fn1_Sub3_from_thumb(TexPlttEntry *texPlttEntry, u32 kartIndex) {
    u16 kartPaletteColor;
    u16 *plttData;
    plttData = texPlttEntry->mPlttData;
    kartPaletteColor = GetVsRacerIndicatorColor_from_thumb(kartIndex);
    plttData[1] = kartPaletteColor;
    Arm_FlushRange(plttData, 8);
}

#pragma thumb off

#pragma thumb on

void StructAERSubSub_Fn1_Sub4_from_thumb(TexPlttEntry *texPlttEntry, u16 kartIndex) {
    u8 *pixels;
    s32 nibbleLimit;
    u32 pixelIndex;
    TexPlttEntry *texPlttEntryAlias;
    u8 pixelPair;
    u32 highNibbleBits;
    u8 highNibble;
    u8 lowNibble;
    texPlttEntryAlias = texPlttEntry;
    if (g_GlobalCO->mCurrentEntries[kartIndex].mPlayer.mLowestGrandPrixRecordValue != 0) {
        pixels = g_TempBuffer4_0x200;
        nibbleLimit = 7;
        switch (g_GlobalCO->mCurrentEntries[kartIndex].mPlayer.mLowestGrandPrixRecordValue) {
            case GP_LOWEST_RECORD_SECOND_BEST:
                nibbleLimit = 4;
                break;
            case GP_LOWEST_RECORD_BEST:
                nibbleLimit = -1;
                break;
        }
        Mem_CpuCopy8(texPlttEntryAlias->mTexData, pixels, texPlttEntryAlias->mTexByteCount);
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
        Arm_FlushRange(pixels, texPlttEntryAlias->mTexByteCount);
        texPlttEntryAlias->mTexData = pixels;
    } else {
        texPlttEntryAlias->mTexData = NULL;
    }
}

void LoadEmblemDataInAED0_from_thumb(void) {
    u16 kartIndex;
    Nclr *nclr;
    NNSG3dResTex *texture;
    char *path;
    u8 *emblemPltt;
    u8 *emblemTex;
    for (kartIndex = 0; (u32) kartIndex < g_GlobalCO->mKartCount; kartIndex++) {
        g_GlobalAED0->mEmblemTex[kartIndex] = NULL;
        g_GlobalAED0->mEmblemPltt[kartIndex] = NULL;
        if (g_GlobalCO->mCurrentEntries[kartIndex].mPlayer.mHasEmblem == 0 || g_GlobalCO->mUseTeams != 0) {
            if (g_GlobalCO->mUseTeams != 0) {
                path = FormatTeamEmblemNsbtx(g_GlobalCO->mCurrentEntries[kartIndex].mPlayer.mTeamIndex == 1 ? 1 : 0);
            } else {
                path = FormatEmblemNsbtx(g_GlobalCO->mCurrentEntries[kartIndex].mCharacterIndex);
            }
            texture = Nsbtx_GetTEX0Block(FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb(path));
            emblemPltt = OFFSET_PTR(u8, texture, texture->mPlttInfo.mOfsPlttData);
            emblemTex = OFFSET_PTR(u8, texture, texture->mTexInfo.mOfsTex);
            g_GlobalAED0->mEmblemTex[kartIndex] = emblemTex;
            g_GlobalAED0->mEmblemPltt[kartIndex] = emblemPltt;
        } else {
            emblemTex = g_GlobalCO->mCurrentEntries[kartIndex].mPlayer.mEmblemData;
            Gfx_ReadPalette(&nclr, FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb("emblem_s_b.NCLR"));
            emblemPltt = nclr->mBytes;
            g_GlobalAED0->mEmblemTex[kartIndex] = emblemTex;
            g_GlobalAED0->mEmblemPltt[kartIndex] = emblemPltt;
        }
    }
}

void UploadKartEmblems(void) {
    u16 kartIndex;
    for (kartIndex = 0; (u32) kartIndex < g_GlobalCO->mKartCount; kartIndex++) {
        UploadKartEmblem(kartIndex, g_GlobalAED0->mEmblemTex[kartIndex], g_GlobalAED0->mEmblemPltt[kartIndex]);
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
    kartModelResMdl = GetCharacterKartModel(kartIndex);
    textureIndex =
        Dict_SomeFn_0(&OFFSET_PTR(NNSG3dResMat, kartModelResMdl, kartModelResMdl->mOfsMat)->mDict,
                                   (const u32 *) g_str_kart_emblem);
    matBlock = OFFSET_PTR(NNSG3dResMat, kartModelResMdl, kartModelResMdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &matBlock->mDict, matBlock->mDict.mOfsEntry);
    material = OFFSET_PTR(NNSG3dResMatData, matBlock, *DICT_ENTRY(u32, entries, textureIndex));
    texOffset = (material->mTexImageParam & 0xffff) << 3;
    plttOffset = material->mTexPlttBase << 4;
    Arm_FlushRange(texData, KART_EMBLEM_TEX_BYTES);
    Arm_FlushRange(plttData, KART_EMBLEM_PLTT_BYTES);
    GX_BeginLoadTex();
    GX_LoadTex(texData, texOffset, KART_EMBLEM_TEX_BYTES);
    GX_EndLoadTex();
    GX_BeginLoadTexPltt();
    SomeDmaCopy_0(plttData, plttOffset, 0x20);
    GX_EndLoadTexPltt();
}

void StructAERSubSub_SomeFn_from_thumb(TexPlttEntry *texPlttEntry) {
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
        SomeDmaCopy_0(texPlttEntry->mPlttData, texPlttEntry->mPlttOffset, texPlttEntry->mPlttByteCount);
        GX_EndLoadTexPltt();
    }
    StructAERSubSub_SomeFn_1_from_thumb(texPlttEntry);
}

#pragma thumb off
