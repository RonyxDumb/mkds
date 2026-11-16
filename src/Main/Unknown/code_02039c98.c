#include "Main/Unknown/code_02039c98.h"
#include "Main/Unknown/code_02039cbc.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/Unknown/code_0205dc84.h"

u32 mproc_main(void) {
    InitializeGeneralObjects();
    scproc_run();
    input_finalize();
    return 0;
}
