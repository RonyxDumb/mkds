#include "Main/Unknown/code_02003000.h"
#include "Main/Unknown/code_020365ac.h"
#include "Main/Unknown/code_02039c98.h"

void main(void) {
    InitStartup();
    RunRootHeapCall((u32) InitAndRunScenesForever);
}
