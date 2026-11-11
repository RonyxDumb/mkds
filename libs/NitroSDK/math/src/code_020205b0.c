#include "code_020205b0.h"

void Crc8InitTable(u8 *table, u32 polynomial) {
    u32 entry;
    u32 index;
    u32 bitIndex;

    for (index = 0; index < 0x100; index++) {
        entry = index;
        for (bitIndex = 0; bitIndex < 8; bitIndex++) {
            if (entry & 0x80) {
                entry = polynomial ^ (entry << 1);
            } else {
                entry = entry << 1;
            }
        }
        table[index] = entry;
    }
}

void Crc8Continue(const u8 *table, u8 *crc, const u8 *data, u32 length) {
    u32 crcValue;
    u32 index;

    crcValue = *crc;
    for (index = 0; index < length; index++) {
        crcValue = table[(crcValue ^ *data) & 0xff];
        data++;
    }
    *crc = crcValue;
}

void Crc16InitTable(u16 *table, u32 polynomial) {
    u32 entry;
    u32 index;
    u32 bitIndex;

    for (index = 0; index < 0x100; index++) {
        entry = index;
        for (bitIndex = 0; bitIndex < 8; bitIndex++) {
            if (entry & 1) {
                entry = polynomial ^ (entry >> 1);
            } else {
                entry = entry >> 1;
            }
        }
        table[index] = entry;
    }
}

void Crc16Continue(const u16 *table, u16 *crc, const u8 *data, u32 length) {
    u32 crcValue;
    u32 index;

    crcValue = *crc;
    for (index = 0; index < length; index++) {
        crcValue = table[(crcValue ^ *data) & 0xff] ^ (crcValue >> 8);
        data++;
    }
    *crc = crcValue;
}

void Crc32InitTable(u32 *table, u32 polynomial) {
    u32 entry;
    u32 index;
    u32 bitIndex;

    for (index = 0; index < 0x100; index++) {
        entry = index;
        for (bitIndex = 0; bitIndex < 8; bitIndex++) {
            if (entry & 1) {
                entry = polynomial ^ (entry >> 1);
            } else {
                entry = entry >> 1;
            }
        }
        table[index] = entry;
    }
}

void Crc32Continue(const u32 *table, u32 *crc, const u8 *data, u32 length) {
    u32 crcValue;
    u32 index;

    crcValue = *crc;
    for (index = 0; index < length; index++) {
        crcValue = table[(crcValue ^ *data) & 0xff] ^ (crcValue >> 8);
        data++;
    }
    *crc = crcValue;
}

u8 Crc8(const u8 *table, const void *data, u32 length) {
    u8 crc;

    crc = 0;
    Crc8Continue(table, &crc, data, length);
    return crc;
}

u16 Crc16(const u16 *table, const u8 *data, u32 length) {
    u16 crc;

    crc = 0;
    Crc16Continue(table, &crc, data, length);
    return crc;
}

u32 Crc32(const u32 *table, const void *data, u32 length) {
    u32 crc;

    crc = -1;
    Crc32Continue(table, &crc, data, length);
    return ~crc;
}
