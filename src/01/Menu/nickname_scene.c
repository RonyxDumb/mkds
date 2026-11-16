#include "01/Menu/nickname_scene.h"
#include "01/Menu/option_select_menu.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/System/heap.h"
#include "Main/Graphics/oam.h"
#include "Main/Graphics/back_screen.h"
#include "Main/Menu/txt_system.h"
#include "Main/Menu/select_return.h"
#include "01/Menu/option_states.h"
#include "01/Menu/option_nickname_scenes.h"
#include "Main/Graphics/font_and_player_character.h"
#include "01/MapObjects/mission_run_map_object_flags.h"
#include "Main/Save/backup_first_block_write_wrapper.h"
#include "cpu_copy_fill.h"
#include "Main/Save/ghost_record_file.h"

NicknameScene *gNicknameScene;

void InitNicknameSceneObject(void *heap, s16 previousScene) {
    SceneTextInitParams textParams;

    gNicknameScene = Mem_AllocateHeap(heap, sizeof(NicknameScene));
    gNicknameScene->mHeap = heap;
    gNicknameScene->mSceneDisplaySettings = CreateLoadSomeDisplayConfig_from_thumb(heap);
    textParams.mUseTxtSystem = TRUE;
    textParams.mTxtSystemFont = GetLoadedFont_from_thumb(1);
    textParams.mUseCanvas1 = 0;
    textParams.mUseCanvas2 = 1;
    textParams.mUseCanvas3 = 0;
    textParams.mUseSelectChoises = FALSE;
    textParams.mSelectChoisesFont = NULL;
    textParams.mUseSelectReturn = TRUE;
    textParams.mUseBackScreen = TRUE;
    textParams.mBackScreenKind = 0;
    PrepareNavigationContextFiles_from_thumb();
    InitializeNavigationContext_from_thumb(heap, &textParams);
    gNicknameScene->mPreviousScene = previousScene;
    gNicknameScene->mNextScene = NICKNAME_SCENE_NEXT_NONE;
    gNicknameScene->mState = NICKNAME_SCENE_STATE_WAIT_FADE;
    gNicknameScene->mNextState = gNicknameScene->mState;
    gNicknameScene->mCommonMessages = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("common.bmg");
}

void ReleaseNicknameSceneObject(void) {
    DisposeNavigationContext_from_thumb();
    gNicknameScene = NULL;
}

void AdvanceNicknameSceneWaitFade(void) {
    void *messageText;
    void *firstButtonText;
    void *secondButtonText;
    if (Bright_IsBothScreensFadedIn() != 0) {
        gNicknameScene->mNextState = NICKNAME_SCENE_STATE_FIRST_MESSAGE;
        messageText = Bmg_GetRawStringPointer_from_thumb(gNicknameScene->mCommonMessages, 0xc);
        firstButtonText = Bmg_GetRawStringPointer_from_thumb(gNicknameScene->mCommonMessages, 0);
        secondButtonText = Bmg_GetRawStringPointer_from_thumb(gNicknameScene->mCommonMessages, 1);
        TextSystem_DisplayDoubleButtonDialog_Simple_from_thumb(messageText, firstButtonText, secondButtonText, 0);
    }
}

void AdvanceNicknameSceneFirstMessage(void) {
    void *messageText;
    void *firstButtonText;
    void *secondButtonText;
    if (TextSystem_WasAnyDialogButtonPressed_from_thumb() != 0) {
        TextSystem_CloseDialog_from_thumb();
        return;
    }
    if (TextSystem_IsDialogFinished_from_thumb() != 0) {
        if (TextSystem_IsButton2Focused_from_thumb() == 0) {
            gNicknameScene->mNextState = NICKNAME_SCENE_STATE_SECOND_MESSAGE;
            messageText = Bmg_GetRawStringPointer_from_thumb(gNicknameScene->mCommonMessages, 0xd);
            firstButtonText = Bmg_GetRawStringPointer_from_thumb(gNicknameScene->mCommonMessages, 0);
            secondButtonText = Bmg_GetRawStringPointer_from_thumb(gNicknameScene->mCommonMessages, 1);
            TextSystem_DisplayDoubleButtonDialog_Simple_from_thumb(messageText, firstButtonText, secondButtonText, 0);
        } else {
            gNicknameScene->mNextScene = SCENE_KEYBOARD;
        }
    }
}

