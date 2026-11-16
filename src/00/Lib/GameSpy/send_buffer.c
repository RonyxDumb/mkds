#include "00/Lib/GameSpy/send_buffer.h"
#include "00/Lib/DWC/matching_result_codes.h"
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
#include "00/Lib/GameSpy/unique_nick_transfer.h"
#include "00/Lib/GameSpy/login_connect_close.h"
#include "00/Lib/GameSpy/profile_info.h"
#include "00/Lib/GameSpy/dynamic_array.h"
#include "00/Lib/GameSpy/buddy_messages.h"
#include "00/Lib/GameSpy/profile_search.h"
#include "00/Lib/GameSpy/peer_connection.h"

#include "00/Lib/GameSpy/socket_calls.h"
#include "00/Lib/GameSpy/error_set.h"
#include "00/Lib/GameSpy/profile_walk.h"
#include "00/Lib/GameSpy/callback_queue.h"

u32 gpiAppendCharToBuffer(void *connection, GPIBuffer *outputBuffer, s32 byte) {
    u8 *buffer;
    s32 length;
    s32 capacity;

    if (outputBuffer == NULL) {
        AssertionFailed("outputBuffer != NULL", "gpiBuffer.c", NULL, 0x25);
    }
    length = outputBuffer->mLength;
    capacity = outputBuffer->mCapacity;
    buffer = outputBuffer->mBuffer;
    if (capacity == length) {
        capacity += 0x800;
        buffer = DWCi_GsRealloc(buffer, capacity + 1);
        if (buffer == NULL) {
            gpiSetErrorString(connection, "Out of memory.");
            return GP_MEMORY_ERROR;
        }
    }
    buffer[length] = byte;
    buffer[length + 1] = 0;
    outputBuffer->mLength += 1;
    outputBuffer->mCapacity = capacity;
    outputBuffer->mBuffer = buffer;
    return 0;
}

u32 gpiAppendStringToBufferLen(void *connection, GPIBuffer *outputBuffer, const void *string, s32 stringLen) {
    s32 capacity;
    u8 *buffer;
    s32 length;

    if (string == NULL) {
        AssertionFailed("string != NULL", "gpiBuffer.c", NULL, 0x51);
    }
    if (stringLen < 0) {
        AssertionFailed("stringLen >= 0", "gpiBuffer.c", NULL, 0x52);
    }
    if (outputBuffer == NULL) {
        AssertionFailed("outputBuffer != NULL", "gpiBuffer.c", NULL, 0x53);
    }
    if (string == NULL) {
        return 0;
    }
    length = outputBuffer->mLength;
    capacity = outputBuffer->mCapacity;
    buffer = outputBuffer->mBuffer;
    if (capacity - length < stringLen) {
        capacity += stringLen < 0x800 ? 0x800 : stringLen;
        buffer = DWCi_GsRealloc(buffer, capacity + 1);
        if (buffer == NULL) {
            gpiSetErrorString(connection, "Out of memory.");
            return GP_MEMORY_ERROR;
        }
    }
    memcpy(buffer + length, string, stringLen);
    buffer[length + stringLen] = 0;
    outputBuffer->mLength += stringLen;
    outputBuffer->mCapacity = capacity;
    outputBuffer->mBuffer = buffer;
    return 0;
}

u32 gpiAppendStringToBuffer(void *connection, void *outputBuffer, const void *string) {
    return gpiAppendStringToBufferLen(connection, outputBuffer, string, strlen(string));
}

u32 gpiAppendIntToBuffer(void *connection, void *outputBuffer, u32 number) {
    char numberText[0x14];

    sprintf(numberText, "%d", number);
    return gpiAppendStringToBuffer(connection, outputBuffer, numberText);
}

