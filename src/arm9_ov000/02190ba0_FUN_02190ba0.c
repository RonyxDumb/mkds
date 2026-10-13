/* Decompiled C draft; module arm9_ov000; ROM address 02190ba0. No matching claim. */
#include "types.h"
#include "deps/02190ba0_FUN_02190ba0.h"

undefined4 FUN_02190ba0(undefined4 param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_3 == 0) {
    func_0x0213442c(DAT_02190c4c,DAT_02190c50,0,0x51);
  }
  if (param_4 < 0) {
    func_0x0213442c(DAT_02190c54,DAT_02190c50,0,0x52);
  }
  if (param_2 == (int *)0x0) {
    func_0x0213442c(DAT_02190c58,DAT_02190c50,0,0x53);
  }
  if (param_3 == 0) {
    return 0;
  }
  iVar1 = param_2[2];
  iVar3 = param_2[1];
  iVar4 = *param_2;
  if (iVar3 - iVar1 < param_4) {
    iVar2 = DAT_02190c5c;
    if (DAT_02190c5c <= param_4) {
      iVar2 = param_4;
    }
    iVar3 = iVar3 + iVar2;
    iVar4 = FUN_021a3678(iVar4,iVar3 + 1);
    if (iVar4 == 0) {
      FUN_02196590((undefined4 *)(uintptr_t)(param_1),DAT_02190c60);
      return 1;
    }
  }
  func_0x02134eb8((uint *)(uintptr_t)(iVar4 + iVar1),param_3,param_4);
  *(undefined1 *)(iVar4 + iVar1 + param_4) = 0;
  param_2[2] = param_2[2] + param_4;
  param_2[1] = iVar3;
  *param_2 = iVar4;
  return 0;
}

