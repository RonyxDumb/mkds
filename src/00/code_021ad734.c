#include "00/code_021ad734.h"

#include "code_0214d018.h"
#include "00/code_021a9228.h"
#include "00/unk_021b6000.h"
#include "00/code_021a91b4.h"
#include "00/code_021ad018.h"
#include "00/code_021ad3b8.h"
#include "00/code_021ad36c.h"
#include "00/unk_021b6380.h"
#include "os_thread.h"
#include "os_tick.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0200fc8c.h"
#include "string.h"
#include "code_02134398.h"
#include "code_02133048.h"
#include "00/code_021a669c.h"
#include "00/code_021a6934.h"
#include "00/code_021a8878.h"
#include "03/code_021b94b8.h"
#include "02/unk_02180500.h"
#include "code_02000b44.h"

void reset_network_vars(u32 reason) {
    u32 addressSeen;
    OSThread *thread;
    CPSSoc *socket;
    s32 i;
    CPSFragTable *fragment;

    if (CPSMyIp != 0) {
        addressSeen = 1;
    } else {
        addressSeen = 0;
    }
    CPSNoIpReason = reason;
    CPSMyIp = 0;
    CPSNetMask = 0;
    CPSGatewayIp = 0;
    CPSDnsIp[0] = 0;
    CPSDnsIp[1] = 0;
    CPSDhcpServerIp = 0;
    if (addressSeen != 0) {
        MI_CpuFill8(gArpCache, 0, 0x60);
        thread = OSi_ThreadInfo.mListHead;
        if (thread != NULL) {
            do {
                socket = thread->mSpecific[0];
                if (socket != NULL && socket->mThread != NULL) {
                    if (socket->mState != 10 && socket->mState != 11) {
                        socket->mState = 0;
                    }
                    if (socket->mBlockType != 0) {
                        socket->mBlockType = 0;
                        OS_WakeupThreadDirect(socket->mThread);
                    }
                }
                thread = thread->mNext;
            } while (thread != NULL);
        }
        i = 0;
        fragment = gFragTable;
        for (; i < 8; i++) {
            if (fragment->mFrags != 0) {
                CPSiFree(fragment->mBuf);
                fragment->mFrags = 0;
            }
            fragment++;
        }
        CPSi_SslCleanup();
    }
}

void yield_thread(void) {
    if (gYieldWait == 0) {
        OS_YieldThread();
    } else {
        OS_Sleep(gYieldWait);
    }
}

void empty_func(void) {}

BOOL default_link_is_on(void) {
    return 1;
}

void CPS_Startup(CPSConfig *config) {
    OSi_ReferSymbol(0x2000bfc);
    if (*(u64 *) &config->mRandomSeedLow != 0) {
        CPSiRand32ctx[0] = *(u64 *) &config->mRandomSeedLow;
        CPSiRand32ctx[1] = 0x5d588b656c078965ULL;
        CPSiRand32ctx[2] = 0x269ec3;
    } else {
        CPSiRand32ctx[0] = OS_GetTick();
        CPSiRand32ctx[1] = 0x5d588b656c078965ULL;
        CPSiRand32ctx[2] = 0x269ec3;
    }
    if (config->mAlloc != NULL && config->mFree != NULL) {
        CPSiAlloc = (u8 * (*) (u32)) config->mAlloc;
        CPSiFree = config->mFree;
    } else {
        CPSiAlloc = (u8 * (*) (u32)) empty_func;
        CPSiFree = (void (*)(void *)) empty_func;
    }
    gCPSMode = config->mMode;
    if (config->mMyMss != 0) {
        gMyMss = config->mMyMss;
    } else {
        gMyMss = 0x5b4;
    }
    gOfferedMyIp = config->mRequestedIp;
    gYieldWait = config->mYieldWait;
    if (config->mDhcpCallback != NULL) {
        gDhcpCallback = config->mDhcpCallback;
    } else {
        gDhcpCallback = empty_func;
    }
    if (config->mLinkIsOn != NULL) {
        gLinkIsOn = config->mLinkIsOn;
    } else {
        gLinkIsOn = (u32(*)(void)) default_link_is_on;
    }
    gWlanBuf = config->mLanBuf;
    gWlanBufLen = config->mLanBufLen;
    gWlanGetPnt = 0;
    gWlanPutPnt = 0;
    CPSiRand32ctx[0] = _ll_mul(CPSiRand32ctx[1], CPSiRand32ctx[0]) + CPSiRand32ctx[2];
    gEport = (_ll_mul(CPSiRand32ctx[0] >> 32, 0xf88) >> 32) + 0x400;
    OS_GetMacAddress(CPSMyMac);
    gIpConflict = 0;
    OS_CreateThread(&gTcpipThread, (void (*)(void *)) tcpip, NULL, gTcpipStackTop, 0x800, gHelperThreadsPriority);
    OS_CreateThread(&gScavengerThread, (void (*)(void *)) scavenger, NULL, gScavengerStackTop, 0x800,
                    gHelperThreadsPriority);
    OS_WakeupThreadDirect(&gTcpipThread);
    OS_WakeupThreadDirect(&gScavengerThread);
}

s32 CPS_CalmDown(void) {
    u32 interruptState;
    s32 isTerminated;

    interruptState = OS_DisableInterrupts();
    isTerminated = OS_IsThreadTerminated(&gScavengerThread);
    if (isTerminated == 0 && gScavengerForceExit == 0) {
        gScavengerForceExit = 1;
        OS_WakeupThreadDirect(&gScavengerThread);
    }
    OS_RestoreInterrupts(interruptState);
    return isTerminated;
}

void CPS_SetScavengerCallback(UnkFunc *callback) {
    u32 callbackAddress = (u32) callback;
    u32 slotAddress;
    slotAddress = (u32) &gScavengerCallback;
    *(u32 *) ((slotAddress) + 0u) = callbackAddress;
}

void CPS_Cleanup(void) {
    CPS_CalmDown();
    OS_JoinThread(&gScavengerThread);
    OS_DestroyThread(&gTcpipThread);
    gReceiverThread = NULL;
    reset_network_vars(0);
    gWlanBuf = NULL;
    gWlanBufLen = 0;
}

void CPS_SetThreadPriority(s32 priority) {
    gHelperThreadsPriority = priority;
    OS_SetThreadPriority(&gTcpipThread, priority);
    OS_SetThreadPriority(&gScavengerThread, priority);
}

u32 calc_checksum_do(const void *buffer, u32 length, u32 sum) {
    const u8 *bytes = buffer;

    if ((u32) bytes & 1) {
        while (length > 1) {
            sum += (u16) ((bytes[0] << 8) | bytes[1]);
            bytes += 2;
            length -= 2;
        }
    } else {
        u16 word = sum;

        sum = (u16) ((word >> 8) | (word << 8));
        while (length > 1) {
            sum += *(const u16 *) bytes;
            bytes += 2;
            length -= 2;
        }
        sum = ((sum >> 8) & 0x00ff00ff) | ((sum << 8) & 0xff00ff00);
        sum = (sum >> 16) | (sum << 16);
    }
    if (length != 0) {
        sum += *bytes << 8;
    }
    sum = (sum & 0xffff) + (sum >> 16);
    sum += sum >> 16;
    return (u16) sum;
}

u16 invert_checksum(u16 sum) {
    sum ^= 0xffff;
    if (sum == 0) {
        sum = 0xffff;
    }
    return sum;
}

u16 calc_checksum(const void *buffer, u32 length) {
    return invert_checksum(calc_checksum_do(buffer, length, 0));
}

BOOL check_tcpudpsum(const void *buffer, u32 length, const IpHeader *header, u32 sum) {
    sum = calc_checksum_do(buffer, length, sum);
    sum = calc_checksum_do(&header->mSourceAddressHigh, 8, sum);
    sum += length;
    if (sum & 0x10000) {
        sum = (sum + 1) & 0xffff;
    }
    if (sum != 0xffff) {
        return TRUE;
    }
    return FALSE;
}

BOOL ip_islocal(u32 address) {
    return address == 0xffffffff || address == 0x7f000001 || (address & CPSNetMask) == (CPSMyIp & CPSNetMask);
}

u32 get_targetip(u32 address) {
    if (ip_islocal(address) == FALSE) {
        address = CPSGatewayIp;
    }
    return address;
}

BOOL is_broadcast(u32 address) {
    BOOL result = FALSE;

    if (ip_islocal(address) != FALSE && (address & ~CPSNetMask) == ~CPSNetMask) {
        result = TRUE;
    }
    return result;
}

BOOL is_multicast(u32 address) {
    if ((address & 0xf0000000) == 0xe0000000) {
        return TRUE;
    }
    return FALSE;
}

BOOL ip_isme(u32 address) {
    return CPSMyIp == 0 || address == CPSMyIp || address == 0x7f000001 || is_broadcast(address) != 0 ||
           is_multicast(address) != FALSE;
}

BOOL maccmp(const u16 *first, const u16 *second) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if (*first++ != *second++) {
            return TRUE;
        }
    }
    return FALSE;
}

void send_packet(u8 *header, u32 headerLength, const void *body, u32 bodyLength) {
    u8 failed;

    if (header + headerLength != body) {
        MI_CpuCopy8(body, header + headerLength, bodyLength);
    }
    MI_CpuCopy8(gIpv4LlcSnapHeader, header + 6, 6);
    if (WCM_SendDCFData(header, header + 6, headerLength + bodyLength - 6) < 0) {
        failed = 1;
    } else {
        failed = 0;
    }
    gSendFailed = failed;
}

void put_in_buffer(const void *sourceAddress, const void *destAddress, u8 *firstBuffer, u32 firstSize,
                   void *secondBuffer, u32 secondSize) {
    u8 *ringBuffer;
    u32 ringSize;
    u32 i;
    u16 blockLength;
    u32 putPos;
    u32 endPos;
    u32 newPutPos;

    ringBuffer = gWlanBuf;
    if (ringBuffer == NULL) {
        return;
    }
    ringSize = gWlanBufLen;
    if (ringSize == 0) {
        return;
    }
    i = firstSize + secondSize;
    if (i < 8 || i > 0x5e4) {
        return;
    }
    if (firstBuffer[0] != gIpv4LlcSnapHeader[0] || firstBuffer[1] != gIpv4LlcSnapHeader[1] ||
        firstBuffer[2] != gIpv4LlcSnapHeader[2]) {
        return;
    }
    if (firstBuffer[6] != 8) {
        return;
    }
    if (firstBuffer[7] != 0 && firstBuffer[7] != 6) {
        return;
    }
    blockLength = (i + 9) & ~1;
    putPos = gWlanPutPnt;
    endPos = putPos + blockLength;
    newPutPos = endPos;
    i = gWlanGetPnt;
    if (putPos < i && i <= endPos) {
        return;
    }
    if (endPos == ringSize) {
        newPutPos = 0;
        if (i == 0) {
            return;
        }
    } else if (endPos > ringSize) {
        newPutPos = blockLength;
        if (i <= blockLength) {
            return;
        }
    }
    if (endPos > ringSize) {
        if (ringSize - putPos >= 2) {
            ringBuffer[putPos] = 0;
            (gWlanBuf + gWlanPutPnt)[1] = 0;
        }
        gWlanPutPnt = 0;
    }
    gWlanBuf[gWlanPutPnt] = blockLength;
    (gWlanBuf + gWlanPutPnt)[1] = blockLength >> 8;
    MI_CpuCopy8(destAddress, gWlanBuf + gWlanPutPnt + 2, 6);
    MI_CpuCopy8(sourceAddress, gWlanBuf + gWlanPutPnt + 8, 6);
    MI_CpuCopy8(firstBuffer + 6, gWlanBuf + gWlanPutPnt + 0xe, firstSize - 6);
    if (secondBuffer != NULL && secondSize != 0) {
        MI_CpuCopy8(secondBuffer, gWlanBuf + gWlanPutPnt + 8 + firstSize, secondSize);
    }
    gWlanPutPnt = newPutPos;
}

