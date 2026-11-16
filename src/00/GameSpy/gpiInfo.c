#include "00/GameSpy/gpiInfo.h"

#include "00/GameSpy/gpiBuddy.h"
#include "00/code_02194000.h"
#include "00/GameSpy/gp.h"
#include "00/GameSpy/gpi.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/GameSpy/gpiBuffer.h"
#include "00/code_0219210c.h"
#include "00/code_02193000.h"
#include "00/code_02196590.h"
#include "00/GameSpy/gpiUtility.h"
#include "00/code_021a3690.h"
#include "string.h"
#include "code_02134398.h"
#include "code_0213a460.h"
#include "code_02133048.h"
#include "00/GameSpy/nonport.h"
#include "00/code_02192d64.h"
#include "00/unk_021b2000.h"
#include "00/unk_021b3000.h"
#include "00/code_021947e4.h"
#include "00/code_021965a0.h"
#include "00/code_021919ac.h"
#include "00/GameSpy/gpiOperation.h"
#include "00/GameSpy/gpiProfile.h"
#include "00/code_0218e0fc.h"
#include "00/code_02191200.h"
#include "00/code_02196480.h"
#include "00/GameSpy/gpiCallback.h"
#include "00/code_02196000.h"
#include "00/code_021a3668.h"
#include "00/GameSpy/gpiPeer.h"

u32 GpiUnpackDate(u32 *a, s32 b, u32 *c, u32 *d, u32 *e) {
    int v1;
    u32 v2;
    u32 v3;
    v2 = b >> 0x18 & 0xff;
    v3 = b >> 0x10 & 0xff;
    b = b & (0x0000ffffu);
    v1 = GpiIsValidDate(v2, v3, b);
    if (v1 == 0) {
        __msl_assertion_failed(data_ov000_021b323c, data_ov000_021b31f8, NULL, 0xb7);
    }
    v1 = GpiIsValidDate(v2, v3, b);
    if (v1 == 0) {
        GpiSetErrorMessage((u32 *) (u32) a, data_ov000_021b3254);
        return 2;
    }
    *c = v2;
    *d = v3;
    *e = b;
    return 0;
}

void func_ov000_0219338c(Unk02192e04 *a, Unk0219338c *b) {
    if (a->field0[0] != NULL) {
        GpiCopyString(b->field8, a->field0[0], 0x1f);
    } else {
        b->field8[0] = 0;
    }
    if (a->field0[1] != NULL) {
        GpiCopyString(b->field27, a->field0[1], 0x15);
    } else {
        b->field27[0] = 0;
    }
    if (a->field0[2] != NULL) {
        GpiCopyString(b->field3C, a->field0[2], 0x33);
    } else {
        b->field3C[0] = 0;
    }
    if (a->field0[3] != NULL) {
        GpiCopyString(b->field6F, a->field0[3], 0x1f);
    } else {
        b->field6F[0] = 0;
    }
    if (a->field0[4] != NULL) {
        GpiCopyString(b->field8E, a->field0[4], 0x1f);
    } else {
        b->field8E[0] = 0;
    }
    if (a->field0[5] != NULL) {
        GpiCopyString(b->fieldAD, a->field0[5], 0x4c);
    } else {
        b->fieldAD[0] = 0;
    }
    b->fieldFC = a->field18;
    GpiCopyString(b->field100, a->field1C, 0xb);
    GpiCopyString(b->field10B, a->field27, 3);
    b->field110 = a->field2C;
    b->field114 = a->field30;
    if (a->field34 != NULL) {
        GpiCopyString(b->field118, a->field34, 0x80);
    } else {
        b->field118[0] = 0;
    }
    b->field198 = a->fieldB4;
    b->field19C = a->fieldB8;
    b->field1A0 = a->fieldBC;
    b->field1A4 = a->fieldC0;
    b->field1A8 = a->fieldC4;
    if (a->fieldC8 != NULL) {
        GpiCopyString(b->field1AC, a->fieldC8, 0x33);
    } else {
        b->field1AC[0] = 0;
    }
    b->fieldFC = a->field18;
    b->field110 = a->field2C;
    b->field114 = a->field30;
    b->field198 = a->fieldB4;
    b->field19C = a->fieldB8;
    b->field1A0 = a->fieldBC;
    b->field1A4 = a->fieldC0;
    b->field1A8 = a->fieldC4;
    b->field1E0 = a->fieldCC[0];
    b->field1E4 = a->fieldCC[1];
    b->field1E8 = a->fieldCC[2];
    b->field1EC = a->fieldCC[3];
    b->field1F0 = a->fieldCC[4];
    b->field1F4 = a->fieldCC[5];
    b->field1F8 = a->fieldCC[6];
    b->field1FC = a->fieldCC[7];
    b->field200 = a->fieldCC[8];
}

