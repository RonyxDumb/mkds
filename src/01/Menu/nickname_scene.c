#include "01/Menu/nickname_scene.h"
#include "01/Menu/option_select_menu.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/System/heap.h"
#include "Main/Graphics/oam.h"
#include "Main/Graphics/back_screen.h"
#include "Main/Menu/txt_system.h"
#include "Main/Menu/select_return.h"
#include "01/Menu/option_states.h"
#include "01/code_02192000.h"
#include "01/code_02199000.h"
#include "01/Menu/option_nickname_scenes.h"
#include "Main/Graphics/font_and_player_character.h"
#include "01/unk_021a6000.h"
#include "Main/Save/backup_first_block_write_wrapper.h"
#include "code_0214d018.h"
#include "Main/Save/ghost_record_file.h"

NicknameScene *gNicknameScene;

void InitNicknameSceneObject(void *heap, s16 a) {
    SceneTextInitParams textParams;

    gNicknameScene = HeapAlloc(heap, sizeof(NicknameScene));
    gNicknameScene->mHeap = heap;
    gNicknameScene->mSceneDisplaySettings = CreateSceneDisplaySettings(heap);
    textParams.mUseTxtSystem = TRUE;
    textParams.mTxtSystemFont = GetFontByIndex(1);
    textParams.mUseCanvas1 = 0;
    textParams.mUseCanvas2 = 1;
    textParams.mUseCanvas3 = 0;
    textParams.mUseSelectChoises = FALSE;
    textParams.mSelectChoisesFont = NULL;
    textParams.mUseSelectReturn = TRUE;
    textParams.mUseBackScreen = TRUE;
    textParams.mBackScreenKind = 0;
    LoadTxtSystemAndSelectChoisesAndSelectReturnData();
    InitSceneText(heap, &textParams);
    gNicknameScene->mUnk_0c = a;
    gNicknameScene->mNextScene = NICKNAME_SCENE_NEXT_NONE;
    gNicknameScene->mState = NICKNAME_SCENE_STATE_WAIT_FADE;
    gNicknameScene->mNextState = gNicknameScene->mState;
    gNicknameScene->mCommonMessages = FindFileInLoadedArchives("common.bmg");
}

void ReleaseNicknameSceneObject(void) {
    ReleaseSceneText();
    gNicknameScene = NULL;
}

void AdvanceNicknameSceneState0(void) {
    void *messageText;
    void *firstButtonText;
    void *secondButtonText;
    if (AreBrightnessFadesClear() != 0) {
        gNicknameScene->mNextState = NICKNAME_SCENE_STATE_FIRST_MESSAGE;
        messageText = GetBmgEntry(gNicknameScene->mCommonMessages, 0xc);
        firstButtonText = GetBmgEntry(gNicknameScene->mCommonMessages, 0);
        secondButtonText = GetBmgEntry(gNicknameScene->mCommonMessages, 1);
        SetupTxtSystemSubTextTwoButtons(messageText, firstButtonText, secondButtonText, 0);
    }
}

void AdvanceNicknameSceneState1(void) {
    void *messageText;
    void *firstButtonText;
    void *secondButtonText;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        if (GetTxtSystemSelectedIndex() == 0) {
            gNicknameScene->mNextState = NICKNAME_SCENE_STATE_SECOND_MESSAGE;
            messageText = GetBmgEntry(gNicknameScene->mCommonMessages, 0xd);
            firstButtonText = GetBmgEntry(gNicknameScene->mCommonMessages, 0);
            secondButtonText = GetBmgEntry(gNicknameScene->mCommonMessages, 1);
            SetupTxtSystemSubTextTwoButtons(messageText, firstButtonText, secondButtonText, 0);
        } else {
            gNicknameScene->mNextScene = SCENE_KEYBOARD;
        }
    }
}

void AdvanceNicknameSceneState2(void) {
    void *messageText;
    void *firstButtonText;
    void *secondButtonText;
    u16 *ownerText;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        if (GetTxtSystemSelectedIndex() == 0) {
            ownerText = gStartupWork->mOwnerText;
            gBackupBuffers->mFirstBlock->mHasPlayerName = 1;
            MI_CpuFill8(gBackupBuffers->mFirstBlock->mPlayerName, 0, 0x14);
            MI_CpuCopy8(ownerText, gBackupBuffers->mFirstBlock->mPlayerName, 0x14);
            WriteBackupFirstBlockWrapper();
            gNicknameScene->mNextState = NICKNAME_SCENE_STATE_THIRD_MESSAGE;
            messageText = GetBmgEntry(gNicknameScene->mCommonMessages, 0x13);
            firstButtonText = GetBmgEntry(gNicknameScene->mCommonMessages, 0);
            secondButtonText = GetBmgEntry(gNicknameScene->mCommonMessages, 1);
            SetupTxtSystemSubTextTwoButtons(messageText, firstButtonText, secondButtonText, 1);
        } else {
            gNicknameScene->mNextScene = SCENE_KEYBOARD;
        }
    }
}

void AdvanceNicknameSceneState3(void) {
    s32 backupBusy;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        if (gBackupBuffers->mBusy == 0) {
            if (gBackupAccess->mBackupEnabled != 0) {
                backupBusy = gBackupAccess->mCommandRunning;
            } else {
                backupBusy = 0;
            }
        } else {
            backupBusy = 1;
        }
        if (backupBusy == 0) {
            if (GetTxtSystemSelectedIndex() == 0) {
                gNicknameScene->mNextScene = SCENE_EMBLEM;
            } else {
                gNicknameScene->mNextScene = SCENE_TITLE;
            }
        }
    }
}

void AdvanceNicknameScene(void) {
    AdvanceSceneText();
    gNicknameScene->mState = gNicknameScene->mNextState;
    switch (gNicknameScene->mState) {
        case NICKNAME_SCENE_STATE_WAIT_FADE:
            AdvanceNicknameSceneState0();
            break;
        case NICKNAME_SCENE_STATE_FIRST_MESSAGE:
            AdvanceNicknameSceneState1();
            break;
        case NICKNAME_SCENE_STATE_SECOND_MESSAGE:
            AdvanceNicknameSceneState2();
            break;
        case NICKNAME_SCENE_STATE_THIRD_MESSAGE:
            AdvanceNicknameSceneState3();
            break;
    }
}

void NicknameWriteSceneTextRegistersWrapper(void) {
    WriteSceneTextRegisters();
}

int GetNicknameSceneNextScene(void) {
    return gNicknameScene->mNextScene;
}
