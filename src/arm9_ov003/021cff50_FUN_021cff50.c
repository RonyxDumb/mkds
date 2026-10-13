/* Decompiled C draft; module arm9_ov003; ROM address 021cff50. No matching claim. */
#include "types.h"
#include "deps/021cff50_FUN_021cff50.h"

void FUN_021cff50(int param_1)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  
  if (*(short *)(param_1 + 2) != 0) {
    FUN_021d079c();
    FUN_021d07b0(9);
    return;
  }
  if ((code *)*DAT_021cffe8 != (code *)0x0) {
    (*(code *)*DAT_021cffe8)
              (DAT_021cffec,DAT_021cfff0,*(undefined2 *)(param_1 + 8),*(undefined2 *)(param_1 + 10))
    ;
  }
  piVar2 = DAT_021cfff4;
  uVar4 = (uint)*(ushort *)(param_1 + 8);
  uVar1 = *(ushort *)(param_1 + 10);
  iVar3 = *DAT_021cfff4;
  if (uVar1 < *(ushort *)(iVar3 + 0x5e)) {
    *(ushort *)(iVar3 + 0x5e) = uVar1;
    *(short *)(*piVar2 + 0x60) = (short)(1 << (uVar4 - 1 & 0xff));
  }
  else if (*(ushort *)(iVar3 + 0x5e) == uVar1) {
    *(ushort *)(iVar3 + 0x60) = *(ushort *)(iVar3 + 0x60) | (ushort)(1 << (uVar4 - 1 & 0xff));
  }
  iVar3 = FUN_021cfff8(uVar4 + 1 & 0xffff);
  if (iVar3 == 0x18) {
    FUN_021d07b0(7);
    return;
  }
  if (iVar3 != 2) {
    FUN_021d07b0(9);
  }
  return;
}