s32 GpiProcessInfoOperation(GpConnection *r, GpiOperation *s, const char *t) {
    GpiConnection *a;
    GpiProfile *b;
    GpiCallback c;
    char d[0x40];
    char e[0x1f];
    char f[0x15];
    char g[0x33];
    char h[0x1f];
    char i[0x1f];
    char j[0x33];
    Unk0219338c *l;
    GpiPeer *q;
    s32 profileid;
    s32 o;
    s32 p;

    a = r->mGpiConnection;
    if (GpiReadError(r, t, 1) != FALSE) {
        return 4;
    }
    if (strncmp(t, data_ov000_021b31b0, 4) != 0) {
        GpiSetError(r, 1, data_ov000_021b31b8);
        GpiQueueErrorCallback(r, 3, 1);
        return 3;
    }
    if (GpiGetValue(t, data_ov000_021b2f80, d, 0x40) == FALSE) {
        GpiSetError(r, 1, data_ov000_021b31b8);
        GpiQueueErrorCallback(r, 3, 1);
        return 3;
    }
    profileid = StrtolBase10(d);
    if (profileid <= 0) {
        __msl_assertion_failed(data_ov000_021b31e8, data_ov000_021b31f8, NULL, 0x15a);
    }
    GpiFindProfile(r, profileid, &b);
    {
        Unk02192e04 k = {0};
        char m[0x4c];
        k.field0[0] = e;
        k.field0[1] = f;
        k.field0[2] = g;
        k.field0[3] = h;
        k.field0[4] = i;
        k.field0[5] = m;
        k.fieldC8 = j;
        if (GpiGetValue(t, data_ov000_021b2fcc, k.field0[0], 0x1f) == FALSE) {
            k.field0[0][0] = 0;
        }
        if (GpiGetValue(t, data_ov000_021b2fd4, k.field0[1], 0x15) == FALSE) {
            k.field0[1][0] = 0;
        }
        if (GpiGetValue(t, data_ov000_021b2fe4, k.field0[2], 0x33) == FALSE) {
            k.field0[2][0] = 0;
        }
        if (GpiGetValue(t, data_ov000_021b2ff8, k.field0[3], 0x1f) == FALSE) {
            k.field0[3][0] = 0;
        }
        if (GpiGetValue(t, data_ov000_021b3004, k.field0[4], 0x1f) == FALSE) {
            k.field0[4][0] = 0;
        }
        if (GpiGetValue(t, data_ov000_021b3064, d, 0x40) == FALSE) {
            k.field18 = -1;
        } else {
            k.field18 = StrtolBase10(d);
        }
        if (GpiGetValue(t, data_ov000_021b3010, k.field0[5], 0x4c) == FALSE) {
            k.field0[5][0] = 0;
        }
        if (GpiGetValue(t, data_ov000_021b301c, k.field1C, 0xb) == FALSE) {
            k.field1C[0] = 0;
        }
        if (GpiGetValue(t, data_ov000_021b3040, k.field27, 3) == FALSE) {
            k.field27[0] = 0;
        }
        if (GpiGetValue(t, data_ov000_021b3204, d, 0x40) == FALSE) {
            k.field2C = 0;
        } else {
            k.field2C = atof(d);
        }
        if (GpiGetValue(t, data_ov000_021b320c, d, 0x40) == FALSE) {
            k.field30 = 0;
        } else {
            k.field30 = atof(d);
        }
        if (GpiGetValue(t, data_ov000_021b3214, k.field34, 0x80) == FALSE) {
            k.field34[0] = 0;
        }
        if (GpiGetValue(t, data_ov000_021b2fb0, d, 0x40) == FALSE) {
            k.fieldB4 = 0;
            k.fieldB8 = 0;
            k.fieldBC = 0;
        } else {
            o = GpiUnpackDate((u32 *) r, StrtolBase10(d), &k.fieldB4, &k.fieldB8, &k.fieldBC);
            if (o != 0) {
                return o;
            }
        }
        if (GpiGetValue(t, data_ov000_021b305c, d, 0x40) == FALSE) {
            k.fieldC0 = 0x502;
        } else if ((s8) d[0] == 0x30) {
            k.fieldC0 = 0x500;
        } else if ((s8) d[0] == 0x31) {
            k.fieldC0 = 0x501;
        } else {
            k.fieldC0 = 0x502;
        }
        if (GpiGetValue(t, data_ov000_021b321c, d, 0x40) == FALSE) {
            k.fieldC4 = -1;
        } else {
            k.fieldC4 = StrtolBase10(d);
        }
        if (GpiGetValue(t, data_ov000_021b30a4, k.fieldC8, 0x33) == FALSE) {
            k.fieldC8[0] = 0;
        }
        if (GpiGetValue(t, data_ov000_021b30ac, d, 0x40) == FALSE) {
            k.fieldCC[0] = 0;
        } else {
            k.fieldCC[0] = StrtolBase10(d);
        }
        if (GpiGetValue(t, data_ov000_021b30b4, d, 0x40) == FALSE) {
            k.fieldCC[1] = 0;
        } else {
            k.fieldCC[1] = StrtolBase10(d);
        }
        if (GpiGetValue(t, data_ov000_021b30bc, d, 0x40) == FALSE) {
            k.fieldCC[2] = 0;
        } else {
            k.fieldCC[2] = StrtolBase10(d);
        }
        if (GpiGetValue(t, data_ov000_021b30c4, d, 0x40) == FALSE) {
            k.fieldCC[3] = 0;
        } else {
            k.fieldCC[3] = StrtolBase10(d);
        }
        if (GpiGetValue(t, data_ov000_021b30cc, d, 0x40) == FALSE) {
            k.fieldCC[4] = 0;
        } else {
            k.fieldCC[4] = StrtolBase10(d);
        }
        if (GpiGetValue(t, data_ov000_021b30d4, d, 0x40) == FALSE) {
            k.fieldCC[5] = 0;
        } else {
            k.fieldCC[5] = StrtolBase10(d);
        }
        if (GpiGetValue(t, data_ov000_021b30dc, d, 0x40) == FALSE) {
            k.fieldCC[6] = 0;
        } else {
            k.fieldCC[6] = StrtolBase10(d);
        }
        if (GpiGetValue(t, data_ov000_021b3224, d, 0x40) == FALSE) {
            k.fieldCC[7] = 0;
        } else {
            k.fieldCC[7] = StrtolBase10(d);
        }
        if (GpiGetValue(t, data_ov000_021b322c, d, 0x40) == FALSE) {
            k.fieldCC[8] = 0;
        } else {
            k.fieldCC[8] = StrtolBase10(d);
        }
        if (GpiGetValue(t, data_ov000_021b3234, d, 0x40) == FALSE) {
            GpiSetError(r, 1, data_ov000_021b31b8);
            GpiQueueErrorCallback(r, 3, 1);
            return 3;
        }
        p = a->field100;
        q = a->mPeerList;
        while (q != NULL) {
            if (q->mProfileId == profileid && q->mState == 0x65) {
                if (b == NULL) {
                    b = GpiFindOrAddProfile(r, profileid);
                }
                q->mState = 0x66;
                p = 1;
            }
            q = q->mNext;
        }
        if (b == NULL && a->field100 != 0) {
            b = GpiFindOrAddProfile(r, profileid);
        }
        if (p != 0) {
            func_ov000_021a3668(b->field18);
            b->field18 = NULL;
            b->field18 = func_ov000_0218e880(d);
        }
        if (a->field100 != 0) {
            func_ov000_0219218c(r, (Unk021919ac_node *) b, (Unk021919ac_f0 *) &k);
        }
        c = s->fieldC;
        if (c.mCallback != NULL) {
            l = func_ov000_021a3690(0x204);
            if (l == NULL) {
                GpiSetErrorMessage(r, data_ov000_021b2f58);
                return 1;
            }
            func_ov000_0219338c(&k, l);
            l->field0 = 0;
            l->field4 = profileid;
            o = GpiQueueCallback(r, c, l, s, 0);
            if (o != 0) {
                return o;
            }
        }
        GpiRemoveOperation(r, s);
        return 0;
    }
}

