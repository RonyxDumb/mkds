/* Decompiled C draft; module arm9_ov000; ROM address 02190c64. No matching claim. */
#include "types.h"
#include "deps/02190c64_FUN_02190c64.h"

undefined4 FUN_02190c64(undefined4 param_1,int *param_2,undefined1 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 == (int *)0x0) {
    func_0x0213442c(DAT_02190cc4,DAT_02190cc8,0,0x25);
  }
  iVar3 = param_2[2];
  iVar2 = param_2[1];
  iVar1 = *param_2;
  if (iVar2 == iVar3) {
    iVar2 = iVar2 + DAT_02190ccc;
    iVar1 = FUN_021a3678(iVar1,iVar2 + 1);
    if (iVar1 == 0) {
      FUN_02196590(param_1,DAT_02190cd0);
      return 1;
    }
  }
  *(undefined1 *)(iVar1 + iVar3) = param_3;
  *(undefined1 *)(iVar1 + iVar3 + 1) = 0;
  param_2[2] = param_2[2] + 1;
  param_2[1] = iVar2;
  *param_2 = iVar1;
  return 0;
}

