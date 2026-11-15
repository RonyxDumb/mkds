#include "00/Lib/NitroWiFi/socl_startup.h"
#include "00/Lib/DWC/code_0218a064.h"

#include "00/Lib/NitroWiFi/socl_startup_commands.h"
#include "03/Net/essid_packet_steps.h"
#include "00/Lib/NitroWiFi/code_021a6fb4.h"
#include "00/Lib/NitroWiFi/code_021a6d1c.h"
#include "00/Lib/NitroWiFi/code_021a669c.h"
#include "00/Lib/NitroWiFi/cpsif.h"
#include "00/Lib/NitroWiFi/code_021a73d8.h"
#include "00/Lib/NitroWiFi/code_021a8878.h"
#include "00/Lib/CPS/network.h"
#include "os_thread.h"
#include "code_0214d018.h"
#include "00/Lib/CPS/cps_globals.h"
#include "00/Lib/CPS/code_021a91b4.h"
#include "mb_data.h"
#include "00/Lib/wifi_library_globals.h"
#include "code_02000b44.h"
#include "code_02133048.h"
#include "code_0200fc8c.h"
#include "00/Lib/NitroWiFi/code_021a6fa8.h"
#include "00/Lib/CPS/code_021a88a8.h"
#include "code_0200e77c.h"
#include "00/Lib/wifi_library_work_objects.h"
#include "code_0200edc0.h"
#include "00/Lib/NitroWiFi/code_021a72c4.h"
#include "00/Lib/NitroWiFi/code_021a8aa8.h"
#include "00/Lib/NitroWiFi/code_021a78a4.h"
#include "00/Lib/NitroWiFi/code_021a740c.h"
#include "00/Lib/NitroWiFi/code_021a7bfc.h"
#include "00/Lib/DWC/code_02186d04.h"
#include "00/Lib/NitroWiFi/code_021a7bc8.h"
#include "00/Lib/NitroWiFi/code_021a86bc.h"
#include "00/Lib/NitroWiFi/code_021a8a80.h"
#include "00/Lib/GameSpy/code_0218e2dc.h"
#include "00/Lib/GameSpy/code_021a3a18.h"
#include "os_printf.h"
#include "std_string.h"
#include "00/Lib/NitroWiFi/code_021a8a28.h"

u32 SOCLiYieldWait;
SOCLConfig *SOCLiConfigPtr;
SOCLSocket *SOCLiUDPSendSocket;
u32 SOCLiRequestedIP;
u32 SOCLiDhcpState;
CPSConfig SOCLiCPSConfig;

s32 SOCL_Startup(SOCLConfig *config) {
    OSi_ReferSymbol(0x2000bbc);
    if (SOCLiConfigPtr != NULL) {
        return 0;
    }
    SOCLiConfigPtr = config;
    SOCLi_StartupCPS();
    return SOCLi_StartupSOCL();
}

s32 SOCLi_StartupSOCL(void) {
    s32 result;

    result = SOCLi_StartupCommandPacketQueue(SOCLiConfigPtr->mCmdPacketMax);
    if (result >= 0) {
        SOCLiUDPSendSocket = (SOCLSocket *) SOCL_CreateSocket(&SOCLSocketParamUDPSend);
    }
    return result;
}

void SOCLi_StartupCPS(void) {
    CPSConfig *cfgBlock = &SOCLiCPSConfig;
    SOCLConfig *config = SOCLiConfigPtr;
    s32 value;
    s32 rwin;

    MI_CpuFill8(cfgBlock, 0, sizeof(CPSConfig));
    cfgBlock->mAlloc = config->mAlloc;
    cfgBlock->mFree = config->mFree;
    cfgBlock->mLinkIsOn = SOCL_LinkIsOn;
    cfgBlock->mRandomSeed = 0;
    cfgBlock->mYieldWait = SOCLiYieldWait;
    if (config->mLanBufLen != 0) {
        cfgBlock->mLanBufLen = config->mLanBufLen;
    } else {
        cfgBlock->mLanBufLen = 0x4000;
    }
    if (config->mLanBuf != NULL) {
        cfgBlock->mLanBuf = config->mLanBuf;
    } else {
        cfgBlock->mLanBuf = SOCLiConfigPtr->mAlloc(cfgBlock->mLanBufLen);
    }
    value = config->mMtu;
    if (value == 0) {
        value = 0x240;
    }
    rwin = config->mRwin;
    if (rwin == 0) {
        rwin = 0x10c0;
    }
    cfgBlock->mMyMss = value - 0x28;
    SOCLSocketParamTCP.mRcvbufSize = rwin;
    SOCLSocketParamTCP.mRcvbufConsumeMin = rwin / 2;
    CPSMyIp = 0;
    if (config->mUseDhcp != 0) {
        SOCLiDhcpState = 1;
        cfgBlock->mMode = 0;
        cfgBlock->mDhcpCallback = SOCLi_DhcpTimeout;
        cfgBlock->mRequestedIp = SOCLiRequestedIP;
    } else {
        SOCLiDhcpState = 0;
        cfgBlock->mMode = 1;
        cfgBlock->mDhcpCallback = SOCLi_SetMyIP;
    }
    value = config->mCpsThreadPriority;
    if (value == 0) {
        value = 0xb;
    }
    CPS_SetThreadPriority(value);
    WCM_SetRecvDCFCallback(CPSi_RecvCallbackFunc);
    CPS_SetScavengerCallback(SOCLi_TrashSocket);
    CPS_Startup(cfgBlock);
}

void SOCLi_SetMyIP(void) {
    SOCLConfig *config = SOCLiConfigPtr;

    CPSMyIp = config->mMyIp;
    CPSNetMask = config->mNetMask;
    CPSGatewayIp = config->mGatewayIp;
    CPSDnsIp[0] = config->mDnsFirstIp;
    CPSDnsIp[1] = config->mDnsSecondIp;
    SOCLiDhcpState |= 2;
}

void SOCLi_DhcpTimeout(void) {
    SOCLiDhcpState |= 2;
}
