#include "model_texture_bind.h"

#include "reset_interrupt_enable.h"
#include "os_tick.h"
#include "model_draw_blend.h"
#include "animation_lookup.h"
#include "vector_math.h"
#include "exception_state.h"
#include "registers.h"

u32 gVramBankLockedMask;
u16 gVramBankLockIds[9];
NNSG3dGlb NNS_G3dGlb;

// Sets the texture offset and size ratio of each material in the list.
void bindMdlTex_Internal_(NNSG3dResMat *mat, NNSG3dResDictTexToMatIdxData *data, NNSG3dResTex *tex,
                          NNSG3dResDictTexData *texData) {
    u32 keyOffset;
    u32 matIndex;
    u8 *matIndices;
    u32 width;
    u32 height;
    NNSG3dResMatData *matEntry;

    matIndices = (u8 *) mat + data->mOffset;
    if ((texData->mTexImageParam & G3D_TEX_IMAGE_FORMAT_MASK) != G3D_TEX_IMAGE_FORMAT_4X4_COMPRESSED) {
        keyOffset = tex->mTexInfo.mVramKey & G3D_VRAM_KEY_OFFSET_MASK;
    } else {
        keyOffset = tex->mTex4x4Info.mVramKey & G3D_VRAM_KEY_OFFSET_MASK;
    }
    for (matIndex = 0; matIndex < data->mNumIdx; matIndex++) {
        NNSG3dResDictEntryHeader *table;
        table = OFFSET_PTR(NNSG3dResDictEntryHeader, &mat->mDict, mat->mDict.mOfsEntry);
        matEntry = OFFSET_PTR(NNSG3dResMatData, mat, *DICT_ENTRY(u32, table, matIndices[matIndex]));
        matEntry->mTexImageParam |= texData->mTexImageParam + keyOffset;
        width = texData->mExtraParam & G3D_TEX_EXTRA_WIDTH_MASK;
        height = (texData->mExtraParam >> 11) & 0x7ff;
        matEntry->mMagW =
            (width == matEntry->mOrigWidth) ? 0x1000 : FX_Div(TO_FIXED12(width), TO_FIXED12(matEntry->mOrigWidth));
        matEntry->mMagH =
            (height == matEntry->mOrigHeight) ? 0x1000 : FX_Div(TO_FIXED12(height), TO_FIXED12(matEntry->mOrigHeight));
    }
    data->mFlag |= 1;
}

// Resets the texture offset and size ratio of each material in the list.
void releaseMdlTex_Internal_(NNSG3dResMat *mat, NNSG3dResDictTexToMatIdxData *data) {
    u8 *matIndices;
    u32 matIndex;
    NNSG3dResMatData *matEntry;

    matIndices = (u8 *) mat + data->mOffset;
    for (matIndex = 0; matIndex < data->mNumIdx; matIndex++) {
        NNSG3dResDictEntryHeader *table;
        table = OFFSET_PTR(NNSG3dResDictEntryHeader, &mat->mDict, mat->mDict.mOfsEntry);
        matEntry = OFFSET_PTR(NNSG3dResMatData, mat, *DICT_ENTRY(u32, table, matIndices[matIndex]));
        matEntry->mTexImageParam &= G3D_TEX_IMAGE_KEEP_MASK;
        matEntry->mMagW = FIXED12_UNIT;
        matEntry->mMagH = matEntry->mMagW;
    }
    data->mFlag &= ~1;
}

// Returns 0 when the texture has no entry for one of the names.
int NNS_G3dBindMdlTex(NNSG3dResMdl *mdl, NNSG3dResTex *tex) {
    NNSG3dResMat *materials;
    NNSG3dResDict *list;
    int result;
    u32 entryIndex;
    void *texEntry;
    NNSG3dResDictEntryHeader *table;
    NNSG3dResDictTexToMatIdxData *binding;

    materials = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    list = OFFSET_PTR(NNSG3dResDict, materials, materials->mOfsDictTexToMatList);
    result = 1;
    for (entryIndex = 0; entryIndex < list->mNumEntry; entryIndex++) {
        table = OFFSET_PTR(NNSG3dResDictEntryHeader, list, list->mOfsEntry);
        texEntry = NNS_G3dGetResDataByName(&tex->mDict, DICT_ENTRY_NAME(table, entryIndex));
        if (texEntry != 0) {
            table = OFFSET_PTR(NNSG3dResDictEntryHeader, list, list->mOfsEntry);
            binding = DICT_ENTRY(NNSG3dResDictTexToMatIdxData, table, entryIndex);
            if ((binding->mFlag & 1) == 0) {
                bindMdlTex_Internal_(materials, binding, tex, texEntry);
            }
        } else {
            result = 0;
        }
    }
    return result;
}

