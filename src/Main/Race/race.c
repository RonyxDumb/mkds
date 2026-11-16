#include "Main/Race/race.h"

#include "Main/Save/course_time_record.h"
#include "Main/Kart/kart_scale_surface_tables.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "cpu_copy_fill.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Race/race_clock.h"
#include "Main/Kart/karts.h"
#include "Main/Kart/course_models.h"
#include "Main/System/heap.h"
#include "registers.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Kart/camera.h"
#include "Main/Kart/kart_model_menu.h"
#include "ITCM/model_draw_and_irq_handler.h"
#include "ITCM/collision_slots.h"
#include "Main/Kart/kart_call.h"
#include "Main/Race/race_progress_kart.h"
#include "Main/Kart/kart_ai_item_throw.h"
#include "sound_archive_load.h"
#include "Main/Graphics/model_effects.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Course/course_map_group_entry.h"
#include "animation_lookup.h"
#include "Main/Kart/shadow_model_draw.h"
#include "Main/System/heap_call.h"
#include "Main/Race/entry_race_ended.h"
#include "Main/Kart/camera_entry.h"
#include "Main/Kart/camera_entry_flags.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Kart/kart_ai.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/Kart/kart_name_tag_draw.h"
#include "Main/Kart/kart_model_path.h"
#include "Main/Graphics/stem_set_array.h"
#include "Main/Graphics/effects.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "Main/Graphics/res_file_entries_reset.h"
#include "Main/Race/race_progress_lap.h"
#include "fixed_vector_math.h"
#include "Main/Net/wifi_race_sync_advance.h"
#include "Main/Race/standings_balloons.h"
#include "Main/Race/race_hud_draw.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object_create.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/rock.h"
#include "Main/MapObjects/attractor.h"
#include "Main/MapObjects/jg.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Item/item_link_following.h"
#include "Main/Item/bouncing_item_box.h"
#include "vram_bank_display_setup.h"
#include "geometry_render_state.h"
#include "model_draw_state.h"
#include "geometry_function_tables_and_fast_dma.h"
#include "Main/System/result_archive_path.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Menu/menu_screens_work.h"
#include "sound_player_control.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "frame_texture_vram_alloc.h"
#include "frame_palette_vram_alloc.h"
#include "geometry_engine_setup.h"
#include "Main/Course/course_map_sections.h"
#include "01/Race/mission_run_state.h"
#include "Main/Race/kart_standing_rank.h"
#include "Main/Net/wifi_session.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

s16 gToonTableFramesLimit = 2;
u16 gFadeFogRemaining = 0x48;
Vec3 g_SomeTDVector = {0, -4095, 0};
const u16 gToonTableFirstColors[8] = {0x35bf, 0x36df, 0x37ff, 0x37ed, 0x7fed, 0x7ecd, 0x7dad, 0x7dbf};
const u16 gToonTableSecondColors[8] = {0x4e73, 0x56b5, 0x5ef7, 0x6739, 0x6f7b, 0x7fff, 0x7fff, 0x7fff};
u16 g_AnotherFogColor;
s16 gCourseFogGreen;
u16 g_YetAnotherFogColor;
s16 gCourseFogBlue;
s16 gCourseFogRed;
u16 gFadeFogHoldFrames;
u16 g_SomeFogColor;
Camera *g_GlobalHD3;
MtxFx43 *g_SomeMatrix4x3;
s32 gFadeFogActive;
Camera *g_YetAnotherGlobalHD;
s32 gCourseFogLastEntry;
s32 g_AnotherFogOffset;
s32 gFadeFogByteBoost;
Race *g_GlobalTD;
s32 gCourseFogWeight;
s32 g_SomeFogDepthShift;
s32 gFadeFogWeight;
s32 gFadeFogAlpha;
s32 g_SomeFogAlpha;
Camera *g_GlobalHD4;
s32 g_SomeFogOffset;
void *g_GlobalDTT;
s32 g_AnotherFogAlpha;
s32 gFadeFogStepping;
u32 gFadeFogEntryBytes[4];
u32 g_FogTable1[8];
u32 g_FogTable2[8];
u16 gToonTable[32];

u32 IsNotStaffRoll(void) {
    return (g_GlobalTD->mUseChainCameras);
}

