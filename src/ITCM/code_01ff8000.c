#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/unk_02152000.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_02170000.h"
#include "Main/Unknown/unk_02173000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0200c914.h"
#include "code_02010c84.h"
#include "code_0214c778.h"
#include "cp_context.h"
#include "registers.h"

void NNS_G3dGeSetBuffer(Unk01ff9048 *a) {
    if (NNS_G3dGeBuffer == 0) {
        a->field0 = 0;
        NNS_G3dGeBuffer = a;
    }
}

Unk01ff9048 *NNS_G3dGeReleaseBuffer(void) {
    Unk01ff9048 *p;

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
    if (NNS_G3dGeBuffer->field0 == 0) {
        return;
    }
    MIi_CpuSend32(NNS_G3dGeBuffer->field4, &reg_G3X_GXFIFO, NNS_G3dGeBuffer->field0 * 4);
    NNS_G3dGeBuffer->field0 = 0;
}

void NNS_G3dGeWaitSendDL(void) {
    while (NNS_G3dFlagGXDmaAsync != 0) {
    }
}

void func_01ff9210(u32 *a) {
    *a = 0;
}

void NNS_G3dGeSendDL(const void *a, u32 b) {
    if (b < 0x100 || GXi_DmaId[0] == 0xffffffff) {
        NNS_G3dGeBufferOP_N(*(u32 *) a, a + 4, (b >> 2) - 1);
        return;
    }
    NNS_G3dGeFlushBuffer();
    NNS_G3dFlagGXDmaAsync = 1;
    if (NNS_G3dFlagUseFastDma != 0) {
        MI_SendGXCommandAsyncFast(GXi_DmaId[0], a, b, (MIDmaCallback) func_01ff9210, &NNS_G3dFlagGXDmaAsync);
    } else {
        MI_SendGXCommandAsync(GXi_DmaId[0], a, b, (MIDmaCallback) func_01ff9210, &NNS_G3dFlagGXDmaAsync);
    }
}

void NNS_G3dGeBufferOP_N(u32 a, const void *b, u32 n) {
    u32 c;

    if (NNS_G3dGeBuffer != 0) {
        if (NNS_G3dFlagGXDmaAsync != 0) {
            c = NNS_G3dGeBuffer->field0;
            if (c + 1 + n <= 0xc0) {
                NNS_G3dGeBuffer->field0 = c + 1;
                NNS_G3dGeBuffer->field4[c] = a;
                if (n == 0) {
                    return;
                }
                MIi_CpuCopyFast(b, &NNS_G3dGeBuffer->field4[NNS_G3dGeBuffer->field0], n * 4);
                NNS_G3dGeBuffer->field0 += n;
                return;
            }
        }
        if (NNS_G3dGeBuffer->field0 != 0) {
            NNS_G3dGeFlushBuffer();
        } else if (NNS_G3dFlagGXDmaAsync != 0) {
            NNS_G3dGeWaitSendDL();
        }
    } else if (NNS_G3dFlagGXDmaAsync != 0) {
        NNS_G3dGeWaitSendDL();
    }
    reg_G3X_GXFIFO = a;
    MIi_CpuSend32(b, &reg_G3X_GXFIFO, n * 4);
}

void G3dDrawInternal_Loop_(Unk02170500 *s) {
    u32 v1;

    do {
        s->field8 &= ~0x40;
        v1 = s->field0[0];
        NNS_G3dFuncSbcTable[v1 & 0x1f](s, v1 & 0xe0);
    } while (!(s->field8 & 0x20));
}

