#include "00/GameSpy/gpiSearch.h"
#include "00/GameSpy/gpiBuddy.h"

#include "00/code_02196590.h"
#include "00/code_021a3690.h"
#include "string.h"
#include "code_02134398.h"
#include "03/code_021b94b8.h"
#include "00/GameSpy/nonport.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/GameSpy/gpiBuffer.h"
#include "00/code_021965a0.h"
#include "00/code_02194000.h"
#include "00/GameSpy/gp.h"
#include "00/code_02196000.h"
#include "00/unk_021b3000.h"
#include "00/GameSpy/gpiUtility.h"
#include "00/code_021a3668.h"
#include "00/code_021a3678.h"
#include "code_0213a460.h"
#include "00/code_021947e4.h"
#include "00/unk_021b2000.h"
#include "00/GameSpy/gpiProfile.h"
#include "00/code_0218e0fc.h"
#include "00/code_02191200.h"
#include "00/code_02196480.h"
#include "00/GameSpy/gpiConnect.h"
#include "00/code_02192d64.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/GameSpy/darray.h"
#include "00/GameSpy/gpiPeer.h"
#include "00/GameSpy/gpi.h"
#include "00/code_02193000.h"
#include "00/GameSpy/gpiOperation.h"
#include "code_021384cc.h"
#include "00/unk_021b4000.h"
#include "00/GameSpy/gpiCallback.h"
#include "00/code_021a6d5c.h"

void func_ov000_02196434(GpConnection *a, GpiPeer *b, s32 c, const char *d, s32 e, s32 f) {
    char s[0x40];
    s32 v[3];

    if (GpiGetValue(d, data_ov000_021b3994, s, 0x40) != FALSE) {
        if (sscanf(s, data_ov000_021b399c, &v[0], &v[1], &v[2]) == 3) {
            func_ov000_02196480(a, v, b, 2, NULL);
        }
    }
}

s32 GpiOpenSearchSocket(GpConnection *a, GpiOperation *b) {
    Unk02196240 *c;
    Unk021a8f84 *h;
    s32 t;

    c = b->field4;
    c->fieldC = 0x1000;
    c->mInputBuffer = func_ov000_021a3690(c->fieldC + 1);
    if (c->mInputBuffer == NULL) {
        GpiSetErrorMessage(a, data_ov000_021b35f8);
        return 1;
    }
    c->mSocket = func_ov000_0218e554(2, 1, 0);
    if (c->mSocket == -1) {
        GpiSetError(a, 5, data_ov000_021b38c0);
        GpiQueueErrorCallback(a, 3, 1);
        return 3;
    }
    if (func_ov000_0218e80c(c->mSocket, 0) == FALSE) {
        GpiSetError(a, 5, data_ov000_021b38e8);
        GpiQueueErrorCallback(a, 3, 1);
        return 3;
    }
    h = func_ov000_021a8f84(data_ov000_021b35b8);
    if (h == NULL) {
        GpiSetError(a, 5, data_ov000_021b391c);
        GpiQueueErrorCallback(a, 3, 1);
        return 3;
    }
    {
        Unk021962d4Addr s = {0};

        s.field1 = 2;
        s.field4 = h->fieldC[0][0];
        if (s.field4 == 0) {
            __msl_assertion_failed(data_ov000_021b394c, data_ov000_021b3628, NULL, 0x59);
        }
        s.field2 = 0xcd74;
        if (func_ov000_0218e4b4(c->mSocket, &s, 8) == -1) {
            t = func_ov000_0218e368(c->mSocket);
            if (t != -6 && t != -0x1a && t != -0x4c) {
                GpiSetError(a, 5, data_ov000_021b396c);
                GpiQueueErrorCallback(a, 3, 1);
                return 3;
            }
        }
    }
    b->field14 = 1;
    return 0;
}

BOOL GpiCreateSearch(GpConnection *a, Unk02196240 **b, u32 c) {
    Unk02196240 *d;

    d = func_ov000_021a3690(0x144);
    if (d == NULL) {
        GpiSetErrorMessage(a, data_ov000_021b35f8);
        return TRUE;
    }
    memset(d, 0, 0x144);
    d->mKind = c;
    d->mSocket = -1;
    d->mInputBuffer = NULL;
    d->field10 = 0;
    d->field14 = 0;
    d->fieldC = 0;
    d->field20 = 0;
    d->field24 = 0;
    d->field1C = 0x1000;
    d->mOutputBuffer = func_ov000_021a3690(d->field1C + 1);
    if (d->mOutputBuffer == NULL) {
        GpiSetErrorMessage(a, data_ov000_021b35f8);
        return TRUE;
    }
    d->field13C = 0;
    d->field140 = 0;
    *b = d;
    return FALSE;
}

