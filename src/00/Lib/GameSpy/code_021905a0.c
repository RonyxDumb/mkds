#include "00/Lib/GameSpy/code_0218f960.h"
#include "code_02139f70.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "string.h"
#include "code_02134398.h"
#include "00/Lib/GameSpy/code_0218d818.h"
#include "00/Lib/GameSpy/code_0218e2dc.h"
#include "00/Lib/GameSpy/code_021965a0.h"
#include "00/Lib/GameSpy/code_02190ff8.h"
#include "00/Lib/GameSpy/code_021906e4.h"
#include "00/Lib/GameSpy/code_02196594.h"
#include "code_0213a460.h"
#include "00/Lib/GameSpy/code_0218e8d4.h"
#include "00/Lib/GameSpy/gpiProfile.h"
#include "00/Lib/GameSpy/code_02190cd4.h"
#include "00/Lib/GameSpy/code_021947e4.h"
#include "00/Lib/GameSpy/code_021948f8.h"
#include "00/Lib/DWC/dwc_memfunc.h"
#include "00/Lib/GameSpy/code_02196590.h"
#include "00/Lib/GameSpy/code_0218e0fc.h"
#include "00/Lib/GameSpy/code_02191200.h"
#include "00/Lib/GameSpy/code_02196480.h"
#include "00/Lib/GameSpy/code_02192d64.h"
#include "00/Lib/GameSpy/code_02194bb8.h"
#include "00/Lib/GameSpy/code_02193b88.h"

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
        if (strncmp((const char *) (str - 5), "\\msg\\", 5) != 0) {
            return 3;
        }
        *str = 0;
        if (GpiGetValue((const char *) inputBuffer->mBuffer, "\\m\\", intText, 0x10) == FALSE) {
            return 3;
        }
        *type = StrtolBase10(intText);
        if (GpiGetValue((const char *) inputBuffer->mBuffer, "\\len\\", intText, 0x10) == FALSE) {
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
