#include "render_object_resources.h"
#include "render_object_callback_link.h"
#include "texture_required_size.h"
#include "texture_key_set.h"
#include "texture_vram_load.h"
#include "vram_load_3d_graphics.h"
#include "texture_pltt_size_key_release.h"
#include "texture_resource_type.h"

void addLink_(NNSG3dAnmObj **head, NNSG3dAnmObj *item) {
    NNSG3dAnmObj *prev;
    NNSG3dAnmObj *next;
    NNSG3dAnmObj *tail;

    prev = *head;
    if (prev == 0) {
        *head = item;
        return;
    }
    next = prev->mNext;
    if (next == 0) {
        if (prev->mPriority > item->mPriority) {
            tail = item;
            if (item->mNext != 0) {
                do {
                    tail = tail->mNext;
                } while (tail->mNext != 0);
            }
            tail->mNext = prev;
            *head = item;
            return;
        }
        prev->mNext = item;
        return;
    }
    while (next != 0) {
        if (next->mPriority >= item->mPriority) {
            tail = item;
            if (item->mNext != 0) {
                do {
                    tail = tail->mNext;
                } while (tail->mNext != 0);
            }
            prev->mNext = item;
            tail->mNext = next;
            return;
        }
        prev = next;
        next = next->mNext;
    }
    prev->mNext = item;
}

// Marks the entries the chain maps.
void updateHintVec_(u32 *pVec, const NNSG3dAnmObj *pAnmObj) {
    int mapIndex;

    while (pAnmObj != 0) {
        for (mapIndex = 0; mapIndex < pAnmObj->mNumMapData; mapIndex++) {
            if ((pAnmObj->mMapData[mapIndex] & 0x100) != 0) {
                pVec[mapIndex >> 5] |= 1 << (mapIndex & 31);
            }
        }
        pAnmObj = pAnmObj->mNext;
    }
}

void NNS_G3dRenderObjAddAnmObj(NNSG3dRenderObj *pRenderObj, NNSG3dAnmObj *pAnmObj) {
    NNSG3dResAnmHeader *header;

    header = pAnmObj->mResAnm;
    switch (header->mCategory0) {
        case 'M':
            updateHintVec_(pRenderObj->mHintMatAnmExist, pAnmObj);
            addLink_(&pRenderObj->mAnmMat, pAnmObj);
            break;
        case 'J':
            updateHintVec_(pRenderObj->mHintJntAnmExist, pAnmObj);
            addLink_(&pRenderObj->mAnmJnt, pAnmObj);
            break;
        case 'V':
            updateHintVec_(pRenderObj->mHintVisAnmExist, pAnmObj);
            addLink_(&pRenderObj->mAnmVis, pAnmObj);
            break;
    }
}

int removeLink_(NNSG3dAnmObj **head, NNSG3dAnmObj *item) {
    NNSG3dAnmObj *next;
    NNSG3dAnmObj *cur;

    cur = *head;
    if (cur == 0) {
        return 0;
    }
    if (cur == item) {
        *head = cur->mNext;
        item->mNext = 0;
        return 1;
    }
    next = cur->mNext;
    while (next != 0) {
        if (next == item) {
            cur->mNext = next->mNext;
            next->mNext = 0;
            return 1;
        }
        cur = next;
        next = next->mNext;
    }
    return 0;
}

void NNS_G3dRenderObjRemoveAnmObj(NNSG3dRenderObj *pRenderObj, NNSG3dAnmObj *pAnmObj) {
    if (removeLink_(&pRenderObj->mAnmMat, pAnmObj) != 0 || removeLink_(&pRenderObj->mAnmJnt, pAnmObj) != 0 ||
        removeLink_(&pRenderObj->mAnmVis, pAnmObj) != 0) {
        pRenderObj->mFlag |= RENDER_OBJ_HINTS_STALE;
    }
}

void NNS_G3dRenderObjSetCallBack(NNSG3dRenderObj *pRenderObj, NNSG3dSbcCallBackFunc func, u8 *unused, u8 cmd,
                                 u32 timing) {
    pRenderObj->mCbFunc = func;
    pRenderObj->mCbCmd = cmd;
    pRenderObj->mCbTiming = timing;
}

