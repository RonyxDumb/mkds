#include "Main/Race/race.h"

#include "Main/Save/course_time_record.h"
#include "Main/Kart/kart_scale_surface_tables.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Race/race_setup_block.h"
#include "tp.h"
#include "cpu_copy_fill.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/followed_kart_or.h"
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
#include "ITCM/g3d_draw_and_irq_handler.h"
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
#include "vector_math.h"
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
#include "vram_bank_assign.h"
#include "g3x.h"
#include "model_draw_blend.h"
#include "gecom.h"
#include "Main/System/result_archive_path.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Menu/menu_screens_work.h"
#include "player.h"
#include "sound_player_type.h"
#include "stream.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "gfd_FrameTexVramMan.h"
#include "gfd_FramePlttVramMan.h"
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
Vec3 gRaceLightVector = {0, -4095, 0};
const u16 gToonTableFirstColors[8] = {0x35bf, 0x36df, 0x37ff, 0x37ed, 0x7fed, 0x7ecd, 0x7dad, 0x7dbf};
const u16 gToonTableSecondColors[8] = {0x4e73, 0x56b5, 0x5ef7, 0x6739, 0x6f7b, 0x7fff, 0x7fff, 0x7fff};
u16 gFadeFogFullColor;
s16 gCourseFogGreen;
u16 gFadeFogColor;
s16 gCourseFogBlue;
s16 gCourseFogRed;
u16 gFadeFogHoldFrames;
u16 gCourseFogColor;
Camera *gRaceChaseCamera;
MtxFx43 *gCurrentViewMatrix;
s32 gFadeFogActive;
Camera *gRaceEntryCamera;
s32 gCourseFogLastEntry;
s32 gCourseFogOffset;
s32 gFadeFogByteBoost;
Race *gRace;
s32 gCourseFogWeight;
s32 gCourseFogSlope;
s32 gFadeFogWeight;
s32 gFadeFogAlpha;
s32 gFadeFogFullAlpha;
Camera *gCurrentCamera;
s32 gFadeFogOffset;
void *gGeBuffer;
s32 gCourseFogAlpha;
s32 gFadeFogStepping;
u32 gFadeFogEntryBytes[4];
u32 gCourseFogTable[8];
u32 gFadeFogTable[8];
u16 gToonTable[32];

u32 GetRaceUseChainCameras(void) {
    return (gRace->mUseChainCameras);
}

u32 IsRaceAwardOrStaffRoll(void) {
    return (gRace->mIsAwardOrStaffRoll);
}

