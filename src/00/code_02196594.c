#include "00/code_02196594.h"

#include "00/code_02190cd4.h"
#include "00/code_0218f960.h"
#include "00/code_02194000.h"
#include "00/code_0218e8d4.h"
#include "00/code_02196000.h"
#include "00/code_021965a0.h"
#include "code_02134398.h"
#include "00/unk_021b3000.h"
#include "code_02139f70.h"
#include "code_0213a460.h"

void GpiCopyString(char *dest, const char *src, s32 len) {
    if (dest == NULL) {
        AssertionFailed(gDestAssertText, gGpiUtilityFileName, NULL, 0x2f);
    }
    if (src == NULL) {
        AssertionFailed(gSrcAssertText, gGpiUtilityFileName, NULL, 0x30);
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
    if (strncmp(input, gErrorKey, 7) == 0) {
        if (GpiGetValue(input, gErrKey, buffer, 0x10) != FALSE) {
            gpState->mErrorNumber = StrtolBase10(buffer);
        }
        if (GpiGetValue(input, gGpErrmsgKey, gpState->mErrorMessage, 0x100) == FALSE) {
            gpState->mErrorMessage[0] = 0;
        }
        if (callErrorCallback != 0) {
            isFatalErr = (strstr(input, data_ov000_021b3b08) != NULL);
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
        AssertionFailed(gCommandAssertText, gGpiUtilityFileName, NULL, 0x10d);
    }
    if (key == NULL) {
        AssertionFailed(gKeyAssertText, gGpiUtilityFileName, NULL, 0x10e);
    }
    if (value == NULL) {
        AssertionFailed(gValueAssertText, gGpiUtilityFileName, NULL, 0x10f);
    }
    if (len <= 0) {
        AssertionFailed(data_ov000_021b3ae4, gGpiUtilityFileName, NULL, 0x110);
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
    int canWrite;
    int errFlags[2];
    canWrite = 0;
    errFlags[0] = 0;
    readyNum = GSISocketSelect((u32) sock, NULL, (u32 *) (&canWrite), (u32 *) errFlags);
    if (readyNum == -1) {
        gpiDebug(connection, gErrorConnectingDebugText);
        GpiSetError(connection, 5, gCompletedConnectionErrorString);
        GpiQueueErrorCallback(connection, 3, 1);
        return 3;
    }
    if (0 < readyNum) {
        if (errFlags[0] != 0) {
            gpiDebug(connection, gConnectionRejectedDebugText);
            *state = 4;
            return 0;
        }
        if (canWrite != 0) {
            gpiDebug(connection, gConnectionAcceptedDebugText);
            *state = 3;
            return 0;
        }
    }
    *state = 0;
    return 0;
}

s32 GpiReadKeyValue(GpConnection *connection, s8 *buffer, s32 *index, s8 *key, s8 *value) {
    s8 *start;
    s8 character;
    s32 length;

    if (buffer == NULL) {
        AssertionFailed(gBufferAssertText, gGpiUtilityFileName, NULL, 0x199);
    }
    if (key == NULL) {
        AssertionFailed(gKeyAssertText, gGpiUtilityFileName, NULL, 0x19a);
    }
    if (value == NULL) {
        AssertionFailed(gValueAssertText, gGpiUtilityFileName, NULL, 0x19b);
    }
    start = buffer + *index;
    if (*start != 0x5c) {
        GpiSetError(connection, 1, gParseErrorString);
        GpiQueueErrorCallback(connection, 3, 1);
        return 3;
    }
    length = 0;
    buffer = start + 2;
    character = start[1];
    if (character != 0x5c) {
        do {
            if (character == 0) {
                GpiSetError(connection, 1, gParseErrorString);
                GpiQueueErrorCallback(connection, 3, 1);
                return 3;
            }
            if (length == 0x1ff) {
                GpiSetError(connection, 1, gParseErrorString);
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
            GpiSetError(connection, 1, gParseErrorString);
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