u32 gpiSendData(GPConnection *connection, s32 sock, const void *data, s32 dataLen, s32 *wasClosed, s32 *bytesSent,
                 const s8 *label) {
    s32 sendResult;
    u32 lastError;

    sendResult = send(sock, data, dataLen, 0);
    if (sendResult == -1) {
        lastError = GOAGetLastError(sock);
        if (lastError != -6 && lastError != -0x1a && lastError != -0x4c) {
            if (label[0] == 0x50 && label[1] == 0x52) {
                return 3;
            }
            gpiSetError(connection, 5, "There was an error sending on a socket.");
            gpiCallErrorCallback(connection, GP_NETWORK_ERROR, 0);
            return GP_NETWORK_ERROR;
        }
        *bytesSent = 0;
        *wasClosed = 0;
    } else if (sendResult == 0) {
        gpiDebug(connection, "SENDXXXX(%s): Connection closed\n", label);
        *bytesSent = 0;
        *wasClosed = 1;
    } else {
        *bytesSent = sendResult;
        *wasClosed = 0;
    }
    return 0;
}

u32 gpiSendOrBufferChar(GPConnection *connection, GPIPeer *gpiPeer, s8 byte) {
    s32 wasClosed;
    s32 bytesSent;
    u32 sendResult;

    if (gpiPeer->mOutputBuffer.mBuffer == NULL) {
        AssertionFailed("peer->outputBuffer.buffer != NULL", "gpiBuffer.c", NULL, 0xde);
    }
    if (gpiPeer->mOutputBuffer.mLength - gpiPeer->mOutputBuffer.mPos == 0 &&
        ArrayLength(gpiPeer->mQueuedMessages) == 0) {
        sendResult = gpiSendData(connection, gpiPeer->mSocket, &byte, 1, &wasClosed, &bytesSent, (s8 *) "PT");
        if (sendResult != 0) {
            return sendResult;
        }
        if (bytesSent != 0) {
            return 0;
        }
    }
    return gpiAppendCharToBuffer(connection, &gpiPeer->mOutputBuffer, byte);
}

u32 gpiSendOrBufferStringLen(GPConnection *connection, GPIPeer *gpiPeer, const char *data, s32 byteCount) {
    s32 offset;
    s32 wasClosed;
    s32 bytesSent;
    u32 sendResult;

    if (gpiPeer->mOutputBuffer.mBuffer == NULL) {
        AssertionFailed("peer->outputBuffer.buffer != NULL", "gpiBuffer.c", NULL, 0xfb);
    }
    offset = 0;
    if (byteCount == 0) {
        return offset;
    }
    if (gpiPeer->mOutputBuffer.mLength - gpiPeer->mOutputBuffer.mPos == 0 &&
        ArrayLength(gpiPeer->mQueuedMessages) == 0) {
        do {
            sendResult = gpiSendData(connection, gpiPeer->mSocket, data + offset, byteCount, &wasClosed, &bytesSent,
                                      (s8 *) "PT");
            if (sendResult != 0) {
                return sendResult;
            }
            if (bytesSent != 0) {
                offset += bytesSent;
                byteCount -= bytesSent;
            }
        } while (bytesSent != 0 && byteCount != 0);
    }
    if (byteCount != 0) {
        sendResult = gpiAppendStringToBufferLen(connection, &gpiPeer->mOutputBuffer, data + offset, byteCount);
        if (sendResult != 0) {
            return sendResult;
        }
    }
    return 0;
}

u32 gpiSendOrBufferString(GPConnection *connection, GPIPeer *gpiPeer, const char *string) {
    u32 stringLen = strlen(string);
    return gpiSendOrBufferStringLen(connection, gpiPeer, string, stringLen);
}

static void UnusedFormatDecimal(char *text, u32 number) {
    sprintf(text, "%d", number);
}

