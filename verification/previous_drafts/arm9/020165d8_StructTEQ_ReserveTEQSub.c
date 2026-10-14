/* Decompiled C draft; module arm9; ROM address 020165d8. No matching claim. */
#include "types.h"
#include "deps/020165d8_StructTEQ_ReserveTEQSub.h"

undefined4 StructTEQ_ReserveTEQSub(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = StructTEQ_IsTEQSubListFull();
  if (iVar2 == 0) {
    uVar1 = StructTEQ_IncrementValidateIndex(param_1,*(undefined2 *)(param_1 + 10));
    *(undefined2 *)(param_1 + 10) = uVar1;
    *(short *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) + 1;
    return 1;
  }
  return 0;
}

