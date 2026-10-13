/* Decompiled C draft; module arm9_ov001; ROM address 021874c4. No matching claim. */
#include "types.h"
#include "deps/021874c4_FUN_021874c4.h"

void FUN_021874c4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = param_1;
  do {
    if (*(int *)(iVar1 + 0xd0) == 0) {
      *(undefined4 *)(param_1 + iVar2 * 0x18 + 0xbc) = 5;
      FUN_02187614(param_1,iVar2,param_2,param_3,param_4,param_5,param_6);
      return;
    }
    iVar1 = iVar1 + 0x18;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  return;
}