void CPSi_RecvCallbackFunc(void *sourceAddress, void *destAddress, void *buffer, u16 size) {
    put_in_buffer(sourceAddress, destAddress, buffer, size, NULL, 0);
    if (gReceiverThread != NULL) {
        OS_WakeupThreadDirect(gReceiverThread);
    }
}

u8 *receive_packet(u32 *length) {
    u16 blockLength;
    u32 ringSize;
    u8 *ringBuffer;

    while (gWlanGetPnt == gWlanPutPnt) {
        gReceiverThread = OSi_ThreadInfo.mCurrentThread;
        OS_SleepThread(NULL);
        gReceiverThread = NULL;
    }
    ringSize = gWlanBufLen;
    ringBuffer = gWlanBuf;
    do {
        if (ringSize - gWlanGetPnt < 2) {
            gWlanGetPnt = 0;
        }
        blockLength = ringBuffer[gWlanGetPnt] + ((ringBuffer + gWlanGetPnt)[1] << 8);
        if (blockLength == 0) {
            gWlanGetPnt = 0;
        }
    } while (blockLength == 0);
    *length = blockLength - 2;
    return gWlanBuf + gWlanGetPnt + 2;
}

void throw_packet(void) {
    u32 interruptState;
    u32 getPos;
    u8 *ringBuffer;

    interruptState = OS_DisableInterrupts();
    getPos = gWlanGetPnt;
    ringBuffer = gWlanBuf;
    gWlanGetPnt = getPos + (ringBuffer[getPos] + ((ringBuffer + getPos)[1] << 8));
    if (gWlanGetPnt >= gWlanBufLen) {
        gWlanGetPnt = 0;
    }
    OS_RestoreInterrupts(interruptState);
}

u8 *inq_arpcache(u32 address) {
    u32 interruptState;
    u8 *mac;
    u32 index;
    u16 tick;

    interruptState = OS_DisableInterrupts();
    mac = NULL;
    if (address == 0x7f000001 || address == CPSMyIp) {
        mac = (u8 *) CPSMyMac;
    } else if (is_broadcast(address) != 0 || is_multicast(address) != FALSE) {
        mac = gMacBroadcast;
    } else {
        for (index = 0; index < 8; index++) {
            if (address == gArpCache[index].mIp) {
                tick = OS_GetTick() >> 16;
                gArpCache[index].mWhen = tick;
                mac = gArpCache[index].mMac;
                break;
            }
        }
    }
    OS_RestoreInterrupts(interruptState);
    return mac;
}

void send_arprequest(u32 address) {
    ArpRequestFrame frame;

    MI_CpuFill8(&frame, 0, 0x2a);
    MI_CpuFill8(&frame, 0xff, 6);
    MI_CpuCopy8(CPSMyMac, frame.mSourceMac, 6);
    frame.mEtherType = 0x608;
    frame.mHardwareTypeLow = 1;
    frame.mProtocolTypeHigh = 8;
    frame.mAddressLengths = 0x406;
    frame.mOperationLow = 1;
    MI_CpuCopy8(CPSMyMac, frame.mSenderMac, 6);
    frame.mSenderAddressHigh = ((u16) (*(u32 *) &CPSMyIp >> 16) >> 8) | ((u16) (*(u32 *) &CPSMyIp >> 16) << 8);
    frame.mSenderAddressLow = ((u16) CPSMyIp >> 8) | ((u16) CPSMyIp << 8);
    frame.mTargetAddressHigh = ((u16) (address >> 16) >> 8) | ((u16) (address >> 16) << 8);
    frame.mTargetAddressLow = ((u16) address >> 8) | ((u16) address << 8);
    send_packet((u8 *) &frame, 0x2a, NULL, 0);
}

u8 *arprequest(u32 address) {
    u32 outerRetry;
    u32 innerRetry;
    u8 *mac;

    for (outerRetry = 0; outerRetry < 8; outerRetry++) {
        send_arprequest(address);
        for (innerRetry = 0; innerRetry < 0x14; innerRetry++) {
            OS_Sleep(100);
            mac = inq_arpcache(address);
            if (mac != NULL) {
                return mac;
            }
        }
    }
    return NULL;
}

void reg_arpcache(u8 *mac, u32 address, u32 addedEntry) {
    u16 now;
    u16 maxAge;
    u32 candidate;
    u32 index;
    CPSArpCache *entry;

    if (address == 0x7f000001 || address == CPSMyIp || ip_islocal(address) == FALSE || is_multicast(address) != FALSE) {
        return;
    }
    now = OS_GetTick() >> 16;
    for (index = 0; index < 8; index++) {
        if (address == gArpCache[index].mIp) {
            gArpCache[index].mWhen = now;
            MI_CpuCopy8(mac, gArpCache[index].mMac, 6);
            return;
        }
    }
    if (addedEntry != 0) {
        maxAge = 0;
        candidate = 0;
        for (index = 0, entry = gArpCache; index < 8; index++) {
            if (entry->mIp == 0) {
                candidate = index;
                break;
            }
            if ((s16) (now - entry->mWhen) > maxAge) {
                maxAge = now - entry->mWhen;
                candidate = index;
            }
            entry++;
        }
        gArpCache[candidate].mIp = address;
        MI_CpuCopy8(mac, gArpCache[candidate].mMac, 6);
        gArpCache[candidate].mWhen = now;
    }
}

void send_ether(u8 *header, u32 headerLength, void *body, u32 bodyLength, u32 addressTo, u16 type) {
    u8 *destMac;

    *(u16 *) (header - 2) = (type >> 8) | (type << 8);
    if (is_multicast(addressTo) == FALSE) {
        addressTo = get_targetip(addressTo);
        if (addressTo == 0) {
            return;
        }
        destMac = inq_arpcache(addressTo);
        if (destMac == NULL) {
            destMac = arprequest(addressTo);
        }
        if (destMac == NULL) {
            return;
        }
        MI_CpuCopy8(destMac, header - 0xe, 6);
    } else {
        header[-0xe] = 1;
        header[-0xd] = 0;
        header[-0xc] = 0x5e;
        header[-0xb] = (addressTo >> 16) & 0x7f;
        header[-0xa] = addressTo >> 8;
        header[-9] = addressTo;
    }
    MI_CpuCopy8(CPSMyMac, header - 8, 6);
    send_packet(header - 0xe, headerLength + 0xe, body, bodyLength);
}

void send_ip_frag(u8 *header, u32 headerLength, void *body, u32 bodyLength, u32 addressTo, u32 offset) {
    u16 g;
    u32 interruptState;

    g = headerLength + 0x14 + bodyLength;
    *(u16 *) (header - 0x12) = (g >> 8) | (g << 8);
    g = offset;
    *(u16 *) (header - 0xe) = (g >> 8) | (g << 8);
    *(u16 *) (header - 0xa) = 0;
    g = calc_checksum(header - 0x14, 0x14);
    *(u16 *) (header - 0xa) = (g >> 8) | (g << 8);
    if (addressTo != 0x7f000001 && addressTo != CPSMyIp) {
        send_ether(header - 0x14, headerLength + 0x14, body, bodyLength, addressTo, 0x800);
    }
    if (addressTo == 0x7f000001 || addressTo == CPSMyIp || is_multicast(addressTo) != FALSE) {
        MI_CpuCopy8(gIpv4LlcSnapHeader, header - 0x1c, 8);
        interruptState = OS_DisableInterrupts();
        put_in_buffer(CPSMyMac, CPSMyMac, header - 0x1c, headerLength + 0x1c, body, bodyLength);
        OS_RestoreInterrupts(interruptState);
    }
}

void send_ip(u8 *header, u32 headerLength, u8 *body, u32 bodyLength, u32 addressTo, u8 protocol) {
    u16 offset;
    u8 *payloadCursor;
    u32 chunkLength;

    header[-0x14] = 0x45;
    offset = 0;
    header[-0x13] = 0;
    gIpId++;
    *(u16 *) (header - 0x10) = (gIpId >> 8) | (gIpId << 8);
    header[-0xc] = 0x80;
    header[-0xb] = protocol;
    *(u16 *) (header - 8) = ((u16) (CPSMyIp >> 16) >> 8) | ((u16) (CPSMyIp >> 16) << 8);
    *(u16 *) (header - 6) = ((u16) CPSMyIp >> 8) | ((u16) CPSMyIp << 8);
    *(u16 *) (header - 4) = ((u16) (addressTo >> 16) >> 8) | ((u16) (addressTo >> 16) << 8);
    *(u16 *) (header - 2) = ((u16) addressTo >> 8) | ((u16) addressTo << 8);
    if (headerLength > 0x5c8) {
        payloadCursor = header;
        while (headerLength > 0x5c8) {
            send_ip_frag(header, 0, payloadCursor, 0x5c8, addressTo, offset | 0x2000);
            payloadCursor += 0x5c8;
            headerLength -= 0x5c8;
            offset += 0xb9;
        }
        if (headerLength != 0) {
            if (bodyLength != 0) {
                send_ip_frag(header, 0, payloadCursor, headerLength, addressTo, offset | 0x2000);
            } else {
                send_ip_frag(header, 0, payloadCursor, headerLength, addressTo, offset);
            }
            offset += headerLength >> 3;
            headerLength = 0;
        }
    }
    if (headerLength + bodyLength > 0x5c8) {
        do {
            chunkLength = 0x5c8 - headerLength;
            send_ip_frag(header, headerLength, body, chunkLength, addressTo, offset | 0x2000);
            body += chunkLength;
            bodyLength -= chunkLength;
            offset += 0xb9;
            headerLength = 0;
        } while (bodyLength > 0x5c8);
    }
    if (headerLength + bodyLength != 0) {
        send_ip_frag(header, headerLength, body, bodyLength, addressTo, offset);
    }
}

