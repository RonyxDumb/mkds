#include "00/Lib/GameSpy/code_02196590.h"
#include "00/Lib/GameSpy/code_02196594.h"

void GpiSetErrorMessage(void *errorTarget, void *message) {
    u32 destination = (u32) errorTarget;
    void *source = message;
    u32 capacity;
    u32 unusedValue;
    destination = *(const u32 *) ((destination) + 0u);
    capacity = 0x100u;
    GpiCopyString((char *) destination, source, capacity);
}
