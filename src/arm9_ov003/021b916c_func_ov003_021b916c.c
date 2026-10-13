/* Decompiled C draft; module arm9_ov003; ROM address 021b916c. No matching claim. */
#include "types.h"
#include "deps/021b916c_func_ov003_021b916c.h"

void func_ov003_021b916c(int param_1,int param_2,undefined4 param_3)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < param_1) {
    do {
      func_ov003_021b7d90(param_2,param_3,6);
      uVar1 = func_ov003_021b7bb4();
      *(undefined2 *)(param_2 + 6) = uVar1;
      uVar1 = func_ov003_021b7c94(*(undefined2 *)(param_2 + 6));
      *(undefined2 *)(param_2 + 6) = uVar1;
      param_2 = param_2 + 8;
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_1);
  }
  return;
}

