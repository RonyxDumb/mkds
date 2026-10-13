/* Decompiled C draft; module arm9; ROM address 02112a0c. No matching claim. */
#include "types.h"
#include "deps/02112a0c_func_02112a0c.h"

void func_02112a0c(void)

{
  undefined2 uVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  ushort *puVar5;
  int iVar6;
  ushort *puVar7;
  int local_1c;
  
  piVar2 = piRam02112b24;
  *(int *)(*piRam02112b24 + 0x54) = *(int *)(*piRam02112b24 + 0x54) + 1;
  uVar3 = ComputeValueInterpolation_from_thumb(1,0xffffff40,0,*(undefined4 *)(*piVar2 + 0x54),10);
  piVar2 = piRam02112b24;
  *(undefined4 *)(*piRam02112b24 + 0x5c) = uVar3;
  *(undefined4 *)(*piVar2 + 100) = uVar3;
  uVar4 = (uint)*(ushort *)(*(int *)(*piVar2 + 8) + 6);
  uVar1 = (undefined2)uVar3;
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + 6) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + 0x46) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + 0x86) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + 0xc6) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + uVar4 * 0x40 + 6) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uVar4 + 1) * 0x40 + 6) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uVar4 + 0xb) * 0x40 + 6) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uVar4 + 0xc) * 0x40 + 6) = uVar1;
  local_1c = 0;
  puVar7 = puRam02112b28;
  do {
    iVar6 = 0;
    puVar5 = puVar7;
    do {
      *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uVar4 + *puVar5) * 0x40 + 6) = uVar1;
      puVar5 = puVar5 + 1;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 3);
    puVar7 = puVar7 + 3;
    local_1c = local_1c + 1;
  } while (local_1c < 3);
  uVar4 = (uint)*(ushort *)(*(int *)(*piVar2 + 0x18) + 6);
  *(undefined2 *)(*(int *)(*piVar2 + 0x24) + 0x46) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x24) + 6) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x24) + uVar4 * 0x40 + 6) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x24) + (uVar4 + 1) * 0x40 + 6) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x24) + (uVar4 + 0xe) * 0x40 + 6) = uVar1;
  piVar2 = piRam02112b24;
  iVar6 = 0;
  puVar7 = puRam02112b2c;
  do {
    *(undefined2 *)(*(int *)(*piVar2 + 0x24) + (uVar4 + *puVar7) * 0x40 + 6) = uVar1;
    puVar7 = puVar7 + 1;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0xc);
  if (9 < *(int *)(*piVar2 + 0x54)) {
    func_0211349c();
  }
  return;
}

