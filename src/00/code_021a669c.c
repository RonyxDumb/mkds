#include "00/code_021a669c.h"
#include "ITCM/code_01ff8000.h"
#include "00/code_021a666c.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"
#include "code_02133274.h"
#include "os_thread.h"
#include "Main/Unknown/code_02000800.h"

void func_ov000_021a68dc(OSMutex *a) {
    if (a->mHolder == (struct OSThread *) OS_IrqHandler) {
        a->mLockCount--;
        if (a->mLockCount == 0) {
            a->mHolder = NULL;
            OS_WakeupThread(&a->mQueue);
        }
    }
}

void func_ov000_021a6894(void) {
    u32 v1;
    Unk021b5f50 *g;

    v1 = OS_DisableInterrupts();
    g = func_ov000_021a5b30();
    if (g == NULL) {
        OS_RestoreInterrupts(v1);
        return;
    }
    if (g->field2270 != NULL && (s32) g->field2274 > 0) {
        MI_CpuFill8(g->field2270, 0, g->field2274);
    }
    OS_RestoreInterrupts(v1);
}

u32 func_ov000_021a6844(void) {
    u32 v1;
    u32 r;
    Unk021b5f50 *g;

    v1 = OS_DisableInterrupts();
    g = func_ov000_021a5b30();
    r = 0;
    if (g == NULL) {
        OS_RestoreInterrupts(v1);
        return r;
    }
    if (g->field2270 != NULL && g->field2274 > 0xc) {
        r = g->field2270->field0;
    }
    OS_RestoreInterrupts(v1);
    return r;
}

u32 func_ov000_021a67dc(u32 a) {
    u32 v1;
    Unk021b5f50 *g;

    v1 = OS_DisableInterrupts();
    g = func_ov000_021a5b30();
    if (g == NULL) {
        OS_RestoreInterrupts(v1);
        return 0;
    }
    if (a != 0) {
        a = g->field226A != 0;
        g->field226A = 1;
    } else {
        a = g->field226A != 0;
        g->field226A = 0;
    }
    OS_RestoreInterrupts(v1);
    return a;
}

u8 *func_ov000_021a6788(u16 a) {
    u32 v1;
    Unk021b5f50_2270_0c *e;

    v1 = OS_DisableInterrupts();
    if (func_ov000_021a5b30() == NULL) {
        OS_RestoreInterrupts(v1);
        return NULL;
    }
    e = func_ov000_021a65d8(a);
    if (e == NULL) {
        OS_RestoreInterrupts(v1);
        return NULL;
    }
    OS_RestoreInterrupts(v1);
    return e->field10;
}

void func_ov000_021a671c(Unk021a5e84 *a, u16 b) {
    Unk021b5f50 *g;
    Unk021b5f50_2270_0c *e;

    g = func_ov000_021a5b30();
    if (g != NULL && g->field226A == 0 && a->field3C == 0) {
        e = func_ov000_021a6614(a->field4);
        if (e == NULL) {
            e = func_ov000_021a669c();
        }
        if (e == NULL && g->field2278 == 1) {
            e = func_ov000_021a666c();
        }
        if (e != NULL) {
            e->field2 = b;
            MIi_CpuCopyFast(a, e->field10, 0xc0);
            func_ov000_021a6558(e);
        }
    }
}

Unk021b5f50_2270_0c *func_ov000_021a669c(void) {
    Unk021b5f50 *g;
    Unk021b5f50_2270 *l;
    Unk021b5f50_2270_0c *e;
    u32 n;
    s32 i;

    g = func_ov000_021a5b30();
    l = g->field2270;
    e = NULL;
    if (l != NULL && g->field2274 > 0xc) {
        n = (g->field2274 - 0xc) / 0xd0;
        if (n != 0 && n > l->field0) {
            for (i = 0; i < n; i++) {
                e = &l->fieldC[(u32) i];
                if (e->field0 == 0) {
                    break;
                }
            }
            if (i < n) {
                e->field0 = 1;
                e->field4 = l->field0;
                e->fieldC = NULL;
                e->field8 = l->field8;
                l->field8 = e;
                if (e->field8 != NULL) {
                    e->field8->fieldC = e;
                } else {
                    l->field4 = e;
                }
                l->field0++;
            }
        }
    }
    return e;
}
