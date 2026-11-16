#include "Main/Unknown/code_02061654.h"

#include "Main/Unknown/code_02056b30.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_0203ca20.h"
#include "Main/Unknown/code_0207a30c.h"
#include "Main/Unknown/code_02062ed8.h"
#include "Main/System/Heap.h"
#include "registers.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_02076cd0.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02063000.h"
#include "Main/Unknown/code_0203d568.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0208eb10.h"
#include "Main/Unknown/code_02017000.h"
#include "Main/Unknown/code_0208d978.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_02075000.h"
#include "Main/Unknown/code_02076000.h"
#include "Main/Unknown/code_02077000.h"
#include "Main/Unknown/code_02078000.h"
#include "code_02013740.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02088000.h"
#include "Main/Unknown/unk_02155000.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_02077bc0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "Main/Unknown/code_02073e04.h"
#include "Main/Unknown/code_02073e98.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0208537c.h"
#include "Main/Unknown/code_02086058.h"
#include "Main/Unknown/code_02086e8c.h"
#include "Main/Kart/KartResourcePaths.h"
#include "Main/Unknown/code_02089fa0.h"
#include "Main/Unknown/code_02018000.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/code_0208533c.h"
#include "Main/Unknown/code_0203c5ac.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0205b0f4.h"
#include "Main/Unknown/code_020a02f8.h"
#include "Main/Unknown/code_020af66c.h"
#include "Main/Unknown/code_020d2d94.h"
#include "Main/Unknown/code_020d2dec.h"
#include "Main/Unknown/code_020d4130.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d50c4.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_020e7a84.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_021031f4.h"
#include "Main/Unknown/code_02148d24.h"
#include "code_0214a730.h"
#include "code_02010c84.h"
#include "gecom.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_02048000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "00/code_021832d8.h"
#include "00/code_02181f98.h"
#include "gfd_FrameTexVramMan.h"
#include "gfd_FramePlttVramMan.h"
#include "code_0214a748.h"
#include "Main/Unknown/code_02042064.h"
#include "01/code_0218155c.h"
#include "Main/Unknown/code_0203ca38.h"

u32 race_isCamAnimMode(void) {
    return (race_sState->mUseChainCameras);
}

u32 race_isAwardStaffRoll(void) {
    return (race_sState->mIsAwardOrStaffRoll);
}