void send_ping(u8 *pattern, u32 length, CPSSoc *socket) {
    u32 checksum;
    u16 invertedChecksum;
    u16 sequence;
    u8 *sendBuffer;
    u8 *icmpHeader;

    sendBuffer = socket->mSendBuffer;
    icmpHeader = sendBuffer + 0x22;
    *OFFSET_PTR(u16, sendBuffer, 0x22) = 8;
    *OFFSET_PTR(u16, icmpHeader, 4) = (u32) OSi_ThreadInfo.mCurrentThread;
    *OFFSET_PTR(u16, icmpHeader, 2) = 0;
    sequence = gPingSequence;
    socket->mLocalPort = sequence;
    gPingSequence++;
    *OFFSET_PTR(u16, icmpHeader, 6) = sequence;
    checksum = calc_checksum_do(icmpHeader, 8, 0);
    checksum = calc_checksum_do(pattern, length, checksum);
    invertedChecksum = invert_checksum(checksum);
    *OFFSET_PTR(u16, icmpHeader, 2) = (invertedChecksum >> 8) | (invertedChecksum << 8);
    send_ip(icmpHeader, 8, pattern, length, socket->mRemoteIp, 1);
}

void send_udp(u8 *data, u32 length, CPSSoc *socket) {
    u8 *sendBuffer;
    u8 *header;
    u32 checksum;
    u16 f;

    sendBuffer = socket->mSendBuffer;
    header = sendBuffer + 0x22;
    *(u16 *) (header - 0xc) = ((u16) (CPSMyIp >> 16) >> 8) | ((u16) (CPSMyIp >> 16) << 8);
    *(u16 *) (header - 0xa) = ((u16) CPSMyIp >> 8) | ((u16) CPSMyIp << 8);
    *(u16 *) (header - 8) = ((u16) (socket->mRemoteIp >> 16) >> 8) | ((u16) (socket->mRemoteIp >> 16) << 8);
    *(u16 *) (header - 6) = ((u16) socket->mRemoteIp >> 8) | ((u16) socket->mRemoteIp << 8);
    *(u16 *) (header - 4) = 0x1100;
    f = length + 8;
    *OFFSET_PTR(u16, header, 4) = (f >> 8) | (f << 8);
    *(u16 *) (header - 2) = *OFFSET_PTR(u16, header, 4);
    *OFFSET_PTR(u16, header, 2) = (socket->mRemotePort >> 8) | (socket->mRemotePort << 8);
    *OFFSET_PTR(u16, sendBuffer, 0x22) = (socket->mLocalPort >> 8) | (socket->mLocalPort << 8);
    *OFFSET_PTR(u16, header, 6) = 0;
    checksum = calc_checksum_do(header - 0xc, 0x14, 0);
    checksum = calc_checksum_do(data, length, checksum);
    f = invert_checksum(checksum);
    *OFFSET_PTR(u16, header, 6) = (f >> 8) | (f << 8);
    send_ip(header, 8, data, length, socket->mRemoteIp, 0x11);
}

void send_tcp(u8 *data, u32 length, CPSSoc *socket, u32 flag, u16 urgent) {
    u8 *header;
    u32 tcpSize;
    u32 checksum;
    u16 invertedChecksum;

    if (socket->mState == 0) {
        return;
    }
    if (OSi_ThreadInfo.mCurrentThread == &gTcpipThread) {
        header = gTmpBufTcpHeader;
    } else {
        header = socket->mSendBuffer + 0x22;
    }
    if (flag & 2) {
        tcpSize = 0x18;
    } else {
        tcpSize = 0x14;
    }
    *(u16 *) (header - 0xc) = ((u16) (CPSMyIp >> 16) >> 8) | ((u16) (CPSMyIp >> 16) << 8);
    *(u16 *) (header - 0xa) = ((u16) CPSMyIp >> 8) | ((u16) CPSMyIp << 8);
    *(u16 *) (header - 8) = ((u16) (socket->mRemoteIp >> 16) >> 8) | ((u16) (socket->mRemoteIp >> 16) << 8);
    *(u16 *) (header - 6) = ((u16) socket->mRemoteIp >> 8) | ((u16) socket->mRemoteIp << 8);
    *(u16 *) (header - 4) = 0x600;
    *(u16 *) (header - 2) = ((u16) (tcpSize + length) >> 8) | ((u16) (tcpSize + length) << 8);
    *(u16 *) header = (socket->mLocalPort >> 8) | (socket->mLocalPort << 8);
    *OFFSET_PTR(u16, header, 2) = (socket->mRemotePort >> 8) | (socket->mRemotePort << 8);
    *OFFSET_PTR(u16, header, 4) = ((u16) (socket->mSeqNo >> 16) >> 8) | ((u16) (socket->mSeqNo >> 16) << 8);
    *OFFSET_PTR(u16, header, 6) = ((u16) socket->mSeqNo >> 8) | ((u16) socket->mSeqNo << 8);
    *OFFSET_PTR(u16, header, 8) = ((u16) (socket->mAckNo >> 16) >> 8) | ((u16) (socket->mAckNo >> 16) << 8);
    *OFFSET_PTR(u16, header, 0xa) = ((u16) socket->mAckNo >> 8) | ((u16) socket->mAckNo << 8);
    header[0xc] = (tcpSize >> 2) << 4;
    header[0xd] = flag;
    *OFFSET_PTR(u16, header, 0xe) = ((u16) (socket->mReceiveBufferSize - socket->mReceiveBufferLength) >> 8) |
                                    ((u16) (socket->mReceiveBufferSize - socket->mReceiveBufferLength) << 8);
    *OFFSET_PTR(u16, header, 0x10) = 0;
    *OFFSET_PTR(u16, header, 0x12) = (urgent >> 8) | (urgent << 8);
    if (flag & 2) {
        *OFFSET_PTR(u16, header, 0x14) =
            ((u16) ((gMyMss + 0x2040000U) >> 16) >> 8) | ((u16) ((gMyMss + 0x2040000U) >> 16) << 8);
        *OFFSET_PTR(u16, header, 0x16) = ((u16) (gMyMss + 0x2040000U) >> 8) | ((u16) (gMyMss + 0x2040000U) << 8);
    }
    checksum = calc_checksum_do(header - 0xc, tcpSize + 0xc, 0);
    checksum = calc_checksum_do(data, length, checksum);
    invertedChecksum = invert_checksum(checksum);
    *OFFSET_PTR(u16, header, 0x10) = (invertedChecksum >> 8) | (invertedChecksum << 8);
    send_ip(header, tcpSize, data, length, socket->mRemoteIp, 6);
    socket->mSeqNo += length;
    flag &= 3;
    if (flag != 0) {
        socket->mSeqNo++;
    }
}

void reply_arp(ArpPacket *packet) {
    packet->mOperation = 0x200;
    MI_CpuCopy8(packet->mSenderMac, packet->mTargetMac, 10);
    MI_CpuCopy8(CPSMyMac, packet->mSenderMac, 6);
    packet->mSenderAddressHigh = ((u16) (CPSMyIp >> 16) >> 8) | ((u16) (CPSMyIp >> 16) << 8);
    packet->mSenderAddressLow = ((u16) CPSMyIp >> 8) | ((u16) CPSMyIp << 8);
    MI_CpuCopy8(packet->mTargetMac, (u8 *) packet - 0xe, 6);
    MI_CpuCopy8(CPSMyMac, (u8 *) packet - 8, 6);
    send_packet((u8 *) packet - 0xe, 0x2a, NULL, 0);
}

void dispatch_arp(ArpPacket *packet, u32 length) {
    u32 operation;
    u32 fromUs;
    u32 toUs;
    u32 ownAddress;
    u32 senderAddress;

    if (length < 0x1c) {
        return;
    }
    if (maccmp(packet->mSenderMac, CPSMyMac) == FALSE) {
        return;
    }
    if (CPSMyIp == 0) {
        return;
    }
    if (packet->mHardwareType != 0x100) {
        return;
    }
    if (packet->mProtocolType != 8) {
        return;
    }
    if (packet->mAddressLengths != 0x406) {
        return;
    }
    operation = (u16) ((packet->mOperation >> 8) | (packet->mOperation << 8));
    if (operation != 1 && operation != 2) {
        return;
    }
    senderAddress = ((u16) ((packet->mSenderAddressHigh >> 8) | (packet->mSenderAddressHigh << 8)) << 16) |
                    (u16) ((packet->mSenderAddressLow >> 8) | (packet->mSenderAddressLow << 8));
    ownAddress = CPSMyIp;
    if (senderAddress == ownAddress) {
        fromUs = 1;
    } else {
        fromUs = 0;
    }
    if (ownAddress == (u32) (((u16) ((packet->mTargetAddressHigh >> 8) | (packet->mTargetAddressHigh << 8)) << 16) |
                             (u16) ((packet->mTargetAddressLow >> 8) | (packet->mTargetAddressLow << 8)))) {
        toUs = 1;
    } else {
        toUs = 0;
    }
    if (fromUs == 0) {
        reg_arpcache((u8 *) packet->mSenderMac, senderAddress, toUs);
    }
    if (operation == 1 && toUs != 0) {
        reply_arp(packet);
        return;
    }
    if (operation == 2 && toUs != 0 && fromUs != 0) {
        gIpConflict = 1;
    }
}

void reply_icmp(IpHeader *ipHeader, IcmpHeader *icmp, u32 length) {
    u32 senderAddress;
    u32 targetAddress;
    u16 checksum;

    senderAddress = ((u16) ((ipHeader->mSourceAddressHigh >> 8) | (ipHeader->mSourceAddressHigh << 8)) << 16) |
                    (u16) ((ipHeader->mSourceAddressLow >> 8) | (ipHeader->mSourceAddressLow << 8));
    if (is_multicast(senderAddress) != FALSE) {
        return;
    }
    targetAddress = get_targetip(senderAddress);
    if (targetAddress == 0) {
        return;
    }
    if (inq_arpcache(targetAddress) == NULL) {
        send_arprequest(targetAddress);
        return;
    }
    icmp->mType = 0;
    icmp->mChecksum = 0;
    checksum = calc_checksum(icmp, length);
    icmp->mChecksum = (checksum >> 8) | (checksum << 8);
    send_ip((u8 *) icmp, length, NULL, 0,
            ((u16) ((ipHeader->mSourceAddressHigh >> 8) | (ipHeader->mSourceAddressHigh << 8)) << 16) |
                (u16) ((ipHeader->mSourceAddressLow >> 8) | (ipHeader->mSourceAddressLow << 8)),
            1);
}

