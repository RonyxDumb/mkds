#include "Main/Graphics/nibbles_join.h"

#pragma thumb on

#include "Main/Graphics/nibbles_join.h"

#pragma thumb on

// The reverse of SplitBytesIntoNibbles: joins pairs of 4-bit entries into bytes.
void JoinNibblesIntoBytes(const u8 *nibbles, u8 *bytes, int side) {
    int byteIndex;
    int byteCount = side * side / 2;
    for (byteIndex = 0; byteIndex < byteCount; byteIndex++) {
        bytes[byteIndex] = nibbles[byteIndex * 2] | (nibbles[byteIndex * 2 + 1] << 4);
    }
}

#pragma thumb off

#pragma thumb off