// Builds the race world and race_sState. Not part of it: the screen and 3D engine set-up (race_initG3d, called before), the
// net and the HUD, which are in the scene slot racesc_init.
void race_init(void) {
    void *heap;
    u16 texBankMask;
    s16 i;
    u16 j;

    heap = proc_getHeap(proc_getCurrent());
    cklcr_setLoadFromFolder(0);
    race_sState = heap_alloc(heap, 72);
    race_initState();
    texBankMask = GX_GetBankForTex();
    NNS_GfdInitFrmTexVramManager(
        ((texBankMask >> 3) & 1) + ((texBankMask >> 2) & 1) + ((texBankMask >> 1) & 1) + (texBankMask & 1), 1);
    NNS_GfdInitFrmPlttVramManager(0x10000, 1);
    model_initResList();
    cam_setupRaceParams();
    arc_setHeapGroupId(1);
    InitKartNameTagsAndDistanceOrder();
    chkrt_init(heap, gRaceMultiConfig->mKartCount);
    chkrt_applyAllHeyhoPalettes();
    func_020872a4();
    arc_switchKartModelBSubToCourse();
    map2d_load();
    arc_setHeapGroupId(2);
    mdat_init(heap);
    crsmdl_init(heap);
    arc_switchCourseTexToSceneRace();
    arc_setHeapGroupId(7);
    rstat_init(heap);
    func_0205cd24(heap);
    arc_setHeapGroupId(2);
    col_loadCourseCollision();
    arc_setHeapGroupId(8);
    col_init();
    arc_setHeapGroupId(1);
    rwrd_init(heap);
    InitKartAiShared();
    driver_initAll(gRaceMultiConfig->mKartCount);
    cam_setupPlayerCamera();
    cam_20777AC(gRaceMultiConfig->mFollowedKartIndex);
    if (race_sState->mUseChainCameras != 0) {
        if (race_sState->mUseFirstChainCamera != 0) {
            cam_setupIntroCamSingle();
        } else {
            cam_setupIntroCamDouble();
        }
    }
    race_sPlayerCamera = cam_getPlayerCamera();
    race_sReplayCamera = cam_getReplayCamera();
    race_sCurCamera = race_sPlayerCamera;
    race_sCurCameraMtx = &race_sPlayerCamera->mViewMatrix;
    cam_updateFrustum(race_sPlayerCamera);
    arc_setHeapGroupId(3);
    switch (gRaceMultiConfig->mMode) {
        case MODE_BATTLE:
            mgcnt_init();
            break;
        case MODE_MISSION_RUN:
            if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
                mrcnt_init();
            }
            if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
                mgcnt_init();
            }
            break;
    }
    arc_setHeapGroupId(3);
    jg_load();
    jg_init();
    mobj_init();
    InitializeItems();
    arc_setHeapGroupId(6);
    ptcm_init(heap);
    rptc_init(heap);
    expl_init(heap);
    trl_init(heap);
    arc_setHeapGroupId(9);
    *(u16 *) 0x05000000 = 0xff00;
    reg_G3X_DISP3DCNT = reg_G3X_DISP3DCNT & 0xffffcffd;
    G3X_SetToonTable(race_sToonTable);
    for (i = 0; i < 8; i++) {
        race_sToonTable[i] = race_sStarEffectToonTable[i];
        race_sToonTable[i + 16] = race_sSlipStreamEffectToonTable[i];
    }
    for (i = 0; i < 8; i++) {
        race_sToonTable[i + 8] = race_sToonTable[i];
        race_sToonTable[i + 24] = race_sToonTable[i + 16];
    }
    race_setupFog();
    crsmdl_setupLights();
    if (gRaceMultiConfig->mRaceKind == RACE_KIND_AWARD) {
        for (j = 0; j < 3; j++) {
            trl_createTrailForDriver(j);
        }
    }
}

void race_initState(void) {
    Vec3 lightVector;
    s32 m;

    race_sState->mUpdateFrames = 0;
    race_sState->mDrawFrames = 0;
    race_sState->mUpdateFramesModKartCount = 0;
    race_sState->mUpdateFramesMod2 = 0;
    race_sState->mUpdateFramesMod8 = 0;
    race_sState->mToonTableOffset = 0;
    race_sState->mToonTableFrames = 0;
    race_sState->mUpdateFramesLimitReached = FALSE;
    race_sState->mUpdateFramesUnlimited = FALSE;
    race_sState->mUpdateFramesAtEntryEnd = 0;
    lightVector = data_021653f0;
    race_sState->mLightVectorX = lightVector.x;
    race_sState->mLightVectorY = lightVector.y;
    race_sState->mLightVectorZ = lightVector.z;
    race_sState->mUseChainCameras = (gRaceMultiConfig->mRaceKind - 3) <= 2 ? 1 : 0;
    race_sState->mUseFirstChainCamera = gRaceMultiConfig->mRaceKind == 4 ? 1 : 0;
    race_sState->mIsAwardOrStaffRoll =
        (gRaceMultiConfig->mRaceKind == RACE_KIND_AWARD || gRaceMultiConfig->mRaceKind == RACE_KIND_STAFF_ROLL) != 0 ? 1 : 0;
    race_sState->mStarted = race_sState->mIsAwardOrStaffRoll != 0 ? 1 : 0;
}

void race_initResManagement(void) {
    u16 texBankMask;

    texBankMask = GX_GetBankForTex();
    NNS_GfdInitFrmTexVramManager(
        ((texBankMask >> 3) & 1) + ((texBankMask >> 2) & 1) + ((texBankMask >> 1) & 1) + (texBankMask & 1), 1);
    NNS_GfdInitFrmPlttVramManager(0x10000, 1);
    model_initResList();
}

