#include "00/Lib/GameSpy/socket_accessors.h"
#include "00/Lib/GameSpy/connection_events.h"
#include "print_memory_multibyte_write.h"

u16 gt2GetLocalPort(GTI2Socket *socket) {
    return socket->mPort;
}

int gt2GetOutgoingBufferFreeSpace(GTI2Connection *connection) {
    return connection->mSendBuffer.mSize - connection->mSendBuffer.mLength;
}

u32 gt2GetSocketSOCKET(GTI2Socket *socket) {
    return socket->mDescriptor;
}

void gt2SetUnrecognizedMessageCallback(GTI2Socket *socket, UnmatchedDataCallback callback) {
    socket->mUnmatchedDataCallback = callback;
}

void gt2SetConnectionData(GTI2Connection *connection, void *data) {
    if (connection == NULL) {
        AssertionFailed("connection", "gt2Main.c", NULL, 0x19c);
    }
    connection->mData = data;
}

u8 *gt2GetConnectionData(GTI2Connection *object) {
    if (object == NULL) {
        AssertionFailed("connection", "gt2Main.c", NULL, 0x1a3);
    }
    return object->mData;
}
