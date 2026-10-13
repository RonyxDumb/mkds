/* Decompiled C draft; module arm9; ROM address 02009c34. No matching claim. */
#include "types.h"
#include "deps/02009c34_func_02009c34.h"

undefined4 func_02009c34(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 1;
  uVar2 = Os_DisableIrq();
  iVar3 = iRam02009c84;
  piVar1 = piRam02009c80;
  if (*(short *)(*piRam02009c80 + iRam02009c84) == 0) {
    uVar4 = 0;
    *(undefined4 *)(*piRam02009c80 + iRam02009c88) = 0;
    *(undefined2 *)(*piVar1 + iVar3) = 1;
    iVar3 = IsGlobalANSet_from_thumb();
    if (iVar3 == 0) {
      uVar4 = SomeAnnFnPtr_Impl_from_thumb();
    }
    else {
      func_0200aeb4(uRam02009c8c);
    }
  }
  Os_RestoreIrq(uVar2);
  return uVar4;
}

