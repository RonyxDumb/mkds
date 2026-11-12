#include "00/Lib/GameSpy/code_0218e2dc.h"

#include "00/unk_021b2000.h"
#include "os_tick.h"
#include "code_02134398.h"
#include "00/unk_021b4000.h"
#include "00/code_021a88a8.h"
#include "00/Lib/GameSpy/code_021a3a18.h"
#include "00/code_021a8aa8.h"
#include "00/code_021a740c.h"
#include "00/unk_021b6000.h"
#include "00/code_021a7000.h"
#include "00/unk_021b5000.h"
#include "code_0214d018.h"
#include "03/Net/essid_packet_steps.h"
#include "00/code_021a6fa8.h"
#include "00/code_021a86bc.h"
#include "00/Lib/DWC/dwc_memfunc.h"
#include "00/code_021a8dd8.h"
#include "code_02139f70.h"
#include "code_0214177c.h"
#include "00/Lib/GameSpy/code_0218f960.h"
#include "00/code_02190000.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/Lib/GameSpy/code_0218d818.h"
#include "00/Lib/GameSpy/code_021965a0.h"
#include "00/Lib/GameSpy/code_02190ff8.h"
#include "00/code_02196000.h"
#include "00/Lib/GameSpy/code_021906e4.h"
#include "00/Lib/GameSpy/code_02196590.h"
#include "00/Lib/GameSpy/code_02196594.h"
#include "00/unk_021b23b0.h"
#include "00/Lib/NitroWiFi/code_021a6d5c.h"
#include "code_0213a460.h"

static char *aliases = NULL;
static s32 GSINitroErrno;

#pragma opt_propagation off

u32 GetElapsedMilliseconds(void) {
    u64 ticks;
    if (OS_IsTickAvailable() != 1) {
        AssertionFailed(gTickAvailableAssertion, gNonportFileName, NULL, 0x109);
    }
    ticks = OS_GetTick();
    return (ticks << 6) / 0x82ea;
}

void msleep(u32 msec) {
    u32 sleepMsec = msec;
    u32 unusedValue;
    OS_Sleep(sleepMsec);
}

void SocketStartUp(void) {}

void SocketShutDown(void) {}

void *goastrdup(const char *src) {
    void *res;
    if (src == NULL) {
        return NULL;
    }
    res = DWCi_GsMalloc(strlen(src) + 1);
    if (res != NULL) {
        strcpy(res, src);
    }
    return res;
}

s8 *_strlwr(s8 *string) {
    s32 character;
    s8 *startPtr;
    startPtr = string;
    character = *string;
    if (character != 0) {
        do {
            if (character >= 0 && character < 0x80) {
                character = gLowerCaseMap[character];
            }
            *string = character;
            string++;
            character = *string;
        } while (character != 0);
    }
    return startPtr;
}

BOOL SetSockBlocking(s32 sock, s32 isblocking) {
    s32 flags;
    flags = SOC_Fcntl((SOCLSocket *) sock, 3, 0);
    if (isblocking != 0) {
        flags = flags & ~4;
    } else {
        flags = flags | 4;
    }
    return SOC_Fcntl((SOCLSocket *) sock, 4, flags) == 0;
}

s32 SetReceiveBufferSize(s32 sock, u32 size) {
    return setsockopt(sock, 0xffff, 0x1002, &size, 4) != -1 ? 1 : 0;
}

s32 SetSendBufferSize(s32 sock, u32 size) {
    return setsockopt(sock, 0xffff, 0x1001, &size, 4) != -1 ? 1 : 0;
}

s32 GetReceiveBufferSize(s32 sock) {
    s32 size;
    s32 len = 4;
    s32 rcode = getsockopt(sock, 0xffff, 0x1002, &size, &len);
    return rcode != -1 ? size : -1;
}

s32 GetSendBufferSize(s32 sock) {
    s32 size;
    s32 len = 4;
    s32 rcode = getsockopt(sock, 0xffff, 0x1001, &size, &len);
    return rcode != -1 ? size : -1;
}

