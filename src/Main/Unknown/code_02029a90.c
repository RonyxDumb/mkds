#include "Main/Unknown/code_02029a90.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/code_02125da0.h"

#pragma thumb on
void ReleaseSceneTextWrapper(void) {
    u32 unused;
    ReleaseSceneText();
}
#pragma thumb off

#pragma thumb on
void WriteSceneTextRegistersWrapper(void) {
    u32 unused;
    WriteSceneTextRegisters();
}
#pragma thumb off
