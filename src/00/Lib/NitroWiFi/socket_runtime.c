#include "00/Lib/NitroWiFi/socket_runtime.h"
#include "00/Lib/NitroWiFi/socket_library_startup.h"
#include "00/Lib/DWC/socket_config.h"

#include "00/Lib/NitroWiFi/socket_startup_commands.h"
#include "03/Net/essid_packet_steps.h"
#include "00/Lib/NitroWiFi/socket_command_packet.h"
#include "00/Lib/NitroWiFi/link_on_and_bssid_compare.h"
#include "00/Lib/NitroWiFi/access_point_list.h"
#include "00/Lib/NitroWiFi/wifi_stack_bridge.h"
#include "00/Lib/NitroWiFi/socket_create_call.h"
#include "00/Lib/NitroWiFi/dns_resolver_setting.h"
#include "00/Lib/CPS/tcp_ip_stack.h"
#include "thread_scheduler.h"
#include "cpu_copy_fill.h"
#include "00/Lib/CPS/stack_globals.h"
#include "00/Lib/CPS/https_session_upkeep.h"
#include "multiboot_piece_buffers.h"
#include "00/Lib/wifi_library_globals.h"
#include "startup_entry.h"
#include "signed_int_divide.h"
#include "reset_interrupts_halt.h"
#include "00/Lib/NitroWiFi/socket_objects.h"
#include "00/Lib/CPS/socket_status_resolve.h"
#include "thread_mutex_types.h"
#include "00/Lib/wifi_library_work_objects.h"
#include "mutex_init_decl.h"
#include "00/Lib/NitroWiFi/socket_allocation.h"
#include "00/Lib/NitroWiFi/socket_api_prototypes.h"
#include "00/Lib/NitroWiFi/udp_read_command.h"
#include "00/Lib/NitroWiFi/socket_listen_accept.h"
#include "00/Lib/NitroWiFi/socket_write_buffer.h"
#include "00/Lib/DWC/http_transfer.h"
#include "00/Lib/NitroWiFi/socket_read_command.h"
#include "00/Lib/NitroWiFi/socket_shutdown_all.h"
#include "00/Lib/NitroWiFi/socket_validity.h"
#include "00/Lib/GameSpy/socket_calls.h"
#include "00/Lib/GameSpy/query_reporting.h"
#include "formatted_text_to_buffer.h"
#include "string_copy_zero_fill.h"
#include "00/Lib/NitroWiFi/socket_api_calls.h"

s32 SOCLi_CheckCount[2];

u32 SOCLi_RoundUp4(int size) {
    return size + 3U & 0xfffffffc;
}

// The halfword at 0x70 is read again for every test, through a volatile view of the object.
u32 SOCL_GetStatus(SOCLSocket *socket) {
    u32 status = 0;
    u32 interruptState;
    BOOL isTcp;
    volatile SOCLSocket *volatileSocket = socket;
    if (SOCL_SocketIsInvalid(socket) != 0) {
        status |= 0x80;
    } else {
        if ((volatileSocket->mStatusFlags & SOCL_STATUS_ERROR) != 0) {
            status |= 0x20;
        }
        if (socket->mFlagMode == SOCKET_MODE_DATAGRAM_RECEIVE ||
            (volatileSocket->mStatusFlags & SOCL_STATUS_CONNECTED) != 0) {
            interruptState = OS_DisableInterrupts();
            if (SOCLi_GetReadBufferOccpiedSize(socket) > 0) {
                status |= 1;
            }
            if (SOCLi_GetWriteBufferFreeSize(socket) > 0) {
                status |= 8;
            }
            OS_RestoreInterrupts(interruptState);
        }
        isTcp = TRUE;
        if (socket->mFlagMode != SOCKET_MODE_STREAM && socket->mFlagMode != SOCKET_MODE_STREAM_DIRECT_READ) {
            isTcp = FALSE;
        }
        if (isTcp != FALSE) {
            if ((volatileSocket->mStatusFlags & SOCL_STATUS_CONNECTED) != 0 &&
                socket->mCps.mState != SOCKET_STATE_ESTABLISHED && (status & 1) == 0) {
                volatileSocket->mStatusFlags &= ~(SOCL_STATUS_CONNECTING | SOCL_STATUS_CONNECTED);
            }
            if ((volatileSocket->mStatusFlags & SOCL_STATUS_CONNECTING) == 0 &&
                (volatileSocket->mStatusFlags & SOCL_STATUS_CONNECTED) == 0) {
                status |= 0x40;
            }
        }
    }
    return status;
}

s32 SOCLi_GetReadBufferOccpiedSize(SOCLSocket *socket) {
    u32 size;
    SOCLiSocketRecvCommandPipe *inPipe;
    s8 kind;
    inPipe = socket->mReceiveBlock;
    size = 0;
    if (inPipe != NULL) {
        kind = socket->mFlagMode;
        if (kind == SOCKET_MODE_DATAGRAM_RECEIVE) {
            if (inPipe->mUdpDataOut != NULL) {
                size = inPipe->mUdpDataOut->mSize;
            }
        } else if ((kind == SOCKET_MODE_STREAM) || (kind == SOCKET_MODE_STREAM_DIRECT_READ)) {
            size = socket->mCps.mReceiveBufferLength - inPipe->mConsumed;
        }
    }
    return size;
}

