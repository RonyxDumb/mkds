/* Decompiled C draft; module arm9; ROM address 0214b824. No matching claim. */
#include "types.h"
#include "deps/0214b824_CopyBgData_Bg3_Bottom.h"

void CopyBgData_Bg3_Bottom(undefined4 param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = GetVramBg3BaseOffset_Bottom();
  uVar2 = *(uint *)(uRam0214b888 & 0xfffffffc) >> (uRam0214b888 & 3) * 8 |
          *(uint *)(uRam0214b888 & 0xfffffffc) << (uRam0214b888 & 3) * -8 + 0x20;
  if ((uVar2 != 0xffffffff) && (0x30 < param_3)) {
    MI_DmaCopy32(uVar2,param_1,iVar1 + param_2,param_3);
    return;
  }
  Mem_CpuCopy32(param_1,iVar1 + param_2,param_3);
  return;
}

