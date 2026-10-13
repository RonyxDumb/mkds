/* Decompiled C draft; module arm9; ROM address 021128cc. No matching claim. */
#include "types.h"
#include "deps/021128cc_func_021128cc.h"

void func_021128cc(void)

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
  
  func_021137f4();
  piVar1 = piRam021129d4;
  *(int *)(*piRam021129d4 + 0x54) = *(int *)(*piRam021129d4 + 0x54) + 1;
  uVar2 = ComputeValueInterpolation_from_thumb(1,uRam021129d8,0,*(undefined4 *)(*piVar1 + 0x54),10);
  piVar1 = piRam021129d4;
  uVar3 = (uint)*(ushort *)(*(int *)(*piRam021129d4 + 0x30) + 6);
  *(undefined2 *)(*(int *)(*piRam021129d4 + 0x3c) + iRam021129dc) = uVar2;
  *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + iRam021129e0) = uVar2;
  *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + iRam021129e4) = uVar2;
  *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + iRam021129e8) = uVar2;
  *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + iRam021129ec) = uVar2;
  *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + (uVar3 + 5) * 0x40 + 4) = uVar2;
  local_24 = 0;
  local_18 = puRam021129fc;
  local_20 = puRam02112a00;
  puVar4 = puRam021129f8;
  puVar5 = puRam021129f4;
  puVar6 = puRam021129f0;
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
    func_02113480();
  }
  piVar1 = piRam021129d4;
  if (*(int *)(*piRam021129d4 + 0x54) == 4) {
    *(undefined4 *)(*(int *)(*piRam021129d4 + 0x3c) + iRam02112a04) = 1;
    *(undefined4 *)(*(int *)(*piVar1 + 0x3c) + iRam02112a08) = 0;
  }
  return;
}

