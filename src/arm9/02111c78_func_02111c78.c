/* Decompiled C draft; module arm9; ROM address 02111c78. No matching claim. */
#include "types.h"
#include "deps/02111c78_func_02111c78.h"

void func_02111c78(void)

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
  piVar1 = piRam02111d80;
  *(int *)(*piRam02111d80 + 0x54) = *(int *)(*piRam02111d80 + 0x54) + 1;
  uVar2 = ComputeValueInterpolation_from_thumb(1,uRam02111d84,0,*(undefined4 *)(*piVar1 + 0x54),10);
  piVar1 = piRam02111d80;
  uVar3 = (uint)*(ushort *)(*(int *)(*piRam02111d80 + 0x30) + 6);
  *(undefined2 *)(*(int *)(*piRam02111d80 + 0x3c) + iRam02111d88) = uVar2;
  *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + iRam02111d8c) = uVar2;
  *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + iRam02111d90) = uVar2;
  *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + iRam02111d94) = uVar2;
  *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + iRam02111d98) = uVar2;
  *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + (uVar3 + 5) * 0x40 + 4) = uVar2;
  local_24 = 0;
  local_18 = puRam02111da8;
  local_20 = puRam02111dac;
  puVar4 = puRam02111da4;
  puVar5 = puRam02111da0;
  puVar6 = puRam02111d9c;
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
    func_0211346c();
  }
  piVar1 = piRam02111d80;
  if (*(int *)(*piRam02111d80 + 0x54) == 2) {
    *(undefined4 *)(*(int *)(*piRam02111d80 + 0x3c) + iRam02111db0) = 1;
    *(undefined4 *)(*(int *)(*piVar1 + 0x3c) + iRam02111db4) = 0;
  }
  return;
}

