#include "00/Lib/DWC/code_021898dc.h"
#include "00/Lib/DWC/code_02188720.h"
#include "00/unk_021b4000.h"
#include "00/Lib/DWC/code_021884d8.h"
#include "00/Lib/DWC/code_02188ee0.h"
#include "00/Lib/DWC/code_0218973c.h"
#include "00/Lib/DWC/code_02189888.h"
#include "00/Lib/DWC/code_0218a018.h"
#include "00/code_021a8878.h"
#include "00/code_021a8aa8.h"
#include "00/unk_021b0000.h"
#include "os_tick.h"

u32 ConvNetMask(s32 a) {
    s32 i;
    u32 mask;

    a = 0x20 - a;
    i = 0;
    mask = ~i;
    for (; i < a; i++) {
        mask <<= 1;
    }
    return ((mask << 24) & 0xff000000) | (((mask << 8) & 0xff0000) | (((mask >> 24) & 0xff) | ((mask >> 8) & 0xff00)));
}

void CheckSetDNS(ACWORK *work) {
    DWCMemPage *info;
    s32 dnsSum;
    u32 dns1;
    u32 dns2;

    if (work->mConnectApType < 6) {
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
    work = (ACWORK *) DWCi_AC_GetMemPtr(0x10);
    if (wcmPhase == 1) {
        config.mDmaNo = work->mDmaNo;
        config.mPbdBuffer = NULL;
        config.mNbdBuffer = 0;
        config.mNbdMode = 0;
        DWCi_AC_MakeSearchList(0);
        result = WCM_StartupAsync(&config, (void (*)(WCMNotice *)) DWCi_AC_CallBackWCM);
        if (result == 1 || result >= 4) {
            DWCi_AC_SetError(1);
            return 0x11;
        }
    } else {
        return 1;
    }
    return 2;
}

u32 DWCi_AC_SearchAP(void) {
    ACWORK *work;
    u32 phase;
    u32 wcmPhase;

    work = (ACWORK *) DWCi_AC_GetMemPtr(0x10);
    phase = DWCi_AC_GetPhase();
    wcmPhase = WCM_GetPhase();
    if (phase == 2 && wcmPhase == 3) {
        phase = SearchStart(work);
    } else if (phase == 6) {
        phase = SearchEndCheck(work, phase);
    } else if (wcmPhase == 3 || wcmPhase == 6) {
        phase = SearchEndCheck(work, phase);
        if (phase != 7) {
            if (phase == 3) {
                phase = SearchAround(work);
            } else if (phase == 4) {
                phase = SearchDifferChannel(work);
            } else if (phase == 5) {
                phase = SearchStealth(work);
            }
        }
    }
    return phase;
}

void DWCi_AC_SetStealthChannel(u32 channel) {
    ACWORK *work;

    work = (ACWORK *) DWCi_AC_GetMemPtr(0x10);
    if (channel > 0xd) {
        channel = 0xd;
    }
    work->mStealthChannel |= 1 << (channel - 1);
}

s8 DWCi_AC_GetStealthChannel(s32 index) {
    ACWORK *work;
    u16 mask;
    u8 i;
    u8 found;

    work = (ACWORK *) DWCi_AC_GetMemPtr(0x10);
    mask = work->mStealthChannel;
    if (mask == 0) {
        return -1;
    }
    found = i = 0;
    for (; i < 0xd; i++) {
        if ((mask & (1 << i)) != 0) {
            if (found == index) {
                return i;
            }
            found++;
        }
    }
    return -1;
}

void DWCi_AC_SearchReStart(u32 phase) {
    ACWORK *work;

    work = (ACWORK *) DWCi_AC_GetMemPtr(0x10);
    switch (phase) {
        case 3:
            work->mTimeOut = OS_GetTick();
            ScanStart(WCM_Bssid_Any, WCM_Essid_Any, work->mSearchChannel, 0x200000);
            break;
        case 4:
            work->mTimeOut = OS_GetTick();
            ScanStart(WCM_Bssid_Any, work->mSearchList[work->mSearchListNo].mSsid,
                      work->mSearchList[work->mSearchListNo].mChannel, 0x300000);
            break;
        case 5:
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
    return 3;
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
    return 3;
}

u32 SearchAround2ndLap(ACWORK *work) {
    work->mCount = 0;
    work->mAroundCount = work->mAroundCount + 1;
    DWCi_AC_MakeSearchList(0);
    work->mSearchChannel = 1;
    return 3;
}

u32 SearchDifferChannel(ACWORK *work) {
    if ((OS_GetTick() - work->mTimeOut) * 64 / 0x82ea >= 0x96 ||
        work->mSearchList[work->mSearchListNo].mUnk_00_lo == 1) {
        work->mSearchList[work->mSearchListNo].mUnk_00_lo = 0;
        work->mSearchListNo++;
        if (work->mSearchListNum <= work->mSearchListNo) {
            work->mSearchListNo = 0;
            return NextSearchCheck(work, 4);
        }
        work->mTimeOut = OS_GetTick();
        ScanStart(WCM_Bssid_Any, work->mSearchList[work->mSearchListNo].mSsid,
                  work->mSearchList[work->mSearchListNo].mChannel, 0x300000);
    }
    return 4;
}

u32 SearchStealth(ACWORK *work) {
    if ((OS_GetTick() - work->mTimeOut) * 64 / 0x82ea >= 0x96 ||
        work->mSearchList[work->mSearchListNo].mUnk_00_lo == 1) {
        work->mSearchList[work->mSearchListNo].mUnk_00_lo = 0;
        work->mSearchListNo++;
        if (work->mSearchListNum == work->mSearchListNo) {
            work->mCount++;
            work->mSearchListNo = 0;
            work->mSearchChannel = DWCi_AC_GetStealthChannel(work->mCount);
        }
        if (work->mSearchChannel < 0) {
            work->mCount = 0;
            return NextSearchCheck(work, 5);
        }
        work->mTimeOut = OS_GetTick();
        ScanStart(WCM_Bssid_Any, work->mSearchList[work->mSearchListNo].mSsid, work->mSearchChannel, 0x300000);
    }
    return 5;
}

u32 NextSearchCheck(ACWORK *work, u32 phase) {
    switch (phase) {
        case 3:
            if (work->mFindListNum != 0 || work->mStealthChannel != 0) {
                if (DWCi_AC_MakeSearchList(1) != 0) {
                    phase = 4;
                } else {
                    phase = CheckStartStealthSearch(work);
                }
            } else if (work->mAroundCount < 1) {
                phase = SearchAround2ndLap(work);
            } else {
                phase = 6;
            }
            break;
        case 4:
            phase = CheckStartStealthSearch(work);
            break;
        case 5:
            if (work->mAroundCount < 1) {
                phase = SearchAround2ndLap(work);
            } else {
                phase = 6;
            }
            break;
    }
    DWCi_AC_SearchReStart(phase);
    return phase;
}

u32 SearchEndCheck(ACWORK *work, u32 phase) {
    u8 i;
    u8 findListNum;

    if (phase == 0x11) {
        return phase;
    }
    i = 0;
    findListNum = work->mFindListNum;
    for (; i < findListNum; i++) {
        if (work->mFindList[i].mState == 0) {
            break;
        }
    }
    if (phase == 6) {
        if (findListNum == i) {
            if (i == 0) {
                DWCi_AC_SetError(5);
            } else {
                DWCi_AC_SetError(6);
            }
            return 0x11;
        }
    } else {
        if (findListNum == 0) {
            return phase;
        }
        if (findListNum == i) {
            return phase;
        }
        if (work->mFindList[i].mRssi < 0x14) {
            return phase;
        }
    }
    work->mConnectNo = i;
    if (WCM_EndSearchAsync() != 1) {
        work->mPhaseBak = phase;
        phase = 7;
    }
    return phase;
}
