/* Decompiled C draft; module arm9; ROM address 02009c04. No matching claim. */
#include "types.h"
#include "deps/02009c04_func_02009c04.h"

void func_02009c04(void)

{
  undefined4 uVar1;
  
  uVar1 = Os_DisableIrq();
  if (*(int *)(*piRam02009c2c + iRam02009c30) == 0) {
    Os_Terminate();
  }
  func_02009c34();
  Os_RestoreIrq(uVar1);
  return;
}

