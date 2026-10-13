/* Decompiled C draft; module arm9; ROM address 020d4f94. No matching claim. */
#include "types.h"
#include "deps/020d4f94_func_020d4f94.h"

void func_020d4f94(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 auStack_38 [24];
  int local_20;
  int local_1c;
  int local_18;
  uint uVar7;
  
  func_02146d0c((undefined4 *)(uintptr_t)(param_1),(undefined4 *)(void *)(auStack_38));
  MTX_MultVec33(param_1 + 0x24,(uint)(uintptr_t)(auStack_38),(uint *)(uintptr_t)(uRam020d508c));
  iVar1 = iRam020d5090;
  uVar5 = iRam020d5090 + 0xcU & 3;
  uVar4 = *(uint *)(iRam020d5090 + 0xcU & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = iRam020d5090 + 8U & 3;
  uVar6 = *(uint *)(iRam020d5090 + 8U & 0xfffffffc);
  uVar7 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
  uVar5 = iRam020d5090 + 0x10U & 3;
  uVar6 = *(uint *)(iRam020d5090 + 0x10U & 0xfffffffc);
  uVar5 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
  *(int *)(iRam020d5090 + 0x18) = -local_1c;
  *(int *)(iVar1 + 0x14) = -local_20;
  *(int *)(iVar1 + 0x1c) = -local_18;
  *(uint *)(iVar1 + 0x10) = -uVar5;
  uVar3 = uRam020d5098;
  uVar2 = uRam020d5094;
  *(uint *)(iVar1 + 8) = -uVar7;
  *(uint *)(iVar1 + 0xc) = -uVar4;
  *(uint *)(iVar1 + 8) = uVar7 * -0x10;
  *(uint *)(iVar1 + 0xc) = uVar4 * -0x10;
  *(uint *)(iVar1 + 0x10) = uVar5 * -0x10;
  MTX_MultVec33(uVar2,(uint)(uintptr_t)(auStack_38),(uint *)(uintptr_t)(uVar3));
  MTX_MultVec33(uRam020d509c,(uint)(uintptr_t)(auStack_38),(uint *)(uintptr_t)(uRam020d50a0));
  MTX_MultVec33(uRam020d50a4,(uint)(uintptr_t)(auStack_38),(uint *)(uintptr_t)(uRam020d50a8));
  MTX_MultVec33(uRam020d50ac,auStack_38);
  uVar5 = iVar1 + 0x50U & 3;
  uVar4 = *(uint *)(iVar1 + 0x50U & 0xfffffffc);
  if (uVar4 >> uVar5 * 8 == 0 && uVar4 << uVar5 * -8 + 0x20 == 0) {
    *(undefined4 *)(iVar1 + 0x54) = 0;
  }
  else {
    *(undefined4 *)(iVar1 + 0x54) = 1;
    *(undefined4 *)(iVar1 + 0x50) = 0;
  }
  return;
}

