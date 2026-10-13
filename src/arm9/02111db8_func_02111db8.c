/* Decompiled C draft; module arm9; ROM address 02111db8. No matching claim. */
#include "types.h"
#include "deps/02111db8_func_02111db8.h"

void func_02111db8(void)

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
  
  piVar1 = piRam02111ebc;
  *(int *)(*piRam02111ebc + 0x54) = *(int *)(*piRam02111ebc + 0x54) + 1;
  uVar2 = ComputeValueInterpolation_from_thumb(1,0,uRam02111ec0,*(undefined4 *)(*piVar1 + 0x54),10);
  piVar1 = piRam02111ebc;
  uVar3 = (uint)*(ushort *)(*(int *)(*piRam02111ebc + 0x30) + 6);
  *(undefined2 *)(*(int *)(*piRam02111ebc + 0x3c) + iRam02111ec4) = uVar2;
  *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + iRam02111ec8) = uVar2;
  *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + iRam02111ecc) = uVar2;
  *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + iRam02111ed0) = uVar2;
  *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + iRam02111ed4) = uVar2;
  *(undefined2 *)(*(int *)(*piVar1 + 0x3c) + (uVar3 + 5) * 0x40 + 4) = uVar2;
  local_24 = 0;
  local_18 = puRam02111ee4;
  local_20 = puRam02111ee8;
  puVar4 = puRam02111ee0;
  puVar5 = puRam02111edc;
  puVar6 = puRam02111ed8;
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
    func_02111488(*(undefined4 *)(*piVar1 + 0x90));
  }
  piVar1 = piRam02111ebc;
  if (*(int *)(*piRam02111ebc + 0x54) == 6) {
    *(undefined4 *)(*(int *)(*piRam02111ebc + 0x3c) + iRam02111eec) = 0;
    *(undefined4 *)(*(int *)(*piVar1 + 0x3c) + iRam02111ef0) = 0;
  }
  return;
}

