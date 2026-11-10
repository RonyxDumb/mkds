#include "Main/Unknown/code_020b2574.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020b24e4.h"
#include "Main/Unknown/code_020b252c.h"
#include "Main/Unknown/code_020b29b0.h"
#include "Main/Unknown/code_020b29c4.h"
#include "Main/Unknown/code_020b2a4c.h"
#include "Main/Unknown/code_020b2a74.h"
#include "Main/Unknown/code_020b2b24.h"
#include "Main/Unknown/code_020b2b54.h"
#include "Main/Unknown/code_020b2b70.h"
#include "Main/Unknown/code_020b2c80.h"
#include "Main/Unknown/code_020b2e98.h"
#include "Main/Unknown/code_020b2ec0.h"
#include "Main/Unknown/code_020b2ecc.h"
#include "Main/Unknown/code_020b3278.h"
#include "Main/Unknown/code_020b32ec.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_020b1de4.h"

#pragma thumb on
#pragma optimize_for_size on
void UpdateChoisesS(void) {
    s32 a;

    gChoisesS->mPrevOpenDuringRace = gChoisesS->mOpenDuringRace;
    gChoisesS->mCycleFrames = gChoisesS->mCycleFrames + 1;
    if (gChoisesS->mCycleFrames >= 0x32) {
        gChoisesS->mCycleFrames = 0;
    }
    if (ChoisesSIsBackupBusy() != 0) {
        return;
    }
    if ((ChoisesSGetCurrentMode() == MODE_GRAND_PRIX || ChoisesSGetCurrentMode() == MODE_TIME_ATTACK) &&
        ChoisesSGetCurrentRaceKind() == RACE_KIND_REPLAY && func_0203c0bc() != 0) {
        return;
    }
    if (gChoisesS->mPickFrames == 0 && gChoisesS->mCloseFrames == 0 && IsChoisesSPickLocked() == 0) {
        if (func_020b2bc8() != 0) {
            if (IsChoisesSOpenAllowedAfterRace() != 0) {
                if (ChoisesSGetCurrentMode() == MODE_MISSION_RUN && func_020b2b5c() != 0 && func_020b2f58() != 0) {
                    if (ChoisesSGetNewBits(GetChoisesSInputSlot(), PAD_KEY_A) != 0 ||
                        ChoisesSIsSlotPairNew(GetChoisesSInputSlot()) != 0) {
                        gChoisesS->mPickedValue = 10;
                        gChoisesS->mSelectedValue = gChoisesS->mPickedValue;
                        gChoisesS->mPickLocked = 1;
                        StartChoisesSSelectedValueSeq();
                    }
                } else if (ChoisesSGetCurrentMode() == MODE_MISSION_RUN && func_020b2ecc() != 0) {
                    if (ChoisesSGetNewBits(GetChoisesSInputSlot(), PAD_KEY_A) != 0 ||
                        ChoisesSIsSlotPairNew(GetChoisesSInputSlot()) != 0) {
                        gChoisesS->mPickedValue = 6;
                        gChoisesS->mSelectedValue = gChoisesS->mPickedValue;
                        gChoisesS->mPickLocked = 1;
                        StartChoisesSSelectedValueSeq();
                        func_020b2a60(1);
                    }
                } else if (ChoisesSGetCurrentMode() == MODE_MISSION_RUN && func_020b2b5c() != 0) {
                    if (ChoisesSGetNewBits(GetChoisesSInputSlot(), PAD_KEY_A) != 0 ||
                        ChoisesSIsSlotPairNew(GetChoisesSInputSlot()) != 0) {
                        gChoisesS->mPickedValue = 6;
                        gChoisesS->mSelectedValue = gChoisesS->mPickedValue;
                        gChoisesS->mPickLocked = 1;
                        StartChoisesSSelectedValueSeq();
                    }
                } else if (ChoisesSGetNewBits(GetChoisesSInputSlot(), 8) != 0) {
                    if (IsChoisesSOpen() != 0) {
                        RaiseSndHandleVolumes();
                        gChoisesS->mCloseFrames = 1;
                    } else {
                        LowerSndHandleVolumes();
                        SetChoisesSOpen(1);
                    }
                } else if (MoveChoisesSSelectedValueByTouch() != 0) {
                    gChoisesS->mPickFrames = 1;
                } else if (ChoisesSGetNewBits(GetChoisesSInputSlot(), PAD_KEY_A) != 0) {
                    if (IsChoisesSOpen() != 0) {
                        if (gChoisesS->mSelectedValue == 0) {
                            RaiseSndHandleVolumes();
                        } else {
                            StartChoisesSSelectedValueSeq();
                        }
                        gChoisesS->mPickFrames = 1;
                        gChoisesS->mPickStartedOnSelected = TRUE;
                    } else {
                        LowerSndHandleVolumes();
                        SetChoisesSOpen(1);
                    }
                } else if (ChoisesSGetNewBits(GetChoisesSInputSlot(), PAD_KEY_B) != 0) {
                    if (IsChoisesSOpen() != 0) {
                        RaiseSndHandleVolumes();
                        gChoisesS->mCloseFrames = 1;
                    }
                } else if (GetNewOrRepeatBits(GetChoisesSInputSlot(), PAD_KEY_UP) != 0) {
                    MoveChoisesSSelectedValue(-1);
                } else if (GetNewOrRepeatBits(GetChoisesSInputSlot(), PAD_KEY_DOWN) != 0) {
                    MoveChoisesSSelectedValue(1);
                }
            }
        } else if (IsChoisesSOpenAllowedDuringRace() != 0) {
            if (ChoisesSGetNewBits(GetChoisesSInputSlot(), 8) != 0) {
                if (IsChoisesSOpen() != 0) {
                    RaiseSndHandleVolumes();
                    gChoisesS->mCloseFrames = 1;
                } else {
                    LowerSndHandleVolumes();
                    SetChoisesSOpen(1);
                }
            } else if (MoveChoisesSSelectedValueByTouch() != 0) {
                gChoisesS->mPickFrames = 1;
            } else if (ChoisesSGetNewBits(GetChoisesSInputSlot(), PAD_KEY_A) != 0) {
                if (IsChoisesSOpen() != 0) {
                    if (gChoisesS->mSelectedValue == 0) {
                        RaiseSndHandleVolumes();
                    } else {
                        StartChoisesSSelectedValueSeq();
                    }
                    gChoisesS->mPickFrames = 1;
                    gChoisesS->mPickStartedOnSelected = TRUE;
                }
            } else if (ChoisesSGetNewBits(GetChoisesSInputSlot(), PAD_KEY_B) != 0) {
                if (IsChoisesSOpen() != 0) {
                    RaiseSndHandleVolumes();
                    gChoisesS->mCloseFrames = 1;
                }
            } else if (GetNewOrRepeatBits(GetChoisesSInputSlot(), PAD_KEY_UP) != 0) {
                MoveChoisesSSelectedValue(-1);
            } else if (GetNewOrRepeatBits(GetChoisesSInputSlot(), PAD_KEY_DOWN) != 0) {
                MoveChoisesSSelectedValue(1);
            }
        }
    }
    a = gChoisesS->mPickFrames;
    if (a != 0) {
        gChoisesS->mPickFrames = a + 1;
        if (gChoisesS->mPickFrames > 0xf) {
            if (func_020b2bc8() != 0) {
                if (IsChoisesSOpen() != 0) {
                    gChoisesS->mPickedValue = gChoisesS->mSelectedValue;
                    SetChoisesSOpen(0);
                } else {
                    SetChoisesSOpen(1);
                }
            } else if (IsChoisesSOpen() != 0) {
                gChoisesS->mPickedValue = gChoisesS->mSelectedValue;
                SetChoisesSOpen(0);
            }
            gChoisesS->mPickFrames = 0;
            gChoisesS->mPickStartedOnSelected = FALSE;
        }
    }
    a = gChoisesS->mCloseFrames;
    if (a != 0) {
        gChoisesS->mCloseFrames = a + 1;
        if (gChoisesS->mCloseFrames > 4) {
            if (func_020b2bc8() != 0) {
                if (IsChoisesSOpen() != 0) {
                    SetChoisesSOpen(0);
                } else {
                    SetChoisesSOpen(1);
                }
            } else if (IsChoisesSOpen() != 0) {
                SetChoisesSOpen(0);
            }
            gChoisesS->mCloseFrames = 0;
        }
    }
    if (ChoisesSGetConnectionKind() != 0 && ChoisesSGetCurrentMode() == 5 && func_020b2bc8() != 0) {
        gChoisesS->mAutoPickFrames = gChoisesS->mAutoPickFrames + 1;
        if (gChoisesS->mAutoPickFrames > 0x384) {
            gChoisesS->mPickedValue = GetCourseNumber() != 4 ? 2 : 7;
        }
    }
    if (GetChoisesSOpenDuringRace() != 0) {
        a = gChoisesS->mUnk_030;
        gChoisesS->mUnk_030 = a + 1;
        if (a >= 1) {
            gChoisesS->mUnk_02c = 2;
            gChoisesS->mUnk_030 = 1;
        }
    } else {
        gChoisesS->mUnk_02c = 0;
        gChoisesS->mUnk_030 = 0;
    }
}
#pragma thumb off