void race_initG3d(void) {
    NNS_G3dInit();
    NNS_G3dGlbInit();
    NNS_G3dGeReleaseBuffer();
    NNS_G3dGeUseFastDma(1);
    gSystemData->mUnk_1c |= 8;
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
    race_sG3dGeBuffer = heap_alloc(gSystemData->mHeap, 772);
    NNS_G3dGeSetBuffer(race_sG3dGeBuffer);
}

// Advances the race one frame. Skipped while scene_areUpdatesSuspended or input_getFlagsBit0 refuse (the draw is not), and in kind 6 for
// the first 0x708 frames (neither update nor draw). The HUD step and the end-of-race state are in the scene slot
// racesc_update, which calls this; the exit loop also runs it with a == NULL.
void race_update(void) {
    void *viewMatrix;

    data_0217d020 = 1;
    col_update();
    crsmdl_update();
    UpdateKarts();
    if (race_sState->mUpdateFramesMod8 == 0) {
        UpdateKartAiShared();
    }
    switch (gRaceMultiConfig->mMode) {
        case MODE_BATTLE:
            mgcnt_update();
            break;
        case MODE_MISSION_RUN:
            if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
                mrcnt_update();
            }
            if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
                mgcnt_update();
            }
            break;
    }
    cam_2073E98();
    if (race_sState->mUseChainCameras != 0) {
        if (race_sState->mUseFirstChainCamera != 0) {
            viewMatrix = cam_updateIntroCamSingle();
        } else {
            viewMatrix = cam_updateIntroCamDouble();
        }
        race_sCurCameraMtx = viewMatrix;
        race_sCurCamera = cam_getIntroCamera();
    } else if (rstat_getUncontrollable() != 0) {
        cam_updatePlayerCamera(race_sPlayerCamera, driver_getById(gRaceMultiConfig->mFollowedKartIndex));
        cam_updateLookAtEx(race_sPlayerCamera);
        if (cam_updateReplayCamera(race_sReplayCamera) != 0) {
            race_sCurCamera = race_sReplayCamera;
            race_sCurCameraMtx = &race_sReplayCamera->mViewMatrix;
        } else {
            race_sCurCamera = race_sPlayerCamera;
            race_sCurCameraMtx = &race_sPlayerCamera->mViewMatrix;
        }
    } else {
        cam_updatePlayerCamera(race_sPlayerCamera, driver_getById(gRaceMultiConfig->mEntryIndex));
        cam_updateLookAtEx(race_sPlayerCamera);
        race_sCurCamera = race_sPlayerCamera;
        race_sCurCameraMtx = &race_sPlayerCamera->mViewMatrix;
    }
    cam_updateFrustum(race_sCurCamera);
    mobj_updateCameraVectors((Unk020d4f94 *) race_sCurCameraMtx);
    if (cam_2073E88() != 0) {
        mobj_20D50C4();
    }
    it_updateAll();
    jg_update();
    mobj_updateAll();
    expl_update();
    trl_update();
    ptcm_update();
    if (race_sDarkeningActive != 0) {
        if (race_sDarkeningIsFading != 0) {
            if (race_sDarkeningFogDensity == 0) {
                race_sState->mFadeFog = 0;
                driver_setFogEnableFlags(1);
                crsmdl_setFogFlags(0);
                race_sDarkeningActive = 0;
                race_sDarkeningIsFading = 0;
            } else {
                race_updateDarkeningFog(race_sDarkeningFogDensity, 0);
            }
            race_sDarkeningFogDensity -= 4;
        } else {
            race_sDarkeningFadeWaitCounter++;
            if (race_sDarkeningFadeWaitCounter >= 72) {
                race_sDarkeningIsFading = 1;
            }
        }
    }
    rwrd_update();
    rstat_update();
    UpdateKartSoundDistancesSquared();
    func_0208677c();
    if (gRaceMultiConfig->mMode == 5) {
        if (race_sState->mUpdateFramesUnlimited == FALSE) {
            if (race_sState->mUpdateFramesLimitReached == FALSE) {
                race_sState->mUpdateFrames++;
                if ((u32) race_sState->mUpdateFrames >= 128) {
                    race_sState->mUpdateFramesLimitReached = TRUE;
                }
            }
        } else {
            race_sState->mUpdateFrames++;
        }
    } else {
        race_sState->mUpdateFrames++;
    }
    race_sState->mUpdateFramesMod8 = race_sState->mUpdateFrames & 7;
    race_sState->mUpdateFramesMod2 = race_sState->mUpdateFrames & 1;
    race_sState->mUpdateFramesModKartCount = (u32) race_sState->mUpdateFrames % gRaceMultiConfig->mKartCount;
    G3X_SetToonTable(&race_sToonTable[race_sState->mToonTableOffset]);
    race_sState->mToonTableFrames++;
    if ((u32) race_sState->mToonTableFrames > race_sToonTableUpdateInterval) {
        race_sState->mToonTableFrames = 0;
        race_sState->mToonTableOffset++;
    }
    if ((u32) race_sState->mToonTableOffset > 7) {
        race_sState->mToonTableOffset = 0;
    }
}

