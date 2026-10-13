/* Decompiled C draft; module arm9_ov000; ROM address 021a17bc. No matching claim. */
#include "types.h"
#include "deps/021a17bc_FUN_021a17bc.h"

undefined4 FUN_021a17bc(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined8 uVar3;
  
  iVar2 = FUN_0219bab4();
  piVar1 = DAT_021a18b4;
  if (iVar2 != 5) {
    return 0;
  }
  if (*(char *)(*DAT_021a18b4 + 0x15) == '\x02') {
    return 1;
  }
  if (param_1 != 0) {
    FUN_021a1a38(param_1,param_2 - DAT_021a18b8);
    return 1;
  }
  *(undefined1 *)(*DAT_021a18b4 + DAT_021a18bc) = 0;
  iVar2 = *piVar1;
  if ((*(char *)(iVar2 + DAT_021a18c0) != '\x01') &&
     (1 < (byte)(*(char *)(iVar2 + DAT_021a18c4) - 1U))) {
    if (*(int *)(iVar2 + DAT_021a18c8) != 0) {
      FUN_0219ac50();
      *(undefined4 *)(*DAT_021a18b4 + DAT_021a18c8) = 0;
    }
    piVar1 = DAT_021a18b4;
    iVar2 = *DAT_021a18b4;
    if (*(char *)(iVar2 + 0xd) == '\0') {
      if (*(char *)(iVar2 + 0x15) == '\x03') {
        FUN_021a1a38(6,DAT_021a18cc);
      }
      else if (*(int *)(iVar2 + DAT_021a18d0) == 0) {
        if (*(int *)(iVar2 + DAT_021a18d4) == 1) {
          *(int *)(iVar2 + DAT_021a18d4) = 0x12;
          uVar3 = FUN_021a350c();
          iVar2 = *DAT_021a18b4;
          *(int *)(iVar2 + DAT_021a18d8) = (int)uVar3;
          *(int *)(iVar2 + DAT_021a18dc) = (int)((ulonglong)uVar3 >> 0x20);
        }
        else {
          FUN_0219f23c(1);
        }
      }
      else {
        FUN_0219f184();
      }
    }
    else if (*(char *)(iVar2 + DAT_021a18c4) == '\0') {
      *(char *)(iVar2 + DAT_021a18c4) = '\x03';
      FUN_021988e8(**(undefined4 **)(*piVar1 + 4));
    }
    return 1;
  }
  return 1;
}

