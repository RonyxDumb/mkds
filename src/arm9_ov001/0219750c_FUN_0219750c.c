/* Decompiled C draft; module arm9_ov001; ROM address 0219750c. No matching claim. */
#include "types.h"
#include "deps/0219750c_FUN_0219750c.h"

void FUN_0219750c(int param_1)

{
  ushort uVar1;
  int *piVar2;
  ushort *puVar3;
  int iVar4;
  uint uVar5;
  
  puVar3 = DAT_021975dc;
  piVar2 = DAT_021975d8;
  if (param_1 == 0) {
    *(undefined4 *)(*(int *)(*DAT_021975d8 + 0x38) + (uint)*DAT_021975dc * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar2 + 0x38) + (uint)puVar3[1] * 0x40) = 0;
    uVar5 = (uint)*(ushort *)(*(int *)(*piVar2 + 8) + 6);
    uVar1 = *DAT_021975e0;
    *(undefined4 *)(*(int *)(*piVar2 + 0x38) + (uVar5 + uVar1) * 0x40) = 1;
    iVar4 = *piVar2;
    func_0x02124224(0,(uint)uVar1,*(undefined4 *)(iVar4 + 0x10),DAT_021975e4,
                    *(undefined4 *)(iVar4 + 8),*(undefined4 *)(iVar4 + 0x38),7);
    *(undefined4 *)(*(int *)(*DAT_021975d8 + 0x38) + (uVar5 + *DAT_021975e8) * 0x40) = 0;
    return;
  }
  *(undefined4 *)(*(int *)(*DAT_021975d8 + 0x3c) + (uint)DAT_021975dc[param_1 * 2] * 0x40) = 0;
  *(undefined4 *)(*(int *)(*piVar2 + 0x3c) + (uint)*(ushort *)(DAT_021975ec + param_1 * 4) * 0x40) =
       0;
  uVar1 = DAT_021975e0[param_1];
  uVar5 = (uint)*(ushort *)(*(int *)(*piVar2 + 0x1c) + 6);
  *(undefined4 *)(*(int *)(*piVar2 + 0x3c) + (uVar5 + uVar1) * 0x40) = 1;
  iVar4 = *piVar2;
  func_0x02124224(1,(uint)uVar1,*(undefined4 *)(iVar4 + 0x24),DAT_021975f0,
                  *(undefined4 *)(iVar4 + 0x1c),*(undefined4 *)(iVar4 + 0x3c),7);
  *(undefined4 *)(*(int *)(*DAT_021975d8 + 0x3c) + (uVar5 + DAT_021975e8[param_1]) * 0x40) = 0;
  return;
}