u32 IsAwardOrStaffRoll_0(void) {
    return (g_GlobalTD->mIsAwardOrStaffRoll);
}

// Builds the race world and g_GlobalTD. Not part of it: the screen and 3D engine set-up (Init3dEngine, called before), the
// net and the HUD, which are in the scene slot Scene_Race_Initialize.
void InitializeGlobalTD(void) {
    void *heap;
    u16 texBankMask;
    s16 index;
    u16 stripIndex;

    heap = ExecutionContext_GetHeapHandle(GetActiveExecutionContext());
    SetCurrentlyInKartModelMenu(0);
    g_GlobalTD = Mem_AllocateHeap(heap, 72);
    CreateGlobalTD();
    texBankMask = GX_GetBankForTex();
    NNS_GfdInitFrmTexVramManager(
        ((texBankMask >> 3) & 1) + ((texBankMask >> 2) & 1) + ((texBankMask >> 1) & 1) + (texBankMask & 1), 1);
    NNS_GfdInitFrmPlttVramManager(0x10000, 1);
    InitializeLoadedModelTextureList();
    InitCameraGlobals();
    SetActiveExecutionContextHeapGroupId_from_thumb(1);
    CreateGlobalAED0_from_thumb();
    InitializeGlobalAD00_from_thumb(heap, g_GlobalCO->mKartCount);
    CopyDefaultHeyhoColorPalettes_from_thumb();
    UploadKartNameTagTextures();
    Dispose_KM2_KSB_Mount_CRS_from_thumb();
    LoadMap2DStuff();
    SetActiveExecutionContextHeapGroupId_from_thumb(2);
    LoadCourseMapNkm_from_thumb(heap);
    LoadCourseModelsAnimations(heap);
    Dispose_CST_Mount_K2D_R2D_MAR_from_thumb();
    SetActiveExecutionContextHeapGroupId_from_thumb(7);
    InitializeGlobalMV(heap);
    InitializeGlobalAA(heap);
    SetActiveExecutionContextHeapGroupId_from_thumb(2);
    LoadCourseKcl_from_thumb();
    SetActiveExecutionContextHeapGroupId_from_thumb(8);
    AllocateSomePointers();
    SetActiveExecutionContextHeapGroupId_from_thumb(1);
    CreateGlobalBO(heap);
    CreateGlobalAEBC_from_thumb();
    CreateGlobalMQAndRK(g_GlobalCO->mKartCount);
    CreateGlobalHD5_from_thumb();
    CreateAnotherGlobalHD_from_thumb(g_GlobalCO->mFollowedKartIndex);
    if (g_GlobalTD->mUseChainCameras != 0) {
        if (g_GlobalTD->mUseFirstChainCamera != 0) {
            CreateGlobalHD_HD2_from_thumb();
        } else {
            CreateGlobalHD_HD2_V2_from_thumb();
        }
    }
    g_GlobalHD3 = GetGlobalHD5();
    g_YetAnotherGlobalHD = GetAnotherGlobalHD();
    g_GlobalHD4 = g_GlobalHD3;
    g_SomeMatrix4x3 = &g_GlobalHD3->mViewMatrix;
    StructHD_SomeFn_2(g_GlobalHD3);
    SetActiveExecutionContextHeapGroupId_from_thumb(3);
    switch (g_GlobalCO->mMode) {
        case MODE_BATTLE:
            InitStandings();
            break;
        case MODE_MISSION_RUN:
            if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
                CreateMissionRunData();
            }
            if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
                InitStandings();
            }
            break;
    }
    SetActiveExecutionContextHeapGroupId_from_thumb(3);
    CreateJg();
    InitJg();
    InitMapObjects();
    MaybeLoadSlotListAndRacerPrs_from_thumb();
    SetActiveExecutionContextHeapGroupId_from_thumb(6);
    SomeEffectFileStuff(heap);
    InitKartEffectTables(heap);
    LoadEffectMapObjModels(heap);
    InitPosStrips(heap);
    SetActiveExecutionContextHeapGroupId_from_thumb(9);
    *HW_BG_PLTT = 0xff00;
    reg_G3X_DISP3DCNT =
        reg_G3X_DISP3DCNT & ~(REG_G3X_DISP3DCNT_GO_MASK | REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_THS_MASK);
    G3X_SetToonTable(gToonTable);
    for (index = 0; index < 8; index++) {
        gToonTable[index] = gToonTableFirstColors[index];
        gToonTable[index + 16] = gToonTableSecondColors[index];
    }
    for (index = 0; index < 8; index++) {
        gToonTable[index + 8] = gToonTable[index];
        gToonTable[index + 24] = gToonTable[index + 16];
    }
    InitRaceFog();
    SetKoopaCourseLight2();
    if (g_GlobalCO->mRaceKind == RACE_KIND_AWARD) {
        for (stripIndex = 0; stripIndex < 3; stripIndex++) {
            StartAwardKartPosStrip(stripIndex);
        }
    }
}

