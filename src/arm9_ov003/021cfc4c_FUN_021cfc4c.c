/* Decompiled C draft; module arm9_ov003; ROM address 021cfc4c. No matching claim. */
#include "types.h"
#include "deps/021cfc4c_FUN_021cfc4c.h"

undefined4 FUN_021cfc4c(int param_1,undefined2 param_2,undefined2 param_3)

{
  int *piVar1;
  int iVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  
  if (*(int *)(*DAT_021cfd20 + 0x40) != 1) {
    func_0x0200fd1c();
  }
  iVar2 = DAT_021cfd28;
  piVar1 = DAT_021cfd20;
  *(undefined4 *)(*DAT_021cfd20 + DAT_021cfd28) = DAT_021cfd24;
  *(undefined4 *)(*piVar1 + DAT_021cfd2c) = 0xe0;
  if ((code *)*DAT_021cfd30 != (code *)0x0) {
    (*(code *)*DAT_021cfd30)(DAT_021cfd34,DAT_021cfd38,*(undefined4 *)(*piVar1 + iVar2));
  }
  if ((code *)*DAT_021cfd30 != (code *)0x0) {
    (*(code *)*DAT_021cfd30)
              (DAT_021cfd34,DAT_021cfd3c,*(undefined4 *)(*DAT_021cfd20 + DAT_021cfd2c));
  }
  *(int *)(*DAT_021cfd20 + 0x44) = param_1;
  FUN_021d07b0(3);
  piVar1 = DAT_021cfd20;
  *(undefined2 *)(*DAT_021cfd20 + 0xc) = param_2;
  *(undefined2 *)(*piVar1 + 0x32) = param_3;
  uVar3 = func_0x02143134();
  piVar1 = DAT_021cfd20;
  *(undefined2 *)(*DAT_021cfd20 + 0x18) = uVar3;
  *(undefined2 *)(*piVar1 + 0x34) = 0xd0;
  *(undefined2 *)(*piVar1 + 0x36) = 0x44;
  *(undefined2 *)(*piVar1 + 0x10) = 2;
  *(undefined2 *)(*piVar1 + 0x16) = 0;
  *(undefined2 *)(*piVar1 + 0x12) = 0;
  *(undefined2 *)(*piVar1 + 0xe) = 1;
  *(ushort *)(*DAT_021cfd20 + 0x14) = (ushort)(param_1 == 2);
  if (((param_1 != 0) && (param_1 != 2)) && (param_1 != 4)) {
    if ((code *)*DAT_021cfd30 != (code *)0x0) {
      (*(code *)*DAT_021cfd30)(DAT_021cfd34,DAT_021cfd40,param_1);
    }
    return 0;
  }
  uVar4 = FUN_021d0760();
  return uVar4;
}

