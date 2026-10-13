/* Decompiled C draft; module arm9; ROM address 020177b0. No matching claim. */
#include "types.h"
#include "deps/020177b0_Mem_ResizeExpHeap.h"

uint Mem_ResizeExpHeap(int param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  undefined4 uStack_28;
  
  uVar6 = param_2 - 0xcU & 3;
  uVar7 = *(uint *)(param_2 - 0xcU & 0xfffffffc);
  uVar7 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  uVar9 = param_3 + 3U & 0xfffffffc;
  uVar6 = param_1 + 0x24;
  if (uVar9 == uVar7) {
    return uVar9;
  }
  if (uVar7 < uVar9) {
    for (uVar8 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                 *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
        (uVar8 != 0 && (uVar8 != uVar7 + param_2));
        uVar8 = uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) {
      uVar5 = uVar8 + 0xc & 3;
      uVar8 = *(uint *)(uVar8 + 0xc & 0xfffffffc);
    }
    if ((uVar8 == 0) ||
       (uVar5 = uVar8 + 4 & 3, uVar1 = *(uint *)(uVar8 + 4 & 0xfffffffc),
       uVar7 + 0x10 + (uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) < uVar9)) {
      return 0;
    }
    Mem_GetMemoryBlockRegion(&iStack_38,uVar8);
    uVar2 = Mem_ExpHeapMemoryBlockList_Remove((uint *)(uintptr_t)(uVar6),uVar8);
    iVar4 = iStack_38;
    iStack_38 = uVar9 + param_2;
    if ((uint)(iStack_34 - iStack_38) < 0x10) {
      iStack_38 = iStack_34;
    }
    *(int *)(param_2 + -0xc) = iStack_38 - param_2;
    if (0xf < (uint)(iStack_34 - iStack_38)) {
      uVar3 = Mem_Exp_InitializeMemoryBlock((uint)(uintptr_t)(&iStack_38),uRam02017934);
      Mem_ExpHeapMemoryBlockList_Insert((int *)(uintptr_t)(uVar6),uVar3,uVar2);
    }
    uVar6 = param_1 + 0x20U & 3;
    uVar7 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    if (((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & 1) != 0) {
      uStack_28 = 0;
      MIi_CpuClear32(0,(undefined4 *)(uintptr_t)(iVar4),iStack_38 - iVar4);
    }
  }
  else {
    iStack_30 = uVar9 + param_2;
    uVar8 = param_2 - 0xcU & 3;
    uVar5 = *(uint *)(param_2 - 0xcU & 0xfffffffc);
    iStack_2c = (uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20) + param_2;
    *(uint *)(param_2 + -0xc) = uVar9;
    iVar4 = Mem_Exp_CoalesceFreedRegion(uVar6,(uint)(uintptr_t)(&iStack_30));
    if (iVar4 == 0) {
      *(uint *)(param_2 + -0xc) = uVar7;
    }
  }
  uVar6 = param_2 - 0xcU & 3;
  uVar7 = *(uint *)(param_2 - 0xcU & 0xfffffffc);
  return uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
}