int GpiStartSearchOperation(GpConnection *a, u32 b, u32 c, u32 d, u32 e) {
    int v1;
    int v2;
    a->mGpiConnection->mSearchCount = a->mGpiConnection->mSearchCount + 1;
    v1 = GpiCreateOperation(a, 3, b, &v2, c, d, e);
    if (((v1 == 0) && (v1 = GpiOpenSearchSocket(a, (GpiOperation *) v2), v1 == 0)) &&
        ((*(s32 *) (v2 + 8) == 0 || (v1 = GpiUpdateConnection(a, *(u32 *) (v2 + 0x18)), v1 == 0)))) {
        v1 = 0;
    }
    return v1;
}

int func_ov000_021960a4(GpConnection *a, s8 *b, s8 *c, s8 *d, s8 *e, s8 *f, int g, int h, u32 l, u32 m, u32 n) {
    int v1;
    Unk02196240 *v2;
    if ((((((b == NULL) || (*b == 0)) && ((d == NULL || (*d == 0)))) && ((e == NULL || (*e == 0)))) &&
         ((f == NULL || (*f == 0)))) &&
        ((g == 0 && ((c == NULL || (*c == 0)))))) {
        GpiSetErrorMessage((u32 *) a, data_ov000_021b38ac);
        return 2;
    }
    v1 = GpiCreateSearch(a, &v2, 1);
    if (v1 == 0) {
        if (b == NULL) {
            v2->field28[0] = 0;
        } else {
            GpiCopyString((char *) v2->field28, (const char *) b, 0x1f);
        }
        if (c == NULL) {
            v2->field47[0] = 0;
        } else {
            GpiCopyString((char *) v2->field47, (const char *) c, 0x15);
        }
        if (d == NULL) {
            v2->field5C[0] = 0;
        } else {
            GpiCopyString((char *) v2->field5C, (const char *) d, 0x33);
        }
        func_ov000_0218e850(v2->field5C);
        if (e == NULL) {
            v2->field8F[0] = 0;
        } else {
            GpiCopyString((char *) v2->field8F, (const char *) e, 0x1f);
        }
        if (f == NULL) {
            v2->fieldAE[0] = 0;
        } else {
            GpiCopyString((char *) v2->fieldAE, (const char *) f, 0x1f);
        }
        v2->field130 = g;
        if (h < 0) {
            h = 0;
        }
        v2->field134 = h;
        v1 = GpiStartSearchOperation(a, (u32) v2, l, m, n);
        if (v1 == 0) {
            v1 = 0;
        }
    }
    return v1;
}

