/* Decompiled C draft; module arm9_ov000; ROM address 021a7eec. No matching claim. */
#include "types.h"
#include "deps/021a7eec_FUN_021a7eec.h"

int FUN_021a7eec(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_3 + 0x14);
  if (param_2 < iVar1) {
    iVar1 = param_2;
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_3 + 0x1c);
    if (param_2 - iVar1 < *(int *)(param_3 + 0x1c)) {
      iVar2 = param_2 - iVar1;
    }
  }
  if (0 < iVar1) {
    func_0x0214d1fc(*(undefined4 *)(param_3 + 0x10),param_1,iVar1);
    *(int *)(param_3 + 0x10) = *(int *)(param_3 + 0x10) + iVar1;
    *(int *)(param_3 + 0x14) = *(int *)(param_3 + 0x14) - iVar1;
  }
  if (0 < iVar2) {
    func_0x0214d1fc(*(undefined4 *)(param_3 + 0x18),param_1 + iVar1,iVar2);
    *(int *)(param_3 + 0x18) = *(int *)(param_3 + 0x18) + iVar2;
    *(int *)(param_3 + 0x1c) = *(int *)(param_3 + 0x1c) - iVar2;
  }
  return iVar1 + iVar2;
}

