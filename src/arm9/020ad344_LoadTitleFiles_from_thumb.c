/* Decompiled C draft; module arm9; ROM address 020ad344. No matching claim. */
#include "types.h"
#include "deps/020ad344_LoadTitleFiles_from_thumb.h"

void LoadTitleFiles_from_thumb(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar2 = IsTitleTrue();
  uVar3 = GetActiveExecutionContextHeapHandle_4();
  puVar4 = (undefined4 *)Mem_AllocateHeap(uVar3,uRam020ad700);
  piVar1 = piRam020ad704;
  *piRam020ad704 = (int)puVar4;
  *puVar4 = 0;
  *(undefined4 *)(*piVar1 + 4) = 1;
  *(undefined4 *)(*piVar1 + 8) = 0;
  *(undefined4 *)(*piVar1 + 0xc) = 0;
  *(undefined4 *)(*piVar1 + 0x10) = 8;
  *(undefined4 *)(*piVar1 + 0x4c) = 0;
  iVar5 = GetB488TitleMenuSkipIntro();
  piVar1 = piRam020ad704;
  *(uint *)(*piRam020ad704 + 0x50) = (uint)(iVar5 != 0);
  *(undefined4 *)(*piVar1 + 0x54) = 0;
  *(undefined4 *)(*piVar1 + 0x58) = 0;
  *(undefined4 *)(*piVar1 + 0x5c) = 1;
  *(undefined2 *)(*piVar1 + 0x60) = 0;
  iVar5 = GetB488TitleMenuSkipIntro();
  if (iVar5 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0x6b;
  }
  *(undefined4 *)(*piRam020ad704 + 100) = uVar3;
  Title_SomeBldalphaConfig_from_thumb();
  Title_CopyFunctionList_from_thumb();
  OamBuffer_SomeFn_from_thumb(*piRam020ad704 + 0xb0,*piRam020ad704 + iRam020ad708);
  uVar3 = uRam020ad710;
  if (iVar2 != 0) {
    uVar3 = uRam020ad70c;
  }
  uVar3 = func_020b47c0(uVar3);
  Gfx_ReadPalette((int *)(uintptr_t)(*piRam020ad704 + 0x78),uVar3);
  uVar3 = func_020b47c0(uRam020ad714);
  Gfx_ReadPalette((int *)(uintptr_t)(*piRam020ad704 + 0x80),uVar3);
  uVar3 = uRam020ad71c;
  if (iVar2 != 0) {
    uVar3 = uRam020ad718;
  }
  uVar3 = func_020b47c0(uVar3);
  Gfx_ReadCharGraphicsV2((int *)(uintptr_t)(*piRam020ad704 + 0x7c),uVar3);
  uVar3 = func_020b47c0(uRam020ad720);
  Gfx_ReadCharGraphicsV2((int *)(uintptr_t)(*piRam020ad704 + 0x84),uVar3);
  uVar3 = uRam020ad728;
  if (iVar2 != 0) {
    uVar3 = uRam020ad724;
  }
  uVar3 = func_020b47c0(uVar3);
  MaybeReadScreenBlock_0((int *)(uintptr_t)(*piRam020ad704 + 0x88),uVar3);
  uVar3 = uRam020ad730;
  if (iVar2 != 0) {
    uVar3 = uRam020ad72c;
  }
  uVar3 = func_020b47c0(uVar3);
  MaybeReadScreenBlock_0((int *)(uintptr_t)(*piRam020ad704 + 0x8c),uVar3);
  uVar3 = func_020b47c0(uRam020ad734);
  MaybeReadScreenBlock_0((int *)(uintptr_t)(*piRam020ad704 + 0x90),uVar3);
  uVar3 = func_020b47c0(uRam020ad738);
  Gfx_ReadPalette((int *)(uintptr_t)(*piRam020ad704 + 0xa0),uVar3);
  uVar3 = func_020b47c0(uRam020ad73c);
  Gfx_ReadCharGraphics((int *)(uintptr_t)(*piRam020ad704 + 0xa4),uVar3);
  uVar3 = func_020b47c0(uRam020ad740);
  LoadCellBankFrom(*piRam020ad704 + 0xa8,uVar3);
  uVar3 = func_020b47c0(uRam020ad744);
  *(undefined4 *)(*piRam020ad704 + 0x6c) = uVar3;
  uVar3 = func_020b47c0(uRam020ad748);
  *(undefined4 *)(*piRam020ad704 + 0x70) = uVar3;
  uVar3 = func_020b47c0(uRam020ad74c);
  *(undefined4 *)(*piRam020ad704 + 0x74) = uVar3;
  uVar3 = GetActiveExecutionContextHeapHandle_4();
  uVar3 = CreateDisplayConfig(uVar3,uRam020ad750);
  DisplayConfig_SetTopEngineBg1Config(uVar3,0,0,0,0,2,0,0);
  DisplayConfig_SetTopEngineBg2Config(uVar3,2,0,0,1,0xe,4);
  DisplayConfig_SetTopEngineBg3Config(uVar3,3,0,0,1,0xf,4);
  DisplayConfig_SetBottomEngineBg3Config(uVar3,3,0,0,0,1,6);
  SetGlobalDisplayConfig(uVar3);
  iVar2 = *piRam020ad704;
  uVar3 = GetActiveExecutionContextHeapHandle_4();
  func_02124ed0(uVar3,*(undefined4 *)(iVar2 + 0x6c),*(undefined4 *)(iVar2 + 0x74),iVar2 + 0x68);
  CellBank_ResetSomeMetatileObjectsMode_from_thumb
            (0,1,*(undefined4 *)(*piRam020ad704 + 0xa8),*(undefined4 *)(*piRam020ad704 + 0x6c));
  CellBank_ResetSomeMetatileObjectsMode_from_thumb
            (1,1,*(undefined4 *)(*piRam020ad704 + 0xa8),*(undefined4 *)(*piRam020ad704 + 0x6c));
  CellBank_ResetSomeMetatileObjectsMode_from_thumb
            (2,1,*(undefined4 *)(*piRam020ad704 + 0xa8),*(undefined4 *)(*piRam020ad704 + 0x6c));
  CellBank_ResetSomeMetatileObjectsMode_from_thumb
            (3,1,*(undefined4 *)(*piRam020ad704 + 0xa8),*(undefined4 *)(*piRam020ad704 + 0x6c));
  CellBank_ResetSomeMetatileObjectsMode_from_thumb
            (4,1,*(undefined4 *)(*piRam020ad704 + 0xa8),*(undefined4 *)(*piRam020ad704 + 0x6c));
  iVar2 = func_02148ca0();
  iVar5 = *piRam020ad704;
  uVar3 = GetActiveExecutionContextHeapHandle_4();
  iVar5 = func_021243ac(uVar3,0,*(undefined4 *)(iVar5 + 0x74),0x55,0xd,0xd,
                        *(undefined4 *)(iVar5 + 0xa8),*(undefined4 *)(iVar5 + 0x6c),
                        *(undefined4 *)(iVar5 + 0x68),iVar2);
  iVar6 = *piRam020ad704;
  uVar3 = GetActiveExecutionContextHeapHandle_4();
  func_021243ac(uVar3,1,*(undefined4 *)(iVar6 + 0x74),0x55,0xd,0xe,*(undefined4 *)(iVar6 + 0xa8),
                *(undefined4 *)(iVar6 + 0x6c),*(undefined4 *)(iVar6 + 0x68),iVar2 - iVar5);
  iVar2 = *piRam020ad704;
  uVar3 = func_020b47c0(uRam020ad754);
  uVar3 = Bmg_GetRawStringPointer_from_thumb(uVar3,1);
  func_0212426c(1,0,*(undefined4 *)(*piRam020ad704 + 0x74),uVar3,*(undefined4 *)(iVar2 + 0x6c),
                *(undefined4 *)(iVar2 + 0x68));
  iVar2 = *piRam020ad704;
  uVar3 = func_020b47c0(uRam020ad758);
  uVar3 = Bmg_GetRawStringPointer_from_thumb(uVar3,0);
  func_0212426c(1,1,*(undefined4 *)(*piRam020ad704 + 0x74),uVar3,*(undefined4 *)(iVar2 + 0x6c),
                *(undefined4 *)(iVar2 + 0x68));
  func_0214b720();
  func_0214b6a0(*(undefined4 *)(*(int *)(*piRam020ad704 + 0x78) + 0xc),uRam020ad75c,
                *(undefined4 *)(*(int *)(*piRam020ad704 + 0x78) + 8));
  func_0214b6a0(*(undefined4 *)(*(int *)(*piRam020ad704 + 0x78) + 0xc),uRam020ad760,
                *(undefined4 *)(*(int *)(*piRam020ad704 + 0x78) + 8));
  func_0214b63c();
  CopyBgData_Bg2_Top(*(undefined4 *)(*(int *)(*piRam020ad704 + 0x7c) + 0x14),0,
                     *(undefined4 *)(*(int *)(*piRam020ad704 + 0x7c) + 0x10));
  TEQSub_Fn10Impl_Fn12Impl(*(int *)(*piRam020ad704 + 0x88) + 0xc,0,uRam020ad764);
  TEQSub_Fn11Impl_Fn13Impl(*(int *)(*piRam020ad704 + 0x8c) + 0xc,0,uRam020ad764);
  CopyPaletteBottom(*(undefined4 *)(*(int *)(*piRam020ad704 + 0x80) + 0xc),0,
                    *(undefined4 *)(*(int *)(*piRam020ad704 + 0x80) + 8));
  CopyBgData_Bg3_Bottom
            (*(undefined4 *)(*(int *)(*piRam020ad704 + 0x84) + 0x14),0,
             *(undefined4 *)(*(int *)(*piRam020ad704 + 0x84) + 0x10));
  TEQSub_Fn27Impl_Fn29Impl(*(int *)(*piRam020ad704 + 0x90) + 0xc,0,uRam020ad764);
  TEQSub_Fn30Impl(*(undefined4 *)(*(int *)(*piRam020ad704 + 0xa0) + 0xc),0,
                  *(undefined4 *)(*(int *)(*piRam020ad704 + 0xa0) + 8));
  TEQSub_Fn35Impl(*(undefined4 *)(*(int *)(*piRam020ad704 + 0xa4) + 0x14),0,
                  *(undefined4 *)(*(int *)(*piRam020ad704 + 0xa4) + 0x10));
  SetDispcntTopDisplayFrameSelect(0x10);
  SetDispcntSubDisplayFrameSelect(0x10);
  EnableAlphaSetTopBldcntBldalpha(4,8,0,0x10);
  EnableAlphaSetSubBldcntBldalpha(0,0x3f,6,10);
  SetTopDispcntWindow0Window1ObjDisplayFlag(0);
  SetSubDispcntWindow0Window1ObjDisplayFlag(0);
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = GetLoadedFont_from_thumb();
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  PrepareNavigationContextFiles_from_thumb();
  uVar3 = GetActiveExecutionContextHeapHandle_4();
  InitializeNavigationContext_from_thumb(uVar3,&local_38);
  GetActiveExecutionContextHeapHandle_4();
  uVar3 = AllocateKartAppearTableData_from_thumb();
  *(undefined4 *)(*piRam020ad818 + iRam020ad81c) = uVar3;
  SetSystemContextOverlayState(0);
  StructP_SetAFlag4_SkipBattleIntro(0);
  ResetB488HeyhoPaletteRows_from_thumb();
  SetB488_b2(1);
  SetB488SinglePlayerMenuTarget(0);
  SetCurrentMissionNotBeaten(0);
  SetB488_b6(0);
  PopulateNextRaceConfig();
  return;
}

