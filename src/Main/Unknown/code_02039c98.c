#include "Main/Unknown/code_02039c98.h"
#include "Main/Unknown/code_02039cbc.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/Unknown/code_0205dc84.h"

u32 InitAndRunScenesForever(void) {
    InitAfterStartup();
    RunScenesForever();
    ReleaseTouchMicInputWrapper();
    return 0;
}
