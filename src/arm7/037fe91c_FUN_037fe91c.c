/* Decompiled C draft; module arm7; ROM address 037fe91c. No matching claim. */
#include "types.h"
#include "deps/037fe91c_FUN_037fe91c.h"

void FUN_037fe91c(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  iVar1 = param_1 * 0x24 + DAT_037fe964;
  if (param_4 == 1) {
    *(char *)(iVar1 + param_2) = (char)param_3;
  }
  else if (param_4 == 2) {
    *(short *)(iVar1 + param_2) = (short)param_3;
  }
  else if (param_4 == 4) {
    *(undefined4 *)(iVar1 + param_2) = param_3;
  }
  return;
}

