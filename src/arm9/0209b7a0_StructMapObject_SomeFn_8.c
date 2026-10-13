/* Decompiled C draft; module arm9; ROM address 0209b7a0. No matching claim. */
#include "types.h"
#include "deps/0209b7a0_StructMapObject_SomeFn_8.h"

void StructMapObject_SomeFn_8(undefined4 *param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar3;
  uint uVar4;
  char cVar5;
  uint uVar2;
  
  uVar2 = (uint)(param_1 + 3) & 3;
  uVar1 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 != 0) {
    if ((param_2 == 0) && (param_3 == 0)) {
      cVar5 = '\0';
    }
    else {
      cVar5 = '\x01';
    }
    if (cVar5 == *(char *)((*(uint *)(uRam0209b8a8 & 0xfffffffc) >> (uRam0209b8a8 & 3) * 8 |
                           *(uint *)(uRam0209b8a8 & 0xfffffffc) << (uRam0209b8a8 & 3) * -8 + 0x20) +
                          0x57)) {
      uVar1 = uVar2 + 0x14 & 3;
      uVar4 = *(uint *)(uVar2 + 0x14 & 0xfffffffc);
      *(uint *)(uVar2 + 0x14) = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20 | 0x80;
      uVar2 = (uint)(param_1 + 3) & 3;
      uVar1 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
      uVar4 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
      uVar2 = uVar4 + 0x14;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      *(uint *)(uVar4 + 0x14) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xffffffbf;
    }
    else {
      uVar1 = uVar2 + 0x14 & 3;
      uVar4 = *(uint *)(uVar2 + 0x14 & 0xfffffffc);
      *(uint *)(uVar2 + 0x14) = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 0xffffff7f;
      uVar2 = (uint)(param_1 + 3) & 3;
      uVar1 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
      uVar4 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
      uVar2 = uVar4 + 0x14;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      *(uint *)(uVar4 + 0x14) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 0x40;
    }
  }
  uVar2 = (uint)(param_1 + 4) & 3;
  uVar1 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 != 0) {
    if ((param_2 == 0) && (param_3 == 0)) {
      cVar5 = '\0';
    }
    else {
      cVar5 = '\x01';
    }
    if (cVar5 == *(char *)((*(uint *)(uRam0209b8a8 & 0xfffffffc) >> (uRam0209b8a8 & 3) * 8 |
                           *(uint *)(uRam0209b8a8 & 0xfffffffc) << (uRam0209b8a8 & 3) * -8 + 0x20) +
                          0x57)) {
      Model_SetCullMode(uVar2,2);
    }
    else {
      Model_SetCullMode(uVar2,1);
    }
  }
  if (param_2 == 0) {
    uVar3 = 0x1000;
  }
  else {
    uVar3 = 0xfffff000;
  }
  *param_1 = uVar3;
  if (param_3 == 0) {
    uVar3 = 0x1000;
  }
  else {
    uVar3 = 0xfffff000;
  }
  param_1[1] = uVar3;
  return;
}

