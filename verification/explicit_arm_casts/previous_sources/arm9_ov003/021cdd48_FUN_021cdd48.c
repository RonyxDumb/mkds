/* Decompiled C draft; module arm9_ov003; ROM address 021cdd48. No matching claim. */
#include "types.h"
#include "deps/021cdd48_FUN_021cdd48.h"

void FUN_021cdd48(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_1c;
  undefined1 auStack_18 [4];
  
  FUN_021d1770(*(undefined4 *)*DAT_021cddc0,0,&local_1c,auStack_18);
  local_1c = local_1c + -8;
  iVar4 = 0;
  iVar2 = 0;
  iVar3 = DAT_021cddc4;
  do {
    FUN_021d17d4(*(undefined4 *)(*DAT_021cddc0 + iVar2),0xffffffff,local_1c,
                 *(undefined2 *)(iVar3 + 2));
    iVar3 = iVar3 + 4;
    iVar2 = iVar2 + 4;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 5);
  if ((local_1c <= DAT_021cddc8) && (DAT_021cddcc <= local_1c)) {
    FUN_021d34c8(0,param_1);
    piVar1 = DAT_021cddc0;
    iVar3 = 0;
    iVar2 = 0;
    do {
      FUN_021d197c(*(undefined4 *)(*piVar1 + iVar2));
      iVar2 = iVar2 + 4;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 5);
    FUN_021d2808(DAT_021cddc0);
  }
  return;
}

