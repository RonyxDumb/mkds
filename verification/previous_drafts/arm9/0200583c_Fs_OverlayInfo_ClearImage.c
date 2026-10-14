/* Decompiled C draft; module arm9; ROM address 0200583c. No matching claim. */
#include "types.h"
#include "deps/0200583c_Fs_OverlayInfo_ClearImage.h"

void Fs_OverlayInfo_ClearImage(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar6;
  uint uVar5;
  
  uVar1 = param_1 + 8U & 3;
  uVar4 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar5 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0xcU & 3;
  uVar2 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar4 = param_1 + 4U & 3;
  uVar6 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar4 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
  iVar3 = uVar5 + (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  IC_InvalidateRangeNoClean(uVar4,iVar3);
  DC_InvalidateRangeNoClean(uVar4,iVar3);
  Mem_CpuFill8((uint *)(uintptr_t)(uVar4 + uVar5),0,iVar3 - uVar5);
  return;
}

