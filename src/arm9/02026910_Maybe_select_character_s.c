/* Decompiled C draft; module arm9; ROM address 02026910. No matching claim. */
#include "types.h"
#include "deps/02026910_Maybe_select_character_s.h"

void Maybe_select_character_s
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  short *psVar1;
  short *psVar2;
  short *psVar3;
  undefined4 uVar4;
  int iVar5;
  short *psVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  int *piVar11;
  int iVar12;
  undefined4 unaff_r4;
  short *psVar13;
  undefined4 local_4c [2];
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  uVar4 = Mem_CreateOrphanChildHeap();
  iVar5 = Mem_AllocateHeap(uVar4,DAT_02026c8c);
  *DAT_02026c90 = iVar5;
  Mem_CpuFastMemorySet(0,(undefined4 *)(uintptr_t)(iVar5),DAT_02026c8c);
  piVar11 = DAT_02026c90;
  *(undefined4 *)(*DAT_02026c90 + 0x5c) = uVar4;
  *(undefined4 *)(*piVar11 + 0x80) = param_2;
  iVar5 = GetGlobalCA_from_thumb();
  if (*(int *)(iVar5 + DAT_02026c94) == 0) {
    func_02025f80(*DAT_02026c90 + 0xf8,0,10,0xffffff80,0);
    func_02025f80(*DAT_02026c90 + DAT_02026c98,0,10,0x60,0);
    if (*DAT_02026c9c != 2) {
      func_020789e4();
    }
  }
  else if (*(int *)(iVar5 + DAT_02026c94) == 2) {
    func_02025f80(*DAT_02026c90 + 0xf8,1,10,0xffffff80,0);
    func_02025f80(*DAT_02026c90 + DAT_02026c98,1,10,0x60,0);
    if (*(int *)(*DAT_02026c90 + 0x80) == 1) {
      if (*(int *)(*DAT_02026ca0 + 4) == 8) {
        *(undefined1 *)(*DAT_02026ca0 + DAT_02026ca4) = 0xff;
      }
    }
    else if (*(int *)(*DAT_02026c90 + 0x80) == 2) {
      func_02121ee4();
    }
  }
  func_02025f80(*DAT_02026c90 + DAT_02026c94,0,10,0xffffffc0,0);
  piVar11 = DAT_02026c90;
  *(undefined4 *)(*DAT_02026c90 + 0x54) = param_3;
  *(undefined4 *)(*piVar11 + 0x58) = param_4;
  if (((*(int *)(*piVar11 + 0x80) == 0) &&
      (iVar5 = GetGlobalCA_from_thumb(), *(int *)(iVar5 + 200) != 3)) &&
     (iVar5 = GetGlobalCA_from_thumb(), *(int *)(iVar5 + 200) != 2)) {
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  iVar5 = DAT_02026ca8;
  piVar11 = DAT_02026c90;
  *(undefined4 *)(*DAT_02026c90 + DAT_02026ca8) = uVar4;
  if (*(int *)(*piVar11 + iVar5) != 0) {
    iVar5 = *(int *)(*piVar11 + 0x80);
    if (iVar5 == 0) {
      unaff_r4 = 0;
    }
    else if (iVar5 == 1) {
      unaff_r4 = 1;
    }
    else if (iVar5 == 2) {
      unaff_r4 = 2;
    }
    Maybe_mb_select_menu_etc_download_m_bg_00(unaff_r4,0);
  }
  iVar5 = *DAT_02026c90;
  iVar8 = *(int *)(iVar5 + 0x80);
  if (iVar8 == 0) {
    *(undefined4 *)(iVar5 + 0x78) = 0;
  }
  else if (iVar8 == 1) {
    piVar11 = (int *)*DAT_02026ca0;
    if (*piVar11 == 2) {
      uVar9 = (uint)*(ushort *)((int)piVar11 + DAT_02026cac);
    }
    else {
      uVar9 = 0;
    }
    *(uint *)(iVar5 + 0x78) =
         (uint)*(ushort *)((int)piVar11 + DAT_02026cb0 + ((uVar9 << 0x10) >> 0xd));
  }
  else if (iVar8 == 2) {
    uVar4 = func_020295e4();
    *(undefined4 *)(*DAT_02026c90 + 0x78) = uVar4;
  }
  iVar5 = *DAT_02026c90;
  if (*(int *)(iVar5 + DAT_02026ca8) == 0) {
    func_02025b20(iVar5,DAT_02026cbc,DAT_02026cc0,DAT_02026cc4,DAT_02026cb4,0,0,DAT_02026cb8);
    func_02025a50(0,*(undefined4 *)(*DAT_02026c90 + 0x5c),(int *)(uintptr_t)(iVar5));
    func_02025b20((int)(uintptr_t)(local_4c),DAT_02026ccc,DAT_02026cd0,0,DAT_02026cc8,0,0,DAT_02026cb8);
    func_02124748(0,local_44,local_4c[0],local_40,0,0,*(undefined4 *)(iVar5 + 8),
                  *(undefined4 *)(iVar5 + 0xc));
    func_02025b20(*DAT_02026c90 + 0x38,DAT_02026cd8,DAT_02026cdc,0,DAT_02026cd4,0,0,DAT_02026cb8);
    iVar8 = DAT_02026ce0;
    *(undefined4 *)(*(int *)(iVar5 + 0x18) + DAT_02026ce0) = 0;
    iVar12 = DAT_02026ce4;
    *(undefined4 *)(*(int *)(iVar5 + 0x18) + DAT_02026ce4) =
         *(undefined4 *)(*(int *)(iVar5 + 0x18) + iVar8);
    iVar8 = DAT_02026ce8;
    *(undefined4 *)(*(int *)(iVar5 + 0x18) + DAT_02026ce8) =
         *(undefined4 *)(*(int *)(iVar5 + 0x18) + iVar12);
    iVar12 = DAT_02026cec;
    *(undefined4 *)(*(int *)(iVar5 + 0x18) + DAT_02026cec) =
         *(undefined4 *)(*(int *)(iVar5 + 0x18) + iVar8);
    iVar8 = DAT_02026cf0;
    *(undefined4 *)(*(int *)(iVar5 + 0x18) + DAT_02026cf0) =
         *(undefined4 *)(*(int *)(iVar5 + 0x18) + iVar12);
    *(undefined4 *)(*(int *)(iVar5 + 0x18) + DAT_02026cf4) =
         *(undefined4 *)(*(int *)(iVar5 + 0x18) + iVar8);
  }
  if (*DAT_02026c9c == 2) {
    iVar5 = GetGlobalCA_from_thumb();
    if (*(int *)(iVar5 + 200) == 2) {
      func_0211f4b0(*(undefined4 *)(*DAT_02026c90 + 0x5c),*(undefined4 *)(*DAT_02026c90 + 0x58));
      func_0211f394();
    }
  }
  else {
    iVar8 = *DAT_02026c90;
    func_02025b20(iVar8 + 0x1c,DAT_02026d00,DAT_02026d04,DAT_02026d08,DAT_02026cf8,0,DAT_02026cfc,
                  DAT_02026cb8);
    func_02025a50(1,*(undefined4 *)(*DAT_02026c90 + 0x5c),(int *)(uintptr_t)(iVar8 + 0x1c));
    iVar5 = 0;
    *(undefined4 *)(*(int *)(iVar8 + 0x34) + DAT_02026d0c) = 0;
    psVar6 = DAT_02026d10;
    do {
      *(undefined4 *)(*(int *)(iVar8 + 0x34) + psVar6[2] * 0x40 + 0x10) = 1;
      *(undefined4 *)(*(int *)(iVar8 + 0x34) + psVar6[1] * 0x40 + 0x10) =
           *(undefined4 *)(*(int *)(iVar8 + 0x34) + psVar6[2] * 0x40 + 0x10);
      *(undefined4 *)(*(int *)(iVar8 + 0x34) + *psVar6 * 0x40 + 0x10) =
           *(undefined4 *)(*(int *)(iVar8 + 0x34) + psVar6[1] * 0x40 + 0x10);
      *(undefined4 *)(*(int *)(iVar8 + 0x34) + psVar6[2] * 0x40 + 0x34) = 0;
      *(undefined4 *)(*(int *)(iVar8 + 0x34) + psVar6[1] * 0x40 + 0x34) =
           *(undefined4 *)(*(int *)(iVar8 + 0x34) + psVar6[2] * 0x40 + 0x34);
      *(undefined4 *)(*(int *)(iVar8 + 0x34) + *psVar6 * 0x40 + 0x34) =
           *(undefined4 *)(*(int *)(iVar8 + 0x34) + psVar6[1] * 0x40 + 0x34);
      iVar12 = DAT_02026d14;
      psVar6 = psVar6 + 4;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0xc);
    *(undefined4 *)(*(int *)(iVar8 + 0x34) + DAT_02026d14) = 1;
    *(undefined4 *)(*(int *)(iVar8 + 0x34) + DAT_02026d18) =
         *(undefined4 *)(*(int *)(iVar8 + 0x34) + iVar12);
    iVar5 = DAT_02026d1c;
    *(undefined4 *)(*(int *)(iVar8 + 0x34) + DAT_02026d1c) = 0;
    *(undefined4 *)(*(int *)(iVar8 + 0x34) + DAT_02026d20) =
         *(undefined4 *)(*(int *)(iVar8 + 0x34) + iVar5);
  }
  piVar11 = DAT_02026c90;
  *(undefined4 *)(*DAT_02026c90 + 0x7c) = 8;
  iVar8 = *piVar11;
  puVar10 = DAT_02026d24;
  iVar5 = 0;
  do {
    iVar12 = iVar5;
    uVar4 = puVar10[1];
    *(undefined4 *)(iVar8 + 0x90) = *puVar10;
    *(undefined4 *)(iVar8 + 0x94) = uVar4;
    puVar10 = puVar10 + 2;
    iVar8 = iVar8 + 8;
    iVar5 = iVar12 + 1;
  } while (iVar5 < 8);
  iVar8 = CheckSavedSecretFlag_from_thumb(0x15);
  if (iVar8 != 0) {
    iVar8 = *DAT_02026c90;
    iVar5 = iVar8 + iVar5 * 8;
    uVar4 = DAT_02026d24[0x11];
    *(undefined4 *)(iVar5 + 0x90) = DAT_02026d24[0x10];
    *(undefined4 *)(iVar5 + 0x94) = uVar4;
    iVar5 = iVar12 + 2;
    *(int *)(iVar8 + 0x7c) = *(int *)(iVar8 + 0x7c) + 1;
  }
  iVar8 = CheckSavedSecretFlag_from_thumb(0x14);
  if (iVar8 != 0) {
    iVar12 = *DAT_02027060;
    iVar8 = iVar12 + iVar5 * 8;
    uVar4 = *(undefined4 *)(DAT_02027064 + 0x4c);
    *(undefined4 *)(iVar8 + 0x90) = *(undefined4 *)(DAT_02027064 + 0x48);
    *(undefined4 *)(iVar8 + 0x94) = uVar4;
    iVar5 = iVar5 + 1;
    *(int *)(iVar12 + 0x7c) = *(int *)(iVar12 + 0x7c) + 1;
  }
  iVar8 = CheckSavedSecretFlag_from_thumb(0x16);
  if (iVar8 != 0) {
    iVar12 = *DAT_02027060;
    iVar8 = iVar12 + iVar5 * 8;
    uVar4 = *(undefined4 *)(DAT_02027064 + 0x54);
    *(undefined4 *)(iVar8 + 0x90) = *(undefined4 *)(DAT_02027064 + 0x50);
    *(undefined4 *)(iVar8 + 0x94) = uVar4;
    iVar5 = iVar5 + 1;
    *(int *)(iVar12 + 0x7c) = *(int *)(iVar12 + 0x7c) + 1;
  }
  iVar8 = CheckSavedSecretFlag_from_thumb(0x17);
  if (iVar8 != 0) {
    iVar12 = *DAT_02027060;
    iVar8 = iVar12 + iVar5 * 8;
    uVar4 = *(undefined4 *)(DAT_02027064 + 0x5c);
    *(undefined4 *)(iVar8 + 0x90) = *(undefined4 *)(DAT_02027064 + 0x58);
    *(undefined4 *)(iVar8 + 0x94) = uVar4;
    iVar5 = iVar5 + 1;
    *(int *)(iVar12 + 0x7c) = *(int *)(iVar12 + 0x7c) + 1;
  }
  piVar11 = DAT_02027060;
  if (iVar5 < 0xc) {
    iVar8 = iVar5 << 3;
    do {
      *(undefined4 *)(*piVar11 + iVar8 + 0x90) = 0xffffffff;
      iVar8 = iVar8 + 8;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0xc);
  }
  piVar11 = DAT_02027060;
  iVar8 = 0;
  iVar5 = *DAT_02027060;
  if (0 < *(int *)(iVar5 + 0x7c)) {
    iVar12 = 0;
    do {
      iVar7 = GetGlobalCA_from_thumb();
      if (*(int *)(iVar5 + iVar12 + 0x90) == *(int *)(iVar7 + *(int *)(iVar5 + 0x78) * 0x18)) {
        *(int *)(iVar5 + 0x60) = iVar8;
      }
      iVar12 = iVar12 + 8;
      iVar8 = iVar8 + 1;
      iVar5 = *piVar11;
    } while (iVar8 < *(int *)(iVar5 + 0x7c));
  }
  piVar11 = DAT_02027060;
  *(undefined4 *)(*DAT_02027060 + 100) = *(undefined4 *)(*DAT_02027060 + 0x60);
  iVar8 = *piVar11;
  iVar5 = GetGlobalCA_from_thumb();
  *(undefined4 *)(iVar8 + 0xf0) = *(undefined4 *)(iVar5 + *(int *)(iVar8 + 0x78) * 0x18);
  if (*(int *)(*DAT_02027060 + 0xf0) == -1) {
    *(undefined4 *)(*DAT_02027060 + 0xf0) = 0;
  }
  uVar4 = func_02025e60(*(undefined4 *)(*DAT_02027060 + 0xf0));
  *(undefined4 *)(*DAT_02027060 + 0xf4) = uVar4;
  iVar5 = GetGlobalCA_from_thumb();
  *(undefined4 *)(iVar5 + *(int *)(*DAT_02027060 + 0x78) * 0x18) = 0xffffffff;
  iVar5 = GetGlobalCA_from_thumb();
  *(undefined4 *)(iVar5 + *(int *)(*DAT_02027060 + 0x78) * 0x18 + 4) = 0xffffffff;
  iVar5 = GetGlobalCA_from_thumb();
  piVar11 = DAT_02027060;
  *(undefined4 *)(iVar5 + *(int *)(*DAT_02027060 + 0x78) * 0x18 + 0x14) = 0;
  if (*DAT_02027068 != 2) {
    iVar12 = *piVar11;
    LoadPlayerGfxData_from_thumb(0,&local_30);
    iVar8 = 0;
    iVar5 = *DAT_02027060;
    if (0 < *(int *)(iVar5 + 0x7c)) {
      iVar7 = 0;
      psVar6 = DAT_0202706c;
      do {
        func_0212481c(*(undefined4 *)(iVar5 + iVar7 + 0x90),local_28,local_30,local_2c,local_24,1,
                      (int)psVar6[1],*(undefined4 *)(iVar12 + 0x24),*(undefined4 *)(iVar12 + 0x28));
        psVar6 = psVar6 + 4;
        iVar7 = iVar7 + 8;
        iVar8 = iVar8 + 1;
        iVar5 = *DAT_02027060;
      } while (iVar8 < *(int *)(iVar5 + 0x7c));
    }
  }
  psVar3 = DAT_0202707c;
  psVar2 = DAT_02027078;
  psVar1 = DAT_02027074;
  psVar6 = DAT_02027070;
  if (*DAT_02027068 != 2) {
    iVar5 = *DAT_02027060;
    psVar13 = (short *)0x0;
    switch(*(undefined4 *)(iVar5 + 0x7c)) {
    case 8:
      func_02027be0();
      psVar13 = psVar6;
      break;
    case 9:
      func_02027a58();
      psVar13 = psVar1;
      break;
    case 10:
      func_02027850();
      psVar13 = psVar2;
      break;
    case 0xb:
      func_02027648();
      psVar13 = psVar3;
      break;
    case 0xc:
      func_02027448();
    }
    if (psVar13 != (short *)0x0) {
      iVar8 = 0;
      psVar6 = DAT_0202706c;
      if (0 < *(int *)(*DAT_02027060 + 0x7c)) {
        do {
          func_02025c94((int)*psVar6,(int)*psVar13,(int)psVar13[1],*(undefined4 *)(iVar5 + 0x28));
          func_02025c94((int)psVar6[1],(int)*psVar13,(int)psVar13[1],*(undefined4 *)(iVar5 + 0x28));
          func_02025bb4((int)psVar6[3],(int)*psVar13,(int)psVar13[1],*(undefined4 *)(iVar5 + 0x2c));
          func_02025c94((int)psVar6[2],(*psVar13 + 3) * 0x10000 >> 0x10,
                        (psVar13[1] + 3) * 0x10000 >> 0x10,*(undefined4 *)(iVar5 + 0x28));
          psVar13 = psVar13 + 2;
          iVar8 = iVar8 + 1;
          psVar6 = psVar6 + 4;
        } while (iVar8 < *(int *)(*DAT_02027060 + 0x7c));
      }
      if (iVar8 < 0xc) {
        psVar6 = DAT_0202706c + iVar8 * 4;
        do {
          *(undefined4 *)(*(int *)(iVar5 + 0x34) + *psVar6 * 0x40) = 0;
          *(undefined4 *)(*(int *)(iVar5 + 0x34) + psVar6[1] * 0x40) = 0;
          *(undefined4 *)(*(int *)(iVar5 + 0x34) + psVar6[2] * 0x40) = 0;
          func_02025bb4((int)psVar6[3],DAT_02027080,DAT_02027080,*(undefined4 *)(iVar5 + 0x2c));
          psVar6 = psVar6 + 4;
          iVar8 = iVar8 + 1;
        } while (iVar8 < 0xc);
      }
    }
    func_020271e8();
    func_0202721c();
  }
  if (*(int *)(*DAT_02027060 + 0x80) == 0) {
    func_021170f8();
    func_021281c8(0xe);
    func_02128374();
  }
  iVar5 = Bright_IsBothScreensFadedIn();
  if (iVar5 == 0) {
    BrightCtx_SomeFnTopBottom(10);
    func_0202734c(0);
  }
  else {
    *(undefined4 *)(*DAT_02027060 + 0x6c) = 1;
  }
  if (*DAT_02027068 != 2) {
    func_02077f48(0);
  }
  func_02036820(*(undefined4 *)(*DAT_02027060 + 0x5c));
  return;
}

