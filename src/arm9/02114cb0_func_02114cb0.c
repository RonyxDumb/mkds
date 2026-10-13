/* Decompiled C draft; module arm9; ROM address 02114cb0. No matching claim. */
#include "types.h"
#include "deps/02114cb0_func_02114cb0.h"

void func_02114cb0(void)

{
  int *piVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  ushort *puVar6;
  ushort *puVar7;
  ushort *puVar8;
  int local_2c;
  ushort *local_28;
  ushort *local_24;
  ushort *local_20;
  ushort *local_18;
  
  piVar1 = piRam02114dd0;
  *(int *)(*piRam02114dd0 + 0x5c) = *(int *)(*piRam02114dd0 + 0x5c) + 1;
  uVar2 = ComputeValueInterpolation_from_thumb(1,0,uRam02114dd4,*(undefined4 *)(*piVar1 + 0x5c),10);
  uVar3 = ComputeValueInterpolation_from_thumb
                    (1,0,0xffffff40,*(undefined4 *)(*piRam02114dd0 + 0x5c),10);
  piVar1 = piRam02114dd0;
  uVar5 = (uint)*(ushort *)(*(int *)(*piRam02114dd0 + 0x30) + 6);
  *(undefined4 *)(*piRam02114dd0 + 0x70) = uVar3;
  *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + iRam02114dd8) = uVar2;
  *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + iRam02114ddc) = uVar2;
  *(short *)(*(int *)(*piVar1 + 0x3c) + (uVar5 + 5) * 0x40 + 6) = (short)uVar3;
  local_2c = 0;
  local_18 = puRam02114dec;
  local_28 = puRam02114df0;
  local_24 = puRam02114df4;
  local_20 = puRam02114df8;
  puVar6 = puRam02114de8;
  puVar7 = puRam02114de4;
  puVar8 = puRam02114de0;
  do {
    *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + (uint)*puVar8 * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + (uint)*puVar7 * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + (uint)*puVar6 * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + (uint)*local_18 * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + (uint)*local_28 * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + (uint)*local_24 * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + (uVar5 + *local_20) * 0x40 + 4) = uVar2;
    puVar8 = puVar8 + 1;
    puVar7 = puVar7 + 1;
    puVar6 = puVar6 + 1;
    local_18 = local_18 + 1;
    local_28 = local_28 + 1;
    local_24 = local_24 + 1;
    local_20 = local_20 + 1;
    local_2c = local_2c + 1;
  } while (local_2c < 5);
  if ((10 < *(int *)(*piVar1 + 0x5c)) && (iVar4 = func_02128274(), iVar4 != 0)) {
    func_02115d08();
  }
  return;
}

