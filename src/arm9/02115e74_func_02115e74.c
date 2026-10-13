/* Decompiled C draft; module arm9; ROM address 02115e74. No matching claim. */
#include "types.h"
#include "deps/02115e74_func_02115e74.h"

void func_02115e74(void)

{
  undefined2 uVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  ushort *puVar6;
  int iVar7;
  ushort *puVar8;
  ushort *puVar9;
  int local_30;
  ushort *local_2c;
  ushort *local_28;
  ushort *local_24;
  ushort *local_1c;
  
  piVar2 = piRam02115fa4;
  local_30 = 0;
  *(undefined4 *)(*piRam02115fa4 + 0x58) = 0;
  *(undefined4 *)(*piVar2 + 0x5c) = 0;
  *(undefined4 *)(*piVar2 + 0x70) = 0xffffff40;
  uVar5 = (uint)*(ushort *)(*(int *)(*piVar2 + 0x30) + 6);
  uVar1 = (undefined2)uRam02115fa8;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + iRam02115fac) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + iRam02115fb0) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uVar5 + 5) * 0x40 + 6) = 0xff40;
  local_1c = puRam02115fc0;
  local_2c = puRam02115fc4;
  local_28 = puRam02115fc8;
  local_24 = puRam02115fcc;
  puVar6 = puRam02115fbc;
  puVar8 = puRam02115fb8;
  puVar9 = puRam02115fb4;
  do {
    *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uint)*puVar9 * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uint)*puVar8 * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uint)*puVar6 * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uint)*local_1c * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uint)*local_2c * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uint)*local_28 * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uVar5 + *local_24) * 0x40 + 4) = uVar1;
    puVar9 = puVar9 + 1;
    puVar8 = puVar8 + 1;
    puVar6 = puVar6 + 1;
    local_1c = local_1c + 1;
    local_2c = local_2c + 1;
    local_28 = local_28 + 1;
    local_24 = local_24 + 1;
    local_30 = local_30 + 1;
  } while (local_30 < 5);
  func_021162cc();
  uVar3 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam02115fa4 + 0x48),4);
  uVar4 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam02115fa4 + 0x44),6);
  TextSystem_DisplaySingleButtonDialog_from_thumb(uVar3,uVar4,0,1,1,1);
  piVar2 = piRam02115fa4;
  iVar7 = 0;
  puVar6 = puRam02115fd0;
  do {
    *(undefined4 *)(*(int *)(*piVar2 + 0x3c) + (uint)*puVar6 * 0x40) = 0;
    puVar6 = puVar6 + 1;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 2);
  return;
}

