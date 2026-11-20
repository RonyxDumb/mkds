#include "00/Lib/GameSpy/presence_api.h"
#include "00/Lib/DWC/matching_result_codes.h"
#include "03/Net/essid_packet_steps.h"
#include "00/Lib/GameSpy/socket_calls.h"
#include "00/Lib/GameSpy/buddy_messages.h"
#include "00/Lib/GameSpy/presence_connection.h"
#include "00/Lib/GameSpy/error_message_set.h"
#include "00/Lib/DWC/memory_allocator.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "string.h"
#include "print_memory_multibyte_write.h"
#include "00/Lib/GameSpy/dynamic_array.h"
#include "00/Lib/GameSpy/error_set.h"
#include "00/Lib/GameSpy/callback_queue.h"
#include "00/Lib/GameSpy/login_connect_close.h"
#include "narrow_string_functions.h"
#include "00/Lib/GameSpy/send_buffer.h"
#include "00/Lib/GameSpy/reply_parse.h"
#include "00/Lib/GameSpy/connect_operation.h"
#include "00/Lib/GameSpy/profile_info.h"
#include "00/Lib/GameSpy/login_connect.h"
#include "00/Lib/GameSpy/profile_empty_check.h"
#include "text_to_number.h"
#include "00/Lib/GameSpy/operation_queue.h"
#include "00/Lib/GameSpy/profile_list.h"
#include "00/Lib/GameSpy/md5_base64_encode.h"
#include "00/Lib/GameSpy/unique_nick_transfer.h"
#include "00/Lib/GameSpy/peer_connection.h"
#include "00/Lib/GameSpy/profile_walk.h"
#include "00/Lib/GameSpy/profile_search.h"
#include "00/Lib/wifi_library_globals.h"
#include "scan_text_random.h"
#include "00/Lib/GameSpy/availability_check.h"
#include "tick_counter.h"
#include "00/Lib/GameSpy/profile_find_by_buddy.h"
#include "00/Lib/GameSpy/profile_info_set.h"

u32 gpiReset(GPConnection *connection) {
    GPIConnection *gpState;
    GPIOperation **operationLink;
    gpState = connection->mGpiConnection;
    gpState->mNick[0] = 0;
    gpState->mUniquenick[0] = 0;
    gpState->mEmail[0] = 0;
    gpState->mConnectSocket = -1;
    gpState->mConnectState = PROFILE_CONNECTION_IDLE;
    gpState->mInputBufferLength = 0;
    gpState->mInputBufferPos = 0;
    gpState->mInputBufferCapacity = 0;
    DWCi_GsFree(gpState->mInputBuffer);
    gpState->mInputBuffer = NULL;
    gpState->mInputBuffer = NULL;
    gpState->mCommandBufferCapacity = 0;
    DWCi_GsFree(gpState->mCommandBuffer);
    gpState->mCommandBuffer = NULL;
    gpState->mCommandBuffer = NULL;
    gpState->mOutputBuffer.mLength = 0;
    gpState->mOutputBuffer.mPos = 0;
    gpState->mOutputBuffer.mCapacity = 0;
    DWCi_GsFree(gpState->mOutputBuffer.mBuffer);
    gpState->mOutputBuffer.mBuffer = NULL;
    gpState->mOutputBuffer.mBuffer = NULL;
    gpState->mUpdateproBufferLength = 0;
    gpState->mUpdateproBufferPos = 0;
    gpState->mUpdateproBufferCapacity = 0;
    DWCi_GsFree(gpState->mUpdateproBuffer);
    gpState->mUpdateproBuffer = NULL;
    gpState->mUpdateproBuffer = NULL;
    gpState->mUpdateuiBufferLength = 0;
    gpState->mUpdateuiBufferPos = 0;
    gpState->mUpdateuiBufferCapacity = 0;
    DWCi_GsFree(gpState->mUpdateuiBuffer);
    gpState->mUpdateuiBuffer = NULL;
    gpState->mUpdateuiBuffer = NULL;
    gpState->mListenSocket = -1;
    gpState->mNextOperationId = PROFILE_FIRST_OPERATION_ID;
    operationLink = &gpState->mOperationList;
    while (*operationLink != NULL) {
        gpiRemoveOperation(connection, *operationLink);
    }
    gpState->mOperationList = NULL;
    gpState->mBuddyCount = 0;
    gpiProfileMap(connection, gpiResetProfile, NULL);
    gpState->mUserId = 0;
    gpState->mProfileId = 0;
    gpState->mSesskey = 0;
    gpState->mSearchCount = 0;
    gpState->mFatal = FALSE;
    gpState->mPeerList = NULL;
    gpState->mStatus = -1;
    gpState->mStatusString[0] = 0;
    gpState->mLocationString[0] = 0;
    return 0;
}

