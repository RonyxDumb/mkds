#include "00/Lib/GameSpy/error_message_set.h"
#include "00/Lib/GameSpy/reply_parse.h"

void GpiSetErrorMessage(void *connection, void *message) {
    u32 destination = (u32) connection;
    void *source = message;
    u32 capacity;
    u32 unusedValue;
    destination = *(const u32 *) ((destination) + 0u);
    capacity = 0x100u;
    GpiCopyString((char *) destination, source, capacity);
}