s32 SOCL_Resolve(const char *hostname) {
    CPSSoc soc;
    u8 *memory;
    s32 resolvedAddr;
    if (hostname == NULL) {
        return 0;
    }
    memory = SOCLiConfigPtr->mAlloc(0x1154);
    if (memory == NULL) {
        return 0;
    }
    MI_CpuFill8(&soc, 0, sizeof(soc));
    soc.mReceiveBuffer.mStart = memory;
    soc.mReceiveBuffer.mSize = 0xb68;
    soc.mSendBuffer.mStart = memory + 0xb68;
    soc.mSendBuffer.mSize = 0x5ea;
    CPS_SocRegister(&soc);
    resolvedAddr = CPS_Resolve(hostname);
    CPS_SocUnRegister();
    SOCLiConfigPtr->mFree(memory);
    return resolvedAddr;
}

s32 SOCL_InetAtoH(const char *hostname) {
    u32 interruptState = OS_DisableInterrupts();
    u32 savedFirstDns = CPSDnsIp[0];
    u32 savedSecondDns = CPSDnsIp[1];
    s32 resolvedAddr;
    CPSDnsIp[0] = 0;
    CPSDnsIp[1] = 0;
    resolvedAddr = CPS_Resolve(hostname);
    CPSDnsIp[0] = savedFirstDns;
    CPSDnsIp[1] = savedSecondDns;
    OS_RestoreInterrupts(interruptState);
    return resolvedAddr;
}

s32 SOCL_SetResolver(u32 firstDns, u32 secondDns) {
    if (SOCL_GetHostID() == 0) {
        return 0xffffffd9;
    }
    CPSDnsIp[0] = firstDns;
    CPSDnsIp[1] = secondDns;
    return 0;
}

s32 SOCL_GetHostID(void) {
    if (CPSMyIp == 0) {
        if ((SOCLiDhcpState & 3) == 1) {
            if (OS_GetProcMode() != 0x12) {
                OS_Sleep(10);
            }
        }
    } else if (SOCLiRequestedIP == 0) {
        SOCLiRequestedIP = CPSMyIp;
    }
    return CPSMyIp;
}

s32 SOCL_Cleanup(void) {
    s32 result;
    s32 inProgressCode;
    if (SOCLiRequestedIP == 0) {
        SOCLiRequestedIP = CPSMyIp;
    }
    result = SOCL_CalmDown();
    inProgressCode = -0x1a;
    if (result == inProgressCode) {
        do {
            OS_Sleep(100);
        } while (SOCL_CalmDown() == inProgressCode);
    }
    result = SOCLi_CleanupCommandPacketQueue();
    if (result >= 0) {
        CPS_Cleanup();
        CPS_SetScavengerCallback(NULL);
        if (SOCLiConfigPtr->mLanBuf == NULL) {
            SOCLiConfigPtr->mFree(SOCLiCPSConfig.mLanBuf);
        }
        SOCLiConfigPtr = NULL;
    }
    return result;
}

s32 SOCL_CloseAll(void) {
    SOCLSocket *sockObj;
    SOCLSocket *udpSendSocket;
    u32 interruptState;
    for (;;) {
        interruptState = OS_DisableInterrupts();
        sockObj = SOCLiSocketList;
        if (sockObj != NULL) {
            udpSendSocket = SOCLiUDPSendSocket;
            do {
                if (sockObj != udpSendSocket && (sockObj->mStatusFlags & SOCL_STATUS_WAIT_CLOSE) == 0) {
                    break;
                }
                sockObj = sockObj->mNext;
            } while (sockObj != NULL);
        }
        OS_RestoreInterrupts(interruptState);
        if (sockObj == NULL) {
            break;
        }
        SOCL_Close((s32) sockObj);
    }
    if (SOCLiSocketList == NULL || (SOCLiSocketList == SOCLiUDPSendSocket && SOCLiSocketList->mNext == NULL)) {
        if (SOCLiSocketListTrash == NULL) {
            return 0;
        }
    }
    return -0x1a;
}

s32 SOCL_CalmDown(void) {
    s32 result;
    SOCL_CloseAll();
    if (SOCLiUDPSendSocket != NULL) {
        result = SOCL_CloseAll();
        if (result == 0) {
            SOCL_Close((s32) SOCLiUDPSendSocket);
            if (SOCL_IsClosed(SOCLiUDPSendSocket) != 0) {
                SOCLiUDPSendSocket = NULL;
            }
            result = -0x1a;
        }
        SOCLi_TrashSocket();
    } else {
        if (CPS_CalmDown() != 0) {
            result = 0;
        } else {
            result = -0x1a;
        }
    }
    return result;
}

BOOL SOCL_IsClosed(SOCLSocket *socket) {
    int checkResult;
    if (((0 <= (s32) socket) && (checkResult = SOCL_SocketIsInvalid(socket), checkResult != 0)) &&
        (checkResult = SOCL_SocketIsInTrash(socket), checkResult == 0)) {
        return 1;
    }
    return 0;
}

