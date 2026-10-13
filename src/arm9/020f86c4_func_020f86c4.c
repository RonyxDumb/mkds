/* Decompiled C draft; module arm9; ROM address 020f86c4. No matching claim. */
#include "types.h"
#include "deps/020f86c4_func_020f86c4.h"

void func_020f86c4(undefined4 *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar3;
  
  uVar6 = (uint)(param_1 + 6) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
  puVar3 = (undefined4 *)(uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20);
  uVar6 = (uint)(puVar3 + 5) & 3;
  uVar2 = *(uint *)((uint)(puVar3 + 5) & 0xfffffffc);
  if ((uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) != 0x13) {
    puVar3[5] = 0x13;
  }
  if (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 == 0 &&
      *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20 == 0) {
    uVar6 = (uint)(puVar3 + 0xc) & 3;
    uVar2 = *(uint *)((uint)(puVar3 + 0xc) & 0xfffffffc);
    if ((uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) != 0x13) {
      func_020f45f0(puVar3 + 0xc,1);
    }
  }
  else {
    uVar6 = (uint)(puVar3 + 8) & 3;
    uVar2 = *(uint *)((uint)(puVar3 + 8) & 0xfffffffc);
    if (uVar2 >> uVar6 * 8 == 0 && uVar2 << uVar6 * -8 + 0x20 == 0) {
      uVar6 = (uint)(puVar3 + 4) & 3;
      uVar2 = *(uint *)((uint)(puVar3 + 4) & 0xfffffffc);
      iVar7 = (uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) * 0x1c +
              (*(uint *)(uRam020f87a0 & 0xfffffffc) >> (uRam020f87a0 & 3) * 8 |
              *(uint *)(uRam020f87a0 & 0xfffffffc) << (uRam020f87a0 & 3) * -8 + 0x20);
      uVar6 = iVar7 + 8;
      uVar2 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      iVar5 = (uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) * 0x44 +
              (*(uint *)(uRam020f87a4 & 0xfffffffc) >> (uRam020f87a4 & 3) * 8 |
              *(uint *)(uRam020f87a4 & 0xfffffffc) << (uRam020f87a4 & 3) * -8 + 0x20);
      uVar6 = iVar5 + 0x1c;
      uVar2 = uVar6 & 3;
      uVar4 = *(uint *)(uVar6 & 0xfffffffc);
      uVar6 = iVar7 + 0xc;
      uVar1 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      *(uint *)(iVar5 + 0x1c) =
           (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) -
           (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20);
    }
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[3] = 0x13;
    puVar3[4] = 0x13;
    puVar3[5] = 0x13;
    puVar3[8] = 0;
  }
  *param_1 = 1;
  param_1[1] = 0;
  param_1[2] = 0x85;
  param_1[3] = 0x13;
  param_1[5] = 0x13;
  param_1[4] = 0x13;
  param_1[8] = 1;
  return;
}