u32 GpiWriteUpdateBuffers(GpConnection *a, GpiBuffer *b) {
    GpiConnection *v1;
    v1 = a->mGpiConnection;
    if (0 < v1->mUpdateproBufferLength) {
        GpiAppendBufferString(a, b, data_ov000_021b3184);
        GpiAppendBufferNumber(a, b, v1->mSesskey);
        GpiAppendBufferString(a, b, v1->mUpdateproBuffer);
        GpiAppendBufferString(a, b, data_ov000_021b2f94);
        v1->mUpdateproBufferLength = 0;
    }
    if (0 < v1->mUpdateuiBufferLength) {
        GpiAppendBufferString(a, b, data_ov000_021b319c);
        GpiAppendBufferNumber(a, b, v1->mSesskey);
        GpiAppendBufferString(a, b, v1->mUpdateuiBuffer);
        GpiAppendBufferString(a, b, data_ov000_021b2f94);
        v1->mUpdateuiBufferLength = 0;
    }
    return 0;
}

u32 func_ov000_02192d30(GpConnection *p, const char *a, const char *b) {
    GpiConnection *o;
    u32 r;

    o = p->mGpiConnection;
    r = GpiAppendBufferString(p, &o->mUpdateproBuffer, a);
    if (r != 0) {
        return r;
    }
    r = GpiAppendBufferString(p, &o->mUpdateproBuffer, b);
    if (r != 0) {
        return r;
    }
    return 0;
}

