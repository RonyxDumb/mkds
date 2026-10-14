/* Decompiled C draft; module arm9; ROM address 02016574. No matching claim. */
#include "types.h"
#include "deps/02016574_StructTEQ_TryPopTEQSub.h"

undefined4 StructTEQ_TryPopTEQSub(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = StructTEQ_IsCounterEmpty();
  if (iVar2 == 0) {
    uVar1 = StructTEQ_IncrementValidateIndex(param_1,*(undefined2 *)(param_1 + 8));
    *(undefined2 *)(param_1 + 8) = uVar1;
    *(short *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) + -1;
    return 1;
  }
  return 0;
}

