#include "00/Lib/GameSpy/code_02190548.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"
#include "00/Lib/GameSpy/code_0218d818.h"
#include "00/Lib/GameSpy/code_0218e2dc.h"
#include "00/Lib/GameSpy/code_021965a0.h"
#include "00/Lib/GameSpy/code_02190ff8.h"
#include "00/code_02196000.h"
#include "00/Lib/GameSpy/code_021906e4.h"
#include "00/Lib/GameSpy/code_02196594.h"
#include "00/unk_021b23b0.h"
#include "code_0213a460.h"

u32 gpiReadMessageFromBuffer(GpConnection *connection, GpiBuffer *inputBuffer, s32 *message, s32 *type, s32 *plen) {
    char intText[0x10];
    u8 *str;
    s32 bodyLength;
    s32 len;
    *message = 0;
    if (inputBuffer->mLength < 5) {
        return 0;
    }
    str = (u8 *) strchr((const char *) inputBuffer->mBuffer, 10);
    if (str != NULL) {
        if (strncmp((const char *) (str - 5), data_ov000_021b287c, 5) != 0) {
            return 3;
        }
        *str = 0;
        if (GpiGetValue((const char *) inputBuffer->mBuffer, gMKey, intText, 0x10) == FALSE) {
            return 3;
        }
        *type = StrtolBase10(intText);
        if (GpiGetValue((const char *) inputBuffer->mBuffer, gLenKey, intText, 0x10) == FALSE) {
            return 3;
        }
        bodyLength = StrtolBase10(intText);
        len = bodyLength + 1;
        if (inputBuffer->mLength > len + (str - inputBuffer->mBuffer)) {
            if (*(s8 *) (str + len) != 0) {
                return 3;
            }
            *message = (s32) (str + 1);
            *plen = bodyLength;
            inputBuffer->mPos = len + (str - inputBuffer->mBuffer) + 1;
        } else {
            *str = 10;
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

u32 gpiSendAuthBuddyRequest(GpConnection *connection, GpiProfile *profile) {
    GpiConnection *gpState;
    gpState = connection->mGpiConnection;
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gAuthaddKey);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, data_ov000_021b275c);
    GpiAppendBufferNumber(connection, &gpState->mOutputBuffer, gpState->mSesskey);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gFromprofileidKey);
    GpiAppendBufferNumber(connection, &gpState->mOutputBuffer, profile->mProfileId);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gSigKey);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, profile->mAuthSig);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, data_ov000_021b2778);
    return 0;
}
