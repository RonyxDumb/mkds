/* Decompiled C draft; module arm9; ROM address 0212a1e0. No matching claim. */
#include "types.h"
#include "deps/0212a1e0_InitializeKeyboardContext_from_thumb.h"

void InitializeKeyboardContext_from_thumb(undefined4 param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined2 *local_54;
  int local_50;
  int local_4c;
  int local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  uint local_1c;
  
  puVar2 = (undefined4 *)Mem_AllocateHeap(param_1,0xc4);
  *piRam0212a3fc = (int)puVar2;
  *puVar2 = param_1;
  uVar3 = CreateLoadSomeDisplayConfig_from_thumb(param_1);
  *(undefined4 *)(*piRam0212a3fc + 0xbc) = uVar3;
  uVar3 = GetKeyboardOam_from_thumb();
  CreateGlobalNN_from_thumb(param_1,uVar3);
  local_40 = 1;
  local_3c = GetLoadedFont_from_thumb();
  local_38 = 0;
  local_34 = 1;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 1;
  local_1c = (uint)(param_2 == 0xc);
  PrepareNavigationContextFiles_from_thumb();
  InitializeNavigationContext_from_thumb(param_1,&local_40);
  func_02129c18();
  Maybe_Keyboard_s_10key();
  uVar3 = GetKeyboardOam_from_thumb();
  uVar4 = func_02128884();
  OamBuffer_SomeFn_from_thumb(uVar3,uVar4);
  CreateGlobal78_from_thumb(0x20,0x40,0xc);
  func_020ab94c(0,0x28);
  func_0212a700();
  func_020aba94(0);
  piVar1 = piRam0212a3fc;
  *(short *)(*piRam0212a3fc + 0x70) = (short)param_2;
  *(undefined2 *)(*piVar1 + 0x72) = 0xffff;
  if (param_2 == 0xc) {
    *(undefined4 *)(*piVar1 + 4) = 0;
    *(undefined4 *)(*piVar1 + 0xc) = 0;
    *(undefined4 *)(*piVar1 + 0x1c) = 0;
    *(undefined4 *)(*piVar1 + 0x20) = 1;
  }
  else {
    *(undefined4 *)(*piVar1 + 4) = 1;
    *(undefined4 *)(*piVar1 + 0xc) = 5;
    *(undefined4 *)(*piVar1 + 0x1c) = 1;
    if (param_2 == 0xb) {
      *(undefined4 *)(*piVar1 + 0x20) = 0;
    }
    else {
      *(undefined4 *)(*piVar1 + 0x20) = 1;
    }
    func_0212a448();
  }
  iVar5 = *piRam0212a3fc;
  if (*(int *)(iVar5 + 4) == 0) {
    *(undefined4 *)(iVar5 + 8) = 0;
    func_020ab758(*puRam0212a400);
  }
  else {
    if (*(int *)*puRam0212a404 == 0) {
      *(undefined4 *)(iVar5 + 8) = 1;
    }
    else {
      *(undefined4 *)(iVar5 + 8) = 2;
    }
    func_020ab758(puRam0212a400[1]);
  }
  func_020ab9d0(*(undefined4 *)(*piRam0212a3fc + 8));
  func_02129e78();
  piVar1 = piRam0212a3fc;
  iVar8 = 0;
  iVar5 = 0;
  local_4c = 0;
  do {
    *(undefined4 *)(*piVar1 + iVar5 + 0x14) = 0;
    iVar5 = iVar5 + 4;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 2);
  *(undefined4 *)(*piVar1 + 0x24) = 0;
  *(undefined4 *)(*piVar1 + 0x10) = *(undefined4 *)(*piVar1 + 0xc);
  *(undefined4 *)(*piVar1 + 0x28) = 0;
  *(undefined2 *)(*piVar1 + 0x84) = 0xc0;
  piVar1 = piRam0212a3fc;
  local_54 = puRam0212a408;
  iVar5 = 0;
  do {
    iVar9 = 0;
    iVar8 = 0;
    puVar7 = local_54;
    do {
      *(undefined2 *)(iVar8 + iVar5 + *piVar1 + 0x86) = *puVar7;
      puVar7 = puVar7 + 1;
      iVar8 = iVar8 + 2;
      iVar9 = iVar9 + 1;
    } while (iVar9 < 2);
    local_54 = local_54 + 2;
    iVar5 = iVar5 + 4;
    local_4c = local_4c + 1;
  } while (local_4c < 2);
  uVar3 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam0212a40c);
  *(undefined4 *)(*piRam0212a3fc + 0xc0) = uVar3;
  iVar9 = 0;
  local_50 = 0;
  iVar10 = 0;
  local_48 = 0;
  iVar5 = local_48;
  iVar8 = local_48;
  do {
    do {
      iVar6 = iVar10 + *piRam0212a3fc;
      func_02124ed0(param_1,*(undefined4 *)(iVar6 + 0x9c),*(undefined4 *)(iVar6 + 0xac),
                    *piRam0212a3fc + 0x74 + iVar9 + iVar5);
      iVar8 = iVar8 + 1;
      iVar5 = iVar5 + 4;
    } while (iVar8 < 2);
    iVar9 = iVar9 + 8;
    iVar10 = iVar10 + 4;
    local_50 = local_50 + 1;
    iVar5 = local_48;
    iVar8 = local_48;
  } while (local_50 < 2);
  func_0212a604();
  iVar5 = 0;
  iVar8 = 0;
  do {
    Mem_CpuFill16(0,*piRam0212a3fc + 0x2c + iVar8,0x18);
    iVar8 = iVar8 + 0x18;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  func_0212a724();
  func_0212a670();
  func_0212a4f4();
  func_02129ea4();
  return;
}

