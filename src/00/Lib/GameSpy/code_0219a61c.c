#include "00/Lib/GameSpy/code_0219a61c.h"
#include "code_02139f70.h"
#include "00/code_0219a000.h"

void gti2MessageCheck(const char **messagePointer, s32 *lengthPointer) {
    if (*messagePointer == NULL) {
        *messagePointer = data_ov000_021b3fc8;
        *lengthPointer = 0;
    } else if (*lengthPointer == -1) {
        *lengthPointer = strlen(*messagePointer) + 1;
    }
}
