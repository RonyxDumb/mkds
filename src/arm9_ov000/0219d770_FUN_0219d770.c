/* Decompiled C draft; module arm9_ov000; ROM address 0219d770. No matching claim. */
#include "types.h"
#include "deps/0219d770_FUN_0219d770.h"

void FUN_0219d770(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_3c [40];
  
  piVar1 = DAT_0219d814;
  *(undefined4 *)(*DAT_0219d814 + 0x2c) = param_3;
  *(undefined4 *)(*piVar1 + 0x30) = param_4;
  *(undefined4 *)(*piVar1 + 0x34) = param_5;
  *(undefined4 *)(*piVar1 + 0x38) = param_6;
  *(undefined4 *)(*piVar1 + 0x3c) = param_7;
  *(undefined4 *)(*piVar1 + 0x40) = param_8;
  iVar4 = 0;
  *(undefined1 *)(*piVar1 + 0x1d) = 0;
  *(undefined1 *)(*piVar1 + 0x1e) = 0;
  *(undefined1 *)(*piVar1 + 0x1f) = 0;
  *(undefined4 *)*piVar1 = 1;
  iVar2 = *piVar1;
  if (**(char **)(iVar2 + 0x28) == '\0') {
    *(char *)(iVar2 + 0x1f) = *(char *)(iVar2 + 0x1f) + '\x01';
    return;
  }
  do {
    iVar2 = FUN_02197690(0);
    if (iVar2 == 0) break;
    if ((iVar2 != 2) || (iVar4 == 4)) {
      FUN_0219cfc0();
      return;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 5);
  uVar3 = FUN_021975f4(0);
  FUN_02197a9c(uVar3,param_2,auStack_3c);
  FUN_02197594(0,param_1,(undefined4)(uintptr_t)(auStack_3c),DAT_0219d818,0);
  FUN_0219cb30();
  return;
}

