#include "Main/Unknown/code_0203a3a4.h"

#include "Main/Unknown/code_02039e08.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_02045874.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02029aa0.h"
#include "Main/Unknown/code_0204673c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_021832d8.h"
#include "01/code_021956dc.h"
#include "os_printf.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_02039000.h"
#include "Main/Unknown/code_020431e4.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02046c10.h"
#include "code_020176b0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02039774.h"
#include "Main/Unknown/code_0204a550.h"
#include "Main/Unknown/code_02053e54.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_02056d40.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_02059bc0.h"
#include "Main/Unknown/code_02060004.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020af66c.h"
#include "Main/Unknown/code_020b03bc.h"
#include "Main/Ui/ChoisesS.h"
#include "Main/Unknown/unk_02164000.h"
#include "code_021458c4.h"
#include "Main/Unknown/code_02046740.h"
#include "registers.h"

static inline u32 func_0203a908_inline(void) {
    InputSlotIndex slotIndex = UNK_02175628_INDEX_8;
    u32 result = 1;
    u32 briefNoPair = 0;
    u16 hasPair = gInputUnits[slotIndex].mHasPair;
    if (hasPair == 0 && gInputUnits[slotIndex].mNoPairCount < 5) {
        briefNoPair = 1;
    }
    if (briefNoPair == 0 && hasPair == 0) {
        result = 0;
    }
    return result;
}

BOOL race_getGhostFileNameForCourse(u32 courseId, void *buffer, u32 size) {
    int cupCourseIndex = rconf_getCourseNumber(courseId);
    if (cupCourseIndex == -1) {
        return FALSE;
    }
    OS_SNPrintf(buffer, size, aDataGhostGhost, cupCourseIndex & 0xff);
    return TRUE;
}

static inline u32 func_0203a9ec_inline(void) {
    u8 i;
    u8 j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            if (savd_getIsCupPlayed(i, j) != 0) {
                return 1;
            }
        }
    }
    return 0;
}

// The staff roll waits 0x708 frames before the race runs.
u32 race_getShouldUpdate(u32 sceneFrames) {
    if (gRaceMultiConfig->mRaceKind != RACE_KIND_STAFF_ROLL) {
        return 1;
    }
    return sceneFrames >= 0x708;
}

void race_initDisplayConfig(void *heap) {
    DisplaySettings *settings;
    settings = dc_createDisplayConfig(heap, race_sDisplayConfigBases[gRaceMultiConfig->mRaceKind]);
    dc_set3DSwapConfig(settings, 1, 1);
    dc_setBg0Config(&settings->mMainBg0, 1, 0, 0, 1, 0, 0, 0);
    switch (gRaceMultiConfig->mRaceKind) {
        case RACE_KIND_NORMAL:
        case 2:
        case RACE_KIND_STAFF_ROLL:
            dc_setBg2Config(&settings->mMainBg0, 1, 0, 0, 0, 7, 0);
            dc_setBg0Config(&settings->mSubBg0, 0, 0, 0, 0, 0xd, 0, 0);
            dc_setBg1Config(&settings->mSubBg0, 1, 0, 0, 0, 0xe, 0, 0);
            dc_setBg2Config(&settings->mSubBg0, 2, 0, 0, 0, 0xf, 0);
            dce_setMode(0);
            break;
        case RACE_KIND_DEMO:
            dc_setBg2Config(&settings->mMainBg0, 1, 0, 0, 0, 7, 0);
            dc_setBg0Config(&settings->mSubBg0, 0, 0, 0, 0, 0xd, 0, 0);
            dc_setBg1Config(&settings->mSubBg0, 1, 0, 0, 0, 0xe, 0, 0);
            dc_setBg2Config(&settings->mSubBg0, 2, 0, 0, 0, 0xf, 0);
            dce_setMode(0);
            break;
        case RACE_KIND_START_GP:
        case RACE_KIND_AWARD:
            dc_setBg2Config(&settings->mMainBg0, 1, 0, 0, 0, 7, 0);
            dc_setBg2ConfigMode5(&settings->mSubBg0, 0, 0, 1, 0, 0);
            dc_setSubObjBmpMode(settings, 0x20);
            dce_setMode(1);
            break;
        case 4:
            dc_setBg2Config(&settings->mMainBg0, 1, 0, 0, 0, 7, 0);
            dce_setMode(0);
            break;
    }
    dc_setDisplayConfig(settings);
    dce_setupGX();
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 2;
}