void CreateGlobalTD(void) {
    Vec3 lightVector;
    s32 unusedValue;

    g_GlobalTD->mUpdateFrames = 0;
    g_GlobalTD->mDrawFrames = 0;
    g_GlobalTD->mUpdateFramesModKartCount = 0;
    g_GlobalTD->mUpdateFramesMod2 = 0;
    g_GlobalTD->mUpdateFramesMod8 = 0;
    g_GlobalTD->mToonTableOffset = 0;
    g_GlobalTD->mToonTableFrames = 0;
    g_GlobalTD->mUpdateFramesLimitReached = FALSE;
    g_GlobalTD->mUpdateFramesUnlimited = FALSE;
    g_GlobalTD->mUpdateFramesAtEntryEnd = 0;
    lightVector = g_SomeTDVector;
    g_GlobalTD->mLightVectorX = lightVector.x;
    g_GlobalTD->mLightVectorY = lightVector.y;
    g_GlobalTD->mLightVectorZ = lightVector.z;
    g_GlobalTD->mUseChainCameras = (g_GlobalCO->mRaceKind - 3) <= 2 ? 1 : 0;
    g_GlobalTD->mUseFirstChainCamera = g_GlobalCO->mRaceKind == RACE_KIND_START_BATTLE ? 1 : 0;
    g_GlobalTD->mIsAwardOrStaffRoll =
        (g_GlobalCO->mRaceKind == RACE_KIND_AWARD || g_GlobalCO->mRaceKind == RACE_KIND_STAFF_ROLL) != 0 ? 1 : 0;
    g_GlobalTD->mStarted = g_GlobalTD->mIsAwardOrStaffRoll != 0 ? 1 : 0;
}

void InitFrmVramManagers(void) {
    u16 texBankMask;

    texBankMask = GX_GetBankForTex();
    NNS_GfdInitFrmTexVramManager(
        ((texBankMask >> 3) & 1) + ((texBankMask >> 2) & 1) + ((texBankMask >> 1) & 1) + (texBankMask & 1), 1);
    NNS_GfdInitFrmPlttVramManager(0x10000, 1);
    InitializeLoadedModelTextureList();
}

// Bytes of the geometry command buffer: the word count and 192 words.
#define RACE_GE_BUFFER_BYTES 772

void Init3dEngine(void) {
    NNS_G3dInit();
    NNS_G3dGlbInit();
    NNS_G3dGeReleaseBuffer();
    NNS_G3dGeUseFastDma(1);
    g_GlobalP->mUnk_1c |= STARTUP_FLAG_FAST_DMA;
    NNS_G3dGlbLightVector(0, 0, -0x1000, 0);
    NNS_G3dGlbLightVector(1, 0x93d, 0x93d, 0x93d);
    NNS_G3dGlbLightVector(2, 0, -0x1000, 0);
    NNS_G3dGlbLightVector(3, 0, 0xfff, 0);
    NNS_G3dGlbLightColor(0, 0x7fff);
    NNS_G3dGlbLightColor(1, 0x6318);
    NNS_G3dGlbLightColor(2, 31);
    NNS_G3dGlbLightColor(3, 0x3ff);
    NNS_G3dGlbMaterialColorDiffAmb(0x5294, 0x5294, 0);
    NNS_G3dGlbMaterialColorSpecEmi(0, 0, 1);
    NNS_G3dGlbPolygonAttr(15, 0, 2, 0, 31, 0);
    g_GlobalDTT = Mem_AllocateHeap(g_GlobalP->mHeap, RACE_GE_BUFFER_BYTES);
    NNS_G3dGeSetBuffer(g_GlobalDTT);
}

