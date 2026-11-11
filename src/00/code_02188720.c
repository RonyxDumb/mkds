#include "00/code_02188720.h"
#include "00/code_021884d8.h"
#include "00/unk_021b4000.h"
#include "00/code_02188008.h"
#include "00/code_02188694.h"
#include "00/code_02189478.h"
#include "00/code_0218a658.h"
#include "00/code_0218a000.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"
#include "00/code_0218a67c.h"
#include "00/code_021892f4.h"
#include "code_0200fc8c.h"
#include "code_02139f70.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_021519a8.h"

void DWCi_AC_CallBackWCM(Unk02188d78 *notice) {
    Unk02188408 *work;

    work = (Unk02188408 *) DWCi_AC_GetMemPtr(0x10);
    if (notice->mUnk_00 == 5) {
        if (notice->mUnk_02 != 0) {
            switch (notice->mUnk_08) {
                case 0xd:
                    work->mUnk_d14 = 1;
                    break;
                case 0xf:
                    work->mUnk_d14 = 2;
                    break;
                case 0x11:
                    work->mUnk_d14 = 3;
                    break;
                default:
                    work->mUnk_d14 = 4;
                    break;
            }
        }
    } else if (notice->mUnk_00 == 7) {
        DWCi_AC_GetBeacon(notice->mUnk_04);
    }
}

void DWCi_AC_GetBeacon(Unk02188408Entry0xc0 *bssdesc) {
    Unk02188408 *work;
    s32 type;
    u32 phase;

    type = -1;
    work = (Unk02188408 *) DWCi_AC_GetMemPtr(0x10);
    ((ACHOLD *) DWCi_AC_GetMemPtr(1))->mUnk_0b = 1;
    phase = DWCi_AC_GetPhase();
    switch (phase) {
        case 3:
            if (bssdesc->mUnk_0a == 0 || bssdesc->mUnk_0c[0] == 0) {
                func_ov000_02189e54(bssdesc->mUnk_36);
            } else if (bssdesc->mUnk_0a == 1 || bssdesc->mUnk_0c[0] == 0x20) {
                func_ov000_02189e54(bssdesc->mUnk_36);
                type = CompareList(bssdesc, work->mUnk_d10, work->mUnk_300);
            } else {
                type = CompareList(bssdesc, work->mUnk_d10, work->mUnk_300);
            }
            break;
        case 4:
        case 5:
            type = CompareList(bssdesc, 1, work->mUnk_300 + work->mUnk_d0f);
            if (type >= 0) {
                work->mUnk_300[work->mUnk_d0f].mUnk_00 = (work->mUnk_300[work->mUnk_d0f].mUnk_00 & ~0xf) | 1;
            }
            break;
        default:
            return;
    }
    if (type >= 0) {
        SortList(AddList(type, bssdesc, work), work);
    }
}

s32 DWCi_AC_CheckNintendoSSID(Unk02188408Entry0xc0 *bssdesc) {
    Unk02188408 *work;
    u8 nintendoFlag;

    work = (Unk02188408 *) DWCi_AC_GetMemPtr(0x10);
    if (work->mUnk_d0c_0 == 0 || work->mUnk_d0c_0 == 4) {
        nintendoFlag = bssdesc->mUnk_2c >> 4 & 1;
        if (nintendoFlag == 1) {
            if (func_ov000_0218a658((const u8 *) bssdesc->mUnk_0c) == 1) {
                return 6;
            }
        }
    }
    if (work->mUnk_d0c_0 == 0 || work->mUnk_d0c_0 == 5) {
        nintendoFlag = bssdesc->mUnk_2c >> 4 & 1;
        if (nintendoFlag == 1) {
            if (func_ov000_0218a6c8((const u8 *) bssdesc->mUnk_0c) == 1) {
                return 7;
            }
        }
    }
    return -1;
}

s32 CompareList(Unk02188408Entry0xc0 *bssdesc, s32 num, Unk02188408Entry24 *list) {
    s32 i;
    s32 checkResult;
    u16 ssidLength;

    if (bssdesc->mUnk_0a == 0x20) {
        checkResult = DWCi_AC_CheckNintendoSSID(bssdesc);
        if (checkResult > 0) {
            return checkResult;
        }
    }
    i = 0;
    if (num > 0) {
        ssidLength = bssdesc->mUnk_0a;
        do {
            if ((u8) ssidLength == list->mUnk_03) {
                if (strncmp(bssdesc->mUnk_0c, list->mUnk_04, ssidLength) == 0) {
                    return list->mUnk_01;
                }
            }
            list++;
            i++;
        } while (i < num);
    }
    return -1;
}

