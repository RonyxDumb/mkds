#include "00/Lib/GameSpy/buddy_messages.h"
#include "narrow_string_functions.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "string.h"
#include "print_memory_multibyte_write.h"
#include "00/Lib/GameSpy/dynamic_array.h"
#include "00/Lib/GameSpy/socket_calls.h"
#include "00/Lib/GameSpy/error_set.h"
#include "00/Lib/GameSpy/login_connect_close.h"
#include "00/Lib/GameSpy/send_buffer.h"
#include "00/Lib/GameSpy/reply_parse.h"
#include "text_to_number.h"
#include "00/Lib/GameSpy/presence_api.h"
#include "00/Lib/GameSpy/profile_walk.h"
#include "00/Lib/GameSpy/callback_queue.h"
#include "00/Lib/GameSpy/profile_empty_check.h"
#include "00/Lib/GameSpy/profile_list.h"
#include "00/Lib/DWC/memory_allocator.h"
#include "00/Lib/GameSpy/error_message_set.h"
#include "00/Lib/GameSpy/md5_base64_encode.h"
#include "00/Lib/GameSpy/connect_operation.h"
#include "00/Lib/GameSpy/unique_nick_transfer.h"
#include "00/Lib/GameSpy/profile_info.h"
#include "00/Lib/GameSpy/profile_search.h"
#include "00/Lib/GameSpy/peer_connection.h"

u32 gpiReadMessageFromBuffer(GpConnection *connection, GpiBuffer *inputBuffer, s32 *message, s32 *type, s32 *plen) {
    char intText[0x10];
    u8 *headerEnd;
    s32 bodyLength;
    s32 bodyEndOffset;
    *message = 0;
    if (inputBuffer->mLength < 5) {
        return 0;
    }
    headerEnd = (u8 *) strchr((const char *) inputBuffer->mBuffer, 10);
    if (headerEnd != NULL) {
        if (strncmp((const char *) (headerEnd - 5), "\\msg\\", 5) != 0) {
            return 3;
        }
        *headerEnd = 0;
        if (gpiValueForKey((const char *) inputBuffer->mBuffer, "\\m\\", intText, 0x10) == FALSE) {
            return 3;
        }
        *type = StrtolBase10(intText);
        if (gpiValueForKey((const char *) inputBuffer->mBuffer, "\\len\\", intText, 0x10) == FALSE) {
            return 3;
        }
        bodyLength = StrtolBase10(intText);
        bodyEndOffset = bodyLength + 1;
        if (inputBuffer->mLength > bodyEndOffset + (headerEnd - inputBuffer->mBuffer)) {
            if (*(s8 *) (headerEnd + bodyEndOffset) != 0) {
                return 3;
            }
            *message = (s32) (headerEnd + 1);
            *plen = bodyLength;
            inputBuffer->mPos = bodyEndOffset + (headerEnd - inputBuffer->mBuffer) + 1;
        } else {
            *headerEnd = 10;
        }
    }
    return 0;
}

u32 gpiClipBufferToPosition(GpConnection *connection, GpiBuffer *buffer) {
    s32 position;
    if (buffer == NULL || buffer->mBuffer == NULL || (position = buffer->mPos) == 0) {
        return 0;
    }
    buffer->mLength = buffer->mLength - position;
    if (buffer->mLength != 0) {
        memmove(buffer->mBuffer, buffer->mBuffer + buffer->mPos, buffer->mLength);
    }
    buffer->mBuffer[buffer->mLength] = 0;
    buffer->mPos = 0;
    return 0;
}
