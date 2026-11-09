#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/unk_02152000.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_02170000.h"
#include "Main/Unknown/unk_02173000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/code_020846c0.h" // Nsbmd
#include "code_0200c914.h"
#include "code_02010c84.h"
#include "code_0214c778.h"
#include "cp_context.h"
#include "registers.h"

void NNS_G3dGeSetBuffer(GxCommandBuffer *a) {
    if (NNS_G3dGeBuffer == 0) {
        a->mWordCount = 0;
        NNS_G3dGeBuffer = a;
    }
}

GxCommandBuffer *NNS_G3dGeReleaseBuffer(void) {
    GxCommandBuffer *p;

    NNS_G3dGeFlushBuffer();
    p = NNS_G3dGeBuffer;
    NNS_G3dGeBuffer = 0;
    return p;
}
// clang-format on

void NNS_G3dGeFlushBuffer(void) {
    if (NNS_G3dFlagGXDmaAsync != 0) {
        NNS_G3dGeWaitSendDL();
    }
    if (NNS_G3dGeBuffer == 0) {
        return;
    }
    if (NNS_G3dGeBuffer->mWordCount == 0) {
        return;
    }
    MIi_CpuSend32(NNS_G3dGeBuffer->mWords, &reg_G3X_GXFIFO, NNS_G3dGeBuffer->mWordCount * 4);
    NNS_G3dGeBuffer->mWordCount = 0;
}

void NNS_G3dGeWaitSendDL(void) {
    while (NNS_G3dFlagGXDmaAsync != 0) {
    }
}

void simpleUnlock_(u32 *a) {
    *a = 0;
}

void NNS_G3dGeSendDL(const void *commands, u32 commandLength) {
    if (commandLength < 0x100 || data_0216f074[0] == 0xffffffff) {
        NNS_G3dGeBufferOP_N(*(u32 *) commands, commands + 4, (commandLength >> 2) - 1);
        return;
    }
    NNS_G3dGeFlushBuffer();
    NNS_G3dFlagGXDmaAsync = 1;
    if (NNS_G3dFlagUseFastDma != 0) {
        MI_SendGXCommandAsyncFast(data_0216f074[0], commands, commandLength, (MIDmaCallback) simpleUnlock_,
                                  &NNS_G3dFlagGXDmaAsync);
    } else {
        MI_SendGXCommandAsync(data_0216f074[0], commands, commandLength, (MIDmaCallback) simpleUnlock_,
                              &NNS_G3dFlagGXDmaAsync);
    }
}

void NNS_G3dGeBufferOP_N(u32 command, const void *parameters, u32 parameterCount) {
    u32 wordCount;

    if (NNS_G3dGeBuffer != 0) {
        if (NNS_G3dFlagGXDmaAsync != 0) {
            wordCount = NNS_G3dGeBuffer->mWordCount;
            if (wordCount + 1 + parameterCount <= 0xc0) {
                NNS_G3dGeBuffer->mWordCount = wordCount + 1;
                NNS_G3dGeBuffer->mWords[wordCount] = command;
                if (parameterCount == 0) {
                    return;
                }
                MIi_CpuCopyFast(parameters, &NNS_G3dGeBuffer->mWords[NNS_G3dGeBuffer->mWordCount], parameterCount * 4);
                NNS_G3dGeBuffer->mWordCount += parameterCount;
                return;
            }
        }
        if (NNS_G3dGeBuffer->mWordCount != 0) {
            NNS_G3dGeFlushBuffer();
        } else if (NNS_G3dFlagGXDmaAsync != 0) {
            NNS_G3dGeWaitSendDL();
        }
    } else if (NNS_G3dFlagGXDmaAsync != 0) {
        NNS_G3dGeWaitSendDL();
    }
    reg_G3X_GXFIFO = command;
    MIi_CpuSend32(parameters, &reg_G3X_GXFIFO, parameterCount * 4);
}

