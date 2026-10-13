/* Decompiled C draft; module arm9; ROM address 021188dc. No matching claim. */
#include "types.h"
#include "deps/021188dc_func_021188dc.h"

void func_021188dc(void)

{
  ushort uVar1;
  int *piVar2;
  undefined4 uVar3;
  ushort *puVar4;
  ushort *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  if (*psRam021189b0 != 2) {
    uVar1 = *(ushort *)(*(int *)(*piRam021189b4 + 4) + 6);
    iVar7 = 0;
    iVar8 = 0;
    puVar5 = puRam021189bc;
    puVar4 = puRam021189b8;
    do {
      *(undefined4 *)(*(int *)(*piRam021189b4 + 0x18) + (uint)*puVar4 * 0x40) = 0;
      *(undefined4 *)(*(int *)(*piRam021189b4 + 0x18) + ((uint)uVar1 + (uint)*puVar5) * 0x40) = 1;
      piVar2 = piRam021189b4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
      iVar7 = iVar7 + 1;
    } while (iVar7 < 4);
    iVar7 = 0;
    puVar5 = puRam021189c0;
    do {
      iVar6 = 0;
      puVar4 = puVar5;
      do {
        *(undefined4 *)(*(int *)(*piVar2 + 0x1c) + (uint)*puVar4 * 0x40) = 0;
        puVar4 = puVar4 + 1;
        iVar6 = iVar6 + 1;
      } while (iVar6 < 6);
      puVar5 = puVar5 + 6;
      iVar8 = iVar8 + 1;
    } while (iVar8 < 8);
    *(undefined4 *)(*(int *)(*piVar2 + 0x18) + iRam021189c4) = 1;
    *(undefined4 *)(*(int *)(*piVar2 + 0x18) + iRam021189c8) = 1;
    *(undefined4 *)(*(int *)(*piVar2 + 0x1c) + 0x80) = 1;
    *(undefined4 *)(*(int *)(*piVar2 + 0x1c) + 0xc0) = 1;
    piVar2 = piRam021189b4;
    puVar5 = puRam021189c0;
    do {
      *(undefined4 *)(*(int *)(*piVar2 + 0x1c) + (uint)*puVar5 * 0x40) = 1;
      puVar5 = puVar5 + 6;
      iVar7 = iVar7 + 1;
    } while (iVar7 < 8);
    iVar7 = 0;
    puVar5 = puRam021189c0;
    do {
      iVar8 = *piRam021189b4;
      uVar3 = func_02124a68(puVar5[4],*(undefined4 *)(iVar8 + 0xc),*(undefined4 *)(iVar8 + 0x10));
      func_0211ded0(iVar7,*(undefined4 *)(iVar8 + 0xc),*(undefined4 *)(iVar8 + 0x10),puVar5[4],uVar3
                    ,1);
      puVar5 = puVar5 + 6;
      iVar7 = iVar7 + 1;
    } while (iVar7 < 8);
  }
  return;
}

