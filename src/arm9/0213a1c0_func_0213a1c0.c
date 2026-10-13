/* Decompiled C draft; module arm9; ROM address 0213a1c0. No matching claim. */
#include "types.h"
#include "deps/0213a1c0_func_0213a1c0.h"

void func_0213a1c0(uint *param_1,uint param_2)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  
  do {
    puVar4 = param_1;
    param_1 = (uint *)((int)puVar4 + 1);
  } while (((*(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
            *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20) & 0xff) != 0);
  do {
    uVar3 = (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
            *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) & 0xff |
            (*(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
            *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20) & 0xffffff00;
    uVar1 = (4 - ((uint)puVar4 & 3)) * 8 & 0x1f;
    *puVar4 = uVar3 >> uVar1 | uVar3 << 0x20 - uVar1;
    param_2 = param_2 + 1;
    puVar2 = (uint *)((uint)puVar4 & 0xfffffffc);
    uVar1 = (uint)puVar4 & 3;
    puVar4 = (uint *)((int)puVar4 + 1);
  } while (((*puVar2 >> uVar1 * 8 | *puVar2 << uVar1 * -8 + 0x20) & 0xff) != 0);
  return;
}