u32 gpiProcessConnectionManager(GPConnection *connection) {
    GPIConnection *gpState;
    GPIOperation *pendingOp;
    u32 result;
    s32 operationId;
    char *found;
    char *buffer;
    s32 len;
    u32 socketGone;
    s32 growth;
    socketGone = 0;
    gpState = connection->mGpiConnection;
    do {
        gpiAddLocalInfo(connection, &gpState->mOutputBuffer);
        result = gpiSendFromBuffer(connection, gpState->mConnectSocket, &gpState->mOutputBuffer, &socketGone, 1,
                               (s8 *) "CM");
        if (result != 0) {
            return result;
        }
        result = gpiRecvToBuffer(connection, gpState->mConnectSocket, (GPIBuffer *) &gpState->mInputBuffer,
                                  &len, &socketGone, (s8 *) "CM");
        if (result != 0) {
            if (result == 3) {
                gpiSetError(connection, 5, "There was an error reading from the server.");
                gpiCallErrorCallback(connection, PROFILE_RESULT_NETWORK_ERROR, 1);
                return PROFILE_RESULT_NETWORK_ERROR;
            }
            return result;
        }
        found = strstr(gpState->mInputBuffer, "\\final\\");
        while (found != NULL) {
            *found = 0;
            gpiDebug(connection, "CMD: %s\n", gpState->mInputBuffer);
            len = found - gpState->mInputBuffer;
            if (len > gpState->mCommandBufferCapacity) {
                growth = len;
                if (growth < 0x800) {
                    growth = 0x800;
                }
                gpState->mCommandBufferCapacity = gpState->mCommandBufferCapacity + growth;
                buffer = DWCi_GsRealloc(gpState->mCommandBuffer, gpState->mCommandBufferCapacity + 1);
                if (buffer == NULL) {
                    gpiSetErrorString(connection, "Out of memory.");
                    return PROFILE_RESULT_OUT_OF_MEMORY;
                }
                gpState->mCommandBuffer = buffer;
            }
            memcpy(gpState->mCommandBuffer, gpState->mInputBuffer, len + 1);
            gpState->mInputBufferLength = gpState->mInputBufferLength - (found + 7 - gpState->mInputBuffer);
            memmove(gpState->mInputBuffer, found + 7, gpState->mInputBufferLength + 1);
            buffer = gpState->mCommandBuffer;
            found = strstr(buffer, "\\id\\");
            if (found != NULL) {
                operationId = StrtolBase10(found + 4);
                if (gpiFindOperationByID(connection, &pendingOp, operationId) == FALSE) {
                    gpiDebug(connection, "No matching operation found for id %d\n", operationId);
                } else {
                    result = GpiProcessOperation(connection, pendingOp, gpState->mCommandBuffer);
                    if (result != 0) {
                        return result;
                    }
                }
            } else {
                if (gpiCheckForError(connection, buffer, 1) != FALSE) {
                    return 4;
                }
                buffer = gpState->mCommandBuffer;
                if (strncmp(buffer, "\\bm\\", 4) == 0) {
                    result = gpiProcessRecvBuddyMessage(connection, buffer);
                    if (result != 0) {
                        return result;
                    }
                } else if (strncmp(buffer, "\\ka\\", 10) != 0) {
                    gpiDebug(connection, "Received an unrecognized, unsolicited message.\n");
                }
            }
            found = strstr(gpState->mInputBuffer, "\\final\\");
        }
        if (socketGone != 0) {
            gpState->mConnectState = PROFILE_CONNECTION_CLOSED;
            gpiSetError(connection, 7, "The server has closed the connection.");
            gpiCallErrorCallback(connection, PROFILE_RESULT_NETWORK_ERROR, 1);
            return 0;
        }
        result = gpiOperationsAreBlocking(connection);
        if (result != 0) {
            msleep(10);
        }
    } while (result != 0);
    return 0;
}

int gpiProcess(void *connectionArgument, int blockingOperationID) {
    GPConnection *connection;
    GPIConnection *gpState;
    GPIOperation *operation;
    GPIOperation *opToRemove;
    u32 result;
    u32 callbackResult;
    BOOL loop;
    connection = connectionArgument;
    gpState = connection->mGpiConnection;
    result = 0;
    if ((u32) gpState->mConnectState > PROFILE_CONNECTION_CLOSED) {
        AssertionFailed("(iconnection->connectState == GPI_NOT_CONNECTED) || (iconnection->connectState == "
                        "GPI_CONNECTING) || (iconnection->connectState == GPI_NEGOTIATING) || "
                        "(iconnection->connectState == GPI_CONNECTED) || (iconnection->connectState == "
                        "GPI_DISCONNECTED)",
                        "gpi.c", NULL, 0x1b5);
    }
    if (gpState->mConnectState == PROFILE_CONNECTION_SOCKET_OPENING) {
        do {
            result = gpiCheckConnect(connection);
            if (result == 0 && blockingOperationID != 0 &&
                gpState->mConnectState == PROFILE_CONNECTION_SOCKET_OPENING) {
                loop = TRUE;
            } else {
                loop = FALSE;
            }
            if (loop != FALSE) {
                msleep(10);
            }
        } while (loop != FALSE);
        if (result != 0) {
            if (gpiFindOperationByID(connection, &operation, 1) != FALSE) {
                operation->mResult = PROFILE_REQUEST_FAILED;
            } else {
                AssertionFailed("0", "gpi.c", NULL, 0x1db);
            }
        }
    }
    if ((u32) (gpState->mConnectState - PROFILE_CONNECTION_HANDSHAKE) <= 1) {
        if (result == 0) {
            result = gpiProcessConnectionManager(connection);
        }
        if (result == 0) {
            result = gpiProcessPeers(connection);
        }
    }
    if (result == 0) {
        result = gpiProcessSearches(connection);
    }
    operation = gpState->mOperationList;
    if (operation != NULL) {
        do {
            if (operation->mResult != PROFILE_REQUEST_OK) {
                gpiFailedOpCallback(connection, operation);
                opToRemove = operation;
                operation = operation->mNext;
                gpiRemoveOperation(connection, opToRemove);
            } else {
                operation = operation->mNext;
            }
        } while (operation != NULL);
    }
    callbackResult = gpiProcessCallbacks(connection, blockingOperationID);
    if (callbackResult == 0) {
        if (gpState->mFatal != FALSE) {
            gpiDisconnect(connection, 0);
        }
        callbackResult = result;
    }
    return callbackResult;
}
