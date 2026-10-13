/* Decompiled C draft; module arm9; ROM address 02028864. No matching claim. */
#include "types.h"
#include "deps/02028864_Maybe_kart_select.h"

void Maybe_kart_select(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 unaff_r4;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 local_4c [2];
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_30 [2];
  undefined4 local_28;
  undefined4 local_24;
  
  uVar4 = Mem_CreateOrphanChildHeap();
  iVar5 = Mem_AllocateHeap(uVar4,uRam02028c10);
  *piRam02028c14 = iVar5;
  CARD_func_0054(iVar5,uRam02028c10);
  piVar2 = piRam02028c14;
  *(undefined4 *)(*piRam02028c14 + 0x8c) = uVar4;
  *(undefined4 *)(*piVar2 + 0xfc) = param_2;
  *(undefined4 *)(*piVar2 + iRam02028c18) = 0xffffffff;
  iVar5 = GetGlobalCA_from_thumb();
  if (*(int *)(iVar5 + iRam02028c1c) == 0) {
    func_02025f80(*piRam02028c14 + 0xac,0,10,0xffffff80,0);
    func_02025f80(*piRam02028c14 + 0xcc,0,10,0x60,0);
    iVar5 = func_020280dc();
    if (iVar5 == 0) {
      func_020789e4();
      func_02077f48(0);
    }
  }
  else if (*(int *)(iVar5 + iRam02028c1c) == 1) {
    func_02025f80(*piRam02028c14 + 0xac,1,10,0xffffff80,0);
    func_02025f80(*piRam02028c14 + 0xcc,1,10,0x60,0);
  }
  func_02025f80(*piRam02028c14 + 0xbc,0,10,0xffffffc0,0);
  func_02025f80(*piRam02028c14 + 0xdc,0,10,0x40,0);
  func_02025f80(*piRam02028c14 + 0xec,0,10,0xffffff40,0);
  piVar2 = piRam02028c14;
  *(undefined4 *)(*piRam02028c14 + 0x80) = param_3;
  *(undefined4 *)(*piVar2 + 0x84) = param_4;
  if (((*(int *)(*piVar2 + 0xfc) == 0) &&
      (iVar5 = GetGlobalCA_from_thumb(), *(int *)(iVar5 + 200) != 3)) &&
     (iVar5 = GetGlobalCA_from_thumb(), *(int *)(iVar5 + 200) != 2)) {
    uVar7 = 0;
  }
  else {
    uVar7 = 1;
  }
  iVar5 = iRam02028c20;
  piVar2 = piRam02028c14;
  *(undefined4 *)(*piRam02028c14 + iRam02028c20) = uVar7;
  if (*(int *)(*piVar2 + iVar5) != 0) {
    iVar5 = *(int *)(*piVar2 + 0xfc);
    if (iVar5 == 0) {
      unaff_r4 = 0;
    }
    else if (iVar5 == 1) {
      unaff_r4 = 1;
    }
    else if (iVar5 == 2) {
      unaff_r4 = 2;
    }
    Maybe_mb_select_menu_etc_download_m_bg_00(unaff_r4,1);
  }
  iVar5 = *(int *)(*piRam02028c14 + 0xfc);
  if (iVar5 == 0) {
    *(undefined4 *)(*piRam02028c14 + 0xa0) = 0;
  }
  else if (iVar5 == 1) {
    uVar7 = Maybe_helper_028d9c();
    *(undefined4 *)(*piRam02028c14 + 0xa0) = uVar7;
  }
  else if (iVar5 == 2) {
    uVar7 = func_020295e4();
    *(undefined4 *)(*piRam02028c14 + 0xa0) = uVar7;
  }
  iVar5 = func_020280dc();
  if (iVar5 == 0) {
    uVar7 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02028c24);
    piVar2 = piRam02028c14;
    *(undefined4 *)(*piRam02028c14 + 0x88) = uVar7;
    uVar7 = LoadKartAppearTablePointer_from_thumb(*(undefined4 *)(*piVar2 + 0x8c));
    *(undefined4 *)(*piRam02028c14 + 0x98) = uVar7;
  }
  iVar8 = *piRam02028c14;
  iVar5 = GetGlobalCA_from_thumb();
  *(undefined4 *)(iVar8 + 0xa4) = *(undefined4 *)(iVar5 + *(int *)(iVar8 + 0xa0) * 0x18);
  iVar8 = *piRam02028c14;
  iVar5 = GetGlobalCA_from_thumb();
  *(undefined4 *)(iVar8 + 0xa8) = *(undefined4 *)(iVar5 + *(int *)(iVar8 + 0xa0) * 0x18 + 4);
  if (*(int *)(*piRam02028c14 + 0xa4) == -1) {
    *(undefined4 *)(*piRam02028c14 + 0xa4) = 0;
  }
  if (*(int *)(*piRam02028c14 + 0xa8) == -1) {
    *(undefined4 *)(*piRam02028c14 + 0xa8) = 0;
  }
  iVar5 = GetGlobalCA_from_thumb();
  *(undefined4 *)(iVar5 + *(int *)(*piRam02028c14 + 0xa0) * 0x18 + 4) = 0xffffffff;
  iVar5 = GetGlobalCA_from_thumb();
  piVar2 = piRam02028c14;
  *(undefined4 *)(iVar5 + *(int *)(*piRam02028c14 + 0xa0) * 0x18 + 0x14) = 0;
  uVar7 = func_02025e34(*(undefined4 *)(*piVar2 + 0xa8));
  *(undefined4 *)(*piRam02028c14 + 0x9c) = uVar7;
  iVar5 = func_020280dc();
  if ((iVar5 == 0) && (iVar5 = *piRam02028c14, *(int *)(iVar5 + iRam02028c20) == 0)) {
    func_02025b20(iVar5 + 0x48,uRam02028c30,uRam02028c34,uRam02028c38,uRam02028c28,0,0,uRam02028c2c)
    ;
    func_02025a50(0,*(undefined4 *)(*piRam02028c14 + 0x8c),(int *)(uintptr_t)(iVar5 + 0x48));
    func_02025b20((int)(uintptr_t)(local_4c),uRam02028c40,uRam02028c44,0,uRam02028c3c,0,0,uRam02028c2c);
    func_02124748(1,local_44,local_4c[0],local_40,0,0,*(undefined4 *)(iVar5 + 0x50),
                  *(undefined4 *)(iVar5 + 0x54));
    func_02025b20((int)(uintptr_t)(local_30),uRam02028c4c,uRam02028c50,0,uRam02028c48,0,0,uRam02028c2c);
    func_02124748(*(undefined2 *)(iRam02028c54 + *(int *)(*piRam02028c14 + 0xa4) * 2),local_28,
                  local_30[0],local_24,0,2,*(undefined4 *)(iVar5 + 0x50),
                  *(undefined4 *)(iVar5 + 0x54));
    func_02124748(*(undefined2 *)(iRam02028c54 + *(int *)(*piRam02028c14 + 0xa4) * 2),local_28,
                  local_30[0],local_24,0,1,*(undefined4 *)(iVar5 + 0x50),
                  *(undefined4 *)(iVar5 + 0x54));
  }
  iVar5 = func_020280dc();
  if (iVar5 == 0) {
    func_020258d4(1,*piRam02028c14 + 0x24,uRam02028c5c,uRam02028c60,uRam02028c58,3,uRam02028c2c);
  }
  iVar5 = func_020280dc();
  if (iVar5 == 0) {
    iVar5 = func_02148ca0();
    iVar8 = *piRam02028c14;
    iVar9 = iVar8 + 100;
    func_02025b20(iVar9,uRam02028c70,uRam02028c74,uRam02028c78,uRam02028c64,uRam02028c68,
                  uRam02028c6c,uRam02028c2c);
    func_02025a50(1,*(undefined4 *)(*piRam02028c14 + 0x8c),(int *)(uintptr_t)(iVar9));
    iVar10 = 0;
    do {
      iVar6 = func_02025a00(1,*(undefined4 *)(*piRam02028c14 + 0x8c),iVar9,
                            (short *)(uintptr_t)(iRam02028c7c + iVar10 * 0xc),iVar5);
      iVar3 = iRam02028d8c;
      iVar5 = iVar5 - iVar6;
      iVar10 = iVar10 + 1;
    } while (iVar10 < 9);
    iVar5 = 0;
    do {
      uVar7 = Bmg_GetRawStringPointer_from_thumb
                        (*(undefined4 *)(*piRam02028d90 + 0x88),
                         *(undefined4 *)(iVar3 + iVar5 * 0xc + 8));
      iVar9 = (int)*(short *)(iVar3 + iVar5 * 0xc);
      func_0212426c(1,iVar9,*(undefined4 *)(iVar8 + 0x78),uVar7,*(undefined4 *)(iVar8 + 0x70),
                    *(undefined4 *)(iVar8 + 0x7c));
      func_02124094(iVar9,1,*(undefined4 *)(iVar8 + 0x78),*(undefined4 *)(iVar8 + 0x7c),
                    *(undefined4 *)(iVar8 + 0x70));
      iVar5 = iVar5 + 1;
    } while (iVar5 < 6);
    uVar7 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(uRam02028d94);
    uVar7 = Bmg_GetRawStringPointer_from_thumb(uVar7,*(undefined4 *)(iRam02028d8c + 0x50));
    sVar1 = *(short *)(iRam02028d98 + 8);
    func_0212426c(1,(int)sVar1,*(undefined4 *)(iVar8 + 0x78),uVar7,*(undefined4 *)(iVar8 + 0x70),
                  *(undefined4 *)(iVar8 + 0x7c));
    func_02124100((int)sVar1,1,*(undefined4 *)(iVar8 + 0x78),*(undefined4 *)(iVar8 + 0x7c),
                  *(undefined4 *)(iVar8 + 0x70));
    func_0212b928(*(undefined4 *)(*piRam02028d90 + 0x8c),*(undefined4 *)(iVar8 + 0x68),1);
    *(undefined4 *)(*(int *)(iVar8 + 0x7c) + 0x80) = 0;
    *(undefined4 *)(*(int *)(iVar8 + 0x7c) + 0xc0) = *(undefined4 *)(*(int *)(iVar8 + 0x7c) + 0x80);
  }
  else {
    func_0211f4b0(*(undefined4 *)(*piRam02028d90 + 0x8c),*(undefined4 *)(*piRam02028d90 + 0x84));
    func_0211f394();
  }
  func_02028e38();
  func_02029330();
  func_02028f20();
  iVar5 = func_020280dc();
  if (iVar5 == 0) {
    func_02128374();
  }
  iVar5 = func_0202811c();
  if (iVar5 == 2) {
    func_021281dc();
  }
  if (*(int *)(*piRam02028d90 + 0xfc) == 0) {
    func_02117060();
  }
  func_02036820(uVar4);
  return;
}

