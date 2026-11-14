#include "00/code_0219a3f4.h"
#include "00/GameSpy/darray.h"
#include "00/GameSpy/hashtable.h"
#include "00/GameSpy/gt2Callback.h"
#include "00/GameSpy/nonport.h"
#include "00/code_021a3668.h"

void DeleteSocket(Gt2Socket *a) {
    if (a->mRunningCallbackCount != 0) {
        a->mDeletePending = TRUE;
        return;
    }
    func_ov000_0218e53c(a->mDescriptor);
    HashtableDelete(a->mConnections);
    DarrayDelete(a->mConnectionsToFree);
    func_ov000_021a3668(a);
    func_ov000_0218e8b4();
}

void SetIncomingConnectionCallback(Gt2Socket *a, void *b) {
    a->mIncomingConnectionCallback = b;
}
