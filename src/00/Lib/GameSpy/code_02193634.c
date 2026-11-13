#include "00/Lib/GameSpy/code_02193634.h"

#include "00/Lib/GameSpy/code_021947e4.h"
#include "00/Lib/GameSpy/code_02196594.h"
#include "00/Lib/GameSpy/code_021965a0.h"
#include "00/Lib/DWC/dwc_memfunc.h"
#include "00/Lib/GameSpy/code_02196590.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"
#include "code_02139f70.h"
#include "code_0213a460.h"
#include "00/code_021919ac.h"
#include "00/Lib/GameSpy/code_021906e4.h"
#include "00/Lib/GameSpy/code_021948f8.h"
#include "00/Lib/GameSpy/code_0218e0fc.h"
#include "00/code_02191200.h"
#include "00/Lib/GameSpy/code_02196480.h"
#include "00/Lib/GameSpy/code_02190ff8.h"
#include "00/code_02192d64.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/Lib/GameSpy/code_0218d818.h"
#include "00/code_02196000.h"
#include "00/code_02190000.h"
#include "00/Lib/GameSpy/code_0218f960.h"
#include "00/Lib/GameSpy/code_02194bb8.h"
#include "00/code_02193000.h"
#include "00/Lib/GameSpy/code_02193b88.h"
#include "00/unk_021b3000.h"
#include "00/Lib/GameSpy/code_02190cd4.h"
#include "00/Lib/GameSpy/code_0218e2dc.h"
#include "00/code_02194000.h"
#include "00/unk_021b4000.h"

s32 GpiQueueOperationCallback(GpConnection *connection, GpiOperation *operation) {
    GpiConnection *gpState = connection->mGpiConnection;
    GpiCallback callback;
    ConnectReply *arg;
    NewProfileReply *newProfileArg;
    ProfileSearchReply *searchArg;
    RegisterNickReply *uniquenickArg;
    s32 result;

    if (connection == NULL) {
        AssertionFailed("connection != NULL", "gpiOperation.c", NULL, 0x22);
    }
    if (connection->mGpiConnection == NULL) {
        AssertionFailed("*connection != NULL", "gpiOperation.c", NULL, 0x23);
    }
    if (operation == NULL) {
        AssertionFailed("operation != NULL", "gpiOperation.c", NULL, 0x24);
    }
    callback = operation->mCallback;
    if (callback.mCallback != NULL) {
        switch (operation->mType) {
            case 0:
                arg = DWCi_GsMalloc(0x20);
                if (arg == NULL) {
                    GpiSetErrorMessage(connection, "Out of memory.");
                    return 1;
                }
                memset(arg, 0, 0x20);
                arg->mResult = operation->mResult;
                if (gpState->mErrorNumber == 0x201) {
                    arg->mProfile = gpState->mProfileId;
                    gpState->mProfileId = 0;
                }
                result = GpiQueueCallback(connection, callback, arg, operation, 0);
                if (result != 0) {
                    return result;
                }
                break;
            case 1:
                newProfileArg = DWCi_GsMalloc(8);
                if (newProfileArg == NULL) {
                    GpiSetErrorMessage(connection, "Out of memory.");
                    return 1;
                }
                memset(newProfileArg, 0, 8);
                newProfileArg->mResult = operation->mResult;
                result = GpiQueueCallback(connection, callback, newProfileArg, operation, 0);
                if (result != 0) {
                    return result;
                }
                break;
            case 2:
                arg = DWCi_GsMalloc(0x204);
                if (arg == NULL) {
                    GpiSetErrorMessage(connection, "Out of memory.");
                    return 1;
                }
                memset(arg, 0, 0x204);
                arg->mResult = operation->mResult;
                result = GpiQueueCallback(connection, callback, arg, operation, 0);
                if (result != 0) {
                    return result;
                }
                break;
            case 3:
                searchArg = DWCi_GsMalloc(0x10);
                if (searchArg == NULL) {
                    GpiSetErrorMessage(connection, "Out of memory.");
                    return 1;
                }
                memset(searchArg, 0, 0x10);
                searchArg->mResult = operation->mResult;
                searchArg->mMatches = 0;
                result = GpiQueueCallback(connection, callback, searchArg, operation, 0);
                if (result != 0) {
                    return result;
                }
                break;
            case 4:
                uniquenickArg = DWCi_GsMalloc(4);
                if (uniquenickArg == NULL) {
                    GpiSetErrorMessage(connection, "Out of memory.");
                    return 1;
                }
                memset(uniquenickArg, 0, 4);
                uniquenickArg->mResult = operation->mResult;
                result = GpiQueueCallback(connection, callback, uniquenickArg, operation, 0);
                if (result != 0) {
                    return result;
                }
                break;
            default:
                AssertionFailed("0", "gpiOperation.c", NULL, 0x6b);
                break;
        }
    }
    return 0;
}

