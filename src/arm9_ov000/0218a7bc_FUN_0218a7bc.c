/* Decompiled C draft; module arm9_ov000; ROM address 0218a7bc. No matching claim. */
#include "types.h"
#include "deps/0218a7bc_FUN_0218a7bc.h"

void FUN_0218a7bc(int param_1,undefined4 param_2,int param_3)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  byte local_20 [4];
  undefined4 local_1c [2];
  
  iVar3 = DAT_0218a840;
  if (param_3 == 0) {
    FUN_0218a854();
    return;
  }
  iVar2 = 0;
  do {
    *(char *)(param_1 + iVar2) = (char)iVar2;
    iVar2 = iVar2 + 1;
  } while (iVar2 < iVar3);
  local_1c[0] = 0;
  local_20[0] = 0;
  iVar3 = 0xff;
  do {
    iVar2 = FUN_0218a898(param_1,iVar3,param_2,param_3,local_20,local_1c);
    uVar1 = *(undefined1 *)(param_1 + iVar3);
    *(undefined1 *)(param_1 + iVar3) = *(undefined1 *)(param_1 + iVar2);
    *(undefined1 *)(param_1 + iVar2) = uVar1;
    iVar3 = iVar3 + -1;
  } while (-1 < iVar3);
  *(undefined1 *)(param_1 + DAT_0218a840) = *(undefined1 *)(param_1 + 1);
  *(undefined1 *)(param_1 + DAT_0218a844) = *(undefined1 *)(param_1 + 3);
  *(undefined1 *)(param_1 + DAT_0218a848) = *(undefined1 *)(param_1 + 5);
  *(undefined1 *)(param_1 + DAT_0218a84c) = *(undefined1 *)(param_1 + 7);
  *(undefined1 *)(param_1 + DAT_0218a850) = *(undefined1 *)(param_1 + (uint)local_20[0]);
  return;
}

