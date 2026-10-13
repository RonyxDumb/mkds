/* Decompiled C draft; module arm9; ROM address 0214358c. No matching claim. */
#include "types.h"
#include "deps/0214358c_func_0214358c.h"

int func_0214358c(int param_1,undefined4 param_2,undefined4 param_3)

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
  iVar2 = iVar2 + param_1 * 4;
  *(undefined4 *)(iVar2 + 0xc4) = param_2;
  *(undefined4 *)(iVar2 + 0x104) = param_3;
  Os_RestoreIrq(uVar1);
  return 0;
}