void racesc_init(void) {
    void *p;
    s32 mirrorMode;
    WiFiSession *session;
    BOOL sessionHeapCreated;
    p = proc_getHeap(proc_getCurrent());
    overlay_createExpHeap();
    if (gRaceMultiConfig->mRaceKind == RACE_KIND_START_GP || gRaceMultiConfig->mRaceKind == RACE_KIND_AWARD) {
        vram_terminateWifiVram();
    } else {
        vram_startUpWifiVram();
        sub_2053E74();
    }
    race_initG3d();
    arc_setHeapGroupId(7);
    dce_init(p);
    race_initDisplayConfig(p);
    input_20431E4();
    arc_setHeapGroupId(9);
    race_init();
    arc_setHeapGroupId(5);
    rchoi_init();
    r2d_init();
    if (gRaceMultiConfig->mRaceKind != RACE_KIND_START_GP) {
        sub_20AF99C();
    }
    arc_setHeapGroupId(8);
    mirrorMode = gRaceMultiConfig->mMirrorMode;
    if (mirrorMode == 0 && gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        if ((gRaceMultiConfig->field44 & 0x10) != 0) {
            mirrorMode = 1;
        }
    }
    input_setMirrorMode(mirrorMode);
    arc_setHeapGroupId(9);
    if (gRaceMultiConfig->mMode != MODE_BATTLE) {
        if (gRaceMultiConfig->mMode == 5) {
            sessionHeapCreated = FALSE;
            session = gStruct217D384;
            if (session != NULL) {
                if (session->mHeapCreated != FALSE) {
                    sessionHeapCreated = TRUE;
                }
            }
            if (sessionHeapCreated != FALSE) {
                StateMachine *p;
                session->field1F38 = TRUE;
                p = &gStruct217D384->field8;
                p->mNextState = 5;
                p->mNextStateRequested = 1;
            }
        }
    } else {
        if (gRaceMultiConfig->mBattleKind == BATTLE_KIND_BALLOON) {
            spi_startMicAutoSampling(proc_getHeap(proc_getCurrent()));
        }
    }
}

void racesc_finalize(void) {
    RaceSetup *p;
    WiFiSession *session;
    s32 flagIndex;
    BOOL sessionHeapCreated;
    if (gRaceMultiConfig->mMode == 5) {
        sessionHeapCreated = FALSE;
        session = gStruct217D384;
        if (session != NULL) {
            if (session->mHeapCreated != FALSE) {
                sessionHeapCreated = TRUE;
            }
        }
        if (sessionHeapCreated != FALSE) {
            StateMachine *p;
            session->field1F38 = FALSE;
            p = &gStruct217D384->field8;
            p->mNextState = 4;
            p->mNextStateRequested = 1;
        }
    }
    p = gRaceMultiConfig;
    if (p->mRaceKind == RACE_KIND_STAFF_ROLL) {
        flagIndex = 0x18;
        if (p->mMode != MODE_GRAND_PRIX) {
            if (p->mMode == MODE_MISSION_RUN) {
                flagIndex = 0x1a;
            }
        } else {
            if (p->mCourseId == COURSE_ID_STAFFROLLTRUE) {
                flagIndex = 0x19;
            }
        }
        if (savd_isUnlockBitSet(flagIndex) == 0) {
            savd_setUnlockBit(flagIndex);
            savd_flushNksy();
            bgwkr_waitForCompletion();
            if (gSaveCore->mBackupEnabled != 0) {
                CARD_WaitBackupAsync();
            }
        }
    }
    spi_stopMicAutoSampling();
    rchoi_finalize();
    race_finalize();
    sub_20AF86C();
    dce_uninit();
    sub_2053E54();
    overlay_destroyExpHeap();
}

void racesc_vblank(void) {
    dce_updateVBlank(rchoi_getPrevIsRacePaused());
    race_vblank();
    r2d_vblank();
}

