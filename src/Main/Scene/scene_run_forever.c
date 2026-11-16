#include "Main/Scene/scene_run_forever.h"
#include "Main/System/init_after_startup.h"
#include "Main/Race/race_setup_input.h"
#include "Main/Scene/run_scenes.h"

WvrState g_SomeVramConfigMode;

u32 StartExecuteFunction(void) {
    InitializeGeneralObjects();
    RunMain();
    j_ResetGlobal59C4();
    return 0;
}
