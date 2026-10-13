/* Decompiled C draft; module arm9; ROM address 02022040. No matching claim. */
#include "types.h"
#include "deps/02022040_func_02022040.h"

void func_02022040(int *param_1,undefined4 param_2,uint param_3)

{
  ushort *puVar1;
  uint uVar2;
  uint uVar4;
  ushort *puVar5;
  uint uVar3;
  
  uVar3 = (uint)(param_1 + 4) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (0 < (int)uVar3) {
    param_3 = 1;
  }
  uVar2 = (uint)(param_1 + 1) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  if ((int)uVar3 < 1) {
    param_3 = 0;
  }
  if (param_3 == (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20)) {
    uVar3 = (uint)(param_1 + 6) & 3;
    uVar2 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
    puVar5 = (ushort *)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
    puVar1 = puVar5 + 6;
    uVar3 = (uint)puVar1 & 3;
    uVar2 = *(uint *)((uint)puVar1 & 0xfffffffc);
    *param_1 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + (uint)*puVar5 * 8 + -8;
  }
  else {
    uVar3 = (uint)(param_1 + 6) & 3;
    uVar2 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
    uVar4 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    uVar3 = uVar4 + 0xc;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    *param_1 = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + (uint)*(ushort *)(uVar4 + 2) * 8;
  }
  param_1[3] = 0;
  return;
}

