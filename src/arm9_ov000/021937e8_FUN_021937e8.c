/* Decompiled C draft; module arm9_ov000; ROM address 021937e8. No matching claim. */
#include "types.h"
#include "deps/021937e8_FUN_021937e8.h"

undefined4 FUN_021937e8(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(*param_1 + DAT_02193814);
  while( true ) {
    if (iVar1 == 0) {
      if (param_2 != (int *)0x0) {
        *param_2 = 0;
      }
      return 0;
    }
    if (*(int *)(iVar1 + 0x18) == param_3) break;
    iVar1 = *(int *)(iVar1 + 0x20);
  }
  if (param_2 != (int *)0x0) {
    *param_2 = iVar1;
  }
  return 1;
}

