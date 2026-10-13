/* Decompiled C draft; module arm9; ROM address 02113d84. No matching claim. */
#include "types.h"
#include "deps/02113d84_func_02113d84.h"

void func_02113d84(void)

{
  int *piVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  ushort *puVar6;
  ushort *puVar7;
  int iVar8;
  ushort *puVar9;
  ushort *puVar10;
  int local_34;
  ushort *local_28;
  ushort *local_24;
  ushort *local_20;
  ushort *local_1c;
  
  uVar3 = (uint)*(ushort *)(*(int *)(*piRam02113ed8 + 0x30) + 6);
  sVar2 = func_02113f1c();
  local_34 = 0;
  local_1c = puRam02113eec;
  iVar8 = 0;
  puVar6 = puRam02113ee8;
  puVar7 = puRam02113ee4;
  puVar9 = puRam02113ee0;
  puVar10 = puRam02113edc;
  do {
    *(undefined4 *)(*(int *)(*piRam02113ed8 + 0x3c) + (uint)*puVar10 * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piRam02113ed8 + 0x3c) + (uint)*puVar9 * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piRam02113ed8 + 0x3c) + (uint)*puVar7 * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piRam02113ed8 + 0x3c) + (uint)*puVar6 * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piRam02113ed8 + 0x3c) + (uVar3 + *local_1c) * 0x40) = 0;
    piVar1 = piRam02113ed8;
    puVar10 = puVar10 + 1;
    puVar9 = puVar9 + 1;
    puVar7 = puVar7 + 1;
    puVar6 = puVar6 + 1;
    local_1c = local_1c + 1;
    local_34 = local_34 + 1;
  } while (local_34 < 5);
  local_28 = puRam02113edc;
  local_24 = puRam02113ee4;
  local_20 = puRam02113ee8;
  puVar6 = puRam02113eec;
  puVar7 = puRam02113ee0;
  do {
    iVar4 = func_02113ef0((int)(short)iVar8);
    if (iVar4 != 0) {
      iVar4 = *piVar1;
      if (*(short *)(iVar4 + 0x68) == iVar8) {
        *(undefined4 *)(*(int *)(iVar4 + 0x3c) + (uint)*puVar7 * 0x40) = 1;
        iVar4 = *piVar1;
        func_02124100(*puVar6,0xe,*(undefined4 *)(iVar4 + 0x38),*(undefined4 *)(iVar4 + 0x3c),
                      *(undefined4 *)(iVar4 + 0x30));
      }
      else {
        *(undefined4 *)(*(int *)(iVar4 + 0x3c) + (uint)*local_28 * 0x40) = 1;
        iVar4 = *piVar1;
        func_02124100(*puVar6,0xf,*(undefined4 *)(iVar4 + 0x38),*(undefined4 *)(iVar4 + 0x3c),
                      *(undefined4 *)(iVar4 + 0x30));
      }
      iVar4 = func_02114398(sVar2);
      *(uint *)(*(int *)(*piVar1 + 0x3c) + (uint)*local_24 * 0x40) = (uint)(iVar4 == 0);
      uVar5 = func_02114398(sVar2);
      *(undefined4 *)(*(int *)(*piVar1 + 0x3c) + (uint)*local_20 * 0x40) = uVar5;
      *(undefined4 *)(*(int *)(*piVar1 + 0x3c) + (uVar3 + *puVar6) * 0x40) = 1;
    }
    puVar7 = puVar7 + 1;
    puVar6 = puVar6 + 1;
    local_28 = local_28 + 1;
    sVar2 = sVar2 + 1;
    local_24 = local_24 + 1;
    local_20 = local_20 + 1;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 5);
  return;
}

