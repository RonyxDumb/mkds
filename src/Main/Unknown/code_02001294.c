#include "Main/Unknown/code_02001294.h"
#include "Main/Unknown/code_02001000.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_02125ebc.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02126230.h"
#include "Main/Unknown/code_02126248.h"
#include "01/code_021956dc.h"

void logo_waitSaveBusyStateUpdate(void) {
    s32 v1;
    StateMachine *stateMachine;
    s32 v3;
    LogoScene *scene;
    if (gSaveData->mBusy == 0) {
        if (gSaveCore->mBackupEnabled != 0) {
            v1 = gSaveCore->mCommandRunning;
        } else {
            v1 = 0;
        }
    } else {
        v1 = 1;
    }
    if (v1 != 0) {
        return;
    }
    v3 = gSaveData->mReadStatus;
    if (v3 != 0) {
        if (v3 == 3) {
            logo_sLogoState->mUnk_2c_1 = 1;
            stateMachine = &logo_sLogoState->mStateMachine;
            stateMachine->mNextState = 2;
            stateMachine->mNextStateRequested = 1;
        } else if (gSaveCore->mErrorCode == 4) {
            logo_sLogoState->mUnk_2c_1 = 0;
            stateMachine = &logo_sLogoState->mStateMachine;
            stateMachine->mNextState = 6;
            stateMachine->mNextStateRequested = 1;
        } else {
            stateMachine = &logo_sLogoState->mStateMachine;
            stateMachine->mNextState = 8;
            stateMachine->mNextStateRequested = 1;
        }
    } else {
        scene = logo_sLogoState;
        if (scene->mUnk_2c_0 != 0) {
            stateMachine = &scene->mStateMachine;
            stateMachine->mNextState = 5;
            stateMachine->mNextStateRequested = 1;
        } else {
            stateMachine = &scene->mStateMachine;
            stateMachine->mNextState = 8;
            stateMachine->mNextStateRequested = 1;
        }
    }
}

void logo_corruptedMsgStateInit(void) {
    void *message;
    message = jn_msg_getMessage(logo_sLogoState->mCommonMessages, 125);
    SetupTxtSystemSubTextButton(message, jn_msg_getMessage(logo_sLogoState->mCommonMessages, 4));
}

void logo_corruptedMsgStateUpdate(void) {
    StateMachine *stateMachine;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() == 0) {
        return;
    }
    stateMachine = &logo_sLogoState->mStateMachine;
    stateMachine->mNextState = 3;
    stateMachine->mNextStateRequested = 1;
}

void logo_corruptedErasingMsgStateInit(void) {
    void *message;
    savd_repairErrorsAsync();
    message = jn_msg_getMessage(logo_sLogoState->mCommonMessages, 126);
    SetupTxtSystemSubTextEx(message, 1, 1, 1, 0, 1);
    logo_sLogoState->mSubTextFrames = 0;
}

void logo_corruptedErasingMsgStateUpdate(void) {
    s32 v1;
    StateMachine *stateMachine;
    logo_sLogoState->mSubTextFrames = logo_sLogoState->mSubTextFrames + 1;
    if (IsTxtSystemState2AfterState1() != 0) {
        sfx_2105AC0(34);
    }
    if (gSaveData->mBusy == 0) {
        if (gSaveCore->mBackupEnabled != 0) {
            v1 = gSaveCore->mCommandRunning;
        } else {
            v1 = 0;
        }
    } else {
        v1 = 1;
    }
    if (v1 != 0) {
        return;
    }
    if (IsTxtSystemState2NoCloseRequest() == 0) {
        return;
    }
    if (logo_sLogoState->mSubTextFrames > 90) {
        stateMachine = &logo_sLogoState->mStateMachine;
        stateMachine->mNextState = 4;
        stateMachine->mNextStateRequested = 1;
    }
}

void logo_corruptedDeletedMsgStateInit(void) {
    void *message;
    SetTxtSystemOpenSoundId(33);
    message = jn_msg_getMessage(logo_sLogoState->mCommonMessages, 128);
    SetupTxtSystemSubTextButton(message, jn_msg_getMessage(logo_sLogoState->mCommonMessages, 4));
}

