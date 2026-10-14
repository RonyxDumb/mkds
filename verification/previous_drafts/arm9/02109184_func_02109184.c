/* Decompiled C draft; module arm9; ROM address 02109184. No matching claim. */
#include "types.h"
#include "deps/02109184_func_02109184.h"

uint func_02109184(uint param_1)

{
  ushort *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  puVar2 = puRam02109204;
  uVar3 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  if (uVar3 == 0) {
    uVar3 = param_1 + 0x20 & 3;
    uVar4 = *(uint *)(param_1 + 0x20 & 0xfffffffc);
    uVar3 = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + 0xc;
    uVar4 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar3 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  }
  else {
    uVar3 = uVar3 + 0x40;
    uVar4 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar3 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  }
  *puRam02109200 = 0;
  *puVar2 = uVar3;
  uVar3 = param_1 + 4 & 3;
  uVar4 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar3 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  iVar5 = func_02073e4c(uVar3);
  *(int *)(param_1 + 8) = iVar5 >> 0xc;
  iVar5 = func_02073e04(uVar3);
  puVar1 = puRam02109200;
  *(int *)(param_1 + 0xc) = iVar5 >> 0xc;
  do {
  } while ((*puVar1 & 0x8000) != 0);
  return *(uint *)(uRam02109208 & 0xfffffffc) >> (uRam02109208 & 3) * 8 |
         *(uint *)(uRam02109208 & 0xfffffffc) << (uRam02109208 & 3) * -8 + 0x20;
}

