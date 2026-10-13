/* Decompiled C draft; module arm9; ROM address 0212d5f8. No matching claim. */
#include "types.h"
#include "deps/0212d5f8_Sound_ReadSdatFromMemory.h"

void Sound_ReadSdatFromMemory(int param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar3;
  
  Mem_CpuCopy32((undefined4 *)(uintptr_t)(param_2),(undefined4 *)(uintptr_t)(param_1),0x30);
  uVar3 = param_1 + 0x18U & 3;
  uVar2 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar2 = 0;
  if (uVar3 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = param_2 + uVar3;
  }
  *(int *)(param_1 + 0x8c) = iVar4;
  uVar3 = param_1 + 0x20U & 3;
  uVar5 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar3 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  if (uVar3 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = param_2 + uVar3;
  }
  *(int *)(param_1 + 0x84) = iVar4;
  uVar3 = param_1 + 0x10U & 3;
  uVar5 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  uVar3 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  if (uVar3 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = param_2 + uVar3;
  }
  *(int *)(param_1 + 0x88) = iVar4;
  uVar3 = param_1 + 0x84U & 3;
  uVar5 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
  uVar7 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  uVar3 = uVar7 + 8 & 3;
  uVar5 = *(uint *)(uVar7 + 8 & 0xfffffffc);
  if (uVar5 >> uVar3 * 8 != 0 || uVar5 << uVar3 * -8 + 0x20 != 0) {
    iVar4 = 0;
    do {
      uVar3 = uVar7 + 0xc + iVar4;
      uVar5 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      uVar3 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
      if (uVar3 == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = param_2 + uVar3;
      }
      *(int *)(uVar7 + 0xc + iVar4 + 8) = iVar6;
      uVar3 = param_1 + 0x84U & 3;
      uVar5 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
      uVar7 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
      uVar2 = uVar2 + 1;
      uVar3 = uVar7 + 8 & 3;
      uVar5 = *(uint *)(uVar7 + 8 & 0xfffffffc);
      iVar4 = iVar4 + 0x10;
    } while (uVar2 < (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20));
  }
  piVar1 = piRam0212d6c0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *piVar1 = param_1;
  return;
}

