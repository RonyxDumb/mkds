/* Decompiled C draft; module arm9_ov000; ROM address 0219ddbc. No matching claim. */
#include "types.h"
#include "deps/0219ddbc_FUN_0219ddbc.h"

void FUN_0219ddbc(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(*DAT_0219de30 + DAT_0219de34);
  if (iVar3 == 1) {
    *(int *)(*DAT_0219de30 + DAT_0219de34) = 6;
  }
  else if ((iVar3 != 6) && (iVar3 != 0xb)) {
    return;
  }
  iVar3 = DAT_0219de38;
  piVar1 = DAT_0219de30;
  iVar2 = *DAT_0219de30;
  if (*(int *)(iVar2 + DAT_0219de38) == param_1) {
    *(char *)(iVar2 + DAT_0219de3c) = *(char *)(iVar2 + DAT_0219de3c) + '\x01';
  }
  else {
    *(undefined1 *)(iVar2 + DAT_0219de3c) = 0;
    *(int *)(*piVar1 + iVar3) = param_1;
  }
  iVar3 = *DAT_0219de30;
  *(undefined4 *)(iVar3 + DAT_0219de40) = 0;
  *(undefined4 *)(iVar3 + DAT_0219de44) = 0;
  FUN_021a0cac(1);
  iVar3 = FUN_0219e4a0();
  if (iVar3 == 0) {
    *(undefined1 *)(*DAT_0219de30 + DAT_0219de48) = 0xff;
  }
  return;
}

