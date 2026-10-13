/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MATHi_CRC8Update Friend_ComputeCrcImpl
#define MATH_CalcCRC8 ComputeFriendCrc
#include "nitro/types.h"
#include "MATH_crc.h"
#include "code32.h"
extern void MATHi_CRC8Update(const struct MATHCRC8Table *table, MATHCRC8Context *context, const void *input, u32 length);
u8 MATH_CalcCRC8(const struct MATHCRC8Table *table, const void *data, u32 dataLength) {
    MATHCRC8Context ctx = 0;
    MATHi_CRC8Update(table, &ctx, data, dataLength);
    return ctx;
}