static inline s32 SOCL_SocketIsTCP(SOCLSocket *socket) {
    BOOL isTcp = TRUE;
    if (socket->mFlagMode != SOCKET_MODE_STREAM && socket->mFlagMode != SOCKET_MODE_STREAM_DIRECT_READ) {
        isTcp = FALSE;
    }
    return isTcp;
}

static inline s32 SOCL_SocketIsCreated(SOCLSocket *socket) {
    BOOL isCreated = FALSE;
    if (socket != NULL) {
        isCreated = (socket->mStatusFlags & SOCL_STATUS_CREATE) != 0;
    }
    return isCreated;
}

s32 SOCL_Close(s32 socketHandle) {
    volatile SOCLSocket *volatileSocket;
    SOCLSocket *sockObj = (SOCLSocket *) socketHandle;
    SOCLiCommandPacket *cmdPacket;
    volatileSocket = sockObj;
    if (socketHandle <= 0) {
        return -0x1c;
    }
    if (SOCL_SocketIsInTrash(sockObj) != FALSE) {
        return -0x1a;
    }
    if (SOCL_SocketIsInvalid(sockObj) != 0) {
        return 0;
    }
    if (SOCL_SocketIsCreated(sockObj) == 0) {
        return -0x27;
    }
    if ((volatileSocket->mStatusFlags & SOCL_STATUS_WAIT_CLOSE) != 0) {
        return -0x1a;
    }
    volatileSocket->mStatusFlags |= (SOCL_STATUS_CLOSING | SOCL_STATUS_WAIT_CLOSE);
    if (SOCL_SocketIsTCP(sockObj) != 0) {
        SOCLi_SendCommandPacket(&sockObj->mSendBlock->mCommandPipe, NULL);
    }
    cmdPacket = SOCLi_CreateCommandPacket(SOCLi_CloseCallBack, sockObj, 1);
    cmdPacket->mFlagBlock = 0;
    return SOCLi_ExecCommandPacketInCtrlPipe(sockObj, cmdPacket);
}

s32 SOCLi_CloseCallBack(SOCLiCommandPacket *command) {
    SOCLSocket *sockObj = command->mSocket;
    void *block;
    u32 interruptState;
    if (SOCL_SocketIsTCP(sockObj) != 0) {
        OS_JoinThread(&sockObj->mSendBlock->mCommandPipe.mThread);
        CPS_TcpShutdown();
        CPS_TcpClose();
        CPS_SocRelease();
    }
    CPS_SocUnRegister();
    sockObj->mStatusFlags &= ~(SOCL_STATUS_CONNECTING | SOCL_STATUS_CONNECTED);
    if (sockObj->mFlagMode == SOCKET_MODE_DATAGRAM_SEND) {
        block = sockObj->mSendBlock;
    } else {
        block = sockObj->mReceiveBlock;
    }
    SOCLi_SendCommandPacket(block, NULL);
    interruptState = OS_DisableInterrupts();
    SOCLi_SocketUnregister(sockObj);
    SOCLi_SocketRegisterTrash(sockObj);
    OS_RestoreInterrupts(interruptState);
    sockObj->mStatusFlags |= SOCL_STATUS_WAIT_RELEASE;
    return 0;
}

void SOCLi_CleanupSocket(SOCLSocket *socket) {
    SOCLiSocketUdpData *datagram;
    SOCLiSocketUdpData *nextDatagram;
    u32 interruptState;
    if (socket != NULL) {
        socket->mStatusFlags = 0;
        if (SOCL_SocketIsTCP(socket) != 0) {
            SOCLi_FreeCommandPipe(&socket->mSendBlock->mCommandPipe);
            SOCLi_FreeCommandPipe(&socket->mReceiveBlock->mCommandPipe);
        } else if (socket->mFlagMode == SOCKET_MODE_DATAGRAM_RECEIVE) {
            datagram = socket->mReceiveBlock->mUdpDataOut;
            while (datagram != NULL) {
                nextDatagram = datagram->mNext;
                SOCLiConfigPtr->mFree(datagram);
                datagram = nextDatagram;
            }
            socket->mReceiveBlock->mUdpDataSize = 0;
            socket->mReceiveBlock->mUdpDataIn = NULL;
            socket->mReceiveBlock->mUdpDataOut = NULL;
            OS_WakeupThread(&socket->mReceiveBlock->mUdpDataWaiting);
            SOCLi_FreeCommandPipe(&socket->mReceiveBlock->mCommandPipe);
        } else if (socket->mFlagMode == SOCKET_MODE_DATAGRAM_SEND) {
            SOCLi_FreeCommandPipe(&socket->mSendBlock->mCommandPipe);
        }
        interruptState = OS_DisableInterrupts();
        SOCLi_SocketUnregister(socket);
        SOCLi_SocketUnregisterTrash(socket);
        SOCLiConfigPtr->mFree(socket);
        OS_RestoreInterrupts(interruptState);
    }
}

