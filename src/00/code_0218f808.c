#include "00/code_0218f808.h"
#include "00/code_0218dd8c.h"
#include "00/code_02190ff8.h"

void gpiDestroy(GpConnection *connection) {
    GpiConnection *gpState;
    gpState = connection->mGpiConnection;
    GpiCloseConnection(connection, 1);
    DWCi_GsFree(gpState->mDebugBuffer);
    gpState->mDebugBuffer = NULL;
    HashtableDelete(gpState->mProfileList.mTable);
    DWCi_GsFree(gpState);
    connection->mGpiConnection = NULL;
}
