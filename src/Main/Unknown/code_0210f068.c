#include "Main/Unknown/code_0210f068.h"
#include "Main/Unknown/code_0210f090.h"
#include "code_0201ec30.h"

void mic_handlePreSleep(MicBuffer *micBuffer) {
    u32 unused;
    micBuffer->mUnk_41c = 1;
    func_020203e4();
}

void mic_handlePostSleep(MicBuffer *micBuffer) {
    u32 unused;
    micBuffer->mUnk_41c = 2;
    func_0202041c();
}
