/* ARM instruction reconstruction; differential tests are local only.
 * No byte-exact matching or whole-game correctness claim. */
#include "race_memory.h"

uint32_t GetDriverPlace(uint32_t driver)
{
    uint32_t state = MKDS_READ32(0x021759C0u);
    if (MKDS_READ32(state + 8u) == 5u) {
        uint32_t mapping = MKDS_READ32(0x0217AA18u);
        int32_t slot = (int8_t)MKDS_READ8(mapping + (driver & 0xFFu));
        uint32_t base = MKDS_READ32(0x0217AA14u);
        /* MLA wraps at 32 bits, including a negative signed slot. */
        uint32_t offset = (uint32_t)slot * 0x88u;
        return MKDS_READ8(base + offset + 0x18Au) >> 1;
    }
    uint32_t base = MKDS_READ32(0x0217561Cu);
    return MKDS_READ16(base + driver * 0x8Cu + 0x50u) & 0xFu;
}
