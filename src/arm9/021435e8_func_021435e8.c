/* Decompiled C draft; module arm9; ROM address 021435e8. No matching claim. */
#include "types.h"
#include "deps/021435e8_func_021435e8.h"

int func_021435e8(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = Os_DisableIrq();
  iVar2 = Wm_CheckInitialized();
  if (iVar2 != 0) {
    Os_RestoreIrq(uVar1);
    return iVar2;
  }
  iVar2 = Wm_GetGlobal();
  *(undefined4 *)(iVar2 + 0xc0) = param_1;
  Os_RestoreIrq(uVar1);
  return 0;
}

