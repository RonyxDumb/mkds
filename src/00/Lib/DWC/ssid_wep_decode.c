#include "00/Lib/DWC/ssid_wep_decode.h"
#include "hash1.h"
#include "signed_int_divide.h"
#include "cpu_copy_fill.h"

SsidOrderTable gSsidOrderTable = {
    {0x17, 0x14, 0x11, 0xd, 0xb, 6, 0xf, 0xe, 9, 0x15, 0xc, 4, 2, 1, 0x12, 0x10, 5, 3, 0x13, 0xa, 7, 8, 0, 0x16}};
const u8 gConv4BitTable[16] = {0xa, 0xd, 0xe, 8, 9, 3, 6, 0, 0xc, 5, 2, 7, 0xb, 1, 0xf, 4};
s8 *gUsbWepSecondXorKey = (s8 *) "%(egEr)ag(s&m";
const u8 gConvByteTable[13] = {5, 1, 0xc, 4, 2, 3, 0xa, 0, 0xb, 7, 9, 8, 6};
s8 *gSsidDecodeSecondXorKey = (s8 *) "38g6zxjk20gvmv]6^=j&%vY1";
s8 *gUsbWepFirstXorKey = (s8 *) "gwi'6&fs=0Nf~";
s8 *gSsidDecodeFirstXorKey = (s8 *) "952uybjnpmu903bia@bk5m[-";

void DecodeSsid(const u8 *ssid, u8 *decoded) {
    SsidOrderTable order = gSsidOrderTable;
    s32 startIndex;
    s32 firstXorIndex;
    s32 previousIndex;
    s32 currentIndex;
    s32 secondXorIndex;
    u32 moving;
    u32 displaced;
    u8 *entry;
    DecodeBase64(ssid, decoded, 32, 24);
    for (firstXorIndex = 0; firstXorIndex < 24; firstXorIndex++) {
        decoded[firstXorIndex] ^= gSsidDecodeFirstXorKey[firstXorIndex];
    }
    for (startIndex = 0; startIndex < 24; startIndex++) {
        previousIndex = (u8) startIndex;
        currentIndex = previousIndex;
        moving = decoded[startIndex];
        while (order.mOrder[currentIndex] != 0xff) {
            entry = &order.mOrder[currentIndex];
            currentIndex = order.mOrder[currentIndex];
            displaced = decoded[currentIndex];
            decoded[order.mOrder[previousIndex]] = moving;
            previousIndex = currentIndex;
            *entry = 0xff;
            moving = displaced;
        }
    }
    for (secondXorIndex = 0; secondXorIndex < 24; secondXorIndex++) {
        decoded[secondXorIndex] ^= gSsidDecodeSecondXorKey[secondXorIndex];
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
    s32 byteIndex;
    s32 tailIndex;
    s32 xorIndex;
    s32 copyIndex;
    s32 secondXorIndex;
    s32 nibbleIndex;
    s32 mixIndex;
    for (byteIndex = 0; byteIndex < 13; byteIndex++) {
        wepKey[byteIndex] = name[byteIndex] ^ name[byteIndex % 7 + 13];
    }
    for (tailIndex = 0; tailIndex < 7; tailIndex++) {
        wepKey[tailIndex + 3] ^= name[tailIndex + 13];
    }
    for (xorIndex = 0; xorIndex < 13; xorIndex++) {
        wepKey[xorIndex] ^= gUsbWepFirstXorKey[xorIndex];
    }
    MI_CpuCopy8(wepKey, copy, 13);
    copyIndex = 0;
    source = copy;
    target = gConvByteTable;
    for (; copyIndex < 13; copyIndex++) {
        wepKey[*target] = *source;
        source++;
        target++;
    }
    for (secondXorIndex = 0; secondXorIndex < 13; secondXorIndex++) {
        wepKey[secondXorIndex] ^= gUsbWepSecondXorKey[secondXorIndex];
    }
    for (nibbleIndex = 0; nibbleIndex < 13; nibbleIndex++) {
        u8 keyByte = wepKey[nibbleIndex];
        wepKey[nibbleIndex] = (gConv4BitTable[(keyByte >> 4) & 15] << 4) | gConv4BitTable[keyByte & 15];
    }
    for (mixIndex = 0; mixIndex < 3; mixIndex++) {
        wepKey[mixIndex] ^= wepKey[mixIndex + 6];
        wepKey[mixIndex + 3] ^= wepKey[mixIndex + 9];
        wepKey[mixIndex + 6] ^= wepKey[mixIndex + 3];
        wepKey[mixIndex + 9] ^= wepKey[mixIndex];
        wepKey[12] ^= wepKey[mixIndex];
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
    s32 groupStart;
    u32 group;
    s32 charIndex;
    u32 groupBytes;
    u32 tailGroup;
    s32 byteIndex;
    if (capacity >= (u32) (encodedLength * 3) >> 2) {
        remainder = encodedLength & 3;
        fullLength = encodedLength - remainder;
    } else {
        return -1;
    }
    groupStart = 0;
    for (; groupStart < fullLength; groupStart += 4) {
        group = 0;
        for (charIndex = 0; charIndex < 4; charIndex++) {
            group |= CodeToValue(encoded[groupStart + charIndex]) << ((3 - charIndex) * 6);
        }
        groupBytes = group;
        for (byteIndex = 0; byteIndex < 3; byteIndex++) {
            decoded[groupStart / 4 * 3 + byteIndex] = ((u8 *) &groupBytes)[2 - byteIndex];
        }
    }
    if (remainder != 0) {
        group = 0;
        tailGroup = 0;
        for (charIndex = 0; charIndex < remainder; charIndex++) {
            group |= CodeToValue(encoded[fullLength + charIndex]) << ((3 - charIndex) * 6);
            tailGroup |= group;
        }
        for (charIndex = 0; charIndex < remainder; charIndex++) {
            decoded[fullLength * 3 / 4 + charIndex] = ((u8 *) &tailGroup)[2 - charIndex];
        }
    }
    return (u32) (encodedLength * 3) >> 2;
}
