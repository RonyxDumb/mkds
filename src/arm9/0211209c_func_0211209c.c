/* Decompiled C draft; module arm9; ROM address 0211209c. No matching claim. */
#include "types.h"
#include "deps/0211209c_func_0211209c.h"

void func_0211209c(void)

{
  int *piVar1;
  undefined2 uVar2;
  uint uVar3;
  ushort *puVar4;
  ushort *puVar5;
  ushort *puVar6;
  int local_24;
  ushort *local_20;
  ushort *local_18;
  
  piVar1 = piRam0211219c;
  *(int *)(*piRam0211219c + 0x54) = *(int *)(*piRam0211219c + 0x54) + 1;
  uVar2 = ComputeValueInterpolation_from_thumb(1,0,uRam021121a0,*(undefined4 *)(*piVar1 + 0x54),10);
  piVar1 = piRam0211219c;
  uVar3 = (uint)*(ushort *)(*(int *)(*piRam0211219c + 0x30) + 6);
  *(undefined2 *)(*(int *)(*piRam0211219c + 0x3c) + iRam021121a4) = uVar2;
  *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + iRam021121a8) = uVar2;
  *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + iRam021121ac) = uVar2;
  *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + iRam021121b0) = uVar2;
  *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + iRam021121b4) = uVar2;
  *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + (uVar3 + 5) * 0x40 + 4) = uVar2;
  local_24 = 0;
  local_18 = puRam021121c4;
  local_20 = puRam021121c8;
  puVar4 = puRam021121c0;
  puVar5 = puRam021121bc;
  puVar6 = puRam021121b8;
  do {
    *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + (uint)*puVar6 * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + (uint)*puVar5 * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + (uint)*puVar4 * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + (uint)*local_18 * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + (uVar3 + *local_20) * 0x40 + 4) = uVar2;
    puVar6 = puVar6 + 1;
    puVar5 = puVar5 + 1;
    puVar4 = puVar4 + 1;
    local_18 = local_18 + 1;
    local_20 = local_20 + 1;
    local_24 = local_24 + 1;
  } while (local_24 < 5);
  if (9 < *(int *)(*piVar1 + 0x54)) {
    func_021132e4();
  }
  piVar1 = piRam0211219c;
  if (*(int *)(*piRam0211219c + 0x54) == 6) {
    *(undefined4 *)(*(int *)(*piRam0211219c + 0x3c) + iRam021121cc) = 0;
    *(undefined4 *)(*(int *)(*piVar1 + 0x3c) + iRam021121d0) = 0;
  }
  return;
}

