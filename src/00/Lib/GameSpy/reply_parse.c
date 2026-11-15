#include "00/Lib/GameSpy/reply_parse.h"

#include "00/Lib/GameSpy/callback_queue.h"
#include "00/Lib/GameSpy/buddy_messages.h"
#include "00/Lib/GameSpy/presence_api.h"
#include "00/Lib/GameSpy/error_set.h"
#include "print_memory_functions.h"
#include "narrow_string_functions.h"
#include "text_to_number.h"

void GpiCopyString(char *dest, const char *src, s32 len) {
    if (dest == NULL) {
        AssertionFailed("dest != NULL", "gpiUtility.c", NULL, 0x2f);
    }
    if (src == NULL) {
        AssertionFailed("src != NULL", "gpiUtility.c", NULL, 0x30);
    }
    strncpy(dest, src, len);
    *(dest + len + -1) = 0;
}

void gpiDebug(GpConnection *connection, const char *fmt, ...) {}

BOOL GpiReadError(GpConnection *connection, const char *input, s32 callErrorCallback) {
    GpiConnection *gpState;
    BOOL isFatalErr;
    char buffer[0x10];

    gpState = connection->mGpiConnection;
    if (strncmp(input, "\\error\\", 7) == 0) {
        if (GpiGetValue(input, "\\err\\", buffer, 0x10) != FALSE) {
            gpState->mErrorNumber = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, "\\errmsg\\", gpState->mErrorMessage, 0x100) == FALSE) {
            gpState->mErrorMessage[0] = 0;
        }
        if (callErrorCallback != 0) {
            isFatalErr = (strstr(input, "\\fatal\\") != NULL);
            GpiQueueErrorCallback(connection, 4, (isFatalErr != FALSE) ? 1 : 0);
        }
        return TRUE;
    }
    return FALSE;
}

BOOL GpiGetValue(const char *command, const char *key, char *value, s32 len) {
    const char *keyStart;
    const char *start;
    s32 index;
    s8 stopChar;
    s8 character;

    if (command == NULL) {
        AssertionFailed("command != NULL", "gpiUtility.c", NULL, 0x10d);
    }
    if (key == NULL) {
        AssertionFailed("key != NULL", "gpiUtility.c", NULL, 0x10e);
    }
    if (value == NULL) {
        AssertionFailed("value != NULL", "gpiUtility.c", NULL, 0x10f);
    }
    if (len <= 0) {
        AssertionFailed("len > 0", "gpiUtility.c", NULL, 0x110);
    }
    stopChar = *key;
    keyStart = strstr(command, key);
    if (keyStart == NULL) {
        return FALSE;
    }
    start = keyStart + strlen(key);
    for (index = 0; index < len - 1 && (character = start[index]) != 0 && character != stopChar; index++) {
        value[index] = character;
    }
    value[index] = 0;
    return TRUE;
}

u32 GpiCheckConnectComplete(GpConnection *connection, u32 sock, u32 *state) {
    int readyNum;
    u32 canWrite;
    u32 errFlags[2];
    canWrite = 0;
    errFlags[0] = 0;
    readyNum = GSISocketSelect((u32) sock, NULL, &canWrite, errFlags);
    if (readyNum == -1) {
        gpiDebug(connection, "Error connecting\n");
        GpiSetError(connection, 5, "There was an error checking for a completed connection.");
        GpiQueueErrorCallback(connection, 3, 1);
        return 3;
    }
    if (0 < readyNum) {
        if (errFlags[0] != 0) {
            gpiDebug(connection, "Connection rejected\n");
            *state = 4;
            return 0;
        }
        if (canWrite != 0) {
            gpiDebug(connection, "Connection accepted\n");
            *state = 3;
            return 0;
        }
    }
    *state = 0;
    return 0;
}

s32 GpiReadKeyValue(GpConnection *connection, s8 *buffer, s32 *index, char *key, char *value) {
    s8 *start;
    s8 character;
    s32 length;

    if (buffer == NULL) {
        AssertionFailed("buffer != NULL", "gpiUtility.c", NULL, 0x199);
    }
    if (key == NULL) {
        AssertionFailed("key != NULL", "gpiUtility.c", NULL, 0x19a);
    }
    if (value == NULL) {
        AssertionFailed("value != NULL", "gpiUtility.c", NULL, 0x19b);
    }
    start = buffer + *index;
    if (*start != 0x5c) {
        GpiSetError(connection, 1, "Parse Error.");
        GpiQueueErrorCallback(connection, 3, 1);
        return 3;
    }
    length = 0;
    buffer = start + 2;
    character = start[1];
    if (character != 0x5c) {
        do {
            if (character == 0) {
                GpiSetError(connection, 1, "Parse Error.");
                GpiQueueErrorCallback(connection, 3, 1);
                return 3;
            }
            if (length == 0x1ff) {
                GpiSetError(connection, 1, "Parse Error.");
                GpiQueueErrorCallback(connection, 3, 1);
                return 3;
            }
            *key = character;
            key++;
            length++;
            character = *buffer;
            buffer++;
        } while (character != 0x5c);
    }
    *key = 0;
    length = 0;
    while ((character = *buffer++) != 0x5c && character != 0) {
        if (length == 0x1ff) {
            GpiSetError(connection, 1, "Parse Error.");
            GpiQueueErrorCallback(connection, 3, 1);
            return 3;
        }
        *value = character;
        value++;
        length++;
    }
    *value = 0;
    *index = *index + ((buffer - start) - 1);
    return 0;
}
