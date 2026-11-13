#include "00/Lib/DWC/code_021894e4.h"

#include "00/Lib/DWC/code_02188ec0.h"
#include "00/unk_021b0000.h"
#include "00/unk_021b2000.h"
#include "code_0214d018.h"
#include "code_02139f70.h"

const u8 gWayportSsid[8] = {0x57, 0x61, 0x79, 0x70, 0x6f, 0x72, 0x74, 0x32};
const char gFreespotSsid[8] = {'F', 'R', 'E', 'E', 'S', 'P', 'O', 'T'};
const u8 gNintendoWfcSsid[12] = {0x4e, 0x49, 0x4e, 0x54, 0x45, 0x4e, 0x44, 0x4f, 0x57, 0x46, 0x43, 0};
u8 gNwcUsbApSsid[12] = {0x4e, 0x57, 0x43, 0x55, 0x53, 0x42, 0x41, 0x50, 0, 0, 0, 0};

u32 DWCi_AC_CheckFreespot(WMBssDesc *bssDesc) {
    int compare;
    compare = strncmp((const char *) bssDesc->mSsid, gFreespotSsid, 8);
    if (compare == 0) {
        return 8;
    }
    return 0;
}

u8 MakeAroundList(ACWORK *work) {
    u8 num;
    ACSL *list;

    list = work->mSearchList;
    num = MakeUserList(work);
    list += num;
    if (work->mConnectType == 0 || work->mConnectType == 6) {
        MI_CpuCopy8(gFreespotSsid, list->mSsid, 8);
        list->mSsidLength = 8;
        list->mApType = 8;
        num++;
    }
    return num;
}

u8 MakeStealthList(ACWORK *work) {
    u8 num;
    ACSL *list;

    list = work->mSearchList;
    num = MakeUserList(work);
    list += num;
    if (work->mConnectType == 0 || work->mConnectType == 4) {
        MI_CpuCopy8(gNwcUsbApSsid, list->mSsid, 8);
        list->mSsidLength = 8;
        list->mApType = 6;
        num++;
        list++;
    }
    if (work->mConnectType == 0 || work->mConnectType == 7) {
        MI_CpuCopy8(gWayportSsid, list->mSsid, 8);
        list->mSsidLength = 8;
        list->mApType = 9;
        num++;
        list++;
    }
    if (work->mConnectType == 0 || work->mConnectType == 8) {
        MI_CpuCopy8(gNintendoWfcSsid, list->mSsid, 0xb);
        list->mSsidLength = 0xb;
        list->mApType = 10;
        num++;
    }
    return num;
}

u8 MakeUserList(ACWORK *work) {
    s32 apIndex;
    u8 num;
    u8 ssidIndex;
    BOOL hasName;
    DWCMemPage *info;
    ACSL *list;

    num = 0;
    info = work->mUserInfo;
    list = work->mSearchList;
    for (apIndex = 0; apIndex < 3; info++, apIndex++) {
        if (work->mConnectType == 0 || work->mConnectType == apIndex + 1) {
            if (info->mSetType != 0xff) {
                for (ssidIndex = 0; ssidIndex < 0x20; ssidIndex++) {
                    if (info->mSsid[ssidIndex] == 0) {
                        break;
                    }
                    list->mSsid[ssidIndex] = info->mSsid[ssidIndex];
                }
                if (ssidIndex != 0) {
                    list->mSsidLength = ssidIndex;
                    list->mApType = apIndex;
                    hasName = TRUE;
                } else {
                    hasName = FALSE;
                }
                if (hasName != FALSE) {
                    num++;
                    list++;
                }
                if (info->mSetType == 1) {
                    for (ssidIndex = 0; ssidIndex < 0x20; ssidIndex++) {
                        if (info->mSecondSsid[ssidIndex] == 0) {
                            break;
                        }
                        list->mSsid[ssidIndex] = info->mSecondSsid[ssidIndex];
                    }
                    if (ssidIndex != 0) {
                        list->mSsidLength = ssidIndex;
                        list->mApType = apIndex + 3;
                        hasName = TRUE;
                    } else {
                        hasName = FALSE;
                    }
                    if (hasName != FALSE) {
                        num++;
                        list++;
                    }
                }
            }
        }
    }
    return num;
}

u8 MakeDifferChannelList(s32 findListNum, ACFL *findList, ACSL *searchList, WMBssDesc *bssDescs) {
    u8 num;
    u8 findIndex;
    u8 ssidIndex;

    num = 0;
    for (findIndex = 0; findIndex < findListNum; findList++, bssDescs++, findIndex++) {
        if (findIndex >= 9) {
            break;
        }
        if (findList->mState == 0 && bssDescs->mChannel != findList->mChannel) {
            for (ssidIndex = 0; ssidIndex < 0x20; ssidIndex++) {
                if (bssDescs->mSsid[ssidIndex] == 0) {
                    break;
                }
                searchList->mSsid[ssidIndex] = bssDescs->mSsid[ssidIndex];
            }
            searchList->mSsidLength = ssidIndex;
            searchList->mChannel = bssDescs->mChannel - 1;
            searchList++;
            num++;
        }
    }
    return num;
}
