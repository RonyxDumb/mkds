#include "00/Lib/NitroWiFi/code_021a6ee4.h"
#include "00/Lib/NitroWiFi/socl_startup.h"
#include "00/Lib/DWC/code_0218a064.h"

#include "00/code_021a6d6c.h"
#include "03/Net/essid_packet_steps.h"
#include "00/code_021a6fb4.h"
#include "00/Lib/NitroWiFi/code_021a6d1c.h"
#include "00/Lib/NitroWiFi/code_021a669c.h"
#include "00/Lib/NitroWiFi/cpsif.h"
#include "00/code_021a73d8.h"
#include "00/code_021a8424.h"
#include "00/code_021a8878.h"
#include "00/Lib/CPS/network.h"
#include "os_thread.h"
#include "code_0214d018.h"
#include "00/unk_021b6000.h"
#include "00/Lib/CPS/code_021a91b4.h"
#include "mb_data.h"
#include "00/unk_021b4000.h"
#include "code_02000b44.h"
#include "code_02133048.h"
#include "code_0200fc8c.h"
#include "00/code_021a6fa8.h"
#include "00/code_021a6fc0.h"
#include "00/code_021a88a8.h"
#include "code_0200e77c.h"
#include "00/unk_021b5000.h"
#include "code_0200edc0.h"
#include "00/code_021a72c4.h"
#include "00/code_021a8aa8.h"
#include "00/code_021a78a4.h"
#include "00/code_021a740c.h"
#include "00/code_021a7000.h"
#include "00/code_021ae1e4.h"
#include "00/code_021a7bfc.h"
#include "00/code_02186d04.h"
#include "00/code_021a7bc8.h"
#include "00/code_021ae000.h"
#include "00/code_021a86bc.h"
#include "00/code_021b026c.h"
#include "00/code_021a8a80.h"
#include "00/Lib/GameSpy/code_0218e2dc.h"
#include "00/Lib/GameSpy/code_021a3a18.h"
#include "os_printf.h"
#include "00/code_021a87bc.h"
#include "00/code_021a75f8.h"
#include "std_string.h"
#include "00/code_021a8604.h"
#include "00/code_021a836c.h"
#include "00/Lib/NitroWiFi/code_021a8a28.h"

void *SOCLiCommandPackets;
OSMessageQueue SOCLiCommandPacketQueue;

s32 SOCL_Bind(SOCLSocket *socket, u16 ownPort) {
    BOOL isCreated;
    if (SOCL_SocketIsInvalid(socket) != 0) {
        return -28;
    }
    isCreated = FALSE;
    if (socket != NULL) {
        isCreated = (socket->mStatusFlags & 1) != 0;
    }
    if (isCreated == FALSE) {
        return -39;
    }
    if (socket->mStatusFlags & 2) {
        return -7;
    }
    socket->mLocalPort = ownPort;
    if (socket->mFlagMode == 1) {
        return SOCLi_ExecBindCommand(socket);
    }
    return 0;
}

s32 SOCL_Connect(SOCLSocket *socket, u16 remotePort, u16 *peerAddr) {
    s32 result;
    BOOL condition;
    volatile SOCLSocket *volatileSocket = socket;

    if (SOCL_SocketIsInvalid(socket) != 0 || (volatileSocket->mStatusFlags & 8)) {
        return -28;
    }
    condition = FALSE;
    if (socket != NULL) {
        condition = (socket->mStatusFlags & 1) != 0;
    }
    if (condition == FALSE) {
        return -39;
    }
    condition = TRUE;
    if (socket->mFlagMode != 0 && socket->mFlagMode != 4) {
        condition = FALSE;
    }
    if (condition != FALSE) {
        if (volatileSocket->mStatusFlags & 4) {
            if (socket->mFlagBlock == 1) {
                return -30;
            }
            return 0;
        }
        if (volatileSocket->mStatusFlags & 2) {
            if (volatileSocket->mStatusFlags & 0x40) {
                return socket->mEntryResult;
            }
            return SOCLiResultCodeInConnecting;
        }
        socket->mRemotePort = remotePort;
        socket->mRemoteIp = peerAddr;
        result = SOCLi_ExecBindCommand(socket);
        if (socket->mFlagBlock == 1) {
            return result;
        }
        return -26;
    }
    socket->mRemotePort = remotePort;
    socket->mRemoteIp = peerAddr;
    return 0;
}

