#include "00/code_021ad018.h"
#include "00/code_021ad3b8.h"
#include "00/code_021ad734.h"
#include "00/unk_021b6380.h"
#include "code_0200f5ac.h"

BOOL dhcp_request_server(u32 *sleep, s32 mode) {
    s32 result;
    s32 retry;
    u32 savedSleep;

    CPS_SocUse();
    CPS_SocDatagramMode();
    if (mode == 1) {
        CPS_SocBind(0x44, 0x43, CPSDhcpServerIp);
    } else {
        CPS_SocBind(0x44, 0x43, -1);
    }
    for (retry = 0; retry < 4; retry++) {
        result = dhcp_analyze_response(dhcp_send_request(mode), retry);
        if (result != 0) {
            break;
        }
    }
    CPS_SocRelease();
    if (result == 2) {
        *sleep = gLeaseTime >> 1;
        gSleepSave = gLeaseTime * 3 >> 3;
        return TRUE;
    }
    savedSleep = gSleepSave >> 1;
    gSleepSave = savedSleep;
    *sleep = savedSleep;
    switch (mode) {
        case 1:
            if (savedSleep < 0x3c) {
                *sleep = 1;
                gSleepSave = gLeaseTime >> 3;
            }
            break;
        case 2:
            if (savedSleep < 0x3c) {
                *sleep = 1;
            }
            break;
    }
    return FALSE;
}

void dhcp_release_server(void) {
    u8 *cursor;
    u8 *message;
    u8 *paddedEnd;

    CPS_SocUse();
    CPS_SocDatagramMode();
    CPS_SocBind(0x44, 0x43, CPSDhcpServerIp);
    message = (u8 *) &gScavengerSendPayload;
    cursor = dhcp_setcommon(message, 7, NULL);
    *cursor = 0xff;
    cursor++;
    paddedEnd = pad_mem(0, 0x12c, cursor, cursor - message);
    CPS_SocWrite(message, paddedEnd - message);
    CPS_SocRelease();
}

u8 *dns_skipname(u8 *name) {
    u32 labelLength;

    labelLength = *name++;
    while (labelLength != 0) {
        if ((labelLength & 0xc0) == 0xc0) {
            return name + 1;
        }
        name += labelLength;
        labelLength = *name++;
    }
    return name;
}

s32 resolve_common(const char *a, u32 b, s32 c) {
    struct {
        /* 00 */ u32 mUnk_00;
        /* 04 */ u16 mUnk_04;
        /* 06 */ u16 mUnk_06;
        /* 08 */ u16 mUnk_08;
        /* 0a */ u16 mUnk_0a;
        /* 0c */ u16 mUnk_0c;
        /* 0e */ u16 mUnk_0e;
        /* 10 */ u8 mUnk_10[0x30];
    } v;
    u8 *q;
    u8 *p;
    u8 d;
    u8 *r;
    s32 e;
    s32 f;
    u32 g;
    u32 h;
    u16 i;
    u16 j;
    u32 k;

    v.mUnk_04 = (c >> 8) | (c << 8);
    if (b == 1) {
        v.mUnk_06 = 1;
    } else {
        v.mUnk_06 = 0x1001;
    }
    v.mUnk_08 = 0x100;
    v.mUnk_0a = 0;
    v.mUnk_0c = 0;
    v.mUnk_0e = 0;
    p = v.mUnk_10;
    q = p + 1;
    v.mUnk_00 = 0;
    d = *a++;
    while (d != 0) {
        if (d != '.') {
            if (q - (u8 *) &v.mUnk_04 >= 0x3c) {
                return -1;
            }
            *q = d;
            q++;
            v.mUnk_00++;
        } else {
            *p = v.mUnk_00;
            p = q;
            q++;
            v.mUnk_00 = 0;
        }
        d = *a++;
    }
    *p = v.mUnk_00;
    q[0] = 0;
    q[1] = b >> 8;
    q[2] = b;
    q[3] = 0;
    q[4] = 1;
    CPS_SocWrite((u8 *) &v.mUnk_04, q + 5 - (u8 *) &v.mUnk_04);
    e = 0;
    g = OS_GetTick() >> 16;
    f = -1;
    while (gLinkIsOn() != 0 && e == 0 && (s32) ((u32) (OS_GetTick() >> 16) - g) < 0xf) {
        if (CPS_SocGetLength() == 0) {
            yield_thread();
            continue;
        }
        r = CPS_SocRead(&v.mUnk_00);
        if (v.mUnk_00 > 0xc && c == (u16) ((*(u16 *) r >> 8) | (*(u16 *) r << 8))) {
            k = r[3] & 0xf;
            if (k == 3) {
                e = f;
            } else if (k == 0) {
                p = r + v.mUnk_00;
                i = r[4] << 8 | r[5];
                r += 12;
                h = i;
                while (h-- != 0) {
                    r = dns_skipname(r);
                    r += 4;
                }
                while (r < p) {
                    r = dns_skipname(r);
                    j = r[8] << 8 | r[9];
                    if (b == (u16) (r[0] << 8 | r[1])) {
                        e = (u16) (((u8 *) (r + 6) + j)[0] << 8 | ((u8 *) (r + 6) + j)[1]) << 16 |
                            (u16) (((u8 *) (r + 8) + j)[0] << 8 | ((u8 *) (r + 8) + j)[1]);
                        break;
                    }
                    r += j + 10;
                }
            }
        }
        CPS_SocConsume(v.mUnk_00);
    }
    return e;
}

u32 strtol10(const char *text, const char **end) {
    u32 value;
    u8 digit;

    *end = text;
    value = 0;
    for (;;) {
        digit = *text - '0';
        if (digit > 9) {
            break;
        }
        value = value * 10 + digit;
        text++;
        *end = text;
    }
    return value;
}

BOOL rawip(const char *name, u32 *address) {
    const char *cursor;
    const char *fieldEnd;
    u32 result;
    u32 octet;
    s32 fieldIndex;

    result = 0;
    fieldIndex = 0;
    cursor = name;
    do {
        result <<= 8;
        octet = strtol10(cursor, &fieldEnd);
        if (cursor == fieldEnd) {
            return FALSE;
        }
        cursor = fieldEnd;
        if (octet > 0xff || (fieldIndex != 3 && (cursor++, *fieldEnd != '.')) || (fieldIndex == 3 && *cursor != 0)) {
            return FALSE;
        }
        result |= octet;
        fieldIndex++;
    } while (fieldIndex < 4);
    *address = result;
    return TRUE;
}
