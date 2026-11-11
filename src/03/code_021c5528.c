#include "03/code_021c5528.h"

BOOL ValueRecordsPAD_DetectFold(void) {
    if ((*(vu16 *) 0x027fffa8 & 0x8000) >> 15) {
        return 1;
    }
    return 0;
}
