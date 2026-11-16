#include "00/Lib/DWC/address_convert.h"

u32 ConvAddress(const u8 *bytes) {
    u32 valueA = (u32) bytes;
    u32 word;
    u32 valueB;
    u32 valueC;
    u32 valueD;
    word = 0u;
    valueB = *(const u8 *) ((valueA) + 0u);
    valueB = (valueB << 24);
    word = (word) | (valueB);
    valueB = *(const u8 *) ((valueA) + 1u);
    valueB = (valueB << 16);
    word = (word) | (valueB);
    valueB = *(const u8 *) ((valueA) + 2u);
    valueB = (valueB << 8);
    word = (word) | (valueB);
    valueA = *(const u8 *) ((valueA) + 3u);
    word = (word) | (valueA);
    valueA = (word << 24);
    valueB = 0xff000000u;
    valueA = (valueA) & (valueB);
    valueD = (word << 8);
    valueB = 0xff0000u;
    valueD = (valueD) & (valueB);
    valueC = (word >> 24);
    valueB = 255u;
    valueC = (valueC) & (valueB);
    valueB = (word >> 8);
    word = 0xff00u;
    valueB = (valueB) & (word);
    valueC = (valueC) | (valueB);
    valueD = (valueD) | (valueC);
    valueA = (valueA) | (valueD);
    return valueA;
}
