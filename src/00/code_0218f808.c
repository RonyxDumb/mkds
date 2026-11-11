#include "00/code_0218f808.h"
#include "00/code_0218dd8c.h"
#include "00/code_02190ff8.h"

void gpiDestroy(GpConnection *connection) {
    GpiConnection *gpState;
    gpState = connection->mGpiConnection;
    GpiCloseConnection(connection, 1);
    func_ov000_021a3668(gpState->mUnk_460);
    gpState->mUnk_460 = NULL;
    HashtableDelete(gpState->mProfileList.mTable);
    func_ov000_021a3668(gpState);
    connection->mGpiConnection = NULL;
}
