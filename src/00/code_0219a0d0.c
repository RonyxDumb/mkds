#include "00/code_0219a0d0.h"
#include "00/GameSpy/darray.h"
#include "string.h"
#include "code_02134398.h"
#include "00/code_0218d000.h"
#include "00/code_0219a61c.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "00/code_021a3678.h"
#include "00/code_021a3690.h"
#include "00/GameSpy/hashtable.h"
#include "00/GameSpy/nonport.h"
#include "00/unk_021b4000.h"
#include "00/code_02197000.h"
#include "00/code_02199000.h"
#include "00/code_0219a000.h"
#include "00/code_0219903c.h"
#include "00/code_02197ddc.h"
#include "00/code_02198584.h"
#include "00/code_0219a044.h"
#include "00/code_0219a3e8.h"
#include "00/code_0219a430.h"
#include "00/code_021a3668.h"
#include "code_021382a8.h"

typedef struct Unk0219a110Addr {
    /* 0 */ u8 field0;
    /* 1 */ u8 field1;
    /* 2 */ u16 field2;
    /* 4 */ u32 field4;
} Unk0219a110Addr;

u32 CreateConnection(Gt2Socket *a, Gt2Connection **b, u32 c, u32 d) {
    Gt2Connection *e = NULL;
    if (FindConnection(a, c, d) != NULL) {
        return 5;
    }
    e = func_ov000_0219a3e8();
    if (e != NULL) {
        memset(e, 0, 0xa0);
        e->mAddress = c;
        e->mPort = d;
        e->mSocket = a;
        e->mCreateTime = func_ov000_0218e8c4();
        e->mLastSendTime = e->mCreateTime;
        e->field64 = 0;
        e->field66 = 0;
        if (InitBuffer(&e->field44, a->field3C) != 0 && InitBuffer(&e->mSendBuffer, a->mSendBufferSize) != 0) {
            e->field5C = DarrayCreate(0x10, 0x40, NULL);
            if (e->field5C != NULL) {
                e->field60 = DarrayCreate(0x10, 0x40, NULL);
                if (e->field60 != NULL) {
                    e->field98 = DarrayCreate(4, 2, NULL);
                    if (e->field98 != NULL) {
                        e->field9C = DarrayCreate(4, 2, NULL);
                        if (e->field9C != NULL) {
                            HashtableSet(a->mConnections, &e);
                            *b = FindConnection(a, c, d);
                            if (*b != NULL) {
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    if (e != NULL) {
        func_ov000_021a3668(e->field44.mData);
        func_ov000_021a3668(e->mSendBuffer.mData);
        if (e->field5C != NULL) {
            DarrayDelete(e->field5C);
        }
        if (e->field60 != NULL) {
            DarrayDelete(e->field60);
        }
        if (e->field98 != NULL) {
            DarrayDelete(e->field98);
        }
        if (e->field9C != NULL) {
            DarrayDelete(e->field9C);
        }
        func_ov000_021a3668(e);
    }
    return 1;
}

void func_ov000_0219a220(Gt2Connection *a) {
    s32 b;
    s32 c;
    if (a->field14 == FALSE && a->field24 == 0) {
        if (a->fieldC == 7) {
            b = DarrayGetCount(a->mSocket->mConnectionsToFree);
            for (c = 0; c < b; c++) {
                if (a == *(Gt2Connection **) DarrayGetElement(a->mSocket->mConnectionsToFree, c)) {
                    DarrayRemove(a->mSocket->mConnectionsToFree, c);
                    return;
                }
            }
        } else {
            HashtableRemove(a->mSocket->mConnections, &a);
        }
    }
}

u32 func_ov000_0219a110(u32 *c, u32 d, int f, u32 g, u32 h) {
    Gt2Socket *a = (Gt2Socket *) c;
    s32 e;
    func_ov000_0219a61c((const char **) &g, (s32 *) &h);
    if (func_ov000_0218e644(a->mDescriptor) == 0) {
        return 1;
    }
    {
        Unk0219a110Addr b = {0, 0, 0, 0};
        Unk0219a110Addr *p = &b;
        p->field1 = 2;
        p->field4 = d;
        p->field2 = ((f >> 8) & 0xff) | ((f << 8) & 0xff00);
        if (func_ov000_0218e3e4(a->mDescriptor, (void *) g, h, 0, &b, 8) == -1) {
            e = func_ov000_0218e368(a->mDescriptor);
            if (e == -15) {
                if (func_ov000_0219922c(a, d, f) == 0) {
                    return 0;
                }
            } else if (e == -42 || e == -6) {
                return 1;
            } else if (e != -35) {
                func_ov000_0219a044(a);
                return 0;
            }
        } else if (a->mSentCallback != NULL) {
            if (func_ov000_02197f28(a, FindConnection(a, d, f), d, f, 0, g, h, 1) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

u32 func_ov000_0219a0d0(Gt2Connection **a, u32 *b) {
    Gt2Connection *c = *a;
    u32 d = *b;
    if (c->fieldC != 7 && func_ov000_02198584(c, d) == 0) {
        return 0;
    }
    if (c->fieldC == 7 && c->field14 == FALSE && c->field24 == 0) {
        func_ov000_0219a220(c);
    }
    return 1;
}