s32 AddList(u32 type, Unk02188408Entry0xc0 *bssdesc, Unk02188408 *work) {
    s32 i;
    s32 found;
    char *entryBssid;
    s32 findListNum;

    i = 0;
    found = -1;
    findListNum = work->mUnk_d12;
    if (findListNum > 0) {
        entryBssid = work->mUnk_470[0].mUnk_04;
        do {
            if (bssdesc->mUnk_04[0] == entryBssid[0] && bssdesc->mUnk_04[1] == entryBssid[1] &&
                bssdesc->mUnk_04[2] == entryBssid[2] && bssdesc->mUnk_04[3] == entryBssid[3] &&
                bssdesc->mUnk_04[4] == entryBssid[4] && bssdesc->mUnk_04[5] == entryBssid[5]) {
                found = i;
                break;
            }
            entryBssid += 0xc0;
            i++;
        } while (i < work->mUnk_d12);
    }
    if (found == -1) {
        SetDataListTail(type, bssdesc, work);
        if (work->mUnk_d12 < 10) {
            work->mUnk_d12++;
        }
        found = 10;
    } else {
        UpDateList(found, bssdesc, work);
    }
    return found;
}

void SetDataListTail(u8 type, Unk02188408Entry0xc0 *bssdesc, Unk02188408 *work) {
    Unk02188408Entry4 *tailFind;
    Unk02188408Entry0xc0 *tailBss;
    u16 rssiWord;

    tailFind = &work->mUnk_444[10];
    tailBss = &work->mUnk_470[10];
    tailFind->mUnk_01 = type;
    rssiWord = bssdesc->mUnk_02;
    tailFind->mUnk_02 = (rssiWord & 2) != 0 ? (u8) (rssiWord >> 2) : (u8) ((rssiWord >> 2) + 0x19);
    tailFind->mUnk_03 = work->mUnk_d11 + 1;
    MIi_CpuCopy32(bssdesc, tailBss, 0xc0);
}

void UpDateList(u32 listIndex, Unk02188408Entry0xc0 *bssdesc, Unk02188408 *work) {
    Unk02188408Entry4 *findEntry;
    Unk02188408Entry0xc0 *bssEntry;
    u16 rssiWord;
    u8 rssiLevelByte;
    s32 rssiLevel;

    findEntry = &work->mUnk_444[listIndex];
    bssEntry = &work->mUnk_470[listIndex];
    rssiWord = bssdesc->mUnk_02;
    rssiLevel = (rssiWord & 2) != 0 ? (u8) (rssiWord >> 2) : (u8) ((rssiWord >> 2) + 0x19);
    rssiLevelByte = rssiLevel;
    if (rssiLevelByte > findEntry->mUnk_02) {
        findEntry->mUnk_02 = rssiLevelByte;
        findEntry->mUnk_03 = work->mUnk_d11 + 1;
    }
    MIi_CpuCopy32(bssdesc, bssEntry, 0xc0);
}

void SortList(u32 listIndex, Unk02188408 *work) {
    Unk02188408Entry4 *findList;
    Unk02188408Entry0xc0 *bssDescList;
    Unk02188408Entry4 *previousFind;
    Unk02188408Entry0xc0 *previousBss;
    Unk02188408Entry4 swapFind;
    Unk02188408Entry0xc0 swapBss;
    s32 i;

    findList = work->mUnk_444;
    bssDescList = work->mUnk_470;
    i = listIndex - 1;
    if (i >= 0) {
        previousFind = &findList[i];
        previousBss = &bssDescList[i];
        do {
            if (findList[listIndex].mUnk_02 < previousFind->mUnk_02) {
                break;
            }
            MIi_CpuCopy32(previousFind, &swapFind, 4);
            MIi_CpuCopy32(&findList[listIndex], previousFind, 4);
            MIi_CpuCopy32(&swapFind, &findList[listIndex], 4);
            MIi_CpuCopy32(previousBss, &swapBss, 0xc0);
            MIi_CpuCopy32(&bssDescList[listIndex], previousBss, 0xc0);
            MIi_CpuCopy32(&swapBss, &bssDescList[listIndex], 0xc0);
            listIndex = i;
            previousFind--;
            previousBss--;
            i--;
        } while (i >= 0);
    }
    findList += 10;
    func_0214d018_inline(findList, 4);
    func_0214d018_inline(bssDescList + 10, 0xc0);
}

