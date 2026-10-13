/* Decompiled C draft; module arm9_ov000; ROM address 021a7d68. No matching claim. */
#include "types.h"
#include "deps/021a7d68_FUN_021a7d68.h"

int FUN_021a7d68(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,uint param_7)

{
  bool bVar1;
  int iVar2;
  undefined1 unaff_r7;
  undefined4 local_1c;
  
  iVar2 = *(int *)(param_1 + 100);
  if (((param_7 & 2) == 0) || (iVar2 == 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    unaff_r7 = *(undefined1 *)(iVar2 + 0xfe);
    *(undefined1 *)(iVar2 + 0xfe) = 1;
  }
  if (*(char *)(param_1 + 0x73) == '\x01') {
    local_1c = FUN_021a797c(param_1,param_2,param_3,(undefined2 *)(uintptr_t)(param_4),(int *)(uintptr_t)(param_5),param_6);
  }
  else {
    local_1c = FUN_021a7d14(param_1,param_2,param_3,param_4,param_5,param_6);
    if (-1 < local_1c) {
      FUN_021a7aa8(param_1);
    }
  }
  if (bVar1) {
    *(undefined1 *)(iVar2 + 0xfe) = unaff_r7;
  }
  return local_1c;
}

