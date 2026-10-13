/* Decompiled C draft; module arm9; ROM address 020fa13c. No matching claim. */
#include "types.h"
#include "deps/020fa13c_MaybeLoadSlotListAndRacerPrs_from_thumb.h"

void MaybeLoadSlotListAndRacerPrs_from_thumb(void)

{
  byte bVar1;
  ushort *puVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined4 local_1c [2];
  
  GetActiveExecutionContext();
  uVar4 = ExecutionContext_GetHeapHandle();
  local_1c[0] = 0;
  Maybe_Item_ItemSlotList();
  func_020f82e8(1);
  func_020f82c4(1);
  func_020f82a4(1);
  func_020f4b8c();
  func_020f1a24();
  func_020f73a4();
  func_020f357c();
  bVar1 = *(byte *)(*piRam020fa274 + iRam020fa278);
  *puRam020fa27c = (ushort)bVar1;
  iVar5 = Mem_AllocateHeap(uVar4,iRam020fa280 * (uint)bVar1);
  piVar3 = piRam020fa284;
  *piRam020fa284 = iVar5;
  puVar2 = puRam020fa27c;
  uVar7 = 0;
  if (*puRam020fa27c != 0) {
    iVar5 = 0;
    do {
      StructPR_Load_from_thumb(*piVar3 + iVar5,uVar7 & 0xffff);
      iVar5 = iVar5 + iRam020fa280;
      uVar7 = uVar7 + 1;
    } while ((int)uVar7 < (int)(uint)*puVar2);
  }
  iVar5 = Mem_AllocateHeap(uVar4,uRam020fa288);
  piVar3 = piRam020fa28c;
  *piRam020fa28c = iVar5;
  iVar5 = 0;
  do {
    func_020f02c0(*piVar3 + iVar5 * 0x44,iVar5,local_1c);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0xe);
  LoadItems_from_thumb();
  if (*(int *)(*piRam020fa274 + 8) == 5) {
    func_020fe46c();
    func_020fe450();
  }
  puVar2 = puRam020fa27c;
  if ((*(int *)(*piRam020fa274 + 8) == 1) && (uVar7 = 0, *puRam020fa27c != 0)) {
    iVar5 = 0;
    do {
      iVar8 = *piRam020fa284 + iVar5 + 0x30;
      func_020f47e4(iVar8,5);
      iVar6 = GetDriverKartIndexMod3(uVar7 & 0xffff);
      if (iVar6 == 0) {
        func_020f4754(iVar8,1);
      }
      else if (iVar6 == 1) {
        func_020f4754(iVar8,2);
      }
      iVar5 = iVar5 + iRam020fa280;
      uVar7 = uVar7 + 1;
    } while ((int)uVar7 < (int)(uint)*puVar2);
  }
  GetActiveExecutionContext();
  uVar4 = ExecutionContext_GetHeapHandle();
  uVar4 = Mem_AllocateHeap(uVar4,0x40);
  *puRam020fa290 = uVar4;
  func_020fa294();
  func_02102674();
  func_02103468();
  func_02104970();
  return;
}

