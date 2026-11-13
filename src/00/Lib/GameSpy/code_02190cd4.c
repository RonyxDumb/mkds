#include "00/Lib/GameSpy/code_02190cd4.h"
#include "00/Lib/GameSpy/code_021947e4.h"
#include "00/code_02194000.h"
#include "00/code_02196000.h"
#include "00/Lib/GameSpy/code_0218e2dc.h"
#include "00/Lib/GameSpy/code_02196590.h"
#include "00/Lib/GameSpy/code_02196594.h"
#include "00/Lib/DWC/dwc_memfunc.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"

#include "00/Lib/GameSpy/code_021906e4.h"
#include "code_02139f70.h"
#include "code_0213a460.h"
#include "00/Lib/GameSpy/code_021948f8.h"
#include "00/Lib/GameSpy/code_0218e0fc.h"
#include "00/code_02191200.h"
#include "00/Lib/GameSpy/code_02196480.h"
#include "00/Lib/GameSpy/code_02190ff8.h"
#include "00/code_02192d64.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/Lib/GameSpy/code_0218d818.h"
#include "00/code_02190000.h"
#include "00/Lib/GameSpy/code_0218f960.h"
#include "00/Lib/GameSpy/code_02194bb8.h"
#include "00/Lib/GameSpy/code_02193b88.h"
#include "00/Lib/GameSpy/gpiProfile.h"

void GpiQueueErrorCallback(GpConnection *connection, s32 result, s32 fatal) {
    GpiConnection *iconnection;
    GpiCallback errorCallback;
    ErrorData *errorArg;

    iconnection = connection->mGpiConnection;
    if (iconnection == NULL) {
        AssertionFailed("iconnection != NULL", "gpiCallback.c", NULL, 0x23);
    }
    if (result == 0) {
        AssertionFailed("result != GP_NO_ERROR", "gpiCallback.c", NULL, 0x24);
    }
    if (fatal != 1 && fatal != 0) {
        AssertionFailed("(fatal == GP_FATAL) || (fatal == GP_NON_FATAL)", "gpiCallback.c", NULL, 0x25);
    }
    if (fatal == 1) {
        iconnection->mFatal = TRUE;
    }
    errorCallback = iconnection->mCallbacks[0];
    if (errorCallback.mCallback != NULL) {
        errorArg = DWCi_GsMalloc(0x10);
        if (errorArg != NULL) {
            errorArg->mResult = result;
            errorArg->mFatal = fatal;
            errorArg->mErrorCode = iconnection->mErrorNumber;
            errorArg->mErrorString = iconnection;
        }
        GpiQueueCallback(connection, errorCallback, errorArg, NULL, 1);
    }
}

u32 GpiQueueCallback(GpConnection *connection, GpiCallback callback, void *arg, GpiOperation *operation, s32 type) {
    GpiConnection *gpState;
    GpiQueuedCallback *queued;

    gpState = connection->mGpiConnection;
    queued = DWCi_GsMalloc(0x18);
    if (queued == NULL) {
        GpiSetErrorMessage(connection, "Out of memory.");
        return 1;
    }
    queued->mCallback = callback;
    queued->mArg = arg;
    if (operation != NULL) {
        queued->mOperationId = operation->mId;
    } else {
        queued->mOperationId = 0;
    }
    queued->mType = type;
    queued->mNext = NULL;
    if (gpState->mCallbackQueueHead == NULL) {
        gpState->mCallbackQueueHead = queued;
    }
    if (gpState->mCallbackQueueTail != NULL) {
        gpState->mCallbackQueueTail->mNext = queued;
    }
    gpState->mCallbackQueueTail = queued;
    return 0;
}