int NNS_G3dBindMdlTexEx(NNSG3dResMdl *mdl, NNSG3dResTex *tex, const u32 *name) {
    NNSG3dResDict *list;
    NNSG3dResMat *materials;
    void *texEntry;
    NNSG3dResDictTexToMatIdxData *binding;

    materials = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    list = OFFSET_PTR(NNSG3dResDict, materials, materials->mOfsDictTexToMatList);
    texEntry = NNS_G3dGetResDataByName(&tex->mDict, name);
    if (texEntry != 0) {
        binding = NNS_G3dGetResDataByName(list, name);
        if (binding != 0 && (binding->mFlag & 1) == 0) {
            bindMdlTex_Internal_(materials, binding, tex, texEntry);
            return 1;
        }
    }
    return 0;
}

void NNS_G3dReleaseMdlTex(NNSG3dResMdl *mdl) {
    NNSG3dResMat *materials;
    NNSG3dResDict *list;
    NNSG3dResDictEntryHeader *table;
    NNSG3dResDictTexToMatIdxData *binding;
    u32 entryIndex;

    materials = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    list = OFFSET_PTR(NNSG3dResDict, materials, materials->mOfsDictTexToMatList);
    for (entryIndex = 0; entryIndex < list->mNumEntry; entryIndex++) {
        table = OFFSET_PTR(NNSG3dResDictEntryHeader, list, list->mOfsEntry);
        binding = DICT_ENTRY(NNSG3dResDictTexToMatIdxData, table, entryIndex);
        if ((binding->mFlag & 1) != 0) {
            releaseMdlTex_Internal_(materials, binding);
        }
    }
}

u32 NNS_G3dReleaseMdlTexEx(NNSG3dResMdl *mdl, const u32 *name) {
    NNSG3dResMat *materials;
    NNSG3dResDictTexToMatIdxData *binding;

    materials = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    binding = NNS_G3dGetResDataByName((u8 *) materials + materials->mOfsDictTexToMatList, name);
    if (binding != 0 && (binding->mFlag & 1) != 0) {
        releaseMdlTex_Internal_(materials, binding);
        return 1;
    }
    return 0;
}

// Sets the palette offset of each material in the list.
void bindMdlPltt_Internal_(NNSG3dResMat *mat, NNSG3dResDictTexToMatIdxData *data, NNSG3dResTex *tex,
                           NNSG3dResDictPlttData *plttData) {
    u8 *matIndices;
    u32 base;
    u32 keyOffset;
    u32 matIndex;
    NNSG3dResDictEntryHeader *table;
    NNSG3dResMatData *matEntry;

    matIndices = (u8 *) mat + data->mOffset;
    base = (u16) tex->mPlttInfo.mVramKey;
    keyOffset = plttData->mOffset;
    if ((plttData->mFlag & 1) == 0) {
        base = (base << 15) >> 16;
        keyOffset = (keyOffset << 15) >> 16;
    }
    for (matIndex = 0; matIndex < data->mNumIdx; matIndex++) {
        table = OFFSET_PTR(NNSG3dResDictEntryHeader, &mat->mDict, mat->mDict.mOfsEntry);
        matEntry = OFFSET_PTR(NNSG3dResMatData, mat, *DICT_ENTRY(u32, table, matIndices[matIndex]));
        matEntry->mTexPlttBase = keyOffset + base;
    }
    data->mFlag |= 1;
}

// Returns 0 when the texture has no palette for one of the names.
u32 NNS_G3dBindMdlPltt(NNSG3dResMdl *mdl, NNSG3dResTex *tex) {
    NNSG3dResMat *materials;
    NNSG3dResDict *list;
    NNSG3dResDictEntryHeader *table;
    u32 entryIndex;
    u32 result;
    void *plttEntry;
    NNSG3dResDictTexToMatIdxData *binding;

    materials = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    result = 1;
    entryIndex = 0;
    list = OFFSET_PTR(NNSG3dResDict, materials, materials->mOfsDictPlttToMatList);
    for (; entryIndex < list->mNumEntry; entryIndex++) {
        table = OFFSET_PTR(NNSG3dResDictEntryHeader, list, list->mOfsEntry);
        plttEntry = NNS_G3dGetResDataByName((u8 *) tex + tex->mPlttInfo.mOfsDict, DICT_ENTRY_NAME(table, entryIndex));
        if (plttEntry != 0) {
            table = OFFSET_PTR(NNSG3dResDictEntryHeader, list, list->mOfsEntry);
            binding = DICT_ENTRY(NNSG3dResDictTexToMatIdxData, table, entryIndex);
            if ((binding->mFlag & 1) == 0) {
                bindMdlPltt_Internal_(materials, binding, tex, plttEntry);
            }
        } else {
            result = 0;
        }
    }
    return result;
}