// Advances the race one frame. Skipped while IsDataSharingIncomplete or Struct5624_HasXflag1 refuse (the draw is not),
// and in kind 6 for the first 0x708 frames (neither update nor draw). The HUD step and the end-of-race state are in the
// scene slot Scene_Race_Update, which calls this; the CheckZetaInvokeBeta loop also runs it with a == NULL.
void UpdateRace(void) {
    void *viewMatrix;

    gExpireWhileRequestedSounds = 1;
    UpdateCollisionSlotBounds();
    HandleCourseAnim();
    UpdateKarts();
    if (g_GlobalTD->mUpdateFramesMod8 == 0) {
        UpdateKartAiShared();
    }
    switch (g_GlobalCO->mMode) {
        case MODE_BATTLE:
            UpdateStandings();
            break;
        case MODE_MISSION_RUN:
            if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
                UpdateMissionRunData();
            }
            if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
                UpdateStandings();
            }
            break;
    }
    ClearCameraEntryFlags();
    if (g_GlobalTD->mUseChainCameras != 0) {
        if (g_GlobalTD->mUseFirstChainCamera != 0) {
            viewMatrix = SomeLookAtHD3();
        } else {
            viewMatrix = SomeLookAtHD_HD2();
        }
        g_SomeMatrix4x3 = viewMatrix;
        g_GlobalHD4 = GetCurrentChainCamera();
    } else if (GetEntryRaceEnded() != 0) {
        StructHD_SomeMQFn(g_GlobalHD3, GetRacerMQEntry(g_GlobalCO->mFollowedKartIndex));
        StructHD_SomeLookAt(g_GlobalHD3);
        if (StructHD_SomeFn_7(g_YetAnotherGlobalHD) != 0) {
            g_GlobalHD4 = g_YetAnotherGlobalHD;
            g_SomeMatrix4x3 = &g_YetAnotherGlobalHD->mViewMatrix;
        } else {
            g_GlobalHD4 = g_GlobalHD3;
            g_SomeMatrix4x3 = &g_GlobalHD3->mViewMatrix;
        }
    } else {
        StructHD_SomeMQFn(g_GlobalHD3, GetRacerMQEntry(g_GlobalCO->mEntryIndex));
        StructHD_SomeLookAt(g_GlobalHD3);
        g_GlobalHD4 = g_GlobalHD3;
        g_SomeMatrix4x3 = &g_GlobalHD3->mViewMatrix;
    }
    StructHD_SomeFn_2(g_GlobalHD4);
    UpdateViewFrustum(g_SomeMatrix4x3);
    if (GetCameraEntryChanged() != 0) {
        RequestViewTestRefresh();
    }
    UpdateItems();
    UpdateJg();
    UpdateMapObjects();
    UpdateExplosionInstances();
    UpdatePosStrips();
    UpdateEffects();
    if (gFadeFogActive != 0) {
        if (gFadeFogStepping != 0) {
            if (gFadeFogRemaining == 0) {
                g_GlobalTD->mFadeFog = 0;
                SetKartModelsFogEnable(1);
                SetCourseModelsFogEnableFlags(0);
                gFadeFogActive = 0;
                gFadeFogStepping = 0;
            } else {
                BuildFadeFog(gFadeFogRemaining, 0);
            }
            gFadeFogRemaining -= 4;
        } else {
            gFadeFogHoldFrames++;
            if (gFadeFogHoldFrames >= 72) {
                gFadeFogStepping = 1;
            }
        }
    }
    UpdateStemSets();
    UpdateRaceProgress();
    UpdateKartSoundDistancesSquared();
    UpdateKartNameTags();
    if (g_GlobalCO->mMode == MODE_WIFI) {
        if (g_GlobalTD->mUpdateFramesUnlimited == FALSE) {
            if (g_GlobalTD->mUpdateFramesLimitReached == FALSE) {
                g_GlobalTD->mUpdateFrames++;
                if ((u32) g_GlobalTD->mUpdateFrames >= RACE_WIFI_UPDATE_FRAMES_LIMIT) {
                    g_GlobalTD->mUpdateFramesLimitReached = TRUE;
                }
            }
        } else {
            g_GlobalTD->mUpdateFrames++;
        }
    } else {
        g_GlobalTD->mUpdateFrames++;
    }
    g_GlobalTD->mUpdateFramesMod8 = g_GlobalTD->mUpdateFrames & 7;
    g_GlobalTD->mUpdateFramesMod2 = g_GlobalTD->mUpdateFrames & 1;
    g_GlobalTD->mUpdateFramesModKartCount = (u32) g_GlobalTD->mUpdateFrames % g_GlobalCO->mKartCount;
    G3X_SetToonTable(&gToonTable[g_GlobalTD->mToonTableOffset]);
    g_GlobalTD->mToonTableFrames++;
    if ((u32) g_GlobalTD->mToonTableFrames > gToonTableFramesLimit) {
        g_GlobalTD->mToonTableFrames = 0;
        g_GlobalTD->mToonTableOffset++;
    }
    if ((u32) g_GlobalTD->mToonTableOffset > 7) {
        g_GlobalTD->mToonTableOffset = 0;
    }
}