// Builds the race world and gRace. Not part of it: the screen and 3D engine set-up (Init3dEngine, called before), the
// net and the HUD, which are in the scene slot InitRaceScene.
void InitRace(void) {
    void *heap;
    u16 texBankMask;
    s16 index;
    u16 stripIndex;

    heap = GetHeap(GetCurrentHeapCall());
    SetKartModelPathPrefix(0);
    gRace = HeapAlloc(heap, 72);
    InitRaceFields();
    texBankMask = GX_GetBankForTex();
    NNS_GfdInitFrmTexVramManager(
        ((texBankMask >> 3) & 1) + ((texBankMask >> 2) & 1) + ((texBankMask >> 1) & 1) + (texBankMask & 1), 1);
    NNS_GfdInitFrmPlttVramManager(0x10000, 1);
    ResetResFileEntries();
    InitCameraGlobals();
    SetHeapGroupId(1);
    InitKartNameTagsAndDistanceOrder();
    InitKartModels(heap, gRaceSetup->mKartCount);
    SetupHeyhoPalettes();
    UploadKartNameTagTextures();
    ReleaseKartModelSlotsLoadCourse();
    InitMap2D();
    SetHeapGroupId(2);
    CreateCourseMap(heap);
    InitCourseModels(heap);
    ReleaseCourseLoadSlotsInRace();
    SetHeapGroupId(7);
    CreateRaceProgress(heap);
    InitWiFiRaceSync(heap);
    SetHeapGroupId(2);
    InitCourseCollision();
    SetHeapGroupId(8);
    InitCollisionSlots();
    SetHeapGroupId(1);
    InitStemSets(heap);
    InitKartAiShared();
    InitKarts(gRaceSetup->mKartCount);
    CreateChaseCamera();
    CreateEntryCamera(gRaceSetup->mFollowedKartIndex);
    if (gRace->mUseChainCameras != 0) {
        if (gRace->mUseFirstChainCamera != 0) {
            CreateFirstChainCamera();
        } else {
            CreateChainCameraPair();
        }
    }
    gRaceChaseCamera = GetChaseCamera();
    gRaceEntryCamera = GetEntryCamera();
    gCurrentCamera = gRaceChaseCamera;
    gCurrentViewMatrix = &gRaceChaseCamera->mViewMatrix;
    RefreshCameraProjection(gRaceChaseCamera);
    SetHeapGroupId(3);
    switch (gRaceSetup->mMode) {
        case MODE_BATTLE:
            InitStandings();
            break;
        case MODE_MISSION_RUN:
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                CreateMissionRunData();
            }
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                InitStandings();
            }
            break;
    }
    SetHeapGroupId(3);
    CreateJg();
    InitJg();
    InitMapObjects();
    InitItems();
    SetHeapGroupId(6);
    InitEffects(heap);
    InitKartEffectTables(heap);
    InitModelEffects(heap);
    InitPosStrips(heap);
    SetHeapGroupId(9);
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
    if (gRaceSetup->mRaceKind == RACE_KIND_AWARD) {
        for (stripIndex = 0; stripIndex < 3; stripIndex++) {
            StartAwardKartPosStrip(stripIndex);
        }
    }
}

void InitRaceFields(void) {
    Vec3 lightVector;
    s32 unusedValue;

    gRace->mUpdateFrames = 0;
    gRace->mDrawFrames = 0;
    gRace->mUpdateFramesModKartCount = 0;
    gRace->mUpdateFramesMod2 = 0;
    gRace->mUpdateFramesMod8 = 0;
    gRace->mToonTableOffset = 0;
    gRace->mToonTableFrames = 0;
    gRace->mUpdateFramesLimitReached = FALSE;
    gRace->mUpdateFramesUnlimited = FALSE;
    gRace->mUpdateFramesAtEntryEnd = 0;
    lightVector = gRaceLightVector;
    gRace->mLightVectorX = lightVector.x;
    gRace->mLightVectorY = lightVector.y;
    gRace->mLightVectorZ = lightVector.z;
    gRace->mUseChainCameras = (gRaceSetup->mRaceKind - 3) <= 2 ? 1 : 0;
    gRace->mUseFirstChainCamera = gRaceSetup->mRaceKind == RACE_KIND_START_BATTLE ? 1 : 0;
    gRace->mIsAwardOrStaffRoll =
        (gRaceSetup->mRaceKind == RACE_KIND_AWARD || gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) != 0 ? 1 : 0;
    gRace->mStarted = gRace->mIsAwardOrStaffRoll != 0 ? 1 : 0;
}

void InitFrmVramManagers(void) {
    u16 texBankMask;

    texBankMask = GX_GetBankForTex();
    NNS_GfdInitFrmTexVramManager(
        ((texBankMask >> 3) & 1) + ((texBankMask >> 2) & 1) + ((texBankMask >> 1) & 1) + (texBankMask & 1), 1);
    NNS_GfdInitFrmPlttVramManager(0x10000, 1);
    ResetResFileEntries();
}

// Bytes of the geometry command buffer: the word count and 192 words.
#define RACE_GE_BUFFER_BYTES 772

void Init3dEngine(void) {
    NNS_G3dInit();
    NNS_G3dGlbInit();
    NNS_G3dGeReleaseBuffer();
    NNS_G3dGeUseFastDma(1);
    gStartupWork->mUnk_1c |= STARTUP_FLAG_FAST_DMA;
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
    gGeBuffer = HeapAlloc(gStartupWork->mHeap, RACE_GE_BUFFER_BYTES);
    NNS_G3dGeSetBuffer(gGeBuffer);
}

