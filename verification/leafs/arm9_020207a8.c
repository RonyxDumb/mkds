/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MATHi_CRC8InitTable GenerateFriendCrcLookupTable
#include "nitro/types.h"
#include "MATH_crc.h"
#include "code32.h"

void MATHi_CRC8InitTable(struct MATHCRC8Table *table, u8 poly) {
    u32 r, i, j;
    u8 *t = table->table;

    for (i = 0; i < 256; i++) {
        r = i;
        for (j = 0; j < 8; j++) {
            if (r & 0x80) {
                r = (r << 1) ^ poly;
            }
            else {
                r <<= 1;
            }
        }
        t[i] = (u8)r;
    }
}
