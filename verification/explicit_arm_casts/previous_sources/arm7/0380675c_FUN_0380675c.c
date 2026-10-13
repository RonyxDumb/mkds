/* Decompiled C draft; module arm7; ROM address 0380675c. No matching claim. */
#include "types.h"
#include "deps/0380675c_FUN_0380675c.h"

void FUN_0380675c(void)

{
  uint uVar1;
  
  uVar1 = *(uint *)(DAT_03806790 & 0xfffffffc) >> (DAT_03806790 & 3) * 8 |
          *(uint *)(DAT_03806790 & 0xfffffffc) << (DAT_03806790 & 3) * -8 + 0x20;
  if (uVar1 != 0) {
    FUN_037fb2c4(uVar1,0x6000000,
                 *(uint *)(DAT_03806794 & 0xfffffffc) >> (DAT_03806794 & 3) * 8 |
                 *(uint *)(DAT_03806794 & 0xfffffffc) << (DAT_03806794 & 3) * -8 + 0x20);
  }
  return;
}