void SOCLi_FreeCommandPipe(SOCLiSocketCommandPipe *pipe) {
    SOCLiCommandPacket *cmdPacket;
    u32 interruptState;
    if (pipe != NULL) {
        OS_JoinThread(&pipe->mThread);
        interruptState = OS_DisableInterrupts();
        OS_DisableScheduler();
        if (OS_ReceiveMessage(&pipe->mQueue, (void **) &cmdPacket, 0) != 0) {
            do {
                if (cmdPacket != NULL) {
                    if (cmdPacket->mResponse != NULL) {
                        OS_SendMessage(cmdPacket->mResponse, (void *) -11, 0);
                    }
                    SOCLi_FreeCommandPacket(cmdPacket);
                }
            } while (OS_ReceiveMessage(&pipe->mQueue, (void **) &cmdPacket, 0) != 0);
        }
        OS_EnableScheduler();
        OS_RestoreInterrupts(interruptState);
        OSi_RescheduleThread();
    }
}

void SOCLi_TrashSocket(void) {
    u32 interruptState = OS_DisableInterrupts();
    while (SOCLiSocketListTrash != NULL) {
        SOCLi_CleanupSocket(SOCLiSocketListTrash);
    }
    OS_RestoreInterrupts(interruptState);
}

s32 SOCL_Shutdown(s32 socketHandle) {
    volatile SOCLSocket *volatileSocket;
    SOCLSocket *sockObj = (SOCLSocket *) socketHandle;
    SOCLiSocketSendCommandPipe *outPipe;
    SOCLiCommandPacket *cmdPacket;
    volatileSocket = sockObj;
    if (SOCL_SocketIsInvalid(sockObj) != 0) {
        return -0x1c;
    }
    if (SOCL_SocketIsCreated(sockObj) == 0) {
        return -0x27;
    }
    if ((volatileSocket->mStatusFlags & SOCL_STATUS_CONNECTED) == 0 ||
        (volatileSocket->mStatusFlags & SOCL_STATUS_CLOSING) != 0) {
        return -0x38;
    }
    volatileSocket->mStatusFlags |= SOCL_STATUS_CLOSING;
    outPipe = sockObj->mSendBlock;
    if (outPipe != NULL && outPipe->mExeSocket != NULL) {
        cmdPacket = SOCLi_CreateCommandPacket(SOCLi_ShutdownCallBack, outPipe->mExeSocket, sockObj->mFlagBlock);
        if (cmdPacket == NULL) {
            return -0x21;
        }
        return SOCLi_ExecCommandPacketInSendPipe(outPipe->mExeSocket, cmdPacket);
    }
    return 0;
}

s32 SOCLi_ShutdownCallBack(SOCLiCommandPacket *command) {
    if (SOCL_SocketIsTCP(command->mSocket) != 0) {
        CPS_TcpShutdown();
    }
    return 0;
}

s32 SOCL_WriteTo(u32 socketHandle, void *buffer, u32 length, u16 remotePort, u32 peerAddr, u32 flags) {
    volatile SOCLSocket *volatileSocket;
    SOCLSocket *sockObj = (SOCLSocket *) socketHandle;
    SOCLiSocketSendCommandPipe *outPipe;
    BOOL isBlocking;
    s32 result;
    volatileSocket = sockObj;
    if (SOCL_SocketIsInvalid(sockObj) != 0) {
        return -0x1c;
    }
    if (SOCL_SocketIsCreated(sockObj) == 0) {
        return -0x27;
    }
    if (SOCL_SocketIsTCP(sockObj) != 0) {
        if ((volatileSocket->mStatusFlags & SOCL_STATUS_CONNECTED) == 0 ||
            (volatileSocket->mStatusFlags & SOCL_STATUS_CLOSING) != 0) {
            return -0x38;
        }
    }
    outPipe = sockObj->mSendBlock;
    if ((flags & 4) != 0 || sockObj->mFlagBlock == 0) {
        if (OS_TryLockMutex(&outPipe->mCommandPipe.mInUse) == 0) {
            return -6;
        }
        isBlocking = FALSE;
    } else {
        OS_LockMutex(&outPipe->mCommandPipe.mInUse);
        isBlocking = TRUE;
    }
    result = SOCLi_WriteBuffer(sockObj, buffer, length, remotePort, peerAddr, isBlocking);
    OS_UnlockMutex(&outPipe->mCommandPipe.mInUse);
    return result;
}

s32 SOCLi_WriteBuffer(SOCLSocket *socket, u8 *buffer, s32 length, u16 remotePort, u32 peerAddr, s32 isBlocking) {
    s32 chunkLimit;
    s32 copiedLength;
    s32 writeLength;
    u32 ringIn;
    copiedLength = 0;
    chunkLimit = socket->mSendBlock->mExeSocket->mCps.mSendBuffer.mSize;
    if (socket->mFlagMode == SOCKET_MODE_DATAGRAM_RECEIVE) {
        chunkLimit -= 0x2a;
        if (length > chunkLimit) {
            return -0x23;
        }
        chunkLimit = length;
    } else {
        chunkLimit -= 0x36;
        if (length <= chunkLimit) {
            chunkLimit = length;
        }
    }
    while (length > 0) {
        writeLength = SOCLi_AllocWriteBuffer(socket, length, chunkLimit, &ringIn, isBlocking);
        if (writeLength > 0) {
            if (SOCLi_ExecWriteCommand(socket, buffer, writeLength, ringIn, remotePort, peerAddr, isBlocking) <= 0) {
                return -6;
            }
            buffer += writeLength;
            length -= writeLength;
            copiedLength += writeLength;
        }
        if (isBlocking == 0) {
            if (writeLength > 0) {
                break;
            }
            return -6;
        }
    }
    return copiedLength;
}

