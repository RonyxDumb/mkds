/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MATHi_CRC32InitTableRev GenerateProfileInfoCrcLookupTable
#include "nitro/types.h"
#include "MATH_crc.h"
#include "code32.h"

void MATHi_CRC32InitTableRev(struct MATHCRC32Table *table, u32 poly) {
    u32 r, i, j;
    u32 *t = table->table;

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
        t[i] = r;
    }
}