s32 GSISocketSelect(s32 theSocket, u32 *theReadFlag, u32 *theWriteFlag, u32 *theExceptFlag) {
    SOCPollFD pollEntry;
    s32 pollResult;
    pollEntry.mFd = theSocket;
    pollEntry.mEvents = 0;
    if (theReadFlag != NULL) {
        pollEntry.mEvents |= 1;
    }
    if (theWriteFlag != NULL) {
        pollEntry.mEvents |= 8;
    }
    pollEntry.mRevents = 0;
    pollResult = SOC_Poll(&pollEntry, 1, 0);
    if (pollResult < 0) {
        return -1;
    }
    if (theReadFlag != NULL) {
        if (pollResult > 0 && (pollEntry.mRevents & 0x41) != 0) {
            *theReadFlag = 1;
        } else {
            *theReadFlag = 0;
        }
    }
    if (theWriteFlag != NULL) {
        if (pollResult > 0 && (pollEntry.mRevents & 8) != 0) {
            *theWriteFlag = 1;
        } else {
            *theWriteFlag = 0;
        }
    }
    if (theExceptFlag != NULL) {
        if (pollResult > 0 && (pollEntry.mRevents & 0x20) != 0) {
            *theExceptFlag = 1;
        } else {
            *theExceptFlag = 0;
        }
    }
    return pollResult;
}

u32 CanReceiveOnSocket(u32 sock) {
    int selectResult;
    u32 readFlag[1];
    readFlag[0] = 0;
    selectResult = GSISocketSelect((u32) sock, (readFlag), NULL, NULL);
    if (selectResult == 1) {
        return readFlag[0];
    }
    return 0;
}

u32 CanSendOnSocket(u32 sock) {
    int selectResult;
    u32 writeFlag[1];
    writeFlag[0] = 0;
    selectResult = GSISocketSelect((u32) sock, NULL, (writeFlag), NULL);
    if (selectResult == 1) {
        return writeFlag[0];
    }
    return 0;
}

SOCHostEnt *getlocalhost(void) {
    static SOCHostEnt loopbackEntry;
    static u32 *addrList[6];
    static u32 ips[5];

    loopbackEntry.mName = gLocalhostName;
    loopbackEntry.mAliases = (u8 *) &aliases;
    loopbackEntry.mAddrType = 2;
    loopbackEntry.mLength = 0;
    loopbackEntry.mAddrList = addrList;
    ips[0] = 0;
    SOC_U32to4U8(SOCL_GetHostID(), (u8 *) &ips[0]);
    if (ips[0] == 0) {
        return NULL;
    }
    addrList[0] = &ips[0];
    loopbackEntry.mLength = 4;
    addrList[1] = NULL;
    return &loopbackEntry;
}

BOOL IsPrivateIP(u32 *addr) {
    u32 rawAddress = *addr;
    u32 hostAddress = ((rawAddress << 24) & 0xff000000) |
                      (((rawAddress << 8) & 0xff0000) | (((rawAddress >> 24) & 0xff) | ((rawAddress >> 8) & 0xff00)));
    s32 firstByte = (hostAddress >> 24) & 0xff;
    s32 secondByte = (hostAddress >> 16) & 0xff;
    if (firstByte == 10) {
        return TRUE;
    }
    if (firstByte == 172 && secondByte >= 16 && secondByte <= 31) {
        return TRUE;
    }
    if (firstByte == 192 && secondByte == 168) {
        return TRUE;
    }
    return FALSE;
}

s32 CheckRcode(s32 result, s32 fallback) {
    if (result < 0) {
        GSINitroErrno = result;
        result = fallback;
    }
    return result;
}

s32 OpenNetSocket(s32 domain, s32 type, s32 protocol) {
    return CheckRcode(SOC_Socket(domain, type, protocol), -1);
}

s32 closesocket(s32 descriptor) {
    return CheckRcode(SOC_Close(descriptor), -1);
}

s32 shutdown(s32 descriptor, s32 how) {
    return CheckRcode(SOC_Shutdown(descriptor), -1);
}

s32 bind(s32 sock, void *addr, s32 len) {
    SOCSockAddr *addrRecord = addr;
    SOCSockAddr boundAddr;
    if (*(u16 *) addrRecord->mData == 0) {
        return 0;
    }
    boundAddr = *addrRecord;
    boundAddr.mLen = len;
    return CheckRcode(SOC_Bind(sock, &boundAddr), -1);
}

s32 connect(s32 sock, void *addr, s32 len) {
    SOCSockAddr target = *(SOCSockAddr *) addr;
    target.mLen = len;
    return CheckRcode(SOC_Connect((SOCLSocket *) sock, (SOCSockAddrIn *) &target), -1);
}