BOOL DWC_AC_Create(DWCACConfig *config) {
    ACHOLD *hold;
    Unk02188408 *work;
    DWCNetcheckParam *netCheckParam;
    s32 result;

    gAcHold = config->mUnk_00(1, 0x18);
    func_0214d018_inline(gAcHold, 0x18);
    hold = gAcHold;
    hold->mUnk_00 = config->mUnk_00;
    hold->mUnk_04 = config->mUnk_04;
    hold->mUnk_09 = 1;
    hold->mUnk_16 = 1;
    hold->mUnk_08 = 1;
    gAcWork = DWCi_AC_Alloc(0x10, 0xd18);
    gWcmBuffer = DWCi_AC_Alloc(2, 0x2300);
    gSocConfig = DWCi_AC_Alloc(4, 0x58);
    gNetCheck = DWCi_AC_Alloc(8, 0xc);
    func_0214d018_inline(gAcWork, 0xd18);
    func_0214d018_inline(gWcmBuffer, 0x2300);
    func_0214d018_inline(gSocConfig, 0x58);
    func_0214d018_inline(gNetCheck, 0xc);
    work = gAcWork;
    work->mUnk_d0a = config->mUnk_08;
    work->mUnk_d0b_0 = config->mUnk_09;
    netCheckParam = gNetCheck;
    netCheckParam->mAlloc = config->mUnk_00;
    netCheckParam->mFree = config->mUnk_04;
    netCheckParam->mUnk_08 = 0;
    work->mUnk_d0c_0 = config->mUnk_0a;
    work->mUnk_d0c_4 = config->mUnk_0b;
    ReadNvramFirstThreeEntries(work);
    result = func_ov000_021a6470(gWcmBuffer, 0x2300);
    if (result == 1 || result >= 4) {
        DWCi_AC_FreeAll();
        return 0;
    }
    return 1;
}

s32 DWC_AC_Process(void) {
    u8 phase;
    u32 interruptState;
    s32 duplicateResult;

    phase = DWCi_AC_GetPhase();
    if (phase == 1) {
        phase = func_ov000_02189f00();
    } else if (phase < 7) {
        interruptState = OS_DisableInterrupts();
        phase = ((u8(*)(void)) func_ov000_02189e80)();
        DWCi_AC_SetPhase(phase);
        OS_RestoreInterrupts(interruptState);
    } else if (phase < 9) {
        phase = ((u8(*)(void)) func_ov000_0218922c)();
    } else if (phase < 10) {
        phase = ((u8(*)(void)) func_ov000_021897bc)();
    } else if (phase < 16) {
        phase = ((u8(*)(void)) func_ov000_0218a294)();
    } else if (phase == 17) {
        phase = func_ov000_021894c0();
    }
    DWCi_AC_SetPhase(phase);
    if (phase == 16) {
        duplicateResult = CheckDuplicate();
        FreeDisused();
        return duplicateResult;
    }
    if (phase == 18) {
        FreeDisused();
        return -1;
    }
    return 0;
}

u32 DWC_AC_GetStatus(void) {
    u32 phase;

    phase = DWCi_AC_GetPhase();
    if (phase <= 1) {
        return 0;
    }
    if (phase < 7) {
        return 1;
    }
    if (phase == 9) {
        return 4;
    }
    if (phase < 10) {
        return 2;
    }
    if (phase == 11) {
        return 4;
    }
    if (phase < 16) {
        return 3;
    }
    if (phase == 16) {
        return 5;
    }
    if (phase == 17) {
        return 4;
    }
    return func_ov000_02189478();
}

BOOL DWC_AC_Destroy(void) {
    u8 phase;

    phase = DWCi_AC_GetPhase();
    if (phase == 0 || phase == 0x12) {
        DWCi_AC_FreeAll();
        return 1;
    }
    func_ov000_021892f4(&phase);
    DWCi_AC_SetPhase(phase);
    return 0;
}
