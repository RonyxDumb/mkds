#include "gfd_LinkedListTexVramMan.h"
#include "gfd_LinkedListPlttVramMan.h"

#include "code_020169a4.h"
#include "code_02016d28.h"
#include "gfd_FrameTexVramMan.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_02173000.h"

int NNS_GfdGetLnkTexVramManagerWorkSize(int numMemBlk) {
    return numMemBlk << 4;
}

void NNS_GfdInitLnkTexVramManager(u32 szByte, u32 szByteFor4x4, void *pManagementWork, u32 szByteManagementWork,
                                  int useAsDefault) {
    gTexVramManager.mSzByte = szByte;
    gTexVramManager.mSzByteFor4x4 = szByteFor4x4;
    gTexVramManager.mWorkHead = pManagementWork;
    gTexVramManager.mSzByteManagementWork = szByteManagementWork;
    NNS_GfdResetLnkTexVramState();
    if (useAsDefault != 0) {
        data_021619ec = (u32(*)(s32, s32, s32)) NNS_GfdAllocLnkTexVram;
        data_021619f0 = NNS_GfdFreeLnkTexVram;
    }
}

u32 NNS_GfdAllocLnkTexVram(u32 szByte, s32 is4x4comp, u32 opt) {
    u32 size;
    u32 addr;
    s32 result;

    if (szByte == 0) {
        size = 0x10;
    } else {
        size = (szByte + 0xf) & ~0xf;
    }
    if (size >= 0x7fff0) {
        return 0;
    }
    if (is4x4comp != 0) {
        result = NNSi_GfdAllocLnkVram(&data_02173238, &data_0217323c, &addr, size);
    } else {
        result = NNSi_GfdAllocLnkVram(&gTexVramManager.mMgrNrm, &data_0217323c, &addr, size);
    }
    if (result == 0) {
        return 0;
    }
    return ((size >> 4) << 16) | ((addr >> 3) & 0xffff) | (is4x4comp << 31);
}

s32 NNS_GfdFreeLnkTexVram(u32 texKey) {
    u32 addr;
    u32 size;
    u32 is4x4;
    s32 result;

    addr = (texKey & 0xffff) << 3;
    size = ((texKey & 0x7fff0000) >> 16) << 4;
    is4x4 = (texKey & 0x80000000) >> 31;
    if (size != 0) {
        if (is4x4 != 0) {
            result = NNSi_GfdFreeLnkVram(&data_02173238, &data_0217323c, addr, size);
        } else {
            result = NNSi_GfdFreeLnkVram(&gTexVramManager.mMgrNrm, &data_0217323c, addr, size);
        }
        if (result != 0) {
            return 0;
        }
        return 1;
    }
    return 2;
}

void NNS_GfdResetLnkTexVramState(void) {
    LnkTexBankData banks[4] = {{0x20000, 0, 0}, {0x20000, 0, 0}, {0x20000, 0, 0}, {0x20000, 0, 0}};
    u32 left4x4;
    LnkTexBankData *bank;
    u32 bankNo;
    u32 leftNormal;
    u32 indexSize;
    u32 amount;
    u32 bank0NrmAddr;
    u32 bank2NrmAddr;
    u32 bank2Nrm;

    left4x4 = gTexVramManager.mSzByteFor4x4;
    leftNormal = gTexVramManager.mSzByte;
    indexSize = left4x4 >> 1;
    leftNormal = leftNormal - (left4x4 + indexSize);
    bank = banks;
    for (bankNo = 0; bankNo < 4; bankNo++) {
        if (bankNo == 0 || bankNo == 2) {
            if (bank->mSzFree != 0 && left4x4 != 0) {
                amount = bank->mSzFree;
                if (amount > left4x4) {
                    amount = left4x4;
                }
                bank->mSz4x4 += amount;
                left4x4 -= amount;
                bank->mSzFree -= amount;
            }
        }
        bank++;
    }
    banks[1].mSzFree -= indexSize;
    bank = banks;
    for (bankNo = 0; bankNo < 4; bankNo++) {
        if (bank->mSzFree != 0 && leftNormal != 0) {
            amount = bank->mSzFree;
            if (amount > leftNormal) {
                amount = leftNormal;
            }
            bank->mSzNrm += amount;
            leftNormal -= amount;
            bank->mSzFree -= amount;
        }
        bank++;
    }
    NNSi_GfdInitLnkVramMan(&gTexVramManager.mMgrNrm);
    NNSi_GfdInitLnkVramMan(&data_02173238);
    gTexVramManager.mBlockList =
        NNSi_GfdInitLnkVramBlockPool(gTexVramManager.mWorkHead, gTexVramManager.mSzByteManagementWork >> 4);
    if (banks[0].mSz4x4 != 0) {
        NNSi_GfdAddNewFreeBlock(&data_02173238, &data_0217323c, 0, banks[0].mSz4x4);
    }
    bank0NrmAddr = banks[0].mSz4x4;
    if (banks[0].mSzNrm != 0) {
        NNSi_GfdAddNewFreeBlock(&gTexVramManager.mMgrNrm, &data_0217323c, bank0NrmAddr, banks[0].mSzNrm);
    }
    if (banks[2].mSz4x4 != 0) {
        NNSi_GfdAddNewFreeBlock(&data_02173238, &data_0217323c, 0x40000, banks[2].mSz4x4);
    }
    bank2Nrm = banks[2].mSzNrm;
    bank2NrmAddr = banks[2].mSz4x4 + 0x40000;
    if (bank2Nrm != 0) {
        NNSi_GfdAddNewFreeBlock(&gTexVramManager.mMgrNrm, &data_0217323c, bank2NrmAddr, bank2Nrm);
    }
    if (banks[3].mSzNrm != 0) {
        NNSi_GfdAddNewFreeBlock(&gTexVramManager.mMgrNrm, &data_0217323c, 0x60000, banks[3].mSzNrm);
    }
    if (banks[1].mSzNrm != 0) {
        NNSi_GfdAddNewFreeBlock(&gTexVramManager.mMgrNrm, &data_0217323c, indexSize + 0x20000, banks[1].mSzNrm);
    }
}