s32 listen(s32 descriptor) {
    return CheckRcode(SOC_Listen(descriptor), -1);
}

s32 AcceptConnection(s32 sock, void *addr, s32 *len) {
    u8 *addrBytes = addr;
    s32 *lenPointer = len;
    s32 inputLen = *lenPointer;
    s32 rcode;
    *addrBytes = inputLen;
    rcode = SOC_Accept((SOCLSocket *) sock, (SOCSockAddrIn *) addrBytes, inputLen);
    *lenPointer = *addrBytes;
    return CheckRcode(rcode, -1);
}

s32 recv(s32 sock, void *buf, s32 len, s32 flags) {
    return CheckRcode(SOC_Recv(sock, buf, len, flags), -1);
}

s32 recvfrom(s32 sock, void *buf, s32 len, s32 flags, void *addr, s32 *fromlen) {
    u8 *addrBytes = addr;
    s32 *fromlenPointer = fromlen;
    s32 recvResult;
    *addrBytes = *fromlenPointer;
    recvResult = SOC_RecvFrom(sock, buf, len, flags, addrBytes);
    *fromlenPointer = *addrBytes;
    return CheckRcode(recvResult, -1);
}

s32 send(s32 sock, void *buf, s32 len, s32 flags) {
    return CheckRcode(SOC_Send(sock, buf, len, flags), -1);
}

s32 sendto(s32 sock, void *buf, s32 len, s32 flags, void *addr, s32 tolen) {
    SOCSockAddr destAddr;
    __memcpy(&destAddr, addr, sizeof(destAddr));
    destAddr.mLen = tolen;
    return CheckRcode(SOC_SendTo(sock, buf, len, flags, &destAddr), -1);
}

s32 getsockopt(s32 sock, s32 level, s32 optname, void *optval, s32 *optlen) {
    MI_CpuFill8(optval, 0, *optlen);
    return CheckRcode(0, -1);
}

u32 setsockopt(s32 sock, s32 level, s32 optname, void *optval, s32 optlen) {
    u32 optResult;
    u32 errCode;
    u32 unusedValue;
    optResult = 0u;
    errCode = ~(optResult);
    unusedValue = (u32) &CheckRcode;
    optResult = CheckRcode(optResult, errCode);
    return optResult;
}

s32 getsockname(u32 sock, void *addr, u32 *len) {
    u32 addrBase = (u32) addr;
    u32 lenBase = (u32) len;
    u32 lenValue = (*(u32 *) ((lenBase) + (0)));
    u32 nameResult;
    u32 addrLen;
    u32 errCode;
    u32 result;
    *(u8 *) ((addrBase) + (0)) = lenValue;
    nameResult = SOC_GetSockName(sock, addr);
    addrLen = (*(u8 *) ((addrBase) + (0)));
    *(u32 *) ((lenBase) + (0)) = addrLen;
    errCode = ~(0x0u);
    result = CheckRcode(nameResult, errCode);
    return result;
}

u32 inet_addr(u32 name) {
    int parseResult;
    u32 addr[1];
    parseResult = SOC_InetAtoN(name, addr);
    if (parseResult == 0) {
        return 0xffffffff;
    }
    return addr[0];
}

u32 GOAGetLastError(s32 sock) {
    return GSINitroErrno;
}

u32 GetUnixTime(u32 *timer) {
    u32 seconds;
    if (OS_IsTickAvailable() != 1) {
        AssertionFailed(gTickAvailableAssertion, gNonportFileName, NULL, 0x667);
    }
    seconds = (OS_GetTick() << 6) / 0x1ff6210;
    if (timer != NULL) {
        *timer = seconds;
    }
    return seconds;
}

u32 nextlongrand(u32 seed) {
    u32 lowProduct = (seed & 0xffff) * 0x41a7;
    u32 highProduct = (seed >> 16) * 0x41a7;
    u32 next = lowProduct + ((highProduct & 0x7fff) << 16);
    if (next > 0x7fffffff) {
        next = (next & 0x7fffffff) + 1;
    }
    next += highProduct >> 15;
    if (next > 0x7fffffff) {
        next = (next & 0x7fffffff) + 1;
    }
    return next;
}