// Draws the 3D scene and writes the fog registers when the fade state changes; advances no game value. Has its own gate
// in the scene slot; the HUD draw is in the scene slot too.
void race_render(void) {
    if (race_sDarkeningIsFading != 0) {
        G3X_SetFog(1, 0, race_sFogSlope, race_sDarkeningFadeFogOffset);
        G3X_SetFogTable(race_sDarkeningFogTable);
        reg_G3X_FOG_COLOR = race_sDarkeningFadeFogColor | (race_sDarkeningFadeFogAlpha << 16);
    } else if (race_sState->mFadeFog != race_sState->mDrawnFadeFog) {
        if (race_sState->mFadeFog == 0) {
            if (gMapData->mSettings->mFogEnabled != 0) {
                G3X_SetFog(1, 0, race_sFogSlope, race_sStagFogOffset);
                reg_G3X_FOG_COLOR = race_sStagFogColor | (race_sStagFogAlpha << 16);
                G3X_SetFogTable(race_sStagFogTable);
            } else {
                G3X_SetFog(0, 0, 5, 0);
            }
        } else {
            G3X_SetFog(1, 0, race_sFogSlope, 0);
            reg_G3X_FOG_COLOR = race_sDarkeningFogColor | (race_sDarkeningFogAlpha << 16);
            G3X_SetFogTable(race_sDarkeningFogTable);
        }
    }
    race_sState->mDrawnFadeFog = race_sState->mFadeFog;
    race_renderRace();
    ptcm_render(race_sCurCameraMtx);
    trl_render(race_sCurCameraMtx);
    rwrd_render();
    if (race_sState->mUseChainCameras == 0) {
        driver_renderLabels(race_sCurCameraMtx);
    }
    cspl_render();
    race_sState->mDrawFrames++;
}

void race_setLight0Direction(const Vec3 *lightVector) {
    race_sState->mLightVectorX = lightVector->x;
    race_sState->mLightVectorY = lightVector->y;
    race_sState->mLightVectorZ = lightVector->z;
}

void race_renderRace(void) {
    Vec3 lightVector;
    Vec3 a;
    Vec3 b;
    u32 v;
    Camera *currentCamera;

    cam_applyFrustum(race_sCurCamera, 1);
    cam_applyLookAt(race_sCurCamera);
    currentCamera = race_sCurCamera;
    NNS_G3dGlbLightVector(0, race_sState->mLightVectorX, race_sState->mLightVectorY, race_sState->mLightVectorZ);
    NNS_G3dGlbLightColor(0, 0x7fff);
    a.x = currentCamera->mViewMatrix.mUnk_00[0].y;
    a.y = currentCamera->mViewMatrix.mUnk_00[1].y;
    a.z = currentCamera->mViewMatrix.mUnk_00[2].y;
    b.x = -currentCamera->mViewMatrix.mUnk_00[0].z;
    b.y = -currentCamera->mViewMatrix.mUnk_00[1].z;
    b.z = -currentCamera->mViewMatrix.mUnk_00[2].z;
    VEC_Subtract(&b, &a, &lightVector);
    if ((s64) lightVector.x * lightVector.x + (s64) lightVector.y * lightVector.y +
            (s64) lightVector.z * lightVector.z >=
        16) {
        vec_normalize(&lightVector, &lightVector);
    }
    NNS_G3dGlbLightVector(1, (s16) lightVector.x, (s16) lightVector.y, (s16) lightVector.z);
    NNS_G3dGlbLightColor(1, 0x7fff);
    NNS_G3dGlbFlushP();
    NNS_G3dGeBufferOP_N(23, race_sCurCameraMtx, 12);
    v = 30;
    NNS_G3dGeBufferOP_N(19, &v, 1);
    crsmdl_renderSky();
    cam_applyFrustum(race_sCurCamera, 0);
    NNS_G3dGlbFlushP();
    NNS_G3dGeSetBuffer(race_sG3dGeBuffer);
    crsmdl_renderCourse();
    mobj_renderDColObjects(race_sCurCamera);
    NNS_G3dGeReleaseBuffer();
    driver_renderAll();
    NNS_G3dGlbLightVector(0, race_sState->mLightVectorX, race_sState->mLightVectorY, race_sState->mLightVectorZ);
    jg_render();
    mobj_renderAll(race_sCurCamera);
    it_renderAll(race_sCurCameraMtx);
    expl_render();
    NNS_G3dGeFlushBuffer();
}

