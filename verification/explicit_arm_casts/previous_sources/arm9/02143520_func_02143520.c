/* Decompiled C draft; module arm9; ROM address 02143520. No matching claim. */
#include "types.h"
#include "deps/02143520_func_02143520.h"

int func_02143520(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = Wm_GetGlobal();
  iVar3 = Wm_CheckInitialized();
  if (iVar3 != 0) {
    return iVar3;
  }
  if (param_1 != 0) {
    uVar1 = iVar2 + 4U & 3;
    uVar4 = *(uint *)(iVar2 + 4U & 0xfffffffc);
    DC_InvalidateRangeNoClean(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20,uRam02143588);
    uVar1 = iVar2 + 4U & 3;
    uVar4 = *(uint *)(iVar2 + 4U & 0xfffffffc);
    MIi_CpuCopyFast(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20,param_1,uRam02143588);
    return 0;
  }
  return 6;
}

