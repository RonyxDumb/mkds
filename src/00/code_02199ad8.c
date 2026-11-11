#include "00/code_02199ad8.h"
#include "00/code_0218d818.h"
#include "00/code_0219903c.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"
#include "00/code_021a3678.h"
#include "00/code_021a3690.h"
#include "00/code_02197b08.h"
#include "00/code_02197b34.h"
#include "00/code_02197ddc.h"
#include "00/code_02197e58.h"
#include "00/code_021985ec.h"
#include "00/code_021988e8.h"
#include "00/code_02198a8c.h"
#include "00/code_02198d04.h"
#include "00/code_02199fa4.h"
#include "00/code_02199fb0.h"
#include "00/code_0219a014.h"
#include "00/code_021a3668.h"
#include "code_021382a8.h"
#include "00/code_0218e2dc.h"

enum { K0, K1 };

u32 func_ov000_02199ec8(Gt2Connection *a, u32 b) {
    s32 c;
    s32 d;
    s32 e;
    GTI2OutgoingBufferMessage *f;
    c = DarrayGetCount(a->mOutgoingBufferMessages);
    if (c == 0) {
        return 1;
    }
    for (d = 0; d < c; d++) {
        f = DarrayGetElement(a->mOutgoingBufferMessages, d);
        if (func_ov000_0219a014(f->mSerialNumber, b) >= 0) {
            break;
        }
    }
    if (d == 0) {
        return 1;
    }
    while (d-- != 0) {
        DarrayRemove(a->mOutgoingBufferMessages, d);
    }
    c = DarrayGetCount(a->mOutgoingBufferMessages);
    if (c == 0) {
        a->mSendBuffer.mLength = 0;
        return 1;
    }
    f = DarrayGetElement(a->mOutgoingBufferMessages, 0);
    e = f->mStart;
    for (d = 0; d < c; d++) {
        f = DarrayGetElement(a->mOutgoingBufferMessages, d);
        f->mStart -= e;
    }
    RemoveBufferBytes(&a->mSendBuffer, 0, e);
    return 1;
}

u32 func_ov000_02199e50(Gt2Connection *a, const u8 *b, s32 c) {
    if (a->mState != 5 && a->mState != 6) {
        return 1;
    }
    if (DarrayGetCount(a->mReceiveFilters) != 0) {
        if (gti2ReceiveFilterCallback(a, 0, b, c, 0) != FALSE) {
            return 1;
        }
        return 0;
    }
    if (Gt2CallDataCallback(a, b, c, 0) != FALSE) {
        return 1;
    }
    return 0;
}

u32 func_ov000_02199dd0(Gt2Connection *a, const u8 *c, u32 d) {
    if (a->mState != 5 && a->mState != 6) {
        if (func_ov000_02199fa4(a) == 0) {
            return 0;
        }
    } else {
        if (DarrayGetCount(a->mReceiveFilters) != 0) {
            if (gti2ReceiveFilterCallback(a, 0, c, d, 1) != FALSE) {
                return 1;
            }
            return 0;
        }
        if (Gt2CallDataCallback(a, c, d, 1) == FALSE) {
            return 0;
        }
    }
    return 1;
}

u32 func_ov000_02199d4c(Gt2Connection *a, const u8 *e, int f) {
    s8 b[0x20];
    s8 c[0x20];
    if (a->mState != 2) {
        if (func_ov000_02199fa4(a) != 0) {
            return 1;
        }
        return 0;
    }
    if (f < 0x20) {
        if (func_ov000_02199fa4(a) != 0) {
            return 1;
        }
        return 0;
    }
    gti2GetResponse(b, (const s8 *) e);
    gti2GetChallenge(c);
    gti2GetResponse((s8 *) a->mResponse, c);
    if (gti2SendServerChallenge(a, (const u8 *) b, (const u8 *) c) == 0) {
        return 0;
    }
    a->mState = 3;
    return 1;
}

u32 func_ov000_02199c98(Gt2Connection *a, const u8 *d, int e) {
    s8 b[0x20];
    if (a->mState != 0) {
        if (func_ov000_02199fa4(a) != 0) {
            return 1;
        }
        return 0;
    }
    if (e < 0x40) {
        if (func_ov000_02199fa4(a) != 0) {
            return 1;
        }
        return 0;
    }
    if (gti2CheckResponse(d, a->mResponse) == FALSE) {
        if (func_ov000_02199fa4(a) != 0) {
            return 1;
        }
        return 0;
    }
    gti2GetResponse(b, (const s8 *) (d + 0x20));
    if (gti2SendClientResponse(a, (const u8 *) b, a->mUnk_38.mData, a->mUnk_38.mSize) == 0) {
        return 0;
    }
    if (a->mUnk_38.mData != NULL) {
        func_ov000_021a3668(a->mUnk_38.mData);
        a->mUnk_38.mData = NULL;
    }
    a->mState = 1;
    return 1;
}

u32 func_ov000_02199bb4(Gt2Connection *a, const u8 *c, int d) {
    if (a->mState != 3) {
        if (func_ov000_02199fa4(a) != 0) {
            return 1;
        }
        return 0;
    }
    if (d < 0x20) {
        if (func_ov000_02199fa4(a) != 0) {
            return 1;
        }
        return 0;
    }
    if (gti2CheckResponse(c, a->mResponse) == FALSE) {
        if (func_ov000_02199fa4(a) != 0) {
            return 1;
        }
        return 0;
    }
    if (a->mSocket->mIncomingConnectionCallback == NULL) {
        if (gti2SendClosed(a) == 0) {
            return 0;
        }
        gti2ConnectionClosed(a);
        return 1;
    }
    a->mState = 4;
    if (CallIncomingConnectionCallback(a->mSocket, a, a->mAddress, a->mPort, GetElapsedMilliseconds() - a->mChallengeTime,
                                       c + 0x20, d - 0x20) != FALSE) {
        return 1;
    }
    return 0;
}

u32 func_ov000_02199b70(Gt2Connection *a) {
    if (a->mState != 1) {
        if (func_ov000_02199fa4(a) != 0) {
            return 1;
        }
        return 0;
    }
    a->mState = 5;
    if (Gt2SetResultAndCallResultCallback(a, 0, NULL, 0) != 0) {
        return 1;
    }
    return 0;
}

u32 func_ov000_02199b14(Gt2Connection *a, void *c, u32 d) {
    if (a->mState != 1) {
        if (func_ov000_02199fa4(a) != 0) {
            return 1;
        }
        return 0;
    }
    gti2ConnectionClosed(a);
    if (gti2SendClosed(a) == 0) {
        return 0;
    }
    if (Gt2SetResultAndCallResultCallback(a, 2, c, d) != FALSE) {
        return 1;
    }
    return 0;
}

u32 func_ov000_02199ad8(Gt2Connection *a) {
    if (gti2SendClosed(a) == 0) {
        return 0;
    }
    if (func_ov000_02199fb0(a, 2, a->mState == 6 ? K0 : K1) == 0) {
        return 0;
    }
    return 1;
}