u32 GpiCreateOperation(GpConnection *connection, int type, int data, int *operationOut, int blocking, int callback,
                       int param) {
    GpiConnection *gpState = connection->mGpiConnection;
    GpiOperation *pendingOp = DWCi_GsMalloc(0x24);

    if (pendingOp == NULL) {
        GpiSetErrorMessage(connection, "Out of memory.");
        return 1;
    }
    pendingOp->mType = type;
    pendingOp->mData = (void *) data;
    pendingOp->mBlocking = blocking;
    pendingOp->mState = 0;
    if (type == 0) {
        pendingOp->mId = 1;
    } else {
        pendingOp->mId = gpState->mNextOperationId++;
        if (gpState->mNextOperationId < 2) {
            gpState->mNextOperationId = 2;
        }
    }
    pendingOp->mResult = GP_REQUEST_OK;
    pendingOp->mCallback.mCallback = (void (*)(void *, void *, u32)) callback;
    pendingOp->mCallback.mParam = param;
    pendingOp->mNext = gpState->mOperationList;
    gpState->mOperationList = pendingOp;
    *operationOut = (s32) pendingOp;
    return 0;
}

void GpiDeleteOperation(GpConnection *connection, GpiOperation *operation) {
    GpiConnection *gpState = connection->mGpiConnection;
    GPISearchData *searchData;

    if (operation->mType == 3) {
        searchData = operation->mData;
        gpState->mSearchCount--;
        if (gpState->mSearchCount < 0) {
            AssertionFailed("iconnection->numSearches >= 0", "gpiOperation.c", NULL, 0xb6);
        }
        shutdown(searchData->mSocket, 2);
        closesocket(searchData->mSocket);
        DWCi_GsFree(searchData->mOutputBuffer);
        searchData->mOutputBuffer = NULL;
        DWCi_GsFree(searchData->mInputBuffer);
        searchData->mInputBuffer = NULL;
    }
    DWCi_GsFree(operation->mData);
    operation->mData = NULL;
    DWCi_GsFree(operation);
}

void GpiRemoveOperation(GpConnection *connection, GpiOperation *operation) {
    GpiConnection *gpState = connection->mGpiConnection;
    GpiOperation *current = gpState->mOperationList;
    GpiOperation *previous = NULL;

    while (current != NULL) {
        if (current == operation) {
            if (previous == NULL) {
                gpState->mOperationList = current->mNext;
            } else {
                previous->mNext = operation->mNext;
            }
            GpiDeleteOperation(connection, operation);
            return;
        }
        previous = current;
        current = current->mNext;
    }
}

BOOL GpiFindOperation(GpConnection *object, GpiOperation **output, u32 key) {
    GpiOperation *node = object->mGpiConnection->mOperationList;
    while (node != NULL) {
        if (node->mId == key) {
            if (output != NULL) {
                *output = node;
            }
            return TRUE;
        }
        node = node->mNext;
    }
    if (output != NULL) {
        *output = NULL;
    }
    return FALSE;
}

BOOL gpiOperationsAreBlocking(GpConnection *object) {
    GpiOperation *node = object->mGpiConnection->mOperationList;
    while (node != NULL) {
        if (node->mBlocking != 0 && node->mType != 3) {
            return TRUE;
        }
        node = node->mNext;
    }
    return FALSE;
}

s32 GpiProcessOperation(GpConnection *connection, GpiOperation *operation, const char *input) {
    s32 result = 0;
    u32 type = operation->mType;

    switch (type) {
        case 0:
            result = GpiProcessConnectOperation(connection, operation, input);
            break;
        case 1:
            result = gpiProcessNewProfile(connection, operation, input);
            break;
        case 2:
            result = GpiProcessInfoOperation(connection, operation, input);
            break;
        case 4:
            result = gpiProcessRegisterUniqueNick(connection, operation, input);
            break;
        default:
            gpiDebug(connection, "gpiProcessOperation was passed an operation with an invalid type (%d)\n", type);
            AssertionFailed("0", "gpiOperation.c", NULL, 0x146);
            break;
    }
    if (result != 0) {
        operation->mResult = result;
    }
    return result;
}

u32 GpiIsValidDate(int day, int month, int year) {
    if (day == 0 && month == 0 && year == 0) {
        return 1;
    }
    if (day < 0 || month < 0 || year < 0) {
        return 0;
    }
    switch (month) {
        case 0:
            if (day != 0) {
                return 0;
            }
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (day > 0x1f) {
                return 0;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (day > 0x1e) {
                return 0;
            }
            break;
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                if (day > 0x1d) {
                    return 0;
                }
            } else if (day > 0x1c) {
                return 0;
            }
            break;
        default:
            return 0;
    }
    if (year < 0x76c) {
        return 0;
    }
    if (year > 0x81f) {
        return 0;
    }
    if (year == 0x81f) {
        if (month > 6) {
            return 0;
        }
        if (month == 6 && day > 6) {
            return 0;
        }
    }
    return 1;
}