void race_finalize(void) {
    WiFiSession *wiFiSession;
    BOOL heapCreated;

    mobj_finalize();
    driver_finalize();
    model_releaseAll();
    rstat_finalize();
    heapCreated = FALSE;
    wiFiSession = gStruct217D384;
    if (wiFiSession != NULL && wiFiSession->mHeapCreated != FALSE) {
        heapCreated = TRUE;
    }
    if (heapCreated != FALSE) {
        wiFiSession->mKartMask = gStruct217AA14->mUnk_749;
    }
    gStruct217AA14 = NULL;
}

void race_vblank(void) {}

u32 race_getState(void) {
    return (race_sState->mStarted);
}

void race_start(void) {
    race_sState->mStarted = 1;
    rstat_startTime();
}

u32 race_getFrameCounter(void) {
    return (race_sState->mUpdateFrames);
}

u32 race_getFrameCounterModuloDriverCount(void) {
    return (race_sState->mUpdateFramesModKartCount);
}

u32 race_getFrameCounterModulo8(void) {
    return (race_sState->mUpdateFramesMod8);
}

u32 race_getIsOddFrame(void) {
    return (race_sState->mUpdateFramesMod2);
}

// Also writes FOG_COLOR, FOG_OFFSET and FOG_TABLE directly and resets the fade state.
void race_setupFog(void) {
    u32 fogCurve[32];
    u16 i;
    u8 fogTableMode;

    race_updateDarkeningFog(72, 1);
    race_sDarkeningFogDensity = 72;
    race_sDarkeningIsFading = 0;
    race_sDarkeningActive = 0;
    race_sDarkeningFadeWaitCounter = 0;
    race_sState->mDrawnFadeFog = 0;
    race_sState->mFadeFog = race_sState->mDrawnFadeFog;
    if (gMapData->mSettings->mFogEnabled != 0) {
        fogTableMode = gMapData->mSettings->mFogTableMode;
        if (fogTableMode == 0) {
            for (i = 0; i < 8; i++) {
                race_sStagFogTable[i] =
                    ((i * 4) << 2) | ((i * 16 + 4) << 8) | ((i * 16 + 8) << 16) | ((i * 16 + 12) << 24);
            }
        } else if (fogTableMode == 1) {
            for (i = 0; i < 32; i++) {
                fogCurve[i] = ((i + 1) * (i + 1)) / 8;
                if (fogCurve[i] > 127) {
                    fogCurve[i] = 127;
                }
            }
            fogCurve[0] = 0;
            for (i = 0; i < 8; i++) {
                race_sStagFogTable[i] = fogCurve[i * 4] | (fogCurve[i * 4 + 1] << 8) | (fogCurve[i * 4 + 2] << 16) |
                                     (fogCurve[i * 4 + 3] << 24);
            }
        } else if (fogTableMode == 2) {
            for (i = 0; i < 32; i++) {
                fogCurve[i] = 128 - ((32 - (i + 1)) * (32 - (i + 1))) / 8;
                if (fogCurve[i] > 127) {
                    fogCurve[i] = 127;
                }
            }
            fogCurve[0] = 0;
            for (i = 0; i < 8; i++) {
                race_sStagFogTable[i] = fogCurve[i * 4] | (fogCurve[i * 4 + 1] << 8) | (fogCurve[i * 4 + 2] << 16) |
                                     (fogCurve[i * 4 + 3] << 24);
            }
        }
        race_sStagFogColor = gMapData->mSettings->mColorAndFogAlpha & 0x7fff;
        race_sStagFogAlpha = ((u32) gMapData->mSettings->mColorAndFogAlpha >> 15) & 31;
        race_sFogSlope = gMapData->mSettings->mUnk_07;
        race_sStagFogOffset = gMapData->mSettings->mFogOffset / 512;
        race_sStagFogColorR = race_sStagFogColor & 31;
        race_sStagFogColorG = (race_sStagFogColor >> 5) & 31;
        race_sStagFogColorB = (race_sStagFogColor >> 10) & 31;
    }
    if (gMapData->mSettings->mFogEnabled != 0) {
        G3X_SetFog(1, 0, race_sFogSlope, race_sStagFogOffset);
        reg_G3X_FOG_COLOR = race_sStagFogColor | (race_sStagFogAlpha << 16);
        G3X_SetFogTable(race_sStagFogTable);
    } else {
        G3X_SetFog(0, 0, 5, 0);
    }
}

