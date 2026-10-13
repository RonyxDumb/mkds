/* Decompiled C draft; module arm9; ROM address 020aab40. No matching claim. */
#include "types.h"
#include "deps/020aab40_func_020aab40.h"

undefined4 func_020aab40(int param_1)

{
  bool bVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  bVar1 = false;
  if ((*(int *)(param_1 + 0x10) != 0) && (*(int *)(param_1 + 0x14) != 0)) {
    bVar1 = true;
  }
  if ((bVar1) &&
     (*(short *)(*(int *)(param_1 + 0x14) + 6) == *(short *)(*(int *)(param_1 + 0x10) + 6))) {
    uVar2 = 1;
  }
  return uVar2;
}

