#include "00/GameSpy/gpiCallback.h"
#include "00/code_021947e4.h"
#include "00/code_02194000.h"
#include "00/code_02196000.h"
#include "00/GameSpy/nonport.h"
#include "00/code_02196590.h"
#include "00/GameSpy/gpiUtility.h"
#include "00/code_021a3668.h"
#include "00/code_021a3678.h"
#include "00/code_021a3690.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"

#include "00/GameSpy/gpiBuffer.h"
#include "code_02139f70.h"
#include "code_0213a460.h"
#include "00/GameSpy/gpiProfile.h"
#include "00/code_0218e0fc.h"
#include "00/code_02191200.h"
#include "00/code_02196480.h"
#include "00/GameSpy/gpiConnect.h"
#include "00/code_02192d64.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/GameSpy/darray.h"
#include "00/code_02190000.h"
#include "00/GameSpy/gpiBuddy.h"
#include "00/GameSpy/gpiSearch.h"
#include "00/GameSpy/gpiPeer.h"
#include "00/code_02194840.h"

void GpiQueueErrorCallback(GpConnection *a, s32 result, s32 fatal) {
    GpiConnection *iconnection;
    GpiCallback e;
    Unk02190f4c *f;

    iconnection = a->mGpiConnection;
    if (iconnection == NULL) {
        __msl_assertion_failed(data_ov000_021b2a8c, data_ov000_021b2a58, NULL, 0x23);
    }
    if (result == 0) {
        __msl_assertion_failed(data_ov000_021b2aa0, data_ov000_021b2a58, NULL, 0x24);
    }
    if (fatal != 1 && fatal != 0) {
        __msl_assertion_failed(data_ov000_021b2ab8, data_ov000_021b2a58, NULL, 0x25);
    }
    if (fatal == 1) {
        iconnection->mFatal = TRUE;
    }
    e = iconnection->mCallbacks[0];
    if (e.mCallback != NULL) {
        f = func_ov000_021a3690(0x10);
        if (f != NULL) {
            f->field0 = result;
            f->fieldC = fatal;
            f->field4 = iconnection->mErrorNumber;
            f->field8 = iconnection;
        }
        GpiQueueCallback(a, e, f, NULL, 1);
    }
}

u32 GpiQueueCallback(GpConnection *a, GpiCallback b, void *c, GpiOperation *d, s32 e) {
    GpiConnection *f;
    GpiQueuedCallback *g;

    f = a->mGpiConnection;
    g = func_ov000_021a3690(0x18);
    if (g == NULL) {
        GpiSetErrorMessage(a, data_ov000_021b2a7c);
        return 1;
    }
    g->mCallback = b;
    g->mArg = c;
    if (d != NULL) {
        g->field10 = d->mId;
    } else {
        g->field10 = 0;
    }
    g->fieldC = e;
    g->mNext = NULL;
    if (f->mCallbackQueueHead == NULL) {
        f->mCallbackQueueHead = g;
    }
    if (f->mCallbackQueueTail != NULL) {
        f->mCallbackQueueTail->mNext = g;
    }
    f->mCallbackQueueTail = g;
    return 0;
}

void GpiCallAndFreeCallback(GpConnection *a, GpiQueuedCallback *data) {
    Unk02190da0Data *c;
    Unk02190da0Data *e;
    s32 d;

    if (data->mCallback.mCallback == NULL) {
        __msl_assertion_failed(data_ov000_021b2a38, data_ov000_021b2a58, NULL, 0x6e);
    }
    if (data->mArg == NULL) {
        __msl_assertion_failed(data_ov000_021b2a68, data_ov000_021b2a58, NULL, 0x6f);
    }
    data->mCallback.mCallback(a, data->mArg, data->mCallback.field4);
    if (data->fieldC == 2) {
        c = data->mArg;
        func_ov000_021a3668(c->field8);
        c = data->mArg;
        c->field8 = NULL;
    } else if (data->fieldC == 3) {
        e = data->mArg;
        for (d = 0; d < e->field38; d++) {
            func_ov000_021a3668(e->field3C[d]);
            e->field3C[d] = NULL;
            func_ov000_021a3668(e->field40[d]);
            e->field40[d] = NULL;
        }
        func_ov000_021a3668(e->field3C);
        e->field3C = NULL;
        func_ov000_021a3668(e->field40);
        e->field40 = NULL;
    } else if (data->fieldC == 4) {
        c = data->mArg;
        func_ov000_021a3668(c->fieldC);
        c->fieldC = NULL;
    } else if (data->fieldC == 7) {
        c = data->mArg;
        if (c->field10 != NULL) {
            func_ov000_021a3668(c->field10);
            c->field10 = NULL;
        }
    } else if (data->fieldC == 8) {
        c = data->mArg;
        if (c->field8 != NULL) {
            func_ov000_021a3668(c->field8);
            c->field8 = NULL;
        }
    } else if (data->fieldC == 9) {
        Unk02190da0Data *f = data->mArg;
        for (d = 0; d < f->field4; d++) {
            func_ov000_021a3668(f->field8[d]);
            f->field8[d] = NULL;
        }
        func_ov000_021a3668(f->field8);
        f->field8 = NULL;
    }
    func_ov000_021a3668(data->mArg);
    data->mArg = NULL;
    func_ov000_021a3668(data);
}

u32 GpiCallQueuedCallbacks(GpConnection *a, s32 b) {
    GpiConnection *c;
    GpiQueuedCallback *d;
    GpiQueuedCallback *e;
    GpiQueuedCallback *f;
    GpiQueuedCallback *g;

    c = a->mGpiConnection;
    if (b != 0) {
        d = c->mCallbackQueueHead;
        e = c->mCallbackQueueTail;
        f = NULL;
        c->mCallbackQueueHead = NULL;
        c->mCallbackQueueTail = NULL;
        g = d;
        if (g != NULL) {
            do {
                GpiQueuedCallback *h = g->mNext;
                if (g->field10 == b || g->fieldC == 1) {
                    if (f != NULL) {
                        f->mNext = h;
                    } else {
                        d = h;
                    }
                    if (e == g) {
                        e = f;
                    }
                    GpiCallAndFreeCallback(a, g);
                } else {
                    f = g;
                }
                g = h;
            } while (g != NULL);
        }
        if (c->mCallbackQueueHead != NULL) {
            c->mCallbackQueueTail->mNext = d;
            c->mCallbackQueueTail = e;
        } else {
            c->mCallbackQueueHead = d;
            c->mCallbackQueueTail = e;
        }
        return 0;
    }
    g = c->mCallbackQueueHead;
    while (g != NULL) {
        c->mCallbackQueueHead = NULL;
        c->mCallbackQueueTail = NULL;
        while (g != NULL) {
            d = g->mNext;
            GpiCallAndFreeCallback(a, g);
            g = d;
        }
        g = c->mCallbackQueueHead;
    }
    return 0;
}