// Draws the 3D scene and writes the fog registers when the fade state changes; advances no game value. Has its own gate
// in the scene slot; the HUD draw is in the scene slot too.
void RaceRenderingFogRelated(void) {
    if (gFadeFogStepping != 0) {
        G3X_SetFog(1, 0, g_SomeFogDepthShift, g_SomeFogOffset);
        G3X_SetFogTable(g_FogTable2);
        reg_G3X_FOG_COLOR = g_YetAnotherFogColor | (gFadeFogAlpha << 16);
    } else if (g_GlobalTD->mFadeFog != g_GlobalTD->mDrawnFadeFog) {
        if (g_GlobalTD->mFadeFog == 0) {
            if (g_GlobalPE->mSettings->mFogEnabled != 0) {
                G3X_SetFog(1, 0, g_SomeFogDepthShift, g_AnotherFogOffset);
                reg_G3X_FOG_COLOR = g_SomeFogColor | (g_AnotherFogAlpha << 16);
                G3X_SetFogTable(g_FogTable1);
            } else {
                G3X_SetFog(0, 0, 5, 0);
            }
        } else {
            G3X_SetFog(1, 0, g_SomeFogDepthShift, 0);
            reg_G3X_FOG_COLOR = g_AnotherFogColor | (g_SomeFogAlpha << 16);
            G3X_SetFogTable(g_FogTable2);
        }
    }
    g_GlobalTD->mDrawnFadeFog = g_GlobalTD->mFadeFog;
    DrawRaceWorld();
    DrawEffects(g_SomeMatrix4x3);
    DrawPosStrips(g_SomeMatrix4x3);
    DrawStemSets();
    if (g_GlobalTD->mUseChainCameras == 0) {
        DrawKartNameTags(g_SomeMatrix4x3);
    }
    DrawOrthoQuads();
    g_GlobalTD->mDrawFrames++;
}

void SetSomeTDVector(const Vec3 *lightVector) {
    g_GlobalTD->mLightVectorX = lightVector->x;
    g_GlobalTD->mLightVectorY = lightVector->y;
    g_GlobalTD->mLightVectorZ = lightVector->z;
}

