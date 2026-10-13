/* Decompiled C draft; module arm9; ROM address 020f7ec8. No matching claim. */
#include "types.h"
#include "deps/020f7ec8_Maybe_Item_ItemSlotList.h"

void Maybe_Item_ItemSlotList(void)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  short *psVar6;
  short *psVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar3 = FindFileBuffer_MAR_EFT_from_thumb(DAT_020f809c);
  switch(*(undefined4 *)(*DAT_020f80a0 + 8)) {
  case 0:
  case 1:
  case 4:
    uVar4 = func_020f8148(DAT_020f80a4,(byte *)(uintptr_t)(iVar3 + 1));
    func_020f8148((uint *)(uintptr_t)(DAT_020f80a8),(byte *)(uintptr_t)(uVar4));
    func_020f813c();
    func_020f813c();
    func_020f813c();
    uVar4 = func_020f813c();
    func_020f8148((uint *)(uintptr_t)(DAT_020f80ac),(byte *)(uintptr_t)(uVar4));
    break;
  case 2:
    func_020f813c((byte *)(uintptr_t)(iVar3 + 1));
    func_020f813c();
    func_020f813c();
    func_020f813c();
    func_020f813c();
    uVar4 = func_020f813c();
    uVar4 = func_020f8148((uint *)(uintptr_t)(DAT_020f80ac),(byte *)(uintptr_t)(uVar4));
    if ((*(int *)(*DAT_020f80a0 + 0x18) == 0) || (*(int *)(*DAT_020f80a0 + 0x18) != 1)) {
      uVar4 = func_020f8148(DAT_020f80a4);
      func_020f8148(DAT_020f80a8,uVar4);
    }
    else {
      func_020f813c(uVar4,uVar4);
      uVar4 = func_020f813c();
      uVar4 = func_020f8148(DAT_020f80a4,uVar4);
      func_020f8148(DAT_020f80a8,uVar4);
    }
    break;
  case 3:
    func_020f813c(iVar3 + 1);
    uVar4 = func_020f813c();
    uVar4 = func_020f8148(DAT_020f80a4,uVar4);
    func_020f8148(DAT_020f80a8,uVar4);
    func_020f813c();
    uVar4 = func_020f813c();
    func_020f8148(DAT_020f80ac,uVar4);
    if (*(int *)(*DAT_020f80a0 + 0x14) == 0) {
      func_020f80c0(DAT_020f80a4,*(undefined1 *)(*DAT_020f80a0 + DAT_020f80b0));
      func_020f80c0(DAT_020f80a8,*(undefined1 *)(*DAT_020f80a0 + DAT_020f80b0));
    }
    break;
  case 5:
    func_020f813c(iVar3 + 1);
    func_020f813c();
    func_020f813c();
    uVar4 = func_020f813c();
    uVar4 = func_020f8148(DAT_020f80a4,uVar4);
    uVar4 = func_020f8148(DAT_020f80a8,uVar4);
    func_020f8148(DAT_020f80ac,uVar4);
    if (*(int *)(*DAT_020f80a0 + 0x14) == 0) {
      func_020f80c0(DAT_020f80a4,*(undefined1 *)(*DAT_020f80a0 + DAT_020f80b0));
      func_020f80c0(DAT_020f80a8,*(undefined1 *)(*DAT_020f80a0 + DAT_020f80b0));
    }
  }
  iVar8 = *DAT_020f80a4;
  iVar10 = 0;
  iVar11 = DAT_020f80a4[1];
  iVar3 = *(int *)(DAT_020f80a8 + 4);
  do {
    *(undefined4 *)(DAT_020f80b4 + iVar10 * 4) = 0x12;
    iVar9 = 0;
    if (0 < iVar8) {
      psVar7 = (short *)(iVar11 + iVar10 * 2);
      psVar6 = (short *)(iVar3 + iVar10 * 2);
      piVar5 = (int *)(DAT_020f80b4 + iVar10 * 4);
      do {
        if ((*psVar7 != 0) || (*psVar6 != 0)) {
          *piVar5 = iVar10;
        }
        psVar7 = psVar7 + 0x12;
        psVar6 = psVar6 + 0x12;
        iVar9 = iVar9 + 1;
      } while (iVar9 < iVar8);
    }
    puVar2 = DAT_020f80b8;
    iVar10 = iVar10 + 1;
  } while (iVar10 < 0x12);
  iVar8 = 0;
  *DAT_020f80b8 = 0;
  iVar3 = DAT_020f80b4;
  do {
    if (*(int *)(iVar3 + iVar8 * 4) != 0x12) {
      uVar1 = *puVar2;
      *puVar2 = uVar1 + 1;
      *(undefined4 *)(iVar3 + (uint)uVar1 * 4) = *(undefined4 *)(iVar3 + iVar8 * 4);
    }
    iVar8 = iVar8 + 1;
  } while (iVar8 < 0x12);
  *DAT_020f80bc = 0;
  return;
}

