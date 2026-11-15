#pragma once

#include "types.h"

// Values of MBiCacheInfo.mState.
enum {
    MULTIBOOT_CACHE_EMPTY,
    MULTIBOOT_CACHE_LOADING,
    MULTIBOOT_CACHE_LOADED, // dropped when a block outside the cache is read
    MULTIBOOT_CACHE_FIXED
};

// 0x10-byte entries from 0x30 of MBiCacheList.
typedef struct MBiCacheInfo {
    /* 00 */ u32 mSrc;
    /* 04 */ u32 mLen;
    /* 08 */ u8 *mPtr;
    /* 0c */ u32 mState;
} MBiCacheInfo;

typedef struct MBiCacheList {
    /* 00 */ u32 mLifetime;
    /* 04 */ u8 mUnk_04[0xc];
    /* 10 */ u8 mArcName[4];
    /* 14 */ s32 mArcNameLen;
    /* 18 */ u8 mUnk_18[0x18];
    /* 30 */ MBiCacheInfo mList[4];
} MBiCacheList;

void MBi_InitCache(MBiCacheList *table);
u32 MBi_ReadFromCache(MBiCacheList *table, u32 offset, void *destination, u32 byteCount);
void MBi_AttachCacheBuffer(MBiCacheList *table, u32 offset, u32 size, u8 *data, u32 value);