void DrawRaceWorld(void) {
    Vec3 lightVector;
    Vec3 cameraUp;
    Vec3 cameraForward;
    u32 commandValue;
    Camera *currentCamera;

    ApplyCameraFrustum(g_GlobalHD4, 1);
    ApplyCameraLookAt(g_GlobalHD4);
    currentCamera = g_GlobalHD4;
    NNS_G3dGlbLightVector(0, g_GlobalTD->mLightVectorX, g_GlobalTD->mLightVectorY, g_GlobalTD->mLightVectorZ);
    NNS_G3dGlbLightColor(0, 0x7fff);
    cameraUp.x = currentCamera->mViewMatrix.mRows[0].y;
    cameraUp.y = currentCamera->mViewMatrix.mRows[1].y;
    cameraUp.z = currentCamera->mViewMatrix.mRows[2].y;
    cameraForward.x = -currentCamera->mViewMatrix.mRows[0].z;
    cameraForward.y = -currentCamera->mViewMatrix.mRows[1].z;
    cameraForward.z = -currentCamera->mViewMatrix.mRows[2].z;
    VecFx32_Subtract(&cameraForward, &cameraUp, &lightVector);
    if (SQUARE_SUM3(lightVector.x, lightVector.y, lightVector.z) >=
        16) {
        Vector3_MaybeNormalize(&lightVector, &lightVector);
    }
    NNS_G3dGlbLightVector(1, (s16) lightVector.x, (s16) lightVector.y, (s16) lightVector.z);
    NNS_G3dGlbLightColor(1, 0x7fff);
    NNS_G3dGlbFlushP();
    NNS_G3dGeBufferOP_N(23, g_SomeMatrix4x3, 12);
    commandValue = 30;
    NNS_G3dGeBufferOP_N(19, &commandValue, 1);
    DrawCourseModelV();
    ApplyCameraFrustum(g_GlobalHD4, 0);
    NNS_G3dGlbFlushP();
    NNS_G3dGeSetBuffer(g_GlobalDTT);
    DrawCourseModel();
    DrawKoopaBlocksRotariesAndBridges(g_GlobalHD4);
    NNS_G3dGeReleaseBuffer();
    DrawKarts();
    NNS_G3dGlbLightVector(0, g_GlobalTD->mLightVectorX, g_GlobalTD->mLightVectorY, g_GlobalTD->mLightVectorZ);
    DrawJg();
    DrawMapObjects(g_GlobalHD4);
    DrawItems(g_SomeMatrix4x3);
    DrawModelEffects();
    NNS_G3dGeFlushBuffer();
}

void ResetAA(void) {
    WiFiSession *wiFiSession;
    BOOL heapCreated;

    ClearMapObjectListSlots();
    ResetGlobalMQ();
    MaybeDisposeLoadedModelTextures();
    StopRaceInput();
    heapCreated = FALSE;
    wiFiSession = g_GlobalB;
    if (wiFiSession != NULL && wiFiSession->mHeapCreated != FALSE) {
        heapCreated = TRUE;
    }
    if (heapCreated != FALSE) {
        wiFiSession->mKartMask = g_GlobalAA->mParticipantMask;
    }
    g_GlobalAA = NULL;
}

void nullsub_6(void) {}

u32 IsAwardOrStaffRoll(void) {
    return (g_GlobalTD->mStarted);
}

void StartRace(void) {
    g_GlobalTD->mStarted = 1;
    StartRaceClock();
}

u32 GetSomeTimeOrDuration(void) {
    return (g_GlobalTD->mUpdateFrames);
}

u32 GetRaceUpdateFramesModKartCount(void) {
    return (g_GlobalTD->mUpdateFramesModKartCount);
}

u32 GetRaceUpdateFramesMod8(void) {
    return (g_GlobalTD->mUpdateFramesMod8);
}

u32 GetRaceUpdateFramesMod2(void) {
    return (g_GlobalTD->mUpdateFramesMod2);
}

