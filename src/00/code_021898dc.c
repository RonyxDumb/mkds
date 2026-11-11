#include "00/code_021898dc.h"
#include "00/code_02188720.h"
#include "00/unk_021b4000.h"
#include "00/code_021884d8.h"
#include "00/code_02188ee0.h"
#include "00/code_0218973c.h"
#include "00/code_02189888.h"
#include "00/code_0218a018.h"
#include "00/code_021a8878.h"
#include "00/code_021a8aa8.h"
#include "00/unk_021b0000.h"
#include "code_0200f5ac.h"

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

    if (work->mUnk_d0d < 6) {
        info = &work->mUnk_000[DWCi_ConvConnectAPType(work->mUnk_d0d)];
        dnsSum = info->mUnk_c8[3] + (info->mUnk_c8[2] + (info->mUnk_c8[0] + info->mUnk_c8[1]));
        if (info->mUnk_c0[0] == 0 && dnsSum != 0) {
            dns1 = ConvAddress(info->mUnk_c8);
            dns2 = ConvAddress(info->mUnk_cc);
            func_ov000_021a8e78(&dns1, &dns2);
        }
    }
}

u8 DWCi_AC_Start(void) {
    u32 wcmPhase;
    ACWORK *work;
    Unk02189f00 config;
    s32 result;

    wcmPhase = WCM_GetPhase();
    work = (ACWORK *) DWCi_AC_GetMemPtr(0x10);
    if (wcmPhase == 1) {
        config.mUnk_00 = work->mUnk_d0a;
        config.mUnk_04 = 0;
        config.mUnk_08 = 0;
        config.mUnk_0c = 0;
        DWCi_AC_MakeSearchList(0);
        result = WCM_StartupAsync((WCMConfig *) &config, (void (*)(WCMNotice *)) DWCi_AC_CallBackWCM);
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
    work->mUnk_d16 |= 1 << (channel - 1);
}

s8 DWCi_AC_GetStealthChannel(s32 index) {
    ACWORK *work;
    u16 mask;
    u8 i;
    u8 found;

    work = (ACWORK *) DWCi_AC_GetMemPtr(0x10);
    mask = work->mUnk_d16;
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
            work->mUnk_cb0 = OS_GetTick();
            ScanStart(WCM_Bssid_Any, WCM_Essid_Any, work->mUnk_d11, 0x200000);
            break;
        case 4:
            work->mUnk_cb0 = OS_GetTick();
            ScanStart(WCM_Bssid_Any, work->mUnk_300[work->mUnk_d0f].mUnk_04, work->mUnk_300[work->mUnk_d0f].mUnk_02,
                      0x300000);
            break;
        case 5:
            work->mUnk_cb0 = OS_GetTick();
            ScanStart(WCM_Bssid_Any, work->mUnk_300[work->mUnk_d0f].mUnk_04, work->mUnk_d11, 0x300000);
            break;
    }
}

u32 SearchStart(ACWORK *work) {
    work->mUnk_cb0 = OS_GetTick();
    work->mUnk_d11 = 0;
    work->mUnk_cb0 = OS_GetTick();
    ScanStart(WCM_Bssid_Any, WCM_Essid_Any, work->mUnk_d11, 0x200000);
    return 3;
}

u32 SearchAround(ACWORK *work) {
    if ((OS_GetTick() - work->mUnk_cb0) * 64 / 0x82ea >= 0x12c) {
        work->mUnk_d11 += 2;
        if (work->mUnk_d11 >= 0xd) {
            return NextSearchCheck(work, 3);
        }
        work->mUnk_cb0 = OS_GetTick();
        ScanStart(WCM_Bssid_Any, WCM_Essid_Any, work->mUnk_d11, 0x200000);
    }
    return 3;
}

u32 SearchAround2ndLap(ACWORK *work) {
    work->mUnk_d15 = 0;
    work->mUnk_d0b_4 = work->mUnk_d0b_4 + 1;
    DWCi_AC_MakeSearchList(0);
    work->mUnk_d11 = 1;
    return 3;
}

u32 SearchDifferChannel(ACWORK *work) {
    if ((OS_GetTick() - work->mUnk_cb0) * 64 / 0x82ea >= 0x96 || work->mUnk_300[work->mUnk_d0f].mUnk_00_lo == 1) {
        work->mUnk_300[work->mUnk_d0f].mUnk_00_lo = 0;
        work->mUnk_d0f++;
        if (work->mUnk_d10 <= work->mUnk_d0f) {
            work->mUnk_d0f = 0;
            return NextSearchCheck(work, 4);
        }
        work->mUnk_cb0 = OS_GetTick();
        ScanStart(WCM_Bssid_Any, work->mUnk_300[work->mUnk_d0f].mUnk_04, work->mUnk_300[work->mUnk_d0f].mUnk_02,
                  0x300000);
    }
    return 4;
}

u32 SearchStealth(ACWORK *work) {
    if ((OS_GetTick() - work->mUnk_cb0) * 64 / 0x82ea >= 0x96 || work->mUnk_300[work->mUnk_d0f].mUnk_00_lo == 1) {
        work->mUnk_300[work->mUnk_d0f].mUnk_00_lo = 0;
        work->mUnk_d0f++;
        if (work->mUnk_d10 == work->mUnk_d0f) {
            work->mUnk_d15++;
            work->mUnk_d0f = 0;
            work->mUnk_d11 = DWCi_AC_GetStealthChannel(work->mUnk_d15);
        }
        if (work->mUnk_d11 < 0) {
            work->mUnk_d15 = 0;
            return NextSearchCheck(work, 5);
        }
        work->mUnk_cb0 = OS_GetTick();
        ScanStart(WCM_Bssid_Any, work->mUnk_300[work->mUnk_d0f].mUnk_04, work->mUnk_d11, 0x300000);
    }
    return 5;
}

u32 NextSearchCheck(ACWORK *work, u32 phase) {
    switch (phase) {
        case 3:
            if (work->mUnk_d12 != 0 || work->mUnk_d16 != 0) {
                if (DWCi_AC_MakeSearchList(1) != 0) {
                    phase = 4;
                } else {
                    phase = CheckStartStealthSearch(work);
                }
            } else if (work->mUnk_d0b_4 < 1) {
                phase = SearchAround2ndLap(work);
            } else {
                phase = 6;
            }
            break;
        case 4:
            phase = CheckStartStealthSearch(work);
            break;
        case 5:
            if (work->mUnk_d0b_4 < 1) {
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
    findListNum = work->mUnk_d12;
    for (; i < findListNum; i++) {
        if (work->mUnk_444[i].mUnk_00 == 0) {
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
        if (work->mUnk_444[i].mUnk_02 < 0x14) {
            return phase;
        }
    }
    work->mUnk_d13 = i;
    if (WCM_EndSearchAsync() != 1) {
        work->mUnk_d0e = phase;
        phase = 7;
    }
    return phase;
}
