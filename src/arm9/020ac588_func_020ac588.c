/* Decompiled C draft; module arm9; ROM address 020ac588. No matching claim. */
#include "types.h"
#include "deps/020ac588_func_020ac588.h"

void func_020ac588(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < param_2) {
    do {
      iVar1 = func_020d34d4(param_3,param_1);
      if ((*(ushort *)(iVar1 + 2) & 0x100) == 0) {
        func_020d2398();
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_2);
    return;
  }
  return;
}