s32 GpiUpdateSearch(GpConnection *a, GpiOperation *b) {
    char w0[0x200];
    char w1[0x200];
    Unk02194cac_10 e;
    u32 h;
    s32 n;
    GpiCallback c1;
    u32 j;
    u32 m;
    GpiCallback c8;
    GpiCallback c7;
    GpiCallback c6;
    GpiCallback c5;
    GpiCallback c4;
    GpiCallback c3;
    GpiCallback c2;
    BOOL d;
    s32 g;
    GpiConnection *o;
    Unk02196240 *p;
    BOOL k;
    s32 r;
    BOOL f;
    s32 x;
    s32 y;
    s32 v;
    char *q;
    Unk02194cac_ac *q1;
    Unk02194cac_ac *t1;
    Unk02194cac_128 *q4;
    Unk02194cac_128 *t4;
    Unk02194cac_3c *u2;
    Unk02194cac_44 *u3;
    Unk02194cac_102 *u4;
    Unk02194cac_08 *u5;
    Unk02194cac_0c *u7;
    s32 i;
    Unk02194cac_0c2 *u9;

    o = a->mGpiConnection;
    p = b->field4;
    if (b->field8 != 0) {
        k = TRUE;
    } else {
        k = FALSE;
    }
    do {
        r = GpiSendBuffer(a, p->mSocket, (GpiBuffer *) &p->mOutputBuffer, &m, 1, data_ov000_021b3634);
        if (r != 0) {
            return r;
        }
        if (b->field14 == 1) {
            r = GpiCheckConnectComplete(a, p->mSocket, &h);
            if (r != 0) {
                return r;
            }
            if (h == 4) {
                GpiSetError(a, 0xd01, data_ov000_021b3638);
                GpiQueueErrorCallback(a, 4, 0);
                return 4;
            }
            if (h == 3) {
                if (p->mKind == 1) {
                    GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b3664);
                    GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b3670);
                    GpiAppendBufferNumber(a, &p->mOutputBuffer, o->mSesskey);
                    GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b367c);
                    GpiAppendBufferNumber(a, &p->mOutputBuffer, o->mProfileId);
                    GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b3688);
                    GpiAppendBufferNumber(a, &p->mOutputBuffer, o->mNamespaceId);
                    if (p->field28[0] != 0) {
                        GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b3698);
                        GpiAppendBufferString(a, &p->mOutputBuffer, p->field28);
                    }
                    if (p->field47[0] != 0) {
                        GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b36a0);
                        GpiAppendBufferString(a, &p->mOutputBuffer, p->field47);
                    }
                    if (p->field5C[0] != 0) {
                        GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b36b0);
                        GpiAppendBufferString(a, &p->mOutputBuffer, p->field5C);
                    }
                    if (p->field8F[0] != 0) {
                        GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b36b8);
                        GpiAppendBufferString(a, &p->mOutputBuffer, p->field8F);
                    }
                    if (p->fieldAE[0] != 0) {
                        GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b36c4);
                        GpiAppendBufferString(a, &p->mOutputBuffer, p->fieldAE);
                    }
                    if (p->field130 != 0) {
                        GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b36d0);
                        GpiAppendBufferNumber(a, &p->mOutputBuffer, p->field130);
                    }
                    if (p->field134 > 0) {
                        GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b36dc);
                        GpiAppendBufferNumber(a, &p->mOutputBuffer, p->field134);
                    }
                } else if (p->mKind == 2) {
                    GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b36e4);
                    GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b36b0);
                    GpiAppendBufferString(a, &p->mOutputBuffer, p->field5C);
                } else if (p->mKind == 3) {
                    GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b36ec);
                    GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b36b0);
                    GpiAppendBufferString(a, &p->mOutputBuffer, p->field5C);
                    GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b36f4);
                    GpiAppendBufferString(a, &p->mOutputBuffer, p->fieldCD);
                    GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b3688);
                    GpiAppendBufferNumber(a, &p->mOutputBuffer, o->mNamespaceId);
                } else if (p->mKind == 4) {
                    GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b36fc);
                    GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b3670);
                    GpiAppendBufferNumber(a, &p->mOutputBuffer, o->mSesskey);
                    GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b367c);
                    GpiAppendBufferNumber(a, &p->mOutputBuffer, o->mProfileId);
                    GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b3708);
                    GpiAppendBufferNumber(a, &p->mOutputBuffer, p->field138);
                } else if (p->mKind == 5) {
                    GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b3714);
                    GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b3698);
                    GpiAppendBufferString(a, &p->mOutputBuffer, p->field28);
                    GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b36b0);
                    GpiAppendBufferString(a, &p->mOutputBuffer, p->field5C);
                    GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b36f4);
                    GpiAppendBufferString(a, &p->mOutputBuffer, p->fieldCD);
                } else if (p->mKind == 6) {
                    GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b371c);
                    GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b3698);
                    GpiAppendBufferString(a, &p->mOutputBuffer, p->field28);
                    GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b36b0);
                    GpiAppendBufferString(a, &p->mOutputBuffer, p->field5C);
                    GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b36f4);
                    GpiAppendBufferString(a, &p->mOutputBuffer, p->fieldCD);
                    GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b3728);
                    GpiAppendBufferNumber(a, &p->mOutputBuffer, o->mProductId);
                    GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b3688);
                    GpiAppendBufferNumber(a, &p->mOutputBuffer, o->mNamespaceId);
                    GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b36a0);
                    GpiAppendBufferString(a, &p->mOutputBuffer, p->field47);
                    if (p->fieldEC[0] != 0) {
                        GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b3734);
                        GpiAppendBufferString(a, &p->mOutputBuffer, p->fieldEC);
                    }
                } else if (p->mKind == 7) {
                    GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b373c);
                    GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b3670);
                    GpiAppendBufferNumber(a, &p->mOutputBuffer, o->mSesskey);
                    GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b367c);
                    GpiAppendBufferNumber(a, &p->mOutputBuffer, o->mProfileId);
                    GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b3688);
                    GpiAppendBufferNumber(a, &p->mOutputBuffer, o->mNamespaceId);
                } else if (p->mKind == 8) {
                    GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b3748);
                    GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b3758);
                    GpiAppendBufferString(a, &p->mOutputBuffer, p->field47);
                    GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b3688);
                    GpiAppendBufferNumber(a, &p->mOutputBuffer, o->mNamespaceId);
                } else {
                    __msl_assertion_failed(data_ov000_021b3768, data_ov000_021b3628, NULL, 0x275);
                }
                GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b376c);
                GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b4d6c);
                GpiAppendBufferString(a, &p->mOutputBuffer, data_ov000_021b3778);
                b->field14 = 4;
            }
        } else if (b->field14 == 4) {
            r = GpiReceiveBuffer(a, p->mSocket, (GpiBuffer *) &p->mInputBuffer, (s32 *) &j, &m, data_ov000_021b3634);
            if (r != 0) {
                if (r != 3) {
                    return r;
                }
                GpiSetError(a, 0xd01, data_ov000_021b3780);
                GpiQueueErrorCallback(a, 3, 0);
                return 3;
            }
            if (strstr(p->mInputBuffer, data_ov000_021b3778) != NULL) {
                n = 0;
                b->field14 = 5;
                if (GpiReadError(a, p->mInputBuffer, 1) != FALSE) {
                    p->field140 = TRUE;
                    return 4;
                }
                if (p->mKind == 1) {
                    d = FALSE;
                    e.field0 = 0;
                    e.field4 = 0;
                    e.fieldC = NULL;
                    e.field8 = 0x601;
                    do {
                        r = GpiReadKeyValue(a, p->mInputBuffer, &n, (s8 *) w0, (s8 *) w1);
                        if (r != 0) {
                            return r;
                        }
                        if (strcmp(w0, data_ov000_021b37ac) == 0) {
                            r = GpiReadKeyValue(a, p->mInputBuffer, &n, (s8 *) w0, (s8 *) w1);
                            if (r != 0) {
                                return r;
                            }
                            if (strcmp(w0, data_ov000_021b37b4) == 0 && strcmp(w1, data_ov000_021b3768) != 0) {
                                e.field8 = 0x600;
                            }
                            d = TRUE;
                        } else if (strcmp(w0, data_ov000_021b37bc) == 0) {
                            q1 = func_ov000_021a3678(e.fieldC, ++e.field4 * 0xac);
                            e.fieldC = q1;
                            if (q1 == NULL) {
                                GpiSetErrorMessage(a, data_ov000_021b35f8);
                                return 1;
                            }
                            i = e.field4 - 1;
                            t1 = &q1[i];
                            memset(t1, 0, 0xac);
                            q1[i].field0 = StrtolBase10(w1);
                            f = FALSE;
                            do {
                                g = n;
                                r = GpiReadKeyValue(a, p->mInputBuffer, &n, (s8 *) w0, (s8 *) w1);
                                if (r != 0) {
                                    return r;
                                }
                                if (strcmp(w0, data_ov000_021b37c0) == 0) {
                                    GpiCopyString(t1->field4, w1, 0x1f);
                                } else if (strcmp(w0, data_ov000_021b37c8) == 0) {
                                    GpiCopyString(t1->field23, w1, 0x15);
                                } else if (strcmp(w0, data_ov000_021b37d4) == 0) {
                                    GpiCopyString(t1->field38, w1, 0x1f);
                                } else if (strcmp(w0, data_ov000_021b37e0) == 0) {
                                    GpiCopyString(t1->field57, w1, 0x1f);
                                } else if (strcmp(w0, data_ov000_021b37ec) == 0) {
                                    GpiCopyString(t1->field76, w1, 0x33);
                                } else if (strcmp(w0, data_ov000_021b37bc) == 0 ||
                                           strcmp(w0, data_ov000_021b37ac) == 0) {
                                    f = TRUE;
                                    n = g;
                                }
                            } while (f == FALSE);
                        } else {
                            GpiSetError(a, 1, data_ov000_021b37f4);
                            GpiQueueErrorCallback(a, 3, 1);
                            return 3;
                        }
                    } while (d == FALSE);
                    v = e.field8;
                    c1 = b->fieldC;
                    if (c1.mCallback != NULL) {
                        c1.mCallback(a, &e, c1.field4);
                    }
                    if (v == 0x600 && e.field8 == 0x600) {
                        r = func_ov000_021960a4(a, p->field28, p->field47, p->field5C, p->field8F, p->fieldAE,
                                                p->field130, e.field4 + p->field134, b->field8,
                                                (u32) b->fieldC.mCallback, b->fieldC.field4);
                        if (r != 0) {
                            return r;
                        }
                    }
                    func_ov000_021a3668(e.fieldC);
                    e.fieldC = NULL;
                } else if (p->mKind == 2) {
                    c2 = b->fieldC;
                    if (c2.mCallback != NULL) {
                        r = GpiReadKeyValue(a, p->mInputBuffer, &n, (s8 *) w0, (s8 *) w1);
                        if (r != 0) {
                            return r;
                        }
                        if (strcmp(w0, data_ov000_021b381c) != 0) {
                            GpiSetError(a, 1, data_ov000_021b37f4);
                            GpiQueueErrorCallback(a, 3, 1);
                            return 3;
                        }
                        u2 = func_ov000_021a3690(0x3c);
                        if (u2 == NULL) {
                            GpiSetErrorMessage(a, data_ov000_021b35f8);
                            return 1;
                        }
                        u2->field0 = 0;
                        GpiCopyString(u2->field4, (const char *) p->field5C, 0x33);
                        if ((s8) w1[0] == 0x30) {
                            u2->field38 = FALSE;
                        } else {
                            u2->field38 = TRUE;
                        }
                        r = GpiQueueCallback(a, c2, u2, b, 0);
                        if (r != 0) {
                            return r;
                        }
                    }
                } else if (p->mKind == 3) {
                    c3 = b->fieldC;
                    if (c3.mCallback != NULL) {
                        u3 = func_ov000_021a3690(0x44);
                        if (u3 == NULL) {
                            GpiSetErrorMessage(a, data_ov000_021b35f8);
                            return 1;
                        }
                        u3->field0 = 0;
                        strcpy(u3->field4, (const char *) p->field5C);
                        u3->field38 = 0;
                        u3->field3C = NULL;
                        u3->field40 = NULL;
                        r = GpiReadKeyValue(a, p->mInputBuffer, &n, (s8 *) w0, (s8 *) w1);
                        if (r != 0) {
                            return r;
                        }
                        if (strcmp(w0, data_ov000_021b3820) != 0) {
                            GpiSetError(a, 1, data_ov000_021b37f4);
                            GpiQueueErrorCallback(a, 3, 1);
                            return 3;
                        }
                        d = FALSE;
                        do {
                            r = GpiReadKeyValue(a, p->mInputBuffer, &n, (s8 *) w0, (s8 *) w1);
                            if (r != 0) {
                                return r;
                            }
                            if (strcmp(w0, data_ov000_021b37c0) == 0) {
                                q = func_ov000_021a3678(u3->field3C, (u3->field38 + 1) * 4);
                                if (q == NULL) {
                                    GpiSetErrorMessage(a, data_ov000_021b35f8);
                                    return 1;
                                }
                                u3->field3C = (char **) q;
                                q = func_ov000_021a3690(0x1f);
                                if (q == NULL) {
                                    GpiSetErrorMessage(a, data_ov000_021b35f8);
                                    return 1;
                                }
                                u3->field3C[u3->field38] = q;
                                GpiCopyString(u3->field3C[u3->field38], w1, 0x1f);
                                u3->field38++;
                            } else if (strcmp(w0, data_ov000_021b37c8) == 0) {
                                if (u3->field38 > 0) {
                                    q = func_ov000_021a3678(u3->field40, u3->field38 * 4);
                                    if (q == NULL) {
                                        GpiSetErrorMessage(a, data_ov000_021b35f8);
                                        return 1;
                                    }
                                    u3->field40 = (char **) q;
                                    q = func_ov000_021a3690(0x15);
                                    if (q == NULL) {
                                        GpiSetErrorMessage(a, data_ov000_021b35f8);
                                        return 1;
                                    }
                                    u3->field40[u3->field38 - 1] = q;
                                    GpiCopyString(u3->field40[u3->field38 - 1], w1, 0x15);
                                }
                            } else if (strcmp(w0, data_ov000_021b3824) == 0) {
                                d = TRUE;
                            } else {
                                GpiSetError(a, 1, data_ov000_021b37f4);
                                GpiQueueErrorCallback(a, 3, 1);
                                return 3;
                            }
                        } while (d == FALSE);
                        r = GpiQueueCallback(a, c3, u3, b, 3);
                        if (r != 0) {
                            return r;
                        }
                    }
                } else if (p->mKind == 4) {
                    c4 = b->fieldC;
                    if (c4.mCallback != NULL) {
                        u4 = func_ov000_021a3690(0x10);
                        if (u4 == NULL) {
                            GpiSetErrorMessage(a, data_ov000_021b35f8);
                            return 1;
                        }
                        u4->field4 = p->field138;
                        d = FALSE;
                        u4->field0 = 0;
                        u4->field8 = 0;
                        u4->fieldC = NULL;
                        do {
                            r = GpiReadKeyValue(a, p->mInputBuffer, &n, (s8 *) w0, (s8 *) w1);
                            if (r != 0) {
                                return r;
                            }
                            if (strcmp(w0, data_ov000_021b382c) == 0) {
                                d = TRUE;
                            } else if (strcmp(w0, data_ov000_021b3834) == 0) {
                                u4->field8++;
                                u4->fieldC = func_ov000_021a3678(u4->fieldC, u4->field8 * 0x128);
                                q4 = u4->fieldC;
                                if (q4 == NULL) {
                                    GpiSetErrorMessage(a, data_ov000_021b35f8);
                                    return 1;
                                }
                                i = u4->field8 - 1;
                                t4 = &q4[i];
                                memset(t4, 0, 0x128);
                                t4->field24 = 1;
                                q4[i].field0 = StrtolBase10(w1);
                                f = FALSE;
                                do {
                                    g = n;
                                    r = GpiReadKeyValue(a, p->mInputBuffer, &n, (s8 *) w0, (s8 *) w1);
                                    if (r != 0) {
                                        return r;
                                    }
                                    if (strcmp(w0, data_ov000_021b3838) == 0) {
                                        GpiCopyString(t4->field28, w1, 0x100);
                                    } else if (strcmp(w0, data_ov000_021b37c0) == 0) {
                                        GpiCopyString(t4->field4, w1, 0x1f);
                                    }
                                    if (strcmp(w0, data_ov000_021b3840) == 0) {
                                        t4->field24 = StrtolBase10(w1);
                                    } else if (strcmp(w0, data_ov000_021b3834) == 0 ||
                                               strcmp(w0, data_ov000_021b382c) == 0) {
                                        f = TRUE;
                                        n = g;
                                    }
                                } while (f == FALSE);
                            } else {
                                GpiSetError(a, 1, data_ov000_021b37f4);
                                GpiQueueErrorCallback(a, 3, 1);
                                return 3;
                            }
                        } while (d == FALSE);
                        r = GpiQueueCallback(a, c4, u4, b, 4);
                        if (r != 0) {
                            return r;
                        }
                    }
                } else if (p->mKind == 5) {
                    c5 = b->fieldC;
                    if (c5.mCallback != NULL) {
                        r = GpiReadKeyValue(a, p->mInputBuffer, &n, (s8 *) w0, (s8 *) w1);
                        if (r != 0) {
                            return r;
                        }
                        if (strcmp(w0, data_ov000_021b384c) != 0) {
                            GpiSetError(a, 1, data_ov000_021b37f4);
                            GpiQueueErrorCallback(a, 3, 1);
                            return 3;
                        }
                        x = StrtolBase10(w1);
                        if (x != 0) {
                            o->mErrorNumber = x;
                            y = 0;
                        } else {
                            if (GpiGetValue(p->mInputBuffer, data_ov000_021b3850, w1, 0x200) == FALSE) {
                                GpiSetError(a, 1, data_ov000_021b37f4);
                                GpiQueueErrorCallback(a, 3, 1);
                                return 3;
                            }
                            y = StrtolBase10(w1);
                        }
                        u5 = func_ov000_021a3690(8);
                        if (u5 == NULL) {
                            GpiSetErrorMessage(a, data_ov000_021b35f8);
                            return 1;
                        }
                        u5->field0 = x;
                        u5->field4 = y;
                        r = GpiQueueCallback(a, c5, u5, b, 0);
                        if (r != 0) {
                            return r;
                        }
                    }
                } else if (p->mKind == 6) {
                    c6 = b->fieldC;
                    if (c6.mCallback != NULL) {
                        r = GpiReadKeyValue(a, p->mInputBuffer, &n, (s8 *) w0, (s8 *) w1);
                        if (r != 0) {
                            return r;
                        }
                        if (strcmp(w0, data_ov000_021b3858) != 0) {
                            GpiSetError(a, 1, data_ov000_021b37f4);
                            GpiQueueErrorCallback(a, 3, 1);
                            return 3;
                        }
                        x = StrtolBase10(w1);
                        if (x != 0) {
                            o->mErrorNumber = x;
                        }
                        if (GpiGetValue(p->mInputBuffer, data_ov000_021b3850, w1, 0x200) == FALSE) {
                            if (x == 0) {
                                GpiSetError(a, 1, data_ov000_021b37f4);
                                GpiQueueErrorCallback(a, 3, 1);
                                return 3;
                            }
                            y = 0;
                        } else {
                            y = StrtolBase10(w1);
                        }
                        u5 = func_ov000_021a3690(8);
                        if (u5 == NULL) {
                            GpiSetErrorMessage(a, data_ov000_021b35f8);
                            return 1;
                        }
                        u5->field0 = x;
                        u5->field4 = y;
                        r = GpiQueueCallback(a, c6, u5, b, 0);
                        if (r != 0) {
                            return r;
                        }
                    }
                } else if (p->mKind == 7) {
                    c7 = b->fieldC;
                    if (c7.mCallback != NULL) {
                        u7 = func_ov000_021a3690(0xc);
                        if (u7 == NULL) {
                            GpiSetErrorMessage(a, data_ov000_021b35f8);
                            return 1;
                        }
                        u7->field0 = 0;
                        u7->field4 = 0;
                        u7->field8 = NULL;
                        r = GpiReadKeyValue(a, p->mInputBuffer, &n, (s8 *) w0, (s8 *) w1);
                        if (r != 0) {
                            return r;
                        }
                        if (strcmp(w0, data_ov000_021b385c) != 0) {
                            GpiSetError(a, 1, data_ov000_021b37f4);
                            GpiQueueErrorCallback(a, 3, 1);
                            return 3;
                        }
                        d = FALSE;
                        do {
                            r = GpiReadKeyValue(a, p->mInputBuffer, &n, (s8 *) w0, (s8 *) w1);
                            if (r != 0) {
                                return r;
                            }
                            if (strcmp(w0, data_ov000_021b3864) == 0) {
                                d = TRUE;
                            } else if (strcmp(w0, data_ov000_021b386c) == 0) {
                                q1 = func_ov000_021a3678(u7->field8, (u7->field4 + 1) * 0xac);
                                if (q1 == NULL) {
                                    GpiSetErrorMessage(a, data_ov000_021b35f8);
                                    return 1;
                                }
                                u7->field8 = q1;
                                q1 = u7->field8;
                                i = u7->field4;
                                t1 = &q1[i];
                                memset(t1, 0, 0xac);
                                u7->field4++;
                                q1[i].field0 = StrtolBase10(w1);
                                f = FALSE;
                                do {
                                    g = n;
                                    r = GpiReadKeyValue(a, p->mInputBuffer, &n, (s8 *) w0, (s8 *) w1);
                                    if (r != 0) {
                                        return r;
                                    }
                                    if (strcmp(w0, data_ov000_021b37c0) == 0) {
                                        GpiCopyString(t1->field4, w1, 0x1f);
                                    } else if (strcmp(w0, data_ov000_021b37c8) == 0) {
                                        GpiCopyString(t1->field23, w1, 0x15);
                                    } else if (strcmp(w0, data_ov000_021b3870) == 0) {
                                        GpiCopyString(t1->field38, w1, 0x1f);
                                    } else if (strcmp(w0, data_ov000_021b3878) == 0) {
                                        GpiCopyString(t1->field57, w1, 0x1f);
                                    } else if (strcmp(w0, data_ov000_021b37ec) == 0) {
                                        GpiCopyString(t1->field76, w1, 0x33);
                                    } else if (strcmp(w0, data_ov000_021b386c) == 0 ||
                                               strcmp(w0, data_ov000_021b3864) == 0) {
                                        f = TRUE;
                                        n = g;
                                    }
                                } while (f == FALSE);
                            } else {
                                GpiSetError(a, 1, data_ov000_021b37f4);
                                GpiQueueErrorCallback(a, 3, 1);
                                return 3;
                            }
                        } while (d == FALSE);
                        r = GpiQueueCallback(a, c7, u7, b, 8);
                        if (r != 0) {
                            return r;
                        }
                    }
                } else if (p->mKind == 8) {
                    c8 = b->fieldC;
                    if (c8.mCallback != NULL) {
                        i = 0;
                        u9 = func_ov000_021a3690(0xc);
                        if (u9 == NULL) {
                            GpiSetErrorMessage(a, data_ov000_021b35f8);
                            return 1;
                        }
                        u9->field0 = 0;
                        u9->field4 = 0;
                        u9->field8 = NULL;
                        r = GpiReadKeyValue(a, p->mInputBuffer, &n, (s8 *) w0, (s8 *) w1);
                        if (r != 0) {
                            return r;
                        }
                        if (strcmp(w0, data_ov000_021b3880) != 0) {
                            GpiSetError(a, 1, data_ov000_021b37f4);
                            GpiQueueErrorCallback(a, 3, 1);
                            return 3;
                        }
                        u9->field4 = StrtolBase10(w1);
                        u9->field8 = func_ov000_021a3690(u9->field4 * 4);
                        if (u9->field8 == NULL) {
                            GpiSetErrorMessage(a, data_ov000_021b35f8);
                            return 1;
                        }
                        d = FALSE;
                        do {
                            r = GpiReadKeyValue(a, p->mInputBuffer, &n, (s8 *) w0, (s8 *) w1);
                            if (r != 0) {
                                return r;
                            }
                            if (strcmp(w0, data_ov000_021b37c0) == 0) {
                                u9->field8[i] = func_ov000_021a3690(0x15);
                                if (u9->field8[i] == NULL) {
                                    GpiSetErrorMessage(a, data_ov000_021b35f8);
                                    return 1;
                                }
                                GpiCopyString(u9->field8[i], w1, 0x15);
                                i++;
                            } else if (strcmp(w0, data_ov000_021b3884) == 0) {
                                if (i != u9->field4) {
                                    __msl_assertion_failed(data_ov000_021b388c, data_ov000_021b3628, NULL, 0x515);
                                }
                                u9->field4 = i;
                                d = TRUE;
                            } else {
                                GpiSetError(a, 1, data_ov000_021b37f4);
                                GpiQueueErrorCallback(a, 3, 1);
                                return 3;
                            }
                        } while (d == FALSE);
                        r = GpiQueueCallback(a, c8, u9, b, 9);
                        if (r != 0) {
                            return r;
                        }
                    }
                } else {
                    __msl_assertion_failed(data_ov000_021b3768, data_ov000_021b3628, NULL, 0x52a);
                }
                p->field140 = TRUE;
                k = FALSE;
            }
        }
        if (k != FALSE) {
            func_ov000_0218e8bc(10);
        }
    } while (k != FALSE);
    return 0;
}