s32 SOCLi_ExecBindCommand(SOCLSocket *socket) {
    SOCLiCommandPacket *cmdPacket;

    cmdPacket = SOCLi_CreateCommandPacket(SOCLi_BindCallBack, socket, socket->mFlagBlock);
    if (cmdPacket == NULL) {
        return -33;
    }
    cmdPacket->mUnk_10 = socket->mLocalPort;
    cmdPacket->mUnk_12 = socket->mRemotePort;
    cmdPacket->mUnk_14 = socket->mRemoteIp;
    socket->mStatusFlags |= 2;
    return SOCLi_ExecCommandPacketInRecvPipe(socket, cmdPacket);
}

s32 SOCLi_BindCallBack(SOCLiCommandPacket *packet) {
    SOCLSocket *sockObj;
    SOCLiSocketRecvCommandPipe *inPipe;
    s32 connectResult;

    sockObj = packet->mSocket;
    connectResult = 0;
    inPipe = sockObj->mReceiveBlock;
    OS_LockMutex(&inPipe->mCommandPipe.mInUse);
    CPS_SocBind(packet->mUnk_10, packet->mUnk_12, (s32) packet->mUnk_14);
    inPipe->mConsumed = 0;
    if (packet->mFlagMode == 0 || packet->mFlagMode == 4) {
        connectResult = CPS_TcpConnect();
    }
    OS_UnlockMutex(&inPipe->mCommandPipe.mInUse);
    if (connectResult != 0) {
        sockObj->mStatusFlags |= 0x40;
        return -76;
    }
    sockObj->mStatusFlags |= 4;
    return 0;
}

s32 SOCL_Listen(s32 socketHandle) {
    SOCLSocket *sockObj = (SOCLSocket *) socketHandle;
    BOOL condition;

    if (SOCL_SocketIsInvalid(sockObj) != 0) {
        return -28;
    }
    condition = FALSE;
    if (sockObj != NULL) {
        condition = (sockObj->mStatusFlags & 1) != 0;
    }
    if (condition == FALSE) {
        return -39;
    }
    if (sockObj->mStatusFlags & 2) {
        return -28;
    }
    condition = TRUE;
    if (sockObj->mFlagMode != 0 && sockObj->mFlagMode != 4) {
        condition = FALSE;
    }
    if (condition == FALSE) {
        return -28;
    }
    if (sockObj->mFlagBlock == 1) {
        return 0;
    }
    return -6;
}

s32 SOCL_Accept(SOCLSocket *socket, u16 *remotePortOut, u32 *remoteIpOut) {
    s32 acceptSocket;
    BOOL condition;
    s32 result;

    if (SOCL_SocketIsInvalid(socket) != 0) {
        return -28;
    }
    condition = FALSE;
    if (socket != NULL) {
        condition = (socket->mStatusFlags & 1) != 0;
    }
    if (condition == FALSE) {
        return -39;
    }
    if (socket->mStatusFlags & 2) {
        return -28;
    }
    condition = TRUE;
    if (socket->mFlagMode != 0 && socket->mFlagMode != 4) {
        condition = FALSE;
    }
    if (condition == FALSE) {
        return -28;
    }
    if (socket->mFlagBlock != 1) {
        return -6;
    }
    acceptSocket = SOCL_CreateSocket(&SOCLSocketParamTCP);
    if (acceptSocket < 0) {
        return acceptSocket;
    }
    result = SOCL_Bind((SOCLSocket *) acceptSocket, socket->mLocalPort);
    if (result < 0) {
        return result;
    }
    result = SOCL_ListenAccept((SOCLSocket *) acceptSocket, remotePortOut, remoteIpOut);
    if (result < 0) {
        return result;
    }
    return acceptSocket;
}

