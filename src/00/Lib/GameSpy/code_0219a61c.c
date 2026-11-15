#include "00/Lib/GameSpy/code_0219a61c.h"
#include "code_02139f70.h"

void gti2MessageCheck(const char **messagePointer, s32 *lengthPointer) {
    if (*messagePointer == NULL) {
        *messagePointer = "";
        *lengthPointer = 0;
    } else if (*lengthPointer == -1) {
        *lengthPointer = strlen(*messagePointer) + 1;
    }
}
