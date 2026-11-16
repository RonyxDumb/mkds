#include "00/Lib/GameSpy/unique_nick_transfer.h"
#include "00/Lib/DWC/matching_result_codes.h"

#include "00/Lib/GameSpy/operation_queue.h"
#include "00/Lib/GameSpy/send_buffer.h"
#include "00/Lib/GameSpy/profile_empty_check.h"
#include "00/Lib/GameSpy/reply_parse.h"
#include "00/Lib/DWC/memory_allocator.h"
#include "00/Lib/GameSpy/error_message_set.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "string.h"
#include "print_memory_multibyte_write.h"
#include "narrow_string_functions.h"
#include "text_to_number.h"
#include "00/Lib/GameSpy/profile_list.h"
#include "00/Lib/GameSpy/md5_base64_encode.h"
#include "00/Lib/GameSpy/connect_operation.h"
#include "00/Lib/GameSpy/login_connect_close.h"
#include "00/Lib/GameSpy/profile_info.h"
#include "00/Lib/GameSpy/dynamic_array.h"
#include "00/Lib/GameSpy/buddy_messages.h"
#include "00/Lib/GameSpy/profile_search.h"
#include "00/Lib/GameSpy/peer_connection.h"
#include "00/Lib/GameSpy/error_set.h"
#include "scan_text_random.h"
#include "00/Lib/GameSpy/socket_calls.h"
#include "00/Lib/wifi_library_globals.h"
#include "00/Lib/GameSpy/callback_queue.h"

s32 gpiProcessRegisterUniqueNick(GPConnection *connection, GPIOperation *operation, const char *input) {
    GPICallback callback;
    u32 *arg;
    s32 result;

    if (gpiCheckForError(connection, input, 1) != FALSE) {
        return 4;
    }
    if (strncmp(input, "\\rn\\", 4) != 0) {
        gpiSetError(connection, 1, "Unexpected data was received from the server.");
        gpiCallErrorCallback(connection, PROFILE_RESULT_NETWORK_ERROR, 1);
        return PROFILE_RESULT_NETWORK_ERROR;
    }
    callback = operation->mCallback;
    if (callback.mCallback != NULL) {
        arg = DWCi_GsMalloc(4);
        if (arg == NULL) {
            gpiSetErrorString(connection, "Out of memory.");
            return PROFILE_RESULT_OUT_OF_MEMORY;
        }
        arg[0] = 0;
        result = gpiAddCallback(connection, callback, arg, operation, 0);
        if (result != 0) {
            return result;
        }
    }
    gpiRemoveOperation(connection, operation);
    return 0;
}

s32 gpiSendTransferReply(GPConnection *connection, GPITransferID *transferID, GPIPeer *peer, s32 result,
                         const char *msg) {
    char buffer[0x24];
    s32 stepResult;

    if (msg == NULL) {
        msg = "";
    }
    stepResult = gpiPeerStartTransferMessage(connection, peer, BUDDY_MESSAGE_TYPE_TRANSFER_REPLY, transferID);
    if (stepResult != 0) {
        return stepResult;
    }
    sprintf(buffer, "\\version\\%d\\result\\%d", 1, result);
    stepResult = gpiSendOrBufferString(connection, peer, buffer);
    if (stepResult != 0) {
        return stepResult;
    }
    stepResult = gpiPeerFinishTransferMessage(connection, peer, msg, -1);
    if (stepResult != 0) {
        return stepResult;
    }
    return 0;
}
