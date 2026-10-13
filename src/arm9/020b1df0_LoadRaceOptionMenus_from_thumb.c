/* Decompiled C draft; module arm9; ROM address 020b1df0. No matching claim. */
#include "types.h"
#include "deps/020b1df0_LoadRaceOptionMenus_from_thumb.h"

void LoadRaceOptionMenus_from_thumb(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 *puVar11;
  uint uVar12;
  undefined4 local_30 [7];
  
  uVar4 = GetActiveExecutionContextHeapHandle_3();
  puVar5 = (undefined4 *)Mem_AllocateHeap(uVar4,DAT_020b2198);
  piVar1 = DAT_020b219c;
  *DAT_020b219c = (int)puVar5;
  *puVar5 = 0;
  *(undefined4 *)(*piVar1 + 4) = 0;
  *(undefined4 *)(*piVar1 + 8) = 0;
  *(undefined4 *)(*piVar1 + 0xc) = 0;
  *(undefined4 *)(*piVar1 + 0x14) = 0;
  *(undefined4 *)(*piVar1 + 0x10) = 0;
  *(undefined4 *)(*piVar1 + 0x1c) = 0;
  iVar6 = GetRaceMode();
  if (iVar6 == 4) {
    uVar4 = MaybeAllMissionStagesBeatenWithStarRank_from_thumb();
    *(undefined4 *)(*DAT_020b219c + 0x20) = uVar4;
  }
  else {
    *(undefined4 *)(*DAT_020b219c + 0x20) = 0;
  }
  piVar1 = DAT_020b219c;
  *(undefined4 *)(*DAT_020b219c + 0x2c) = 0;
  *(undefined4 *)(*piVar1 + 0x30) = 0;
  func_020b3008();
  ClearRaceOptionMenuEntries_from_thumb();
  uVar4 = GetRaceMode();
  switch(uVar4) {
  case 0:
    func_020b31b8(0,0);
    func_020b31b8(0,9);
    iVar6 = func_020b250c();
    if (iVar6 == 0) {
      func_020b31b8(1,2);
      func_020b31b8(1,8);
      func_020b31b8(1,9);
    }
    else {
      func_020b31b8(1,7);
      func_020b31b8(1,8);
    }
    iVar6 = func_020b250c();
    if (iVar6 == 0) {
      func_020b31b8(3,0);
      func_020b31b8(3,2);
      func_020b31b8(3,8);
      func_020b31b8(3,9);
    }
    else {
      func_020b31b8(3,0);
      func_020b31b8(3,7);
      func_020b31b8(3,8);
    }
    break;
  case 1:
    func_020b31b8(0,0);
    func_020b31b8(0,3);
    func_020b31b8(0,4);
    func_020b31b8(0,5);
    func_020b31b8(0,9);
    func_020b31b8(1,1);
    func_020b31b8(1,4);
    func_020b31b8(1,5);
    func_020b31b8(1,8);
    func_020b31b8(1,9);
    func_020b31b8(3,0);
    func_020b31b8(3,1);
    func_020b31b8(3,4);
    func_020b31b8(3,5);
    func_020b31b8(3,8);
    func_020b31b8(3,9);
    break;
  case 2:
    func_020b31b8(0,0);
    func_020b31b8(0,9);
    func_020b31b8(1,2);
    func_020b31b8(1,9);
    func_020b31b8(2,7);
    break;
  case 3:
    func_020b31b8(0,0);
    func_020b31b8(0,9);
    func_020b31b8(1,2);
    func_020b31b8(1,9);
    func_020b31b8(2,7);
    break;
  case 4:
    func_020b31b8(0,0);
    func_020b31b8(0,3);
    func_020b31b8(0,6);
    func_020b31b8(0,9);
    iVar6 = IsCurrentMission_Boss6OrBoss7_from_thumb();
    if (iVar6 == 0) {
      func_020b31b8(1,1);
      func_020b31b8(1,6);
      func_020b31b8(1,9);
      func_020b31b8(2,6);
      func_020b31b8(2,1);
      func_020b31b8(2,9);
    }
    else {
      iVar6 = IsCurrentMissionLevelStageBeaten_from_thumb();
      if (iVar6 == 0) {
        func_020b31b8(1,1);
        func_020b31b8(1,6);
        func_020b31b8(1,9);
        func_020b31b8(2,6);
        func_020b31b8(2,1);
        func_020b31b8(2,9);
      }
      else {
        func_020b31b8(1,1);
        func_020b31b8(1,6);
        func_020b31b8(1,9);
        func_020b31b8(2,6);
        func_020b31b8(2,1);
        func_020b31b8(2,10);
        func_020b31b8(2,9);
      }
    }
    break;
  case 5:
    func_020b31b8(0,0);
    iVar6 = func_020b24f8();
    if (iVar6 == 4) {
      func_020b31b8(1,7);
    }
    else {
      func_020b31b8(1,2);
    }
  }
  iVar6 = GetDisplayMode_0();
  if ((iVar6 == 3) || (iVar6 = GetDisplayMode_0(), iVar6 == 6)) {
    piVar1 = DAT_020b2468;
    *(undefined4 *)(*DAT_020b2468 + DAT_020b248c) = 0;
    *(undefined4 *)(*piVar1 + DAT_020b2490) = 0;
    *(undefined4 *)(*piVar1 + DAT_020b2474) = 0;
    *(undefined4 *)(*piVar1 + DAT_020b246c) = 0;
    *(undefined4 *)(*piVar1 + DAT_020b2494) = 0;
    *(undefined4 *)(*piVar1 + DAT_020b2498) = 0;
    *(undefined4 *)(*piVar1 + DAT_020b249c) = 0;
    *(undefined4 *)(*piVar1 + DAT_020b24a0) = 0;
  }
  else {
    puVar5 = local_30;
    iVar6 = 3;
    puVar11 = DAT_020b21a0;
    do {
      uVar4 = *puVar11;
      uVar9 = puVar11[1];
      puVar11 = puVar11 + 2;
      *puVar5 = uVar4;
      puVar5[1] = uVar9;
      puVar5 = puVar5 + 2;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    uVar4 = func_020b47c0(DAT_020b21a4);
    Gfx_ReadPalette((int *)(uintptr_t)(*DAT_020b219c + DAT_020b21a8),uVar4);
    uVar4 = func_020b47c0(DAT_020b21ac);
    Gfx_ReadCharGraphicsV2((int *)(uintptr_t)(*DAT_020b219c + DAT_020b21b0),uVar4);
    piVar1 = DAT_020b219c;
    iVar6 = 0;
    do {
      uVar4 = func_020b47c0(local_30[iVar6]);
      MaybeReadScreenBlock_0((int *)(uintptr_t)(*piVar1 + DAT_020b21b4 + iVar6 * 4),uVar4);
      iVar8 = DAT_020b21b4;
      piVar2 = DAT_020b219c;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 6);
    iVar6 = *DAT_020b219c;
    *(undefined4 *)(iVar6 + DAT_020b21b8) =
         *(undefined4 *)(iVar6 + (*(int *)(iVar6 + 0x50) + -1) * 4 + DAT_020b21b4);
    iVar6 = *piVar2;
    *(undefined4 *)(iVar6 + DAT_020b21bc) =
         *(undefined4 *)(iVar6 + (*(int *)(iVar6 + 0x6c) + -1) * 4 + iVar8);
    iVar6 = *piVar2;
    *(undefined4 *)(iVar6 + DAT_020b21c0) =
         *(undefined4 *)(iVar6 + (*(int *)(iVar6 + 0x88) + -1) * 4 + iVar8);
    iVar6 = *piVar2;
    *(undefined4 *)(iVar6 + DAT_020b21c4) =
         *(undefined4 *)(iVar6 + (*(int *)(iVar6 + 0xa4) + -1) * 4 + iVar8);
    uVar4 = GetActiveExecutionContextHeapHandle_3();
    uVar9 = ComputeSomeMESize_from_thumb(*(undefined4 *)(*DAT_020b219c + 0x6c));
    uVar4 = Mem_AllocateHeap(uVar4,uVar9);
    *(undefined4 *)(*DAT_020b219c + DAT_020b21c8) = uVar4;
    iVar6 = GetRaceMode();
    if (((iVar6 == 2) || (iVar6 == 3)) || (iVar6 == 4)) {
      uVar4 = GetActiveExecutionContextHeapHandle_3();
      uVar9 = ComputeSomeMESize_from_thumb(*(undefined4 *)(*DAT_020b2468 + 0x88));
      uVar4 = Mem_AllocateHeap(uVar4,uVar9);
      *(undefined4 *)(*DAT_020b2468 + DAT_020b246c) = uVar4;
    }
    uVar4 = GetLoadedFont_from_thumb(2);
    *(undefined4 *)(*DAT_020b2468 + 0xa8) = uVar4;
    iVar6 = GetSomeBgTileData_from_thumb();
    G2d_Sprite_CreateFromTiles(*DAT_020b2468 + 0xac,*(undefined4 *)(iVar6 + 0x14),0x20,0xc,4);
    iVar6 = *DAT_020b2468;
    uVar4 = ComputeSomeInterCharacterWidth();
    RaceOptionMenuEntryDrawContext_Create
              ((undefined4 *)(uintptr_t)(iVar6 + DAT_020b2470),iVar6 + 0xac,*(undefined4 *)(iVar6 + 0xa8),uVar4,0);
    G2d_Sprite_CreateFromTiles
              (*DAT_020b2468 + 0xcc,*(undefined4 *)(*DAT_020b2468 + DAT_020b2474),0x20,0xc,4);
    iVar6 = *DAT_020b2468;
    uVar4 = ComputeSomeInterCharacterWidth();
    RaceOptionMenuEntryDrawContext_Create
              ((undefined4 *)(uintptr_t)(iVar6 + DAT_020b2478),iVar6 + 0xcc,*(undefined4 *)(iVar6 + 0xa8),uVar4,0);
    uVar7 = ComputeSomeMESize_from_thumb(*(undefined4 *)(*DAT_020b2468 + 0x6c));
    piVar1 = DAT_020b2468;
    for (uVar12 = 0; uVar12 < uVar7 >> 1; uVar12 = uVar12 + 1) {
      iVar6 = GetSomeBgTileData_from_thumb();
      *(undefined2 *)(*(int *)(*piVar1 + DAT_020b2474) + uVar12 * 2) =
           *(undefined2 *)(*(int *)(iVar6 + 0x14) + uVar12 * 2);
    }
    iVar6 = *(int *)(*DAT_020b2468 + DAT_020b246c);
    if (iVar6 != 0) {
      G2d_Sprite_CreateFromTiles(*DAT_020b2468 + 0xec,iVar6,0x20,0xc,4);
      iVar6 = *DAT_020b2468;
      uVar4 = ComputeSomeInterCharacterWidth();
      RaceOptionMenuEntryDrawContext_Create
                ((undefined4 *)(uintptr_t)(iVar6 + DAT_020b247c),iVar6 + 0xec,*(undefined4 *)(iVar6 + 0xa8),uVar4,0);
      uVar7 = ComputeSomeMESize_from_thumb(*(undefined4 *)(*DAT_020b2468 + 0x88));
      piVar1 = DAT_020b2468;
      for (uVar12 = 0; uVar12 < uVar7 >> 1; uVar12 = uVar12 + 1) {
        iVar6 = GetSomeBgTileData_from_thumb();
        *(undefined2 *)(*(int *)(*piVar1 + DAT_020b246c) + uVar12 * 2) =
             *(undefined2 *)(*(int *)(iVar6 + 0x14) + uVar12 * 2);
      }
    }
    iVar6 = GetSomeBgTileData_from_thumb();
    G2d_Sprite_CreateFromTiles
              (*DAT_020b2468 + DAT_020b2480,*(undefined4 *)(iVar6 + 0x14),0x20,0xc,4);
    iVar6 = *DAT_020b2468;
    uVar4 = ComputeSomeInterCharacterWidth();
    RaceOptionMenuEntryDrawContext_Create
              (iVar6 + DAT_020b2484,iVar6 + DAT_020b2480,*(undefined4 *)(iVar6 + 0xa8),uVar4,0);
    iVar8 = GetDisplayMode_0();
    uVar4 = DAT_020b2488;
    iVar6 = DAT_020b2484;
    piVar1 = DAT_020b2468;
    if (iVar8 == 2) {
      for (iVar8 = 0; iVar8 < *(int *)(*piVar1 + 0xa4); iVar8 = iVar8 + 1) {
        uVar9 = GetMenuOptionString_from_thumb(3,*(undefined4 *)(*piVar1 + iVar8 * 4 + 0x8c));
        G2d_Text_PrintString3(*piVar1 + iVar6,0x90,iVar8 * 0x10 + 9,0xc,uVar4,uVar9);
      }
    }
    else {
      for (iVar6 = 0; iVar6 < *(int *)(*piVar1 + 0x50); iVar6 = iVar6 + 1) {
        uVar9 = GetMenuOptionString_from_thumb(0,*(undefined4 *)(*piVar1 + iVar6 * 4 + 0x38));
        G2d_Text_PrintString3(*piVar1 + DAT_020b2470,0x90,iVar6 * 0x10 + 9,0xc,uVar4,uVar9);
      }
    }
    uVar4 = DAT_020b2488;
    iVar6 = DAT_020b2478;
    piVar1 = DAT_020b2468;
    for (iVar8 = 0; uVar9 = DAT_020b2488, iVar3 = DAT_020b247c, piVar2 = DAT_020b2468,
        iVar10 = *piVar1, iVar8 < *(int *)(iVar10 + 0x6c); iVar8 = iVar8 + 1) {
      uVar9 = GetMenuOptionString_from_thumb(1,*(undefined4 *)(iVar10 + iVar8 * 4 + 0x54));
      G2d_Text_PrintString3(*piVar1 + iVar6,0x90,iVar8 * 0x10 + 9,0xc,uVar4,uVar9);
    }
    for (iVar6 = 0; iVar8 = *piVar2, iVar6 < *(int *)(iVar8 + 0x88); iVar6 = iVar6 + 1) {
      uVar4 = GetMenuOptionString_from_thumb(2,*(undefined4 *)(iVar8 + iVar6 * 4 + 0x70));
      G2d_Text_PrintString3(*piVar2 + iVar3,0x90,iVar6 * 0x10 + 9,0xc,uVar9,uVar4);
    }
  }
  return;
}