// The award scene ends after 0x564 frames, or on a new key press once some Grand Prix record is filled.
u32 ShouldEndAwardRace(u32 sceneFrames) {
    if (sceneFrames > 0x564) {
        return 1;
    }
    if (mbright_isFadedIn() == 0) {
        return 0;
    }
    if (func_0203a9ec_inline() != 0) {
        InputSlotIndex slotIndex = UNK_02175628_INDEX_8;
        if ((u16) (gInputUnits[slotIndex].mPressedBits & PAD_KEY_A) != 0) {
            return 1;
        }
    }
    return 0;
}

// The staff roll can end early on input after 0xb4 frames when its flag for the mode is set.
u32 japdiff_203A908(u32 sceneFrames) {
    u32 result;
    s32 flagIndex = 0x18;
    if (gRaceMultiConfig->mMode != MODE_GRAND_PRIX) {
        if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
            flagIndex = 0x1a;
        }
    } else {
        if (gRaceMultiConfig->mCourseId == COURSE_ID_STAFFROLLTRUE) {
            flagIndex = 0x19;
        }
    }
    result = 0;
    if (savd_isUnlockBitSet(flagIndex) != 0 && sceneFrames > 0xb4) {
        InputSlotIndex slotIndex = UNK_02175628_INDEX_8;
        if ((u16) (gInputUnits[slotIndex].mBits & 0xc0f) != 0 || func_0203a908_inline() != 0) {
            result = 1;
        }
    }
    return result;
}

u32 race_race_getCurrentRaceMode(void) {
    return (gRaceMultiConfig->mMode);
}

void race_sysdat_setActivatedRaceMenuOption(u32 pickedValue) {
    gSystemData->field44 = pickedValue;
}

// Turns the value picked on the choice screen into the next scene and the settings that go with it.
void race_handleMenuOption(Unk0203a0dc *sceneNumbers, u32 pickedValue) {
    s32 nextScene;
    gStruct217B488->field8 = 0;
    nextScene = -1;
    switch (pickedValue) {
        case 10:
            rconf_setupStaffRoll(0);
            nextScene = 2;
            break;
        case 9:
            if (gRaceMultiConfig->mMode != 5) {
                u32 t;
                u32 f;
                ConnectionWork *q;
                f = 0;
                q = gStruct217AA00;
                if (q == NULL) {
                    t = 0;
                } else {
                    t = q->field0;
                }
                if (t != 0) {
                    if (q->field4 != 0xd) {
                        f = 1;
                    }
                }
                if (f != 0) {
                    if (gSystemData->field1C_2 != 0) {
                        nextScene = 6;
                        gStruct217B488->field74 = 3;
                    } else {
                        nextScene = 1;
                    }
                    gStruct217B488->field8 = 4;
                    gStruct217B488->field4 = 1;
                } else {
                    nextScene = 0;
                }
                if (gRaceMultiConfig->mMode == MODE_TIME_ATTACK) {
                    nullsub_4();
                }
            } else {
                nextScene = 0xc;
                gStruct217B488->field1C = 0;
            }
            break;
        case 1:
        case 3:
            nextScene = 2;
            gRaceMultiConfig->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
            break;
        case 8:
            nextScene = 2;
            gRaceMultiConfig->mNextHeader.mRaceKind = nextScene;
            break;
        case 2:
            switch (gRaceMultiConfig->mMode) {
                case MODE_GRAND_PRIX:
                    rconf_gotoNextGpRace();
                    nextScene = 2;
                    break;
                case MODE_VS:
                    if (sub_2045914() != 0) {
                        if (gSystemData->field1C_2 == 0) {
                            nextScene = 2;
                        } else {
                            nextScene = 6;
                            gStruct217B488->field74 = 1;
                        }
                    } else {
                        if (gRaceMultiConfig->mCourseListMode == 0) {
                            gStruct217B488->field8 = 2;
                        }
                        if (gSystemData->field1C_2 == 0) {
                            nextScene = 1;
                        } else {
                            nextScene = 6;
                            gStruct217B488->field74 = 3;
                        }
                    }
                    break;
                case 5:
                    if (race_2045874() != FALSE) {
                        nextScene = 0xc;
                        gStruct217B488->field1C = 3;
                    } else {
                        nextScene = 0xa;
                        gStruct217B488->field1C = 2;
                    }
                    break;
                case MODE_BATTLE:
                    if (sub_20458CC() != 0) {
                        if (gSystemData->field1C_2 == 0) {
                            nextScene = 2;
                        } else {
                            nextScene = 6;
                            gStruct217B488->field74 = 1;
                        }
                    } else {
                        if (gRaceMultiConfig->mCourseListMode == 0) {
                            gStruct217B488->field8 = 2;
                        }
                        if (gSystemData->field1C_2 == 0) {
                            nextScene = 1;
                        } else {
                            nextScene = 6;
                            gStruct217B488->field74 = 3;
                        }
                    }
                    break;
            }
            break;
        case 7:
            switch (gRaceMultiConfig->mMode) {
                case MODE_GRAND_PRIX:
                    if (rconf_setupAward() != FALSE) {
                        nextScene = 2;
                    } else {
                        nextScene = 0xa;
                    }
                    break;
                case MODE_MISSION_RUN:
                    nextScene = 0;
                    break;
                case MODE_BATTLE:
                case MODE_VS:
                    if (gSystemData->field1C_2 != 0) {
                        nextScene = 6;
                        gStruct217B488->field74 = 2;
                    } else {
                        nextScene = 0xa;
                    }
                    break;
            }
            break;
        case 5:
            nextScene = 1;
            gStruct217B488->field8 = nextScene;
            break;
        case 4:
            gStruct217B488->field8 = 2;
            nextScene = 1;
            break;
        case 6:
            gStruct217B488->field8 = 3;
            nextScene = 1;
            break;
    }
    if (nextScene != -1) {
        sceneNumbers->mNextScene = nextScene;
    }
}

