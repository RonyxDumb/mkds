#include "00/Lib/GameSpy/error_set.h"
#include "00/Lib/GameSpy/buddy_messages.h"
#include "00/Lib/GameSpy/reply_parse.h"

void GpiSetError(GpConnection *connection, u32 errorNumber, const char *errorMessage) {
    GpiConnection *gpState;
    gpState = connection->mGpiConnection;
    GpiCopyString(gpState->mErrorMessage, errorMessage, 0x100);
    gpState->mErrorNumber = errorNumber;
}