void GpiCallAndFreeCallback(GpConnection *connection, GpiQueuedCallback *data) {
    CallbackArgData *callbackArg;
    CallbackArgData *listArg;
    s32 entryIndex;

    if (data->mCallback.mCallback == NULL) {
        AssertionFailed("data->callback.callback != NULL", "gpiCallback.c", NULL, 0x6e);
    }
    if (data->mArg == NULL) {
        AssertionFailed("data->arg != NULL", "gpiCallback.c", NULL, 0x6f);
    }
    data->mCallback.mCallback(connection, data->mArg, data->mCallback.mParam);
    if (data->mType == 2) {
        callbackArg = data->mArg;
        DWCi_GsFree(callbackArg->mUnk_08);
        callbackArg = data->mArg;
        callbackArg->mUnk_08 = NULL;
    } else if (data->mType == 3) {
        listArg = data->mArg;
        for (entryIndex = 0; entryIndex < listArg->mUnk_38; entryIndex++) {
            DWCi_GsFree(listArg->mUnk_3c[entryIndex]);
            listArg->mUnk_3c[entryIndex] = NULL;
            DWCi_GsFree(listArg->mUnk_40[entryIndex]);
            listArg->mUnk_40[entryIndex] = NULL;
        }
        DWCi_GsFree(listArg->mUnk_3c);
        listArg->mUnk_3c = NULL;
        DWCi_GsFree(listArg->mUnk_40);
        listArg->mUnk_40 = NULL;
    } else if (data->mType == 4) {
        callbackArg = data->mArg;
        DWCi_GsFree(callbackArg->mUnk_0c);
        callbackArg->mUnk_0c = NULL;
    } else if (data->mType == 7) {
        callbackArg = data->mArg;
        if (callbackArg->mUnk_10 != NULL) {
            DWCi_GsFree(callbackArg->mUnk_10);
            callbackArg->mUnk_10 = NULL;
        }
    } else if (data->mType == 8) {
        callbackArg = data->mArg;
        if (callbackArg->mUnk_08 != NULL) {
            DWCi_GsFree(callbackArg->mUnk_08);
            callbackArg->mUnk_08 = NULL;
        }
    } else if (data->mType == 9) {
        CallbackArgData *arrayArg = data->mArg;
        for (entryIndex = 0; entryIndex < arrayArg->mUnk_04; entryIndex++) {
            DWCi_GsFree(arrayArg->mUnk_08[entryIndex]);
            arrayArg->mUnk_08[entryIndex] = NULL;
        }
        DWCi_GsFree(arrayArg->mUnk_08);
        arrayArg->mUnk_08 = NULL;
    }
    DWCi_GsFree(data->mArg);
    data->mArg = NULL;
    DWCi_GsFree(data);
}

u32 GpiCallQueuedCallbacks(GpConnection *connection, s32 operationId) {
    GpiConnection *gpState;
    GpiQueuedCallback *queueHead;
    GpiQueuedCallback *queueTail;
    GpiQueuedCallback *previousKept;
    GpiQueuedCallback *current;

    gpState = connection->mGpiConnection;
    if (operationId != 0) {
        queueHead = gpState->mCallbackQueueHead;
        queueTail = gpState->mCallbackQueueTail;
        previousKept = NULL;
        gpState->mCallbackQueueHead = NULL;
        gpState->mCallbackQueueTail = NULL;
        current = queueHead;
        if (current != NULL) {
            do {
                GpiQueuedCallback *next = current->mNext;
                if (current->mOperationId == operationId || current->mType == 1) {
                    if (previousKept != NULL) {
                        previousKept->mNext = next;
                    } else {
                        queueHead = next;
                    }
                    if (queueTail == current) {
                        queueTail = previousKept;
                    }
                    GpiCallAndFreeCallback(connection, current);
                } else {
                    previousKept = current;
                }
                current = next;
            } while (current != NULL);
        }
        if (gpState->mCallbackQueueHead != NULL) {
            gpState->mCallbackQueueTail->mNext = queueHead;
            gpState->mCallbackQueueTail = queueTail;
        } else {
            gpState->mCallbackQueueHead = queueHead;
            gpState->mCallbackQueueTail = queueTail;
        }
        return 0;
    }
    current = gpState->mCallbackQueueHead;
    while (current != NULL) {
        gpState->mCallbackQueueHead = NULL;
        gpState->mCallbackQueueTail = NULL;
        while (current != NULL) {
            queueHead = current->mNext;
            GpiCallAndFreeCallback(connection, current);
            current = queueHead;
        }
        current = gpState->mCallbackQueueHead;
    }
    return 0;
}
