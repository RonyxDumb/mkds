/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MATHi_CRC16InitTableRev SomeHashing
#include "nitro/types.h"
#include "MATH_crc.h"
#include "code32.h"

void MATHi_CRC16InitTableRev(struct MATHCRC16Table *table, u16 poly) {
    u32 r, i, j;
    u16 *t = table->table;

    for (i = 0; i < 256; i++) {
        r = i;
        for (j = 0; j < 8; j++) {
            if (r & 1) {
                r = (r >> 1) ^ poly;
            }
            else {
                r >>= 1;
            }
        }
        t[i] = (u16)r;
    }
}