u32 race_race_getCurrentDisplayMode(void) {
    return gRaceMultiConfig->mRaceKind;
}

void race_sysdat_setDemoRaceWasCanceled(u32 a) {
    if (a != 0) {
        gSystemData->field50 |= 1;
    } else {
        gSystemData->field50 &= ~1;
    }
}

u32 race_input_getDefaultInputId(void) {
    return 0x8u;
}

u16 GetDownBits(u32 slotIndex, u32 mask) {
    u32 bits;
    bits = gInputUnits[slotIndex].mBits;
    return bits & mask;
}

u32 MaybePlaySseqFromSarc0(u32 index) {
    u32 value0 = index;
    u32 value1;
    u32 value2;
    u32 value12;
    value12 = (u32) &NNS_SndArcPlayerStartSeqArc;
    value2 = value0;
    value0 = (u32) &data_0217d068;
    value1 = 0u;
    value0 = NNS_SndArcPlayerStartSeqArc((const void *) value0, value1, value2);
    return value0;
}

u32 HasTouchPressed(u32 slotIndex) {
    u32 result;
    u32 briefNoPair;
    u16 hasPair;
    result = 1;
    briefNoPair = 0;
    hasPair = gInputUnits[slotIndex].mHasPair;
    if (hasPair == 0 && gInputUnits[slotIndex].mNoPairCount < 5) {
        briefNoPair = 1;
    }
    if (briefNoPair == 0 && hasPair == 0) {
        result = 0;
    }
    return result;
}

u32 IsCameraChainEnded(void) {
    return gRaceStatus->mCameraChainEnded;
}

u32 AnotherHasTouchPressed(u32 slotIndex) {
    u32 result;
    u32 briefNoPair;
    result = 0;
    briefNoPair = 0;
    if (gInputUnits[slotIndex].mHasPair == 0 && gInputUnits[slotIndex].mNoPairCount < 5) {
        briefNoPair = 1;
    }
    if (briefNoPair == 0 && gInputUnits[slotIndex].mPrevHasPair == 0 && gInputUnits[slotIndex].mHasPair != 0) {
        result = 1;
    }
    return result;
}

void race_race_setNextDisplayMode(u32 raceKind) {
    gRaceMultiConfig->mNextHeader.mRaceKind = raceKind;
}

u32 race_race_getCurrentCourse(void) {
    return (gRaceMultiConfig->mCourseId);
}
