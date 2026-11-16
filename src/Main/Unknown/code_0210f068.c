#include "Main/Unknown/code_0210f068.h"
#include "Main/Unknown/code_0210f090.h"
#include "code_0201ec30.h"

void mic_handlePreSleep(MicBuffer *micBuffer) {
    u32 unused;
    micBuffer->field41C = 1;
    sub_20203E4();
}

void mic_handlePostSleep(MicBuffer *micBuffer) {
    u32 unused;
    micBuffer->field41C = 2;
    sub_202041C();
}