u32 gpiRecvToBuffer(GPConnection *connection, s32 sock, GPIBuffer *inputBuffer, s32 *bytesRead, u32 *connClosed,
                     const s8 *label) {
    u8 *buffer;
    s32 length;
    s32 capacity;
    s32 totalRead;
    BOOL isClosed;
    s32 recvResult;
    BOOL unusedFlag;
    s32 value;

    if (sock == -1) {
        AssertionFailed("sock != INVALID_SOCKET", "gpiBuffer.c", NULL, 0x150);
    }
    if (inputBuffer == NULL) {
        AssertionFailed("inputBuffer != NULL", "gpiBuffer.c", NULL, 0x151);
    }
    if (bytesRead == NULL) {
        AssertionFailed("bytesRead != NULL", "gpiBuffer.c", NULL, 0x152);
    }
    if (connClosed == NULL) {
        AssertionFailed("connClosed != NULL", "gpiBuffer.c", NULL, 0x153);
    }
    buffer = inputBuffer->mBuffer;
    length = inputBuffer->mLength;
    capacity = inputBuffer->mCapacity;
    totalRead = 0;
    isClosed = FALSE;
    recvResult = 0;
    unusedFlag = FALSE;
    do {
        value = length + 0x800;
        if (value > capacity) {
            capacity = value;
            buffer = DWCi_GsRealloc(buffer, value + 1);
            if (buffer == NULL) {
                gpiSetErrorString(connection, "Out of memory.");
                return GP_MEMORY_ERROR;
            }
        }
        recvResult = recv(sock, buffer + length, capacity - length, 0);
        if (recvResult == -1) {
            value = GOAGetLastError(sock);
            if (value != -6 && value != -0x1a && value != -0x4c) {
                gpiSetErrorString(connection, "There was an error reading from a socket.");
                return 3;
            }
        } else if (recvResult == 0) {
            isClosed = TRUE;
            gpiDebug(connection, "RECVXXXX(%s): Connection closed\n", label);
        } else {
            length += recvResult;
            totalRead += recvResult;
        }
        buffer[length] = 0;
    } while (recvResult != -1 && isClosed == FALSE && totalRead < 0x20000);
    if (totalRead != 0) {
        gpiDebug(connection, "RECVTOTL(%s): %d\n", label, totalRead);
    }
    inputBuffer->mBuffer = buffer;
    inputBuffer->mLength = length;
    inputBuffer->mCapacity = capacity;
    *bytesRead = totalRead;
    *connClosed = isClosed;
    return 0;
}

u32 gpiSendFromBuffer(GPConnection *connection, s32 sock, GPIBuffer *outputBuffer, u32 *connClosed, s32 discardSent,
                  const s8 *label) {
    s32 wasClosed;
    s32 bytesSent;
    u8 *buffer;
    s32 len;
    s32 pos;
    s32 totalSent;
    s32 remaining;
    s32 sentNow;
    u32 sendResult;

    if (outputBuffer == NULL) {
        AssertionFailed("outputBuffer != NULL", "gpiBuffer.c", NULL, 0x1b9);
    }
    buffer = outputBuffer->mBuffer;
    len = outputBuffer->mLength;
    pos = outputBuffer->mPos;
    remaining = len - pos;
    totalSent = 0;
    if (remaining == 0) {
        return totalSent;
    }
    do {
        sendResult =
            gpiSendData(connection, sock, buffer + (pos + totalSent), remaining, &wasClosed, &bytesSent, label);
        if (sendResult != 0) {
            return sendResult;
        }
        sentNow = bytesSent;
        if (sentNow != 0) {
            totalSent += sentNow;
            remaining -= sentNow;
        }
    } while (sentNow != 0 && remaining != 0);
    if (discardSent != 0) {
        if (totalSent > 0) {
            memmove(buffer, buffer + totalSent, remaining + 1);
            len -= totalSent;
        }
    } else {
        pos += totalSent;
    }
    if (len < 0) {
        AssertionFailed("len >= 0", "gpiBuffer.c", NULL, 0x1de);
    }
    if (pos < 0) {
        AssertionFailed("pos >= 0", "gpiBuffer.c", NULL, 0x1df);
    }
    if (pos > len) {
        AssertionFailed("pos <= len", "gpiBuffer.c", NULL, 0x1e0);
    }
    outputBuffer->mLength = len;
    outputBuffer->mPos = pos;
    if (connClosed != NULL) {
        *connClosed = wasClosed;
    }
    return 0;
}
