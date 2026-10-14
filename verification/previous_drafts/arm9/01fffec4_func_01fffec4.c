/* Decompiled C draft; module arm9; ROM address 01fffec4. No matching claim. */
#include "types.h"
#include "deps/01fffec4_func_01fffec4.h"

void func_01fffec4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  Os_DisableIrq();
  iVar1 = iRam01ffff30;
  *(undefined4 *)(&DAT_040000b0 + param_1 * 0xc) = param_2;
  puVar3 = (undefined4 *)(param_1 * 0xc + iVar1);
  puVar3[1] = param_3;
  puVar3[2] = param_4;
  if (param_1 == 0) {
    *puVar3 = 0;
    uVar2 = uRam01ffff34;
    puVar3[1] = 0;
    puVar3[2] = uVar2;
  }
  Os_RestoreIrq();
  return;
}