// Also writes the fog color register directly, sets the fog offset and table through G3X_SetFog and
// G3X_SetFogTable, and resets the fade state.
void InitRaceFog(void) {
    u32 fogCurve[32];
    u16 index;
    u8 fogTableMode;

    BuildFadeFog(72, 1);
    gFadeFogRemaining = 72;
    gFadeFogStepping = 0;
    gFadeFogActive = 0;
    gFadeFogHoldFrames = 0;
    g_GlobalTD->mDrawnFadeFog = 0;
    g_GlobalTD->mFadeFog = g_GlobalTD->mDrawnFadeFog;
    if (g_GlobalPE->mSettings->mFogEnabled != 0) {
        fogTableMode = g_GlobalPE->mSettings->mFogTableMode;
        if (fogTableMode == 0) {
            for (index = 0; index < 8; index++) {
                g_FogTable1[index] =
                    ((index * 4) << 2) | ((index * 16 + 4) << 8) | ((index * 16 + 8) << 16) | ((index * 16 + 12) << 24);
            }
        } else if (fogTableMode == 1) {
            for (index = 0; index < 32; index++) {
                fogCurve[index] = ((index + 1) * (index + 1)) / 8;
                if (fogCurve[index] > 127) {
                    fogCurve[index] = 127;
                }
            }
            fogCurve[0] = 0;
            for (index = 0; index < 8; index++) {
                g_FogTable1[index] = fogCurve[index * 4] | (fogCurve[index * 4 + 1] << 8) |
                                         (fogCurve[index * 4 + 2] << 16) | (fogCurve[index * 4 + 3] << 24);
            }
        } else if (fogTableMode == 2) {
            for (index = 0; index < 32; index++) {
                fogCurve[index] = 128 - ((32 - (index + 1)) * (32 - (index + 1))) / 8;
                if (fogCurve[index] > 127) {
                    fogCurve[index] = 127;
                }
            }
            fogCurve[0] = 0;
            for (index = 0; index < 8; index++) {
                g_FogTable1[index] = fogCurve[index * 4] | (fogCurve[index * 4 + 1] << 8) |
                                         (fogCurve[index * 4 + 2] << 16) | (fogCurve[index * 4 + 3] << 24);
            }
        }
        g_SomeFogColor = g_GlobalPE->mSettings->mColorAndFogAlpha & COLOR15_MASK;
        g_AnotherFogAlpha = ((u32) g_GlobalPE->mSettings->mColorAndFogAlpha >> 15) & 31;
        g_SomeFogDepthShift = g_GlobalPE->mSettings->mFogSlope;
        g_AnotherFogOffset = g_GlobalPE->mSettings->mFogOffset / 512;
        gCourseFogRed = g_SomeFogColor & 31;
        gCourseFogGreen = (g_SomeFogColor >> 5) & 31;
        gCourseFogBlue = (g_SomeFogColor >> 10) & 31;
    }
    if (g_GlobalPE->mSettings->mFogEnabled != 0) {
        G3X_SetFog(1, 0, g_SomeFogDepthShift, g_AnotherFogOffset);
        reg_G3X_FOG_COLOR = g_SomeFogColor | (g_AnotherFogAlpha << 16);
        G3X_SetFogTable(g_FogTable1);
    } else {
        G3X_SetFog(0, 0, 5, 0);
    }
}

void BuildFadeFog(s32 fadeLevel, s32 flag) {
    s32 fadeWeight;
    s32 courseWeight;
    u32 byteIndex;
    u32 tableEntry;
    u16 index;
    s32 fogByte;

    if (g_GlobalPE->mSettings->mFogEnabled != 0 && flag == 0) {
        fadeWeight = MUL_FIXED12_ROUNDED(57, TO_FIXED12(fadeLevel));
        gFadeFogWeight = fadeWeight;
        courseWeight = 4096 - fadeWeight;
        gCourseFogWeight = courseWeight;
        gFadeFogByteBoost = MUL_FIXED12_ROUNDED(fadeWeight, 72);
        g_YetAnotherFogColor = MUL_FIXED12_ROUNDED(gCourseFogRed, courseWeight) +
                        (MUL_FIXED12_ROUNDED(gCourseFogGreen, courseWeight) << 5) +
                        (MUL_FIXED12_ROUNDED(gCourseFogBlue, courseWeight) << 10);
        gFadeFogAlpha =
            MUL_FIXED12_ROUNDED(courseWeight, g_AnotherFogAlpha) + MUL_FIXED12_ROUNDED(fadeWeight, g_SomeFogAlpha);
        g_SomeFogOffset = MUL_FIXED12_ROUNDED(courseWeight, g_AnotherFogOffset);
        for (index = 0; index < 8; index++) {
            tableEntry = g_FogTable1[index];
            gFadeFogEntryBytes[0] = tableEntry & 0xff;
            gFadeFogEntryBytes[1] = (tableEntry & 0xff00) >> 8;
            gFadeFogEntryBytes[2] = (tableEntry & 0xff0000) >> 16;
            gFadeFogEntryBytes[3] = (tableEntry & 0xff000000) >> 24;
            for (byteIndex = 0; byteIndex < 4; byteIndex++) {
                fogByte = gFadeFogEntryBytes[byteIndex];
                gFadeFogEntryBytes[byteIndex] = MUL_FIXED12_ROUNDED(fogByte, (s32) courseWeight) + gFadeFogByteBoost;
            }
            g_FogTable2[index] = gFadeFogEntryBytes[0] | (gFadeFogEntryBytes[1] << 8) |
                                   (gFadeFogEntryBytes[2] << 16) | (gFadeFogEntryBytes[3] << 24);
        }
        gCourseFogLastEntry = tableEntry;
    } else {
        for (index = 0; index < 8; index++) {
            g_FogTable2[index] = fadeLevel | (fadeLevel << 8) | (fadeLevel << 16) | (fadeLevel << 24);
        }
    }
}