u32 func_ov000_02192cfc(GpConnection *p, const char *a, const char *b) {
    GpiConnection *o;
    u32 r;

    o = p->mGpiConnection;
    r = GpiAppendBufferString(p, &o->mUpdateuiBuffer, a);
    if (r != 0) {
        return r;
    }
    r = GpiAppendBufferString(p, &o->mUpdateuiBuffer, b);
    if (r != 0) {
        return r;
    }
    return 0;
}

u32 func_ov000_0219296c(GpConnection *p, s32 a, s32 b) {
    char c[0x10];
    u32 r;

    switch (a) {
        case 0x708:
            if (b < 0) {
                GpiSetErrorMessage(p, data_ov000_021b30e4);
                return 2;
            }
            sprintf(c, data_ov000_021b2f9c, b);
            r = func_ov000_02192d30(p, data_ov000_021b301c, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x70b:
            switch (b) {
                case 0x500:
                    r = func_ov000_02192d30(p, data_ov000_021b305c, data_ov000_021b3050);
                    if (r != 0) {
                        return r;
                    }
                    break;
                case 0x501:
                    r = func_ov000_02192d30(p, data_ov000_021b305c, data_ov000_021b3054);
                    if (r != 0) {
                        return r;
                    }
                    break;
                case 0x502:
                    r = func_ov000_02192d30(p, data_ov000_021b305c, data_ov000_021b3058);
                    if (r != 0) {
                        return r;
                    }
                    break;
                default:
                    GpiSetErrorMessage(p, data_ov000_021b30f8);
                    return 2;
            }
            break;
        case 0x706:
            sprintf(c, data_ov000_021b2f9c, b);
            r = func_ov000_02192d30(p, data_ov000_021b3064, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x70c:
            sprintf(c, data_ov000_021b2f9c, b);
            r = func_ov000_02192cfc(p, data_ov000_021b3108, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x70d:
            sprintf(c, data_ov000_021b2f9c, b);
            r = func_ov000_02192cfc(p, data_ov000_021b3118, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x70e:
            sprintf(c, data_ov000_021b2f9c, b / 16);
            r = func_ov000_02192cfc(p, data_ov000_021b3124, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x710:
            sprintf(c, data_ov000_021b2f9c, b / 4);
            r = func_ov000_02192cfc(p, data_ov000_021b3130, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x712:
            sprintf(c, data_ov000_021b2f9c, b / 4);
            r = func_ov000_02192cfc(p, data_ov000_021b3140, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x713:
            sprintf(c, data_ov000_021b2f9c, b);
            r = func_ov000_02192cfc(p, data_ov000_021b3150, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x714:
            sprintf(c, data_ov000_021b2f9c, b);
            r = func_ov000_02192cfc(p, data_ov000_021b3160, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x715:
            if (b != 0) {
                b = 1;
            }
            sprintf(c, data_ov000_021b2f9c, b);
            r = func_ov000_02192cfc(p, data_ov000_021b3174, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x718:
            sprintf(c, data_ov000_021b2f9c, b);
            r = func_ov000_02192d30(p, data_ov000_021b30ac, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x719:
            sprintf(c, data_ov000_021b2f9c, b);
            r = func_ov000_02192d30(p, data_ov000_021b30b4, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x71a:
            sprintf(c, data_ov000_021b2f9c, b);
            r = func_ov000_02192d30(p, data_ov000_021b30bc, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x71b:
            sprintf(c, data_ov000_021b2f9c, b);
            r = func_ov000_02192d30(p, data_ov000_021b30c4, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x71c:
            sprintf(c, data_ov000_021b2f9c, b);
            r = func_ov000_02192d30(p, data_ov000_021b30cc, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x71d:
            sprintf(c, data_ov000_021b2f9c, b);
            r = func_ov000_02192d30(p, data_ov000_021b30d4, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x71e:
            sprintf(c, data_ov000_021b2f9c, b);
            r = func_ov000_02192d30(p, data_ov000_021b30dc, c);
            if (r != 0) {
                return r;
            }
            break;
        default:
            GpiSetErrorMessage(p, data_ov000_021b2fa0);
            return 2;
    }
    return 0;
}

u32 func_ov000_021923b4(GpConnection *p, s32 a, const s8 *b) {
    GpiConnection *o;
    char c[0x100];
    u32 r;

    o = p->mGpiConnection;
    if (b == NULL) {
        GpiSetErrorMessage(p, data_ov000_021b2fbc);
        return 2;
    }
    switch (a) {
        case 0x700:
            if (*b == 0) {
                GpiSetErrorMessage(p, data_ov000_021b2fbc);
                return 2;
            }
            GpiCopyString(c, (const char *) b, 0x1f);
            GpiCopyString(o->mNick, c, 0x1f);
            r = func_ov000_02192d30(p, data_ov000_021b2fcc, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x701:
            if (*b == 0) {
                GpiSetErrorMessage(p, data_ov000_021b2fbc);
                return 2;
            }
            GpiCopyString(c, (const char *) b, 0x15);
            GpiCopyString((char *) o->mUniquenick, c, 0x15);
            r = func_ov000_02192d30(p, data_ov000_021b2fd4, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x702:
            if (*b == 0) {
                GpiSetErrorMessage(p, data_ov000_021b2fbc);
                return 2;
            }
            GpiCopyString(c, (const char *) b, 0x33);
            func_ov000_0218e850((s8 *) c);
            GpiCopyString(o->mEmail, c, 0x33);
            r = func_ov000_02192cfc(p, data_ov000_021b2fe4, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x703:
            if (*b == 0) {
                GpiSetErrorMessage(p, data_ov000_021b2fbc);
                return 2;
            }
            GpiCopyString(c, (const char *) b, 0x1f);
            GpiCopyString((char *) o->mPassword, c, 0x1f);
            r = func_ov000_02192cfc(p, data_ov000_021b2fec, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x704:
            GpiCopyString(c, (const char *) b, 0x1f);
            r = func_ov000_02192d30(p, data_ov000_021b2ff8, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x705:
            GpiCopyString(c, (const char *) b, 0x1f);
            r = func_ov000_02192d30(p, data_ov000_021b3004, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x707:
            GpiCopyString(c, (const char *) b, 0x4c);
            r = func_ov000_02192d30(p, data_ov000_021b3010, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x708:
            GpiCopyString(c, (const char *) b, 0xb);
            r = func_ov000_02192d30(p, data_ov000_021b301c, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x709:
            if (strlen((const char *) b) != 2) {
                GpiSetErrorMessage(p, data_ov000_021b3028);
                return 2;
            }
            GpiCopyString(c, (const char *) b, 3);
            r = func_ov000_02192d30(p, data_ov000_021b3040, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x70b: {
            s32 d;

            d = *b;
            if (d >= 0 && d < 0x80) {
                d = data_0215d204[d];
            }
            if ((s8) d == 0x4d) {
                __memcpy(c, data_ov000_021b3050, 2);
            } else if ((s8) d == 0x46) {
                __memcpy(c, data_ov000_021b3054, 2);
            } else {
                __memcpy(c, data_ov000_021b3058, 2);
            }
            r = func_ov000_02192d30(p, data_ov000_021b305c, c);
            if (r != 0) {
                return r;
            }
            break;
        }
        case 0x706:
            GpiCopyString(c, (const char *) b, 0x100);
            r = func_ov000_02192d30(p, data_ov000_021b3064, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x70d:
            r = func_ov000_0219296c(p, 0x70d, StrtolBase10((const char *) b));
            if (r != 0) {
                return r;
            }
            break;
        case 0x70e:
            r = func_ov000_0219296c(p, 0x70e, StrtolBase10((const char *) b));
            if (r != 0) {
                return r;
            }
            break;
        case 0x70f:
            GpiCopyString(c, (const char *) b, 0x100);
            r = func_ov000_02192d30(p, data_ov000_021b3070, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x710:
            r = func_ov000_0219296c(p, 0x710, StrtolBase10((const char *) b));
            if (r != 0) {
                return r;
            }
            break;
        case 0x711:
            GpiCopyString(c, (const char *) b, 0x100);
            r = func_ov000_02192d30(p, data_ov000_021b3084, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x712:
            r = func_ov000_0219296c(p, 0x712, StrtolBase10((const char *) b));
            if (r != 0) {
                return r;
            }
            break;
        case 0x714:
            r = func_ov000_0219296c(p, 0x714, StrtolBase10((const char *) b));
            if (r != 0) {
                return r;
            }
            break;
        case 0x715:
            r = func_ov000_0219296c(p, 0x715, StrtolBase10((const char *) b));
            if (r != 0) {
                return r;
            }
            break;
        case 0x716:
            GpiCopyString(c, (const char *) b, 0x100);
            r = func_ov000_02192d30(p, data_ov000_021b3098, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x717:
            GpiCopyString(c, (const char *) b, 0x33);
            r = func_ov000_02192d30(p, data_ov000_021b30a4, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x718:
            GpiCopyString(c, (const char *) b, 0x100);
            r = func_ov000_02192d30(p, data_ov000_021b30ac, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x719:
            GpiCopyString(c, (const char *) b, 0x100);
            r = func_ov000_02192d30(p, data_ov000_021b30b4, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x71a:
            GpiCopyString(c, (const char *) b, 0x100);
            r = func_ov000_02192d30(p, data_ov000_021b30bc, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x71b:
            GpiCopyString(c, (const char *) b, 0x100);
            r = func_ov000_02192d30(p, data_ov000_021b30c4, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x71c:
            GpiCopyString(c, (const char *) b, 0x100);
            r = func_ov000_02192d30(p, data_ov000_021b30cc, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x71d:
            GpiCopyString(c, (const char *) b, 0x100);
            r = func_ov000_02192d30(p, data_ov000_021b30d4, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x71e:
            GpiCopyString(c, (const char *) b, 0x100);
            r = func_ov000_02192d30(p, data_ov000_021b30dc, c);
            if (r != 0) {
                return r;
            }
            break;
        default:
            GpiSetErrorMessage(p, data_ov000_021b2fa0);
            return 2;
    }
    return 0;
}

u32 func_ov000_02192330(GpConnection *p, u32 a, u32 b) {
    GpiConnection *o;

    o = p->mGpiConnection;
    GpiAppendBufferString(p, &o->mOutputBuffer, data_ov000_021b2f68);
    GpiAppendBufferNumber(p, &o->mOutputBuffer, o->mSesskey);
    GpiAppendBufferString(p, &o->mOutputBuffer, data_ov000_021b2f80);
    GpiAppendBufferNumber(p, &o->mOutputBuffer, a);
    GpiAppendBufferString(p, &o->mOutputBuffer, data_ov000_021b2f8c);
    GpiAppendBufferNumber(p, &o->mOutputBuffer, b);
    GpiAppendBufferString(p, &o->mOutputBuffer, data_ov000_021b2f94);
    return 0;
}

u32 func_ov000_0219222c(GpConnection *p, u32 a, s32 b, u32 c, u32 d, u32 e) {
    GpiProfile *x;
    Unk021919ac_node *n;
    Unk021919ac_m *m;
    GpiCallback w;
    u32 r;
    BOOL f;
    u32 t;
    GpiConnection *o;

    o = p->mGpiConnection;
    n = NULL;
    f = FALSE;
    if (b == 1) {
        f = TRUE;
    }
    if (o->field100 == 0) {
        f = FALSE;
    }
    if (d != 0 && f != FALSE && GpiFindProfile(p, a, &x) != 0 && x->fieldC != 0) {
        m = func_ov000_021a3690(0x204);
        if (m == NULL) {
            GpiSetErrorMessage(p, data_ov000_021b2f58);
            return 1;
        }
        func_ov000_0219338c(x->fieldC, (Unk0219338c *) m);
        m->field0 = 0;
        m->field4 = a;
        w.mCallback = (void (*)(void *, void *, u32)) d;
        w.field4 = e;
        r = GpiCreateOperation(p, 2, 0, (s32 *) &n, 1, d, e);
        if (r != 0) {
            return r;
        }
        t = n->mId;
        r = GpiQueueCallback(p, w, m, (GpiOperation *) n, 0);
        if (r != 0) {
            return r;
        }
        GpiRemoveOperation(p, (GpiOperation *) n);
    } else {
        r = GpiCreateOperation(p, 2, 0, (s32 *) &n, c, d, e);
        if (r != 0) {
            return r;
        }
        t = n->mId;
        r = func_ov000_02192330(p, a, t);
        if (r != 0) {
            return r;
        }
    }
    if (c != 0) {
        r = GpiUpdateConnection(p, t);
        if (r != 0) {
            return r;
        }
    }
    return 0;
}

u32 func_ov000_0219218c(GpConnection *p, Unk021919ac_node *n, Unk021919ac_f0 *a) {
    if (p->mGpiConnection->field100 == 0) {
        return 1;
    }
    func_ov000_0219210c(n);
    n->fieldC = func_ov000_021a3690(0xf0);
    if (n->fieldC != NULL) {
        *n->fieldC = *a;
        n->fieldC->field0[0] = func_ov000_0218e880(a->field0[0]);
        n->fieldC->field0[1] = func_ov000_0218e880(a->field0[1]);
        n->fieldC->field0[2] = func_ov000_0218e880(a->field0[2]);
        n->fieldC->field0[3] = func_ov000_0218e880(a->field0[3]);
        n->fieldC->field0[4] = func_ov000_0218e880(a->field0[4]);
        n->fieldC->field0[5] = func_ov000_0218e880(a->field0[5]);
        n->fieldC->fieldC8 = func_ov000_0218e880(a->fieldC8);
    }
    if (n->fieldC != NULL) {
        return 1;
    }
    return 0;
}
