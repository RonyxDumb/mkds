#include "Main/System/NtrMain.h"
#include "Main/System/startup.h"
#include "Main/Scene/scene_run_forever.h"

void NtrMain(void) {
    InitializeEverything();
    SetExecuteStart((u32) StartExecuteFunction);
}