void process_icmp_reply(IpHeader *ipHeader, IcmpHeader *icmp, u32 length) {
    OSThread *thread;
    CPSSoc *socket;

    for (thread = OSi_ThreadInfo.mListHead; thread != NULL; thread = thread->mNext) {
        socket = thread->mSpecific[0];
        if (socket == NULL || socket->mThread == NULL || socket->mState != 0xb ||
            (u16) (u32) socket->mThread != icmp->mIdentifier) {
            continue;
        }
        if (socket->mLocalPort != icmp->mSequence || socket->mReceiveBufferLength != 0) {
            continue;
        }
        if (socket->mRemoteIp !=
            (u32) (((u16) ((ipHeader->mSourceAddressHigh >> 8) | (ipHeader->mSourceAddressHigh << 8)) << 16) |
                   (u16) ((ipHeader->mSourceAddressLow >> 8) | (ipHeader->mSourceAddressLow << 8)))) {
            continue;
        }
        length -= 8;
        if (length > socket->mReceiveBufferSize) {
            socket->mReceiveBufferLength = socket->mReceiveBufferSize;
        } else {
            socket->mReceiveBufferLength = length;
        }
        MI_CpuCopy8((u8 *) icmp + 8, socket->mReceiveBuffer, socket->mReceiveBufferLength);
        if (socket->mBlockType == 3) {
            socket->mBlockType = 0;
            OS_WakeupThreadDirect(socket->mThread);
            return;
        }
        return;
    }
}

BOOL valid_IP(int sourceAddress, int destAddress) {
    if ((((sourceAddress != 0) && (sourceAddress != -1)) && (destAddress != 0)) && (destAddress != -1)) {
        return 1;
    }
    return 0;
}

void dispatch_icmp(IpHeader *ipHeader, IcmpHeader *icmp, u32 length) {
    if (calc_checksum(icmp, length) == 0xffff) {
        if (valid_IP((u32) (((u16) ((ipHeader->mSourceAddressHigh >> 8) | (ipHeader->mSourceAddressHigh << 8)) << 16) |
                            (u16) ((ipHeader->mSourceAddressLow >> 8) | (ipHeader->mSourceAddressLow << 8))),
                     (u32) (((u16) ((ipHeader->mDestAddressHigh >> 8) | (ipHeader->mDestAddressHigh << 8)) << 16) |
                            (u16) ((ipHeader->mDestAddressLow >> 8) | (ipHeader->mDestAddressLow << 8)))) != 0) {
            switch (icmp->mType) {
                case 0:
                    process_icmp_reply(ipHeader, icmp, length);
                    break;
                case 8:
                    if (gIcmpEchoReplyEnabled != 0) {
                        reply_icmp(ipHeader, icmp, length);
                    }
                    break;
            }
        }
    }
}

CPSSoc *check_listener(const IpHeader *ipHeader, const TcpHeader *tcpHeader) {
    CPSSoc *socket;
    OSThread *thread;

    for (thread = OSi_ThreadInfo.mListHead; thread != NULL; thread = thread->mNext) {
        socket = thread->mSpecific[0];
        if (socket == NULL || socket->mThread == NULL || socket->mState != 1 ||
            socket->mLocalPort != (u16) ((tcpHeader->mDestPort >> 8) | (tcpHeader->mDestPort << 8))) {
            continue;
        }
        if (socket->mRemotePort != 0 &&
            socket->mRemotePort != (u16) ((tcpHeader->mSourcePort >> 8) | (tcpHeader->mSourcePort << 8))) {
            continue;
        }
        if (socket->mRemoteIp != 0 &&
            socket->mRemoteIp !=
                (u32) (((u16) ((ipHeader->mSourceAddressHigh >> 8) | (ipHeader->mSourceAddressHigh << 8)) << 16) |
                       (u16) ((ipHeader->mSourceAddressLow >> 8) | (ipHeader->mSourceAddressLow << 8)))) {
            continue;
        }
        return socket;
    }
    return NULL;
}

BOOL check_socket(const IpHeader *ipHeader, const TcpHeader *tcpHeader, const CPSSoc *socket) {
    u32 matches = 0;
    u32 remotePortMatches = 0;
    u32 localPortMatches = 0;
    u32 isStreamSocket = 0;

    if (socket->mState != 0xa && socket->mState != 0xb) {
        isStreamSocket = 1;
    }
    if (isStreamSocket != 0) {
        if (socket->mLocalPort == (u16) ((tcpHeader->mDestPort >> 8) | (tcpHeader->mDestPort << 8))) {
            localPortMatches = 1;
        }
    }
    if (localPortMatches != 0) {
        if (socket->mRemotePort == (u16) ((tcpHeader->mSourcePort >> 8) | (tcpHeader->mSourcePort << 8))) {
            remotePortMatches = 1;
        }
    }
    if (remotePortMatches != 0) {
        if (socket->mRemoteIp ==
            (u32) (((u16) ((ipHeader->mSourceAddressHigh >> 8) | (ipHeader->mSourceAddressHigh << 8)) << 16) |
                   (u16) ((ipHeader->mSourceAddressLow >> 8) | (ipHeader->mSourceAddressLow << 8)))) {
            matches = 1;
        }
    }
    return matches;
}

CPSSoc *find_socket(const IpHeader *ipHeader, const TcpHeader *tcpHeader) {
    CPSSoc *socket;
    OSThread *thread;

    thread = OSi_ThreadInfo.mListHead;
    while (thread != NULL) {
        socket = thread->mSpecific[0];
        if (socket != NULL && socket->mThread != NULL && check_socket(ipHeader, tcpHeader, socket) != 0) {
            return socket;
        }
        thread = thread->mNext;
    }
    return NULL;
}

void parse_mss(const TcpHeader *tcpHeader, CPSSoc *socket) {
    const u8 *options;
    s32 optionsLength;
    s32 remaining;
    s32 skipLength;
    u8 optionKind;

    socket->mRemoteMss = 0x218;
    optionsLength = (tcpHeader->mDataOffset & 0xf0) / 4 - 0x14;
    options = (const u8 *) tcpHeader + 0x14;
    remaining = optionsLength - 1;
    if (optionsLength != 0) {
        do {
            optionKind = *options++;
            if (optionKind == 0) {
                break;
            }
            if (optionKind != 1) {
                if (optionKind == 2) {
                    socket->mRemoteMss = (options[1] << 8) | options[2];
                    options += 3;
                    remaining -= 3;
                } else {
                    skipLength = options[0] - 1;
                    remaining -= skipLength;
                    options += skipLength;
                }
            }
        } while (remaining-- != 0);
    }
}

u32 no_need_inq(u32 address) {
    u32 target;

    target = get_targetip(address);
    if (target == 0) {
        return 1;
    }
    return (u32) inq_arpcache(target);
}

void tcp_send_handshake(CPSSoc *socket, u32 flag, u16 urgent) {
    if (no_need_inq(socket->mRemoteIp) != 0 || OSi_ThreadInfo.mCurrentThread != &gTcpipThread) {
        send_tcp(NULL, 0, socket, flag, urgent);
    } else {
        send_arprequest(get_targetip(socket->mRemoteIp));
    }
}

void tcp_send_ack(void *socket, u16 urgent) {
    tcp_send_handshake(socket, 16, urgent);
}

void tcp_send_finack(void *socket, u16 urgent) {
    tcp_send_handshake(socket, 17, urgent);
}

void tcp_send_rst(IpHeader *ipHeader, TcpHeader *tcpHeader, u32 length, u16 urgent) {
    CPSSoc *socket;

    socket = &gTmpSoc;
    MI_CpuFill8(socket, 0, 0x64);
    socket->mLocalPort = (tcpHeader->mDestPort >> 8) | (tcpHeader->mDestPort << 8);
    socket->mRemotePort = (tcpHeader->mSourcePort >> 8) | (tcpHeader->mSourcePort << 8);
    socket->mRemoteIp = ((u16) ((ipHeader->mSourceAddressHigh >> 8) | (ipHeader->mSourceAddressHigh << 8)) << 16) |
                        (u16) ((ipHeader->mSourceAddressLow >> 8) | (ipHeader->mSourceAddressLow << 8));
    if ((tcpHeader->mFlags & 0x10) != 0) {
        socket->mSeqNo = ((u16) ((tcpHeader->mAckNoHigh >> 8) | (tcpHeader->mAckNoHigh << 8)) << 16) |
                         (u16) ((tcpHeader->mAckNoLow >> 8) | (tcpHeader->mAckNoLow << 8));
        tcp_send_handshake(socket, 4, urgent);
        return;
    }
    socket->mSeqNo = 0;
    socket->mAckNo = length + (u32) (((u16) ((tcpHeader->mSeqNoHigh >> 8) | (tcpHeader->mSeqNoHigh << 8)) << 16) |
                                     (u16) ((tcpHeader->mSeqNoLow >> 8) | (tcpHeader->mSeqNoLow << 8)));
    if ((tcpHeader->mFlags & 3) != 0) {
        socket->mAckNo++;
    }
    tcp_send_handshake(socket, 0x14, urgent);
}

void dt_syn_listen(IpHeader *ipHeader, TcpHeader *tcpHeader, CPSSoc *socket) {
    socket->mState = 3;
    socket->mStateStartTime = OS_GetTick() >> 16;
    socket->mLocalIpReal = ((u16) ((ipHeader->mDestAddressHigh >> 8) | (ipHeader->mDestAddressHigh << 8)) << 16) |
                           (u16) ((ipHeader->mDestAddressLow >> 8) | (ipHeader->mDestAddressLow << 8));
    socket->mRemotePort = (tcpHeader->mSourcePort >> 8) | (tcpHeader->mSourcePort << 8);
    socket->mRemoteIp = ((u16) ((ipHeader->mSourceAddressHigh >> 8) | (ipHeader->mSourceAddressHigh << 8)) << 16) |
                        (u16) ((ipHeader->mSourceAddressLow >> 8) | (ipHeader->mSourceAddressLow << 8));
    socket->mAckNo = (u32) (((u16) ((tcpHeader->mSeqNoHigh >> 8) | (tcpHeader->mSeqNoHigh << 8)) << 16) |
                            (u16) ((tcpHeader->mSeqNoLow >> 8) | (tcpHeader->mSeqNoLow << 8))) +
                     1;
    parse_mss(tcpHeader, socket);
    tcp_send_handshake(socket, 0x12, (ipHeader->mIdentifierSecondByte << 8) + 1);
}

BOOL find_specific_socket(IpHeader *ipHeader, TcpHeader *tcpHeader, u32 length) {
    CPSSoc *socket;

    socket = find_socket(ipHeader, tcpHeader);
    if (socket != NULL) {
        if (socket->mState == 1) {
            dt_syn_listen(ipHeader, tcpHeader, socket);
        } else if (socket->mState == 3 || socket->mState == 4) {
            socket->mSeqNo--;
            dt_syn_listen(ipHeader, tcpHeader, socket);
        } else {
            tcp_send_rst(ipHeader, tcpHeader, length, (ipHeader->mIdentifierSecondByte << 8) + 3);
        }
        return 1;
    }
    return 0;
}