// Advances the race one frame. Skipped while IsDataSharingIncomplete or IsInputOpenDuringRace refuse (the draw is not),
// and in kind 6 for the first 0x708 frames (neither update nor draw). The HUD step and the end-of-race state are in the
// scene slot UpdateRaceScene, which calls this; the exit loop also runs it with a == NULL.
void UpdateRace(void) {
    void *viewMatrix;

    gExpireWhileRequestedSounds = 1;
    UpdateCollisionSlotBounds();
    UpdateCourseModels();
    UpdateKarts();
    if (gRace->mUpdateFramesMod8 == 0) {
        UpdateKartAiShared();
    }
    switch (gRaceSetup->mMode) {
        case MODE_BATTLE:
            UpdateStandings();
            break;
        case MODE_MISSION_RUN:
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                UpdateMissionRunData();
            }
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                UpdateStandings();
            }
            break;
    }
    ClearCameraEntryFlags();
    if (gRace->mUseChainCameras != 0) {
        if (gRace->mUseFirstChainCamera != 0) {
            viewMatrix = UpdateFirstChainCamera();
        } else {
            viewMatrix = UpdateChainCameraPair();
        }
        gCurrentViewMatrix = viewMatrix;
        gCurrentCamera = GetCurrentChainCamera();
    } else if (GetEntryRaceEnded() != 0) {
        UpdateChaseCamera(gRaceChaseCamera, GetKart(gRaceSetup->mFollowedKartIndex));
        UpdateCameraView(gRaceChaseCamera);
        if (TryUpdateEntryCamera(gRaceEntryCamera) != 0) {
            gCurrentCamera = gRaceEntryCamera;
            gCurrentViewMatrix = &gRaceEntryCamera->mViewMatrix;
        } else {
            gCurrentCamera = gRaceChaseCamera;
            gCurrentViewMatrix = &gRaceChaseCamera->mViewMatrix;
        }
    } else {
        UpdateChaseCamera(gRaceChaseCamera, GetKart(gRaceSetup->mEntryIndex));
        UpdateCameraView(gRaceChaseCamera);
        gCurrentCamera = gRaceChaseCamera;
        gCurrentViewMatrix = &gRaceChaseCamera->mViewMatrix;
    }
    RefreshCameraProjection(gCurrentCamera);
    UpdateViewFrustum(gCurrentViewMatrix);
    if (GetCameraEntryChanged() != 0) {
        RequestViewTestRefresh();
    }
    UpdateItems();
    UpdateJg();
    UpdateMapObjects();
    UpdateModelEffects();
    UpdatePosStrips();
    UpdateEffects();
    if (gFadeFogActive != 0) {
        if (gFadeFogStepping != 0) {
            if (gFadeFogRemaining == 0) {
                gRace->mFadeFog = 0;
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
    if (gRaceSetup->mMode == MODE_WIFI) {
        if (gRace->mUpdateFramesUnlimited == FALSE) {
            if (gRace->mUpdateFramesLimitReached == FALSE) {
                gRace->mUpdateFrames++;
                if ((u32) gRace->mUpdateFrames >= RACE_WIFI_UPDATE_FRAMES_LIMIT) {
                    gRace->mUpdateFramesLimitReached = TRUE;
                }
            }
        } else {
            gRace->mUpdateFrames++;
        }
    } else {
        gRace->mUpdateFrames++;
    }
    gRace->mUpdateFramesMod8 = gRace->mUpdateFrames & 7;
    gRace->mUpdateFramesMod2 = gRace->mUpdateFrames & 1;
    gRace->mUpdateFramesModKartCount = (u32) gRace->mUpdateFrames % gRaceSetup->mKartCount;
    G3X_SetToonTable(&gToonTable[gRace->mToonTableOffset]);
    gRace->mToonTableFrames++;
    if ((u32) gRace->mToonTableFrames > gToonTableFramesLimit) {
        gRace->mToonTableFrames = 0;
        gRace->mToonTableOffset++;
    }
    if ((u32) gRace->mToonTableOffset > 7) {
        gRace->mToonTableOffset = 0;
    }
}

// Draws the 3D scene and writes the fog registers when the fade state changes; advances no game value. Has its own gate
// in the scene slot; the HUD draw is in the scene slot too.
void DrawRace(void) {
    if (gFadeFogStepping != 0) {
        G3X_SetFog(1, 0, gCourseFogSlope, gFadeFogOffset);
        G3X_SetFogTable(gFadeFogTable);
        reg_G3X_FOG_COLOR = gFadeFogColor | (gFadeFogAlpha << 16);
    } else if (gRace->mFadeFog != gRace->mDrawnFadeFog) {
        if (gRace->mFadeFog == 0) {
            if (gCourseMap->mSettings->mFogEnabled != 0) {
                G3X_SetFog(1, 0, gCourseFogSlope, gCourseFogOffset);
                reg_G3X_FOG_COLOR = gCourseFogColor | (gCourseFogAlpha << 16);
                G3X_SetFogTable(gCourseFogTable);
            } else {
                G3X_SetFog(0, 0, 5, 0);
            }
        } else {
            G3X_SetFog(1, 0, gCourseFogSlope, 0);
            reg_G3X_FOG_COLOR = gFadeFogFullColor | (gFadeFogFullAlpha << 16);
            G3X_SetFogTable(gFadeFogTable);
        }
    }
    gRace->mDrawnFadeFog = gRace->mFadeFog;
    DrawRaceWorld();
    DrawEffects(gCurrentViewMatrix);
    DrawPosStrips(gCurrentViewMatrix);
    DrawStemSets();
    if (gRace->mUseChainCameras == 0) {
        DrawKartNameTags(gCurrentViewMatrix);
    }
    DrawOrthoQuads();
    gRace->mDrawFrames++;
}

void SetRaceLightVector(const Vec3 *lightVector) {
    gRace->mLightVectorX = lightVector->x;
    gRace->mLightVectorY = lightVector->y;
    gRace->mLightVectorZ = lightVector->z;
}

void DrawRaceWorld(void) {
    Vec3 lightVector;
    Vec3 cameraUp;
    Vec3 cameraForward;
    u32 commandValue;
    Camera *currentCamera;

    ApplyCameraFrustum(gCurrentCamera, 1);
    ApplyCameraLookAt(gCurrentCamera);
    currentCamera = gCurrentCamera;
    NNS_G3dGlbLightVector(0, gRace->mLightVectorX, gRace->mLightVectorY, gRace->mLightVectorZ);
    NNS_G3dGlbLightColor(0, 0x7fff);
    cameraUp.x = currentCamera->mViewMatrix.mRows[0].y;
    cameraUp.y = currentCamera->mViewMatrix.mRows[1].y;
    cameraUp.z = currentCamera->mViewMatrix.mRows[2].y;
    cameraForward.x = -currentCamera->mViewMatrix.mRows[0].z;
    cameraForward.y = -currentCamera->mViewMatrix.mRows[1].z;
    cameraForward.z = -currentCamera->mViewMatrix.mRows[2].z;
    VEC_Subtract(&cameraForward, &cameraUp, &lightVector);
    if (SQUARE_SUM3(lightVector.x, lightVector.y, lightVector.z) >=
        16) {
        Vec3NormalizeAndGetLengthUnchecked(&lightVector, &lightVector);
    }
    NNS_G3dGlbLightVector(1, (s16) lightVector.x, (s16) lightVector.y, (s16) lightVector.z);
    NNS_G3dGlbLightColor(1, 0x7fff);
    NNS_G3dGlbFlushP();
    NNS_G3dGeBufferOP_N(23, gCurrentViewMatrix, 12);
    commandValue = 30;
    NNS_G3dGeBufferOP_N(19, &commandValue, 1);
    DrawCourseModelV();
    ApplyCameraFrustum(gCurrentCamera, 0);
    NNS_G3dGlbFlushP();
    NNS_G3dGeSetBuffer(gGeBuffer);
    DrawCourseModel();
    DrawKoopaBlocksRotariesAndBridges(gCurrentCamera);
    NNS_G3dGeReleaseBuffer();
    DrawKarts();
    NNS_G3dGlbLightVector(0, gRace->mLightVectorX, gRace->mLightVectorY, gRace->mLightVectorZ);
    DrawJg();
    DrawMapObjects(gCurrentCamera);
    DrawItems(gCurrentViewMatrix);
    DrawModelEffects();
    NNS_G3dGeFlushBuffer();
}

void ReleaseRace(void) {
    WiFiSession *wiFiSession;
    BOOL heapCreated;

    ClearMapObjectListSlots();
    ReleaseKartsAndClear();
    ReleaseAllResFiles();
    StopRaceInput();
    heapCreated = FALSE;
    wiFiSession = gWiFiSession;
    if (wiFiSession != NULL && wiFiSession->mHeapCreated != FALSE) {
        heapCreated = TRUE;
    }
    if (heapCreated != FALSE) {
        wiFiSession->mKartMask = gWiFiRaceSync->mParticipantMask;
    }
    gWiFiRaceSync = NULL;
}

void RaceSceneAdvanceNop(void) {}

u32 IsRaceStarted(void) {
    return (gRace->mStarted);
}

void StartRace(void) {
    gRace->mStarted = 1;
    StartRaceClock();
}

u32 GetRaceUpdateFrames(void) {
    return (gRace->mUpdateFrames);
}

u32 GetRaceUpdateFramesModKartCount(void) {
    return (gRace->mUpdateFramesModKartCount);
}

u32 GetRaceUpdateFramesMod8(void) {
    return (gRace->mUpdateFramesMod8);
}

u32 GetRaceUpdateFramesMod2(void) {
    return (gRace->mUpdateFramesMod2);
}

// Also writes FOG_COLOR, FOG_OFFSET and FOG_TABLE directly and resets the fade state.
void InitRaceFog(void) {
    u32 fogCurve[32];
    u16 index;
    u8 fogTableMode;

    BuildFadeFog(72, 1);
    gFadeFogRemaining = 72;
    gFadeFogStepping = 0;
    gFadeFogActive = 0;
    gFadeFogHoldFrames = 0;
    gRace->mDrawnFadeFog = 0;
    gRace->mFadeFog = gRace->mDrawnFadeFog;
    if (gCourseMap->mSettings->mFogEnabled != 0) {
        fogTableMode = gCourseMap->mSettings->mFogTableMode;
        if (fogTableMode == 0) {
            for (index = 0; index < 8; index++) {
                gCourseFogTable[index] =
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
                gCourseFogTable[index] = fogCurve[index * 4] | (fogCurve[index * 4 + 1] << 8) |
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
                gCourseFogTable[index] = fogCurve[index * 4] | (fogCurve[index * 4 + 1] << 8) |
                                         (fogCurve[index * 4 + 2] << 16) | (fogCurve[index * 4 + 3] << 24);
            }
        }
        gCourseFogColor = gCourseMap->mSettings->mColorAndFogAlpha & COLOR15_MASK;
        gCourseFogAlpha = ((u32) gCourseMap->mSettings->mColorAndFogAlpha >> 15) & 31;
        gCourseFogSlope = gCourseMap->mSettings->mFogSlope;
        gCourseFogOffset = gCourseMap->mSettings->mFogOffset / 512;
        gCourseFogRed = gCourseFogColor & 31;
        gCourseFogGreen = (gCourseFogColor >> 5) & 31;
        gCourseFogBlue = (gCourseFogColor >> 10) & 31;
    }
    if (gCourseMap->mSettings->mFogEnabled != 0) {
        G3X_SetFog(1, 0, gCourseFogSlope, gCourseFogOffset);
        reg_G3X_FOG_COLOR = gCourseFogColor | (gCourseFogAlpha << 16);
        G3X_SetFogTable(gCourseFogTable);
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

    if (gCourseMap->mSettings->mFogEnabled != 0 && flag == 0) {
        fadeWeight = MUL_FIXED12_ROUNDED(57, TO_FIXED12(fadeLevel));
        gFadeFogWeight = fadeWeight;
        courseWeight = 4096 - fadeWeight;
        gCourseFogWeight = courseWeight;
        gFadeFogByteBoost = MUL_FIXED12_ROUNDED(fadeWeight, 72);
        gFadeFogColor = MUL_FIXED12_ROUNDED(gCourseFogRed, courseWeight) +
                        (MUL_FIXED12_ROUNDED(gCourseFogGreen, courseWeight) << 5) +
                        (MUL_FIXED12_ROUNDED(gCourseFogBlue, courseWeight) << 10);
        gFadeFogAlpha =
            MUL_FIXED12_ROUNDED(courseWeight, gCourseFogAlpha) + MUL_FIXED12_ROUNDED(fadeWeight, gFadeFogFullAlpha);
        gFadeFogOffset = MUL_FIXED12_ROUNDED(courseWeight, gCourseFogOffset);
        for (index = 0; index < 8; index++) {
            tableEntry = gCourseFogTable[index];
            gFadeFogEntryBytes[0] = tableEntry & 0xff;
            gFadeFogEntryBytes[1] = (tableEntry & 0xff00) >> 8;
            gFadeFogEntryBytes[2] = (tableEntry & 0xff0000) >> 16;
            gFadeFogEntryBytes[3] = (tableEntry & 0xff000000) >> 24;
            for (byteIndex = 0; byteIndex < 4; byteIndex++) {
                fogByte = gFadeFogEntryBytes[byteIndex];
                gFadeFogEntryBytes[byteIndex] = MUL_FIXED12_ROUNDED(fogByte, (s32) courseWeight) + gFadeFogByteBoost;
            }
            gFadeFogTable[index] = gFadeFogEntryBytes[0] | (gFadeFogEntryBytes[1] << 8) |
                                   (gFadeFogEntryBytes[2] << 16) | (gFadeFogEntryBytes[3] << 24);
        }
        gCourseFogLastEntry = tableEntry;
    } else {
        for (index = 0; index < 8; index++) {
            gFadeFogTable[index] = fadeLevel | (fadeLevel << 8) | (fadeLevel << 16) | (fadeLevel << 24);
        }
    }
}

void StartFadeFog(void) {
    if (gRace->mDrawnFadeFog == 1) {
        gRace->mDrawnFadeFog = 0;
    }
    gRace->mFadeFog = 1;
    SetKartModelsFogEnable(0);
    SetCourseModelsFogEnableFlags(1);
    gFadeFogRemaining = 72;
    BuildFadeFog(72, 1);
    gFadeFogStepping = 0;
    gFadeFogActive = 1;
    gFadeFogHoldFrames = 0;
    gFadeFogOffset = 0;
    gFadeFogColor = gFadeFogFullColor;
    gFadeFogAlpha = gFadeFogFullAlpha;
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
    return gCurrentViewMatrix;
}

u32 GetCurrentCameraKind(void) {
    return (gCurrentCamera->mKind);
}

// The camera used this frame: gCurrentCamera.
Camera *GetCurrentCamera(void) {
    return gCurrentCamera;
}

Race *SetRaceUpdateFramesUnlimited(void) {
    Race *race;
    u32 isUnlimited;
    isUnlimited = 1u;
    race = gRace;
    race->mUpdateFramesUnlimited = isUnlimited;
    return race;
}

u32 SetRaceUpdateFramesAtEntryEnd(void) {
    u32 frames;
    frames = gRace->mUpdateFrames;
    gRace->mUpdateFramesAtEntryEnd = frames;
    return frames;
}

s32 TryGetRaceUpdateFramesSinceEntryEnd(u32 *framesOut) {
    Race *race;
    BOOL found;

    race = gRace;
    found = FALSE;
    if (race->mUpdateFramesAtEntryEnd != 0) {
        found = TRUE;
        *framesOut = race->mUpdateFrames - race->mUpdateFramesAtEntryEnd;
    }
    return found;
}

s32 GetMapObjectFirstPolygonId(void) {
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        return 0x2e;
    }
    return 0x1f;
}

u16 GetSplMaxPolyId(void) {
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
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
    MI_CpuCopy8(ghostRecord->mName, name, PLAYER_NAME_BYTES);
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
