/* Decompiled C draft; module arm9; ROM address 0214bafc. No matching claim. */
#include "types.h"
#include "deps/0214bafc_CopyBgData_Bg0_Top.h"

void CopyBgData_Bg0_Top(undefined4 param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = GetVramBg0BaseOffset_Top();
  uVar2 = *(uint *)(uRam0214bb60 & 0xfffffffc) >> (uRam0214bb60 & 3) * 8 |
          *(uint *)(uRam0214bb60 & 0xfffffffc) << (uRam0214bb60 & 3) * -8 + 0x20;
  if ((uVar2 != 0xffffffff) && (0x30 < param_3)) {
    MI_DmaCopy32(uVar2,param_1,iVar1 + param_2,param_3);
    return;
  }
  Mem_CpuCopy32((undefined4 *)(uintptr_t)(param_1),(undefined4 *)(uintptr_t)(iVar1 + param_2),param_3);
  return;
}

