/* Decompiled C draft; module arm9; ROM address 0212f1ac. No matching claim. */
#include "types.h"
#include "deps/0212f1ac_func_0212f1ac.h"

void func_0212f1ac(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_3 >> 1 != 0) {
    do {
      iVar1 = uVar2 * 2;
      uVar2 = uVar2 + 1;
      *(short *)(param_1 + iVar1) =
           (short)((int)*(short *)(param_1 + iVar1) + (int)*(short *)(param_2 + iVar1) + 1 >> 1);
    } while (uVar2 < param_3 >> 1);
  }
  MIi_CpuCopyFast();
  return;
}

