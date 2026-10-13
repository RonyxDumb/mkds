/* Decompiled C draft; module arm9; ROM address 02029dcc. No matching claim. */
#include "types.h"
#include "deps/02029dcc_InstanceStructM_from_thumb.h"

void InstanceStructM_from_thumb(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  ushort *puVar6;
  uint uVar7;
  int iVar8;
  short *psVar9;
  int iVar10;
  int local_108;
  int local_104;
  undefined1 auStack_e8 [20];
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined1 auStack_ac [32];
  int local_8c;
  undefined1 auStack_88 [20];
  undefined2 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined1 auStack_54 [36];
  undefined4 local_30 [2];
  undefined4 local_28;
  undefined4 local_24;
  
  iVar3 = Mem_AllocateHeap(param_1,0x60);
  *piRam0202a1a0 = iVar3;
  Mem_CpuFastMemorySet(0,iVar3,0x60);
  piVar1 = piRam0202a1a0;
  *(undefined4 *)(*piRam0202a1a0 + 0x38) = param_2;
  *(undefined4 *)(*piVar1 + 0x3c) = param_3;
  uVar4 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam0202a1a4);
  *(undefined4 *)(*piRam0202a1a0 + 0x4c) = uVar4;
  uVar4 = find_buf_fn_from_thumb(uRam0202a1a8);
  piVar1 = piRam0202a1a0;
  *(undefined4 *)(*piRam0202a1a0 + 0x50) = uVar4;
  piVar2 = piRam0202a1ac;
  *(undefined4 *)(*piVar1 + 0x40) = *(undefined4 *)(*piRam0202a1ac + 0x84);
  *(undefined4 *)(*piVar1 + 0x48) = *(undefined4 *)(*piVar2 + 0x7c);
  if (*(int *)(*piVar1 + 0x48) < 0) {
    *(undefined4 *)(*piVar1 + 0x48) = 0;
  }
  *(undefined4 *)(*piRam0202a1a0 + 0x44) = *(undefined4 *)(*piRam0202a1ac + 0x80);
  func_02062860();
  iVar3 = CreateDisplayConfig(param_1,uRam0202a1b0);
  DisplayEngineConfig_SetBg1Config(iVar3 + 0x28,2,0,0,0,0x10,6,0);
  DisplayEngineConfig_SetBg3Config(iVar3 + 0x28,3,0,0,0,2,6);
  DisplayEngineConfig_SetBg3Config(iVar3 + 0x70,3,0,0,0,1,6);
  SetGlobalDisplayConfig(iVar3);
  local_d4 = 1;
  local_d0 = GetLoadedFont_from_thumb();
  local_cc = 0;
  local_c8 = 1;
  local_c4 = 0;
  local_c0 = 0;
  local_bc = 0;
  local_b8 = 0;
  local_b4 = 0;
  local_b0 = 0;
  PrepareNavigationContextFiles_from_thumb();
  InitializeNavigationContext_from_thumb(param_1,&local_d4);
  func_02025854(0,auStack_ac,uRam0202a1bc,uRam0202a1c0,uRam0202a1b4,1,uRam0202a1b8);
  uVar4 = find_buf_fn_from_thumb(uRam0202a1c4);
  MaybeReadScreenBlock_0(&local_8c,uVar4);
  AllocateReserveTEQSub(0xb,0,local_8c + 0xc,*(undefined4 *)(local_8c + 8));
  uVar4 = func_02148cb8();
  iVar8 = *piRam0202a1a0;
  PlayerGfxData_Create_from_thumb
            (iVar8,uRam0202a1d0,uRam0202a1d4,uRam0202a1d8,uRam0202a1c8,uRam0202a1cc,0,uRam0202a1b8);
  func_02025a50(0,param_1,iVar8);
  CopyMemory16(*(int *)*puRam0202a1dc + 0xc,auStack_88,0x14);
  local_74 = 0;
  func_021243ac(param_1,0,*(undefined4 *)(iVar8 + 0x14),0x82,0xd,0x14,*(undefined4 *)(iVar8 + 8),
                *(undefined4 *)(iVar8 + 0xc),*(undefined4 *)(iVar8 + 0x18),uVar4);
  func_0212426c(0,0,*(undefined4 *)(iVar8 + 0x14),auStack_88,*(undefined4 *)(iVar8 + 0xc),
                *(undefined4 *)(iVar8 + 0x18));
  func_02124094(0,1,*(undefined4 *)(iVar8 + 0x14),*(undefined4 *)(iVar8 + 0x18),
                *(undefined4 *)(iVar8 + 0xc));
  iVar3 = 0;
  puVar6 = puRam0202a1e0;
  do {
    *(uint *)(*(int *)(iVar8 + 0x18) + (uint)*puVar6 * 0x40) =
         (uint)(iVar3 == *(int *)(*piRam0202a1a0 + 0x48));
    puVar6 = puVar6 + 1;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  iVar3 = 0;
  puVar6 = puRam0202a1e4;
  do {
    *(uint *)(*(int *)(iVar8 + 0x18) + (uint)*puVar6 * 0x40) =
         (uint)(iVar3 == *(int *)(*piRam0202a1a0 + 0x44));
    puVar6 = puVar6 + 1;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  *(uint *)(*(int *)(iVar8 + 0x18) + 0xc0) = (uint)(2 < *(int *)(*piRam0202a1a0 + 0x48));
  *(undefined4 *)(*(int *)(iVar8 + 0x18) + 0x80) = *(undefined4 *)(*(int *)(iVar8 + 0x18) + 0xc0);
  *(uint *)(*(int *)(iVar8 + 0x18) + 0x40) = (uint)(*(int *)(*(int *)(iVar8 + 0x18) + 0x80) == 0);
  **(undefined4 **)(iVar8 + 0x18) = (*(undefined4 **)(iVar8 + 0x18))[0x10];
  uVar4 = *(undefined4 *)(*piRam0202a1ac + 0x90);
  iVar3 = *piRam0202a1a0;
  LoadPlayerGfxData_from_thumb(1,&local_70);
  func_0212463c(uVar4,local_68,local_70,local_6c,local_64,0,0x14,*(undefined4 *)(iVar3 + 8),
                *(undefined4 *)(iVar3 + 0xc));
  func_02025854(1,auStack_54,uRam0202a1ec,uRam0202a1f0,uRam0202a1e8,3,uRam0202a1b8);
  iVar3 = func_02148ca0();
  iVar8 = *piRam0202a1a0;
  iVar10 = iVar8 + 0x1c;
  PlayerGfxData_Create_from_thumb
            (iVar10,uRam0202a1fc,uRam0202a200,uRam0202a204,uRam0202a1f4,uRam0202a1f8,0,uRam0202a1b8)
  ;
  func_02025a50(1,param_1,iVar10);
  local_104 = 0;
  psVar9 = psRam0202a208;
  do {
    iVar5 = func_02025a00(1,param_1,iVar10,psVar9,iVar3);
    iVar3 = iVar3 - iVar5;
    psVar9 = psVar9 + 6;
    local_104 = local_104 + 1;
  } while (local_104 < 0x10);
  uVar4 = Bmg_GetRawStringPointer_from_thumb
                    (*(undefined4 *)(*piRam0202a1a0 + 0x4c),
                     *(undefined2 *)(iRam0202a20c + *(int *)(*piRam0202a1ac + 0x88) * 2));
  iVar10 = 0;
  psVar9 = psRam0202a208;
  iVar3 = 0;
  do {
    iVar5 = iVar3;
    func_0212426c(1,(int)*psVar9,*(undefined4 *)(iVar8 + 0x30),uVar4,*(undefined4 *)(iVar8 + 0x28),
                  *(undefined4 *)(iVar8 + 0x34));
    psVar9 = psVar9 + 6;
    iVar3 = iVar5 + 1;
    iVar10 = iVar10 + 1;
  } while (iVar10 < 2);
  if (*(int *)(*piRam0202a1ac + 0x8c) == 0) {
    iVar3 = iVar5 + 3;
  }
  else {
    uVar4 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam0202a1a0 + 0x4c),0x71);
    iVar10 = 0;
    psVar9 = psRam0202a208 + iVar3 * 6;
    do {
      func_0212426c(1,(int)*psVar9,*(undefined4 *)(iVar8 + 0x30),uVar4,*(undefined4 *)(iVar8 + 0x28)
                    ,*(undefined4 *)(iVar8 + 0x34));
      psVar9 = psVar9 + 6;
      iVar3 = iVar3 + 1;
      iVar10 = iVar10 + 1;
    } while (iVar10 < 2);
  }
  iVar10 = 0;
  local_108 = 0;
  psVar9 = psRam0202a208 + iVar3 * 6;
  do {
    uVar4 = GetBmgIndexFromCircuitIndex_from_thumb
                      (*(undefined4 *)
                        (iVar10 + iRam0202a210 + *(int *)(*piRam0202a1a0 + 0x40) * 0x10));
    uVar4 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam0202a1a0 + 0x4c),uVar4);
    func_0212426c(1,(int)*psVar9,*(undefined4 *)(iVar8 + 0x30),uVar4,*(undefined4 *)(iVar8 + 0x28),
                  *(undefined4 *)(iVar8 + 0x34));
    psVar9 = psVar9 + 6;
    iVar3 = iVar3 + 1;
    iVar10 = iVar10 + 4;
    local_108 = local_108 + 1;
  } while (local_108 < 4);
  iVar10 = 0;
  psVar9 = psRam0202a208 + iVar3 * 6;
  do {
    func_0202a340(auStack_e8,iVar10);
    func_02124224(1,(int)*psVar9,*(undefined4 *)(iVar8 + 0x30),auStack_e8,
                  *(undefined4 *)(iVar8 + 0x28),*(undefined4 *)(iVar8 + 0x34),7);
    func_02124224(1,(int)*(short *)(iRam0202a31c + (iVar3 + 4) * 0xc),*(undefined4 *)(iVar8 + 0x30),
                  auStack_e8,*(undefined4 *)(iVar8 + 0x28),*(undefined4 *)(iVar8 + 0x34),7);
    psVar9 = psVar9 + 6;
    iVar3 = iVar3 + 1;
    iVar10 = iVar10 + 1;
  } while (iVar10 < 4);
  iVar3 = *piRam0202a320;
  PlayerGfxData_Create_from_thumb
            (local_30,uRam0202a32c,uRam0202a330,0,uRam0202a324,0,0,uRam0202a328);
  func_02124748(*(undefined2 *)(iRam0202a334 + *(int *)(*piRam0202a320 + 0x40) * 2),local_28,
                local_30[0],local_24,1,0,*(undefined4 *)(iVar3 + 0x24),*(undefined4 *)(iVar3 + 0x28)
               );
  func_020629a4();
  LoadCupTrophyModel(*(undefined4 *)(*piRam0202a320 + 0x40),
                     *(uint *)(*piRam0202a320 + 0x48) & 0xffff);
  uVar7 = 0xffffffff;
  iVar3 = *(int *)(*piRam0202a320 + 0x44);
  if (iVar3 == 5) {
    uVar7 = 0x1e;
  }
  else if (iVar3 == 6) {
    uVar7 = 0x1f;
  }
  else if (iVar3 == 7) {
    uVar7 = 0x20;
  }
  if (-1 < (int)uVar7) {
    NNSi_MaybeSndPlayerStartSeq(uRam0202a338,0,uVar7 & 0xffff);
  }
  iVar3 = CheckUpdateGrandPrixResult();
  if (iVar3 != 0) {
    WaitForWorkerTask();
    if (*(int *)(*piRam0202a33c + 0xc) != 0) {
      func_02145d38();
    }
    uVar4 = GetCurrentUnlockedSecretFlagsAndSaveIfResultScene();
    *(undefined4 *)(*piRam0202a320 + 0x58) = uVar4;
  }
  return;
}

