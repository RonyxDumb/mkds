/* Decompiled C draft; module arm9; ROM address 0211e160. No matching claim. */
#include "types.h"
#include "deps/0211e160_func_0211e160.h"

undefined4 func_0211e160(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_10 [8];
  
  uVar2 = 0;
  switch(param_1) {
  case 0:
    iVar3 = *(int *)*DAT_0211e1ec;
    iVar1 = GetCourseIdFromInternalId(((int *)*DAT_0211e1ec)[3]);
    uVar2 = func_0206174c(iVar3 + iVar1 * 0x30);
    break;
  case 1:
    if (*(short *)(*DAT_0211e1ec + 0x10) != -1) {
      uVar2 = 1;
    }
    break;
  case 2:
    iVar1 = func_02060228(*(undefined4 *)(*DAT_0211e1ec + 0xc));
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      func_02060134(*(undefined4 *)(*DAT_0211e1ec + 0xc),0,auStack_10);
      uVar2 = func_020908d0(*(undefined4 *)(*DAT_0211e1ec + 0xc),auStack_10);
    }
    break;
  case 4:
    uVar2 = 1;
  }
  return uVar2;
}

