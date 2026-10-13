/* Decompiled C draft; module arm9_ov000; ROM address 021a299c. No matching claim. */
#include "types.h"
#include "deps/021a299c_FUN_021a299c.h"

undefined4 FUN_021a299c(int param_1,int *param_2)

{
  int *piVar1;
  char *pcVar2;
  undefined8 uVar3;
  
  if (*DAT_021a2a78 == 0) {
    return 1;
  }
  if (param_2 == (int *)0x0) {
    return 3;
  }
  if (param_1 != 0) {
    if (param_1 != 1) {
      return 2;
    }
    if (*param_2 == 0) {
      *DAT_021a2a84 = 0;
    }
    else {
      *DAT_021a2a84 = 1;
    }
    DAT_021a2a84[1] = 0;
    return 0;
  }
  if (*(int *)(*DAT_021a2a78 + DAT_021a2a7c) == 0x13) {
    return 1;
  }
  if (((char)*param_2 != '\0') && (*(byte *)((int)param_2 + 1) < 2)) {
    return 3;
  }
  pcVar2 = (char *)*DAT_021a2a80;
  if (pcVar2 == (char *)0x0) {
    pcVar2 = (char *)FUN_021a372c(4,0x20);
    *DAT_021a2a80 = (int)pcVar2;
    if (pcVar2 == (char *)0x0) {
      return 4;
    }
  }
  *pcVar2 = (char)*param_2;
  piVar1 = DAT_021a2a80;
  *(char *)(*DAT_021a2a80 + 1) = *(char *)((int)param_2 + 1);
  *(undefined1 *)(*piVar1 + 2) = 0;
  *(undefined1 *)(*piVar1 + 3) = 0;
  *(int *)(*piVar1 + 4) = param_2[1];
  *(undefined4 *)(*piVar1 + 8) = 0;
  *(undefined4 *)(*piVar1 + 0xc) = 0;
  uVar3 = FUN_021a350c();
  *(undefined8 *)(*DAT_021a2a80 + 0x10) = uVar3;
  uVar3 = FUN_021a350c();
  *(undefined8 *)(*DAT_021a2a80 + 0x18) = uVar3;
  return 0;
}

