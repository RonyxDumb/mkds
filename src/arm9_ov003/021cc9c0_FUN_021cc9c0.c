/* Decompiled C draft; module arm9_ov003; ROM address 021cc9c0. No matching claim. */
#include "types.h"
#include "deps/021cc9c0_FUN_021cc9c0.h"

void FUN_021cc9c0(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *DAT_021cc9f8 + 4 + param_2 * 2;
  iVar1 = 0;
  if (0 < param_4) {
    do {
      func_0x0214cffc(param_1,iVar2,param_3 << 1);
      iVar1 = iVar1 + 1;
      param_1 = param_1 + 0x40;
      iVar2 = iVar2 + 0x40;
    } while (iVar1 < param_4);
  }
  return;
}

