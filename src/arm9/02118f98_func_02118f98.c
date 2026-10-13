/* Decompiled C draft; module arm9; ROM address 02118f98. No matching claim. */
#include "types.h"
#include "deps/02118f98_func_02118f98.h"

void func_02118f98(void)

{
  ushort uVar1;
  undefined2 uVar2;
  bool bVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  ushort *puVar9;
  ushort *puVar10;
  
  piVar4 = piRam02119114;
  *(int *)(*piRam02119114 + 0x3c) = *(int *)(*piRam02119114 + 0x3c) + 1;
  if (*psRam02119118 != 2) {
    if (*(int *)(*piVar4 + 0x40) == 0) {
      if (*(int *)(*piVar4 + 0x6c) == 1) {
        iVar5 = func_0211e130();
        if (iVar5 == 0) {
          bVar3 = false;
        }
        else {
          bVar3 = true;
        }
      }
      else {
        bVar3 = true;
      }
    }
    else {
      bVar3 = true;
    }
    ComputeValueInterpolation_from_thumb(1,0,uRam0211911c,*(undefined4 *)(*piRam02119114 + 0x3c),10)
    ;
    iVar5 = ComputeValueInterpolation_from_thumb
                      (1,0,0xffffff40,*(undefined4 *)(*piRam02119114 + 0x3c),10);
    piVar4 = piRam02119114;
    if (bVar3) {
      uVar6 = (uint)*(ushort *)(*(int *)(*piRam02119114 + 4) + 6);
      *(int *)(*piRam02119114 + 0x44) = iVar5;
      uVar2 = (undefined2)iVar5;
      *(undefined2 *)(*(int *)(*piVar4 + 0x1c) + 6) = uVar2;
      *(undefined2 *)(*(int *)(*piVar4 + 0x1c) + 0x86) = uVar2;
      *(undefined2 *)(*(int *)(*piVar4 + 0x1c) + 0x46) = uVar2;
      *(undefined2 *)(*(int *)(*piVar4 + 0x1c) + iRam02119120) = uVar2;
      *(undefined2 *)(*(int *)(*piVar4 + 0x1c) + 0xc6) = uVar2;
      *(undefined2 *)(*(int *)(*piVar4 + 0x1c) + iRam02119124) = uVar2;
      *(undefined2 *)(*(int *)(*piVar4 + 0x1c) + uVar6 * 0x40 + 6) = uVar2;
      *(undefined2 *)(*(int *)(*piVar4 + 0x1c) + (uVar6 + 1) * 0x40 + 6) = uVar2;
      *(undefined2 *)(*(int *)(*piVar4 + 0x1c) + (uVar6 + 2) * 0x40 + 6) = uVar2;
      *(undefined2 *)(*(int *)(*piVar4 + 0x1c) + (uVar6 + 3) * 0x40 + 6) = uVar2;
      *(undefined2 *)(*(int *)(*piVar4 + 0x1c) + (uVar6 + 4) * 0x40 + 6) = uVar2;
      *(undefined2 *)(*(int *)(*piVar4 + 0x1c) + (uVar6 + 5) * 0x40 + 6) = uVar2;
    }
    piVar4 = piRam02119114;
    iVar7 = *piRam02119114;
    if (*(int *)(iVar7 + 0x6c) != 2) {
      uVar1 = *(ushort *)(*(int *)(iVar7 + 0x10) + 6);
      iVar8 = iVar5 + -0x20;
      *(int *)(iVar7 + 0x48) = iVar8;
      uVar2 = (undefined2)((uint)(iVar8 * 0x10000) >> 0x10);
      *(undefined2 *)(*(int *)(*piVar4 + 0x20) + iRam02119128) = uVar2;
      *(undefined2 *)(*(int *)(*piVar4 + 0x20) + iRam0211912c) = uVar2;
      *(undefined2 *)(*(int *)(*piVar4 + 0x20) + 0x86) = uVar2;
      *(undefined2 *)(*(int *)(*piVar4 + 0x20) + 0x46) = uVar2;
      *(undefined2 *)(*(int *)(*piVar4 + 0x20) + 6) = uVar2;
      iVar7 = 0;
      puVar9 = puRam02119130;
      do {
        *(short *)(*(int *)(*piVar4 + 0x20) + (uint)*puVar9 * 0x40 + 6) = (short)iVar8;
        puVar9 = puVar9 + 1;
        iVar7 = iVar7 + 1;
      } while (iVar7 < 8);
      iVar7 = 0;
      puVar9 = puRam02119138;
      puVar10 = puRam02119134;
      do {
        uVar2 = (undefined2)((uint)((iVar5 + -0x20) * 0x10000) >> 0x10);
        *(undefined2 *)(*(int *)(*piRam02119114 + 0x20) + (uint)*puVar10 * 0x40 + 6) = uVar2;
        *(undefined2 *)(*(int *)(*piRam02119114 + 0x20) + ((uint)uVar1 + (uint)*puVar9) * 0x40 + 6)
             = uVar2;
        puVar10 = puVar10 + 1;
        puVar9 = puVar9 + 1;
        iVar7 = iVar7 + 1;
      } while (iVar7 < 4);
    }
  }
  return;
}

