#include "00/Lib/NitroWiFi/wireless_connection_manager.h"
#include "00/Lib/DWC/access_point_search.h"
#include "00/Lib/DWC/access_point_manager.h"
#include "00/Lib/wifi_library_globals.h"
#include "00/Lib/DWC/access_point_state.h"
#include "00/Lib/DWC/access_point_connect.h"
#include "00/Lib/DWC/access_point_scan.h"
#include "00/Lib/DWC/stealth_search_check.h"
#include "00/Lib/DWC/address_convert.h"
#include "00/Lib/NitroWiFi/dns_resolver_setting.h"
#include "00/Lib/NitroWiFi/socket_api_prototypes.h"
#include "00/Lib/NitroWiFi/access_point_search_defaults.h"
#include "tick_counter.h"
u32 ConvNetMask(s32 prefixLength) {
    s32 shiftCount;
    u32 mask;

    prefixLength = 0x20 - prefixLength;
    shiftCount = 0;
    mask = ~shiftCount;
    for (; shiftCount < prefixLength; shiftCount++) {
        mask <<= 1;
    }
    return ((mask << 24) & 0xff000000) | (((mask << 8) & 0xff0000) | (((mask >> 24) & 0xff) | ((mask >> 8) & 0xff00)));
}

void CheckSetDNS(ACWORK *work) {
    DWCMemPage *info;
    s32 dnsSum;
    u32 dns1;
    u32 dns2;

    if (work->mConnectApType < AUTO_CONNECT_AP_TYPE_NWCUSBAP_SSID) {
        info = &work->mUserInfo[DWCi_ConvConnectAPType(work->mConnectApType)];
        dnsSum = info->mDns1[3] + (info->mDns1[2] + (info->mDns1[0] + info->mDns1[1]));
        if (info->mIp[0] == 0 && dnsSum != 0) {
            dns1 = ConvAddress(info->mDns1);
            dns2 = ConvAddress(info->mDns2);
            SOC_SetResolver(&dns1, &dns2);
        }
    }
}

u8 DWCi_AC_Start(void) {
    u32 wcmPhase;
    ACWORK *work;
    WCMConfig config;
    s32 result;

    wcmPhase = WCM_GetPhase();
    work = DWCi_AC_GetMemPtr(AC_MEM_WORK);
    if (wcmPhase == WIFI_LINK_PHASE_STOPPED) {
        config.mDmaNo = work->mDmaNo;
        config.mPbdBuffer = NULL;
        config.mNbdBuffer = 0;
        config.mNbdMode = 0;
        DWCi_AC_MakeSearchList(AC_SEARCH_LIST_AROUND);
        result = WCM_StartupAsync(&config, (void (*)(WCMNotice *)) DWCi_AC_CallBackWCM);
        if (result == 1 || result >= 4) {
            DWCi_AC_SetError(1);
            return AC_PHASE_ERROR;
        }
    } else {
        return AC_PHASE_START;
    }
    return AC_PHASE_STARTING_UP;
}

u32 DWCi_AC_SearchAP(void) {
    ACWORK *work;
    u32 phase;
    u32 wcmPhase;

    work = DWCi_AC_GetMemPtr(AC_MEM_WORK);
    phase = DWCi_AC_GetPhase();
    wcmPhase = WCM_GetPhase();
    if (phase == AC_PHASE_STARTING_UP && wcmPhase == WIFI_LINK_PHASE_READY) {
        phase = SearchStart(work);
    } else if (phase == AC_PHASE_SEARCH_DONE) {
        phase = SearchEndCheck(work, phase);
    } else if (wcmPhase == WIFI_LINK_PHASE_READY || wcmPhase == WIFI_LINK_PHASE_SEARCHING) {
        phase = SearchEndCheck(work, phase);
        if (phase != AC_PHASE_CONNECT_START) {
            if (phase == AC_PHASE_SEARCH_AROUND) {
                phase = SearchAround(work);
            } else if (phase == AC_PHASE_SEARCH_DIFFER_CHANNEL) {
                phase = SearchDifferChannel(work);
            } else if (phase == AC_PHASE_SEARCH_STEALTH) {
                phase = SearchStealth(work);
            }
        }
    }
    return phase;
}

void DWCi_AC_SetStealthChannel(u32 channel) {
    ACWORK *work;

    work = DWCi_AC_GetMemPtr(AC_MEM_WORK);
    if (channel > 0xd) {
        channel = 0xd;
    }
    work->mStealthChannel |= 1 << (channel - 1);
}

s8 DWCi_AC_GetStealthChannel(s32 index) {
    ACWORK *work;
    u16 mask;
    u8 channel;
    u8 found;

    work = DWCi_AC_GetMemPtr(AC_MEM_WORK);
    mask = work->mStealthChannel;
    if (mask == 0) {
        return -1;
    }
    found = channel = 0;
    for (; channel < 0xd; channel++) {
        if (BIT_IS_SET(mask, channel)) {
            if (found == index) {
                return channel;
            }
            found++;
        }
    }
    return -1;
}

void DWCi_AC_SearchReStart(u32 phase) {
    ACWORK *work;

    work = DWCi_AC_GetMemPtr(AC_MEM_WORK);
    switch (phase) {
        case AC_PHASE_SEARCH_AROUND:
            work->mTimeOut = OS_GetTick();
            ScanStart(WCM_Bssid_Any, WCM_Essid_Any, work->mSearchChannel, 0x200000);
            break;
        case AC_PHASE_SEARCH_DIFFER_CHANNEL:
            work->mTimeOut = OS_GetTick();
            ScanStart(WCM_Bssid_Any, work->mSearchList[work->mSearchListNo].mSsid,
                      work->mSearchList[work->mSearchListNo].mChannel, 0x300000);
            break;
        case AC_PHASE_SEARCH_STEALTH:
            work->mTimeOut = OS_GetTick();
            ScanStart(WCM_Bssid_Any, work->mSearchList[work->mSearchListNo].mSsid, work->mSearchChannel, 0x300000);
            break;
    }
}

