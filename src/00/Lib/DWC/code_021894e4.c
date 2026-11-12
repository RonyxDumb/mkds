#include "00/Lib/DWC/code_021894e4.h"

#include "00/Lib/DWC/code_02188ec0.h"
#include "00/unk_021b0000.h"
#include "00/unk_021b2000.h"
#include "code_0214d018.h"
#include "code_02139f70.h"

const u8 gWayportSsid[8] = {0x57, 0x61, 0x79, 0x70, 0x6f, 0x72, 0x74, 0x32};
const char gFreespotSsid[8] = {'F', 'R', 'E', 'E', 'S', 'P', 'O', 'T'};
const u8 gNintendoWfcSsid[12] = {0x4e, 0x49, 0x4e, 0x54, 0x45, 0x4e, 0x44, 0x4f, 0x57, 0x46, 0x43, 0};
u8 data_ov000_021b20d0[12] = {0x4e, 0x57, 0x43, 0x55, 0x53, 0x42, 0x41, 0x50, 0, 0, 0, 0};

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
        MI_CpuCopy8(data_ov000_021b20d0, list->mSsid, 8);
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
    s32 i;
    u8 num;
    u8 j;
    BOOL hasName;
    DWCMemPage *info;
    ACSL *list;

    num = 0;
    info = work->mUserInfo;
    list = work->mSearchList;
    for (i = 0; i < 3; info++, i++) {
        if (work->mConnectType == 0 || work->mConnectType == i + 1) {
            if (info->mSetType != 0xff) {
                for (j = 0; j < 0x20; j++) {
                    if (info->mSsid[j] == 0) {
                        break;
                    }
                    list->mSsid[j] = info->mSsid[j];
                }
                if (j != 0) {
                    list->mSsidLength = j;
                    list->mApType = i;
                    hasName = TRUE;
                } else {
                    hasName = FALSE;
                }
                if (hasName != FALSE) {
                    num++;
                    list++;
                }
                if (info->mSetType == 1) {
                    for (j = 0; j < 0x20; j++) {
                        if (info->mSecondSsid[j] == 0) {
                            break;
                        }
                        list->mSsid[j] = info->mSecondSsid[j];
                    }
                    if (j != 0) {
                        list->mSsidLength = j;
                        list->mApType = i + 3;
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
    u8 i;
    u8 j;

    num = 0;
    for (i = 0; i < findListNum; findList++, bssDescs++, i++) {
        if (i >= 9) {
            break;
        }
        if (findList->mState == 0 && bssDescs->mChannel != findList->mChannel) {
            for (j = 0; j < 0x20; j++) {
                if (bssDescs->mSsid[j] == 0) {
                    break;
                }
                searchList->mSsid[j] = bssDescs->mSsid[j];
            }
            searchList->mSsidLength = j;
            searchList->mChannel = bssDescs->mChannel - 1;
            searchList++;
            num++;
        }
    }
    return num;
}
