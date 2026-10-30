#include "00/code_021ac3a8.h"

u32 func_ov000_021ac3a8(u32 a, u32 *b) {
    u32 c;
    c = b[a] ^ (b[(a + 2) & 0xf] ^ (b[(a + 13) & 0xf] ^ b[a ^ 8]));
    b[a] = (c << 1) | (c >> 31);
    return b[a];
}