BOOL GpiUpdateSearches(GpConnection *a) {
    GpiConnection *r;
    GpiOperation **v;
    GpiOperation *p;
    Unk02196240 *c;
    u32 t;
    s32 n;
    s32 i;

    r = a->mGpiConnection;
    n = 0;
    if (r->mSearchCount > 0) {
        v = func_ov000_021a3690(r->mSearchCount * 4);
        if (v == NULL) {
            GpiSetErrorMessage(a, data_ov000_021b35f8);
            return TRUE;
        }
        for (p = r->mOperationList; p != NULL; p = p->mNext) {
            if (p->mType == 3 && p->field14 != 5 && p->field4->field13C == 0) {
                if (n >= r->mSearchCount) {
                    __msl_assertion_failed(data_ov000_021b3608, data_ov000_021b3628, NULL, 0x563);
                }
                v[n++] = p;
                p->field4->field13C = 1;
            }
        }
        for (i = 0; i < n; i++) {
            t = GpiUpdateSearch(a, v[i]);
            if (t != 0) {
                v[i]->field1C = t;
            }
        }
        for (i = 0; i < n; i++) {
            c = v[i]->field4;
            c->field13C = 0;
            if (c->field140 != 0) {
                GpiRemoveOperation(a, v[i]);
            }
        }
        func_ov000_021a3668(v);
    }
    return FALSE;
}
