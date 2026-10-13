/* Decompiled C draft; module arm9; ROM address 021132e4. No matching claim. */
#include "types.h"
#include "deps/021132e4_func_021132e4.h"

void func_021132e4(void)

{
  undefined2 uVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  ushort *puVar6;
  ushort *puVar7;
  ushort *puVar8;
  int local_28;
  ushort *local_24;
  ushort *local_1c;
  
  piVar2 = piRam021133d4;
  *(undefined4 *)(*piRam021133d4 + 0x50) = 8;
  local_28 = 0;
  *(undefined4 *)(*piVar2 + 0x54) = 0;
  uVar4 = (uint)*(ushort *)(*(int *)(*piVar2 + 0x30) + 6);
  uVar1 = (undefined2)uRam021133d8;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + iRam021133dc) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + iRam021133e0) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + iRam021133e4) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + iRam021133e8) = uVar1;
  *(undefined4 *)(*(int *)(*piVar2 + 0x3c) + iRam021133ec) = 0;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + iRam021133f0) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uVar4 + 5) * 0x40 + 4) = uVar1;
  local_1c = puRam02113400;
  local_24 = puRam02113404;
  puVar6 = puRam021133fc;
  puVar7 = puRam021133f8;
  puVar8 = puRam021133f4;
  do {
    *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uint)*puVar8 * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uint)*puVar7 * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uint)*puVar6 * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uint)*local_1c * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uVar4 + *local_24) * 0x40 + 4) = uVar1;
    piVar3 = piRam021133d4;
    puVar8 = puVar8 + 1;
    puVar7 = puVar7 + 1;
    puVar6 = puVar6 + 1;
    local_1c = local_1c + 1;
    local_24 = local_24 + 1;
    local_28 = local_28 + 1;
  } while (local_28 < 5);
  iVar5 = 0;
  puVar6 = puRam02113408;
  do {
    *(undefined4 *)(*(int *)(*piVar3 + 0x3c) + (uint)*puVar6 * 0x40) = 0;
    puVar6 = puVar6 + 1;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  WriteFriendListSaveDataSection();
  return;
}

