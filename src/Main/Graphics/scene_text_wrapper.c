#include "Main/Graphics/scene_text_wrapper.h"
#include "Main/Graphics/scene_text.h"
#include "Main/Graphics/scene_text_init.h"

#pragma thumb on
void ReleaseSceneTextWrapper(void) {
    u32 unused;
    ReleaseSceneText();
}

void WriteSceneTextRegistersWrapper(void) {
    u32 unused;
    WriteSceneTextRegisters();
}
#pragma thumb off
