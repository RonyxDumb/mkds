#include "Main/Unknown/code_0210f090.h"

#include "code_0201ec30.h"

u32 UpdateMicBufferInput(MicBuffer *micBuffer) {
    if (micBuffer->mSkipCount == 0) {
        return func_0201ec30();
    }
    if (micBuffer->mSkipCount < 0x1e) {
        micBuffer->mSkipCount = micBuffer->mSkipCount + 1;
    } else {
        micBuffer->mSkipCount = 0;
    }
    return 0;
}
