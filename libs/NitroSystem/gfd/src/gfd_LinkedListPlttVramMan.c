#include "gfd_LinkedListPlttVramMan.h"

#include "gfdi_LinkedListVramMan_Common.h"
#include "gfd_FrameTexVramMan.h"
#include "Main/Kart/data_02161000.h"
#include "data_02173000.h"
#include "mic.h"
#include "gfd_LinkedListTexVramMan.h"

NNS_GfdLnkPlttVramManager gPlttVramManager;

void NNS_GfdInitLnkPlttVramManager(u32 szByte, void *pManagementWork, u32 szByteManagementWork, int useAsDefault) {
    gPlttVramManager.mSzByte = szByte;
    gPlttVramManager.mWorkHead = pManagementWork;
    gPlttVramManager.mSzByteManagementWork = szByteManagementWork;
    NNS_GfdResetLnkPlttVramState();
    if (useAsDefault != 0) {
        data_021619f4 = (u32(*)(s32, s32, s32)) NNS_GfdAllocLnkPlttVram;
        data_021619f8 = NNS_GfdFreeLnkPlttVram;
    }
}

u32 NNS_GfdAllocLnkPlttVram(u32 szByte, s32 b4Pltt, u32 opt) {
    u32 size;
    u32 addr;
    s32 result;

    if (szByte == 0) {
        size = 8;
    } else {
        size = (szByte + 7) & ~7;
    }
    if (size >= 0x7fff8) {
        return 0;
    }
    if (b4Pltt != 0) {
        result = NNSi_GfdAllocLnkVramAligned(&gPlttVramManager.mMgr, &gPlttVramManager.mBlockList, &addr, size, 8);
        if (addr + size > 0x10000) {
            NNSi_GfdFreeLnkVram(&gPlttVramManager.mMgr, &gPlttVramManager.mBlockList, addr, size);
            return 0;
        }
    } else {
        result = NNSi_GfdAllocLnkVramAligned(&gPlttVramManager.mMgr, &gPlttVramManager.mBlockList, &addr, size, 0x10);
    }
    if (result != 0) {
        return ((size >> 3) << 16) | ((addr >> 3) & 0xffff);
    }
    return 0;
}

s32 NNS_GfdFreeLnkPlttVram(u32 plttKey) {
    return NNSi_GfdFreeLnkVram(&gPlttVramManager.mMgr, &gPlttVramManager.mBlockList, (plttKey & 0xffff) << 3,
                               ((plttKey & -0x10000) >> 0x10) << 3) == 0;
}

void NNS_GfdResetLnkPlttVramState(void) {
    gPlttVramManager.mBlockList =
        NNSi_GfdInitLnkVramBlockPool(gPlttVramManager.mWorkHead, gPlttVramManager.mSzByteManagementWork >> 4);
    NNSi_GfdInitLnkVramMan(&gPlttVramManager.mMgr);
    NNSi_GfdAddNewFreeBlock(&gPlttVramManager.mMgr, &gPlttVramManager.mBlockList, 0, gPlttVramManager.mSzByte);
}
