/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MATHi_CRC16UpdateRev func_020206d8
#define MATH_CalcCRC16 func_020205e8
#include "nitro/types.h"
#include "MATH_crc.h"
#include "code32.h"
extern void MATHi_CRC16UpdateRev(const struct MATHCRC16Table *table, MATHCRC16Context *context, const void *input, u32 length);
u16 MATH_CalcCRC16(const struct MATHCRC16Table *table, const void *data, u32 dataLength) {
    MATHCRC16Context ctx = 0;
    MATHi_CRC16UpdateRev(table, &ctx, data, dataLength);
    return ctx;
}