void func_01ff8ff8(NNSG3dRS *s) {
    u32 v1;

    do {
        s->mFlag &= ~0x40;
        v1 = s->mC[0];
        data_usa_0216196c[v1 & 0x1f](s, v1 & 0xe0);
    } while (!(s->mFlag & 0x20));
}

void func_01ff8e64(NNSG3dRS *s, NNSG3dRenderObj *i) {
    MemFillWordsByBlock_inline(s, 0x188);
    s->mIsScaleCacheOne[0] = 1;
    s->mFlag = 1;
    if (i->mPtrUserSbc != 0) {
        s->mC = i->mPtrUserSbc;
    } else {
        s->mC = (u8 *) i->mResMdl + i->mResMdl->mOfsSbc;
    }
    s->mRenderObj = i;
    s->mResNodeInfo = OFFSET_PTR(Unk02170500_d4, i->mResMdl, 0x40);
    s->mResMat = OFFSET_PTR(NNSG3dResMat, i->mResMdl, i->mResMdl->mOfsMat);
    s->mResShp = (u8 *) i->mResMdl + i->mResMdl->mOfsShp;
    s->mUnk_e8 = data_usa_02161850[i->mResMdl->mInfo.mScalingRule];
    s->mUnk_ec = data_usa_02161844[i->mResMdl->mInfo.mScalingRule];
    s->mUnk_f0 = data_0216185c[i->mResMdl->mInfo.mTexMtxMode];
    s->mUnk_e0 = i->mResMdl->mInfo.mPosScale;
    s->mUnk_e4 = i->mResMdl->mInfo.mInvPosScale;
    if (i->mCbFunc != 0 && i->mCbCmd < 0x20) {
        s->mCbVecFunc[i->mCbCmd] = i->mCbFunc;
        s->mCbVecTiming[i->mCbCmd] = i->mCbTiming;
    }
    if (i->mFlag & 1) {
        s->mFlag |= 0x80;
    }
    if (i->mFlag & 2) {
        s->mFlag |= 0x100;
    }
    if (i->mFlag & 4) {
        s->mFlag |= 0x200;
    }
    if (i->mFlag & 8) {
        s->mFlag |= 0x400;
    }
    if (i->mCbInitFunc != 0) {
        i->mCbInitFunc(s);
    }
    func_01ff8ff8(s);
    i->mFlag &= ~1;
}

void func_01ff8dec(u32 *a, NNSG3dAnmObj *b) {
    s32 i;

    if (b == 0) {
        return;
    }
    do {
        for (i = 0; i < b->mNumMapData; i++) {
            if (b->mMapData[i] & 0x100) {
                a[i >> 5] |= 1 << (i & 0x1f);
            }
        }
        b = b->mNext;
    } while (b != 0);
}

void DrawNsbmdRenderObj(Nsbmd *object) {
    NNSG3dRenderObj *renderObj;
    NNSG3dRS renderState;

    renderObj = &object->mRenderObj;
    if ((renderObj->mFlag & 0x10) == 0x10) {
        func_01ff8cf0_inline(renderObj->mHintMatAnmExist);
        func_01ff8cf0_inline(renderObj->mHintJntAnmExist);
        func_01ff8cf0_inline(renderObj->mHintVisAnmExist);
        if (renderObj->mAnmMat != 0) {
            func_01ff8dec(renderObj->mHintMatAnmExist, renderObj->mAnmMat);
        }
        if (renderObj->mAnmJnt != 0) {
            func_01ff8dec(renderObj->mHintJntAnmExist, renderObj->mAnmJnt);
        }
        if (renderObj->mAnmVis != 0) {
            func_01ff8dec(renderObj->mHintVisAnmExist, renderObj->mAnmVis);
        }
        renderObj->mFlag &= ~0x10;
    }
    if (data_02170500 != 0) {
        func_01ff8e64(data_02170500, renderObj);
        return;
    }
    data_02170500 = &renderState;
    func_01ff8e64(&renderState, renderObj);
    data_02170500 = 0;
}

