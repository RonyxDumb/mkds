/* Decompiled C draft; module arm7; ROM address 06009040. No matching claim. */
#include "types.h"
#include "deps/06009040_FUN_06009040.h"

int FUN_06009040(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(ushort *)(param_3 + 10) == DAT_060090b0) {
    uVar2 = thunk_FUN_037f8850(0x1000000);
    iVar1 = FUN_06008e50(param_1,param_3);
    if (iVar1 == 0) {
      iVar1 = FUN_06008f34(param_2,param_3);
    }
    thunk_FUN_037f888c(uVar2);
  }
  else {
    iVar1 = 1;
  }
  return iVar1;
}

