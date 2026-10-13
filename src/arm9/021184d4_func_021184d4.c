/* Decompiled C draft; module arm9; ROM address 021184d4. No matching claim. */
#include "types.h"
#include "deps/021184d4_func_021184d4.h"

void func_021184d4(void)

{
  ushort uVar1;
  undefined2 uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  ushort *puVar7;
  ushort *puVar8;
  
  iVar5 = func_021185d4();
  if (iVar5 != 0) {
    iVar5 = *piRam021185b8;
    if (*(int *)(iVar5 + 0x6c) == 7) {
      *(undefined4 *)(iVar5 + 0x70) = *(undefined4 *)(iVar5 + 0x44);
      func_02118624();
    }
    else if (*psRam021185bc != 2) {
      uVar1 = *(ushort *)(*(int *)(iVar5 + 4) + 6);
      uVar6 = func_02116d10(7 - *(int *)(iVar5 + 0x6c),1);
      piVar3 = piRam021185b8;
      *(undefined4 *)(*piRam021185b8 + 0x40) = uVar6;
      uVar2 = (undefined2)uVar6;
      *(undefined2 *)(*(int *)(*piVar3 + 0x18) + iRam021185c0) = uVar2;
      *(undefined2 *)(*(int *)(*piVar3 + 0x18) + 0x86) = uVar2;
      *(undefined2 *)(*(int *)(*piVar3 + 0x18) + 0x46) = uVar2;
      *(undefined2 *)(*(int *)(*piVar3 + 0x18) + 6) = uVar2;
      iVar5 = 0;
      puVar7 = puRam021185c4;
      do {
        *(undefined2 *)(*(int *)(*piVar3 + 0x18) + (uint)*puVar7 * 0x40 + 6) = uVar2;
        piVar4 = piRam021185b8;
        puVar7 = puVar7 + 1;
        iVar5 = iVar5 + 1;
      } while (iVar5 < 8);
      iVar5 = 0;
      puVar7 = puRam021185c8;
      do {
        *(undefined2 *)(*(int *)(*piVar4 + 0x18) + (uint)*puVar7 * 0x40 + 6) = uVar2;
        piVar3 = piRam021185b8;
        puVar7 = puVar7 + 1;
        iVar5 = iVar5 + 1;
      } while (iVar5 < 4);
      iVar5 = 0;
      puVar7 = puRam021185d0;
      puVar8 = puRam021185cc;
      do {
        *(undefined2 *)(*(int *)(*piVar3 + 0x18) + (uint)*puVar8 * 0x40 + 6) = uVar2;
        *(undefined2 *)(*(int *)(*piVar3 + 0x18) + ((uint)uVar1 + (uint)*puVar7) * 0x40 + 6) = uVar2
        ;
        puVar8 = puVar8 + 1;
        puVar7 = puVar7 + 1;
        iVar5 = iVar5 + 1;
      } while (iVar5 < 4);
    }
    *(int *)(*piRam021185b8 + 0x6c) = *(int *)(*piRam021185b8 + 0x6c) + -1;
    return;
  }
  iVar5 = *piRam021185b8;
  if (*(int *)(iVar5 + 0x44) != *(int *)(iVar5 + 0x70)) {
    *(undefined4 *)(iVar5 + 0x6c) = 7;
  }
  return;
}