void func_01ff8cc4(NNSG3dRS *s, u32 a) {
    if (s->mCbVecFunc[0] != 0) {
        s->mCbVecFunc[0](s);
    }
    s->mC += 1;
}

void func_01ff8c98(NNSG3dRS *s, u32 a) {
    if (s->mCbVecFunc[1] != 0) {
        s->mCbVecFunc[1](s);
    }
    s->mFlag |= 0x20;
}

void func_01ff8b98(NNSG3dRS *s, u32 a) {
    u32 w;
    u32 v1;
    NNSG3dRenderObj *i;

    if (!(s->mFlag & 0x200)) {
        s->mCurrentNode = s->mC[1];
        v1 = s->mCurrentNode;
        s->mFlag |= 4;
        s->mVisAnmResult = &s->mUnk_184;
        if (s->mCbVecFunc[2] != 0) {
            w = s->mCbVecTiming[2];
        } else {
            w = 0;
        }
        i = s->mRenderObj;
        if (i->mAnmVis == 0 || !(i->mHintVisAnmExist[v1 >> 5] & (1 << (v1 & 0x1f))) ||
            i->mFuncBlendVis(s->mVisAnmResult, i->mAnmVis, v1) == 0) {
            s->mVisAnmResult->mIsVisible = s->mC[2] & 1;
        }
        if (s->mVisAnmResult->mIsVisible != 0) {
            s->mFlag |= 1;
        } else {
            s->mFlag &= ~1;
        }
        if (w == 3) {
            s->mFlag &= ~0x40;
            s->mCbVecFunc[2](s);
        }
    }
    s->mC += 3;
}

void func_01ff8b08(NNSG3dRS *s, u32 a) {
    u32 w;
    u32 v;

    if (!(s->mFlag & 0x200) && (s->mFlag & 1)) {
        if (s->mCbVecFunc[3] != 0) {
            w = s->mCbVecTiming[3];
        } else {
            w = 0;
        }
        v = s->mC[1];
        if (!(s->mFlag & 0x100)) {
            NNS_G3dGeBufferOP_N(0x14, &v, 1);
        }
        if (w == 3) {
            s->mFlag &= ~0x40;
            s->mCbVecFunc[3](s);
        }
    }
    s->mC += 2;
}

