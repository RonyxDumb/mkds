/* Decompiled C draft; module arm9_ov001; ROM address 0219a304. No matching claim. */
#include "types.h"
#include "deps/0219a304_FUN_0219a304.h"

void FUN_0219a304(void)

{
  int *piVar1;
  undefined2 uVar2;
  ushort *puVar3;
  ushort *puVar4;
  ushort *puVar5;
  ushort *puVar6;
  int local_1c;
  
  piVar1 = DAT_0219a38c;
  *(int *)(*DAT_0219a38c + 0x38) = *(int *)(*DAT_0219a38c + 0x38) + 1;
  uVar2 = func_0x020ae4c0(1,0,0xe0,*(undefined4 *)(*piVar1 + 0x38),10);
  piVar1 = DAT_0219a38c;
  local_1c = 0;
  puVar3 = DAT_0219a39c;
  puVar4 = DAT_0219a398;
  puVar5 = DAT_0219a394;
  puVar6 = DAT_0219a390;
  do {
    *(undefined2 *)(*(int *)(*piVar1 + 0x1c) + (uint)*puVar6 * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piVar1 + 0x1c) + (uint)*puVar5 * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piVar1 + 0x1c) + (uint)*puVar4 * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piVar1 + 0x1c) + (uint)*puVar3 * 0x40 + 4) = uVar2;
    puVar6 = puVar6 + 1;
    puVar5 = puVar5 + 1;
    puVar4 = puVar4 + 1;
    puVar3 = puVar3 + 1;
    local_1c = local_1c + 1;
  } while (local_1c < 3);
  if (9 < *(int *)(*piVar1 + 0x38)) {
    FUN_0219adbc();
  }
  return;
}

