#include "01/code_0219853c.h"
#include "01/code_02198854.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_02125960.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_0214a000.h"
#include "Main/Unknown/code_02125ebc.h"
#include "Main/Unknown/code_02126230.h"
#include "Main/Unknown/code_02128244.h"
#include "01/code_02192e78.h"
#include "01/code_02192000.h"
#include "01/code_02199000.h"
#include "01/code_0219e824.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_02105000.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_0212b000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02056d40.h"
#include "Main/Unknown/code_02125f54.h"
#include "code_0214d018.h"

NicknameScene *gNicknameScene;

void InitNicknameSceneObject(void *heap, s16 a) {
    SceneTextInitParams textParams;

    gNicknameScene = HeapAlloc(heap, 0x18);
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
    gNicknameScene->mNextScene = -1;
    gNicknameScene->mState = 0;
    gNicknameScene->mNextState = gNicknameScene->mState;
    gNicknameScene->mCommonMessages = FindFileInLoadedArchives("common.bmg");
}

void ReleaseNicknameSceneObject(void) {
    ReleaseSceneText();
    *(u32 *) &gNicknameScene = 0;
}

void AdvanceNicknameSceneState0(void) {
    void *messageText;
    void *firstButtonText;
    void *secondButtonText;
    if (AreBrightnessFadesClear() != 0) {
        gNicknameScene->mNextState = 1;
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
            gNicknameScene->mNextState = 2;
            messageText = GetBmgEntry(gNicknameScene->mCommonMessages, 0xd);
            firstButtonText = GetBmgEntry(gNicknameScene->mCommonMessages, 0);
            secondButtonText = GetBmgEntry(gNicknameScene->mCommonMessages, 1);
            SetupTxtSystemSubTextTwoButtons(messageText, firstButtonText, secondButtonText, 0);
        } else {
            gNicknameScene->mNextScene = 0xe;
        }
    }
}

void AdvanceNicknameSceneState2(void) {
    void *messageText;
    void *firstButtonText;
    void *secondButtonText;
    u8 *ownerText;
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
            gNicknameScene->mNextState = 3;
            messageText = GetBmgEntry(gNicknameScene->mCommonMessages, 0x13);
            firstButtonText = GetBmgEntry(gNicknameScene->mCommonMessages, 0);
            secondButtonText = GetBmgEntry(gNicknameScene->mCommonMessages, 1);
            SetupTxtSystemSubTextTwoButtons(messageText, firstButtonText, secondButtonText, 1);
        } else {
            gNicknameScene->mNextScene = 0xe;
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
                gNicknameScene->mNextScene = 3;
            } else {
                gNicknameScene->mNextScene = 0;
            }
        }
    }
}

void AdvanceNicknameScene(void) {
    AdvanceSceneText();
    gNicknameScene->mState = gNicknameScene->mNextState;
    switch (gNicknameScene->mState) {
        case 0:
            AdvanceNicknameSceneState0();
            break;
        case 1:
            AdvanceNicknameSceneState1();
            break;
        case 2:
            AdvanceNicknameSceneState2();
            break;
        case 3:
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
