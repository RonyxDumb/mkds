#include "00/Lib/GameSpy/error_set.h"
#include "00/Lib/GameSpy/buddy_messages.h"
#include "00/Lib/GameSpy/reply_parse.h"

void gpiSetError(GPConnection *connection, u32 errorNumber, const char *errorMessage) {
    GPIConnection *gpState;
    gpState = connection->mGpiConnection;
    CopyStringWithTerminator(gpState->mErrorMessage, errorMessage, 0x100);
    gpState->mErrorNumber = errorNumber;
}
