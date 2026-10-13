/* ARM instruction reconstruction; differential tests are local only.
 * No byte-exact matching or whole-game correctness claim. */
#include "race_memory.h"

uint32_t GetCurrentLapCount(void)
{
    uint32_t state = MKDS_READ32(0x021759C0u);
    if (MKDS_READ32(state + 8u) == 2u) return 1u;
    int32_t laps = (int8_t)MKDS_READ8(state + 0x64u);
    if (laps > 0) return (uint16_t)laps;
    uint32_t owner = MKDS_READ32(0x02175620u);
    uint32_t settings = MKDS_READ32(owner + 0x18u);
    return MKDS_READ16(settings + 2u);
}
