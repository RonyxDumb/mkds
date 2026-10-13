/* Decompiled C draft; module arm9_ov000; ROM address 021a4784. No matching claim. */
#include "types.h"
#include "deps/021a4784_FUN_021a4784.h"

void FUN_021a4784(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + DAT_021a47a8);
  if (((iVar1 < 0xfe) && (0 < param_2)) && (param_2 < 0xff)) {
    *(int *)(param_1 + DAT_021a47a8) = iVar1 + 1;
    *(char *)(param_1 + iVar1) = (char)param_2;
  }
  return;
}