s32 SOCL_ListenAccept(SOCLSocket *socket, u16 *remotePortOut, u32 *remoteIpOut) {
    SOCLiCommandPacket *cmdPacket;
    BOOL condition;
    s32 c;

    if (SOCL_SocketIsInvalid(socket) != 0) {
        return -28;
    }
    condition = FALSE;
    if (socket != NULL) {
        condition = (socket->mStatusFlags & 1) != 0;
    }
    if (condition == FALSE) {
        return -39;
    }
    if (socket->mStatusFlags & 2) {
        return -28;
    }
    condition = TRUE;
    if (socket->mFlagMode != 0 && socket->mFlagMode != 4) {
        condition = FALSE;
    }
    if (condition == FALSE) {
        return -28;
    }
    if (socket->mFlagBlock != 1) {
        return -6;
    }
    if (socket->mLocalPort == 0) {
        return -28;
    }
    cmdPacket = SOCLi_CreateCommandPacket(SOCLi_ListenAcceptCallBack, socket, socket->mFlagBlock);
    cmdPacket->mUnk_10 = socket->mLocalPort;
    cmdPacket->mUnk_14 = remotePortOut;
    cmdPacket->mUnk_18 = remoteIpOut;
    socket->mStatusFlags |= 2;
    return SOCLi_ExecCommandPacketInRecvPipe(socket, cmdPacket);
}

s32 SOCLi_ListenAcceptCallBack(SOCLiCommandPacket *packet) {
    SOCLSocket *sockObj;
    SOCLiSocketRecvCommandPipe *inPipe;
    u16 remotePort;
    u32 ownAddr;
    u32 peerAddr;

    sockObj = packet->mSocket;
    inPipe = sockObj->mReceiveBlock;
    OS_LockMutex(&inPipe->mCommandPipe.mInUse);
    CPS_SocBind(packet->mUnk_10, 0, 0);
    CPS_TcpListen();
    inPipe->mConsumed = 0;
    peerAddr = CPS_SocWho(&remotePort, &ownAddr);
    *packet->mUnk_14 = remotePort;
    *packet->mUnk_18 = peerAddr;
    sockObj->mStatusFlags |= 4;
    OS_UnlockMutex(&inPipe->mCommandPipe.mInUse);
    return 0;
}

s32 SOCL_CreateSocket(SOCLSocketParam *param) {
    SOCLSocket *sockObj;
    SOCLiCommandPacket *cmdPacket;
    sockObj = SOCLi_StartupSocket(param);
    if (sockObj == NULL) {
        return -0x31;
    }
    cmdPacket = SOCLi_CreateCommandPacket(SOCLi_CreateSocketCallBack, sockObj, 1);
    SOCLi_ExecCommandPacketInCtrlPipe(sockObj, cmdPacket);
    return (s32) sockObj;
}

s32 SOCLi_CreateSocketCallBack(SOCLiCommandPacket *command) {
    SOCLSocket *sockObj;
    SOCLiSocketCommandPipe *outPipe;

    sockObj = command->mSocket;
    CPS_SocRegister(sockObj);
    outPipe = &sockObj->mSendBlock->mCommandPipe;
    switch (sockObj->mFlagMode) {
        case 0:
        case 4:
            CPS_SocDup(&outPipe->mThread);
            CPS_SocUse();
            break;
        case 1:
            CPS_SocUse();
            CPS_SocDatagramMode();
            CPS_SetUdpCallback(SOCLi_UdpRecvCallback);
            break;
        case 2:
            CPS_SocDatagramMode();
            break;
        case 3:
            break;
    }
    sockObj->mStatusFlags = 1;
    return 0;
}

SOCLSocket *SOCLi_StartupSocket(SOCLSocketParam *param) {
    s32 size;
    u32 interruptState;
    SOCLSocket *sockObj;

    size = SOCLi_GetSizeSocket(param);
    interruptState = OS_DisableInterrupts();
    sockObj = SOCLiConfigPtr->mAlloc(size);
    if (sockObj != NULL) {
        MI_CpuFill8(sockObj, 0, size);
        SOCLi_InitSocket(sockObj, param);
        SOCLi_SocketRegister(sockObj);
    }
    OS_RestoreInterrupts(interruptState);
    return sockObj;
}

s32 SOCLi_GetSizeSocket(SOCLSocketParam *param) {
    s32 size = 0x80;

    if (param->mRcvbufSize != 0) {
        size += 0x114;
        size += SOCLi_RoundUp4(param->mRcvbufSize);
        size += SOCLi_RoundUp4(param->mLinbufSize);
        size += SOCLi_GetSizeCommandPipe(&param->mRecvPipe);
    }
    if (param->mSndbufSize != 0) {
        size += 0x110;
        size += SOCLi_RoundUp4(param->mSndbufSize);
        size += SOCLi_RoundUp4(param->mOutbufSize);
        size += SOCLi_RoundUp4(param->mWrtbufSize);
        size += SOCLi_GetSizeCommandPipe(&param->mSendPipe);
    }
    return size;
}

