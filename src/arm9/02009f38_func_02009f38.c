/* Decompiled C draft; module arm9; ROM address 02009f38. No matching claim. */
#include "types.h"
#include "deps/02009f38_func_02009f38.h"

undefined4 func_02009f38(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = Os_DisableIrq();
  if (*(char *)(*piRam02009f9c + iRam02009fa0) != '\0') {
    Os_RestoreIrq();
    return 0;
  }
  iVar3 = func_02009fac(param_1,8,param_2);
  piVar1 = piRam02009f9c;
  if (iVar3 == 0) {
    Os_RestoreIrq(uVar2);
    return 0;
  }
  *(short *)(*piRam02009f9c + 0x10) = (short)param_2;
  *(short *)(*piVar1 + iRam02009fa4) = (short)param_1;
  *(undefined2 *)(*piVar1 + iRam02009fa8) = 8;
  Os_RestoreIrq(uVar2);
  return 1;
}

