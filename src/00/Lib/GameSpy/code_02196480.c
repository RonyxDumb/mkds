#include "00/Lib/GameSpy/code_02196480.h"

#include "00/Lib/GameSpy/code_02193634.h"
#include "00/Lib/GameSpy/code_021906e4.h"
#include "00/Lib/GameSpy/code_021947e4.h"
#include "00/Lib/GameSpy/code_02196594.h"
#include "00/Lib/DWC/dwc_memfunc.h"
#include "00/Lib/GameSpy/code_02196590.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"
#include "code_02139f70.h"
#include "code_0213a460.h"
#include "00/Lib/GameSpy/code_021948f8.h"
#include "00/Lib/GameSpy/code_0218e0fc.h"
#include "00/code_02191200.h"
#include "00/Lib/GameSpy/code_02190ff8.h"
#include "00/code_02192d64.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/Lib/GameSpy/code_0218d818.h"
#include "00/code_02196000.h"
#include "00/code_02190000.h"
#include "00/Lib/GameSpy/code_0218f960.h"
#include "00/Lib/GameSpy/code_02194bb8.h"
#include "00/Lib/GameSpy/code_02193b88.h"
#include "00/Lib/GameSpy/code_021965a0.h"
#include "code_021384cc.h"
#include "00/Lib/GameSpy/code_0218e2dc.h"
#include "00/unk_021b4000.h"
#include "00/Lib/GameSpy/code_02190cd4.h"

s32 gpiProcessRegisterUniqueNick(GpConnection *connection, GpiOperation *operation, const char *input) {
    GpiCallback callback;
    u32 *arg;
    s32 result;

    if (GpiReadError(connection, input, 1) != FALSE) {
        return 4;
    }
    if (strncmp(input, "\\rn\\", 4) != 0) {
        GpiSetError(connection, 1, "Unexpected data was received from the server.");
        GpiQueueErrorCallback(connection, 3, 1);
        return 3;
    }
    callback = operation->mCallback;
    if (callback.mCallback != NULL) {
        arg = DWCi_GsMalloc(4);
        if (arg == NULL) {
            GpiSetErrorMessage(connection, "Out of memory.");
            return 1;
        }
        arg[0] = 0;
        result = GpiQueueCallback(connection, callback, arg, operation, 0);
        if (result != 0) {
            return result;
        }
    }
    GpiRemoveOperation(connection, operation);
    return 0;
}

s32 gpiSendTransferReply(GpConnection *connection, GpiTransferId *transferID, GpiPeer *peer, s32 result,
                         const char *msg) {
    char buffer[0x24];
    s32 stepResult;

    if (msg == NULL) {
        msg = "";
    }
    stepResult = GpiPeerSendXfer(connection, peer, 0xc9, transferID);
    if (stepResult != 0) {
        return stepResult;
    }
    sprintf(buffer, "\\version\\%d\\result\\%d", 1, result);
    stepResult = GpiPeerSendString(connection, peer, buffer);
    if (stepResult != 0) {
        return stepResult;
    }
    stepResult = GpiPeerSendLenMsg(connection, peer, msg, -1);
    if (stepResult != 0) {
        return stepResult;
    }
    return 0;
}