s32 SOCLi_AllocWriteBuffer(SOCLSocket *socket, s32 maxSize, s32 lowestSize, u32 *ringInPtr, s32 isBlocking) {
    SOCLiSocketSendCommandPipe *outPipe = socket->mSendBlock;
    s32 freeSize;
    u32 interruptState;
    if (lowestSize > maxSize) {
        lowestSize = maxSize;
    }
    interruptState = OS_DisableInterrupts();
    for (;;) {
        freeSize = SOCLi_GetWriteBufferFreeSize(socket);
        if (freeSize >= lowestSize) {
            if (freeSize >= maxSize) {
                freeSize = maxSize;
            }
            *ringInPtr = outPipe->mBufferIn;
            break;
        }
        if (isBlocking == 0) {
            freeSize = 0;
            break;
        }
        OS_SleepThread((OSThreadQueue *) &outPipe->mBufferWaitingHead);
    }
    OS_RestoreInterrupts(interruptState);
    return freeSize;
}

s32 SOCLi_GetWriteBufferFreeSize(SOCLSocket *socket) {
    SOCLiSocketSendCommandPipe *outPipe = socket->mSendBlock;
    s32 ringSize = outPipe->mBufferArea.mSize;
    s32 freeSize = outPipe->mBufferIn;
    freeSize = outPipe->mBufferOut - freeSize - 1;
    if (freeSize < 0) {
        freeSize += ringSize;
    }
    return freeSize;
}

s32 SOCLi_ExecWriteCommand(SOCLSocket *socket, u8 *buffer, s32 length, s32 ringIn, u16 remotePort, u32 remoteIp,
                           s32 isBlocking) {
    SOCLiSocketSendCommandPipe *outPipe = socket->mSendBlock;
    SOCLiCommandWrite *writePacket;
    s32 zero;
    u8 *ringStart;
    s32 ringSize;
    s32 ringEnd;
    writePacket = (SOCLiCommandWrite *) SOCLi_CreateCommandPacket(SOCLi_WriteCallBack, outPipe->mExeSocket, isBlocking);
    if (writePacket == NULL) {
        return -0x21;
    }
    writePacket->mFlagBlock = 0;
    zero = 0;
    ringStart = outPipe->mBufferArea.mStart;
    ringSize = outPipe->mBufferArea.mSize;
    ringEnd = ringIn + length;
    if (ringEnd < ringSize) {
        writePacket->mBuffer1 = ringStart + ringIn;
        writePacket->mBuffer1Len = length;
        writePacket->mBuffer2 = (u8 *) zero;
        writePacket->mBuffer2Len = zero;
        ringIn = ringEnd;
    } else {
        writePacket->mBuffer1 = ringStart + ringIn;
        writePacket->mBuffer1Len = ringSize - ringIn;
        writePacket->mBuffer2 = ringStart;
        writePacket->mBuffer2Len = length - writePacket->mBuffer1Len;
        ringIn = writePacket->mBuffer2Len;
        MI_CpuCopy8(buffer + writePacket->mBuffer1Len, writePacket->mBuffer2, ringIn);
    }
    MI_CpuCopy8(buffer, writePacket->mBuffer1, writePacket->mBuffer1Len);
    writePacket->mWriteBufferAfter = ringIn;
    outPipe->mBufferIn = writePacket->mWriteBufferAfter;
    if (socket->mFlagMode == SOCKET_MODE_DATAGRAM_RECEIVE) {
        if (socket->mLocalPort == 0) {
            socket->mLocalPort = CPS_SocGetEport();
            socket->mCps.mLocalPort = socket->mLocalPort;
        }
        writePacket->mLocalPort = socket->mLocalPort;
        if (socket->mRemoteIp == 0 || remoteIp != 0) {
            writePacket->mRemoteIp = remoteIp;
            writePacket->mRemotePort = remotePort;
        } else {
            writePacket->mRemoteIp = socket->mRemoteIp;
            writePacket->mRemotePort = socket->mRemotePort;
        }
    } else {
        writePacket->mRemoteIp = 0;
    }
    if (SOCLi_ExecCommandPacketInSendPipe(outPipe->mExeSocket, writePacket) != 0) {
        length = 0;
    }
    return length;
}