void func_01ff8738(NNSG3dRS *s, u32 a, const u8 *e, u32 b) {
    u32 w;
    u32 m;
    u32 *d;
    NNSG3dMatAnmResult *o;
    NNSG3dMatAnmResult *v1;
    u8 *h;
    u8 *t;
    s32 k;
    u32 x;
    u32 y;
    u32 v2[8];
    s32 c;

    s->mCurrentMat = b;
    s->mFlag |= 8;
    s->mMatAnmResult = &s->mUnk_f4;
    if (s->mCbVecFunc[4] != 0) {
        w = s->mCbVecTiming[4];
    } else {
        w = 0;
    }
    v1 = s->mRenderObj->mRecMatAnm;
    if (v1 != 0 && !(s->mFlag & 0x80)) {
        o = v1 + b;
        goto done;
    }
    if (a == 0x20 || a == 0x40) {
        m = 1 << (b & 0x1f);
        if (s->mIsMatCached[b >> 5] & m) {
            if (v1 != 0) {
                o = v1 + b;
            } else {
                o = data_usa_021704e4 + b;
            }
            goto done;
        }
    }
    if (v1 != 0) {
        s->mIsMatCached[b >> 5] |= 1 << (b & 0x1f);
        o = s->mRenderObj->mRecMatAnm + b;
    } else if (a == 0x40) {
        s->mIsMatCached[b >> 5] |= 1 << (b & 0x1f);
        o = data_usa_021704e4 + b;
    } else {
        o = &s->mUnk_f4;
    }
    o->mUnk_00 = 0;
    h = (u8 *) s->mResMat;
    t = h + 4;
    c = *(u16 *) (t + *(u16 *) (h + 0xa));
    if (*(u16 *) (h + *(u32 *) (t + *(u16 *) (h + 0xa) + c * b + 4) + 0x1e) & 0x20) {
        o->mUnk_00 |= 0x20;
    }
    k = *OFFSET_PTR(u16, e, 0x1e);
    x = ((u32 *) data_usa_02152bec)[(k >> 6) & 7];
    o->mUnk_04 = (data_0217029c.mPrmMatColor0 & ~x) | (*OFFSET_PTR(u32, e, 4) & x);
    y = ((u32 *) data_usa_02152bec)[(*OFFSET_PTR(u16, e, 0x1e) >> 9) & 7];
    o->mUnk_08 = (data_0217029c.mPrmMatColor1 & ~y) | (*OFFSET_PTR(u32, e, 8) & y);
    x = *OFFSET_PTR(u32, e, 0x10);
    o->mUnk_0c = (data_0217029c.mPrmPolygonAttr & ~x) | (*OFFSET_PTR(u32, e, 0xc) & x);
    o->mUnk_10 = *OFFSET_PTR(u32, e, 0x14);
    o->mUnk_14 = *OFFSET_PTR(u16, e, 0x1c);
    k = *OFFSET_PTR(u16, e, 0x1e);
    if (k & 1) {
        d = OFFSET_PTR(u32, e, 0x2c);
        if (!(k & 2)) {
            o->mUnk_18[0] = d[0];
            o->mUnk_18[1] = d[1];
            d += 2;
        } else {
            o->mUnk_00 |= 1;
        }
        if (!(*OFFSET_PTR(u16, e, 0x1e) & 4)) {
            o->mUnk_20[0] = ((s16 *) d)[0];
            o->mUnk_20[1] = ((s16 *) d)[1];
            d = (u32 *) ((s16 *) d + 2);
        } else {
            o->mUnk_00 |= 2;
        }
        if (!(*OFFSET_PTR(u16, e, 0x1e) & 8)) {
            o->mUnk_24[0] = d[0];
            o->mUnk_24[1] = d[1];
        } else {
            o->mUnk_00 |= 4;
        }
        o->mUnk_00 |= 8;
    }
    if (s->mRenderObj->mAnmMat != 0 && (s->mRenderObj->mHintMatAnmExist[b >> 5] & (1 << (b & 0x1f)))) {
        s->mRenderObj->mFuncBlendMat(o, s->mRenderObj->mAnmMat, b);
    }
    if (o->mUnk_00 & 0x18) {
        o->mUnk_2c = *OFFSET_PTR(u16, e, 0x20);
        o->mUnk_2e = *OFFSET_PTR(u16, e, 0x22);
        o->mUnk_30 = *OFFSET_PTR(u32, e, 0x24);
        o->mUnk_34 = *OFFSET_PTR(u32, e, 0x28);
    }
done:
    s->mMatAnmResult = o;
    v1 = s->mMatAnmResult;
    if (v1->mUnk_0c & 0x1f0000) {
        if (v1->mUnk_00 & 0x20) {
            v1->mUnk_0c &= ~0x1f0000;
        }
        s->mFlag &= ~2;
        if (!(s->mFlag & 0x100)) {
            v2[0] = 0x293130;
            v2[1] = v1->mUnk_04;
            v2[2] = v1->mUnk_08;
            v2[3] = v1->mUnk_0c;
            v2[4] = 0x2b2a;
            v2[5] = v1->mUnk_10;
            v2[6] = v1->mUnk_14;
            NNS_G3dGeBufferOP_N(v2[0], &v2[1], 6);
            if (v1->mUnk_00 & 0x18) {
                s->mUnk_f0(v1);
            }
        }
    } else {
        s->mFlag |= 2;
    }
    if (w == 3) {
        s->mFlag &= ~0x40;
        s->mCbVecFunc[4](s);
    }
}

