/* Decompiled C draft; module arm9; ROM address 02007d50. No matching claim. */
#include "types.h"
#include "deps/02007d50_func_02007d50.h"

undefined4 func_02007d50(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  
  uVar1 = Os_DisableIrq();
  switch(param_2) {
  case 0:
    iVar3 = 10;
    uVar4 = 4;
    break;
  case 1:
    iVar3 = 10;
    uVar4 = 3;
    break;
  case 2:
    iVar3 = 0xe;
    uVar4 = 2;
    break;
  case 3:
    iVar3 = 7;
    uVar4 = 5;
    break;
  default:
    Os_RestoreIrq(uVar1);
    return 0;
  }
  if ((*DAT_02007dec != 0) && (iVar2 = func_02007138(param_1), iVar2 != 0)) {
    if (iVar3 == *(int *)(*DAT_02007dec + (param_1 + -1) * 4 + DAT_02007df0)) {
      *(undefined2 *)(*DAT_02007dec + (param_1 + -1) * 2 + DAT_02007df4) = uVar4;
      Os_RestoreIrq(uVar1);
      return 1;
    }
  }
  Os_RestoreIrq(uVar1);
  return 0;
}

