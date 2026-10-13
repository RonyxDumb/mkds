/* Decompiled C draft; module arm9; ROM address 020f47e4. No matching claim. */
#include "types.h"
#include "deps/020f47e4_func_020f47e4.h"

void func_020f47e4(int *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  iVar7 = param_2 * 0x1c;
  uVar5 = (*(uint *)(uRam020f487c & 0xfffffffc) >> (uRam020f487c & 3) * 8 |
          *(uint *)(uRam020f487c & 0xfffffffc) << (uRam020f487c & 3) * -8 + 0x20) + iVar7 + 0xc;
  uVar3 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *param_1 = param_2;
  param_1[2] = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  param_1[8] = 0;
  uVar5 = (uint)(param_1 + 1) & 3;
  uVar3 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  uVar5 = (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) + 0x1fc;
  uVar3 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  func_0206c14c(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20);
  uVar4 = uRam020f4880;
  uVar1 = uRam020f487c;
  uVar5 = (*(uint *)(uRam020f487c & 0xfffffffc) >> (uRam020f487c & 3) * 8 |
          *(uint *)(uRam020f487c & 0xfffffffc) << (uRam020f487c & 3) * -8 + 0x20) + iVar7 + 0x10;
  uVar3 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  param_1[3] = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  *(undefined2 *)(param_1 + 4) = 0;
  *(undefined2 *)((int)param_1 + 0x12) = 0;
  uVar5 = uVar1 & 3;
  uVar3 = *(uint *)(uVar1 & 0xfffffffc);
  uVar2 = uVar4 & 3;
  uVar6 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) + iVar7 + 8;
  uVar3 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar1 = (uint)(param_1 + 2) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  iVar7 = (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) * 0x44 +
          (uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20);
  uVar5 = iVar7 + 0x1c;
  uVar3 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *(uint *)(iVar7 + 0x1c) =
       (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) +
       (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  return;
}

