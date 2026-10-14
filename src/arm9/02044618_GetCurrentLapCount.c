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
uint32_t GetCurrentLapCount(void)
{
 uint32_t result=1;
 uint32_t state=READ32(0x021759C0u);
 if(READ32(state+8u)!=2u) {
  int32_t laps=(int8_t)READ8(state+0x64u);
  if(laps<=0) {
   uint32_t owner=READ32(0x02175620u);
   uint32_t settings=READ32(owner+0x18u);
   result=READ16(settings+2u);
  } else result=(uint16_t)laps;
 }
 return result;
}
