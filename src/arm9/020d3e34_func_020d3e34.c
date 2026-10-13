/* Decompiled C draft; module arm9; ROM address 020d3e34. No matching claim. */
#include "types.h"
#include "deps/020d3e34_func_020d3e34.h"

bool func_020d3e34(uint param_1,int param_2,int param_3)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  code *pcVar10;
  int iVar11;
  int iVar12;
  bool bVar13;
  
  if ((*(ushort *)(param_3 + 2) & 1) != 0) {
    return false;
  }
  uVar5 = param_3 + 0x98U & 3;
  uVar7 = *(uint *)(param_3 + 0x98U & 0xfffffffc);
  uVar7 = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20;
  uVar5 = uVar7 + 8;
  uVar2 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  switch(uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) {
  case 0:
    return false;
  case 1:
    break;
  case 2:
    uVar5 = param_3 + 0x58U & 3;
    uVar2 = *(uint *)(param_3 + 0x58U & 0xfffffffc);
    uVar7 = param_3 + 0x5cU & 3;
    uVar6 = *(uint *)(param_3 + 0x5cU & 0xfffffffc);
    iVar8 = param_2 + (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20);
    uVar5 = param_1 + 8 & 3;
    uVar9 = *(uint *)(param_1 + 8 & 0xfffffffc);
    uVar2 = param_3 + 0xcU & 3;
    uVar3 = *(uint *)(param_3 + 0xcU & 0xfffffffc);
    param_2 = param_2 + (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20);
    iVar4 = (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20) -
            (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
    if ((iVar8 < iVar4) || (iVar4 + iVar8 < 0 != SBORROW4(iVar4,-iVar8))) {
      bVar13 = false;
    }
    else {
      uVar5 = param_3 + 4U & 3;
      uVar7 = *(uint *)(param_3 + 4U & 0xfffffffc);
      iVar12 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
               *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) -
               (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
      if ((iVar8 < iVar12) || (iVar12 + iVar8 < 0 != SBORROW4(iVar12,-iVar8))) {
        bVar13 = false;
      }
      else {
        uVar5 = param_1 + 4 & 3;
        uVar3 = *(uint *)(param_1 + 4 & 0xfffffffc);
        uVar7 = param_3 + 8U & 3;
        uVar2 = *(uint *)(param_3 + 8U & 0xfffffffc);
        iVar11 = (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) -
                 (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20);
        if ((param_2 < iVar11) || (iVar11 + param_2 < 0 != SBORROW4(iVar11,-param_2))) {
          bVar13 = false;
        }
        else {
          lVar1 = (longlong)iVar12 * (longlong)iVar12 + (longlong)iVar4 * (longlong)iVar4;
          iVar12 = (int)((ulonglong)lVar1 >> 0x20);
          iVar4 = (int)((ulonglong)((longlong)iVar8 * (longlong)iVar8) >> 0x20);
          bVar13 = (uint)lVar1 < (uint)((longlong)iVar8 * (longlong)iVar8);
          if ((int)(iVar12 - (iVar4 + (uint)bVar13)) < 0 ==
              (SBORROW4(iVar12,iVar4) != SBORROW4(iVar12 - iVar4,(uint)bVar13))) {
            bVar13 = false;
          }
          else {
            bVar13 = true;
          }
        }
      }
    }
    if (bVar13) {
      func_020eb2a0(param_1,param_3 + 4,iVar8,param_2);
      return true;
    }
    return false;
  case 3:
    uVar5 = param_3 + 0x58U & 3;
    uVar7 = *(uint *)(param_3 + 0x58U & 0xfffffffc);
    iVar4 = func_020ead80(param_1,param_3 + 4,param_3 + 0x28,
                          uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
    return iVar4 != 0;
  case 4:
    iVar4 = func_020eafc4(param_1,param_3 + 4,param_3 + 0x28,param_3 + 0x58);
    return iVar4 != 0;
  case 5:
    uVar7 = uVar7 + 0x18;
    uVar5 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    pcVar10 = (code *)(uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
    if (pcVar10 == (code *)0x0) {
      return false;
    }
    iVar4 = (*pcVar10)(param_3,param_1,param_2);
    return iVar4 != 0;
  default:
    return false;
  }
  uVar5 = param_3 + 0x58U & 3;
  uVar9 = *(uint *)(param_3 + 0x58U & 0xfffffffc);
  uVar7 = param_1 + 8 & 3;
  uVar6 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar2 = param_3 + 0xcU & 3;
  uVar3 = *(uint *)(param_3 + 0xcU & 0xfffffffc);
  param_2 = param_2 + (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20);
  iVar8 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) -
          (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  iVar4 = -param_2;
  if ((param_2 < iVar8) || (iVar8 + param_2 < 0 != SBORROW4(iVar8,iVar4))) {
    bVar13 = false;
  }
  else {
    uVar5 = param_3 + 4U & 3;
    uVar7 = *(uint *)(param_3 + 4U & 0xfffffffc);
    iVar12 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
             *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) -
             (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
    if ((param_2 < iVar12) || (iVar12 + param_2 < 0 != SBORROW4(iVar12,iVar4))) {
      bVar13 = false;
    }
    else {
      uVar5 = param_1 + 4 & 3;
      uVar3 = *(uint *)(param_1 + 4 & 0xfffffffc);
      uVar7 = param_3 + 8U & 3;
      uVar2 = *(uint *)(param_3 + 8U & 0xfffffffc);
      iVar11 = (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) -
               (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20);
      if ((param_2 < iVar11) || (iVar11 + param_2 < 0 != SBORROW4(iVar11,iVar4))) {
        bVar13 = false;
      }
      else {
        lVar1 = (longlong)iVar8 * (longlong)iVar8 +
                (longlong)iVar12 * (longlong)iVar12 + (longlong)iVar11 * (longlong)iVar11;
        iVar8 = (int)((ulonglong)lVar1 >> 0x20);
        iVar4 = (int)((ulonglong)((longlong)param_2 * (longlong)param_2) >> 0x20);
        bVar13 = (uint)lVar1 < (uint)((longlong)param_2 * (longlong)param_2);
        if ((int)(iVar8 - (iVar4 + (uint)bVar13)) < 0 ==
            (SBORROW4(iVar8,iVar4) != SBORROW4(iVar8 - iVar4,(uint)bVar13))) {
          bVar13 = false;
        }
        else {
          bVar13 = true;
        }
      }
    }
  }
  if (bVar13) {
    func_020eb3f0(param_1,param_3 + 4);
    return true;
  }
  return false;
}

