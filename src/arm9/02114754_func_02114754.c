/* Decompiled C draft; module arm9; ROM address 02114754. No matching claim. */
#include "types.h"
#include "deps/02114754_func_02114754.h"

void func_02114754(void)

{
  int *piVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  uint uVar4;
  ushort *puVar5;
  ushort *puVar6;
  ushort *puVar7;
  int local_2c;
  ushort *local_28;
  ushort *local_24;
  ushort *local_20;
  ushort *local_18;
  
  piVar1 = piRam02114870;
  *(int *)(*piRam02114870 + 0x5c) = *(int *)(*piRam02114870 + 0x5c) + 1;
  uVar2 = ComputeValueInterpolation_from_thumb(1,0,uRam02114874,*(undefined4 *)(*piVar1 + 0x5c),10);
  uVar3 = ComputeValueInterpolation_from_thumb
                    (1,0,0xffffff40,*(undefined4 *)(*piRam02114870 + 0x5c),10);
  piVar1 = piRam02114870;
  uVar4 = (uint)*(ushort *)(*(int *)(*piRam02114870 + 0x30) + 6);
  *(undefined4 *)(*piRam02114870 + 0x70) = uVar3;
  *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + iRam02114878) = uVar2;
  *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + iRam0211487c) = uVar2;
  *(short *)(*(int *)(*piVar1 + 0x3c) + (uVar4 + 5) * 0x40 + 6) = (short)uVar3;
  local_2c = 0;
  local_18 = puRam0211488c;
  local_28 = puRam02114890;
  local_24 = puRam02114894;
  local_20 = puRam02114898;
  puVar5 = puRam02114888;
  puVar6 = puRam02114884;
  puVar7 = puRam02114880;
  do {
    *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + (uint)*puVar7 * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + (uint)*puVar6 * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + (uint)*puVar5 * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + (uint)*local_18 * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + (uint)*local_28 * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + (uint)*local_24 * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + (uVar4 + *local_20) * 0x40 + 4) = uVar2;
    puVar7 = puVar7 + 1;
    puVar6 = puVar6 + 1;
    puVar5 = puVar5 + 1;
    local_18 = local_18 + 1;
    local_28 = local_28 + 1;
    local_24 = local_24 + 1;
    local_20 = local_20 + 1;
    local_2c = local_2c + 1;
  } while (local_2c < 5);
  if (9 < *(int *)(*piVar1 + 0x5c)) {
    func_02111488(*(undefined4 *)(*piVar1 + 0xa0));
  }
  return;
}

