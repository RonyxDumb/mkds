/* Decompiled C draft; module arm9_ov000; ROM address 0219eac8. No matching claim. */
#include "types.h"
#include "deps/0219eac8_FUN_0219eac8.h"

uint FUN_0219eac8(void)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    if (*(char *)(DAT_0219eaf0 + uVar1 * 0xc) == '\0') {
      return uVar1 + 100 & 0xff;
    }
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 0x9a);
  return 0;
}