u32 NNS_G3dTexGetRequiredSize(const NNSG3dResTex *pTex) {
    return pTex->mTexInfo.mSizeTex << 3;
}

u32 NNS_G3dTex4x4GetRequiredSize(const NNSG3dResTex *pTex) {
    return pTex->mTex4x4Info.mSizeTex << 3;
}

void NNS_G3dTexSetTexKey(NNSG3dResTex *pTex, NNSG3dTexKey texKey, NNSG3dTexKey tex4x4Key) {
    if (texKey != 0) {
        pTex->mTexInfo.mVramKey = texKey;
    }
    if (tex4x4Key != 0) {
        pTex->mTex4x4Info.mVramKey = tex4x4Key;
    }
}

void NNS_G3dTexLoad(NNSG3dResTex *pTex, BOOL execBeginEnd) {
    u32 texSize;
    u32 tex4x4Size;
    u32 keyAddr;
    u32 vramAddr;
    u8 *plttIdxData;

    if (execBeginEnd != 0) {
        GX_BeginLoadTex();
    }
    texSize = pTex->mTexInfo.mSizeTex << 3;
    if (texSize != 0) {
        GX_LoadTex((u8 *) pTex + pTex->mTexInfo.mOfsTex, (pTex->mTexInfo.mVramKey & VRAM_HANDLE_OFFSET_MASK) << 3,
                   texSize);
        pTex->mTexInfo.mFlag |= 1;
    }
    tex4x4Size = pTex->mTex4x4Info.mSizeTex << 3;
    if (tex4x4Size != 0) {
        keyAddr = pTex->mTex4x4Info.mVramKey & VRAM_HANDLE_OFFSET_MASK;
        vramAddr = keyAddr << 3;
        plttIdxData = (u8 *) pTex + pTex->mTex4x4Info.mOfsTexPlttIdx;
        GX_LoadTex((u8 *) pTex + pTex->mTex4x4Info.mOfsTex, vramAddr, tex4x4Size);
        GX_LoadTex(plttIdxData, 0x20000 + (((keyAddr << 3) & 0x1ffff) >> 1) + ((vramAddr & 0x40000) >> 2),
                   tex4x4Size >> 1);
        pTex->mTex4x4Info.mFlag |= 1;
    }
    if (execBeginEnd != 0) {
        GX_EndLoadTex();
    }
}

void NNS_G3dTexReleaseTexKey(NNSG3dResTex *pTex, NNSG3dTexKey *texKey, NNSG3dTexKey *tex4x4Key) {
    pTex->mTexInfo.mFlag &= ~1;
    pTex->mTex4x4Info.mFlag &= ~1;
    *texKey = pTex->mTexInfo.mVramKey;
    pTex->mTexInfo.mVramKey = 0;
    *tex4x4Key = pTex->mTex4x4Info.mVramKey;
    pTex->mTex4x4Info.mVramKey = 0;
}

u32 NNS_G3dPlttGetRequiredSize(const NNSG3dResTex *pTex) {
    return pTex->mPlttInfo.mSizePltt << 3;
}

void NNS_G3dPlttSetPlttKey(NNSG3dResTex *pTex, NNSG3dPlttKey plttKey) {
    pTex->mPlttInfo.mVramKey = plttKey;
}

void NNS_G3dPlttLoad(NNSG3dResTex *pTex, BOOL execBeginEnd) {
    if (execBeginEnd != 0) {
        GX_BeginLoadTexPltt();
    }
    GX_LoadTexPltt((u8 *) pTex + pTex->mPlttInfo.mOfsPlttData,
                   (pTex->mPlttInfo.mVramKey & VRAM_HANDLE_OFFSET_MASK) << 3, pTex->mPlttInfo.mSizePltt << 3);
    pTex->mPlttInfo.mFlag |= 1;
    if (execBeginEnd != 0) {
        GX_EndLoadTexPltt();
    }
}

NNSG3dPlttKey NNS_G3dPlttReleasePlttKey(NNSG3dResTex *pTex) {
    NNSG3dPlttKey plttKey;

    pTex->mPlttInfo.mFlag &= ~1;
    plttKey = pTex->mPlttInfo.mVramKey;
    pTex->mPlttInfo.mVramKey = 0;
    return plttKey;
}