void func_01ff86b4(NNSG3dRS *s, u32 a) {
    u32 f;
    u8 *h;
    u8 *e;
    u32 v1;
    u8 *t;
    s32 b;

    f = s->mFlag;
    if (!(f & 0x200)) {
        v1 = s->mC[1];
        if ((f & 1) || !(f & 8) || v1 != s->mCurrentMat) {
            h = (u8 *) s->mResMat;
            t = h + 4;
            b = *(u16 *) (t + *(u16 *) (h + 0xa));
            e = h + *(u32 *) (t + *(u16 *) (h + 0xa) + b * v1 + 4);
            data_usa_0216187c[*(u16 *) e](s, a, e, v1);
        }
    }
    s->mC += 2;
}

void func_01ff8648(NNSG3dRS *s, u32 a, NNSG3dResShpData *c) {
    u32 w;

    if (s->mCbVecFunc[5] != 0) {
        w = s->mCbVecTiming[5];
    } else {
        w = 0;
    }
    if (!(s->mFlag & 0x100)) {
        NNS_G3dGeSendDL((u8 *) c + c->mOfsDL, c->mSizeDL);
    }
    if (w == 3) {
        s->mFlag &= ~0x40;
        s->mCbVecFunc[5](s);
    }
}

void func_01ff85d0(NNSG3dRS *s, u32 a) {
    u32 f;
    Unk02170500_d4 *b;
    u8 *e;
    u8 *t;
    u32 v1;

    f = s->mFlag;
    if (!(f & 0x200) && (f & 1) && !(f & 2)) {
        b = s->mResShp;
        v1 = s->mC[1];
        t = (u8 *) b + b->mUnk_06;
        e = (u8 *) b + *(u32 *) (t + *(u16 *) t * v1 + 4);
        data_usa_0216188c[*(u16 *) e](s, a, e, v1);
    }
    s->mC += 2;
}

