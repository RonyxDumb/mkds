/* Decompiled C draft; module arm9_ov003; ROM address 021b7ed0. No matching claim. */
#include "types.h"
#include "deps/021b7ed0_func_ov003_021b7ed0.h"

void func_ov003_021b7ed0(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = func_0x02133068(param_3,2);
  iVar2 = 0;
  if (0 < iVar1) {
    do {
      *(byte *)(param_2 + iVar1 + iVar2) =
           *(byte *)(param_2 + iVar1 + iVar2) ^ *(byte *)(param_1 + iVar2);
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  return;
}

