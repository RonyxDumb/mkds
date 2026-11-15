#include "00/Lib/GameSpy/code_021965a0.h"
#include "00/Lib/GameSpy/code_0218f960.h"
#include "00/Lib/GameSpy/code_02196594.h"

void GpiSetError(GpConnection *connection, u32 errorNumber, const char *errorMessage) {
    GpiConnection *gpState;
    gpState = connection->mGpiConnection;
    GpiCopyString(gpState->mErrorMessage, errorMessage, 0x100);
    gpState->mErrorNumber = errorNumber;
}
