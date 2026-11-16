#include "Main/Scene/scene_run_forever.h"
#include "Main/System/init_after_startup.h"
#include "Main/Race/race_setup_input.h"
#include "Main/Scene/run_scenes.h"

WvrState gWvrState;

u32 InitAndRunScenesForever(void) {
    InitAfterStartup();
    RunScenesForever();
    ReleaseTouchMicInputWrapper();
    return 0;
}
