#include "00/code_0219960c.h"
#include "00/code_02198a8c.h"

u32 gti2HandlePing(Gt2Connection *connection, u32 message, u32 len) {
    u32 value0 = (u32) connection;
    u32 value1 = message;
    u32 value2 = len;
    u32 value3;
    value3 = (u32) &gti2SendPong;
    value0 = gti2SendPong(value0, value1, value2);
    return value0;
}
