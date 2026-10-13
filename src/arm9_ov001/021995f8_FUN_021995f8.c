/* Decompiled C draft; module arm9_ov001; ROM address 021995f8. No matching claim. */
#include "types.h"
#include "deps/021995f8_FUN_021995f8.h"

void FUN_021995f8(void)

{
  FUN_02199374();
  FUN_02199420();
  *DAT_02199630 =
       *DAT_02199630 & DAT_02199638 | ((*DAT_02199630 & DAT_02199634) >> 8 & 0xfffffffd) << 8;
  func_0x0212b91c();
  *DAT_0219963c = 0;
  return;
}

