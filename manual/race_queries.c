/* Semantic reconstruction from this ROM's ARM9 instructions.
 * NOT verified with mwccarm; NOT a matching-decomp claim.
 * Names are borrowed from the external mkds-decomp symbol map.
 * Absolute-address globals are intentional; this targets the original DS map.
 */
#include <stdint.h>
#define READ8(a) (*(const uint8_t *)(uintptr_t)(a))
#define READ16(a) (*(const uint16_t *)(uintptr_t)(a))
#define READ32(a) (*(const uint32_t *)(uintptr_t)(a))

/* ROM function 0x0203C8DC, 0x74 bytes including four pool words. */
uint32_t GetDriverPlace(uint32_t driver)
{
    uint32_t state = READ32(0x021759C0u);
    if (READ32(state + 8u) == 5u) {
        uint32_t mapping = READ32(0x0217AA18u);
        int32_t slot = (int8_t)READ8(mapping + (driver & 0xFFu));
        uint32_t base = READ32(0x0217AA14u);
        /* MLA wraps at 32 bits, including a negative signed slot. */
        uint32_t offset = (uint32_t)slot * 0x88u;
        return READ8(base + offset + 0x18Au) >> 1;
    }
    uint32_t base = READ32(0x0217561Cu);
    return READ16(base + driver * 0x8Cu + 0x50u) & 0xFu;
}

/* ROM function 0x02044618, 0x44 bytes including two pool words. */
uint32_t GetCurrentLapCount(void)
{
    uint32_t state = READ32(0x021759C0u);
    if (READ32(state + 8u) == 2u) return 1u;
    int32_t laps = (int8_t)READ8(state + 0x64u);
    if (laps > 0) return (uint16_t)laps;
    uint32_t owner = READ32(0x02175620u);
    uint32_t settings = READ32(owner + 0x18u);
    return READ16(settings + 2u);
}
