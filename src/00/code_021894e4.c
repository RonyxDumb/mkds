#include "00/code_021894e4.h"

#include "00/code_02188ec0.h"
#include "00/unk_021b0000.h"
#include "00/unk_021b2000.h"
#include "code_0214d018.h"
#include "code_02139f70.h"

u32 DWCi_AC_CheckFreespot(Unk02188ee0 *bssDesc) {
    int compare;
    compare = strncmp((const char *) bssDesc->mUnk_0c, gFreespotSsid, 8);
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
        MI_CpuCopy8(gFreespotSsid, list->mUnk_04, 8);
        list->mUnk_03 = 8;
        list->mUnk_01 = 8;
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
        MI_CpuCopy8(data_ov000_021b20d0, list->mUnk_04, 8);
        list->mUnk_03 = 8;
        list->mUnk_01 = 6;
        num++;
        list++;
    }
    if (work->mConnectType == 0 || work->mConnectType == 7) {
        MI_CpuCopy8(gWayportSsid, list->mUnk_04, 8);
        list->mUnk_03 = 8;
        list->mUnk_01 = 9;
        num++;
        list++;
    }
    if (work->mConnectType == 0 || work->mConnectType == 8) {
        MI_CpuCopy8(gNintendoWfcSsid, list->mUnk_04, 0xb);
        list->mUnk_03 = 0xb;
        list->mUnk_01 = 10;
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
            if (info->mUnk_e7 != 0xff) {
                for (j = 0; j < 0x20; j++) {
                    if (info->mUnk_40[j] == 0) {
                        break;
                    }
                    list->mUnk_04[j] = info->mUnk_40[j];
                }
                if (j != 0) {
                    list->mUnk_03 = j;
                    list->mUnk_01 = i;
                    hasName = TRUE;
                } else {
                    hasName = FALSE;
                }
                if (hasName != FALSE) {
                    num++;
                    list++;
                }
                if (info->mUnk_e7 == 1) {
                    for (j = 0; j < 0x20; j++) {
                        if (info->mUnk_60[j] == 0) {
                            break;
                        }
                        list->mUnk_04[j] = info->mUnk_60[j];
                    }
                    if (j != 0) {
                        list->mUnk_03 = j;
                        list->mUnk_01 = i + 3;
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

u8 MakeDifferChannelList(s32 findListNum, ACFL *findList, ACSL *searchList, Unk02188ee0 *bssDescs) {
    u8 num;
    u8 i;
    u8 j;

    num = 0;
    for (i = 0; i < findListNum; findList++, bssDescs++, i++) {
        if (i >= 9) {
            break;
        }
        if (findList->mUnk_00 == 0 && bssDescs->mUnk_36 != findList->mUnk_03) {
            for (j = 0; j < 0x20; j++) {
                if (bssDescs->mUnk_0c[j] == 0) {
                    break;
                }
                searchList->mUnk_04[j] = bssDescs->mUnk_0c[j];
            }
            searchList->mUnk_03 = j;
            searchList->mUnk_02 = bssDescs->mUnk_36 - 1;
            searchList++;
            num++;
        }
    }
    return num;
}
