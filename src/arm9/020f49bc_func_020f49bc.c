/* Decompiled C draft; module arm9; ROM address 020f49bc. No matching claim. */
#include "types.h"
#include "deps/020f49bc_func_020f49bc.h"

void func_020f49bc(undefined4 *param_1)

{
  uint uVar1;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  code *pcVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar2;
  
  uVar2 = (uint)(param_1 + 8) & 3;
  uVar1 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if ((int)uVar2 < 1) {
    return;
  }
  param_1[8] = uVar2 - 1;
  uVar2 = (uint)(param_1 + 8) & 3;
  uVar1 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (((uVar2 != 7) && (uVar2 != 5)) && (uVar2 != 3)) {
    return;
  }
  uVar2 = (uint)(param_1 + 1) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  uVar1 = (uint)(param_1 + 2) & 3;
  uVar3 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  uVar2 = (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) + 0x1fc;
  uVar4 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar10 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
  param_1[2] = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) - 1;
  uVar2 = (uint)(param_1 + 2) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  uVar1 = (uint)(param_1 + (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) + 5) & 3;
  uVar2 = *(uint *)((uint)(param_1 + (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) + 5) &
                   0xfffffffc);
  uVar4 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar2 = uVar4 + 0x44 & 3;
  uVar1 = *(uint *)(uVar4 + 0x44 & 0xfffffffc);
  func_020f0ea0((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) * 0x44 +
                (*(uint *)(uRam020f4b14 & 0xfffffffc) >> (uRam020f4b14 & 3) * 8 |
                *(uint *)(uRam020f4b14 & 0xfffffffc) << (uRam020f4b14 & 3) * -8 + 0x20),uVar4);
  uVar2 = (uint)(param_1 + 1) & 3;
  uVar1 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  func_020efd1c(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20,uVar4);
  VecFx32_AddScale1(uRam020f4b18,uVar10 + 0xa4,uVar4 + 0x5c,(int *)(uintptr_t)(uVar4 + 0x5c));
  uVar5 = *(undefined4 *)(uVar10 + 0x9c);
  uVar7 = *(undefined4 *)(uVar10 + 0xa0);
  *(undefined4 *)(uVar4 + 0x50) = *(undefined4 *)(uVar10 + 0x98);
  *(undefined4 *)(uVar4 + 0x54) = uVar5;
  *(undefined4 *)(uVar4 + 0x58) = uVar7;
  func_020f6630(uVar4,0,(undefined4 *)(uVar10 + 0x98),uVar10 + 0xa4);
  uVar2 = uVar4 + 0x44 & 3;
  uVar1 = *(uint *)(uVar4 + 0x44 & 0xfffffffc);
  uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) * 0xa8 +
          (*(uint *)(uRam020f4b1c & 0xfffffffc) >> (uRam020f4b1c & 3) * 8 |
          *(uint *)(uRam020f4b1c & 0xfffffffc) << (uRam020f4b1c & 3) * -8 + 0x20) + 0x38;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  pcVar6 = (code *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  if (pcVar6 != (code *)0x0) {
    (*pcVar6)(uVar4);
  }
  uVar2 = (uint)(param_1 + 2) & 3;
  uVar1 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  if (uVar1 >> uVar2 * 8 == 0 && uVar1 << uVar2 * -8 + 0x20 == 0) {
    *param_1 = 0x13;
    param_1[2] = 0;
    param_1[8] = 0;
    param_1[3] = 0;
    *(undefined2 *)(param_1 + 4) = 0;
    *(undefined2 *)((int)param_1 + 0x12) = 0;
    iVar8 = 0;
    do {
      iVar9 = iVar8 + 1;
      param_1[iVar8 + 5] = 0;
      iVar8 = iVar9;
    } while (iVar9 < 3);
    return;
  }
  return;
}

