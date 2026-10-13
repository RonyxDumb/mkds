/* Decompiled C draft; module arm9; ROM address 020cbb10. No matching claim. */
#include "types.h"
#include "deps/020cbb10_Scene_Menu_InitializeImpl_from_thumb.h"

void Scene_Menu_InitializeImpl_from_thumb(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  uVar2 = GetActiveExecutionContextHeapHandle();
  iVar3 = Mem_AllocateHeap(uVar2,DAT_020cbefc);
  *DAT_020cbf00 = iVar3;
  GetActiveExecutionContextHeapHandle();
  InitializeGlobalCA_from_thumb();
  uVar2 = GetActiveExecutionContextHeapHandle();
  uVar2 = CreateDisplayConfig(uVar2,DAT_020cbf04);
  DisplayConfig_SetTopEngineBg0Config(uVar2,1,0,0,0,0xd,2,0);
  DisplayConfig_SetTopEngineBg1Config_1(uVar2,0,0,0,0,0xc,0,0);
  DisplayConfig_SetTopEngineBg2Config2(uVar2,0,0,0,0,0x1e,6);
  DisplayConfig_SetTopEngineBg3Config_0(uVar2,3,0,0,0,0x1d,4);
  DisplayConfig_SetBottomEngineBg0Config(uVar2,0,0,0,0,0xb,0,0);
  DisplayConfig_SetBottomEngineBg1Config(uVar2,3,0,0,0,0xd,0,0);
  DisplayConfig_SetBottomEngineBg2Config2(uVar2,0,0,0,0,0xe,0);
  DisplayConfig_SetBottomEngineBg3Config_1(uVar2,2,0,0,0,0xf,0);
  SetGlobalDisplayConfig(uVar2);
  piVar1 = DAT_020cbf00;
  *(undefined4 *)*DAT_020cbf00 = 0;
  *(undefined4 *)(*piVar1 + 4) = 1;
  *(undefined4 *)(*piVar1 + 8) = 0x1f;
  *(undefined4 *)(*piVar1 + 0xc) = 0x1f;
  *(undefined4 *)(*piVar1 + 0x10) = 0x1f;
  *(undefined4 *)(*piVar1 + DAT_020cbf08) = 1;
  *(undefined4 *)(*piVar1 + DAT_020cbf0c) = 1;
  *(undefined4 *)(*piVar1 + DAT_020cbf10) = 1;
  CopyB43CFunctionTable_from_thumb();
  OamBuffer_SomeFn_from_thumb(*DAT_020cbf00 + DAT_020cbf14,*DAT_020cbf00 + DAT_020cbf18);
  SetActiveExecutionContextHeapGroupId_from_thumb(9);
  func_02062860();
  SetActiveExecutionContextHeapGroupId_from_thumb(5);
  func_020629a4();
  SetActiveExecutionContextHeapGroupId_from_thumb(9);
  iVar3 = func_020cbad0();
  if (iVar3 == 0) {
    GetActiveExecutionContextHeapHandle();
    CreateGlobalCE_from_thumb();
    func_02078a9c(0xffffffff);
    func_02078a34(0xffffffff);
  }
  SetActiveExecutionContextHeapGroupId_from_thumb(5);
  iVar3 = func_020cbad0();
  if (iVar3 == 0) {
    GetActiveExecutionContextHeapHandle();
    InitializeGlobalPK_from_thumb();
    InitializeGlobalB4A4_from_thumb();
    uVar2 = func_020b47c0(DAT_020cbf1c);
    Gfx_ReadPalette(*DAT_020cbf00 + DAT_020cbf20,uVar2);
    uVar2 = func_020b47c0(DAT_020cbf24);
    Gfx_ReadCharGraphics(*DAT_020cbf00 + DAT_020cbf28,uVar2);
    uVar2 = func_020b47c0(DAT_020cbf2c);
    LoadCellBankFrom(*DAT_020cbf00 + DAT_020cbf30,uVar2);
    uVar2 = func_020b47c0(DAT_020cbf34);
    piVar1 = DAT_020cbf00;
    *(undefined4 *)(*DAT_020cbf00 + DAT_020cbf38) = uVar2;
    *(undefined4 *)(*piVar1 + DAT_020cbf3c) = 0;
    uVar2 = func_020b47c0(DAT_020cbf40);
    Gfx_ReadPalette(*DAT_020cbf00 + DAT_020cbf44,uVar2);
    uVar2 = func_020b47c0(DAT_020cbf48);
    Gfx_ReadCharGraphics(*DAT_020cbf00 + DAT_020cbf4c,uVar2);
    uVar2 = func_020b47c0(DAT_020cbf50);
    LoadCellBankFrom(*DAT_020cbf00 + DAT_020cbf54,uVar2);
    uVar2 = func_020b47c0(DAT_020cbf58);
    *(undefined4 *)(*DAT_020cbf00 + DAT_020cbf5c) = uVar2;
    uVar2 = func_020b47c0(DAT_020cbf60);
    piVar1 = DAT_020cbf00;
    *(undefined4 *)(*DAT_020cbf00 + DAT_020cbf64) = uVar2;
    iVar3 = *piVar1;
    uVar2 = GetActiveExecutionContextHeapHandle();
    func_02124ed0(uVar2,*(undefined4 *)(iVar3 + DAT_020cbf38),0,iVar3 + DAT_020cbf68);
    iVar3 = *DAT_020cbf00;
    uVar2 = GetActiveExecutionContextHeapHandle();
    func_02124ed0(uVar2,*(undefined4 *)(iVar3 + DAT_020cbf5c),0,iVar3 + DAT_020cbf6c);
    CellBank_ResetSomeMetatileObjectsMode_from_thumb
              (0,1,*(undefined4 *)(*DAT_020cbf00 + DAT_020cbf54),
               *(undefined4 *)(*DAT_020cbf00 + DAT_020cbf5c));
    CellBank_ResetSomeMetatileObjectsMode_from_thumb
              (1,1,*(undefined4 *)(*DAT_020cbf00 + DAT_020cbf54),
               *(undefined4 *)(*DAT_020cbf00 + DAT_020cbf5c));
    CellBank_ResetSomeMetatileObjectsMode_from_thumb
              (2,1,*(undefined4 *)(*DAT_020cbf00 + DAT_020cbf54),
               *(undefined4 *)(*DAT_020cbf00 + DAT_020cbf5c));
    CellBank_ResetSomeMetatileObjectsMode_from_thumb
              (3,1,*(undefined4 *)(*DAT_020cbf00 + DAT_020cbf54),
               *(undefined4 *)(*DAT_020cbf00 + DAT_020cbf5c));
    CellBank_ResetSomeMetatileObjectsMode_from_thumb
              (4,1,*(undefined4 *)(*DAT_020cbf00 + DAT_020cbf54),
               *(undefined4 *)(*DAT_020cbf00 + DAT_020cbf5c));
  }
  VerifySelectMenuFiles_from_thumb();
  uVar2 = GetActiveExecutionContextHeapHandle();
  AndAnotherAlloc_0_from_thumb(uVar2,*DAT_020cbf00 + DAT_020cbf14);
  GetActiveExecutionContextHeapHandle();
  uVar2 = AllocateKartAppearTableData_from_thumb();
  *(undefined4 *)(*DAT_020cbf00 + DAT_020cbf70) = uVar2;
  SetTopDispcntTileObjMappingRemoveBoundary(0x10);
  SetSubDispcntTileObjMappingRemoveBoundary(0x10);
  EnableAlphaSetBldcntBldalphaTop(0,0x3f,6,10);
  EnableAlphaSetBldcntBldalphaSub(0,0x3f,6,10);
  SetDispcntWindows01ObjDisplayFlagsTop(0);
  SetDispcntWindows01ObjDisplayFlagsSub(0);
  iVar3 = func_020cbad0();
  if (iVar3 == 0) {
    VerifySelectCharacterFiles_from_thumb();
    VerifySelectKartFiles_from_thumb();
    func_0x021984ac();
    func_0x0219c6f0();
    func_0x0219f85c();
    func_0x021a10b8();
    func_0x0219d50c();
    func_0x021a1f60();
    VerifySelectCupFiles_from_thumb();
    func_0211f240();
    VerifySelectCupCourseFiles_from_thumb();
  }
  VerifyCommonSelectGameFiles_from_thumb();
  VerifyCommonSelectRaceRuleFiles_from_thumb();
  local_30 = func_020cbad0();
  local_2c = GetLoadedFont_from_thumb(1);
  local_28 = 0;
  local_24 = 1;
  local_20 = 0;
  local_1c = 1;
  local_18 = GetLoadedFont_from_thumb(2);
  local_14 = 1;
  local_10 = 1;
  local_c = 0;
  PrepareNavigationContextFiles_from_thumb();
  uVar2 = GetActiveExecutionContextHeapHandle();
  InitializeNavigationContext_from_thumb(uVar2,&local_30);
  iVar3 = GetPMaybeState_1();
  if (iVar3 == 2) {
    func_021281fc();
  }
  uVar2 = GetActiveExecutionContextHeapHandle();
  CreateGlobalNN_from_thumb(uVar2,*DAT_020cbf00 + DAT_020cbf14);
  uVar2 = GetB488_SinglePlayerMenuTarget();
  switch(uVar2) {
  case 0:
    func_020ccc74(0,0x1f);
    SetB488_B2(1);
    break;
  case 1:
    CopyInfoFromCOtoCA_from_thumb();
    iVar3 = GetGlobalCA_from_thumb();
    switch(*(undefined4 *)(iVar3 + 200)) {
    case 0:
      func_020ccc74(5,0x1f);
      SetSinglePlayerMenuTarget(0);
      SetB488_B2(1);
      break;
    case 1:
      func_020ccc74(0x15,0x1f);
      SetSinglePlayerMenuTarget(0);
      SetB488_B2(1);
      break;
    case 2:
      func_020ccc74(0xf,0x1f);
      break;
    case 3:
      func_020ccc74(8,0x1f);
    }
    break;
  case 2:
    CopyInfoFromCOtoCA_from_thumb();
    iVar3 = GetGlobalCA_from_thumb();
    iVar3 = *(int *)(iVar3 + 200);
    if (iVar3 == 1) {
      func_020ccc74(0x17,0x1f);
      SetSinglePlayerMenuTarget(0);
      SetB488_B2(1);
    }
    else if (iVar3 == 2) {
      func_020ccc74(0x11,0x1f);
    }
    else if (iVar3 == 3) {
      func_020ccc74(0xb,0x1f);
    }
    break;
  case 3:
    CopyInfoFromCOtoCA_from_thumb();
    iVar3 = GetB488_B5();
    if ((iVar3 == 0) && (iVar3 = GetB488_B6(), iVar3 == 0)) {
      func_020ccc74(0x13,0x1f);
    }
    else {
      func_020ccc74(0x12,0x1f);
    }
    SetSinglePlayerMenuTarget(0);
    SetB488_B2(1);
    break;
  case 4:
    func_020ccc74(0xe,0x1f);
    break;
  case 5:
    CopyInfoFromCOtoCA_from_thumb();
    iVar3 = GetGlobalCA_from_thumb();
    *(undefined4 *)(iVar3 + 200) = 1;
    func_020ccc74(0x14,0x1f);
    SetSinglePlayerMenuTarget(0);
    SetB488_B2(1);
  }
  GetActiveExecutionContextHeapHandle();
  CreateSetGlobalKTB_from_thumb();
  iVar3 = GetGlobalCA_from_thumb();
  switch(*(undefined4 *)(iVar3 + 200)) {
  default:
    *(undefined4 *)(*DAT_020cc0d4 + DAT_020cc0d8) = 0;
    break;
  case 1:
    *(undefined4 *)(*DAT_020cc0d4 + DAT_020cc0d8) = 1;
    break;
  case 2:
    *(undefined4 *)(*DAT_020cc0d4 + DAT_020cc0d8) = 3;
    break;
  case 3:
    *(undefined4 *)(*DAT_020cc0d4 + DAT_020cc0d8) = 2;
    break;
  case 4:
    *(undefined4 *)(*DAT_020cc0d4 + DAT_020cc0d8) = 4;
  }
  piVar1 = DAT_020cc0d4;
  *(undefined4 *)(*DAT_020cc0d4 + DAT_020cc0dc) = 0;
  *(undefined2 *)(*piVar1 + DAT_020cc0e0) = 0;
  return;
}

