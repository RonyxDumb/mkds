/* Decompiled C draft; module arm9_ov000; ROM address 021adf30. No matching claim. */
#include "types.h"
#include "deps/021adf30_FUN_021adf30.h"

void FUN_021adf30(uint param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = func_0x0200fca0();
  if (param_1 < *(uint *)(param_2 + 0x44)) {
    *(uint *)(param_2 + 0x44) = *(uint *)(param_2 + 0x44) - param_1;
    func_0x02134df8(*(int *)(param_2 + 0x40),*(int *)(param_2 + 0x40) + param_1);
  }
  else {
    *(undefined4 *)(param_2 + 0x44) = 0;
  }
  func_0x0200fcb4(uVar1);
  if (((*(char *)(param_2 + 8) != '\n') && (*(char *)(param_2 + 8) != '\v')) &&
     (*(int *)(param_2 + 0x44) == 0)) {
    FUN_021aefb4(param_2,0x1b);
  }
  return;
}

