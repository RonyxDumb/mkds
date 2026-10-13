/* Decompiled C draft; module arm9_ov003; ROM address 021d0530. No matching claim. */
#include "types.h"
#include "deps/021d0530_FUN_021d0530.h"

void FUN_021d0530(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = (uint)*(ushort *)(param_1 + 0x10);
  uVar2 = (ushort)(1 << (uVar4 & 0xff));
  if (*(short *)(param_1 + 2) != 0) {
    FUN_021d079c();
    FUN_021d07b0(9);
    return;
  }
  uVar1 = *(ushort *)(param_1 + 8);
  if (uVar1 < 8) {
    if (6 < uVar1) {
      if ((code *)*DAT_021d0618 != (code *)0x0) {
        (*(code *)*DAT_021d0618)(DAT_021d061c,DAT_021d0620,uVar4);
      }
      if ((*(code **)(*DAT_021d0624 + 0x4c) != (code *)0x0) &&
         (iVar3 = (**(code **)(*DAT_021d0624 + 0x4c))(param_1), iVar3 == 0)) {
        iVar3 = func_0x021436d0(0,*(undefined2 *)(param_1 + 0x10));
        if (iVar3 == 2) {
          return;
        }
        FUN_021d079c();
        FUN_021d07b0(9);
        return;
      }
      *(ushort *)(*DAT_021d0624 + 0x52) = *(ushort *)(*DAT_021d0624 + 0x52) | uVar2;
      return;
    }
    if (uVar1 < 3) {
      if (uVar1 == 0) {
        iVar3 = FUN_021d04a8();
        if (iVar3 != 0) {
          return;
        }
        FUN_021d07b0(9);
        return;
      }
      if (uVar1 == 2) {
        return;
      }
    }
  }
  else if (uVar1 == 9) {
    if ((code *)*DAT_021d0618 != (code *)0x0) {
      (*(code *)*DAT_021d0618)(DAT_021d061c,DAT_021d0628,uVar4);
    }
    *(ushort *)(*DAT_021d0624 + 0x52) = *(ushort *)(*DAT_021d0624 + 0x52) & ~uVar2;
    return;
  }
  if ((code *)*DAT_021d0618 != (code *)0x0) {
    (*(code *)*DAT_021d0618)(DAT_021d061c,DAT_021d062c);
  }
  return;
}

