/* Decompiled C draft; module arm9_ov000; ROM address 021a71c0. No matching claim. */
#include "types.h"
#include "deps/021a71c0_FUN_021a71c0.h"

int FUN_021a71c0(int param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  *(undefined1 *)(param_1 + 0x73) = *param_2;
  *(undefined1 *)(param_1 + 0x72) = param_2[1];
  iVar4 = param_1 + 0x80;
  iVar2 = iVar4;
  if (*(short *)(param_2 + 2) != 0) {
    *(int *)(param_1 + 100) = iVar4;
    *(undefined2 *)(param_1 + 0x17c) = *(undefined2 *)(param_2 + 4);
    uVar1 = FUN_021a7154(iVar4 + DAT_021a7288,iVar4,param_2 + 0x10);
    uVar1 = FUN_021a71a4(uVar1,param_1 + 0x3c,*(undefined2 *)(param_2 + 2));
    iVar2 = FUN_021a71a4(uVar1,param_1 + 0x50,*(undefined2 *)(param_2 + 8));
    *(undefined2 *)(iVar4 + DAT_021a728c) = *(undefined2 *)(param_2 + 0xe);
    puVar3 = (undefined4 *)(iVar4 + DAT_021a7290);
    *puVar3 = 0;
    *(undefined4 *)(iVar4 + DAT_021a7294) = *puVar3;
  }
  if (*(short *)(param_2 + 6) == 0) {
    *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(*DAT_021a72a0 + 0x68);
  }
  else {
    *(int *)(param_1 + 0x68) = iVar2;
    *(int *)(iVar2 + DAT_021a7294) = param_1;
    uVar1 = FUN_021a7154(iVar2 + DAT_021a7290,iVar2,param_2 + 0x14);
    uVar1 = FUN_021a71a4(uVar1,param_1 + 0x48,*(undefined2 *)(param_2 + 6));
    uVar1 = FUN_021a71a4(uVar1,param_1 + 0x58,*(undefined2 *)(param_2 + 10));
    iVar4 = FUN_021a71a4(uVar1,iVar2 + 0xf8,*(undefined2 *)(param_2 + 0xc));
    puVar3 = (undefined4 *)(iVar2 + DAT_021a7298);
    *puVar3 = 0;
    *(undefined4 *)(iVar2 + DAT_021a729c) = *puVar3;
    iVar2 = iVar4;
  }
  return iVar2;
}