s32 SOCLi_WriteCallBack(SOCLiCommandPacket *packet) {
    SOCLiCommandWrite *command = (SOCLiCommandWrite *) packet;
    SOCLSocket *sockObj = command->mSocket;
    SOCLiSocketSendCommandPipe *outPipe = sockObj->mSendBlock;
    s32 headerSize;
    u8 *sendBuffer;
    s32 written = 0;
    s32 sendCapacity;
    s32 chunkLength;
    if (SOCL_SocketIsTCP(sockObj) == 0 || (sockObj->mStatusFlags & SOCL_STATUS_CONNECTED) != 0) {
        if (command->mRemoteIp != 0) {
            CPS_SocBind(command->mLocalPort, command->mRemotePort, command->mRemoteIp);
        }
        if (SOCL_SocketIsTCP(sockObj) != 0) {
            headerSize = 0x36;
        } else {
            headerSize = 0x2a;
        }
        sendBuffer = sockObj->mCps.mSendBuffer.mStart + headerSize;
        sendCapacity = sockObj->mCps.mSendBuffer.mSize - headerSize;
        for (;;) {
            chunkLength = SOCLi_MemCpy(sendBuffer, sendCapacity, command);
            if (chunkLength <= 0) {
                break;
            }
            chunkLength = CPS_SocWrite(sendBuffer, chunkLength);
            if (chunkLength <= 0) {
                if (SOCL_SocketIsTCP(sockObj) != 0) {
                    sockObj->mStatusFlags &= ~(SOCL_STATUS_CONNECTING | SOCL_STATUS_CONNECTED | SOCL_STATUS_CLOSING);
                }
                written = -0x4c;
                break;
            }
            written += chunkLength;
        }
    } else {
        written = -0x4c;
    }
    outPipe->mBufferOut = command->mWriteBufferAfter;
    OS_WakeupThread((OSThreadQueue *) &outPipe->mBufferWaitingHead);
    return written;
}

s32 SOCLi_MemCpy(const void *destination, s32 capacity, SOCLiCommandWrite *command) {
    s32 firstLength = command->mBuffer1Len;
    s32 secondLength = command->mBuffer2Len;
    if (firstLength > capacity) {
        firstLength = capacity;
        secondLength = 0;
    } else if (secondLength > capacity - firstLength) {
        secondLength = capacity - firstLength;
    }
    if (firstLength > 0) {
        MI_CpuCopy8(command->mBuffer1, destination, firstLength);
        command->mBuffer1 += firstLength;
        command->mBuffer1Len -= firstLength;
    }
    if (secondLength > 0) {
        MI_CpuCopy8(command->mBuffer2, (u8 *) destination + firstLength, secondLength);
        command->mBuffer2 += secondLength;
        command->mBuffer2Len -= secondLength;
    }
    return firstLength + secondLength;
}

s32 SOCL_ReadFrom(u32 socketHandle, void *buffer, u32 length, u16 *remotePort, u32 *peerAddr, u32 flags) {
    volatile SOCLSocket *volatileSocket;
    SOCLSocket *sockObj = (SOCLSocket *) socketHandle;
    SOCLiSocketRecvCommandPipe *inPipe;
    s32 value;
    volatileSocket = sockObj;
    if (SOCL_SocketIsInvalid(sockObj) != 0) {
        return -0x1c;
    }
    if ((flags & 4) != 0 || sockObj->mFlagBlock == 0) {
        if (sockObj->mFlagMode == SOCKET_MODE_STREAM_DIRECT_READ) {
            return -0x1c;
        }
        value = 0;
    } else {
        if (OS_GetProcMode() == 0x12) {
            return -0x1c;
        }
        value = 1;
    }
    if (SOCL_SocketIsCreated(sockObj) == 0) {
        return -0x27;
    }
    if (SOCL_SocketIsTCP(sockObj) != 0) {
        if ((volatileSocket->mStatusFlags & SOCL_STATUS_CONNECTED) == 0 ||
            (volatileSocket->mStatusFlags & SOCL_STATUS_CLOSING) != 0) {
            return -0x38;
        }
    }
    inPipe = sockObj->mReceiveBlock;
    if (value == 0) {
        if (OS_TryLockMutex(&inPipe->mCommandPipe.mInUse) == 0) {
            return -6;
        }
    } else {
        OS_LockMutex(&inPipe->mCommandPipe.mInUse);
    }
    value = SOCLi_ReadAndConsumeBuffer(sockObj, buffer, length, remotePort, peerAddr, value, flags);
    OS_UnlockMutex(&inPipe->mCommandPipe.mInUse);
    return value;
}

s32 SOCLi_ReadAndConsumeBuffer(SOCLSocket *socket, void *buffer, s32 length, u16 *remotePort, u32 *remoteIp,
                               s32 isBlocking, s32 flags) {
    SOCLiSocketRecvCommandPipe *inPipe = socket->mReceiveBlock;
    s32 savedNoConsume;
    s32 result;
    BOOL isPeek;
    if ((flags & 2) != 0 && inPipe != NULL) {
        isPeek = TRUE;
    } else {
        isPeek = FALSE;
    }
    if (isPeek != FALSE) {
        savedNoConsume = inPipe->mNoConsume;
        inPipe->mNoConsume = 1;
    }
    if (socket->mFlagMode == SOCKET_MODE_DATAGRAM_RECEIVE) {
        result = SOCLi_ReadUdpBuffer(socket, buffer, length, remotePort, remoteIp, isBlocking);
    } else {
        result = SOCLi_ReadBuffer(socket, buffer, length, remotePort, remoteIp, isBlocking);
        if (result >= 0) {
            SOCLi_ConsumeBuffer(socket);
        }
    }
    if (isPeek != FALSE) {
        inPipe->mNoConsume = savedNoConsume;
    }
    return result;
}

s32 SOCLi_ReadBuffer(SOCLSocket *socket, void *buffer, s32 length, u16 *remotePort, u32 *peerAddr, s32 isBlocking) {
    s32 result;
    if (socket->mFlagMode == SOCKET_MODE_STREAM_DIRECT_READ) {
        return SOCLi_ExecReadCommand(socket, buffer, length, remotePort, peerAddr);
    }
    result = SOCLi_CopyCPSBuffer(socket, buffer, length, remotePort, peerAddr);
    if (result == -6 && isBlocking == 1) {
        result = SOCLi_ExecReadCommand(socket, buffer, length, remotePort, peerAddr);
    }
    return result;
}