void dt_syn(IpHeader *ipHeader, TcpHeader *tcpHeader, u32 length) {
    CPSSoc *socket;

    if (valid_IP((u32) (((u16) ((ipHeader->mSourceAddressHigh >> 8) | (ipHeader->mSourceAddressHigh << 8)) << 16) |
                        (u16) ((ipHeader->mSourceAddressLow >> 8) | (ipHeader->mSourceAddressLow << 8))),
                 (u32) (((u16) ((ipHeader->mDestAddressHigh >> 8) | (ipHeader->mDestAddressHigh << 8)) << 16) |
                        (u16) ((ipHeader->mDestAddressLow >> 8) | (ipHeader->mDestAddressLow << 8)))) != 0) {
        if (find_specific_socket(ipHeader, tcpHeader, length) == 0) {
            socket = check_listener(ipHeader, tcpHeader);
            if (socket != NULL) {
                dt_syn_listen(ipHeader, tcpHeader, socket);
                return;
            }
            OS_YieldThread();
            socket = check_listener(ipHeader, tcpHeader);
            if (socket != NULL) {
                dt_syn_listen(ipHeader, tcpHeader, socket);
            }
        }
    }
}

void dt_synack(IpHeader *ipHeader, TcpHeader *tcpHeader, u32 length) {
    CPSSoc *socket;

    socket = find_socket(ipHeader, tcpHeader);
    if (socket == NULL || socket->mState != 2) {
        tcp_send_rst(ipHeader, tcpHeader, length, (ipHeader->mIdentifierSecondByte << 8) + 5);
        return;
    }
    OS_YieldThread();
    socket->mAckNo = (u32) (((u16) ((tcpHeader->mSeqNoHigh >> 8) | (tcpHeader->mSeqNoHigh << 8)) << 16) |
                            (u16) ((tcpHeader->mSeqNoLow >> 8) | (tcpHeader->mSeqNoLow << 8))) +
                     1;
    socket->mRemoteAckNo = ((u16) ((tcpHeader->mAckNoHigh >> 8) | (tcpHeader->mAckNoHigh << 8)) << 16) |
                           (u16) ((tcpHeader->mAckNoLow >> 8) | (tcpHeader->mAckNoLow << 8));
    socket->mRemoteWin = (tcpHeader->mWindow >> 8) | (tcpHeader->mWindow << 8);
    parse_mss(tcpHeader, socket);
    tcp_send_ack(socket, (ipHeader->mIdentifierSecondByte << 8) + 6);
    socket->mState = 4;
    if (socket->mBlockType == 1) {
        socket->mBlockType = 0;
        OS_WakeupThreadDirect(socket->mThread);
    }
}

void dt_ack(IpHeader *ipHeader, TcpHeader *tcpHeader, u32 length) {
    CPSSoc *socket;
    u32 flags;
    u32 c;
    s32 ackNoLow;
    s32 seqNoLow;
    u32 freeSpace;
    u32 interruptState;

    socket = find_socket(ipHeader, tcpHeader);
    if (socket == NULL) {
        tcp_send_rst(ipHeader, tcpHeader, length, (ipHeader->mIdentifierSecondByte << 8) + 9);
        return;
    }
    flags = tcpHeader->mFlags;
    ackNoLow = tcpHeader->mAckNoLow;
    socket->mRemoteAckNo = ((u16) ((tcpHeader->mAckNoHigh >> 8) | (tcpHeader->mAckNoHigh << 8)) << 16) |
                           (u16) ((ackNoLow >> 8) | (ackNoLow << 8));
    seqNoLow = tcpHeader->mSeqNoLow;
    c = ((u16) ((tcpHeader->mSeqNoHigh >> 8) | (tcpHeader->mSeqNoHigh << 8)) << 16) |
        (u16) ((seqNoLow >> 8) | (seqNoLow << 8));
    if (socket->mState == 4 && socket->mAckNo != c) {
        tcp_send_ack(socket, (ipHeader->mIdentifierSecondByte << 8) + 0xa);
        return;
    }
    socket->mRemoteWin = (tcpHeader->mWindow >> 8) | (tcpHeader->mWindow << 8);
    switch (socket->mState) {
        case 0:
        case 2:
            tcp_send_rst(ipHeader, tcpHeader, length, (ipHeader->mIdentifierSecondByte << 8) + 0x63);
            break;
        case 3:
            socket->mState = 4;
            if (socket->mBlockType == 1) {
                socket->mBlockType = 0;
                OS_WakeupThreadDirect(socket->mThread);
            }
            if (length == 0) {
                break;
            }
        case 4:
            socket->mAckRcvd++;
            freeSpace = socket->mReceiveBufferSize - socket->mReceiveBufferLength;
            if (length > freeSpace) {
                length = freeSpace;
                c = 0;
            } else {
                c = 1;
            }
            if (length != 0) {
                interruptState = OS_DisableInterrupts();
                MI_CpuCopy8((u8 *) tcpHeader + (tcpHeader->mDataOffset & 0xf0) / 4,
                            (u8 *) socket->mReceiveBuffer + socket->mReceiveBufferLength, length);
                socket->mReceiveBufferLength += length;
                socket->mAckNo += length;
                OS_RestoreInterrupts(interruptState);
                if (socket->mBlockType == 2) {
                    socket->mBlockType = 0;
                    OS_WakeupThreadDirect(socket->mThread);
                }
            }
            if (c != 0 && (flags & 1) != 0) {
                socket->mState = 6;
                socket->mAckNo++;
                tcp_send_finack(socket, (ipHeader->mIdentifierSecondByte << 8) + 0xb);
                if (length == 0 && socket->mBlockType == 2) {
                    socket->mBlockType = 0;
                    OS_WakeupThreadDirect(socket->mThread);
                }
                break;
            }
            if (length != 0) {
                tcp_send_ack(socket, (ipHeader->mIdentifierSecondByte << 8) + 0xc);
            }
            break;
        case 7:
        case 8:
            if ((flags & 1) != 0) {
                socket->mAckNo = socket->mAckNo + (length + 1);
                tcp_send_ack(socket, (ipHeader->mIdentifierSecondByte << 8) + 0xd);
                socket->mState = 0;
                if (socket->mBlockType == 2) {
                    socket->mBlockType = 0;
                    OS_WakeupThreadDirect(socket->mThread);
                }
                break;
            }
            if (length != 0) {
                socket->mAckNo += length;
                tcp_send_ack(socket, (ipHeader->mIdentifierSecondByte << 8) + 0xe);
            }
            socket->mState = 8;
            break;
        case 6:
        case 9:
            socket->mState = 0;
            if (socket->mBlockType == 2) {
                socket->mBlockType = 0;
                OS_WakeupThreadDirect(socket->mThread);
            }
            break;
        default:
            if ((flags & 1) != 0) {
                socket->mAckNo++;
            }
            tcp_send_ack(socket, (ipHeader->mIdentifierSecondByte << 8) + 0x12);
            break;
    }
    OS_YieldThread();
}

void dt_fin(IpHeader *ipHeader, TcpHeader *tcpHeader, u32 length) {
    CPSSoc *socket;

    socket = find_socket(ipHeader, tcpHeader);
    if (socket == NULL) {
        return;
    }
    switch (socket->mState) {
        case 7:
            socket->mAckNo++;
            tcp_send_ack(socket, (ipHeader->mIdentifierSecondByte << 8) + 0x13);
            socket->mState = 9;
            return;
        case 8:
            socket->mAckNo++;
            tcp_send_ack(socket, (ipHeader->mIdentifierSecondByte << 8) + 0x14);
            socket->mState = 0;
            if (socket->mBlockType == 2) {
                socket->mBlockType = 0;
                OS_WakeupThreadDirect(socket->mThread);
                return;
            }
            return;
        case 4:
            socket->mAckNo++;
            tcp_send_finack(socket, (ipHeader->mIdentifierSecondByte << 8) + 0x15);
            socket->mState = 6;
            return;
        default:
            tcp_send_rst(ipHeader, tcpHeader, length, (ipHeader->mIdentifierSecondByte << 8) + 0x16);
            return;
    }
}

void dt_rst(const IpHeader *ipHeader, const TcpHeader *tcpHeader) {
    CPSSoc *socket;

    socket = find_socket(ipHeader, tcpHeader);
    if (socket != NULL) {
        OS_YieldThread();
        socket->mState = 0;
        if (socket->mBlockType - 1 <= 1) {
            socket->mBlockType = 0;
            OS_WakeupThreadDirect(socket->mThread);
        }
    }
}

void dispatch_tcp(IpHeader *ipHeader, TcpHeader *tcpHeader, u32 length) {
    if (check_tcpudpsum(tcpHeader, length, ipHeader, 6) != FALSE) {
        return;
    }
    length -= (tcpHeader->mDataOffset & 0xf0) / 4;
    switch (tcpHeader->mFlags & 0x17) {
        case 2:
            if (tcpHeader->mFlags & 0x28) {
                return;
            }
            dt_syn(ipHeader, tcpHeader, length);
            return;
        case 0x12:
            if (tcpHeader->mFlags & 0x28) {
                return;
            }
            dt_synack(ipHeader, tcpHeader, length);
            return;
        case 0x10:
        case 0x11:
            dt_ack(ipHeader, tcpHeader, length);
            return;
        case 1:
            dt_fin(ipHeader, tcpHeader, length);
            return;
        default:
            if (tcpHeader->mFlags & 4) {
                dt_rst(ipHeader, tcpHeader);
                return;
            }
            tcp_send_rst(ipHeader, tcpHeader, length, (ipHeader->mIdentifierSecondByte << 8) + 0x17);
            return;
    }
}

