#include "Main/Unknown/code_020aeb7c.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020b2e98.h"
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
#include "Main/Unknown/code_0203c5f8.h"

void UpdateRaceHudSubScreen(void) {
    BOOL subScreenEnabled;
    BOOL switchPressed;
    BOOL switchAllowed;
    BOOL raceKindAllowsSwitch;
    BOOL condition;
    s32 value;

    UpdateRaceLinkLevel();
    if (gRaceSetup->mRaceKind - 3 <= 3) {
        return;
    }
    if (gRaceHud->mEnabled == FALSE) {
        return;
    }
    switch (gRaceSetup->mMode) {
        case MODE_GRAND_PRIX:
            if (IsKartEnded(GetFollowedKartOrEntryIndex()) != 0 && gRaceHud->mShowLapTime == 0) {
                if (gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
                    if (gRaceHud->mGoalMStarted != FALSE) {
                        gRaceHud->mSubScreenEnabled = FALSE;
                    } else {
                        gRaceHud->mSubScreenEnabled = TRUE;
                        gRaceHud->mSubScreenState = 4;
                        gRaceHud->mGoalMStarted = TRUE;
                        gRaceHud->mGoalMUploadPending = TRUE;
                        gRaceHud->mGoalMDelayFrameCount = 0xc;
                    }
                } else if (gRaceHud->mGoalMStarted == FALSE) {
                    gRaceHud->mGoalMStarted = TRUE;
                    gRaceHud->mGoalMUploadPending = TRUE;
                    gRaceHud->mGoalMDelayFrameCount = 0xc;
                }
            } else {
                subScreenEnabled = FALSE;
                switchAllowed = FALSE;
                raceKindAllowsSwitch = FALSE;
                if (gRaceSetup->mRaceKind != RACE_KIND_DEMO && gRaceSetup->mRaceKind != RACE_KIND_START_BATTLE) {
                    raceKindAllowsSwitch = TRUE;
                }
                if (raceKindAllowsSwitch != FALSE) {
                    if (IsChoisesSPickLocked() == 0) {
                        switchAllowed = TRUE;
                    }
                }
                if (switchAllowed != FALSE) {
                    switchPressed = TRUE;
                    if ((u16) (data_0217562c[GetPadInputSlot()].mPressedBits & 0x800) == 0) {
                        condition = FALSE;
                        if (IsChoisesSOpen() == 0) {
                            if (gInputSlots[GetPadInputSlot()].mPair.mNoPairCount == 5) {
                                condition = TRUE;
                            }
                        } else {
                            condition = FALSE;
                        }
                        if (condition == FALSE) {
                            switchPressed = FALSE;
                        }
                    }
                    if (switchPressed != FALSE) {
                        subScreenEnabled = TRUE;
                    }
                }
                if (subScreenEnabled != FALSE) {
                    gRaceHud->mSubScreenEnabled = TRUE;
                    switch (gRaceHud->mSubScreenState) {
                        case 0:
                            gRaceHud->mSubScreenState = 1;
                            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x18);
                            break;
                        case 1:
                            gRaceHud->mSubScreenState = 0;
                            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x17);
                            break;
                    }
                } else {
                    gRaceHud->mSubScreenEnabled = FALSE;
                }
            }
            break;
        case MODE_TIME_ATTACK:
            if (gRaceProgress->mRaceDone != 0 && gRaceHud->mShowLapTime == 0) {
                if (gRaceHud->mGoalMStarted == FALSE) {
                    gRaceHud->mGoalMStarted = TRUE;
                    gRaceHud->mGoalMUploadPending = TRUE;
                    gRaceHud->mGoalMDelayFrameCount = 0xc;
                }
            } else {
                subScreenEnabled = FALSE;
                switchAllowed = FALSE;
                raceKindAllowsSwitch = FALSE;
                if (gRaceSetup->mRaceKind != RACE_KIND_DEMO && gRaceSetup->mRaceKind != RACE_KIND_START_BATTLE) {
                    raceKindAllowsSwitch = TRUE;
                }
                if (raceKindAllowsSwitch != FALSE) {
                    if (IsChoisesSPickLocked() == 0) {
                        switchAllowed = TRUE;
                    }
                }
                if (switchAllowed != FALSE) {
                    switchPressed = TRUE;
                    if ((u16) (data_0217562c[GetPadInputSlot()].mPressedBits & 0x800) == 0) {
                        condition = FALSE;
                        if (IsChoisesSOpen() == 0) {
                            if (gInputSlots[GetPadInputSlot()].mPair.mNoPairCount == 5) {
                                condition = TRUE;
                            }
                        } else {
                            condition = FALSE;
                        }
                        if (condition == FALSE) {
                            switchPressed = FALSE;
                        }
                    }
                    if (switchPressed != FALSE) {
                        subScreenEnabled = TRUE;
                    }
                }
                if (subScreenEnabled != FALSE) {
                    gRaceHud->mSubScreenEnabled = TRUE;
                    if (gRaceSetup->mRaceKind != RACE_KIND_REPLAY) {
                        switch (gRaceHud->mSubScreenState) {
                            case 0:
                                gRaceHud->mSubScreenState = 1;
                                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x18);
                                break;
                            case 1:
                                gRaceHud->mSubScreenState = 0;
                                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x17);
                                break;
                        }
                    } else {
                        switch (gRaceHud->mSubScreenState) {
                            case 0:
                                gRaceHud->mSubScreenState = 1;
                                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x18);
                                break;
                            case 1:
                                gRaceHud->mSubScreenState = 2;
                                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x17);
                                break;
                            case 2:
                                gRaceHud->mSubScreenState = 0;
                                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x17);
                                break;
                        }
                    }
                } else {
                    gRaceHud->mSubScreenEnabled = FALSE;
                }
            }
            break;
        case MODE_BATTLE:
            if (IsWinnerDecidedAndEndReached() != 0) {
                if (gRaceHud->mGoalMStarted != FALSE) {
                    gRaceHud->mSubScreenEnabled = FALSE;
                } else {
                    gRaceHud->mSubScreenEnabled = TRUE;
                    gRaceHud->mSubScreenState = 4;
                    gRaceHud->mGoalMStarted = TRUE;
                    gRaceHud->mGoalMUploadPending = TRUE;
                    gRaceHud->mGoalMDelayFrameCount = 0x8c;
                }
            } else {
                subScreenEnabled = FALSE;
                switchAllowed = FALSE;
                raceKindAllowsSwitch = FALSE;
                if (gRaceSetup->mRaceKind != RACE_KIND_DEMO && gRaceSetup->mRaceKind != RACE_KIND_START_BATTLE) {
                    raceKindAllowsSwitch = TRUE;
                }
                if (raceKindAllowsSwitch != FALSE) {
                    if (IsChoisesSPickLocked() == 0) {
                        switchAllowed = TRUE;
                    }
                }
                if (switchAllowed != FALSE) {
                    switchPressed = TRUE;
                    if ((u16) (data_0217562c[GetPadInputSlot()].mPressedBits & 0x800) == 0) {
                        condition = FALSE;
                        if (IsChoisesSOpen() == 0) {
                            if (gInputSlots[GetPadInputSlot()].mPair.mNoPairCount == 5) {
                                condition = TRUE;
                            }
                        } else {
                            condition = FALSE;
                        }
                        if (condition == FALSE) {
                            switchPressed = FALSE;
                        }
                    }
                    if (switchPressed != FALSE) {
                        subScreenEnabled = TRUE;
                    }
                }
                if (subScreenEnabled != FALSE) {
                    gRaceHud->mSubScreenEnabled = TRUE;
                    switch (gRaceHud->mSubScreenState) {
                        case 0:
                            gRaceHud->mSubScreenState = 1;
                            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x18);
                            break;
                        case 1:
                            gRaceHud->mSubScreenState = 0;
                            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x17);
                            break;
                    }
                } else {
                    gRaceHud->mSubScreenEnabled = FALSE;
                }
            }
            break;
        case MODE_VS:
        case 5:
            if (gRaceProgress->mRaceDone != 0 && gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
                if (gRaceHud->mRaceGoalSShown == FALSE) {
                    gRaceHud->mSubScreenEnabled = TRUE;
                    gRaceHud->mSubScreenState = 4;
                    gRaceHud->mRaceGoalSShown = TRUE;
                    if (gRaceHud->mGoalMStarted == FALSE) {
                        gRaceHud->mGoalMStarted = TRUE;
                        gRaceHud->mGoalMUploadPending = TRUE;
                        gRaceHud->mGoalMDelayFrameCount = 0x8c;
                    }
                } else {
                    gRaceHud->mSubScreenEnabled = FALSE;
                }
            } else if (IsKartEnded(GetFollowedKartOrEntryIndex()) != 0 && gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
                if (gRaceHud->mGoalMStarted == FALSE) {
                    gRaceHud->mSubScreenEnabled = TRUE;
                    gRaceHud->mSubScreenState = 0;
                    gRaceHud->mGoalMStarted = TRUE;
                    gRaceHud->mGoalMUploadPending = TRUE;
                    gRaceHud->mGoalMDelayFrameCount = 0x8c;
                } else {
                    subScreenEnabled = FALSE;
                    switchAllowed = FALSE;
                    raceKindAllowsSwitch = FALSE;
                    if (gRaceSetup->mRaceKind != RACE_KIND_DEMO && gRaceSetup->mRaceKind != RACE_KIND_START_BATTLE) {
                        raceKindAllowsSwitch = TRUE;
                    }
                    if (raceKindAllowsSwitch != FALSE) {
                        if (IsChoisesSPickLocked() == 0) {
                            switchAllowed = TRUE;
                        }
                    }
                    if (switchAllowed != FALSE) {
                        switchPressed = TRUE;
                        if ((u16) (data_0217562c[GetPadInputSlot()].mPressedBits & 0x800) == 0) {
                            condition = FALSE;
                            if (IsChoisesSOpen() == 0) {
                                if (gInputSlots[GetPadInputSlot()].mPair.mNoPairCount == 5) {
                                    condition = TRUE;
                                }
                            } else {
                                condition = FALSE;
                            }
                            if (condition == FALSE) {
                                switchPressed = FALSE;
                            }
                        }
                        if (switchPressed != FALSE) {
                            subScreenEnabled = TRUE;
                        }
                    }
                    if (subScreenEnabled != FALSE) {
                        gRaceHud->mSubScreenEnabled = TRUE;
                        switch (gRaceHud->mSubScreenState) {
                            case 0:
                                gRaceHud->mSubScreenState = 3;
                                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x18);
                                break;
                            case 3:
                                gRaceHud->mSubScreenState = 0;
                                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x17);
                                break;
                        }
                    } else {
                        gRaceHud->mSubScreenEnabled = FALSE;
                    }
                }
            } else {
                subScreenEnabled = FALSE;
                switchAllowed = FALSE;
                raceKindAllowsSwitch = FALSE;
                if (gRaceSetup->mRaceKind != RACE_KIND_DEMO && gRaceSetup->mRaceKind != RACE_KIND_START_BATTLE) {
                    raceKindAllowsSwitch = TRUE;
                }
                if (raceKindAllowsSwitch != FALSE) {
                    if (IsChoisesSPickLocked() == 0) {
                        switchAllowed = TRUE;
                    }
                }
                if (switchAllowed != FALSE) {
                    switchPressed = TRUE;
                    if ((u16) (data_0217562c[GetPadInputSlot()].mPressedBits & 0x800) == 0) {
                        condition = FALSE;
                        if (IsChoisesSOpen() == 0) {
                            if (gInputSlots[GetPadInputSlot()].mPair.mNoPairCount == 5) {
                                condition = TRUE;
                            }
                        } else {
                            condition = FALSE;
                        }
                        if (condition == FALSE) {
                            switchPressed = FALSE;
                        }
                    }
                    if (switchPressed != FALSE) {
                        subScreenEnabled = TRUE;
                    }
                }
                if (subScreenEnabled != FALSE) {
                    gRaceHud->mSubScreenEnabled = TRUE;
                    switch (gRaceHud->mSubScreenState) {
                        case 0:
                            gRaceHud->mSubScreenState = 1;
                            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x18);
                            break;
                        case 1:
                            gRaceHud->mSubScreenState = 0;
                            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x17);
                            break;
                    }
                } else {
                    gRaceHud->mSubScreenEnabled = FALSE;
                }
            }
            break;
        case MODE_MISSION_RUN:
            if (IsFramesSinceFinishPastWait() != FALSE) {
                if (gRaceHud->mGoalMStarted == FALSE) {
                    gRaceHud->mGoalMStarted = TRUE;
                    gRaceHud->mGoalMUploadPending = TRUE;
                    if (IsKartEnded((u16) gRaceSetup->mEntryIndex) != 0) {
                        value = gRaceProgress->mEntryEndKind;
                    } else {
                        value = 6;
                    }
                    if (value == 0) {
                        gRaceHud->mGoalMDelayFrameCount = 0xaf;
                    }
                }
            } else if (gRaceProgress->mRaceDone != 0) {
                if (IsKartEnded((u16) gRaceSetup->mEntryIndex) != 0) {
                    value = gRaceProgress->mEntryEndKind;
                } else {
                    value = 6;
                }
                if (value != 0) {
                    gRaceHud->mGoalMEnabled = 1;
                }
            }
            if ((u16) (data_0217562c[GetPadInputSlot()].mPressedBits & 0x800) != 0) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x19);
            }
            gRaceHud->mSubScreenEnabled = FALSE;
            break;
    }
    if (gRaceHud->mSubScreenEnabled != FALSE) {
        switch (gRaceHud->mSubScreenState) {
            case 0:
                UpdateRaceHudSubScreenCellGroups();
                break;
            case 1:
            case 2:
            case 3:
                UpdateRaceHudSubScreenCellGroups();
                UpdateRaceTaPositions();
                break;
            case 4:
            case 5:
                UpdateRaceGoalS();
                break;
            case 6:
                UpdateRaceNewRecordTa();
                break;
        }
    }
    if (gRaceHud->mUnfilledNotEliminatedSet != FALSE) {
        return;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        value = (gRaceSetup->mMode == MODE_MISSION_RUN ? gRaceSetup->mMissionTableColumn : -1) == 9;
    } else {
        value = 0;
    }
    if (value == 0) {
        return;
    }
    if (gRaceSetup->mMode != MODE_MISSION_RUN) {
        value = 0;
    } else {
        value = IsWinnerDecidedAndEndReached();
    }
    if (value == 0) {
        return;
    }
    if (gRaceSetup->mMode != MODE_MISSION_RUN) {
        value = 0;
    } else {
        value = IsKartEliminated(GetFollowedKartOrEntryIndex());
    }
    if (value != 0) {
        gMenuShared->mUnfilledNotEliminated = 0;
    } else {
        gMenuShared->mUnfilledNotEliminated = gRaceHud->mMissionRunRecordFilled == 0;
    }
    gRaceHud->mUnfilledNotEliminatedSet = TRUE;
}