s32 SOCLi_CopyCPSBuffer(SOCLSocket *socket, void *buffer, s32 length, u16 *remotePort, u32 *peerAddr) {
    u32 interruptState = OS_DisableInterrupts();
    u16 ports[2];
    s32 available;
    u32 remoteAddress;
    u8 *source;
    s32 result;
    source = SOCLi_ReadCPSBuffer(socket, &available, &ports[0], &ports[1], &remoteAddress);
    if (source != NULL) {
        result = available;
        if (result == 0) {
            result = -6;
        } else {
            if (length > result) {
                length = result;
            }
            if (SOCL_SocketIsTCP(socket) != 0) {
                result = length;
            }
            MI_CpuCopy8(source, buffer, length);
            if (socket->mReceiveBlock->mNoConsume == 0) {
                socket->mReceiveBlock->mConsumed = socket->mReceiveBlock->mConsumed + result;
            }
        }
    } else {
        if (available == 0) {
            result = 0;
        } else {
            result = -0x1c;
        }
        socket->mStatusFlags &= ~(SOCL_STATUS_CONNECTING | SOCL_STATUS_CONNECTED);
    }
    if (result >= 0) {
        if (remotePort != NULL && peerAddr != NULL) {
            *remotePort = ports[1];
            *peerAddr = remoteAddress;
        }
        if (socket->mLocalPort == 0) {
            socket->mLocalPort = ports[0];
        }
    }
    OS_RestoreInterrupts(interruptState);
    return result;
}

u8 *SOCLi_ReadCPSBuffer(SOCLSocket *socket, s32 *lengthOut, u16 *localPortOut, u16 *remotePortOut, u32 *remoteIpOut) {
    SOCLiSocketRecvCommandPipe *inPipe = socket->mReceiveBlock;
    SOCLSocket *cpsSocket = inPipe->mCommandPipe.mThread.mSpecific[0];
    s32 used = inPipe->mConsumed;
    s32 available = cpsSocket->mCps.mReceiveBufferLength - used;
    if (available >= 0) {
        *localPortOut = cpsSocket->mCps.mLocalPort;
        *remotePortOut = cpsSocket->mCps.mRemotePort;
        *remoteIpOut = cpsSocket->mCps.mRemoteIp;
        *lengthOut = available;
        if (available == 0 && cpsSocket->mCps.mState != SOCKET_STATE_ESTABLISHED) {
            return NULL;
        }
    } else {
        *lengthOut = -1;
        return NULL;
    }
    return cpsSocket->mCps.mReceiveBuffer.mStart + used;
}

s32 SOCLi_ExecReadCommand(SOCLSocket *socket, u8 *buffer, s32 length, u16 *remotePort, u32 *peerAddr) {
    SOCLiCommandRead *readPacket = (SOCLiCommandRead *) SOCLi_CreateCommandPacket(SOCLi_ReadCallBack, socket, 1);
    readPacket->mBuffer = buffer;
    readPacket->mBufferLen = length;
    readPacket->mRemotePort = remotePort;
    readPacket->mRemoteIp = peerAddr;
    return SOCLi_ExecCommandPacketInRecvPipe(socket, (SOCLiCommandPacket *) readPacket);
}

s32 SOCLi_ReadCallBack(SOCLiCommandPacket *packet) {
    SOCLiCommandRead *command = (SOCLiCommandRead *) packet;
    SOCLSocket *sockObj = command->mSocket;
    SOCLiSocketRecvCommandPipe *inPipe = sockObj->mReceiveBlock;
    u8 *buffer = command->mBuffer;
    u32 length = command->mBufferLen;
    u16 *remotePort = command->mRemotePort;
    u32 *peerAddr = command->mRemoteIp;
    s32 copied = inPipe->mConsumed;
    const u8 *gotData;
    s32 cpsLength;
    BOOL isTcp;
    for (;;) {
        gotData = CPS_SocRead((u32 *) &cpsLength);
        if (gotData == NULL) {
            break;
        }
        if (cpsLength - copied > 0) {
            break;
        }
        isTcp = TRUE;
        if (sockObj->mFlagMode != SOCKET_MODE_STREAM && sockObj->mFlagMode != SOCKET_MODE_STREAM_DIRECT_READ) {
            isTcp = FALSE;
        }
        if (isTcp != FALSE && sockObj->mCps.mState != SOCKET_STATE_ESTABLISHED) {
            gotData = NULL;
            break;
        }
        OS_Sleep(10);
    }
    if (sockObj->mFlagMode == SOCKET_MODE_STREAM_DIRECT_READ) {
        if (gotData == NULL) {
            return 0;
        }
        if (length > cpsLength) {
            length = cpsLength;
        }
        MI_CpuCopy8(gotData, buffer, length);
        CPS_SocConsume(length);
        return length;
    }
    if (gotData != NULL) {
        copied = SOCLi_CopyCPSBuffer(sockObj, buffer, length, remotePort, peerAddr);
    } else {
        copied = 0;
    }
    if (copied <= 0) {
        return copied;
    }
    if (inPipe->mConsumed >= inPipe->mConsumedMin) {
        SOCLi_ConsumeCPSBuffer(sockObj);
    }
    return copied;
}