int SOCLi_GetSizeCommandPipe(SOCLSocketCommandPipeParam *param) {
    int queueSize;
    int stackSize;
    queueSize = SOCLi_RoundUp4(param->mQueueMax << 2);
    stackSize = SOCLi_RoundUp4(param->mStackSize);
    return queueSize + stackSize;
}

u8 *SOCLi_InitSocket(SOCLSocket *socket, SOCLSocketParam *param) {
    u8 *cursor;
    SOCLiSocketRecvCommandPipe *inPipe;
    SOCLiSocketSendCommandPipe *outPipe;

    socket->mFlagMode = param->mFlagMode;
    socket->mFlagBlock = param->mFlagBlock;
    cursor = (u8 *) &socket->mUnk_80;
    if (param->mRcvbufSize != 0) {
        inPipe = &socket->mUnk_80;
        socket->mReceiveBlock = inPipe;
        inPipe->mConsumedMin = param->mRcvbufConsumeMin;
        cursor = SOCLi_InitCommandPipe(inPipe->mCommandMessages, &inPipe->mCommandPipe, &param->mRecvPipe);
        cursor = SOCLi_InitSocketBuffer(cursor, &socket->mReceiveBuffer, param->mRcvbufSize);
        cursor = SOCLi_InitSocketBuffer(cursor, &socket->mUnk_50, param->mLinbufSize);
        inPipe->mUdpDataSizeMax = param->mUdpbufSize;
        inPipe->mUdpDataWaiting.mTail = NULL;
        inPipe->mUdpDataWaiting.mHead = inPipe->mUdpDataWaiting.mTail;
    }
    if (param->mSndbufSize != 0) {
        outPipe = (SOCLiSocketSendCommandPipe *) cursor;
        socket->mSendBlock = outPipe;
        outPipe->mExeSocket = socket;
        cursor = SOCLi_InitCommandPipe(outPipe->mCommandMessages, &outPipe->mCommandPipe, &param->mSendPipe);
        cursor = SOCLi_InitSocketBuffer(cursor, &socket->mSendBuffer, param->mSndbufSize);
        cursor = SOCLi_InitSocketBuffer(cursor, &socket->mUnk_58, param->mOutbufSize);
        cursor = SOCLi_InitSocketBuffer(cursor, &outPipe->mBufferArea, param->mWrtbufSize);
        outPipe->mBufferWaitingTail = 0;
        outPipe->mBufferWaitingHead = outPipe->mBufferWaitingTail;
    } else {
        socket->mSendBlock = SOCLiUDPSendSocket->mSendBlock;
    }
    return cursor;
}

u8 *SOCLi_InitSocketBuffer(u8 *cursor, SizedBuffer *buffer, s32 size) {
    u8 *start;
    start = cursor;
    if (size == 0) {
        start = NULL;
    }
    buffer->mStart = start;
    buffer->mSize = size;
    return cursor + SOCLi_RoundUp4(size);
}

u8 *SOCLi_InitCommandPipe(u8 *messages, SOCLiSocketCommandPipe *pipe, SOCLSocketCommandPipeParam *param) {
    u8 *stackBottom;

    stackBottom = messages + SOCLi_GetSizeCommandPipe(param);
    OS_InitMessageQueue(&pipe->mQueue, (void **) messages, param->mQueueMax);
    OS_InitMutex(&pipe->mInUse);
    OS_CreateThread(&pipe->mThread, SOCLi_CommandPacketHandler, pipe, stackBottom, param->mStackSize, param->mPriority);
    OS_WakeupThreadDirect(&pipe->mThread);
    return stackBottom;
}

s32 SOCLi_StartupCommandPacketQueue(s32 count) {
    s32 queueBytes;
    void **messages;
    SOCLiCommandPacket *packet;
    s32 packetBytes;

    queueBytes = (count * 4 + 3) & ~3;
    packetBytes = (count * 0x2c + 3) & ~3;
    messages = SOCLiConfigPtr->mAlloc(packetBytes + queueBytes);
    if (messages == NULL) {
        return -1;
    }
    OS_InitMessageQueue(&SOCLiCommandPacketQueue, messages, count);
    packet = OFFSET_PTR(SOCLiCommandPacket, messages, queueBytes);
    if (count > 0) {
        do {
            SOCLi_FreeCommandPacket(packet);
            packet++;
            count--;
        } while (count > 0);
    }
    SOCLiCommandPackets = messages;
    return 0;
}

