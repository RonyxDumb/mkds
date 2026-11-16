#include "00/Lib/CPS/bytes_from_words.h"

void char_from_long(u8 *bytes, u32 *words, u32 byteCount) {
    u32 word;
    u32 wordIndex;
    u8 *fourthByte;
    wordIndex = 0;
    if (wordIndex < byteCount >> 2) {
        do {
            word = *words;
            words = words + 1;
            *bytes = (s8) (word >> 0x18);
            bytes[1] = (s8) (word >> 0x10);
            bytes[2] = (s8) (word >> 8);
            fourthByte = bytes + 3;
            bytes = bytes + 4;
            *fourthByte = (s8) word;
            wordIndex = wordIndex + 1;
        } while (wordIndex < byteCount >> 2);
    }
}
