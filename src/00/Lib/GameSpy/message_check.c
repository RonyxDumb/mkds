#include "00/Lib/GameSpy/message_check.h"
#include "narrow_string_functions.h"

void gti2MessageCheck(const char **messagePointer, s32 *lengthPointer) {
    if (*messagePointer == NULL) {
        *messagePointer = "";
        *lengthPointer = 0;
    } else if (*lengthPointer == -1) {
        *lengthPointer = strlen(*messagePointer) + 1;
    }
}
