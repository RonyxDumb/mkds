#include "00/code_0219a09c.h"
#include "00/code_0218dd8c.h"
#include "00/code_0218e2dc.h"
#include "00/code_0219a0d0.h"

u32 gti2SocketConnectionsThink(Gt2Socket *socket) {
    void *stoppedElement;
    u32 currentTime[2];
    currentTime[0] = GetElapsedMilliseconds();
    stoppedElement = HashtableFindByFn(socket->mConnections, (s32) &gti2SocketConnectionsThinkMap, currentTime);
    if (stoppedElement == NULL) {
        return 1;
    }
    return 0;
}
