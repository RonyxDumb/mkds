/* Decompiled C draft; module arm9; ROM address 0211b2cc. No matching claim. */
#include "types.h"
#include "deps/0211b2cc_Maybe_rule.h"

void Maybe_rule(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  ushort *puVar7;
  int iVar8;
  undefined4 *puVar9;
  ushort *puVar10;
  int iVar11;
  ushort *puVar12;
  int iVar13;
  undefined2 *puVar14;
  undefined2 *puVar15;
  int local_3c;
  undefined2 *local_38;
  undefined2 *local_34;
  undefined2 *local_30;
  undefined2 *local_2c;
  int *local_28;
  int local_24;
  undefined2 *local_20;
  int local_1c;
  int local_18;
  
  *DAT_0211b684 = *DAT_0211b684 & 0x43 | (ushort)DAT_0211b688;
  uVar3 = Mem_CreateOrphanChildHeap();
  iVar4 = Mem_AllocateHeap(uVar3,0xbc);
  piVar1 = DAT_0211b68c;
  *DAT_0211b68c = iVar4;
  *(undefined4 *)(iVar4 + 0x28) = uVar3;
  *(undefined4 *)(*piVar1 + 0x2c) = param_4;
  iVar8 = 0;
  *(undefined4 *)(*piVar1 + 0x30) = 0;
  *(undefined4 *)(*piVar1 + 0x60) = 0;
  *(undefined4 *)(*piVar1 + 100) = 4;
  *(undefined2 *)(*piVar1 + 0x58) = 0;
  *(undefined4 *)(*piVar1 + 0x7c) = 0;
  *(undefined4 *)(*piVar1 + 0x80) = 0;
  *(undefined4 *)(*piVar1 + 0x84) = 1;
  *(undefined2 *)(*piVar1 + 0x88) = 0;
  *(undefined2 *)(*piVar1 + 0x8a) = 0;
  *(undefined4 *)(*piVar1 + 0xb4) = param_3;
  *(undefined4 *)(*piVar1 + 0xb8) = 0;
  iVar4 = 0;
  iVar13 = 0;
  do {
    *(undefined2 *)(*piVar1 + iVar4 + 0xac) = 0;
    *(undefined2 *)(*piVar1 + iVar4 + 0xb0) = 0;
    piVar2 = DAT_0211b68c;
    iVar4 = iVar4 + 2;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 2);
  iVar4 = 0;
  iVar8 = 0;
  do {
    iVar11 = 0;
    iVar5 = 0;
    do {
      *(undefined2 *)(iVar5 + iVar4 + *piVar2 + 0x3c) = 0;
      piVar1 = DAT_0211b68c;
      iVar5 = iVar5 + 2;
      iVar11 = iVar11 + 1;
    } while (iVar11 < 2);
    iVar4 = iVar4 + 4;
    iVar13 = iVar13 + 1;
  } while (iVar13 < 5);
  iVar4 = 0;
  do {
    iVar13 = 0;
    iVar5 = 0;
    do {
      *(undefined2 *)(iVar5 + iVar4 + *piVar1 + 0x50) = 0;
      iVar5 = iVar5 + 2;
      iVar13 = iVar13 + 1;
    } while (iVar13 < 2);
    iVar4 = iVar4 + 4;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 2);
  func_0211db90();
  iVar4 = *DAT_0211b68c;
  func_02124ed0(*(undefined4 *)(iVar4 + 0x28),*(undefined4 *)(iVar4 + 4),
                *(undefined4 *)(iVar4 + 0xc),iVar4 + 0x14);
  uVar3 = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(DAT_0211b690);
  *(undefined4 *)(*DAT_0211b68c + 0x18) = uVar3;
  uVar3 = find_buf_fn_from_thumb(DAT_0211b694);
  piVar1 = DAT_0211b68c;
  *(undefined4 *)(*DAT_0211b68c + 0x1c) = uVar3;
  uVar6 = (uint)*(ushort *)(*(int *)(*piVar1 + 4) + 6);
  iVar4 = func_02148ca0();
  local_1c = 0;
  local_3c = 0;
  local_38 = DAT_0211b698;
  local_34 = DAT_0211b69c;
  local_30 = DAT_0211b6a0;
  local_2c = DAT_0211b6a4;
  local_28 = DAT_0211b6a8;
  local_24 = 0;
  local_18 = 0;
  do {
    local_20 = local_30;
    iVar8 = local_18;
    puVar14 = local_38;
    puVar15 = local_34;
    do {
      if ((local_1c != 3) || (iVar8 != 1)) {
        puVar9 = (undefined4 *)*DAT_0211b68c;
        iVar13 = func_021243ac(puVar9[10],*local_20,puVar9[3],*puVar15,*puVar14,iVar8 + local_3c,
                               *puVar9,puVar9[1],puVar9[5],iVar4);
        iVar4 = iVar4 - iVar13;
      }
      puVar14 = puVar14 + 1;
      puVar15 = puVar15 + 1;
      local_20 = local_20 + 1;
      iVar8 = iVar8 + 1;
    } while (iVar8 < 2);
    iVar8 = *DAT_0211b68c;
    uVar3 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar8 + 0x1c),*local_2c);
    func_0212426c(1,*local_30,*(undefined4 *)(*DAT_0211b68c + 0xc),uVar3,*(undefined4 *)(iVar8 + 4),
                  *(undefined4 *)(iVar8 + 0x14));
    if (local_1c != 3) {
      iVar8 = *DAT_0211b68c;
      uVar3 = Bmg_GetRawStringPointer_from_thumb
                        (*(undefined4 *)(iVar8 + 0x1c),
                         *(undefined2 *)(*local_28 + *(int *)(iVar8 + local_24 + 0x68) * 2));
      func_0212426c(1,local_30[1],*(undefined4 *)(*DAT_0211b68c + 0xc),uVar3,
                    *(undefined4 *)(iVar8 + 4),*(undefined4 *)(iVar8 + 0x14));
    }
    local_3c = local_3c + 2;
    local_38 = local_38 + 2;
    local_34 = local_34 + 2;
    local_30 = local_30 + 2;
    local_2c = local_2c + 1;
    local_28 = local_28 + 1;
    local_24 = local_24 + 4;
    local_1c = local_1c + 1;
  } while (local_1c < 5);
  if (*(int *)(*DAT_0211b6ac + 0x20) == 2) {
    puVar9 = (undefined4 *)*DAT_0211b68c;
    iVar8 = func_021243ac(puVar9[10],10,puVar9[3],200,0xf,uVar6 + 3,*puVar9,puVar9[1],puVar9[5],
                          iVar4);
    iVar8 = iVar4 - iVar8;
    iVar4 = *DAT_0211b68c;
    uVar3 = Bmg_GetRawStringPointer_from_thumb
                      (*(undefined4 *)(iVar4 + 0x1c),*(undefined2 *)(DAT_0211b6a8[3] + 4));
    func_0212426c(1,10,*(undefined4 *)(*DAT_0211b68c + 0xc),uVar3,*(undefined4 *)(iVar4 + 4),
                  *(undefined4 *)(iVar4 + 0x14));
  }
  else {
    puVar9 = (undefined4 *)*DAT_0211b68c;
    iVar13 = func_021243ac(puVar9[10],9,puVar9[3],0x96,0xf,uVar6 + 3,*puVar9,puVar9[1],puVar9[5],
                           iVar4);
    puVar9 = (undefined4 *)*DAT_0211b68c;
    iVar8 = func_021243ac(puVar9[10],10,puVar9[3],200,0xf,uVar6 + 9,*puVar9,puVar9[1],puVar9[5],
                          iVar4 - iVar13);
    iVar8 = (iVar4 - iVar13) - iVar8;
    iVar4 = *DAT_0211b68c;
    uVar3 = Bmg_GetRawStringPointer_from_thumb
                      (*(undefined4 *)(iVar4 + 0x1c),*(undefined2 *)(DAT_0211b6a8[3] + 4));
    func_0212426c(1,10,*(undefined4 *)(*DAT_0211b68c + 0xc),uVar3,*(undefined4 *)(iVar4 + 4),
                  *(undefined4 *)(iVar4 + 0x14));
  }
  puVar9 = (undefined4 *)*DAT_0211b68c;
  iVar4 = func_021243ac(puVar9[10],0xc,puVar9[3],0x37,0xf,uVar6 + 0xb,*puVar9,puVar9[1],puVar9[5],
                        iVar8);
  iVar8 = iVar8 - iVar4;
  iVar4 = *DAT_0211b68c;
  uVar3 = Bmg_GetRawStringPointer_from_thumb
                    (*(undefined4 *)(iVar4 + 0x1c),*(undefined2 *)(DAT_0211b6a8[4] + 4));
  func_0212426c(1,0xc,*(undefined4 *)(*DAT_0211b68c + 0xc),uVar3,*(undefined4 *)(iVar4 + 4),
                *(undefined4 *)(iVar4 + 0x14));
  if (*(int *)(*DAT_0211b6ac + 0x20) == 2) {
    puVar9 = (undefined4 *)*DAT_0211b68c;
    func_021243ac(puVar9[10],0xe,puVar9[3],200,0xd,0x2a,*puVar9,puVar9[1],puVar9[5],iVar8);
  }
  else {
    puVar9 = (undefined4 *)*DAT_0211b68c;
    iVar4 = func_021243ac(puVar9[10],0xd,puVar9[3],0x32,0xd,0x29,*puVar9,puVar9[1],puVar9[5],iVar8);
    iVar13 = *DAT_0211b68c;
    uVar3 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar13 + 0x18),4);
    func_0212426c(1,0xd,*(undefined4 *)(*DAT_0211b68c + 0xc),uVar3,*(undefined4 *)(iVar13 + 4),
                  *(undefined4 *)(iVar13 + 0x14));
    puVar9 = (undefined4 *)*DAT_0211b68c;
    func_021243ac(puVar9[10],8,puVar9[3],0x15,0xf,0x1f,*puVar9,puVar9[1],puVar9[5],iVar8 - iVar4);
  }
  func_0211d910(0);
  func_0211d844(0);
  switch(*(undefined4 *)(*DAT_0211b9c0 + 0x2c)) {
  case 2:
  case 4:
    func_021170f8();
    func_02116fb0();
    func_02117060();
    func_02116ef8();
    break;
  case 3:
  case 5:
    func_021170f8();
    func_02116fb0();
    func_02117060();
    func_02116ec0();
  }
  switch(*(undefined4 *)(*DAT_0211b9c0 + 0x2c)) {
  case 0:
  case 1:
    Maybe_mb_select_menu_etc_download_m_bg_00(0,2);
    break;
  case 2:
  case 3:
  case 4:
  case 5:
    Maybe_mb_select_menu_etc_download_m_bg_00(1,2);
  }
  func_0211bd84();
  iVar4 = func_0211cdec();
  if (iVar4 == 0) {
    func_0211bd10();
    func_0211d09c();
    func_0211cfd0();
  }
  piVar1 = DAT_0211b9c0;
  iVar4 = *DAT_0211b9c0;
  switch(*(undefined4 *)(iVar4 + 0x2c)) {
  case 0:
    *(undefined4 *)(iVar4 + 0x60) = 1;
    if (*(int *)(*piVar1 + 0x6c) == 0) {
      func_0211ccac(0);
    }
    *(undefined4 *)(*DAT_0211b9c0 + 0x60) = 0;
    break;
  case 1:
    *(undefined2 *)(iVar4 + 0x58) = 0xffe4;
    *(undefined4 *)(*piVar1 + 0x60) = 1;
    if (*(int *)(*piVar1 + 0x6c) == 0) {
      func_0211ccac(0);
    }
    piVar1 = DAT_0211b9c0;
    *(undefined4 *)(*DAT_0211b9c0 + 0x60) = 3;
    if (*(int *)(*piVar1 + 0x74) == 1) {
      func_0211cb6c(0);
    }
    *(undefined4 *)(*DAT_0211b9c0 + 0x60) = 1;
    break;
  case 2:
    *(undefined2 *)(iVar4 + 0x58) = 0xffe4;
    *(undefined4 *)(*piVar1 + 0x60) = 1;
    iVar4 = func_0211d650();
    if (iVar4 == 8) {
      *(undefined4 *)(*DAT_0211b9c0 + 0x60) = 2;
    }
    break;
  case 3:
    *(undefined4 *)(iVar4 + 0x60) = 3;
    if (*(int *)(*piVar1 + 0x74) == 1) {
      func_0211cb6c(0);
    }
    *(undefined4 *)(*DAT_0211b9c0 + 0x60) = 1;
    iVar4 = func_0211d650();
    if (iVar4 == 8) {
      *(undefined4 *)(*DAT_0211b9c0 + 0x60) = 3;
    }
    break;
  case 5:
    *(undefined2 *)(iVar4 + 0x58) = 0xffe4;
    *(undefined4 *)(*piVar1 + 0x60) = 3;
    if (*(int *)(*piVar1 + 0x74) == 1) {
      func_0211cb6c(0);
    }
    *(undefined4 *)(*DAT_0211b9c0 + 0x60) = 1;
    iVar4 = func_0211d650();
    if (iVar4 == 8) {
      *(undefined4 *)(*DAT_0211b9c0 + 0x60) = 2;
    }
  }
  puVar7 = DAT_0211b9c4;
  piVar1 = DAT_0211b9c0;
  iVar4 = *DAT_0211b9c0;
  switch(*(undefined4 *)(iVar4 + 0x2c)) {
  case 1:
    *(undefined4 *)(*(int *)(iVar4 + 0x14) + (uVar6 + *DAT_0211b9c4) * 0x40) = 0;
    break;
  case 2:
    *(undefined4 *)(*(int *)(iVar4 + 0x14) + (uVar6 + *DAT_0211b9c4) * 0x40) = 0;
    break;
  case 3:
    iVar8 = 0;
    *(undefined4 *)(*(int *)(iVar4 + 0x14) + (uVar6 + *DAT_0211b9c4) * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar1 + 0x14) + (uVar6 + puVar7[4]) * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar1 + 0x14) + (uVar6 + puVar7[1]) * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar1 + 0x14) + (uVar6 + puVar7[5]) * 0x40) = 0;
    puVar7 = DAT_0211b9d0;
    puVar10 = DAT_0211b9cc;
    puVar12 = DAT_0211b9c8;
    do {
      *(undefined4 *)(*(int *)(*piVar1 + 0x14) + (uint)*puVar12 * 0x40) = 0;
      *(undefined4 *)(*(int *)(*piVar1 + 0x14) + (uint)puVar12[4] * 0x40) = 0;
      *(undefined4 *)(*(int *)(*piVar1 + 0x14) + (uint)*puVar10 * 0x40) = 0;
      *(undefined4 *)(*(int *)(*piVar1 + 0x14) + (uint)puVar10[4] * 0x40) = 0;
      *(undefined4 *)(*(int *)(*piVar1 + 0x14) + (uint)*puVar7 * 0x40) = 0;
      *(undefined4 *)(*(int *)(*piVar1 + 0x14) + (uint)puVar7[4] * 0x40) = 0;
      puVar12 = puVar12 + 1;
      puVar10 = puVar10 + 1;
      puVar7 = puVar7 + 1;
      iVar8 = iVar8 + 1;
    } while (iVar8 < 2);
    break;
  case 5:
    *(undefined4 *)(*(int *)(iVar4 + 0x14) + (uVar6 + *DAT_0211b9c4) * 0x40) = 0;
  }
  iVar4 = func_0211d650();
  piVar1 = DAT_0211b9c0;
  if (iVar4 == 8) {
    iVar4 = *(int *)(*DAT_0211b9c0 + 0x6c);
    while (iVar4 != 0) {
      func_0211cb6c(0);
      iVar4 = *(int *)(*piVar1 + 0x6c);
    }
  }
  func_0211baec();
  puVar9 = (undefined4 *)*DAT_0211b9c0;
  func_02116dd4(puVar9[10],*puVar9,puVar9[1],0x2a,0xe,1);
  if (*DAT_0211b9d4 != 2) {
    func_0212b928(*(undefined4 *)(*DAT_0211b9c0 + 0x28),*(undefined4 *)(*DAT_0211b9c0 + 0x10),9);
  }
  func_02036820(*(undefined4 *)(*DAT_0211b9c0 + 0x28));
  func_0211d9dc();
  return;
}