u32 NNS_G3dBindMdlPlttEx(NNSG3dResMdl *mdl, NNSG3dResTex *tex, const u32 *name) {
    NNSG3dResDict *list;
    NNSG3dResMat *materials;
    void *plttEntry;
    NNSG3dResDictTexToMatIdxData *binding;

    materials = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    list = OFFSET_PTR(NNSG3dResDict, materials, materials->mOfsDictPlttToMatList);
    plttEntry = NNS_G3dGetResDataByName((u8 *) tex + tex->mPlttInfo.mOfsDict, name);
    if (plttEntry != 0) {
        binding = NNS_G3dGetResDataByName(list, name);
        if (binding != 0 && (binding->mFlag & 1) == 0) {
            bindMdlPltt_Internal_(materials, binding, tex, plttEntry);
            return 1;
        }
    }
    return 0;
}

void NNS_G3dReleaseMdlPltt(NNSG3dResMdl *mdl) {
    NNSG3dResMat *materials;
    NNSG3dResDict *list;
    NNSG3dResDictEntryHeader *table;
    NNSG3dResDictTexToMatIdxData *binding;
    u32 entryIndex;

    materials = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    list = OFFSET_PTR(NNSG3dResDict, materials, materials->mOfsDictPlttToMatList);
    for (entryIndex = 0; entryIndex < list->mNumEntry; entryIndex++) {
        table = OFFSET_PTR(NNSG3dResDictEntryHeader, list, list->mOfsEntry);
        binding = DICT_ENTRY(NNSG3dResDictTexToMatIdxData, table, entryIndex);
        if ((binding->mFlag & 1) != 0) {
            binding->mFlag &= ~1;
        }
    }
}

u32 NNS_G3dReleaseMdlPlttEx(NNSG3dResMdl *mdl, const u32 *name) {
    NNSG3dResMat *materials;
    NNSG3dResDictTexToMatIdxData *binding;

    materials = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    binding = NNS_G3dGetResDataByName((u8 *) materials + materials->mOfsDictPlttToMatList, name);
    if (binding != 0 && (binding->mFlag & 1) != 0) {
        binding->mFlag &= ~1;
        return 1;
    }
    return 0;
}

// Returns 0 when a name is missing.
u32 NNS_G3dBindMdlSet(NNSG3dResMdlSet *mdlSet, NNSG3dResTex *tex) {
    u32 modelIndex;
    u32 result;
    NNSG3dResDictEntryHeader *table;
    NNSG3dResMdl *model;

    result = 1;
    modelIndex = 0;
    if (modelIndex < mdlSet->mDict.mNumEntry) {
        do {
            table = OFFSET_PTR(NNSG3dResDictEntryHeader, &mdlSet->mDict, mdlSet->mDict.mOfsEntry);
            model = OFFSET_PTR(NNSG3dResMdl, mdlSet, *DICT_ENTRY(u32, table, modelIndex));
            result &= NNS_G3dBindMdlTex(model, tex);
            result &= NNS_G3dBindMdlPltt(model, tex);
            modelIndex++;
        } while (modelIndex < mdlSet->mDict.mNumEntry);
    }
    return result;
}

void NNS_G3dReleaseMdlSet(NNSG3dResMdlSet *mdlSet) {
    u32 modelIndex;
    NNSG3dResDictEntryHeader *table;
    NNSG3dResMdl *model;

    modelIndex = 0;
    if (modelIndex < mdlSet->mDict.mNumEntry) {
        do {
            table = OFFSET_PTR(NNSG3dResDictEntryHeader, &mdlSet->mDict, mdlSet->mDict.mOfsEntry);
            model = OFFSET_PTR(NNSG3dResMdl, mdlSet, *DICT_ENTRY(u32, table, modelIndex));
            NNS_G3dReleaseMdlTex(model);
            NNS_G3dReleaseMdlPltt(model);
            modelIndex++;
        } while (modelIndex < mdlSet->mDict.mNumEntry);
    }
}