void race_updateDarkeningFog(s32 fadeLevel, s32 b) {
    s32 fadeWeight;
    s32 courseWeight;
    u32 byteIndex;
    u32 tableEntry;
    u16 i;
    s32 fogByte;

    if (gMapData->mSettings->mFogEnabled != 0 && b == 0) {
        fadeWeight = ((s64) 57 * (fadeLevel << 12) + 0x800) >> 12;
        data_0217aa78 = fadeWeight;
        courseWeight = 4096 - fadeWeight;
        data_0217aa84 = courseWeight;
        data_0217aa44 = ((s64) fadeWeight * 72 + 0x800) >> 12;
        race_sDarkeningFadeFogColor = (s32) (((s64) race_sStagFogColorR * courseWeight + 0x800) >> 12) +
                        ((s32) (((s64) race_sStagFogColorG * courseWeight + 0x800) >> 12) << 5) +
                        ((s32) (((s64) race_sStagFogColorB * courseWeight + 0x800) >> 12) << 10);
        race_sDarkeningFadeFogAlpha = (s32) (((s64) courseWeight * race_sStagFogAlpha + 0x800) >> 12) +
                        (s32) (((s64) fadeWeight * race_sDarkeningFogAlpha + 0x800) >> 12);
        race_sDarkeningFadeFogOffset = ((s64) courseWeight * race_sStagFogOffset + 0x800) >> 12;
        for (i = 0; i < 8; i++) {
            tableEntry = race_sStagFogTable[i];
            data_0217aa8c[0] = tableEntry & 0xff;
            data_0217aa8c[1] = (tableEntry & 0xff00) >> 8;
            data_0217aa8c[2] = (tableEntry & 0xff0000) >> 16;
            data_0217aa8c[3] = (tableEntry & 0xff000000) >> 24;
            for (byteIndex = 0; byteIndex < 4; byteIndex++) {
                fogByte = data_0217aa8c[byteIndex];
                data_0217aa8c[byteIndex] = (s32) (((s64) fogByte * (s32) courseWeight + 0x800) >> 12) + data_0217aa44;
            }
            race_sDarkeningFogTable[i] =
                data_0217aa8c[0] | (data_0217aa8c[1] << 8) | (data_0217aa8c[2] << 16) | (data_0217aa8c[3] << 24);
        }
        data_0217aa58 = tableEntry;
    } else {
        for (i = 0; i < 8; i++) {
            race_sDarkeningFogTable[i] = fadeLevel | (fadeLevel << 8) | (fadeLevel << 16) | (fadeLevel << 24);
        }
    }
}

