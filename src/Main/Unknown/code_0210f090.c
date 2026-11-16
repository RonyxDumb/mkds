#include "Main/Unknown/code_0210f090.h"

#include "code_0201ec30.h"

u32 mic_update(MicBuffer *micBuffer) {
    if (micBuffer->field41C == 0) {
        return sub_201EC30();
    }
    if (micBuffer->field41C < 0x1e) {
        micBuffer->field41C = micBuffer->field41C + 1;
    } else {
        micBuffer->field41C = 0;
    }
    return 0;
}