void G3dDrawInternal_(Unk02170500 *s, Unk02170500_04 *i) {
    MemFillWordsByBlock_inline(s, 0x188);
    s->fieldC4[0] = 1;
    s->field8 = 1;
    if (i->field30 != 0) {
        s->field0 = i->field30;
    } else {
        s->field0 = (u8 *) i->field4 + i->field4->field4;
    }
    s->field4 = i;
    s->fieldD4 = OFFSET_PTR(Unk02170500_d4, i->field4, 0x40);
    s->fieldD8 = (u8 *) i->field4 + i->field4->field8;
    s->fieldDC = (u8 *) i->field4 + i->field4->fieldC;
    s->fieldE8 = (UnkFunc *) data_02161850[i->field4->field15];
    s->fieldEC = data_02161844[i->field4->field15];
    s->fieldF0 = NNS_G3dSendTexSRT_FuncArray[i->field4->field16];
    s->fieldE0 = i->field4->field1C;
    s->fieldE4 = i->field4->field20;
    if (i->field20 != 0 && i->field24 < 0x20) {
        s->fieldC[i->field24] = i->field20;
        s->field8C[i->field24] = i->field25;
    }
    if (i->field0 & 1) {
        s->field8 |= 0x80;
    }
    if (i->field0 & 2) {
        s->field8 |= 0x100;
    }
    if (i->field0 & 4) {
        s->field8 |= 0x200;
    }
    if (i->field0 & 8) {
        s->field8 |= 0x400;
    }
    if (i->field28 != 0) {
        i->field28(s);
    }
    G3dDrawInternal_Loop_(s);
    i->field0 &= ~1;
}

