/* Decompiled C draft; module arm9; ROM address 020d88fc. No matching claim. */
#include "types.h"
#include "deps/020d88fc_func_020d88fc.h"

int func_020d88fc(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar1 = param_1 + 0xc & 3;
  uVar3 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  uVar2 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  return (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * 0x54 +
         (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) + 0x48;
}

