/* Decompiled C draft; module arm9; ROM address 020e6b58. No matching claim. */
#include "types.h"
#include "deps/020e6b58_func_020e6b58.h"

uint func_020e6b58(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = uRam020e6b90;
  uVar4 = *(uint *)(uRam020e6b90 & 0xfffffffc) >> (uRam020e6b90 & 3) * 8 |
          *(uint *)(uRam020e6b90 & 0xfffffffc) << (uRam020e6b90 & 3) * -8 + 0x20;
  *(int *)(uVar4 + 0x24) =
       (int)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) >> 4;
  uVar1 = param_1 + 4 & 3;
  uVar3 = *(uint *)(param_1 + 4 & 0xfffffffc);
  *(int *)(uVar4 + 0x28) = (int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = param_1 + 8 & 3;
  uVar3 = *(uint *)(param_1 + 8 & 0xfffffffc);
  *(int *)(uVar4 + 0x2c) = (int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