void race_startDarkening(void) {
    if (race_sState->mDrawnFadeFog == 1) {
        race_sState->mDrawnFadeFog = 0;
    }
    race_sState->mFadeFog = 1;
    driver_setFogEnableFlags(0);
    crsmdl_setFogFlags(1);
    race_sDarkeningFogDensity = 72;
    race_updateDarkeningFog(72, 1);
    race_sDarkeningIsFading = 0;
    race_sDarkeningActive = 1;
    race_sDarkeningFadeWaitCounter = 0;
    race_sDarkeningFadeFogOffset = 0;
    race_sDarkeningFadeFogColor = race_sDarkeningFogColor;
    race_sDarkeningFadeFogAlpha = race_sDarkeningFogAlpha;
}

void race_resetDarkeningFadeWaitCounter(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &race_sDarkeningFadeWaitCounter;
    value1 = 0u;
    *(u16 *) ((value0) + (0)) = value1;
}

void race_forceDarkeningFade(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &race_sDarkeningFadeWaitCounter;
    value1 = 0x48u;
    *(u16 *) ((value0) + (0)) = value1;
}

u32 race_getIsDarkeningActive(void) {
    return (race_sDarkeningActive);
}

MtxFx43 *race_getCameraMtx(void) {
    return race_sCurCameraMtx;
}

u32 race_getCameraField250(void) {
    return (race_sCurCamera->mKind);
}

// The camera used this frame: race_sCurCamera.
Camera *race_getCamera(void) {
    return race_sCurCamera;
}

u32 race_setField34(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &race_sState;
    value1 = 1u;
    value0 = *(const u32 *) ((value0) + (0));
    *(u32 *) ((value0) + (52)) = value1;
    return value0;
}

u32 race_20617D8(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &race_sState;
    value1 = *(const u32 *) ((value0) + (0));
    value0 = race_sState->mUpdateFrames;
    race_sState->mUpdateFramesAtEntryEnd = value0;
    return value0;
}

s32 race_20617A8(u32 *framesOut) {
    Race *race;
    BOOL found;

    race = race_sState;
    found = FALSE;
    if (race->mUpdateFramesAtEntryEnd != 0) {
        found = TRUE;
        *framesOut = race->mUpdateFrames - race->mUpdateFramesAtEntryEnd;
    }
    return found;
}

s32 race_getFirstObjectPolygonId(void) {
    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        return 0x2e;
    }
    return 0x1f;
}

u16 race_getLastParticlePolygonId(void) {
    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        return 0x2d;
    }
    return 0x1e;
}

BOOL ghdat_getIsGhostValid(void *record) {
    GhostRecord *ghostRecord = record;

    if (ghostRecord->mFilled == 1) {
        return TRUE;
    }
    return FALSE;
}

BOOL ghdat_getGhostTime(void *record, TimeRecord *timeRecord) {
    GhostRecord *ghostRecord = record;

    if (ghostRecord->mFilled != 1) {
        return FALSE;
    }
    timeRecord->mMinute = ghostRecord->mMinute;
    timeRecord->mSecond = ghostRecord->mSecond;
    timeRecord->mMillisecond = ghostRecord->mMillisecond;
    return TRUE;
}

BOOL ghdat_getGhostNickName(void *record, void *name) {
    GhostRecord *ghostRecord = record;

    if (ghostRecord->mFilled != 1) {
        return FALSE;
    }
    MI_CpuCopy8(ghostRecord->mName, name, 0x14);
    return TRUE;
}

s32 ghdat_getGhostCharacter(void *record) {
    GhostRecord *ghostRecord = record;

    if (ghostRecord->mFilled != 1) {
        return -1;
    }
    return ghostRecord->mCharacterIndex;
}

s32 ghdat_getGhostKart(void *record) {
    GhostRecord *ghostRecord = record;

    if (ghostRecord->mFilled != 1) {
        return -1;
    }
    return ghostRecord->mKartIndex;
}

u32 ghdat_getGhostCourse(void *record) {
    GhostRecord *ghostRecord = record;

    if (ghostRecord->mFilled != 1) {
        return 0;
    }
    return ghostRecord->mCourseId;
}
