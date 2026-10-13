/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MATHi_CRC8Update Friend_ComputeCrcImpl
#include "nitro/types.h"
#include "MATH_crc.h"
#include "code32.h"

void MATHi_CRC8Update(const struct MATHCRC8Table *table, MATHCRC8Context *context, const void *input, u32 length) {
    u32 r, i;
    const u8* t = table->table;
    u8* data = (u8*)input;

    r = *context;
    for (i = 0; i < length; i++) {
        r = t[(r ^ *data) & 0xff];
        data++;
    }
    *context = (MATHCRC8Context)r;
}
