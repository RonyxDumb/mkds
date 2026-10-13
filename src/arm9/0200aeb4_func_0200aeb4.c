/* Decompiled C draft; module arm9; ROM address 0200aeb4. No matching claim. */
#include "types.h"
#include "deps/0200aeb4_func_0200aeb4.h"

void func_0200aeb4(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = Os_DisableIrq();
  iVar2 = IsGlobalANSet_from_thumb();
  if (iVar2 != 0) {
    StructANN_SomeFn_from_thumb((undefined4 *)(uintptr_t)(*piRam0200aee8 + 0xc4),0,param_1,0);
  }
  Os_RestoreIrq(uVar1);
  return;
}

