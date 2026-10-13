/* Decompiled C draft; module arm7; ROM address 0600b3e8. No matching claim. */
#include "types.h"
#include "deps/0600b3e8_FUN_0600b3e8.h"

undefined4 FUN_0600b3e8(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = DAT_0600b440;
  if ((param_1 < 10) || (1000 < param_1)) {
    uVar2 = 5;
  }
  else {
    *(short *)((*(uint *)(DAT_0600b440 & 0xfffffffc) >> (DAT_0600b440 & 3) * 8 |
               *(uint *)(DAT_0600b440 & 0xfffffffc) << (DAT_0600b440 & 3) * -8 + 0x20) + 0x3b2) =
         (short)param_1;
    *DAT_0600b444 = (short)param_1;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    FUN_0600ac7c(*(undefined2 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x338));
    uVar2 = 0;
  }
  return uVar2;
}