// Fills the eight words of buffer with values that change from run to run: the tick counter, the vertical counter,
// the console's stored user data, the clock, the microphone, the touch panel and the buttons.
void OS_GetLowEntropyData(LowEntropyData *buffer) {
    u16 vcount;
    u8 *work;
    u8 *userInfo;
    u8 *macBytes;

    work = HW_MAIN_MEM_SYSTEM_BUF;
    userInfo = work + 0x80;
    macBytes = OFFSET_PTR(u8, userInfo, 0x74);
    vcount = reg_GX_VCOUNT;
    buffer->mTickAndVcount = OS_GetTickLo() | (vcount << 16);
    buffer->mUserDataAndTickCounter = (*OFFSET_PTR(u16, macBytes, 4) << 16) ^ (u32) gTickOverflowCount;
    buffer->mUserDataVblankAndGxStat = *OFFSET_PTR(u32, work, 0x3c) ^ ((gTickOverflowCount >> 32) ^ *(u32 *) macBytes);
    buffer->mUserDataVblankAndGxStat = buffer->mUserDataVblankAndGxStat ^ reg_G3X_GXSTAT;
    buffer->mClockFirst = *OFFSET_PTR(u32, work, 0x1e8);
    buffer->mClockSecond = *OFFSET_PTR(u32, work, 0x1ec);
    buffer->mMicrophone = *OFFSET_PTR(u32, work, 0x390) ^ (*OFFSET_PTR(u16, work, 0x394) << 16);
    buffer->mTouchPanel = (*OFFSET_PTR(u16, work, 0x3aa) << 16) | *OFFSET_PTR(u16, work, 0x3ac);
    buffer->mTouchRssiAndButtons = reg_PAD_KEYINPUT | *HW_BUTTON_XY_BUF | (*OFFSET_PTR(u16, work, 0x398) << 16);
}

// Sets the locked-bank mask and the nine bank lock ids to 0.
void OSi_InitVramExclusive(void) {
    s32 bankIndex;

    gVramBankLockedMask = 0;
    for (bankIndex = 0; bankIndex < 9; bankIndex++) {
        gVramBankLockIds[bankIndex] = 0;
    }
}

// Under OS_DisableInterrupts: returns 0 and changes nothing when a bank of bank is already locked with an id other
// than lockId. Otherwise locks every bank of bank & 0x1ff with lockId and returns 1.
u32 OSi_TryLockVram(u32 bank, u16 lockId) {
    u32 remainingBanks;
    u32 enabled;
    s32 bankIndex;

    enabled = OS_DisableInterrupts();
    remainingBanks = bank & gVramBankLockedMask;
    while (1) {
        bankIndex = 31 - OsCountZeroBits(remainingBanks);
        if (bankIndex < 0) {
            break;
        }
        BIT_CLEAR(remainingBanks, bankIndex);
        if (lockId != gVramBankLockIds[bankIndex]) {
            OS_RestoreInterrupts(enabled);
            return 0;
        }
    }
    remainingBanks = bank & 0x1ff;
    while (1) {
        bankIndex = 31 - OsCountZeroBits(remainingBanks);
        if (bankIndex < 0) {
            break;
        }
        BIT_CLEAR(remainingBanks, bankIndex);
        gVramBankLockIds[bankIndex] = lockId;
        BIT_SET(gVramBankLockedMask, bankIndex);
    }
    OS_RestoreInterrupts(enabled);
    return 1;
}

// Under OS_DisableInterrupts: for each locked bank of bank & 0x1ff whose lock id equals lockId, clears the lock bit
// and the id. Other banks are left alone.
void OSi_UnlockVram(u32 bank, u16 lockId) {
    u32 remainingBanks;
    u32 enabled;
    s32 bankIndex;

    enabled = OS_DisableInterrupts();
    remainingBanks = bank & gVramBankLockedMask & 0x1ff;
    while (1) {
        bankIndex = 31 - OsCountZeroBits(remainingBanks);
        if (bankIndex < 0) {
            break;
        }
        BIT_CLEAR(remainingBanks, bankIndex);
        if (lockId == gVramBankLockIds[bankIndex]) {
            gVramBankLockIds[bankIndex] = 0;
            BIT_CLEAR(gVramBankLockedMask, bankIndex);
        }
    }
    OS_RestoreInterrupts(enabled);
}

// clang-format off
// Counts the leading zero bits of bitmap.
asm u32 OsCountZeroBits(u32 bitmap) {
    clz r0, r0
    bx lr
}
// clang-format on
