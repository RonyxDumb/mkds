/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MATHi_CRC32UpdateRev ComputeProfileInfoCrcImpl
#define MATH_CalcCRC32 ComputeProfileInfoCrc
#include "nitro/types.h"
#include "MATH_crc.h"
#include "code32.h"
extern void MATHi_CRC32UpdateRev(const struct MATHCRC32Table *table, MATHCRC32Context *context, const void *input, u32 length);
u32 MATH_CalcCRC32(const struct MATHCRC32Table *table, const void *data, u32 dataLength) {
    MATHCRC32Context ctx = (MATHCRC32Context)(~0);
    MATHi_CRC32UpdateRev(table, &ctx, data, dataLength);
    return ~ctx;
}
