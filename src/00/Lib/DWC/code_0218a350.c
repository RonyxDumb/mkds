#include "00/Lib/DWC/code_0218a350.h"
#include "hash1.h"
#include "code_02133048.h"
#include "code_0214d018.h"

void DecodeSsid(const u8 *ssid, u8 *decoded) {
    SsidOrderTable order = gSsidOrderTable;
    s32 i;
    s32 j;
    s32 k;
    s32 l;
    s32 m;
    u32 moving;
    u32 displaced;
    u8 *entry;
    DecodeBase64(ssid, decoded, 32, 24);
    for (j = 0; j < 24; j++) {
        decoded[j] ^= gSsidDecodeFirstXorKey[j];
    }
    for (i = 0; i < 24; i++) {
        k = (u8) i;
        l = k;
        moving = decoded[i];
        while (order.mOrder[l] != 0xff) {
            entry = &order.mOrder[l];
            l = order.mOrder[l];
            displaced = decoded[l];
            decoded[order.mOrder[k]] = moving;
            k = l;
            *entry = 0xff;
            moving = displaced;
        }
    }
    for (m = 0; m < 24; m++) {
        decoded[m] ^= gSsidDecodeSecondXorKey[m];
    }
}

void MakeShopWepKey(const u8 *decoded, u8 *wepKey) {
    DGTHash1Context context;
    u8 digest[20];
    DGT_Hash1Reset(&context);
    DGT_Hash1SetSource(&context, decoded, 24);
    DGT_Hash1GetDigest_R(digest, &context);
    MI_CpuCopy8(digest + 3, wepKey, 13);
}

void MakeUsbWepKey(const u8 *name, u8 *wepKey) {
    u8 copy[13];
    u8 *source;
    const u8 *target;
    s32 i;
    s32 j;
    s32 k;
    s32 l;
    s32 m;
    s32 n;
    s32 o;
    for (i = 0; i < 13; i++) {
        wepKey[i] = name[i] ^ name[i % 7 + 13];
    }
    for (j = 0; j < 7; j++) {
        wepKey[j + 3] ^= name[j + 13];
    }
    for (k = 0; k < 13; k++) {
        wepKey[k] ^= gUsbWepFirstXorKey[k];
    }
    MI_CpuCopy8(wepKey, copy, 13);
    l = 0;
    source = copy;
    target = gConvByteTable;
    for (; l < 13; l++) {
        wepKey[*target] = *source;
        source++;
        target++;
    }
    for (m = 0; m < 13; m++) {
        wepKey[m] ^= gUsbWepSecondXorKey[m];
    }
    for (n = 0; n < 13; n++) {
        u8 v = wepKey[n];
        wepKey[n] = (gConv4BitTable[(v >> 4) & 15] << 4) | gConv4BitTable[v & 15];
    }
    for (o = 0; o < 3; o++) {
        wepKey[o] ^= wepKey[o + 6];
        wepKey[o + 3] ^= wepKey[o + 9];
        wepKey[o + 6] ^= wepKey[o + 3];
        wepKey[o + 9] ^= wepKey[o];
        wepKey[12] ^= wepKey[o];
    }
}

s32 CodeToValue(u32 code) {
    s32 value;
    if (code >= 0x41 && code <= 0x5a) {
        return code - 0x41;
    }
    if (code >= 0x61 && code <= 0x7a) {
        value = code - 0x61;
        return value + 0x1a;
    }
    if (code >= 0x30 && code <= 0x39) {
        value = code - 0x30;
        return value + 0x34;
    }
    if (code == 0x2b) {
        return 0x3e;
    }
    if (code == 0x2f) {
        return 0x3f;
    }
    return -(code != 0x3d);
}

s32 DecodeBase64(const u8 *encoded, u8 *decoded, s32 encodedLength, u32 capacity) {
    s32 remainder;
    s32 fullLength;
    s32 h;
    u32 group;
    s32 i;
    u32 groupBytes;
    u32 tailGroup;
    s32 m;
    if (capacity >= (u32) (encodedLength * 3) >> 2) {
        remainder = encodedLength & 3;
        fullLength = encodedLength - remainder;
    } else {
        return -1;
    }
    h = 0;
    for (; h < fullLength; h += 4) {
        group = 0;
        for (i = 0; i < 4; i++) {
            group |= CodeToValue(encoded[h + i]) << ((3 - i) * 6);
        }
        groupBytes = group;
        for (m = 0; m < 3; m++) {
            decoded[h / 4 * 3 + m] = ((u8 *) &groupBytes)[2 - m];
        }
    }
    if (remainder != 0) {
        group = 0;
        tailGroup = 0;
        for (i = 0; i < remainder; i++) {
            group |= CodeToValue(encoded[fullLength + i]) << ((3 - i) * 6);
            tailGroup |= group;
        }
        for (i = 0; i < remainder; i++) {
            decoded[fullLength * 3 / 4 + i] = ((u8 *) &tailGroup)[2 - i];
        }
    }
    return (u32) (encodedLength * 3) >> 2;
}