void func_01ff8220(NNSG3dRS *s, u32 a) {
    s32 b0;
    s32 b1;
    enum { K0 } w;
    u32 t;
    u32 q;
    u32 t2;
    u32 n;
    NNSG3dJntAnmResult *o;
    u16 *r;
    s32 k;
    u32 v1;
    u32 f;
    u32 c;
    s32 v2;
    s32 m;
    u16 *p;
    u8 *h;
    u8 *e;
    NNSG3dRenderObj *i;
    u32 b;

    v1 = s->mC[1];
    n = 4;
    s->mCurrentNodeDesc = v1;
    s->mFlag |= 0x10;
    f = s->mFlag;
    if (f & 0x400) {
        if (a == 0x40 || a == 0x60) {
            n += 1;
        }
        if (a == 0x20 || a == 0x60) {
            n += 1;
            if (!(f & 0x100)) {
                t = s->mC[4];
                NNS_G3dGeBufferOP_N(0x14, &t, 1);
            }
        }
        s->mC += n;
        return;
    }
    if (a == 0x40 || a == 0x60) {
        n += 1;
        if (a == 0x40) {
            q = s->mC[4];
        } else {
            q = s->mC[5];
        }
        if (!(s->mFlag & 0x100)) {
            NNS_G3dGeBufferOP_N(0x14, &q, 1);
        }
    }
    s->mJntAnmResult = &s->mUnk_12c;
    if (s->mCbVecFunc[6] != 0) {
        w = s->mCbVecTiming[6];
    } else {
        w = 0;
    }
    if (s->mRenderObj->mRecJntAnm != 0) {
        o = s->mRenderObj->mRecJntAnm + v1;
        c = (s->mFlag & 0x80) == 0;
    } else {
        o = &s->mUnk_12c;
        c = 0;
    }
    if (c == 0) {
        o->mFlag = 0;
        i = s->mRenderObj;
        if (i->mAnmJnt != 0) {
            if (i->mFuncBlendJnt(o, i->mAnmJnt, v1) != 0) {
                goto done;
            }
        }
        h = s->mResNodeInfo;
        b = *(u16 *) (h + *(u16 *) (h + 6));
        e = h + *(u32 *) (h + *(u16 *) (h + 6) + b * v1 + 4);
        p = (u16 *) e;
        r = OFFSET_PTR(u16, e, 4);
        if (!(*p & 1)) {
            o->mTrans.x = ((s32 *) r)[0];
            o->mTrans.y = ((s32 *) r)[1];
            o->mTrans.z = ((s32 *) r)[2];
            r += 6;
        } else {
            o->mFlag |= 4;
        }
        v2 = *p;
        if (v2 & 2) {
            o->mFlag |= 2;
        } else if (v2 & 8) {
            k = (v2 & 0xf0) >> 4;
            b1 = ((s16 *) r)[1];
            b0 = ((s16 *) r)[0];
            MI_Zero36B(&o->mRot);
            r += 2;
            m = (*p & 0x100) ? -0x1000 : 0x1000;
            o->mRot.mUnk_00_a[k] = m;
            o->mRot.mUnk_00_a[data_usa_02152c0c[k][0]] = b0;
            o->mRot.mUnk_00_a[data_usa_02152c0d[k][0]] = b1;
            if (*p & 0x200) {
                b1 = -b1;
            }
            o->mRot.mUnk_00_a[data_usa_02152c0e[k][0]] = b1;
            if (*p & 0x400) {
                b0 = -b0;
            }
            o->mRot.mUnk_00_a[data_usa_02152c0f[k][0]] = b0;
        } else {
            o->mRot.mUnk_00_a[0] = ((s16 *) p)[1];
            o->mRot.mUnk_00_a[1] = ((s16 *) r)[0];
            o->mRot.mUnk_00_a[2] = ((s16 *) r)[1];
            o->mRot.mUnk_00_a[3] = ((s16 *) r)[2];
            o->mRot.mUnk_00_a[4] = ((s16 *) r)[3];
            o->mRot.mUnk_00_a[5] = ((s16 *) r)[4];
            o->mRot.mUnk_00_a[6] = ((s16 *) r)[5];
            o->mRot.mUnk_00_a[7] = ((s16 *) r)[6];
            o->mRot.mUnk_00_a[8] = ((s16 *) r)[7];
            r += 8;
        }
        s->mUnk_e8(o, r, s->mC, *p);
    }
done:
    s->mJntAnmResult = o;
    if (!(s->mFlag & 0x100)) {
        s->mUnk_ec(s->mJntAnmResult);
    }
    c = 0;
    s->mJntAnmResult = 0;
    if (w == 3) {
        s->mFlag &= ~0x40;
        s->mCbVecFunc[6](s);
        c = s->mFlag & 0x40;
    }
    if (a == 0x20 || a == 0x60) {
        n += 1;
        if (c == 0 && !(s->mFlag & 0x100)) {
            t2 = s->mC[4];
            NNS_G3dGeBufferOP_N(0x13, &t2, 1);
        }
    }
    s->mC += n;
}

void func_01ff81b4(NNSG3dRS *s, u32 a) {
    s32 v[3];
    s32 x;

    if (!(s->mFlag & 0x100) && !(s->mFlag & 0x200)) {
        if (a == 0) {
            x = s->mUnk_e0;
            v[2] = x;
            v[1] = x;
            v[0] = x;
        } else {
            x = s->mUnk_e4;
            v[2] = x;
            v[1] = x;
            v[0] = x;
        }
        NNS_G3dGeBufferOP_N(0x1b, v, 3);
    }
    s->mC += 1;
}

