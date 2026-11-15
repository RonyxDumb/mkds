#include "gfd_FrameTexVramMan.h"
#include "Main/Graphics/g3d_anm_function_pointers.h"
#include "vram_alloc_wrappers.h"

s32 (*NNS_GfdDefaultFuncFreeTexVram)(u32) = FreeTexVram_;
s32 (*NNS_GfdDefaultFuncFreePlttVram)(u32) = FreePlttVram_;
u32 (*NNS_GfdDefaultFuncAllocTexVram)(s32 szByte, s32 is4x4comp, s32 opt) = (u32(*)(s32, s32, s32)) AllocTexVram_;
u32 (*NNS_GfdDefaultFuncAllocPlttVram)(s32 szByte, s32 is4pltt, s32 opt) = (u32(*)(s32, s32, s32)) AllocPlttVram_;
NNSGfdFrmTexRegionState vramRegions_[5] = {
    {0xffffffff, 0xffffffff, 0, 0, 0, 0xffff, 0},
    {0xffffffff, 0xffffffff, 0, 1, 1, 0xffff, 0x20000},
    {0xffffffff, 0xffffffff, 0, 1, 2, 0xffff, 0x30000},
    {0xffffffff, 0xffffffff, 0, 0, 3, 0xffff, 0x40000},
    {0xffffffff, 0xffffffff, 0, 0, 4, 0xffff, 0x60000},
};
NNSGfdFrmTexRegionState *texNrmSearchArray_[5] = {&vramRegions_[4], &vramRegions_[3], &vramRegions_[0],
                                                  &vramRegions_[2], &vramRegions_[1]};
NNSGfdFrmTexRegionState *tex4x4SearchArray_[2] = {&vramRegions_[0], &vramRegions_[3]};
u16 frmExVramMan_;

void NNSi_GfdSetTexNrmSearchArray(int idx1st, int idx2nd, int idx3rd, int idx4th, int idx5th) {
    texNrmSearchArray_[0] = &vramRegions_[idx1st];
    texNrmSearchArray_[1] = &vramRegions_[idx2nd];
    texNrmSearchArray_[2] = &vramRegions_[idx3rd];
    texNrmSearchArray_[3] = &vramRegions_[idx4th];
    texNrmSearchArray_[4] = &vramRegions_[idx5th];
}

void NNS_GfdInitFrmTexVramManager(u16 numBanks, BOOL useAsDefault) {
    if (numBanks <= 2) {
        NNSi_GfdSetTexNrmSearchArray(4, 3, 2, 0, 1);
    } else {
        NNSi_GfdSetTexNrmSearchArray(4, 3, 0, 2, 1);
    }
    frmExVramMan_ = numBanks;
    NNS_GfdResetFrmTexVramState();
    if (useAsDefault != 0) {
        NNS_GfdDefaultFuncAllocTexVram = (u32(*)(s32, s32, s32)) NNS_GfdAllocFrmTexVram;
        NNS_GfdDefaultFuncFreeTexVram = NNS_GfdFreeFrmTexVram;
    }
}

void NNS_GfdResetFrmTexVramState(void) {
    u32 numBanks;
    s32 regionIndex;
    NNSGfdFrmTexRegionState *region;

    numBanks = frmExVramMan_;
    region = vramRegions_;
    if (numBanks > 1) {
        numBanks++;
    }
    for (regionIndex = 0; regionIndex < 5; regionIndex++) {
        if (regionIndex < (s32) numBanks) {
            region->mBActive = 1;
        } else {
            region->mBActive = 0;
        }
        if (region->mBHalfSize != 0) {
            region->mHead = 0;
            region->mTail = FRM_TEX_REGION_HALF_END;
        } else {
            region->mHead = 0;
            region->mTail = FRM_TEX_REGION_FULL_END;
        }
        region++;
    }
}

u32 NNS_GfdAllocFrmTexVram(u32 szByte, u32 is4x4comp, u32 opt) {
    u32 addr;
    u32 size;
    u32 found;
    s32 regionIndex;
    volatile NNSGfdFrmTexRegionState *region;
    NNSGfdFrmTexRegionState *palRegion;
    u32 halfSize;

    if (szByte == 0) {
        size = 0x10;
    } else {
        size = (szByte + 0xf) & ~0xf;
    }
    if (size >= 0x7fff0) {
        return 0;
    }
    if (is4x4comp != 0) {
        halfSize = size >> 1;
        for (regionIndex = 0; regionIndex < 2; regionIndex++) {
            region = tex4x4SearchArray_[regionIndex];
            if (region->mBActive != 0 && region->mTail - region->mHead >= size) {
                switch (region->mIndex) {
                    case FRM_TEX_REGION_4X4_FIRST:
                        palRegion = &vramRegions_[1];
                        break;
                    case FRM_TEX_REGION_4X4_SECOND:
                        palRegion = &vramRegions_[2];
                        break;
                    default:
                        palRegion = 0;
                        break;
                }
                if (palRegion->mBActive != 0 && palRegion->mTail - palRegion->mHead >= halfSize) {
                    found = 1;
                    addr = region->mHead;
                    region->mHead = addr + size;
                    palRegion->mHead += halfSize;
                    addr += region->mBaseAddress;
                    goto done;
                }
            }
        }
        found = 0;
    } else {
        s32 normRegionIndex;
        volatile NNSGfdFrmTexRegionState *normRegion;

        for (normRegionIndex = 0; normRegionIndex < 5; normRegionIndex++) {
            normRegion = texNrmSearchArray_[normRegionIndex];
            if (normRegion->mBActive != 0 && normRegion->mTail - normRegion->mHead >= size) {
                normRegion->mTail -= size;
                found = 1;
                addr = normRegion->mTail + normRegion->mBaseAddress;
                goto done;
            }
        }
        found = 0;
    }
done:
    if (found != 0) {
        return ((addr >> 3) & 0xffff) | ((size >> 4) << 16) | (is4x4comp << 31);
    }
    return 0;
}

// Frame managers do not free single blocks.
s32 NNS_GfdFreeFrmTexVram(u32 texKey) {
    return 0;
}
