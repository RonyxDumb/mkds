/* Decompiled C draft; module arm9; ROM address 0205ad44. No matching claim. */
#include "types.h"
#include "deps/0205ad44_func_0205ad44.h"

undefined4 func_0205ad44(void)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    if (*(char *)(uVar1 * 0xc +
                  (*(uint *)(uRam0205ad84 & 0xfffffffc) >> (uRam0205ad84 & 3) * 8 |
                  *(uint *)(uRam0205ad84 & 0xfffffffc) << (uRam0205ad84 & 3) * -8 + 0x20) + 0x32c)
        == '\0') {
      return 1;
    }
    uVar1 = uVar1 + 1 & 0xffff;
  } while (uVar1 < 0x10);
  return 0;
}

