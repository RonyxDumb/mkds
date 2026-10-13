/* Decompiled C draft; module arm9_ov001; ROM address 0219a4fc. No matching claim. */
#include "types.h"
#include "deps/0219a4fc_FUN_0219a4fc.h"

void FUN_0219a4fc(void)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  
  piVar1 = DAT_0219a5a4;
  *(int *)(*DAT_0219a5a4 + 0x38) = *(int *)(*DAT_0219a5a4 + 0x38) + 1;
  uVar2 = func_0x020ae488(*(undefined4 *)(*piVar1 + 0x38));
  piVar1 = DAT_0219a5a4;
  *(undefined2 *)
   (*(int *)(*DAT_0219a5a4 + 0x1c) +
    (uint)*(ushort *)(DAT_0219a5a8 + *(int *)(*DAT_0219a5a4 + 0x40) * 2) * 0x40 + 4) = uVar2;
  *(undefined2 *)
   (*(int *)(*piVar1 + 0x1c) + (uint)*(ushort *)(DAT_0219a5ac + *(int *)(*piVar1 + 0x40) * 2) * 0x40
   + 4) = uVar2;
  *(undefined2 *)
   (*(int *)(*piVar1 + 0x1c) + (uint)*(ushort *)(DAT_0219a5b0 + *(int *)(*piVar1 + 0x40) * 2) * 0x40
   + 4) = uVar2;
  *(undefined2 *)
   (*(int *)(*piVar1 + 0x1c) + (uint)*(ushort *)(DAT_0219a5b4 + *(int *)(*piVar1 + 0x40) * 2) * 0x40
   + 4) = uVar2;
  if (*(int *)(*piVar1 + 0x38) == 5) {
    FUN_0219afc8(*(undefined4 *)(*piVar1 + 0x40));
  }
  if (9 < *(int *)(*DAT_0219a5a4 + 0x38)) {
    if ((*(int *)(*DAT_0219a5a4 + 0x40) == 2) && (iVar3 = func_0x021143b4(), iVar3 == 0)) {
      FUN_0219ade8();
      return;
    }
    *(undefined4 *)(*DAT_0219a5a4 + 0x44) =
         *(undefined4 *)(DAT_0219a5b8 + *(int *)(*DAT_0219a5a4 + 0x40) * 4);
    FUN_0219adfc();
  }
  return;
}

