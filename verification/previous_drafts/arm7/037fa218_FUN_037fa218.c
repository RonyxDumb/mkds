/* Decompiled C draft; module arm7; ROM address 037fa218. No matching claim. */
#include "types.h"
#include "deps/037fa218_FUN_037fa218.h"

uint FUN_037fa218(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  uVar2 = param_2 + 4 & 3;
  uVar3 = *(uint *)(param_2 + 4 & 0xfffffffc);
  puVar4 = (uint *)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  if (puVar4 != (uint *)0x0) {
    *puVar4 = *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
              *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
  }
  uVar2 = *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
          *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
  if (uVar2 == 0) {
    uVar2 = param_2 + 4 & 3;
    uVar3 = *(uint *)(param_2 + 4 & 0xfffffffc);
    param_1 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  }
  else {
    uVar3 = param_2 + 4 & 3;
    uVar1 = *(uint *)(param_2 + 4 & 0xfffffffc);
    *(uint *)(uVar2 + 4) = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20;
  }
  return param_1;
}

