#include "00/Lib/GameSpy/callback_queue.h"
#include "00/Lib/DWC/matching_result_codes.h"
#include "00/Lib/GameSpy/profile_empty_check.h"
#include "00/Lib/GameSpy/socket_calls.h"
#include "00/Lib/GameSpy/error_message_set.h"
#include "00/Lib/GameSpy/reply_parse.h"
#include "00/Lib/DWC/memory_allocator.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "string.h"
#include "print_memory_multibyte_write.h"

#include "00/Lib/GameSpy/send_buffer.h"
#include "narrow_string_functions.h"
#include "text_to_number.h"
#include "00/Lib/GameSpy/profile_list.h"
#include "00/Lib/GameSpy/md5_base64_encode.h"
#include "00/Lib/GameSpy/connect_operation.h"
#include "00/Lib/GameSpy/unique_nick_transfer.h"
#include "00/Lib/GameSpy/login_connect_close.h"
#include "00/Lib/GameSpy/profile_info.h"
#include "00/Lib/GameSpy/dynamic_array.h"
#include "00/Lib/GameSpy/buddy_messages.h"
#include "00/Lib/GameSpy/profile_search.h"
#include "00/Lib/GameSpy/peer_connection.h"
#include "00/Lib/GameSpy/profile_walk.h"

void gpiCallErrorCallback(GPConnection *connection, s32 result, s32 fatal) {
    GPIConnection *gpState;
    GPICallback errorCallback;
    ErrorData *errorArg;

    gpState = connection->mGpiConnection;
    if (gpState == NULL) {
        AssertionFailed("iconnection != NULL", "gpiCallback.c", NULL, 0x23);
    }
    if (result == 0) {
        AssertionFailed("result != GP_NO_ERROR", "gpiCallback.c", NULL, 0x24);
    }
    if (fatal != 1 && fatal != 0) {
        AssertionFailed("(fatal == GP_FATAL) || (fatal == GP_NON_FATAL)", "gpiCallback.c", NULL, 0x25);
    }
    if (fatal == 1) {
        gpState->mFatal = TRUE;
    }
    errorCallback = gpState->mCallbacks[0];
    if (errorCallback.mCallback != NULL) {
        errorArg = DWCi_GsMalloc(0x10);
        if (errorArg != NULL) {
            errorArg->mResult = result;
            errorArg->mFatal = fatal;
            errorArg->mErrorCode = gpState->mErrorNumber;
            errorArg->mErrorString = gpState;
        }
        gpiAddCallback(connection, errorCallback, errorArg, NULL, PROFILE_CALLBACK_TYPE_ERROR);
    }
}

