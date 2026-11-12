#include "00/code_0219a044.h"
#include "00/code_0218d818.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_02134398.h"
#include "00/code_02197e58.h"
#include "00/gt2Connection.h"
#include "00/gt2Main.h"
#include "00/code_02198a8c.h"
#include "00/code_0219a0d0.h"
#include "00/code_0219a3f4.h"

void gti2FreeClosedConnections(Gt2Socket *socket) {
    s32 index;
    for (index = DarrayGetCount(socket->mConnectionsToFree) - 1; index >= 0; index--) {
        gti2FreeSocketConnection(*(Gt2Connection **) DarrayGetElement(socket->mConnectionsToFree, index));
    }
}

void gti2SocketError(Gt2Socket *socket) {
    if (socket->mError == FALSE) {
        socket->mError = TRUE;
        gt2CloseAllConnectionsHard(socket);
        if (gti2SocketErrorCallback(socket) != FALSE) {
            DeleteSocket(socket);
        }
    }
}