// clang-format off
// Interrupt dispatch: reads the interrupt flag and enable registers (0x04000210), takes the highest set bit with clz,
// acknowledges it, and runs the function in OS_IRQTable for that bit with lr set to func_01ff8058.
// Not compiled code: it jumps with a set return address instead of a call (ldr lr, bx).
asm void func_01ff8000(void) {
    stmdb sp!, {lr}
    mov ip, #0x4000000
    add ip, ip, #0x210
    ldr r1, [ip, #-0x8]
    cmp r1, #0x0
    ldmeqia sp!, {pc}
    ldmia ip, {r1, r2}
    ands r1, r1, r2
    ldmeqia sp!, {pc}
    mov r3, #0x80000000
L_loop:
    clz r0, r1
    bics r1, r1, r3, lsr r0
    bne L_loop
    mov r1, r3, lsr r0
    str r1, [ip, #0x4]
    rsbs r0, r0, #0x1f
    ldr r1, =OS_IRQTable
    ldr r0, [r1, r0, lsl #0x2]
    ldr lr, =func_01ff8058
    bx r0
}
// clang-format on

// clang-format off
// OSThread switch after an interrupt: clears the pending flags of the thread list at data_027e0000, then saves the
// registers of the running thread in its context and loads those of the first runnable thread.
// Not compiled code: it switches processor modes and moves the whole register set with the user-bank forms of stm and
// ldm (msr, mrs, ^).
asm void func_01ff8058(void) {
    mov r2, #0x1
    mov r3, #0x0
    ldr ip, =data_027e0000
    ldr ip, [ip, #0x0]
    cmp ip, #0x0
    beq L_01ff80a8
L_01ff8070:
    str r2, [ip, #0x64]
    str r3, [ip, #0x78]
    str r3, [ip, #0x7c]
    ldr r0, [ip, #0x80]
    str r3, [ip, #0x80]
    mov ip, r0
    cmp ip, #0x0
    bne L_01ff8070
    ldr ip, =data_027e0000
    str r3, [ip, #0x0]
    str r3, [ip, #0x4]
    ldr ip, =data_0216ff5c
    mov r1, #0x1
    strh r1, [ip, #0x0]
L_01ff80a8:
    ldr ip, =data_0216ff5c
    ldrh r1, [ip, #0x0]
    cmp r1, #0x0
    ldreq pc, [sp], #0x4
    mov r1, #0x0
    strh r1, [ip, #0x0]
    mov r3, #0xd2
    msr cpsr_c, r3
    add r2, ip, #0x8
    ldr r1, [r2, #0x0]
L_01ff80d0:
    cmp r1, #0x0
    ldrneh r0, [r1, #0x64]
    cmpne r0, #0x1
    ldrne r1, [r1, #0x68]
    bne L_01ff80d0
    cmp r1, #0x0
    bne L_01ff80f8
L_01ff80ec:
    mov r3, #0x92
    msr cpsr_c, r3
    ldr pc, [sp], #0x4
L_01ff80f8:
    ldr r0, [ip, #0x4]
    cmp r1, r0
    beq L_01ff80ec
    ldr r3, [ip, #0xc]
    cmp r3, #0x0
    beq L_01ff8120
    stmdb sp!, {r0, r1, ip}
    mov lr, pc
    bx r3
    ldmia sp!, {r0, r1, ip}
L_01ff8120:
    str r1, [ip, #0x4]
    mrs r2, spsr
    str r2, [r0, #0x0]!
    stmdb sp!, {r0, r1}
    add r0, r0, #0x0
    add r0, r0, #0x48
    ldr r1, =CP_SaveContext
    blx r1
    ldmia sp!, {r0, r1}
    ldmib sp!, {r2, r3}
    stmib r0!, {r2, r3}
    ldmib sp!, {r2, r3, ip, lr}
    stmib r0!, {r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, ip, sp, lr}^
    stmib r0!, {lr}
    mov r3, #0xd3
    msr cpsr_c, r3
    stmib r0!, {sp}
    stmdb sp!, {r1}
    add r0, r1, #0x0
    add r0, r0, #0x48
    ldr r1, =CPi_RestoreContext
    blx r1
    ldmia sp!, {r1}
    ldr sp, [r1, #0x44]
    mov r3, #0xd2
    msr cpsr_c, r3
    ldr r2, [r1, #0x0]!
    msr spsr_fc, r2
    ldr lr, [r1, #0x40]
    ldmib r1!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, ip, sp, lr}^
    mov r0, r0
    stmda sp!, {r0, r1, r2, r3, ip, lr}
    ldmia sp!, {pc}
}
// clang-format on
