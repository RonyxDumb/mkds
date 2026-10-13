/* Decompiled C draft; module arm9; ROM address 02028130. No matching claim. */
#include "types.h"
#include "deps/02028130_func_02028130.h"

int func_02028130(void)

{
  int *piVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int local_20;
  
  iVar9 = *DAT_020284c0;
  iVar3 = *(int *)(iVar9 + 0xa8);
  iVar8 = 0;
  local_20 = 0;
  uVar4 = GetDirectInputUnitIndex();
  func_02025edc(*DAT_020284c0 + 0xac);
  func_02025edc(*DAT_020284c0 + 0xbc);
  func_02025edc(*DAT_020284c0 + 0xcc);
  func_02025edc(*DAT_020284c0 + 0xdc);
  func_02025edc(*DAT_020284c0 + 0xec);
  func_02029008();
  iVar5 = func_020280dc();
  if (iVar5 == 0) {
    func_0212b80c();
  }
  iVar5 = func_020280dc();
  if (iVar5 == 0) {
    uVar6 = func_020290fc();
    *(undefined4 *)(*DAT_020284c0 + DAT_020284c4) = uVar6;
  }
  else {
    *(undefined4 *)(*DAT_020284c0 + DAT_020284c4) = 0xffffffff;
  }
  piVar1 = DAT_020284c0;
  iVar5 = *DAT_020284c0;
  switch(*(undefined4 *)(iVar5 + 0x94)) {
  case 0:
    if (*(int *)(iVar5 + 0xec) == 1) {
      *(undefined4 *)(iVar5 + 0x90) = 0;
      iVar3 = func_020280dc();
      if (iVar3 == 0) {
        uVar4 = 2;
      }
      else {
        uVar4 = 1;
      }
      *(undefined4 *)(*DAT_020284c0 + 0x94) = uVar4;
    }
    func_02028fac();
    break;
  case 1:
    func_02028824(*(uint *)(iVar5 + 0xa8) & 0xff | 0x80);
    piVar1 = DAT_020284c0;
    *(undefined4 *)(*DAT_020284c0 + DAT_020284c8) = 1;
    *(undefined4 *)(*piVar1 + 0x94) = 5;
    break;
  case 2:
    iVar5 = func_02028774(uVar4);
    if (iVar5 != 0) {
      uVar6 = func_0202874c(uVar4);
      uVar7 = func_02028724(uVar4);
      local_20 = func_02128210(uVar6,uVar7);
    }
    iVar5 = func_020286f4(uVar4,1);
    if (((iVar5 == 0) && (*(int *)(*DAT_020284c0 + DAT_020284c4) != 2)) &&
       (iVar5 = func_02028f84(), iVar5 == 0)) {
      iVar5 = func_020286f4(uVar4,2);
      piVar1 = DAT_020284c0;
      if ((iVar5 == 0) && (local_20 == 0)) {
        iVar5 = func_020ae408(uVar4,0x10);
        if ((iVar5 == 0) && (iVar5 = func_020290ac(1), iVar5 == 0)) {
          iVar5 = func_020ae408(uVar4,0x20);
          if ((iVar5 != 0) || (iVar5 = func_020290ac(0), iVar5 != 0)) {
            func_02029248();
            *(undefined2 *)(*DAT_020284c0 + DAT_020284d4) = 2;
            **(undefined4 **)(iVar9 + 0x7c) = 0;
            *(undefined4 *)(*(int *)(iVar9 + 0x7c) + 0x80) = 1;
          }
        }
        else {
          func_020292bc();
          *(undefined2 *)(*DAT_020284c0 + DAT_020284d4) = 3;
          *(undefined4 *)(*(int *)(iVar9 + 0x7c) + 0x40) = 0;
          *(undefined4 *)(*(int *)(iVar9 + 0x7c) + 0xc0) = 1;
        }
      }
      else {
        *(undefined4 *)(*DAT_020284c0 + 0x90) = 0;
        *(undefined4 *)(*piVar1 + DAT_020284c8) = 2;
        func_0202941c();
        func_02025f14(*DAT_020284c0 + 0xbc,2);
        func_02025f14(*DAT_020284c0 + 0xdc,2);
        func_02025f14(*DAT_020284c0 + 0xec,2);
        piVar1 = DAT_020284c0;
        *(undefined4 *)(*DAT_020284c0 + 0x94) = 7;
        func_02128310(*(int *)(*piVar1 + 0xfc) != 0);
      }
    }
    else {
      piVar1 = DAT_020284c0;
      *(undefined4 *)(*DAT_020284c0 + 0x90) = 0;
      *(undefined4 *)(*piVar1 + DAT_020284c8) = 1;
      *(undefined4 *)(*piVar1 + 0x94) = 4;
      *(undefined4 *)(*(int *)(iVar9 + 0x7c) + DAT_020284cc) = 0;
      func_02124100((int)*(short *)(DAT_020284d0 + 8),0,*(undefined4 *)(iVar9 + 0x78),
                    *(undefined4 *)(iVar9 + 0x7c),*(undefined4 *)(iVar9 + 0x70));
      uVar4 = func_02025eb0(*(undefined4 *)(*DAT_020284c0 + 0xa4));
      func_021106a8(uVar4,1);
      func_02077f48(1);
      func_0212b7e8();
    }
    if (iVar3 != *(int *)(*DAT_020284c0 + 0xa8)) {
      func_02110698();
      func_02028f20();
      func_02028e38();
      piVar1 = DAT_020284c0;
      *(undefined4 *)(*DAT_020284c0 + 0x94) = 3;
      *(undefined4 *)(*piVar1 + 0x90) = 0;
    }
    break;
  case 3:
    *(int *)(iVar5 + 0x90) = *(int *)(iVar5 + 0x90) + 1;
    if (*(int *)(*piVar1 + 0x90) < 7) {
      sVar2 = func_020adc64();
      if (*(ushort *)(*DAT_020284c0 + DAT_020284d4) == 2) {
        sVar2 = -sVar2;
      }
      *(short *)(*(int *)(iVar9 + 0x7c) + (uint)*(ushort *)(*DAT_020284c0 + DAT_020284d4) * 0x40 + 4
                ) = sVar2;
    }
    else {
      *(undefined4 *)(*piVar1 + 0x90) = 0;
      *(undefined4 *)(*piVar1 + 0x94) = 2;
      *(undefined2 *)(*(int *)(iVar9 + 0x7c) + (uint)*(ushort *)(*piVar1 + DAT_020284d4) * 0x40 + 4)
           = 0;
      *(undefined4 *)(*(int *)(iVar9 + 0x7c) + 0x40) = 1;
      **(undefined4 **)(iVar9 + 0x7c) = 1;
      *(undefined4 *)(*(int *)(iVar9 + 0x7c) + 0xc0) = 0;
      *(undefined4 *)(*(int *)(iVar9 + 0x7c) + 0x80) = 0;
    }
    break;
  case 4:
    *(int *)(iVar5 + 0x90) = *(int *)(iVar5 + 0x90) + 1;
    iVar3 = *piVar1;
    if (4 < *(int *)(iVar3 + 0x90)) {
      iVar5 = *(int *)(iVar3 + 0xfc);
      if (iVar5 == 0) {
        iVar5 = GetGlobalCA_from_thumb();
        *(undefined4 *)(iVar5 + *(int *)(*DAT_020284c0 + 0xa0) * 0x18 + 4) =
             *(undefined4 *)(iVar3 + 0xa8);
        iVar3 = GetGlobalCA_from_thumb();
        *(undefined4 *)(iVar3 + *(int *)(*DAT_020284c0 + 0xa0) * 0x18 + 0x14) = 1;
        func_02116ef8();
        *(undefined4 *)(*DAT_020284c0 + 0x94) = 6;
      }
      else if (iVar5 == 1) {
        func_021282c8();
        func_02028824(*(uint *)(*DAT_020284c0 + 0xa8) & 0xff | 0x80);
        *(undefined4 *)(*DAT_020284c0 + 0x94) = 5;
      }
      else if (iVar5 == 2) {
        func_021282c8();
        func_02121eb4(*(undefined4 *)(*DAT_020286dc + 0xa8));
        *(undefined4 *)(*DAT_020286dc + 0x94) = 5;
      }
      *(undefined4 *)(*DAT_020286dc + 0x90) = 0;
      *(undefined4 *)(*(int *)(iVar9 + 0x7c) + DAT_020286e0) = 1;
      func_02124100((int)*(short *)(DAT_020286e4 + 8),1,*(undefined4 *)(iVar9 + 0x78),
                    *(undefined4 *)(iVar9 + 0x7c),*(undefined4 *)(iVar9 + 0x70));
    }
    break;
  case 5:
    if (((*(int *)(iVar5 + 0xfc) == 1) && (iVar3 = func_0202b888(), iVar3 != 0)) ||
       ((*(int *)(*DAT_020286dc + 0xfc) == 2 && (iVar3 = func_02121d0c(), iVar3 != 0)))) {
      piVar1 = DAT_020286dc;
      *(undefined4 *)(*DAT_020286dc + 0x90) = 0;
      *(undefined4 *)(*piVar1 + 0x94) = 6;
    }
    break;
  case 6:
    *(int *)(iVar5 + 0x90) = *(int *)(iVar5 + 0x90) + 1;
    if (0x3c < *(int *)(*piVar1 + 0x90)) {
      func_02025f14(*piVar1 + 0xac,2);
      func_02025f14(*DAT_020286dc + 0xbc,2);
      func_02025f14(*DAT_020286dc + 0xcc,2);
      func_02025f14(*DAT_020286dc + 0xdc,2);
      func_02025f14(*DAT_020286dc + 0xec,2);
      if (*(int *)(*DAT_020286dc + 0xfc) == 2) {
        func_021219cc();
        func_0202941c(3);
      }
      else {
        func_0202941c(2);
      }
      iVar3 = func_020280dc();
      if (iVar3 == 0) {
        func_020789d4();
      }
      else {
        func_0211f378();
      }
      piVar1 = DAT_020286dc;
      *(undefined4 *)(*DAT_020286dc + 0x90) = 0;
      *(undefined4 *)(*piVar1 + 0x94) = 7;
    }
    break;
  case 7:
    if (*(int *)(iVar5 + 0xec) == 3) {
      iVar3 = GetGlobalCA_from_thumb();
      piVar1 = DAT_020286dc;
      *(uint *)(iVar3 + *(int *)(*DAT_020286dc + 0xa0) * 0x18 + 0x14) =
           (uint)(*(int *)(iVar5 + DAT_020286e8) == 1);
      *(undefined4 *)(*piVar1 + 0x94) = 8;
    }
    func_02028fac();
    break;
  case 8:
    iVar8 = *(int *)(iVar5 + DAT_020286e8);
  }
  iVar3 = func_020280dc();
  if (iVar3 == 0) {
    func_02078a9c(*(undefined4 *)(*DAT_020286dc + 0xa4));
    func_02078a34(*(undefined4 *)(*DAT_020286dc + 0xa8));
    iVar3 = GetGlobalCA_from_thumb();
    func_02078420(*(undefined4 *)(iVar3 + 0xd8));
    func_020780f4();
  }
  if (*(int *)(*DAT_020286dc + DAT_020286ec) == 0) {
    func_02124c30(*(undefined4 *)(iVar9 + 0x54),*(undefined4 *)(iVar9 + 0x50),0,
                  *(undefined4 *)(*DAT_020286dc + 0x80),*(undefined4 *)(iVar9 + 0x60));
  }
  else {
    func_0202bb80();
  }
  iVar3 = func_020280dc();
  if (iVar3 == 0) {
    if (*(int *)(*DAT_020286dc + 0x94) != 8) {
      func_02124c30(*(undefined4 *)(iVar9 + 0x70),*(undefined4 *)(iVar9 + 0x6c),
                    *(undefined4 *)(iVar9 + 0x78),*(undefined4 *)(*DAT_020286dc + 0x84),
                    *(undefined4 *)(iVar9 + 0x7c));
    }
  }
  else {
    func_0211f39c();
  }
  if (iVar8 == 1) {
    iVar3 = GetGlobalCA_from_thumb();
    *(undefined4 *)(iVar3 + DAT_020286f0) = 0;
  }
  else if (iVar8 == 2) {
    iVar3 = GetGlobalCA_from_thumb();
    *(undefined4 *)(iVar3 + DAT_020286f0) = 2;
  }
  return iVar8;
}