void dispatch_udp(IpHeader *ipHeader, UdpHeader *udpHeader, u32 length) {
    OSThread *thread;
    CPSSoc *socket;

    if (udpHeader->mChecksum != 0 &&
        check_tcpudpsum(udpHeader, length, ipHeader, 0x11) != FALSE) {
        return;
    }
    for (thread = OSi_ThreadInfo.mListHead; thread != NULL; thread = thread->mNext) {
        socket = thread->mSpecific[0];
        if (socket == NULL || socket->mThread == NULL || socket->mState != 0xa ||
            socket->mLocalPort != (u16) ((udpHeader->mDestPort >> 8) | (udpHeader->mDestPort << 8))) {
            continue;
        }
        if (socket->mRemotePort != 0 &&
            socket->mRemotePort != (u16) ((udpHeader->mSourcePort >> 8) | (udpHeader->mSourcePort << 8))) {
            continue;
        }
        if (socket->mRemoteIp != 0 && socket->mRemoteIp != 0xffffffff &&
            socket->mRemoteIp !=
                (u32) (((u16) ((ipHeader->mSourceAddressHigh >> 8) | (ipHeader->mSourceAddressHigh << 8)) << 16) |
                       (u16) ((ipHeader->mSourceAddressLow >> 8) | (ipHeader->mSourceAddressLow << 8)))) {
            continue;
        }
        socket->mLocalIpReal = ((u16) ((ipHeader->mDestAddressHigh >> 8) | (ipHeader->mDestAddressHigh << 8)) << 16) |
                               (u16) ((ipHeader->mDestAddressLow >> 8) | (ipHeader->mDestAddressLow << 8));
        if (socket->mRemoteIp == 0) {
            socket->mRemoteIp =
                ((u16) ((ipHeader->mSourceAddressHigh >> 8) | (ipHeader->mSourceAddressHigh << 8)) << 16) |
                (u16) ((ipHeader->mSourceAddressLow >> 8) | (ipHeader->mSourceAddressLow << 8));
            socket->mRemotePort = (udpHeader->mSourcePort >> 8) | (udpHeader->mSourcePort << 8);
        }
        if (socket->mReceiveBufferLength != 0) {
            return;
        }
        length -= 8;
        if (length > socket->mReceiveBufferSize) {
            socket->mReceiveBufferLength = socket->mReceiveBufferSize;
        } else {
            socket->mReceiveBufferLength = length;
        }
        MI_CpuCopy8((u8 *) udpHeader + 8, socket->mReceiveBuffer, socket->mReceiveBufferLength);
        if (socket->mBlockType == 3) {
            socket->mBlockType = 0;
            OS_WakeupThreadDirect(socket->mThread);
            return;
        }
        if (socket->mReceiveCallback != NULL &&
            socket->mReceiveCallback(socket->mReceiveBuffer, socket->mReceiveBufferLength, socket) != 0) {
            socket->mReceiveBufferLength = 0;
        }
        return;
    }
}

IpHeader *check_frag(IpHeader *packet, u32 *fragmented) {
    u32 a;
    u32 fragmentBytes;
    u32 fragOffset;
    u32 headerLength;
    u32 size;
    u32 byteOffset;
    u32 sourceAddress;
    u32 fragEnd;
    u32 fragCount;
    u32 last;
    CPSFragTable *freeSlot;
    CPSFragTable *slot;
    u16 identifier;
    u32 slotIndex;
    u32 rangeIndex;
    u32 coveredUpTo;

    *fragmented = 0;
    a = (u16) ((packet->mFragOffset >> 8) | (packet->mFragOffset << 8));
    if ((a & 0x3fff) == 0) {
        return packet;
    }
    headerLength = (packet->mVersionIhl & 0xf) << 2;
    identifier = *(u16 *) &packet->mIdentifierFirstByte;
    sourceAddress = ((u16) ((packet->mSourceAddressHigh >> 8) | (packet->mSourceAddressHigh << 8)) << 16) |
                    (u16) ((packet->mSourceAddressLow >> 8) | (packet->mSourceAddressLow << 8));
    freeSlot = NULL;
    slot = gFragTable;
    for (slotIndex = 0; slotIndex < 8; slot++, slotIndex++) {
        if (slot->mFrags != 0 && slot->mIpFrom == sourceAddress && slot->mId == identifier) {
            break;
        }
        if (slot->mFrags == 0 && freeSlot == NULL) {
            freeSlot = slot;
        }
    }
    fragmentBytes = (u16) ((packet->mTotalLength >> 8) | (packet->mTotalLength << 8)) - headerLength;
    fragOffset = a & 0x1fff;
    byteOffset = fragOffset << 3;
    size = fragmentBytes + byteOffset;
    if (slotIndex == 8) {
        if (freeSlot == NULL || size > 0x1000) {
            return NULL;
        }
        slot = freeSlot;
        freeSlot->mBuf = CPSiAlloc(headerLength + 0x100e);
        if (freeSlot->mBuf == NULL) {
            return NULL;
        }
        freeSlot->mIpFrom = sourceAddress;
        freeSlot->mId = identifier;
        freeSlot->mLast = 0;
        freeSlot->mWhen = OS_GetTick() >> 16;
        freeSlot->mOfs0 = freeSlot->mBuf + 0xe + headerLength;
        MI_CpuCopy8(packet, freeSlot->mBuf + 0xe, headerLength);
    }
    if (slot->mFrags == 8 || size > 0x1000) {
        slot->mFrags = 0;
        CPSiFree(slot->mBuf);
        return NULL;
    }
    fragEnd = fragOffset + ((fragmentBytes + 7) >> 3);
    a = a & 0x2000;
    if (a == 0) {
        slot->mSize = size;
        slot->mLast = fragEnd;
    }
    slot->mFrom[slot->mFrags] = fragOffset;
    slot->mTo[slot->mFrags] = fragEnd;
    slot->mFrags++;
    MI_CpuCopy8((u8 *) packet + headerLength, slot->mOfs0 + byteOffset, fragmentBytes);
    last = slot->mLast;
    if (last == 0) {
        return NULL;
    }
    coveredUpTo = 0;
    rangeIndex = 0;
    fragCount = slot->mFrags;
    while (rangeIndex < fragCount) {
        if (slot->mFrom[rangeIndex] <= coveredUpTo && coveredUpTo < slot->mTo[rangeIndex]) {
            coveredUpTo = slot->mTo[rangeIndex];
            rangeIndex = 0;
        } else {
            rangeIndex++;
        }
    }
    if (coveredUpTo < last) {
        return NULL;
    }
    {
        IpHeader *rebuilt = (IpHeader *) (slot->mBuf + 0xe);

        rebuilt->mTotalLength = ((u16) (slot->mSize + ((rebuilt->mVersionIhl & 0xf) << 2)) >> 8) |
                                ((u16) (slot->mSize + ((rebuilt->mVersionIhl & 0xf) << 2)) << 8);
        slot->mFrags = 0;
        *fragmented = 1;
        return rebuilt;
    }
}

void dispatch_ip(IpHeader *packet, u32 length) {
    u32 wasReassembled;

    if ((u32) (((u16) ((packet->mDestAddressHigh >> 8) | (packet->mDestAddressHigh << 8)) << 16) |
               (u16) ((packet->mDestAddressLow >> 8) | (packet->mDestAddressLow << 8))) !=
        (u32) (((u16) ((packet->mSourceAddressHigh >> 8) | (packet->mSourceAddressHigh << 8)) << 16) |
               (u16) ((packet->mSourceAddressLow >> 8) | (packet->mSourceAddressLow << 8)))) {
        if (ip_isme(((u16) ((packet->mDestAddressHigh >> 8) | (packet->mDestAddressHigh << 8)) << 16) |
                    (u16) ((packet->mDestAddressLow >> 8) | (packet->mDestAddressLow << 8))) == FALSE) {
            return;
        }
        if (length < (u16) ((packet->mTotalLength >> 8) | (packet->mTotalLength << 8))) {
            return;
        }
        if (calc_checksum(packet, (packet->mVersionIhl & 0xf) << 2) != 0xffff) {
            return;
        }
        if (CPSMyIp == (u32) (((u16) ((packet->mDestAddressHigh >> 8) | (packet->mDestAddressHigh << 8)) << 16) |
                              (u16) ((packet->mDestAddressLow >> 8) | (packet->mDestAddressLow << 8)))) {
            reg_arpcache((u8 *) packet - 8,
                         ((u16) ((packet->mSourceAddressHigh >> 8) | (packet->mSourceAddressHigh << 8)) << 16) |
                             (u16) ((packet->mSourceAddressLow >> 8) | (packet->mSourceAddressLow << 8)),
                         0);
        }
    }
    packet = check_frag(packet, &wasReassembled);
    if (packet != NULL) {
        u32 headerLength = (packet->mVersionIhl & 0xf) << 2;
        void *payload = (u8 *) packet + headerLength;
        u32 payloadLength = (u16) ((packet->mTotalLength >> 8) | (packet->mTotalLength << 8)) - headerLength;
        u32 protocol = packet->mProtocol;

        if (protocol == 0x11) {
            dispatch_udp(packet, payload, payloadLength);
        } else if (CPSMyIp != 0) {
            if (protocol == 1) {
                dispatch_icmp(packet, payload, payloadLength);
            } else if (protocol == 6) {
                dispatch_tcp(packet, payload, payloadLength);
            }
        }
        if (wasReassembled != 0) {
            CPSiFree((u8 *) packet - 0xe);
        }
    }
}

void tcpip(void) {
    u32 length;
    EthernetHeader *frame;

    for (;;) {
        frame = (EthernetHeader *) receive_packet(&length);
        if (length > 0x22) {
            switch ((u16) ((frame->mEtherType >> 8) | (frame->mEtherType << 8))) {
                case 0x800:
                    dispatch_ip(OFFSET_PTR(IpHeader, frame, 0xe), length - 0xe);
                    break;
                case 0x806:
                    dispatch_arp(OFFSET_PTR(ArpPacket, frame, 0xe), length - 0xe);
                    break;
            }
        }
        throw_packet();
    }
}

u16 CPS_SocGetEport(void) {
    u32 inUse;
    OSThread *thread;
    CPSSoc *socket;

    do {
        inUse = 0;
        gEport++;
        if (gEport < 0x400 || gEport >= 0x1388) {
            gEport = 0x400;
        }
        for (thread = OSi_ThreadInfo.mListHead; thread != NULL; thread = thread->mNext) {
            socket = thread->mSpecific[0];
            if (socket != NULL && socket->mThread != NULL && socket->mLocalPort == gEport) {
                inUse = 1;
                break;
            }
        }
    } while (inUse != 0);
    return gEport;
}

u32 get_seqno(void) {
    CPSiRand32ctx[0] = CPSiRand32ctx[2] + CPSiRand32ctx[1] * CPSiRand32ctx[0];
    return CPSiRand32ctx[0] >> 32;
}

void CPS_SocRegister(void *socket) {
    u32 socketAddress = (u32) socket;
    u32 value1;
    value1 = (u32) &OSi_ThreadInfo;
    value1 = *(const u32 *) ((value1) + 4u);
    value1 = (value1) + 164u;
    *(u32 *) ((value1) + 0u) = socketAddress;
}

void CPS_SocUnRegister(void) {
    OSi_ThreadInfo.mCurrentThread->mSpecific[0] = NULL;
}

void CPS_SocDatagramMode(void) {
    CPSSoc *socket;
    socket = OSi_ThreadInfo.mCurrentThread->mSpecific[0];
    if (socket != NULL) {
        socket->mState = 10;
        socket->mReceiveBufferLength = 0;
    }
}