void logo_corruptedDeletedMsgStateUpdate(void) {
    StateMachine *stateMachine;
    if (GetTxtSystemDone() != 0) {
        SetTxtSystemOpenSoundId(35);
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() == 0) {
        return;
    }
    stateMachine = &logo_sLogoState->mStateMachine;
    stateMachine->mNextState = 8;
    stateMachine->mNextStateRequested = 1;
}

void logo_eraseAllConfirmStateInit(void) {
    void *commonMessages;
    void *message;
    void *firstButtonMessage;
    void *secondButtonMessage;
    commonMessages = arc_get2dArcFile(aCommon_bmg_36);
    message = jn_msg_getMessage(commonMessages, 124);
    firstButtonMessage = jn_msg_getMessage(commonMessages, 0);
    secondButtonMessage = jn_msg_getMessage(commonMessages, 1);
    SetupTxtSystemSubTextTwoButtons(message, firstButtonMessage, secondButtonMessage, 1);
}

void logo_eraseAllConfirmStateUpdate(void) {
    StateMachine *stateMachine;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() == 0) {
        return;
    }
    if (GetTxtSystemSelectedIndex() == 0) {
        stateMachine = &logo_sLogoState->mStateMachine;
        stateMachine->mNextState = 6;
        stateMachine->mNextStateRequested = 1;
        return;
    }
    stateMachine = &logo_sLogoState->mStateMachine;
    stateMachine->mNextState = 8;
    stateMachine->mNextStateRequested = 1;
}

void logo_eraseAllErasingMsgStateInit(void) {
    void *message;
    savd_eraseAllAsync();
    if (logo_sLogoState->mUnk_2c_0 == 0) {
        return;
    }
    message = jn_msg_getMessage(logo_sLogoState->mCommonMessages, 126);
    SetupTxtSystemSubTextEx(message, 1, 1, 1, 0, 1);
    logo_sLogoState->mSubTextFrames = 0;
}

void logo_eraseAllErasingMsgStateUpdate(void) {
    LogoScene *scene;
    s32 v2;
    StateMachine *stateMachine;
    logo_sLogoState->mSubTextFrames = logo_sLogoState->mSubTextFrames + 1;
    scene = logo_sLogoState;
    if (scene->mUnk_2c_0 != 0) {
        if (IsTxtSystemState2AfterState1() != 0) {
            sfx_2105AC0(34);
        }
        if (gSaveData->mBusy == 0) {
            if (gSaveCore->mBackupEnabled != 0) {
                v2 = gSaveCore->mCommandRunning;
            } else {
                v2 = 0;
            }
        } else {
            v2 = 1;
        }
        if (v2 != 0) {
            return;
        }
        if (IsTxtSystemState2NoCloseRequest() == 0) {
            return;
        }
        if (logo_sLogoState->mSubTextFrames > 90) {
            stateMachine = &logo_sLogoState->mStateMachine;
            stateMachine->mNextState = 7;
            stateMachine->mNextStateRequested = 1;
        }
    } else {
        if (gSaveData->mBusy == 0) {
            if (gSaveCore->mBackupEnabled != 0) {
                v2 = gSaveCore->mCommandRunning;
            } else {
                v2 = 0;
            }
        } else {
            v2 = 1;
        }
        if (v2 == 0) {
            stateMachine = &scene->mStateMachine;
            stateMachine->mNextState = 8;
            stateMachine->mNextStateRequested = 1;
        }
    }
}

void logo_eraseAllDoneMsgStateInit(void) {
    void *message;
    SetTxtSystemOpenSoundId(33);
    message = jn_msg_getMessage(logo_sLogoState->mCommonMessages, 127);
    SetupTxtSystemSubTextButton(message, jn_msg_getMessage(logo_sLogoState->mCommonMessages, 4));
}

void logo_eraseAllDoneMsgStateUpdate(void) {
    StateMachine *stateMachine;
    if (GetTxtSystemDone() != 0) {
        SetTxtSystemOpenSoundId(35);
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() == 0) {
        return;
    }
    stateMachine = &logo_sLogoState->mStateMachine;
    stateMachine->mNextState = 8;
    stateMachine->mNextStateRequested = 1;
}
