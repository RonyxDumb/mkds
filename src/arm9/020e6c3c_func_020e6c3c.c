/* Decompiled C draft; module arm9; ROM address 020e6c3c. No matching claim. */
#include "types.h"
#include "deps/020e6c3c_func_020e6c3c.h"

uint func_020e6c3c(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = uRam020e6cb8;
  uVar4 = *(uint *)(uRam020e6cb8 & 0xfffffffc) >> (uRam020e6cb8 & 3) * 8 |
          *(uint *)(uRam020e6cb8 & 0xfffffffc) << (uRam020e6cb8 & 3) * -8 + 0x20;
  *(int *)(uVar4 + 0xc) =
       (int)(param_2 *
            (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
            *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20)) >> 0xc;
  *(int *)((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
           *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10) = param_3 + 0x1000;
  uVar3 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
  uVar4 = uVar3 + 8;
  uVar2 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(int *)(uVar3 + 0x14) = (int)(param_2 * (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20)) >> 0xc
  ;
  uVar3 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
  *(int *)(uVar3 + 0x24) =
       (int)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) >> 4;
  uVar4 = param_1 + 4 & 3;
  uVar2 = *(uint *)(param_1 + 4 & 0xfffffffc);
  *(int *)(uVar3 + 0x28) = (int)(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) >> 4;
  uVar4 = param_1 + 8 & 3;
  uVar2 = *(uint *)(param_1 + 8 & 0xfffffffc);
  *(int *)(uVar3 + 0x2c) = (int)(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) >> 4;
  return *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
         *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
}