void AdvanceNicknameSceneSecondMessage(void) {
    void *messageText;
    void *firstButtonText;
    void *secondButtonText;
    u16 *ownerText;
    if (TextSystem_WasAnyDialogButtonPressed_from_thumb() != 0) {
        TextSystem_CloseDialog_from_thumb();
        return;
    }
    if (TextSystem_IsDialogFinished_from_thumb() != 0) {
        if (TextSystem_IsButton2Focused_from_thumb() == 0) {
            ownerText = g_GlobalP->mOwnerText;
            g_SaveDataHolder->mFirstBlock->mHasPlayerName = 1;
            Mem_CpuFill8(g_SaveDataHolder->mFirstBlock->mPlayerName, 0, sizeof(g_SaveDataHolder->mFirstBlock->mPlayerName));
            Mem_CpuCopy8(ownerText, g_SaveDataHolder->mFirstBlock->mPlayerName,
                        sizeof(g_SaveDataHolder->mFirstBlock->mPlayerName));
            WriteSaveDataSectionHeaderToSaveData_from_thumb();
            gNicknameScene->mNextState = NICKNAME_SCENE_STATE_THIRD_MESSAGE;
            messageText = Bmg_GetRawStringPointer_from_thumb(gNicknameScene->mCommonMessages, 0x13);
            firstButtonText = Bmg_GetRawStringPointer_from_thumb(gNicknameScene->mCommonMessages, 0);
            secondButtonText = Bmg_GetRawStringPointer_from_thumb(gNicknameScene->mCommonMessages, 1);
            TextSystem_DisplayDoubleButtonDialog_Simple_from_thumb(messageText, firstButtonText, secondButtonText, 1);
        } else {
            gNicknameScene->mNextScene = SCENE_KEYBOARD;
        }
    }
}

void AdvanceNicknameSceneThirdMessage(void) {
    s32 backupBusy;
    if (TextSystem_WasAnyDialogButtonPressed_from_thumb() != 0) {
        TextSystem_CloseDialog_from_thumb();
        return;
    }
    if (TextSystem_IsDialogFinished_from_thumb() != 0) {
        if (g_SaveDataHolder->mBusy == 0) {
            if (g_SaveDataIoManager->mBackupEnabled != 0) {
                backupBusy = g_SaveDataIoManager->mCommandRunning;
            } else {
                backupBusy = 0;
            }
        } else {
            backupBusy = 1;
        }
        if (backupBusy == 0) {
            if (TextSystem_IsButton2Focused_from_thumb() == 0) {
                gNicknameScene->mNextScene = SCENE_EMBLEM;
            } else {
                gNicknameScene->mNextScene = SCENE_TITLE;
            }
        }
    }
}

void AdvanceNicknameScene(void) {
    NavigationContext_OnSceneUpdate_from_thumb();
    gNicknameScene->mState = gNicknameScene->mNextState;
    switch (gNicknameScene->mState) {
        case NICKNAME_SCENE_STATE_WAIT_FADE:
            AdvanceNicknameSceneWaitFade();
            break;
        case NICKNAME_SCENE_STATE_FIRST_MESSAGE:
            AdvanceNicknameSceneFirstMessage();
            break;
        case NICKNAME_SCENE_STATE_SECOND_MESSAGE:
            AdvanceNicknameSceneSecondMessage();
            break;
        case NICKNAME_SCENE_STATE_THIRD_MESSAGE:
            AdvanceNicknameSceneThirdMessage();
            break;
    }
}

void NicknameWriteSceneTextRegistersWrapper(void) {
    NavigationContext_OnSceneVblank_from_thumb();
}

int GetNicknameSceneNextScene(void) {
    return gNicknameScene->mNextScene;
}
