/* Decompiled C draft; module arm9_ov001; ROM address 0219a77c. No matching claim. */
#include "types.h"
#include "deps/0219a77c_FUN_0219a77c.h"

void FUN_0219a77c(void)

{
  int *piVar1;
  undefined2 uVar2;
  ushort *puVar3;
  ushort *puVar4;
  ushort *puVar5;
  ushort *puVar6;
  int local_18;
  
  piVar1 = DAT_0219a7f8;
  *(int *)(*DAT_0219a7f8 + 0x38) = *(int *)(*DAT_0219a7f8 + 0x38) + 1;
  uVar2 = func_0x020ae488(*(undefined4 *)(*piVar1 + 0x38));
  piVar1 = DAT_0219a7f8;
  local_18 = 0;
  puVar3 = DAT_0219a808;
  puVar4 = DAT_0219a804;
  puVar5 = DAT_0219a800;
  puVar6 = DAT_0219a7fc;
  do {
    *(undefined2 *)(*(int *)(*piVar1 + 0x1c) + (uint)*puVar6 * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piVar1 + 0x1c) + (uint)*puVar5 * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piVar1 + 0x1c) + (uint)*puVar4 * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piVar1 + 0x1c) + (uint)*puVar3 * 0x40 + 4) = uVar2;
    puVar6 = puVar6 + 1;
    puVar5 = puVar5 + 1;
    puVar4 = puVar4 + 1;
    puVar3 = puVar3 + 1;
    local_18 = local_18 + 1;
  } while (local_18 < 3);
  if (9 < *(int *)(*piVar1 + 0x38)) {
    FUN_0219ae44();
  }
  return;
}