void CPS_SocBind(int ownPort, u16 remotePort, int remoteAddress) {
    u16 ephemeralPort;
    CPSSoc *socket;
    socket = OSi_ThreadInfo.mCurrentThread->mSpecific[0];
    if (socket != NULL) {
        if (remoteAddress == 0x7f000001) {
            remoteAddress = *(s32 *) &CPSMyIp;
        }
        socket->mRemotePortBound = remotePort;
        socket->mRemotePort = socket->mRemotePortBound;
        socket->mRemoteIpBound = remoteAddress;
        socket->mRemoteIp = socket->mRemoteIpBound;
        if (ownPort == 0) {
            ephemeralPort = CPS_SocGetEport();
            socket->mLocalPort = ephemeralPort;
            return;
        }
        socket->mLocalPort = ownPort;
    }
}

void CPS_SocUse(void) {
    CPSSoc *socket;
    socket = OSi_ThreadInfo.mCurrentThread->mSpecific[0];
    if (socket != NULL) {
        socket->mThread = OSi_ThreadInfo.mCurrentThread;
        socket->mState = 0;
        socket->mReceiveBufferLength = 0;
        socket->mOutBufferLength = 0;
        socket->mReceiveCallback = NULL;
    }
}

void CPS_SocRelease(void) {
    CPSSoc *socket;
    socket = OSi_ThreadInfo.mCurrentThread->mSpecific[0];
    if (socket != NULL) {
        socket->mThread = NULL;
    }
}

void CPS_SocDup(OSThread *thread) {
    thread->mSpecific[0] = OSi_ThreadInfo.mCurrentThread->mSpecific[0];
}

void CPSi_TcpListenRaw(CPSSoc *socket) {
    u32 seqNo;
    seqNo = get_seqno();
    socket->mSeqNo = seqNo;
    socket->mState = 1;
    socket->mBlockType = 1;
    OS_SleepThread(NULL);
}

void CPS_SetUdpCallback(Unk021a78a4Func callback) {
    u8 *socket;
    socket = OSi_ThreadInfo.mCurrentThread->mSpecific[0];
    if (socket != NULL) {
        *(Unk021a78a4Func *) (socket + 0x38) = callback;
    }
}

void CPS_TcpListen(void) {
    CPSSoc *socket;

    socket = OSi_ThreadInfo.mCurrentThread->mSpecific[0];
    if (socket != NULL) {
        if (socket->mUseHttps != 0) {
            RunSetupAfterReadingKind1RecordUntilDone(socket);
        } else {
            CPSi_TcpListenRaw(socket);
        }
    }
}

u32 CPSi_TcpConnectRaw(CPSSoc *socket) {
    u32 seqNo;
    u32 attempt;
    u32 interruptState;

    seqNo = get_seqno();
    for (attempt = 0; attempt < 3; attempt++) {
        socket->mSeqNo = seqNo;
        socket->mState = 2;
        socket->mStateStartTime = OS_GetTick() >> 16;
        tcp_send_handshake(socket, 2, 24);
        interruptState = OS_DisableInterrupts();
        if (CPSMyIp != 0) {
            socket->mBlockType = 1;
            OS_SleepThread(NULL);
        }
        OS_RestoreInterrupts(interruptState);
        if (socket->mState == 4) {
            return 0;
        }
        if (CPSMyIp == 0) {
            break;
        }
    }
    return 1;
}

u32 CPS_TcpConnect(void) {
    CPSSoc *socket;

    socket = OSi_ThreadInfo.mCurrentThread->mSpecific[0];
    if (socket != NULL) {
        if (socket->mUseHttps != 0) {
            return CPSi_SslConnect(socket);
        }
        return CPSi_TcpConnectRaw(socket);
    }
    return 1;
}

u32 CPS_SocWho(u16 *remotePort, u32 *localAddress) {
    CPSSoc *socket;
    socket = OSi_ThreadInfo.mCurrentThread->mSpecific[0];
    if ((socket != NULL) && ((socket->mState == 4 || (socket->mState == '\n')))) {
        if (remotePort != NULL) {
            *remotePort = socket->mRemotePort;
        }
        if (localAddress != NULL) {
            *localAddress = socket->mLocalIpReal;
        }
        return socket->mRemoteIp;
    }
    return 0;
}

void CPSi_TcpShutdownRaw(CPSSoc *socket) {
    OS_YieldThread();
    if (socket->mState == 3 || socket->mState == 4) {
        tcp_send_finack(socket, 25);
        socket->mState = 7;
        return;
    }
    if (socket->mState != 0) {
        tcp_send_ack(socket, 26);
    }
}

void CPS_TcpShutdown(void) {
    CPSSoc *socket;

    socket = OSi_ThreadInfo.mCurrentThread->mSpecific[0];
    if (socket != NULL) {
        if (socket->mUseHttps != 0) {
            CPSi_SslShutdown(socket);
        } else {
            CPSi_TcpShutdownRaw(socket);
        }
    }
}

void CPS_TcpClose(void) {
    CPSSoc *socket;
    s32 startTick;

    socket = OSi_ThreadInfo.mCurrentThread->mSpecific[0];
    if (socket != NULL) {
        startTick = OS_GetTick() >> 16;
        while (gLinkIsOn() != 0 && socket->mState != 0 && (s32) (OS_GetTick() >> 16) - startTick < 0x27) {
            yield_thread();
        }
    }
}

u8 *udp_read_raw(u32 *length, CPSSoc *socket) {
    u32 received;
    received = socket->mReceiveBufferLength;
    while (received == 0) {
        socket->mBlockType = 3;
        OS_SleepThread(0);
        received = socket->mReceiveBufferLength;
    }
    *length = received;
    return socket->mReceiveBuffer;
}

u8 *CPSi_TcpReadRaw(u32 *length, CPSSoc *socket) {
    if (socket->mReceiveBufferLength == 0 && socket->mState == 4) {
        while (socket->mReceiveBufferLength == 0 && socket->mState == 4) {
            socket->mBlockType = 2;
            OS_SleepThread(NULL);
        }
    } else {
        OS_YieldThread();
    }
    *length = socket->mReceiveBufferLength;
    if (*length != 0) {
        return socket->mReceiveBuffer;
    }
    return NULL;
}

u8 *CPS_SocRead(u32 *length) {
    CPSSoc *socket;

    socket = OSi_ThreadInfo.mCurrentThread->mSpecific[0];
    if (socket != NULL) {
        if ((u8) (socket->mState + 0xf6) <= 1) {
            return udp_read_raw(length, socket);
        }
        if (socket->mUseHttps != 0) {
            return ReadHttpsRecordsUntilBytesReceived((s32 *) length, socket);
        }
        return CPSi_TcpReadRaw(length, socket);
    }
    *length = 0;
    return NULL;
}

void CPSi_SocConsumeRaw(u32 length, CPSSoc *socket) {
    u32 interruptState;
    u32 d;
    u8 *buffer;
    u8 *source;

    interruptState = OS_DisableInterrupts();
    d = socket->mReceiveBufferLength;
    if (length >= d) {
        socket->mReceiveBufferLength = 0;
    } else {
        buffer = socket->mReceiveBuffer;
        source = buffer;
        source += length;
        socket->mReceiveBufferLength = (d -= length);
        memmove(buffer, &(*source), d);
    }
    OS_RestoreInterrupts(interruptState);
    if (socket->mState != 0xa && socket->mState != 0xb && socket->mReceiveBufferLength == 0) {
        tcp_send_ack(socket, 0x1b);
    }
}

void CPS_SocConsume(u32 length) {
    CPSSoc *socket;

    socket = OSi_ThreadInfo.mCurrentThread->mSpecific[0];
    if (socket != NULL) {
        if (socket->mUseHttps != 0) {
            SkipHttpsReceivedBytes(length, socket);
        } else {
            CPSi_SocConsumeRaw(length, socket);
        }
    }
}

s32 tcp_write_do(const u8 *buffer, s32 length, CPSSoc *socket, s32 probeFlag) {
    u32 window;
    u32 segmentLength;
    s32 ackCountSaved;
    s32 limit;
    s32 limitNow;

    if (probeFlag != 0) {
        window = 1;
    } else {
        window = socket->mRemoteWin;
    }
    ackCountSaved = socket->mAckRcvd;
    limit = ackCountSaved * 2 + 4;
    while (length != 0 && socket->mState == 4) {
        segmentLength = socket->mRemoteMss;
        if (segmentLength >= window) {
            segmentLength = window;
        }
        if (gMyMss < segmentLength) {
            segmentLength = gMyMss;
        }
        if (probeFlag == 0) {
            segmentLength &= ~1;
        }
        if (length < segmentLength) {
            segmentLength = length;
        }
        limitNow = limit + (socket->mAckRcvd - ackCountSaved);
        ackCountSaved = socket->mAckRcvd;
        limit = limitNow - 1;
        if (limitNow == 0) {
            segmentLength = 0;
        }
        if (segmentLength == 0) {
            break;
        }
        window -= segmentLength;
        send_tcp((u8 *) buffer, segmentLength, socket, 0x18, 0);
        OS_YieldThread();
        buffer += segmentLength;
        length -= segmentLength;
    }
    return segmentLength;
}

void tcp_write_do2(const u8 *buffer, s32 length, const u8 *secondBuffer, s32 secondLength, CPSSoc *socket,
                   s32 probeFlag) {
    if (tcp_write_do(buffer, length, socket, probeFlag) != 0 && secondLength != 0) {
        tcp_write_do(secondBuffer, secondLength, socket, 0);
    }
}

s32 CPSi_TcpWrite2Raw(const u8 *buffer, u32 length, const u8 *secondBuffer, s32 secondLength, void *socketArgument) {
    CPSSoc *socket;
    s32 bytesWritten;
    BOOL probeFlag;
    s32 seqNoBefore;
    u32 startTime;
    s32 ackedLength;
    u32 retryTime;

    socket = socketArgument;
    bytesWritten = 0;
    socket->mAckRcvd = 0;
    probeFlag = FALSE;
    startTime = OS_GetTick() >> 16;
    while (gLinkIsOn() != 0 && length != 0 && socket->mState == 4 &&
           (s32) ((u32) (OS_GetTick() >> 16) - startTime) < 0x9f) {
        seqNoBefore = socket->mSeqNo;
        tcp_write_do2(buffer, length, secondBuffer, secondLength, socket, probeFlag);
        retryTime = OS_GetTick() >> 16;
        do {
            yield_thread();
        } while (gLinkIsOn() != 0 && socket->mState == 4 && socket->mSeqNo != socket->mRemoteAckNo &&
                 (s32) ((u32) (OS_GetTick() >> 16) - retryTime) < 0xf &&
                 (probeFlag == FALSE || socket->mRemoteWin == 0));
        ackedLength = socket->mRemoteAckNo - seqNoBefore;
        bytesWritten += ackedLength;
        if (ackedLength != 0) {
            startTime = OS_GetTick() >> 16;
        }
        socket->mSeqNo = socket->mRemoteAckNo;
        if (socket->mState == 4 && socket->mRemoteWin == 0 && ackedLength == 0) {
            if (probeFlag == FALSE) {
                retryTime = OS_GetTick() >> 16;
                while (gLinkIsOn() != 0 && (s32) ((u32) (OS_GetTick() >> 16) - retryTime) < 0xf) {
                    yield_thread();
                    if (socket->mRemoteWin != 0) {
                        break;
                    }
                }
                if (socket->mRemoteWin == 0) {
                    probeFlag = TRUE;
                }
            }
        } else {
            probeFlag = FALSE;
        }
        if (ackedLength >= length) {
            ackedLength -= length;
            buffer = secondBuffer + ackedLength;
            length = secondLength - ackedLength;
            secondBuffer = NULL;
            secondLength = 0;
        } else {
            buffer += ackedLength;
            length -= ackedLength;
        }
    }
    return bytesWritten;
}