s32 SOCLi_CleanupCommandPacketQueue(void) {
    if (SOCLiCommandPacketQueue.mCount < SOCLiCommandPacketQueue.mCapacity) {
        return -1;
    }
    SOCLiConfigPtr->mFree(SOCLiCommandPackets);
    SOCLiCommandPackets = NULL;
    return 0;
}

SOCLiCommandPacket *SOCLi_AllocCommandPacket(s32 flag) {
    int received;
    SOCLiCommandPacket *packet[1];
    received = OS_ReceiveMessage(&SOCLiCommandPacketQueue, (void **) packet, flag);
    if (received != 0) {
        return packet[0];
    }
    return NULL;
}

SOCLiCommandPacket *SOCLi_CreateCommandPacket(Unk021a7064Func handler, SOCLSocket *socket, s32 flag) {
    SOCLiCommandPacket *packet;

    packet = SOCLi_AllocCommandPacket(flag);
    if (packet != NULL) {
        packet->mHandler = handler;
        packet->mSocket = socket;
        packet->mFlagBlock = flag;
        packet->mFlagMode = socket->mFlagMode;
    }
    return packet;
}

void SOCLi_FreeCommandPacket(SOCLiCommandPacket *packet) {
    if (packet != NULL) {
        OS_SendMessage(&SOCLiCommandPacketQueue, (packet), 0);
    }
}

s32 SOCLi_SendCommandPacket(SOCLiSocketCommandPipe *pipe, SOCLiCommandPacket *packet) {
    s32 result;

    result = OS_SendMessage(&pipe->mQueue, packet, packet != NULL ? packet->mFlagBlock : 1);
    if (result == 0) {
        SOCLi_FreeCommandPacket(packet);
    }
    if (result != 0) {
        return 0;
    }
    return -42;
}

s32 SOCLi_ExecCommandPacket(SOCLiSocketCommandPipe *pipe, SOCLiCommandPacket *packet) {
    s32 result;
    void *response;
    OSMessageQueue replyQueue;

    if (packet->mFlagBlock == 0) {
        packet->mResponse = NULL;
        result = SOCLi_SendCommandPacket(pipe, packet);
    } else {
        OS_InitMessageQueue(&replyQueue, &response, 1);
        packet->mResponse = &replyQueue;
        SOCLi_SendCommandPacket(pipe, packet);
        OS_ReceiveMessage(&replyQueue, (void **) &result, 1);
    }
    return result;
}

s32 SOCLi_ExecCommandPacketInRecvPipe(SOCLSocket *socket, SOCLiCommandPacket *packet) {
    return SOCLi_ExecCommandPacket(&socket->mReceiveBlock->mCommandPipe, packet);
}

s32 SOCLi_ExecCommandPacketInSendPipe(SOCLSocket *socket, void *packet) {
    return SOCLi_ExecCommandPacket(&socket->mSendBlock->mCommandPipe, packet);
}

s32 SOCLi_ExecCommandPacketInCtrlPipe(SOCLSocket *socket, SOCLiCommandPacket *packet) {
    if (socket->mReceiveBlock != NULL) {
        return SOCLi_ExecCommandPacket(&socket->mReceiveBlock->mCommandPipe, packet);
    }
    return SOCLi_ExecCommandPacket(&socket->mSendBlock->mCommandPipe, packet);
}

void SOCLi_CommandPacketHandler(void *queueArgument) {
    OSMessageQueue *queue = queueArgument;
    SOCLiCommandPacket *packet;
    s32 result;
    u32 interruptState;

    while (1) {
        OS_ReadMessage(queue, (void **) &packet, 1);
        if (packet == NULL) {
            return;
        }
        result = packet->mHandler(packet);
        interruptState = OS_DisableInterrupts();
        OS_DisableScheduler();
        OS_ReceiveMessage(queue, NULL, 0);
        if (packet->mSocket != NULL) {
            packet->mSocket->mEntryResult = result;
        }
        if (packet->mResponse != NULL) {
            OS_SendMessage(packet->mResponse, (void *) result, 0);
        }
        SOCLi_FreeCommandPacket(packet);
        OS_EnableScheduler();
        OS_RestoreInterrupts(interruptState);
        OSi_RescheduleThread();
    }
}