u32 gpiAddCallback(GPConnection *connection, GPICallback callback, void *arg, GPIOperation *operation, s32 type) {
    GPIConnection *gpState;
    QueuedCallback *queued;

    gpState = connection->mGpiConnection;
    queued = DWCi_GsMalloc(0x18);
    if (queued == NULL) {
        gpiSetErrorString(connection, "Out of memory.");
        return GP_MEMORY_ERROR;
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

void gpiCallCallback(GPConnection *connection, QueuedCallback *data) {
    CallbackArgData *callbackArg;
    CallbackArgData *nickListArg;
    s32 entryIndex;

    if (data->mCallback.mCallback == NULL) {
        AssertionFailed("data->callback.callback != NULL", "gpiCallback.c", NULL, 0x6e);
    }
    if (data->mArg == NULL) {
        AssertionFailed("data->arg != NULL", "gpiCallback.c", NULL, 0x6f);
    }
    data->mCallback.mCallback(connection, data->mArg, data->mCallback.mParam);
    if (data->mType == PROFILE_CALLBACK_TYPE_FREE_MESSAGE_TEXT) {
        callbackArg = data->mArg;
        DWCi_GsFree(callbackArg->mUnk_08);
        callbackArg = data->mArg;
        callbackArg->mUnk_08 = NULL;
    } else if (data->mType == PROFILE_CALLBACK_TYPE_FREE_NICK_LISTS) {
        nickListArg = data->mArg;
        for (entryIndex = 0; entryIndex < nickListArg->mNickCount; entryIndex++) {
            DWCi_GsFree(nickListArg->mNicknames[entryIndex]);
            nickListArg->mNicknames[entryIndex] = NULL;
            DWCi_GsFree(nickListArg->mUniquenicks[entryIndex]);
            nickListArg->mUniquenicks[entryIndex] = NULL;
        }
        DWCi_GsFree(nickListArg->mNicknames);
        nickListArg->mNicknames = NULL;
        DWCi_GsFree(nickListArg->mUniquenicks);
        nickListArg->mUniquenicks = NULL;
    } else if (data->mType == PROFILE_CALLBACK_TYPE_FREE_MATCH_LIST) {
        callbackArg = data->mArg;
        DWCi_GsFree(callbackArg->mMatchList);
        callbackArg->mMatchList = NULL;
    } else if (data->mType == PROFILE_CALLBACK_TYPE_FREE_TRANSFER_MESSAGE) {
        callbackArg = data->mArg;
        if (callbackArg->mTransferMessage != NULL) {
            DWCi_GsFree(callbackArg->mTransferMessage);
            callbackArg->mTransferMessage = NULL;
        }
    } else if (data->mType == PROFILE_CALLBACK_TYPE_FREE_OTHERS_PROFILES_IF_SET) {
        callbackArg = data->mArg;
        if (callbackArg->mUnk_08 != NULL) {
            DWCi_GsFree(callbackArg->mUnk_08);
            callbackArg->mUnk_08 = NULL;
        }
    } else if (data->mType == PROFILE_CALLBACK_TYPE_FREE_SUGGESTED_NICKS) {
        CallbackArgData *suggestedNicksArg = data->mArg;
        for (entryIndex = 0; entryIndex < suggestedNicksArg->mSuggestedNickCount; entryIndex++) {
            DWCi_GsFree(suggestedNicksArg->mUnk_08[entryIndex]);
            suggestedNicksArg->mUnk_08[entryIndex] = NULL;
        }
        DWCi_GsFree(suggestedNicksArg->mUnk_08);
        suggestedNicksArg->mUnk_08 = NULL;
    }
    DWCi_GsFree(data->mArg);
    data->mArg = NULL;
    DWCi_GsFree(data);
}

u32 gpiProcessCallbacks(GPConnection *connection, s32 operationId) {
    GPIConnection *gpState;
    QueuedCallback *listNode;
    QueuedCallback *queueTail;
    QueuedCallback *previousKept;
    QueuedCallback *current;

    gpState = connection->mGpiConnection;
    if (operationId != 0) {
        listNode = gpState->mCallbackQueueHead;
        queueTail = gpState->mCallbackQueueTail;
        previousKept = NULL;
        gpState->mCallbackQueueHead = NULL;
        gpState->mCallbackQueueTail = NULL;
        current = listNode;
        if (current != NULL) {
            do {
                QueuedCallback *next = current->mNext;
                if (current->mOperationId == operationId || current->mType == PROFILE_CALLBACK_TYPE_ERROR) {
                    if (previousKept != NULL) {
                        previousKept->mNext = next;
                    } else {
                        listNode = next;
                    }
                    if (queueTail == current) {
                        queueTail = previousKept;
                    }
                    gpiCallCallback(connection, current);
                } else {
                    previousKept = current;
                }
                current = next;
            } while (current != NULL);
        }
        if (gpState->mCallbackQueueHead != NULL) {
            gpState->mCallbackQueueTail->mNext = listNode;
            gpState->mCallbackQueueTail = queueTail;
        } else {
            gpState->mCallbackQueueHead = listNode;
            gpState->mCallbackQueueTail = queueTail;
        }
        return 0;
    }
    current = gpState->mCallbackQueueHead;
    while (current != NULL) {
        gpState->mCallbackQueueHead = NULL;
        gpState->mCallbackQueueTail = NULL;
        while (current != NULL) {
            listNode = current->mNext;
            gpiCallCallback(connection, current);
            current = listNode;
        }
        current = gpState->mCallbackQueueHead;
    }
    return 0;
}
