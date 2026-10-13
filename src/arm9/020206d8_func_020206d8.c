/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MATHi_CRC16UpdateRev func_020206d8
#include "nitro/types.h"
#include "MATH_crc.h"
#include "code32.h"

void MATHi_CRC16UpdateRev(const struct MATHCRC16Table *table, MATHCRC16Context *context, const void *input, u32 length) {
    u32 r, i;
    const u16* t = table->table;
    u8* data = (u8*)input;

    r = *context;
    for (i = 0; i < length; i++) {
        r = (r >> 8) ^ t[(r ^ *data) & 0xff];
        data++;
    }
    *context = (MATHCRC16Context)r;
}