s32 CPSi_SocWrite2(const u8 *buffer, s32 length, const u8 *secondBuffer, s32 secondLength) {
    CPSSoc *socket;
    u8 state;
    s32 bytesWritten;

    socket = OSi_ThreadInfo.mCurrentThread->mSpecific[0];
    if (socket != NULL) {
        state = socket->mState;
        if (state == 0xa) {
            if (length != 0) {
                send_udp((u8 *) buffer, length, socket);
            }
            if (secondLength != 0) {
                send_udp((u8 *) secondBuffer, secondLength, socket);
            }
            bytesWritten = length + secondLength;
        } else if (state == 0xb) {
            if (length != 0) {
                send_ping((u8 *) buffer, length, socket);
            }
            if (secondLength != 0) {
                send_ping((u8 *) secondBuffer, secondLength, socket);
            }
            bytesWritten = length + secondLength;
        } else if (socket->mUseHttps != 0) {
            bytesWritten = SendHttpsBytesInChunks((u8 *) buffer, length, (u8 *) secondBuffer, secondLength, socket);
        } else {
            bytesWritten = CPSi_TcpWrite2Raw(buffer, length, secondBuffer, secondLength, socket);
        }
        if (gSendFailed == 0) {
            return bytesWritten;
        }
    }
    return 0;
}

s32 CPS_SocWrite(const u8 *buffer, s32 length) {
    CPSSoc *socket;
    s32 bytesWritten;

    socket = OSi_ThreadInfo.mCurrentThread->mSpecific[0];
    if (socket != NULL) {
        if (socket->mOutBufferLength != 0) {
            bytesWritten = CPSi_SocWrite2(socket->mOutBuffer, socket->mOutBufferLength, buffer, length);
            if (bytesWritten < socket->mOutBufferLength) {
                memmove(socket->mOutBuffer, socket->mOutBuffer + bytesWritten, socket->mOutBufferLength - bytesWritten);
                socket->mOutBufferLength -= bytesWritten;
                return 0;
            }
            bytesWritten -= socket->mOutBufferLength;
            socket->mOutBufferLength = 0;
            return bytesWritten;
        }
        return CPSi_SocWrite2(buffer, length, NULL, 0);
    }
    return 0;
}

s32 CPS_SocGetLength(void) {
    CPSSoc *socket;
    s32 count;

    socket = OSi_ThreadInfo.mCurrentThread->mSpecific[0];
    if (socket != NULL) {
        if (socket->mUseHttps != 0) {
            count = ReadHttpsRecordIfBufferedAndGetUnreadByteCount(socket);
        } else {
            count = socket->mReceiveBufferLength;
        }
        if (count == 0 && socket->mState != 4 && (u8) (socket->mState + 0xf6) > 1) {
            return -1;
        }
        return count;
    }
    return 0;
}

void CPS_SocFlush(void) {
    CPSSoc *socket;
    socket = OSi_ThreadInfo.mCurrentThread->mSpecific[0];
    if ((socket != NULL) && (socket->mOutBufferLength != 0)) {
        CPSi_SocWrite2((socket->mOutBuffer), socket->mOutBufferLength, NULL, 0);
        socket->mOutBufferLength = 0;
    }
}

void set_fixed_ip(void) {
    s32 startTick;

    gDhcpCallback();
    if (CPSMyIp != 0) {
        send_arprequest(CPSMyIp);
        OS_Sleep(100);
        send_arprequest(CPSMyIp);
        startTick = OS_GetTick() >> 16;
        while (gLinkIsOn() != 0 && (s32) (OS_GetTick() >> 16) - startTick < 0x17) {
            if (gIpConflict != 0) {
                reset_network_vars(4);
                return;
            }
            OS_Sleep(100);
        }
    }
}

void scavenger(void) {
    u32 dhcpDelay;
    u32 dhcpPhase;
    u32 now;
    BOOL first;
    s32 e;
    s32 i;
    OSThread *thread;
    CPSSoc *socket;
    CPSArpCache *arpEntry;
    CPSFragTable *fragment;

    gScavengerForceExit = 0;
    MI_CpuFill8(&gScavengerSoc, 0, 0x64);
    gScavengerSoc.mReceiveBufferSize = 0x180;
    gScavengerSoc.mReceiveBuffer = gScavengerReceiveBuffer;
    gScavengerSoc.mSendBufferSize = 0x180;
    gScavengerSoc.mSendBuffer = gScavengerSendBuffer;
    CPS_SocRegister(&gScavengerSoc);
    dhcpPhase = 0;
    first = TRUE;
    dhcpDelay = 1;
    CPSNoIpReason = 1;
    while (1) {
        OS_Sleep(1000);
        if (gScavengerForceExit != 0) {
            break;
        }
        now = OS_GetTick() >> 16;
        if (gLinkIsOn() != 0) {
            dhcpDelay--;
            if (dhcpDelay == 0) {
                if ((gCPSMode & 1) != 0) {
                    if (dhcpPhase == 0) {
                        set_fixed_ip();
                        dhcpPhase = 1;
                    }
                } else {
                    switch (dhcpPhase) {
                        case 0:
                            if (first != FALSE) {
                                CPSNoIpReason = 2;
                                first = FALSE;
                            }
                            if (dhcp_discover_server() == 0 || dhcp_request_server(&dhcpDelay, 0) == FALSE) {
                                set_fixed_ip();
                                dhcpPhase = 3;
                            } else {
                                dhcpPhase = 1;
                            }
                            break;
                        case 1:
                            if (dhcp_request_server(&dhcpDelay, 1) == FALSE && dhcpDelay < 0x3c) {
                                dhcpPhase = 2;
                            }
                            break;
                        case 2:
                            if (dhcp_request_server(&dhcpDelay, 2) != FALSE) {
                                dhcpPhase = 1;
                            } else if (dhcpDelay < 0x3c) {
                                reset_network_vars(3);
                                dhcpPhase = 0;
                                dhcpDelay = 1;
                            }
                            break;
                        case 3:
                            break;
                    }
                }
            }
        } else {
            reset_network_vars(1);
            dhcpPhase = 0;
            dhcpDelay = 1;
        }
        i = 0;
        arpEntry = gArpCache;
        for (; i < 8; i++) {
            if (arpEntry->mIp != 0 && (s16) (now - arpEntry->mWhen) > 0x3bd) {
                arpEntry->mIp = 0;
            }
            arpEntry++;
        }
        thread = OSi_ThreadInfo.mListHead;
        if (thread != NULL) {
            do {
                socket = thread->mSpecific[0];
                if (socket != NULL && socket->mThread != NULL) {
                    if (socket->mState == 3 && (s32) (now - socket->mStateStartTime) > 0x27) {
                        socket->mState = 1;
                        socket->mRemotePort = socket->mRemotePortBound;
                        socket->mRemoteIp = socket->mRemoteIpBound;
                    } else if (socket->mState == 2 && (s32) (now - socket->mStateStartTime) > 0x27 &&
                               socket->mBlockType == 1) {
                        socket->mState = 0;
                        socket->mBlockType = 0;
                        OS_WakeupThreadDirect(socket->mThread);
                    }
                }
                thread = thread->mNext;
            } while (thread != NULL);
        }
        i = 0;
        fragment = gFragTable;
        for (; i < 8; i++) {
            if (fragment->mFrags != 0 && (s32) (now - fragment->mWhen) > 0xef) {
                CPSiFree(fragment->mBuf);
                fragment->mFrags = 0;
            }
            fragment++;
        }
        CPSi_SslPeriodical(now);
        if (gScavengerCallback != NULL) {
            gScavengerCallback();
        }
    }
    if ((gCPSMode & 1) == 0 && dhcpPhase != 3) {
        dhcp_release_server();
    }
    CPS_SocUnRegister();
}

u8 *dhcp_setcommon(u8 *buffer, u8 type, u32 *transactionIdOut) {
    u32 transactionId;

    MI_CpuFill8(buffer, 0, 0xec);
    *(u16 *) buffer = 0x101;
    buffer[2] = 6;
    CPSiRand32ctx[0] = (s64) CPSiRand32ctx[1] * (s64) CPSiRand32ctx[0] + CPSiRand32ctx[2];
    transactionId = CPSiRand32ctx[0] >> 32;
    if (transactionIdOut != NULL) {
        *transactionIdOut = transactionId;
    }
    *OFFSET_PTR(u16, buffer, 4) = (u16) (transactionId >> 16) >> 8 | (u16) (transactionId >> 16) << 8;
    *OFFSET_PTR(u16, buffer, 6) = (u16) transactionId >> 8 | (u16) transactionId << 8;
    *OFFSET_PTR(u16, buffer, 0xc) = (u16) (CPSMyIp >> 16) >> 8 | (u16) (CPSMyIp >> 16) << 8;
    *OFFSET_PTR(u16, buffer, 0xe) = (u16) CPSMyIp >> 8 | (u16) CPSMyIp << 8;
    MI_CpuCopy8(CPSMyMac, buffer + 0x1c, 6);
    *(u16 *) (buffer + 0xec) = 0x8263;
    *(u16 *) (buffer + 0xee) = 0x6353;
    *(u16 *) (buffer + 0xf0) = 0x135;
    buffer[0xf2] = type;
    buffer[0xf3] = 0x3d;
    buffer[0xf4] = 7;
    buffer[0xf5] = 1;
    MI_CpuCopy8(CPSMyMac, buffer + 0xf6, 6);
    buffer[0xfc] = 0xc;
    buffer[0xfd] = 10;
    MI_CpuCopy8(gDhcpHostname, buffer + 0xfe, 10);
    buffer[0x108] = 0x37;
    buffer[0x109] = 3;
    buffer[0x10a] = 1;
    buffer[0x10b] = 3;
    buffer[0x10c] = 6;
    return buffer + 0x10d;
}

u8 *pad_mem(u8 pattern, u32 minimum, u8 *position, u32 currentLength) {
    if (currentLength < minimum) {
        MI_CpuFill8(position, pattern, minimum - currentLength);
        position = position + (minimum - currentLength);
    }
    return position;
}
