#include "Main/Unknown/code_0205a50c.h"
#include "Main/Unknown/unk_0217a000.h"

s32 sub_205A50C(s32 bitIndex) {
    BOOL isSet;

    isSet = TRUE;
    if (!(gStruct217AA14->field749 & (1 << bitIndex))) {
        isSet = FALSE;
    }
    return isSet;
}
