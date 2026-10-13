/* Decompiled C draft; module arm9_ov003; ROM address 021cea3c. No matching claim. */
#include "types.h"
#include "deps/021cea3c_FUN_021cea3c.h"

void FUN_021cea3c(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  *DAT_021ceaa8 = *DAT_021ceaa8 & DAT_021ceaac;
  FUN_021d197c(*(undefined4 *)*DAT_021ceab0);
  FUN_021d197c(*(undefined4 *)(*DAT_021ceab0 + 4));
  iVar2 = DAT_021ceab4;
  piVar1 = DAT_021ceab0;
  iVar5 = 0;
  iVar3 = *DAT_021ceab0;
  if (*(char *)(DAT_021ceab4 + (uint)*(byte *)(iVar3 + 0x1c)) != '\0') {
    iVar4 = 0;
    do {
      if (*(int *)(iVar3 + iVar4 + 8) != 0) {
        FUN_021d197c();
      }
      iVar4 = iVar4 + 4;
      iVar5 = iVar5 + 1;
      iVar3 = *piVar1;
    } while (iVar5 < (int)(uint)*(byte *)(iVar2 + (uint)*(byte *)(iVar3 + 0x1c)));
  }
  FUN_021d2388(*(undefined4 *)(iVar3 + 0x10));
  FUN_021d34c8(1,param_1);
  FUN_021d2808(DAT_021ceab0);
  return;
}

