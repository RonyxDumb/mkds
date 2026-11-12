#include "00/Lib/GameSpy/code_0219887c.h"
#include "00/Lib/GameSpy/code_02197e58.h"
#include "00/unk_021b3000.h"
#include "code_02134398.h"

u16 GetSocketPort(Gt2Socket *socket) {
    return socket->mPort;
}

int gt2GetOutgoingBufferFreeSpace(Gt2Connection *connection) {
    return connection->mSendBuffer.mSize - connection->mSendBuffer.mLength;
}

u32 GetSocketDescriptor(u32 *socket) {
    return *socket;
}

void SetUnmatchedDataCallback(Gt2Socket *socket, UnkWordFunc *callback) {
    socket->mUnmatchedDataCallback = callback;
}

void gt2SetConnectionData(Unk0219887c *connection, void *data) {
    if (connection == NULL) {
        AssertionFailed("connection", "gt2Main.c", NULL, 0x19c);
    }
    connection->mData = data;
}

u8 *gt2GetConnectionData(Unk0219887c *object) {
    if (object == NULL) {
        AssertionFailed("connection", "gt2Main.c", NULL, 0x1a3);
    }
    return object->mData;
}
