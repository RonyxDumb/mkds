#include "00/Lib/NitroWiFi/socl_startup.h"
#include "00/Lib/DWC/socket_config.h"

#include "00/Lib/NitroWiFi/socl_startup_commands.h"
#include "03/Net/essid_packet_steps.h"
#include "00/Lib/NitroWiFi/socket_command_packet.h"
#include "00/Lib/NitroWiFi/link_status.h"
#include "00/Lib/NitroWiFi/access_point_list.h"
#include "00/Lib/NitroWiFi/cpsif.h"
#include "00/Lib/NitroWiFi/socket_create_call.h"
#include "00/Lib/NitroWiFi/dns_resolver_setting.h"
#include "00/Lib/CPS/network.h"
#include "os_thread.h"
#include "cpu_copy_fill.h"
#include "00/Lib/CPS/cps_globals.h"
#include "00/Lib/CPS/https_session_upkeep.h"
#include "mb_data.h"
#include "00/Lib/wifi_library_globals.h"
#include "startup_entry.h"
#include "signed_int_divide.h"
#include "reset_interrupt_enable.h"
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
#include "00/Lib/DWC/http_thread.h"
#include "00/Lib/NitroWiFi/socket_read_command.h"
#include "00/Lib/NitroWiFi/socket_shutdown_all.h"
#include "00/Lib/NitroWiFi/socket_validity.h"
#include "00/Lib/GameSpy/socket_calls.h"
#include "00/Lib/GameSpy/query_reporting.h"
#include "os_printf.h"
#include "std_string.h"
#include "00/Lib/NitroWiFi/socket_api_calls.h"
#include "build_info_layout.h"

u32 SOCLiYieldWait;
SOCLConfig *SOCLiConfigPtr;
SOCLSocket *SOCLiUDPSendSocket;
u32 SOCLiRequestedIP;
u32 SOCLiDhcpState;
CPSConfig SOCLiCPSConfig;

s32 SOCL_Startup(SOCLConfig *config) {
    OSi_ReferSymbol(BuildInfo.mWifi);
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
