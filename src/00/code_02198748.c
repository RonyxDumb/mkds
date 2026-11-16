#include "00/code_02198748.h"
#include "00/code_02197b34.h"
#include "00/GameSpy/gt2Message.h"
#include "00/code_0219a0d0.h"
#include "00/code_0219a61c.h"
#include "00/code_021a3690.h"
#include "string.h"
#include "code_02134398.h"

int func_ov000_0219885c(void *a, Gt2Connection **b, int c, u32 d) {
    int r = CreateConnection(a, b, c, d);
    if (r != 0) {
        return r;
    }
    (*b)->fieldC = 0;
    (*b)->field10 = TRUE;
    return 0;
}

int func_ov000_0219883c(void *a, Gt2Connection **b, int c, u32 d) {
    int r = CreateConnection(a, b, c, d);
    if (r != 0) {
        return r;
    }
    (*b)->fieldC = 2;
    (*b)->field10 = FALSE;
    return 0;
}

BOOL func_ov000_021987c8(Gt2Connection *a, void *b, int c, Gt2ConnectionCallbacks *d) {
    s8 e[0x24];
    func_ov000_0219a61c((const char **) &b, &c);
    if (c > 0) {
        a->field38.mData = func_ov000_021a3690(c);
        if (a->field38.mData == NULL) {
            return TRUE;
        }
        memcpy(a->field38.mData, b, c);
        a->field38.mSize = c;
    }
    if (d != NULL) {
        a->mCallbacks = *d;
    }
    func_ov000_02197be0(e);
    menu_ta_updateMainText((s8 *) a->field68, e);
    func_ov000_02198f24(a, e);
    a->fieldC = 0;
    return FALSE;
}

BOOL func_ov000_02198778(Gt2Connection *a, Gt2ConnectionCallbacks *b) {
    if (a->field14 != FALSE) {
        a->field14 = FALSE;
        return FALSE;
    }
    a->field14 = FALSE;
    if (a->fieldC != 4) {
        return FALSE;
    }
    func_ov000_02198df8(a);
    a->fieldC = 5;
    if (b != NULL) {
        a->mCallbacks = *b;
    }
    return TRUE;
}

void func_ov000_02198748(Gt2Connection *a, void *b, u32 c, ...) {
    a->field14 = FALSE;
    if (a->fieldC == 4) {
        func_ov000_0219a61c((const char **) &b, (s32 *) &c);
        func_ov000_02198d9c(a, b, c);
        a->fieldC = 6;
    }
}
