#include "03/code_021c97c0.h"
#include "03/code_021bf410.h"
#include "03/code_021bf4dc.h"
#include "03/code_021bf810.h"
#include "03/code_021c99a8.h"
#include "03/code_021cb11c.h"
#include "03/code_021cd2e0.h"
#include "03/code_021cdbd0.h"
#include "03/code_021cea3c.h"
#include "03/code_021cef90.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/code_021d254c.h"
#include "03/unk_021d7000.h"
#include "code_0214b824.h"

void UpdateExchangeEntryMessageResult(void) {
    int messageAnswer;
    messageAnswer = func_ov003_021cef80();
    if (messageAnswer == 0) {
        StartSoundSeq(6);
        func_ov003_021cef90();
        SetUpdateFunction(UpdateExchangeEntryMessageClose);
    }
}

void UpdateExchangeEntryMessageClose(void) {
    int messageOpen;
    messageOpen = func_ov003_021cef6c();
    if (messageOpen == 0) {
        SetUpdateFunction(StartExchangeEntryClose);
    }
}

void SetupRecordSaved(void) {
    LoadRecordSavedFilesAndSetBgCnt();
    LoadHlSetScr();
    func_ov003_021cd6d0();
    SetUpdateFunction(StartRecordSavedFadeIn);
}

void LoadRecordSavedFilesAndSetBgCnt(void) {
    void *jbBgStep3NcgName = &gJbBgStep3NcgName4;
    void *bg2CharLoader = &GX_LoadBG2Char;
    u32 bg2CharLoadResult = LoadFileToVram(jbBgStep3NcgName, bg2CharLoader);
    void *ybBgStep3NclName = &gYbBgStep3NclName4;
    void *bgPlttLoader = &GX_LoadBGPltt;
    u32 bgPlttLoadResult = LoadFileToVram(ybBgStep3NclName, bgPlttLoader);
    void *xb4NoneNscName = &gXb4NoneNscName;
    void *bg2ScrLoader = &GX_LoadBG2Scr;
    u32 bg2ScrLoadResult = LoadFileToVram(xb4NoneNscName, bg2ScrLoader);
    u32 subBg0CntAddress = 0x4001008u;
    u32 subBg0CntValue = (*(u16 *) ((subBg0CntAddress) + (0)));
    u32 subBg0CntCleared = ((subBg0CntValue) & ~(0x3u));
    u32 subBg0CntNew = ((subBg0CntCleared) | (0x3u));
    u32 subBg1CntAddress;
    u32 subBg1CntValue;
    u32 subBg1CntCleared;
    u32 subBg1CntNew;
    u32 mainBg1CntAddress;
    u32 mainBg1CntValue;
    u32 mainBg1CntCleared;
    u32 mainBg1CntNew;
    u32 mainBg2CntAddress;
    u32 mainBg2CntValue;
    u32 mainBg2CntCleared;
    u32 mainBg2CntNew;
    *(u16 *) ((subBg0CntAddress) + (0)) = subBg0CntNew;
    subBg1CntAddress = 0x400100au;
    subBg1CntValue = (*(u16 *) ((subBg1CntAddress) + (0)));
    subBg1CntCleared = ((subBg1CntValue) & ~(0x3u));
    subBg1CntNew = ((subBg1CntCleared) | (0x3u));
    *(u16 *) ((subBg1CntAddress) + (0)) = subBg1CntNew;
    mainBg1CntAddress = 0x400000au;
    mainBg1CntValue = (*(u16 *) ((mainBg1CntAddress) + (0)));
    mainBg1CntCleared = ((mainBg1CntValue) & ~(0x3u));
    mainBg1CntNew = ((mainBg1CntCleared) | (0x3u));
    *(u16 *) ((mainBg1CntAddress) + (0)) = mainBg1CntNew;
    mainBg2CntAddress = 0x400000cu;
    mainBg2CntValue = (*(u16 *) ((mainBg2CntAddress) + (0)));
    mainBg2CntCleared = ((mainBg2CntValue) & ~(0x3u));
    mainBg2CntNew = ((mainBg2CntCleared) | (0x3u));
    *(u16 *) ((mainBg2CntAddress) + (0)) = mainBg2CntNew;
}

void StartRecordSavedFadeIn(void) {
    StartBlendBrightnessFade(2, 1, 1, 8);
    StartBlendBrightnessFade(2, 0, 0x14, 8);
    CombineDispcntBits(1, 1);
    CombineDispcntBits(0, 0x14);
    SetUpdateFunction(UpdateRecordSavedFadeIn);
}

void UpdateRecordSavedFadeIn(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if ((fadeSlotBusy == 0) && (fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(0), fadeSlotBusy == 0)) {
        func_ov003_021cefc0(0x96, 5, 1, 0xffffffff, 0);
        SetUpdateFunction(UpdateRecordSaved);
    }
}

void UpdateRecordSaved(void) {
    int messageOpen;
    UpdateRecordSavedInputNop();
    UpdateRecordSavedNop();
    messageOpen = func_ov003_021cef6c();
    if (messageOpen == 0) {
        SetUpdateFunction(StartRecordSavedFadeOut);
    }
}

void UpdateRecordSavedInputNop(void) {}

void UpdateRecordSavedNop(void) {}

void StartRecordSavedFadeOut(void) {
    StartBlendBrightnessFade(3, 1, 1, 8);
    StartBlendBrightnessFade(3, 0, 0x14, 8);
    SetUpdateFunction(UpdateRecordSavedRelease);
}

void UpdateRecordSavedRelease(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if ((fadeSlotBusy == 0) && (fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(0), fadeSlotBusy == 0)) {
        HideSubScreenMessage();
        ClearDispcntBits(1, 1);
        ClearDispcntBits(0, 0x14);
        SetPrimaryMenuPair(2, 1);
        SetUpdateFunction(CreateAp);
    }
}
