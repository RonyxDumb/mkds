#include "gfdi_LinkedListVramMan_Common.h"

void NNSi_GfdInitLnkVramMan(NNSiGfdLnkVramBlock **blockList) {
    *blockList = 0;
}

NNSiGfdLnkVramBlock *NNSi_GfdInitLnkVramBlockPool(NNSiGfdLnkVramBlock *blocks, u32 count) {
    u32 index;
    NNSiGfdLnkVramBlock *prevBlock;
    u32 lastIndex;

    lastIndex = count - 1;
    index = 0;
    if (lastIndex != 0) {
        prevBlock = blocks;
        do {
            blocks[index].mPBlkNext = &blocks[index + 1];
            blocks[index + 1].mPBlkPrev = prevBlock;
            index++;
            prevBlock++;
        } while (index < lastIndex);
    }
    blocks->mPBlkPrev = 0;
    (blocks + count)[-1].mPBlkNext = 0;
    return blocks;
}

s32 NNSi_GfdAddNewFreeBlock(NNSiGfdLnkVramBlock **freeListHead, NNSiGfdLnkVramBlock **spareListHead, u32 addr,
                            u32 size) {
    NNSiGfdLnkVramBlock *block;

    block = *spareListHead;
    if (block != 0) {
        *spareListHead = block->mPBlkNext;
    }
    if (block != 0) {
        block->mAddr = addr;
        block->mSzByte = size;
        block->mPBlkPrev = 0;
        block->mPBlkNext = 0;
        if (*freeListHead != 0) {
            (*freeListHead)->mPBlkPrev = block;
        }
        block->mPBlkNext = *freeListHead;
        block->mPBlkPrev = 0;
        *freeListHead = block;
        return 1;
    }
    return 0;
}

s32 NNSi_GfdAllocLnkVram(NNSiGfdLnkVramBlock **freeListHead, NNSiGfdLnkVramBlock **spareListHead, u32 *outAddr,
                         u32 size) {
    return NNSi_GfdAllocLnkVramAligned(freeListHead, spareListHead, outAddr, size, 0);
}

s32 NNSi_GfdAllocLnkVramAligned(NNSiGfdLnkVramBlock **freeListHead, NNSiGfdLnkVramBlock **spareListHead, u32 *outAddr,
                                u32 size, u32 alignment) {
    u32 addr;
    u32 need;
    u32 pad;
    NNSiGfdLnkVramBlock *best;
    NNSiGfdLnkVramBlock *block;
    NNSiGfdLnkVramBlock *spareBlock;
    NNSiGfdLnkVramBlock *prev;
    NNSiGfdLnkVramBlock *next;

    best = 0;
    for (block = *freeListHead; block != 0; block = block->mPBlkNext) {
        if (alignment > 1) {
            addr = (block->mAddr + (alignment - 1)) & ~(alignment - 1);
            pad = addr - block->mAddr;
            need = size + pad;
        } else {
            addr = block->mAddr;
            pad = 0;
            need = size;
        }
        if (block->mSzByte >= need) {
            best = block;
            break;
        }
    }
    if (best == 0) {
        goto fail;
    }
    if (pad != 0) {
        spareBlock = *spareListHead;
        if (spareBlock != 0) {
            *spareListHead = spareBlock->mPBlkNext;
        }
        if (spareBlock == 0) {
            goto fail;
        }
        spareBlock->mAddr = best->mAddr;
        spareBlock->mSzByte = pad;
        spareBlock->mPBlkPrev = 0;
        spareBlock->mPBlkNext = 0;
        if (*freeListHead != 0) {
            (*freeListHead)->mPBlkPrev = spareBlock;
        }
        spareBlock->mPBlkNext = *freeListHead;
        spareBlock->mPBlkPrev = 0;
        *freeListHead = spareBlock;
    }
    best->mSzByte -= need;
    best->mAddr += need;
    if (best->mSzByte == 0) {
        prev = best->mPBlkPrev;
        next = best->mPBlkNext;
        if (prev != 0) {
            prev->mPBlkNext = next;
        } else {
            *freeListHead = next;
        }
        if (next != 0) {
            next->mPBlkPrev = prev;
        }
        if (*spareListHead != 0) {
            (*spareListHead)->mPBlkPrev = best;
        }
        best->mPBlkNext = *spareListHead;
        best->mPBlkPrev = 0;
        *spareListHead = best;
    }
    *outAddr = addr;
    return 1;
fail:
    *outAddr = 0;
    return 0;
}

s32 NNSi_GfdFreeLnkVram(NNSiGfdLnkVramBlock **freeListHead, NNSiGfdLnkVramBlock **spareListHead, u32 addr, u32 size) {
    u32 range[4];
    u32 *rp;
    NNSiGfdLnkVramBlock *block;
    NNSiGfdLnkVramBlock *next;
    NNSiGfdLnkVramBlock *spareBlock;
    NNSiGfdLnkVramBlock *prev;

    range[0] = addr;
    range[1] = addr + size;
    range[2] = addr;
    range[3] = addr + size;
    rp = range;
    for (block = *freeListHead; block != 0; block = next) {
        next = block->mPBlkNext;
        if (block->mAddr == rp[1]) {
            range[3] = block->mAddr + block->mSzByte;
            prev = block->mPBlkPrev;
            if (prev != 0) {
                prev->mPBlkNext = next;
            } else {
                *freeListHead = next;
            }
            if (next != 0) {
                next->mPBlkPrev = prev;
            }
            if (*spareListHead != 0) {
                (*spareListHead)->mPBlkPrev = block;
            }
            block->mPBlkNext = *spareListHead;
            block->mPBlkPrev = 0;
            *spareListHead = block;
        }
        if (block->mAddr + block->mSzByte == rp[0]) {
            NNSiGfdLnkVramBlock *innerPrev;
            NNSiGfdLnkVramBlock *innerNext;

            range[2] = block->mAddr;
            innerPrev = block->mPBlkPrev;
            innerNext = block->mPBlkNext;
            if (innerPrev != 0) {
                innerPrev->mPBlkNext = innerNext;
            } else {
                *freeListHead = innerNext;
            }
            if (innerNext != 0) {
                innerNext->mPBlkPrev = innerPrev;
            }
            if (*spareListHead != 0) {
                (*spareListHead)->mPBlkPrev = block;
            }
            block->mPBlkNext = *spareListHead;
            block->mPBlkPrev = 0;
            *spareListHead = block;
        }
    }
    spareBlock = *spareListHead;
    if (spareBlock != 0) {
        *spareListHead = spareBlock->mPBlkNext;
    }
    if (spareBlock == 0) {
        return 0;
    }
    spareBlock->mAddr = range[2];
    spareBlock->mSzByte = range[3] - range[2];
    spareBlock->mPBlkPrev = 0;
    spareBlock->mPBlkNext = 0;
    if (*freeListHead != 0) {
        (*freeListHead)->mPBlkPrev = spareBlock;
    }
    spareBlock->mPBlkNext = *freeListHead;
    spareBlock->mPBlkPrev = 0;
    *freeListHead = spareBlock;
    return 1;
}