static inline s32 ReadUdpSOCL_SocketIsCreated(SOCLSocket *socket) {
    BOOL isCreated = FALSE;
    if (socket != NULL) {
        isCreated = (socket->mStatusFlags & SOCL_STATUS_CREATE) != 0;
    }
    return isCreated;
}

s32 SOCLi_ConsumeBuffer(SOCLSocket *socket) {
    SOCLiSocketRecvCommandPipe *inPipe = socket->mReceiveBlock;
    SOCLiCommandPacket *cmdPacket;
    if (inPipe->mConsumed < inPipe->mConsumedMin) {
        return 0;
    }
    cmdPacket = SOCLi_CreateCommandPacket(SOCLi_ConsumeCallBack, socket, 0);
    if (cmdPacket == NULL) {
        return -0x21;
    }
    return SOCLi_ExecCommandPacketInRecvPipe(socket, cmdPacket);
}

s32 SOCLi_ConsumeCallBack(SOCLiCommandPacket *command) {
    return SOCLi_ConsumeCPSBuffer(command->mSocket);
}

s32 SOCLi_ConsumeCPSBuffer(SOCLSocket *socket) {
    SOCLiSocketRecvCommandPipe *inPipe = socket->mReceiveBlock;
    u32 interruptState = OS_DisableInterrupts();
    s32 used = inPipe->mConsumed;
    if (used != 0) {
        inPipe->mConsumed = 0;
        CPS_SocConsume(used);
    }
    OS_RestoreInterrupts(interruptState);
    return used;
}

s32 SOCLi_ReadUdpBuffer(SOCLSocket *socket, void *buffer, s32 length, u16 *remotePort, u32 *peerAddr, s32 isBlocking) {
    SOCLiSocketRecvCommandPipe *inPipe = socket->mReceiveBlock;
    u32 interruptState;
    s32 result;
    SOCLiSocketUdpData *datagram;
    *(SOCLiSocketUdpData *volatile *) &inPipe->mUdpDataOut;
    interruptState = OS_DisableInterrupts();
    datagram = inPipe->mUdpDataOut;
    while (datagram == NULL) {
        if (isBlocking == 0) {
            result = -6;
            break;
        }
        OS_SleepThread(&inPipe->mUdpDataWaiting);
        if (SOCL_SocketIsInvalid(socket) != 0 || ReadUdpSOCL_SocketIsCreated(socket) == 0) {
            result = -0x38;
            break;
        }
        datagram = inPipe->mUdpDataOut;
    }
    if (datagram != NULL) {
        if (length > datagram->mSize) {
            length = datagram->mSize;
        }
        MI_CpuCopy8(datagram->mData, buffer, length);
        if (remotePort != NULL) {
            *remotePort = datagram->mRemotePort;
        }
        if (peerAddr != NULL) {
            *peerAddr = datagram->mRemoteIp;
        }
        result = datagram->mSize;
        if (inPipe->mNoConsume == 0) {
            inPipe->mUdpDataOut = datagram->mNext;
            if (datagram->mNext == NULL) {
                inPipe->mUdpDataIn = NULL;
            }
            SOCLiConfigPtr->mFree(datagram);
            inPipe->mUdpDataSize -= result;
        }
    }
    OS_RestoreInterrupts(interruptState);
    return result;
}

s32 SOCLi_UdpRecvCallback(void *data, u32 length, SOCLSocket *socket) {
    SOCLiSocketRecvCommandPipe *inPipe = socket->mReceiveBlock;
    u32 interruptState = OS_DisableInterrupts();
    if (inPipe->mUdpDataSizeMax >= inPipe->mUdpDataSize + length) {
        SOCLiSocketUdpData *datagram = SOCLiConfigPtr->mAlloc(length + 0xc);
        if (datagram != NULL) {
            inPipe->mUdpDataSize += length;
            datagram->mNext = NULL;
            datagram->mSize = length;
            datagram->mRemotePort = socket->mCps.mRemotePort;
            datagram->mRemoteIp = socket->mCps.mRemoteIp;
            MI_CpuCopy8(data, datagram->mData, length);
            if (socket->mLocalPort == 0) {
                socket->mLocalPort = socket->mCps.mLocalPort;
            }
            socket->mCps.mRemotePort = socket->mCps.mRemotePortBound;
            socket->mCps.mRemoteIp = socket->mCps.mRemoteIpBound;
            if (((const SOCLiSocketRecvCommandPipe *) inPipe)->mUdpDataIn != NULL) {
                inPipe->mUdpDataIn->mNext = datagram;
            }
            inPipe->mUdpDataIn = datagram;
            if (inPipe->mUdpDataOut == NULL) {
                inPipe->mUdpDataOut = datagram;
            }
        } else {
            SOCLi_CheckCount[0]++;
        }
    } else {
        SOCLi_CheckCount[1]++;
    }
    OS_WakeupThread(&inPipe->mUdpDataWaiting);
    OS_RestoreInterrupts(interruptState);
    return 1;
}
