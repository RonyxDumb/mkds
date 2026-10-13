/* Decompiled C draft; module arm9; ROM address 02032f94. No matching claim. */
#include "types.h"
#include "deps/02032f94_InstanceStructV_from_thumb.h"

void InstanceStructV_from_thumb(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  ushort uVar6;
  ushort uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined1 auStack_78 [24];
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38 [9];
  
  iVar2 = Mem_AllocateHeap(param_1,DAT_02033350);
  *DAT_02033354 = iVar2;
  Mem_CpuFastMemorySet(0,iVar2,DAT_02033350);
  piVar1 = DAT_02033354;
  *(undefined4 *)(*DAT_02033354 + 0xb8) = param_2;
  *(undefined4 *)(*piVar1 + 0xbc) = param_3;
  *(undefined4 *)(*piVar1 + 0xe0) = *(undefined4 *)(*DAT_02033358 + 0x20);
  if (*(int *)(*piVar1 + 0xe0) == 3) {
    func_02123a48(3);
  }
  func_02062860();
  iVar2 = CreateDisplayConfig(param_1,DAT_0203335c);
  DisplayEngineConfig_SetBg0Config(iVar2 + 0x28,3,0,0,0,0xd,2,0);
  DisplayEngineConfig_SetBg1Config(iVar2 + 0x28,0,0,0,0,0xc,0,0);
  DisplayEngineConfig_SetBg2Config2(iVar2 + 0x28,2,0,0,0,0x1e,6);
  DisplayEngineConfig_SetBg3Config(iVar2 + 0x28,3,0,0,0,0x1d,6);
  DisplayEngineConfig_SetBg3Config(iVar2 + 0x70,3,0,0,0,1,6);
  SetGlobalDisplayConfig(iVar2);
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 1;
  local_48 = GetLoadedFont_from_thumb(2);
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  PrepareNavigationContextFiles_from_thumb();
  InitializeNavigationContext_from_thumb(param_1,&local_60);
  func_020629a4();
  uVar3 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(DAT_02033360);
  piVar1 = DAT_02033354;
  *(undefined4 *)(*DAT_02033354 + 200) = uVar3;
  switch(*(undefined4 *)(*piVar1 + 0xe0)) {
  case 0:
    *(undefined4 *)(*piVar1 + 0xd0) = 0;
    *(uint *)(*piVar1 + 0xd8) = (uint)*(byte *)(*DAT_02033364 + DAT_02033368);
    *(undefined4 *)(*piVar1 + DAT_0203336c) = 2;
    break;
  case 1:
  case 2:
    func_0212775c(1,0xf);
    piVar1 = DAT_02033354;
    piVar5 = (int *)*DAT_02033370;
    if (*piVar5 == 2) {
      uVar9 = (uint)*(ushort *)((int)piVar5 + DAT_02033374);
    }
    else {
      uVar9 = 0;
    }
    *(uint *)(*DAT_02033354 + 0xd0) =
         (uint)*(ushort *)((int)piVar5 + DAT_02033378 + ((uVar9 << 0x10) >> 0xd));
    *(uint *)(*piVar1 + 0xd8) = (uint)*(byte *)(*DAT_02033364 + DAT_02033368);
    *(undefined4 *)(*piVar1 + DAT_0203336c) = 0;
    break;
  case 3:
    func_0x0219bb50();
    uVar3 = func_02122778();
    piVar1 = DAT_02033354;
    *(undefined4 *)(*DAT_02033354 + 0xd0) = uVar3;
    *(uint *)(*piVar1 + 0xd8) = (uint)*(byte *)(*DAT_0203337c + DAT_02033380);
    *(undefined4 *)(*piVar1 + DAT_02033384) = 1;
    *(undefined4 *)(*piVar1 + DAT_0203338c) = DAT_02033388;
    *(undefined4 *)(*piVar1 + DAT_0203336c) = 2;
  }
  func_02033e6c();
  if (*(char *)(*DAT_02033364 + 0x58) == '\0') {
    iVar2 = func_02033e24();
    piVar1 = DAT_02033354;
    if (iVar2 == 0) {
      iVar2 = *DAT_02033354;
      if (*(int *)(iVar2 + *(int *)(iVar2 + 0xd0) * 0xc + 0xe4) == 0) {
        *(undefined4 *)(iVar2 + 0xdc) = 0;
      }
      else {
        *(undefined4 *)(iVar2 + 0xdc) = 1;
      }
    }
    else {
      *(undefined4 *)(*DAT_02033354 + 0xd4) = *(undefined4 *)(*DAT_02033354 + 0xd8);
      *(undefined4 *)(*piVar1 + 0xdc) = 2;
    }
  }
  else {
    uVar7 = 0;
    uVar6 = 0;
    iVar2 = *(int *)(*DAT_02033364 + 0x1c);
    if (iVar2 == 1) {
      iVar2 = GetSomeLUMaxIndex();
      uVar7 = (ushort)*(byte *)(*DAT_02033390 + DAT_02033394 + iVar2 * 8 + 2);
      iVar2 = GetSomeLUMaxIndex();
      uVar6 = (ushort)*(byte *)(*DAT_02033390 + DAT_02033394 + iVar2 * 8 + 6);
    }
    else if (iVar2 == 2) {
      iVar2 = GetSomeLUMaxIndex();
      uVar7 = *(ushort *)(*DAT_02033390 + DAT_02033394 + iVar2 * 8);
      iVar2 = GetSomeLUMaxIndex();
      uVar6 = *(ushort *)(*DAT_02033390 + DAT_02033394 + iVar2 * 8 + 4);
    }
    piVar1 = DAT_02033354;
    if (uVar7 == uVar6) {
      *(undefined4 *)(*DAT_02033354 + 0xd4) = *(undefined4 *)(*DAT_02033354 + 0xd8);
      *(undefined4 *)(*piVar1 + 0xdc) = 2;
    }
    else if (uVar6 < uVar7) {
      *(uint *)(*DAT_02033354 + 0xd4) = (uint)*(byte *)(*DAT_02033364 + DAT_02033398);
      *(undefined4 *)(*piVar1 + 0xdc) = 3;
    }
    else if (uVar7 < uVar6) {
      *(uint *)(*DAT_02033354 + 0xd4) = (uint)*(byte *)(*DAT_02033364 + DAT_0203339c);
      *(undefined4 *)(*piVar1 + 0xdc) = 4;
    }
  }
  LoadPlayerGfxData_from_thumb(1,*DAT_02033354 + 0x80);
  LoadPlayerGfxData_from_thumb(0,*DAT_02033354 + 0x9c);
  uVar3 = GetPortraitShyGuyPalette_from_thumb(1);
  *(undefined4 *)(*DAT_02033354 + 0xc0) = uVar3;
  uVar3 = GetPortraitShyGuyPalette_from_thumb(0);
  piVar1 = DAT_02033354;
  *(undefined4 *)(*DAT_02033354 + 0xc4) = uVar3;
  iVar8 = *piVar1;
  iVar2 = *(int *)(iVar8 + 0xdc) * 0x24;
  func_02025884(iVar8,*(undefined4 *)(DAT_020333a4 + iVar2),*(undefined4 *)(DAT_020333a8 + iVar2),
                *(undefined4 *)(DAT_020333ac + iVar2),3,DAT_020333a0);
  uVar3 = find_buf_fn_from_thumb
                    (*(undefined4 *)(DAT_020333b0 + *(int *)(*DAT_02033354 + 0xdc) * 0x24));
  MaybeReadScreenBlock_0(iVar8 + 0x1c,uVar3);
  CopyBgData_Bg3_Top(*(undefined4 *)(*(int *)(iVar8 + 0xc) + 0x14),0,
                     *(undefined4 *)(*(int *)(iVar8 + 0xc) + 0x10));
  CopyPaletteTop(*(undefined4 *)(*(int *)(iVar8 + 0x10) + 0xc),0,DAT_020333b4);
  TEQSub_Fn10Impl_Fn12Impl
            (*(int *)(iVar8 + 0x1c) + 0xc,0,*(undefined4 *)(*(int *)(iVar8 + 0x1c) + 8));
  TEQSub_Fn11Impl_Fn13Impl
            (*(int *)(iVar8 + 0x20) + 0xc,0,*(undefined4 *)(*(int *)(iVar8 + 0x20) + 8));
  iVar2 = *DAT_02033354;
  iVar8 = *(int *)(iVar2 + 0xdc) * 0x24;
  PlayerGfxData_Create_from_thumb
            (iVar2 + 0x48,*(undefined4 *)(DAT_020333c0 + iVar8),
             *(undefined4 *)(DAT_020333c4 + iVar8),*(undefined4 *)(DAT_020333c8 + iVar8),
             *(undefined4 *)(DAT_020333b8 + iVar8),*(undefined4 *)(DAT_020333bc + iVar8),0,
             DAT_020333a0);
  func_02025a50(0,param_1,iVar2 + 0x48);
  switch(*(undefined4 *)(*DAT_020336b8 + 0xdc)) {
  case 0:
    func_02033a0c(param_1);
    break;
  case 1:
    func_020338f8(param_1);
    break;
  case 2:
    func_02033840(param_1);
    break;
  case 3:
  case 4:
    func_020336ec(param_1);
  }
  iVar8 = *(int *)(iVar2 + 0x54);
  uVar6 = 0;
  if (*(short *)(iVar8 + 6) != 0) {
    do {
      func_0201ea30(*(undefined4 *)(iVar2 + 0x54),uVar6);
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(ushort *)(iVar8 + 6));
  }
  iVar2 = *DAT_020336b8;
  func_02025884(iVar2 + 0x24,DAT_020336c0,DAT_020336c4,DAT_020336c8,3,DAT_020336bc);
  CopyBgData_Bg3_Bottom
            (*(undefined4 *)(*(int *)(iVar2 + 0x30) + 0x14),0,
             *(undefined4 *)(*(int *)(iVar2 + 0x30) + 0x10));
  CopyPaletteBottom(*(undefined4 *)(*(int *)(iVar2 + 0x34) + 0xc),0,DAT_020336cc);
  TEQSub_Fn27Impl_Fn29Impl
            (*(int *)(iVar2 + 0x44) + 0xc,0,*(undefined4 *)(*(int *)(iVar2 + 0x44) + 8));
  iVar2 = func_02148ca0();
  iVar8 = *DAT_020336b8;
  PlayerGfxData_Create_from_thumb
            (iVar8 + 100,DAT_020336d8,DAT_020336dc,DAT_020336e0,DAT_020336d0,DAT_020336d4,0,
             DAT_020336bc);
  func_02124ed0(param_1,*(undefined4 *)(iVar8 + 0x70),*(undefined4 *)(iVar8 + 0x78),iVar8 + 0x7c);
  TEQSub_Fn35Impl(*(undefined4 *)(*(int *)(iVar8 + 100) + 0x14),0,
                  *(undefined4 *)(*(int *)(iVar8 + 100) + 0x10));
  TEQSub_Fn30Impl(*(undefined4 *)(*(int *)(iVar8 + 0x68) + 0xc),0,
                  *(undefined4 *)(*(int *)(iVar8 + 0x68) + 8));
  uVar9 = 0;
  if (*(short *)(*(int *)(iVar8 + 0x78) + 6) != 0) {
    do {
      iVar4 = func_02025a00(1,param_1,iVar8 + 100,DAT_020336e4 + uVar9 * 8,iVar2);
      iVar2 = iVar2 - iVar4;
      uVar9 = uVar9 + 1 & 0xffff;
    } while (uVar9 < *(ushort *)(*(int *)(iVar8 + 0x78) + 6));
  }
  uVar6 = 0;
  if (*(short *)(*(int *)(iVar8 + 0x70) + 6) != 0) {
    do {
      func_021249a8(uVar6,2,*(undefined4 *)(iVar8 + 0x6c));
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(ushort *)(*(int *)(iVar8 + 0x70) + 6));
  }
  uVar9 = 0;
  uVar10 = 0;
  do {
    local_38[uVar9] = 0;
    uVar9 = uVar9 + 1 & 0xffff;
  } while (uVar9 < 8);
  do {
    iVar4 = *DAT_020336b8 + uVar10 * 0xc;
    iVar11 = *(int *)(iVar4 + 0xec);
    iVar2 = *(int *)(*DAT_020336e8 + uVar10 * 0x30 + 0x70);
    if ((((iVar2 == 0) || (iVar2 == 1)) || (iVar2 == 3)) &&
       ((*(int *)(*DAT_020336b8 + 0xe0) != 3 || (*(int *)(iVar4 + 0xe8) != 0)))) {
      func_02033ab8(1,uVar10,iVar11 + 0x30,1);
      Mem_CpuFill16(0,auStack_78,0x16);
      FormatRacerNameString_from_thumb(uVar10,auStack_78,0);
      func_0212426c(1,iVar11,*(undefined4 *)(iVar8 + 0x78),auStack_78,*(undefined4 *)(iVar8 + 0x70),
                    *(undefined4 *)(iVar8 + 0x7c));
      func_02033b80(uVar10);
      func_02033c80(uVar10);
      local_38[iVar11] = 1;
    }
    uVar10 = uVar10 + 1 & 0xffff;
  } while (uVar10 < 8);
  uVar9 = 0;
  do {
    if (local_38[uVar9] == 0) {
      iVar4 = (uVar9 + 0x48) * 0x40;
      *(undefined4 *)(*(int *)(iVar8 + 0x7c) + iVar4) = 0;
      iVar2 = (uVar9 + 0x30) * 0x40;
      *(undefined4 *)(*(int *)(iVar8 + 0x7c) + iVar2) =
           *(undefined4 *)(*(int *)(iVar8 + 0x7c) + iVar4);
      iVar4 = (uVar9 + 0x38) * 0x40;
      *(undefined4 *)(*(int *)(iVar8 + 0x7c) + iVar4) =
           *(undefined4 *)(*(int *)(iVar8 + 0x7c) + iVar2);
      iVar2 = (uVar9 + 0x28) * 0x40;
      *(undefined4 *)(*(int *)(iVar8 + 0x7c) + iVar2) =
           *(undefined4 *)(*(int *)(iVar8 + 0x7c) + iVar4);
      iVar4 = (uVar9 + 0x20) * 0x40;
      *(undefined4 *)(*(int *)(iVar8 + 0x7c) + iVar4) =
           *(undefined4 *)(*(int *)(iVar8 + 0x7c) + iVar2);
      iVar2 = (uVar9 + 0x18) * 0x40;
      *(undefined4 *)(*(int *)(iVar8 + 0x7c) + iVar2) =
           *(undefined4 *)(*(int *)(iVar8 + 0x7c) + iVar4);
      iVar4 = (uVar9 + 0x10) * 0x40;
      *(undefined4 *)(*(int *)(iVar8 + 0x7c) + iVar4) =
           *(undefined4 *)(*(int *)(iVar8 + 0x7c) + iVar2);
      iVar2 = (uVar9 + 8) * 0x40;
      *(undefined4 *)(*(int *)(iVar8 + 0x7c) + iVar2) =
           *(undefined4 *)(*(int *)(iVar8 + 0x7c) + iVar4);
      *(undefined4 *)(*(int *)(iVar8 + 0x7c) + uVar9 * 0x40) =
           *(undefined4 *)(*(int *)(iVar8 + 0x7c) + iVar2);
    }
    uVar9 = uVar9 + 1 & 0xffff;
  } while (uVar9 < 8);
  iVar8 = *DAT_020336b8;
  iVar2 = *(int *)(iVar8 + 0xdc);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else if (iVar2 == 3) {
    if (*(int *)(*DAT_020336e8 + (*(uint *)(iVar8 + 0xd0) & 0xffff) * 0x30 + 0x74) == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = 7;
    }
  }
  else if (iVar2 == 4) {
    if (*(int *)(*DAT_020336e8 + (*(uint *)(iVar8 + 0xd0) & 0xffff) * 0x30 + 0x74) == 1) {
      uVar3 = 0;
    }
    else {
      uVar3 = 7;
    }
  }
  else {
    uVar3 = 7;
  }
  LoadCupTrophyModel(8,uVar3);
  return;
}