void updateHintVec__0(u32 *a, NNSG3dAnmObj *b) {
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

void NNS_G3dDraw(void *a) {
    Unk02170500_04 *i;
    Unk02170500 v1;

    i = a;
    if ((i->field0 & 0x10) == 0x10) {
        func_01ff8cf0_inline(i->field3C);
        func_01ff8cf0_inline(i->field44);
        func_01ff8cf0_inline(i->field4C);
        if (i->field8 != 0) {
            updateHintVec__0(i->field3C, i->field8);
        }
        if (i->field10 != 0) {
            updateHintVec__0(i->field44, i->field10);
        }
        if (i->field18 != 0) {
            updateHintVec__0(i->field4C, i->field18);
        }
        i->field0 &= ~0x10;
    }
    if (data_02170500 != 0) {
        G3dDrawInternal_(data_02170500, i);
        return;
    }
    data_02170500 = &v1;
    G3dDrawInternal_(&v1, i);
    data_02170500 = 0;
}

void NNSi_G3dFuncSbc_NOP(Unk02170500 *s, u32 a) {
    if (s->fieldC[0] != 0) {
        s->fieldC[0](s);
    }
    s->field0 += 1;
}

void NNSi_G3dFuncSbc_RET(Unk02170500 *s, u32 a) {
    if (s->fieldC[1] != 0) {
        s->fieldC[1](s);
    }
    s->field8 |= 0x20;
}

void NNSi_G3dFuncSbc_NODE(Unk02170500 *s, u32 a) {
    u32 w;
    u32 v1;
    Unk02170500_04 *i;

    if (!(s->field8 & 0x200)) {
        s->fieldAC = s->field0[1];
        v1 = s->fieldAC;
        s->field8 |= 4;
        s->fieldB8 = &s->field184;
        if (s->fieldC[2] != 0) {
            w = s->field8C[2];
        } else {
            w = 0;
        }
        i = s->field4;
        if (i->field18 == 0 || !(i->field4C[v1 >> 5] & (1 << (v1 & 0x1f))) ||
            i->field1C(s->fieldB8, i->field18, v1) == 0) {
            *s->fieldB8 = s->field0[2] & 1;
        }
        if (*s->fieldB8 != 0) {
            s->field8 |= 1;
        } else {
            s->field8 &= ~1;
        }
        if (w == 3) {
            s->field8 &= ~0x40;
            s->fieldC[2](s);
        }
    }
    s->field0 += 3;
}

void NNSi_G3dFuncSbc_MTX(Unk02170500 *s, u32 a) {
    u32 w;
    u32 v;

    if (!(s->field8 & 0x200) && (s->field8 & 1)) {
        if (s->fieldC[3] != 0) {
            w = s->field8C[3];
        } else {
            w = 0;
        }
        v = s->field0[1];
        if (!(s->field8 & 0x100)) {
            NNS_G3dGeBufferOP_N(0x14, &v, 1);
        }
        if (w == 3) {
            s->field8 &= ~0x40;
            s->fieldC[3](s);
        }
    }
    s->field0 += 2;
}

void NNSi_G3dFuncSbc_MAT_InternalDefault(Unk02170500 *s, u32 a, const u8 *e, u32 b) {
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

    s->fieldAD = b;
    s->field8 |= 8;
    s->fieldB0 = &s->fieldF4;
    if (s->fieldC[4] != 0) {
        w = s->field8C[4];
    } else {
        w = 0;
    }
    v1 = s->field4->field38;
    if (v1 != 0 && !(s->field8 & 0x80)) {
        o = v1 + b;
        goto done;
    }
    if (a == 0x20 || a == 0x40) {
        m = 1 << (b & 0x1f);
        if (s->fieldBC[b >> 5] & m) {
            if (v1 != 0) {
                o = v1 + b;
            } else {
                o = data_02170504 + b;
            }
            goto done;
        }
    }
    if (v1 != 0) {
        s->fieldBC[b >> 5] |= 1 << (b & 0x1f);
        o = s->field4->field38 + b;
    } else if (a == 0x40) {
        s->fieldBC[b >> 5] |= 1 << (b & 0x1f);
        o = data_02170504 + b;
    } else {
        o = &s->fieldF4;
    }
    o->field0 = 0;
    h = s->fieldD8;
    t = h + 4;
    c = *(u16 *) (t + *(u16 *) (h + 0xa));
    if (*(u16 *) (h + *(u32 *) (t + *(u16 *) (h + 0xa) + c * b + 4) + 0x1e) & 0x20) {
        o->field0 |= 0x20;
    }
    k = *OFFSET_PTR(u16, e, 0x1e);
    x = ((u32 *) matColorMask_)[(k >> 6) & 7];
    o->field4 = (NNS_G3dGlb.mPrmMatColor0 & ~x) | (*OFFSET_PTR(u32, e, 4) & x);
    y = ((u32 *) matColorMask_)[(*OFFSET_PTR(u16, e, 0x1e) >> 9) & 7];
    o->field8 = (NNS_G3dGlb.mPrmMatColor1 & ~y) | (*OFFSET_PTR(u32, e, 8) & y);
    x = *OFFSET_PTR(u32, e, 0x10);
    o->fieldC = (NNS_G3dGlb.mPrmPolygonAttr & ~x) | (*OFFSET_PTR(u32, e, 0xc) & x);
    o->field10 = *OFFSET_PTR(u32, e, 0x14);
    o->field14 = *OFFSET_PTR(u16, e, 0x1c);
    k = *OFFSET_PTR(u16, e, 0x1e);
    if (k & 1) {
        d = OFFSET_PTR(u32, e, 0x2c);
        if (!(k & 2)) {
            o->field18[0] = d[0];
            o->field18[1] = d[1];
            d += 2;
        } else {
            o->field0 |= 1;
        }
        if (!(*OFFSET_PTR(u16, e, 0x1e) & 4)) {
            o->field20[0] = ((s16 *) d)[0];
            o->field20[1] = ((s16 *) d)[1];
            d = (u32 *) ((s16 *) d + 2);
        } else {
            o->field0 |= 2;
        }
        if (!(*OFFSET_PTR(u16, e, 0x1e) & 8)) {
            o->field24[0] = d[0];
            o->field24[1] = d[1];
        } else {
            o->field0 |= 4;
        }
        o->field0 |= 8;
    }
    if (s->field4->field8 != 0 && (s->field4->field3C[b >> 5] & (1 << (b & 0x1f)))) {
        s->field4->fieldC(o, s->field4->field8, b);
    }
    if (o->field0 & 0x18) {
        o->field2C = *OFFSET_PTR(u16, e, 0x20);
        o->field2E = *OFFSET_PTR(u16, e, 0x22);
        o->field30 = *OFFSET_PTR(u32, e, 0x24);
        o->field34 = *OFFSET_PTR(u32, e, 0x28);
    }
done:
    s->fieldB0 = o;
    v1 = s->fieldB0;
    if (v1->fieldC & 0x1f0000) {
        if (v1->field0 & 0x20) {
            v1->fieldC &= ~0x1f0000;
        }
        s->field8 &= ~2;
        if (!(s->field8 & 0x100)) {
            v2[0] = 0x293130;
            v2[1] = v1->field4;
            v2[2] = v1->field8;
            v2[3] = v1->fieldC;
            v2[4] = 0x2b2a;
            v2[5] = v1->field10;
            v2[6] = v1->field14;
            NNS_G3dGeBufferOP_N(v2[0], &v2[1], 6);
            if (v1->field0 & 0x18) {
                s->fieldF0(v1);
            }
        }
    } else {
        s->field8 |= 2;
    }
    if (w == 3) {
        s->field8 &= ~0x40;
        s->fieldC[4](s);
    }
}

void NNSi_G3dFuncSbc_MAT(Unk02170500 *s, u32 a) {
    u32 f;
    u8 *h;
    u8 *e;
    u32 v1;
    u8 *t;
    s32 b;

    f = s->field8;
    if (!(f & 0x200)) {
        v1 = s->field0[1];
        if ((f & 1) || !(f & 8) || v1 != s->fieldAD) {
            h = s->fieldD8;
            t = h + 4;
            b = *(u16 *) (t + *(u16 *) (h + 0xa));
            e = h + *(u32 *) (t + *(u16 *) (h + 0xa) + b * v1 + 4);
            NNS_G3dFuncSbcMatTable[*(u16 *) e](s, a, e, v1);
        }
    }
    s->field0 += 2;
}

void NNSi_G3dFuncSbc_SHP_InternalDefault(Unk02170500 *s, u32 a, NNSG3dResShpData *c) {
    u32 w;

    if (s->fieldC[5] != 0) {
        w = s->field8C[5];
    } else {
        w = 0;
    }
    if (!(s->field8 & 0x100)) {
        NNS_G3dGeSendDL((u8 *) c + c->mOfsDL, c->mSizeDL);
    }
    if (w == 3) {
        s->field8 &= ~0x40;
        s->fieldC[5](s);
    }
}

void NNSi_G3dFuncSbc_SHP(Unk02170500 *s, u32 a) {
    u32 f;
    Unk02170500_d4 *b;
    u8 *e;
    u8 *t;
    u32 v1;

    f = s->field8;
    if (!(f & 0x200) && (f & 1) && !(f & 2)) {
        b = (Unk02170500_d4 *) s->fieldDC;
        v1 = s->field0[1];
        t = (u8 *) b + b->field6;
        e = (u8 *) b + *(u32 *) (t + *(u16 *) t * v1 + 4);
        NNS_G3dFuncSbcShpTable[*(u16 *) e](s, a, e, v1);
    }
    s->field0 += 2;
}

void NNSi_G3dFuncSbc_NODEDESC(Unk02170500 *s, u32 a) {
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
    Unk02170500_04 *i;
    u32 b;

    v1 = s->field0[1];
    n = 4;
    s->fieldAE = v1;
    s->field8 |= 0x10;
    f = s->field8;
    if (f & 0x400) {
        if (a == 0x40 || a == 0x60) {
            n += 1;
        }
        if (a == 0x20 || a == 0x60) {
            n += 1;
            if (!(f & 0x100)) {
                t = s->field0[4];
                NNS_G3dGeBufferOP_N(0x14, &t, 1);
            }
        }
        s->field0 += n;
        return;
    }
    if (a == 0x40 || a == 0x60) {
        n += 1;
        if (a == 0x40) {
            q = s->field0[4];
        } else {
            q = s->field0[5];
        }
        if (!(s->field8 & 0x100)) {
            NNS_G3dGeBufferOP_N(0x14, &q, 1);
        }
    }
    s->fieldB4 = &s->field12C;
    if (s->fieldC[6] != 0) {
        w = s->field8C[6];
    } else {
        w = 0;
    }
    if (s->field4->field34 != 0) {
        o = s->field4->field34 + v1;
        c = (s->field8 & 0x80) == 0;
    } else {
        o = &s->field12C;
        c = 0;
    }
    if (c == 0) {
        o->mFlag = 0;
        i = s->field4;
        if (i->field10 != 0) {
            if (i->field14(o, i->field10, v1) != 0) {
                goto done;
            }
        }
        h = (u8 *) s->fieldD4;
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
            MI_Zero36B((s32 *) o->mRot);
            r += 2;
            m = (*p & 0x100) ? -0x1000 : 0x1000;
            ((s32 *) o->mRot)[k] = m;
            ((s32 *) o->mRot)[pivotUtil_[k][0]] = b0;
            ((s32 *) o->mRot)[data_02152c0d[k][0]] = b1;
            if (*p & 0x200) {
                b1 = -b1;
            }
            ((s32 *) o->mRot)[data_02152c0e[k][0]] = b1;
            if (*p & 0x400) {
                b0 = -b0;
            }
            ((s32 *) o->mRot)[data_02152c0f[k][0]] = b0;
        } else {
            ((s32 *) o->mRot)[0] = ((s16 *) p)[1];
            ((s32 *) o->mRot)[1] = ((s16 *) r)[0];
            ((s32 *) o->mRot)[2] = ((s16 *) r)[1];
            ((s32 *) o->mRot)[3] = ((s16 *) r)[2];
            ((s32 *) o->mRot)[4] = ((s16 *) r)[3];
            ((s32 *) o->mRot)[5] = ((s16 *) r)[4];
            ((s32 *) o->mRot)[6] = ((s16 *) r)[5];
            ((s32 *) o->mRot)[7] = ((s16 *) r)[6];
            ((s32 *) o->mRot)[8] = ((s16 *) r)[7];
            r += 8;
        }
        s->fieldE8(o, r, s->field0, *p);
    }
done:
    s->fieldB4 = o;
    if (!(s->field8 & 0x100)) {
        s->fieldEC(s->fieldB4);
    }
    c = 0;
    s->fieldB4 = 0;
    if (w == 3) {
        s->field8 &= ~0x40;
        s->fieldC[6](s);
        c = s->field8 & 0x40;
    }
    if (a == 0x20 || a == 0x60) {
        n += 1;
        if (c == 0 && !(s->field8 & 0x100)) {
            t2 = s->field0[4];
            NNS_G3dGeBufferOP_N(0x13, &t2, 1);
        }
    }
    s->field0 += n;
}

