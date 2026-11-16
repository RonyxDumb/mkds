#include "00/Lib/GameSpy/socket_accessors.h"
#include "00/Lib/GameSpy/connection_events.h"
#include "print_memory_multibyte_write.h"

u16 GetSocketPort(Gt2Socket *socket) {
    return socket->mPort;
}

int gt2GetOutgoingBufferFreeSpace(Gt2Connection *connection) {
    return connection->mSendBuffer.mSize - connection->mSendBuffer.mLength;
}

u32 GetSocketDescriptor(Gt2Socket *socket) {
    return socket->mDescriptor;
}

void SetUnmatchedDataCallback(Gt2Socket *socket, Gt2UnmatchedDataCallback callback) {
    socket->mUnmatchedDataCallback = callback;
}

void gt2SetConnectionData(Gt2Connection *connection, void *data) {
    if (connection == NULL) {
        LogThrowAssertion("connection", "gt2Main.c", NULL, 0x19c);
    }
    connection->mData = data;
}

u8 *gt2GetConnectionData(Gt2Connection *object) {
    if (object == NULL) {
        LogThrowAssertion("connection", "gt2Main.c", NULL, 0x1a3);
    }
    return object->mData;
}
