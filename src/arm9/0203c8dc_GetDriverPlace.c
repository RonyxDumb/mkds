/* Reconstructed from EUR ARM instructions; exact complete local bytes verified.
 * Whole-ROM linking and global ABI remain unverified. */
typedef unsigned int uint32_t; typedef signed int int32_t; typedef unsigned char uint8_t; typedef signed char int8_t; typedef unsigned short uint16_t;
#ifndef READ8
#define READ8(a) (*(const uint8_t *)(unsigned long)(a))
#endif
#ifndef READ16
#define READ16(a) (*(const uint16_t *)(unsigned long)(a))
#endif
#ifndef READ32
#define READ32(a) (*(const uint32_t *)(unsigned long)(a))
#endif

struct PackedPlace { unsigned char flags:1; unsigned char place:7; };
struct NormalPlace { unsigned short place:4; unsigned short flags:12; };
#ifndef READ_PACKED_PLACE
#define READ_PACKED_PLACE(a) (((const struct PackedPlace *)(unsigned long)(a))->place)
#endif
#ifndef READ_NORMAL_PLACE
#define READ_NORMAL_PLACE(a) (((const struct NormalPlace *)(unsigned long)(a))->place)
#endif
uint32_t GetDriverPlace(uint32_t driver)
{
    uint32_t state = READ32(0x021759C0u);
    if (READ32(state + 8u) == 5u) {
        uint32_t mapping = READ32(0x0217AA18u);
        int32_t slot = (int8_t)READ8(mapping + (driver & 0xFFu));
        uint32_t base = READ32(0x0217AA14u);
        /* MLA wraps at 32 bits, including a negative signed slot. */
        uint32_t offset = (uint32_t)slot * 0x88u;
        return READ_PACKED_PLACE(base + offset + 0x18Au);
    }
    uint32_t base = READ32(0x0217561Cu);
    return READ_NORMAL_PLACE(base + driver * 0x8Cu + 0x50u);
}
