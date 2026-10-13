/* Decompiled C draft; module arm9_ov000; ROM address 0219e8b8. No matching claim. */
#include "types.h"
#include "deps/0219e8b8_FUN_0219e8b8.h"

void FUN_0219e8b8(int param_1)

{
  int *piVar1;
  char *pcVar2;
  undefined8 uVar3;
  
  piVar1 = DAT_0219e8f8;
  pcVar2 = (char *)*DAT_0219e8f8;
  if ((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) {
    pcVar2[8] = '\0';
    pcVar2[9] = '\0';
    pcVar2[10] = '\0';
    pcVar2[0xb] = '\0';
    *(undefined4 *)(*piVar1 + 0xc) = 0;
    *(undefined1 *)(*piVar1 + 2) = 0;
    uVar3 = FUN_021a350c();
    *(undefined8 *)(*DAT_0219e8f8 + 0x18) = uVar3;
    if (param_1 == 0) {
      uVar3 = FUN_021a350c();
      *(undefined8 *)(*DAT_0219e8f8 + 0x10) = uVar3;
    }
  }
  return;
}