void func_01ff81b4(Unk02170500 *s, u32 a) {
    s32 v[3];
    s32 x;

    if (!(s->field8 & 0x100) && !(s->field8 & 0x200)) {
        if (a == 0) {
            x = s->fieldE0;
            v[2] = x;
            v[1] = x;
            v[0] = x;
        } else {
            x = s->fieldE4;
            v[2] = x;
            v[1] = x;
            v[0] = x;
        }
        NNS_G3dGeBufferOP_N(0x1b, v, 3);
    }
    s->field0 += 1;
}

// clang-format off
// Interrupt dispatch: reads the interrupt flag and enable registers (0x04000210), takes the highest set bit with clz,
// acknowledges it, and runs the function in OS_IRQTable for that bit with lr set to OS_IrqHandler_ThreadSwitch.
// Not compiled code: it jumps with a set return address instead of a call (ldr lr, bx).
asm void OS_IrqHandler(void) {
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
    ldr lr, =OS_IrqHandler_ThreadSwitch
    bx r0
}
// clang-format on

// clang-format off
// OSThread switch after an interrupt: clears the pending flags of the thread list at data_027e0000, then saves the
// registers of the running thread in its context and loads those of the first runnable thread.
// Not compiled code: it switches processor modes and moves the whole register set with the user-bank forms of stm and
// ldm (msr, mrs, ^).
asm void OS_IrqHandler_ThreadSwitch(void) {
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
    ldr ip, =OSi_ThreadInfo
    mov r1, #0x1
    strh r1, [ip, #0x0]
L_01ff80a8:
    ldr ip, =OSi_ThreadInfo
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
    ldr r1, =CP_RestoreContext
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
