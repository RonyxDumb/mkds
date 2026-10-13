/* Decompiled C draft; module arm9; ROM address 02111f54. No matching claim. */
#include "types.h"
#include "deps/02111f54_func_02111f54.h"

void func_02111f54(void)

{
  undefined2 uVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  ushort *puVar6;
  ushort *puVar7;
  int local_1c;
  
  iVar3 = func_0211145c();
  if ((iVar3 == -1) && (*(int *)(*piRam02112090 + 0x90) == 6)) {
    func_02111450(0xc);
  }
  piVar2 = piRam02112090;
  *(int *)(*piRam02112090 + 0x54) = *(int *)(*piRam02112090 + 0x54) + 1;
  uVar4 = ComputeValueInterpolation_from_thumb(1,0,0xffffff40,*(undefined4 *)(*piVar2 + 0x54),10);
  piVar2 = piRam02112090;
  *(undefined4 *)(*piRam02112090 + 0x5c) = uVar4;
  *(undefined4 *)(*piVar2 + 100) = uVar4;
  uVar5 = (uint)*(ushort *)(*(int *)(*piVar2 + 8) + 6);
  uVar1 = (undefined2)uVar4;
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + 6) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + 0x46) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + 0x86) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + 0xc6) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + uVar5 * 0x40 + 6) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uVar5 + 1) * 0x40 + 6) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uVar5 + 0xb) * 0x40 + 6) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uVar5 + 0xc) * 0x40 + 6) = uVar1;
  local_1c = 0;
  puVar7 = puRam02112094;
  do {
    iVar3 = 0;
    puVar6 = puVar7;
    do {
      *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uVar5 + *puVar6) * 0x40 + 6) = uVar1;
      puVar6 = puVar6 + 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 3);
    puVar7 = puVar7 + 3;
    local_1c = local_1c + 1;
  } while (local_1c < 3);
  uVar5 = (uint)*(ushort *)(*(int *)(*piVar2 + 0x18) + 6);
  *(undefined2 *)(*(int *)(*piVar2 + 0x24) + 0x46) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x24) + 6) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x24) + uVar5 * 0x40 + 6) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x24) + (uVar5 + 1) * 0x40 + 6) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x24) + (uVar5 + 0xe) * 0x40 + 6) = uVar1;
  piVar2 = piRam02112090;
  iVar3 = 0;
  puVar7 = puRam02112098;
  do {
    *(undefined2 *)(*(int *)(*piVar2 + 0x24) + (uVar5 + *puVar7) * 0x40 + 6) = uVar1;
    puVar7 = puVar7 + 1;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0xc);
  iVar3 = *piVar2;
  if (9 < *(int *)(iVar3 + 0x54)) {
    if (*(int *)(iVar3 + 0x90) != 6) {
      func_02111488();
    }
  }
  return;
}

