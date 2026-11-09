#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/code_02126700.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/unk_0217d000.h"

#pragma thumb on

void AdvanceSceneText(void) {
    if (gSceneText->mUseTxtSystem != FALSE) {
        AdvanceTxtSystem();
    }
    if (gSceneText->mUseSelectChoises != FALSE) {
        AdvanceSelectChoises();
    }
    if (gSceneText->mUnk_08 != FALSE) {
        AdvanceSelectReturn();
    }
}

void WriteSceneTextRegisters(void) {
    if (gSceneText->mUseTxtSystem != FALSE) {
        WriteTxtSystemRegisters();
    }
    if (gSceneText->mUseSelectChoises != FALSE) {
        WriteSelectChoisesRegisters();
    }
    if (gSceneText->mUnk_08 != FALSE) {
        WriteSelectReturnRegisters();
    }
}

#pragma thumb off
