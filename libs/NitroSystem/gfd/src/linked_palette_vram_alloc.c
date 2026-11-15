#include "linked_palette_vram_alloc.h"

#include "linked_vram_block_pool.h"
#include "frame_texture_vram_alloc.h"
#include "Main/Graphics/g3d_anm_function_pointers.h"
#include "particle_random_state.h"
#include "microphone_sampling.h"
#include "linked_texture_vram_alloc.h"

NNS_GfdLnkPlttVramManager gPlttVramManager;

void NNS_GfdInitLnkPlttVramManager(u32 szByte, void *pManagementWork, u32 szByteManagementWork, int useAsDefault) {
    gPlttVramManager.mSzByte = szByte;
    gPlttVramManager.mWorkHead = pManagementWork;
    gPlttVramManager.mSzByteManagementWork = szByteManagementWork;
    NNS_GfdResetLnkPlttVramState();
    if (useAsDefault != 0) {
        NNS_GfdDefaultFuncAllocPlttVram = (u32(*)(s32, s32, s32)) NNS_GfdAllocLnkPlttVram;
        NNS_GfdDefaultFuncFreePlttVram = NNS_GfdFreeLnkPlttVram;
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
