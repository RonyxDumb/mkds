/* Decompiled C draft; module arm9; ROM address 0207f630. No matching claim. */
#include "types.h"
#include "deps/0207f630_func_0207f630.h"

void func_0207f630(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar3;
  
  uVar2 = (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
          *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) + 0x18;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  puVar3 = (undefined4 *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  uVar4 = puVar3[1];
  uVar5 = puVar3[2];
  *(undefined4 *)(param_1 + 0x44) = *puVar3;
  *(undefined4 *)(param_1 + 0x48) = uVar4;
  *(undefined4 *)(param_1 + 0x4c) = uVar5;
  uVar4 = puRam0207f664[1];
  uVar5 = puRam0207f664[2];
  *(undefined4 *)(param_1 + 0x60) = *puRam0207f664;
  *(undefined4 *)(param_1 + 100) = uVar4;
  *(undefined4 *)(param_1 + 0x68) = uVar5;
  *(undefined4 *)(param_1 + 0x74) = 0;
  return;
}