void StartFadeFog(void) {
    if (g_GlobalTD->mDrawnFadeFog == 1) {
        g_GlobalTD->mDrawnFadeFog = 0;
    }
    g_GlobalTD->mFadeFog = 1;
    SetKartModelsFogEnable(0);
    SetCourseModelsFogEnableFlags(1);
    gFadeFogRemaining = 72;
    BuildFadeFog(72, 1);
    gFadeFogStepping = 0;
    gFadeFogActive = 1;
    gFadeFogHoldFrames = 0;
    g_SomeFogOffset = 0;
    g_YetAnotherFogColor = g_AnotherFogColor;
    gFadeFogAlpha = g_SomeFogAlpha;
}

void ClearFadeFogHoldFrames(void) {
    u32 frames;
    frames = 0u;
    gFadeFogHoldFrames = frames;
}

void SetFadeFogHoldFramesToLimit(void) {
    u32 frames;
    frames = 0x48u;
    gFadeFogHoldFrames = frames;
}

u32 IsFadeFogActive(void) {
    return (gFadeFogActive);
}

MtxFx43 *GetCurrentViewMatrix(void) {
    return g_SomeMatrix4x3;
}

u32 GetCurrentCameraKind(void) {
    return (g_GlobalHD4->mKind);
}

// The camera used this frame: g_GlobalHD4.
Camera *GetGlobalHD4(void) {
    return g_GlobalHD4;
}

Race *SetRaceUpdateFramesUnlimited(void) {
    Race *race;
    u32 isUnlimited;
    isUnlimited = 1u;
    race = g_GlobalTD;
    race->mUpdateFramesUnlimited = isUnlimited;
    return race;
}

u32 SetRaceUpdateFramesAtEntryEnd(void) {
    u32 frames;
    frames = g_GlobalTD->mUpdateFrames;
    g_GlobalTD->mUpdateFramesAtEntryEnd = frames;
    return frames;
}

s32 TryGetRaceUpdateFramesSinceEntryEnd(u32 *framesOut) {
    Race *race;
    BOOL found;

    race = g_GlobalTD;
    found = FALSE;
    if (race->mUpdateFramesAtEntryEnd != 0) {
        found = TRUE;
        *framesOut = race->mUpdateFrames - race->mUpdateFramesAtEntryEnd;
    }
    return found;
}

s32 GetMapObjectFirstPolygonId(void) {
    if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
        return 0x2e;
    }
    return 0x1f;
}

u16 GetSplMaxPolyId(void) {
    if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
        return 0x2d;
    }
    return 0x1e;
}

BOOL IsGhostRecordFilled(GhostRecordHead *ghostRecord) {
    if (ghostRecord->mFilled == 1) {
        return TRUE;
    }
    return FALSE;
}

BOOL GetGhostRecordTime(GhostRecordHead *ghostRecord, TimeRecord *timeRecord) {
    if (ghostRecord->mFilled != 1) {
        return FALSE;
    }
    timeRecord->mMinute = ghostRecord->mMinute;
    timeRecord->mSecond = ghostRecord->mSecond;
    timeRecord->mMillisecond = ghostRecord->mMillisecond;
    return TRUE;
}

BOOL GetGhostRecordName(GhostRecordHead *ghostRecord, void *name) {
    if (ghostRecord->mFilled != 1) {
        return FALSE;
    }
    Mem_CpuCopy8(ghostRecord->mName, name, PLAYER_NAME_BYTES);
    return TRUE;
}

s32 GetGhostRecordCharacterIndex(GhostRecordHead *ghostRecord) {
    if (ghostRecord->mFilled != 1) {
        return -1;
    }
    return ghostRecord->mCharacterIndex;
}

s32 GetGhostRecordKartIndex(GhostRecordHead *ghostRecord) {
    if (ghostRecord->mFilled != 1) {
        return -1;
    }
    return ghostRecord->mKartIndex;
}

u32 GetGhostRecordCourseId(GhostRecordHead *ghostRecord) {
    if (ghostRecord->mFilled != 1) {
        return 0;
    }
    return ghostRecord->mCourseId;
}
