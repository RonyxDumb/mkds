#include "Main/Unknown/code_020aeb7c.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Ui/ChoisesS.h"
#include "Main/Unknown/code_020be950.h"
#include "Main/Unknown/code_020c5e30.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_020f36d8.h"
#include "00/code_02181f98.h"
#include "code_02022030.h"
#include "Main/Unknown/code_020c476c.h"
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
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020b32ec.h"
#include "Main/Unknown/code_020b2000.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_020a128c.h"
#include "Main/Unknown/code_020c3e44.h"
#include "Main/Unknown/code_020c214c.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020be000.h"
#include "Main/Unknown/code_020c6000.h"
#include "Main/Kart/KartTimes.h"

void func_020aeb7c(void) {
    BOOL subScreenEnabled;
    BOOL d;
    BOOL b;
    BOOL c;
    BOOL e;
    s32 v;

    UpdateRaceLinkLevel();
    if (gRaceMultiConfig->mRaceKind - 3 <= 3) {
        return;
    }
    if (r2d_sStatus->mEnabled == FALSE) {
        return;
    }
    switch (gRaceMultiConfig->mMode) {
        case MODE_GRAND_PRIX:
            if (rstat_hasDriverFinished(Race_GetPlayerId()) != 0 && r2d_sStatus->mShowLapTime == 0) {
                if (gRaceMultiConfig->mRaceKind == RACE_KIND_NORMAL) {
                    if (r2d_sStatus->mUnk_83c != FALSE) {
                        r2d_sStatus->mSubScreenEnabled = FALSE;
                    } else {
                        r2d_sStatus->mSubScreenEnabled = TRUE;
                        r2d_sStatus->mSubScreenState = 4;
                        r2d_sStatus->mUnk_83c = TRUE;
                        r2d_sStatus->mUnk_840 = TRUE;
                        r2d_sStatus->mUnk_850 = 0xc;
                    }
                } else if (r2d_sStatus->mUnk_83c == FALSE) {
                    r2d_sStatus->mUnk_83c = TRUE;
                    r2d_sStatus->mUnk_840 = TRUE;
                    r2d_sStatus->mUnk_850 = 0xc;
                }
            } else {
                subScreenEnabled = FALSE;
                b = FALSE;
                c = FALSE;
                if (gRaceMultiConfig->mRaceKind != RACE_KIND_DEMO && gRaceMultiConfig->mRaceKind != 4) {
                    c = TRUE;
                }
                if (c != FALSE) {
                    if (rchoi_getIsExittingRace() == 0) {
                        b = TRUE;
                    }
                }
                if (b != FALSE) {
                    d = TRUE;
                    if ((u16) (data_0217562c[input_getDirectInputUnitId()].mPressedBits & 0x800) == 0) {
                        e = FALSE;
                        if (rchoi_isMenuVisible() == 0) {
                            if (data_02175680[input_getDirectInputUnitId()].mPressedBits == 5) {
                                e = TRUE;
                            }
                        } else {
                            e = FALSE;
                        }
                        if (e == FALSE) {
                            d = FALSE;
                        }
                    }
                    if (d != FALSE) {
                        subScreenEnabled = TRUE;
                    }
                }
                if (subScreenEnabled != FALSE) {
                    r2d_sStatus->mSubScreenEnabled = TRUE;
                    switch (r2d_sStatus->mSubScreenState) {
                        case 0:
                            r2d_sStatus->mSubScreenState = 1;
                            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x18);
                            break;
                        case 1:
                            r2d_sStatus->mSubScreenState = 0;
                            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x17);
                            break;
                    }
                } else {
                    r2d_sStatus->mSubScreenEnabled = FALSE;
                }
            }
            break;
        case MODE_TIME_ATTACK:
            if (gRaceStatus->mRaceDone != 0 && r2d_sStatus->mShowLapTime == 0) {
                if (r2d_sStatus->mUnk_83c == FALSE) {
                    r2d_sStatus->mUnk_83c = TRUE;
                    r2d_sStatus->mUnk_840 = TRUE;
                    r2d_sStatus->mUnk_850 = 0xc;
                }
            } else {
                subScreenEnabled = FALSE;
                b = FALSE;
                c = FALSE;
                if (gRaceMultiConfig->mRaceKind != RACE_KIND_DEMO && gRaceMultiConfig->mRaceKind != 4) {
                    c = TRUE;
                }
                if (c != FALSE) {
                    if (rchoi_getIsExittingRace() == 0) {
                        b = TRUE;
                    }
                }
                if (b != FALSE) {
                    d = TRUE;
                    if ((u16) (data_0217562c[input_getDirectInputUnitId()].mPressedBits & 0x800) == 0) {
                        e = FALSE;
                        if (rchoi_isMenuVisible() == 0) {
                            if (data_02175680[input_getDirectInputUnitId()].mPressedBits == 5) {
                                e = TRUE;
                            }
                        } else {
                            e = FALSE;
                        }
                        if (e == FALSE) {
                            d = FALSE;
                        }
                    }
                    if (d != FALSE) {
                        subScreenEnabled = TRUE;
                    }
                }
                if (subScreenEnabled != FALSE) {
                    r2d_sStatus->mSubScreenEnabled = TRUE;
                    if (gRaceMultiConfig->mRaceKind != 2) {
                        switch (r2d_sStatus->mSubScreenState) {
                            case 0:
                                r2d_sStatus->mSubScreenState = 1;
                                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x18);
                                break;
                            case 1:
                                r2d_sStatus->mSubScreenState = 0;
                                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x17);
                                break;
                        }
                    } else {
                        switch (r2d_sStatus->mSubScreenState) {
                            case 0:
                                r2d_sStatus->mSubScreenState = 1;
                                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x18);
                                break;
                            case 1:
                                r2d_sStatus->mSubScreenState = 2;
                                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x17);
                                break;
                            case 2:
                                r2d_sStatus->mSubScreenState = 0;
                                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x17);
                                break;
                        }
                    }
                } else {
                    r2d_sStatus->mSubScreenEnabled = FALSE;
                }
            }
            break;
        case MODE_BATTLE:
            if (mgcnt_hasMgEnded() != 0) {
                if (r2d_sStatus->mUnk_83c != FALSE) {
                    r2d_sStatus->mSubScreenEnabled = FALSE;
                } else {
                    r2d_sStatus->mSubScreenEnabled = TRUE;
                    r2d_sStatus->mSubScreenState = 4;
                    r2d_sStatus->mUnk_83c = TRUE;
                    r2d_sStatus->mUnk_840 = TRUE;
                    r2d_sStatus->mUnk_850 = 0x8c;
                }
            } else {
                subScreenEnabled = FALSE;
                b = FALSE;
                c = FALSE;
                if (gRaceMultiConfig->mRaceKind != RACE_KIND_DEMO && gRaceMultiConfig->mRaceKind != 4) {
                    c = TRUE;
                }
                if (c != FALSE) {
                    if (rchoi_getIsExittingRace() == 0) {
                        b = TRUE;
                    }
                }
                if (b != FALSE) {
                    d = TRUE;
                    if ((u16) (data_0217562c[input_getDirectInputUnitId()].mPressedBits & 0x800) == 0) {
                        e = FALSE;
                        if (rchoi_isMenuVisible() == 0) {
                            if (data_02175680[input_getDirectInputUnitId()].mPressedBits == 5) {
                                e = TRUE;
                            }
                        } else {
                            e = FALSE;
                        }
                        if (e == FALSE) {
                            d = FALSE;
                        }
                    }
                    if (d != FALSE) {
                        subScreenEnabled = TRUE;
                    }
                }
                if (subScreenEnabled != FALSE) {
                    r2d_sStatus->mSubScreenEnabled = TRUE;
                    switch (r2d_sStatus->mSubScreenState) {
                        case 0:
                            r2d_sStatus->mSubScreenState = 1;
                            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x18);
                            break;
                        case 1:
                            r2d_sStatus->mSubScreenState = 0;
                            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x17);
                            break;
                    }
                } else {
                    r2d_sStatus->mSubScreenEnabled = FALSE;
                }
            }
            break;
        case MODE_VS:
        case 5:
            if (gRaceStatus->mRaceDone != 0 && gRaceMultiConfig->mRaceKind == RACE_KIND_NORMAL) {
                if (r2d_sStatus->mUnk_838 == FALSE) {
                    r2d_sStatus->mSubScreenEnabled = TRUE;
                    r2d_sStatus->mSubScreenState = 4;
                    r2d_sStatus->mUnk_838 = TRUE;
                    if (r2d_sStatus->mUnk_83c == FALSE) {
                        r2d_sStatus->mUnk_83c = TRUE;
                        r2d_sStatus->mUnk_840 = TRUE;
                        r2d_sStatus->mUnk_850 = 0x8c;
                    }
                } else {
                    r2d_sStatus->mSubScreenEnabled = FALSE;
                }
            } else if (rstat_hasDriverFinished(Race_GetPlayerId()) != 0 && gRaceMultiConfig->mRaceKind == RACE_KIND_NORMAL) {
                if (r2d_sStatus->mUnk_83c == FALSE) {
                    r2d_sStatus->mSubScreenEnabled = TRUE;
                    r2d_sStatus->mSubScreenState = 0;
                    r2d_sStatus->mUnk_83c = TRUE;
                    r2d_sStatus->mUnk_840 = TRUE;
                    r2d_sStatus->mUnk_850 = 0x8c;
                } else {
                    subScreenEnabled = FALSE;
                    b = FALSE;
                    c = FALSE;
                    if (gRaceMultiConfig->mRaceKind != RACE_KIND_DEMO && gRaceMultiConfig->mRaceKind != 4) {
                        c = TRUE;
                    }
                    if (c != FALSE) {
                        if (rchoi_getIsExittingRace() == 0) {
                            b = TRUE;
                        }
                    }
                    if (b != FALSE) {
                        d = TRUE;
                        if ((u16) (data_0217562c[input_getDirectInputUnitId()].mPressedBits & 0x800) == 0) {
                            e = FALSE;
                            if (rchoi_isMenuVisible() == 0) {
                                if (data_02175680[input_getDirectInputUnitId()].mPressedBits == 5) {
                                    e = TRUE;
                                }
                            } else {
                                e = FALSE;
                            }
                            if (e == FALSE) {
                                d = FALSE;
                            }
                        }
                        if (d != FALSE) {
                            subScreenEnabled = TRUE;
                        }
                    }
                    if (subScreenEnabled != FALSE) {
                        r2d_sStatus->mSubScreenEnabled = TRUE;
                        switch (r2d_sStatus->mSubScreenState) {
                            case 0:
                                r2d_sStatus->mSubScreenState = 3;
                                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x18);
                                break;
                            case 3:
                                r2d_sStatus->mSubScreenState = 0;
                                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x17);
                                break;
                        }
                    } else {
                        r2d_sStatus->mSubScreenEnabled = FALSE;
                    }
                }
            } else {
                subScreenEnabled = FALSE;
                b = FALSE;
                c = FALSE;
                if (gRaceMultiConfig->mRaceKind != RACE_KIND_DEMO && gRaceMultiConfig->mRaceKind != 4) {
                    c = TRUE;
                }
                if (c != FALSE) {
                    if (rchoi_getIsExittingRace() == 0) {
                        b = TRUE;
                    }
                }
                if (b != FALSE) {
                    d = TRUE;
                    if ((u16) (data_0217562c[input_getDirectInputUnitId()].mPressedBits & 0x800) == 0) {
                        e = FALSE;
                        if (rchoi_isMenuVisible() == 0) {
                            if (data_02175680[input_getDirectInputUnitId()].mPressedBits == 5) {
                                e = TRUE;
                            }
                        } else {
                            e = FALSE;
                        }
                        if (e == FALSE) {
                            d = FALSE;
                        }
                    }
                    if (d != FALSE) {
                        subScreenEnabled = TRUE;
                    }
                }
                if (subScreenEnabled != FALSE) {
                    r2d_sStatus->mSubScreenEnabled = TRUE;
                    switch (r2d_sStatus->mSubScreenState) {
                        case 0:
                            r2d_sStatus->mSubScreenState = 1;
                            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x18);
                            break;
                        case 1:
                            r2d_sStatus->mSubScreenState = 0;
                            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x17);
                            break;
                    }
                } else {
                    r2d_sStatus->mSubScreenEnabled = FALSE;
                }
            }
            break;
        case MODE_MISSION_RUN:
            if (rstat_isMrWinDelayOver() != FALSE) {
                if (r2d_sStatus->mUnk_83c == FALSE) {
                    r2d_sStatus->mUnk_83c = TRUE;
                    r2d_sStatus->mUnk_840 = TRUE;
                    if (rstat_hasDriverFinished((u16) gRaceMultiConfig->mEntryIndex) != 0) {
                        v = gRaceStatus->mEntryEndKind;
                    } else {
                        v = 6;
                    }
                    if (v == 0) {
                        r2d_sStatus->mUnk_850 = 0xaf;
                    }
                }
            } else if (gRaceStatus->mRaceDone != 0) {
                if (rstat_hasDriverFinished((u16) gRaceMultiConfig->mEntryIndex) != 0) {
                    v = gRaceStatus->mEntryEndKind;
                } else {
                    v = 6;
                }
                if (v != 0) {
                    r2d_sStatus->mUnk_84c = 1;
                }
            }
            if ((u16) (data_0217562c[input_getDirectInputUnitId()].mPressedBits & 0x800) != 0) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x19);
            }
            r2d_sStatus->mSubScreenEnabled = FALSE;
            break;
    }
    if (r2d_sStatus->mSubScreenEnabled != FALSE) {
        switch (r2d_sStatus->mSubScreenState) {
            case 0:
                mpicn_update();
                break;
            case 1:
            case 2:
            case 3:
                mpicn_update();
                r2d_updateMapPath();
                break;
            case 4:
            case 5:
                r2dres_update();
                break;
            case 6:
                r2dtar_update();
                break;
        }
    }
    if (r2d_sStatus->mUnk_90c != FALSE) {
        return;
    }
    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        v = (gRaceMultiConfig->mMode == MODE_MISSION_RUN ? gRaceMultiConfig->mMissionTableColumn : -1) == 9;
    } else {
        v = 0;
    }
    if (v == 0) {
        return;
    }
    if (gRaceMultiConfig->mMode != MODE_MISSION_RUN) {
        v = 0;
    } else {
        v = mgcnt_hasMgEnded();
    }
    if (v == 0) {
        return;
    }
    if (gRaceMultiConfig->mMode != MODE_MISSION_RUN) {
        v = 0;
    } else {
        v = mgcnt_isDriverDead(Race_GetPlayerId());
    }
    if (v != 0) {
        gStruct217B488->mUnk_10 = 0;
    } else {
        gStruct217B488->mUnk_10 = r2d_sStatus->mUnk_910 == 0;
    }
    r2d_sStatus->mUnk_90c = TRUE;
}
