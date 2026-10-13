/* Decompiled C draft; module arm9; ROM address 02119544. No matching claim. */
#include "types.h"
#include "deps/02119544_func_02119544.h"

void func_02119544(void)

{
  ushort uVar1;
  undefined2 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  ushort *puVar7;
  int iVar8;
  ushort *puVar9;
  
  piVar3 = piRam021196b4;
  *(int *)(*piRam021196b4 + 0x3c) = *(int *)(*piRam021196b4 + 0x3c) + 1;
  if (*psRam021196b8 != 2) {
    ComputeValueInterpolation_from_thumb(1,uRam021196bc,0,*(undefined4 *)(*piVar3 + 0x3c),10);
    iVar4 = ComputeValueInterpolation_from_thumb
                      (1,0xffffff40,0,*(undefined4 *)(*piRam021196b4 + 0x3c),10);
    iVar5 = func_020cccb4();
    piVar3 = piRam021196b4;
    if (iVar5 != 0x1a) {
      uVar6 = (uint)*(ushort *)(*(int *)(*piRam021196b4 + 4) + 6);
      *(int *)(*piRam021196b4 + 0x44) = iVar4;
      uVar2 = (undefined2)iVar4;
      *(undefined2 *)(*(int *)(*piVar3 + 0x1c) + 6) = uVar2;
      *(undefined2 *)(*(int *)(*piVar3 + 0x1c) + 0x86) = uVar2;
      *(undefined2 *)(*(int *)(*piVar3 + 0x1c) + 0x46) = uVar2;
      *(undefined2 *)(*(int *)(*piVar3 + 0x1c) + iRam021196c0) = uVar2;
      *(undefined2 *)(*(int *)(*piVar3 + 0x1c) + 0xc6) = uVar2;
      *(undefined2 *)(*(int *)(*piVar3 + 0x1c) + iRam021196c4) = uVar2;
      *(undefined2 *)(*(int *)(*piVar3 + 0x1c) + uVar6 * 0x40 + 6) = uVar2;
      *(undefined2 *)(*(int *)(*piVar3 + 0x1c) + (uVar6 + 1) * 0x40 + 6) = uVar2;
      *(undefined2 *)(*(int *)(*piVar3 + 0x1c) + (uVar6 + 2) * 0x40 + 6) = uVar2;
      *(undefined2 *)(*(int *)(*piVar3 + 0x1c) + (uVar6 + 3) * 0x40 + 6) = uVar2;
      *(undefined2 *)(*(int *)(*piVar3 + 0x1c) + (uVar6 + 4) * 0x40 + 6) = uVar2;
      *(undefined2 *)(*(int *)(*piVar3 + 0x1c) + (uVar6 + 5) * 0x40 + 6) = uVar2;
    }
    iVar5 = func_020cccb4();
    piVar3 = piRam021196b4;
    if (iVar5 == 0x1a) {
      uVar1 = *(ushort *)(*(int *)(*piRam021196b4 + 0x10) + 6);
      iVar5 = iVar4 + -0x20;
      *(int *)(*piRam021196b4 + 0x48) = iVar5;
      uVar2 = (undefined2)((uint)(iVar5 * 0x10000) >> 0x10);
      *(undefined2 *)(*(int *)(*piVar3 + 0x20) + iRam021196c8) = uVar2;
      *(undefined2 *)(*(int *)(*piVar3 + 0x20) + iRam021196cc) = uVar2;
      *(undefined2 *)(*(int *)(*piVar3 + 0x20) + 0x86) = uVar2;
      *(undefined2 *)(*(int *)(*piVar3 + 0x20) + 0x46) = uVar2;
      *(undefined2 *)(*(int *)(*piVar3 + 0x20) + 6) = uVar2;
      iVar8 = 0;
      puVar7 = puRam021196d0;
      do {
        *(short *)(*(int *)(*piVar3 + 0x20) + (uint)*puVar7 * 0x40 + 6) = (short)iVar5;
        puVar7 = puVar7 + 1;
        iVar8 = iVar8 + 1;
      } while (iVar8 < 8);
      iVar5 = 0;
      puVar7 = puRam021196d8;
      puVar9 = puRam021196d4;
      do {
        uVar2 = (undefined2)((uint)((iVar4 + -0x20) * 0x10000) >> 0x10);
        *(undefined2 *)(*(int *)(*piRam021196b4 + 0x20) + (uint)*puVar9 * 0x40 + 6) = uVar2;
        *(undefined2 *)(*(int *)(*piRam021196b4 + 0x20) + ((uint)uVar1 + (uint)*puVar7) * 0x40 + 6)
             = uVar2;
        puVar9 = puVar9 + 1;
        puVar7 = puVar7 + 1;
        iVar5 = iVar5 + 1;
      } while (iVar5 < 4);
    }
  }
  if (9 < *(int *)(*piRam021196b4 + 0x3c)) {
    func_02119bf0();
  }
  return;
}