u32 SearchStart(ACWORK *work) {
    work->mTimeOut = OS_GetTick();
    work->mSearchChannel = 0;
    work->mTimeOut = OS_GetTick();
    ScanStart(WCM_Bssid_Any, WCM_Essid_Any, work->mSearchChannel, 0x200000);
    return AC_PHASE_SEARCH_AROUND;
}

u32 SearchAround(ACWORK *work) {
    if ((OS_GetTick() - work->mTimeOut) * 64 / 0x82ea >= 0x12c) {
        work->mSearchChannel += 2;
        if (work->mSearchChannel >= 0xd) {
            return NextSearchCheck(work, 3);
        }
        work->mTimeOut = OS_GetTick();
        ScanStart(WCM_Bssid_Any, WCM_Essid_Any, work->mSearchChannel, 0x200000);
    }
    return AC_PHASE_SEARCH_AROUND;
}

u32 SearchAround2ndLap(ACWORK *work) {
    work->mCount = 0;
    work->mAroundCount = work->mAroundCount + 1;
    DWCi_AC_MakeSearchList(AC_SEARCH_LIST_AROUND);
    work->mSearchChannel = 1;
    return AC_PHASE_SEARCH_AROUND;
}

u32 SearchDifferChannel(ACWORK *work) {
    if ((OS_GetTick() - work->mTimeOut) * 64 / 0x82ea >= 0x96 ||
        work->mSearchList[work->mSearchListNo].mBeaconReceived == 1) {
        work->mSearchList[work->mSearchListNo].mBeaconReceived = 0;
        work->mSearchListNo++;
        if (work->mSearchListNum <= work->mSearchListNo) {
            work->mSearchListNo = 0;
            return NextSearchCheck(work, AC_PHASE_SEARCH_DIFFER_CHANNEL);
        }
        work->mTimeOut = OS_GetTick();
        ScanStart(WCM_Bssid_Any, work->mSearchList[work->mSearchListNo].mSsid,
                  work->mSearchList[work->mSearchListNo].mChannel, 0x300000);
    }
    return AC_PHASE_SEARCH_DIFFER_CHANNEL;
}

u32 SearchStealth(ACWORK *work) {
    if ((OS_GetTick() - work->mTimeOut) * 64 / 0x82ea >= 0x96 ||
        work->mSearchList[work->mSearchListNo].mBeaconReceived == 1) {
        work->mSearchList[work->mSearchListNo].mBeaconReceived = 0;
        work->mSearchListNo++;
        if (work->mSearchListNum == work->mSearchListNo) {
            work->mCount++;
            work->mSearchListNo = 0;
            work->mSearchChannel = DWCi_AC_GetStealthChannel(work->mCount);
        }
        if (work->mSearchChannel < 0) {
            work->mCount = 0;
            return NextSearchCheck(work, AC_PHASE_SEARCH_STEALTH);
        }
        work->mTimeOut = OS_GetTick();
        ScanStart(WCM_Bssid_Any, work->mSearchList[work->mSearchListNo].mSsid, work->mSearchChannel, 0x300000);
    }
    return AC_PHASE_SEARCH_STEALTH;
}

u32 NextSearchCheck(ACWORK *work, u32 phase) {
    switch (phase) {
        case AC_PHASE_SEARCH_AROUND:
            if (work->mFindListNum != 0 || work->mStealthChannel != 0) {
                if (DWCi_AC_MakeSearchList(AC_SEARCH_LIST_DIFFER_CHANNEL) != 0) {
                    phase = AC_PHASE_SEARCH_DIFFER_CHANNEL;
                } else {
                    phase = CheckStartStealthSearch(work);
                }
            } else if (work->mAroundCount < 1) {
                phase = SearchAround2ndLap(work);
            } else {
                phase = AC_PHASE_SEARCH_DONE;
            }
            break;
        case AC_PHASE_SEARCH_DIFFER_CHANNEL:
            phase = CheckStartStealthSearch(work);
            break;
        case AC_PHASE_SEARCH_STEALTH:
            if (work->mAroundCount < 1) {
                phase = SearchAround2ndLap(work);
            } else {
                phase = AC_PHASE_SEARCH_DONE;
            }
            break;
    }
    DWCi_AC_SearchReStart(phase);
    return phase;
}

u32 SearchEndCheck(ACWORK *work, u32 phase) {
    u8 findIndex;
    u8 findListNum;

    if (phase == AC_PHASE_ERROR) {
        return phase;
    }
    findIndex = 0;
    findListNum = work->mFindListNum;
    for (; findIndex < findListNum; findIndex++) {
        if (work->mFindList[findIndex].mState == 0) {
            break;
        }
    }
    if (phase == AC_PHASE_SEARCH_DONE) {
        if (findListNum == findIndex) {
            if (findIndex == 0) {
                DWCi_AC_SetError(5);
            } else {
                DWCi_AC_SetError(6);
            }
            return AC_PHASE_ERROR;
        }
    } else {
        if (findListNum == 0) {
            return phase;
        }
        if (findListNum == findIndex) {
            return phase;
        }
        if (work->mFindList[findIndex].mRssi < 0x14) {
            return phase;
        }
    }
    work->mConnectNo = findIndex;
    if (WCM_EndSearchAsync() != 1) {
        work->mPhaseBak = phase;
        phase = AC_PHASE_CONNECT_START;
    }
    return phase;
}
