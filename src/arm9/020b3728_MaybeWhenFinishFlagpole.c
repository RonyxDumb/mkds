/* Decompiled C draft; module arm9; ROM address 020b3728. No matching claim. */
#include "types.h"
#include "deps/020b3728_MaybeWhenFinishFlagpole.h"

void MaybeWhenFinishFlagpole(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  bool bVar8;
  
  uVar1 = (*(uint *)(DAT_020b3ac8 & 0xfffffffc) >> (DAT_020b3ac8 & 3) * 8 |
          *(uint *)(DAT_020b3ac8 & 0xfffffffc) << (DAT_020b3ac8 & 3) * -8 + 0x20) + 0x4cc;
  uVar5 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if ((uVar1 >> uVar5 * 8 != 0 || uVar1 << uVar5 * -8 + 0x20 != 0) &&
     (uVar1 = (*(uint *)(DAT_020b3acc & 0xfffffffc) >> (DAT_020b3acc & 3) * 8 |
              *(uint *)(DAT_020b3acc & 0xfffffffc) << (DAT_020b3acc & 3) * -8 + 0x20) + 0xc,
     uVar5 = uVar1 & 3, uVar1 = *(uint *)(uVar1 & 0xfffffffc),
     uVar1 >> uVar5 * 8 == 0 && uVar1 << uVar5 * -8 + 0x20 == 0)) {
    func_020b3cd8();
    func_020b3b58();
    func_0205eeb0();
    *(undefined4 *)
     ((*(uint *)(DAT_020b3acc & 0xfffffffc) >> (DAT_020b3acc & 3) * 8 |
      *(uint *)(DAT_020b3acc & 0xfffffffc) << (DAT_020b3acc & 3) * -8 + 0x20) + 0xc) = 1;
  }
  iVar2 = GetCurrentPlayerRacerId();
  uVar5 = *(uint *)(DAT_020b3ac8 & 0xfffffffc) >> (DAT_020b3ac8 & 3) * 8 |
          *(uint *)(DAT_020b3ac8 & 0xfffffffc) << (DAT_020b3ac8 & 3) * -8 + 0x20;
  uVar1 = iVar2 * 0x8c + uVar5 + 0x14;
  uVar7 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if (((uVar1 >> uVar7 * 8 | uVar1 << uVar7 * -8 + 0x20) != 1) &&
     (uVar5 = uVar5 + 0x4cc, uVar1 = uVar5 & 3, uVar5 = *(uint *)(uVar5 & 0xfffffffc),
     uVar5 >> uVar1 * 8 == 0 && uVar5 << uVar1 * -8 + 0x20 == 0)) {
    return;
  }
  piVar6 = (int *)(*(uint *)(DAT_020b3acc & 0xfffffffc) >> (DAT_020b3acc & 3) * 8 |
                  *(uint *)(DAT_020b3acc & 0xfffffffc) << (DAT_020b3acc & 3) * -8 + 0x20);
  uVar1 = *(uint *)((uint)piVar6 & 0xfffffffc) >> ((uint)piVar6 & 3) * 8 |
          *(uint *)((uint)piVar6 & 0xfffffffc) << ((uint)piVar6 & 3) * -8 + 0x20;
  if (10 < (int)uVar1) goto switchD_020b397c_default;
  *piVar6 = uVar1 + 1;
  if (uVar1 != 0) {
    if (uVar1 == 10) {
      uVar7 = *(uint *)(DAT_020b3ad0 & 0xfffffffc) >> (DAT_020b3ad0 & 3) * 8 |
              *(uint *)(DAT_020b3ad0 & 0xfffffffc) << (DAT_020b3ad0 & 3) * -8 + 0x20;
      uVar1 = uVar7 + 8 & 3;
      uVar5 = *(uint *)(uVar7 + 8 & 0xfffffffc);
      switch(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) {
      case 0:
        break;
      case 1:
        break;
      case 2:
        iVar2 = GetDriverEntry((int)*(char *)(uVar7 + 0x62));
        uVar1 = iVar2 + 0x7cU & 3;
        uVar5 = *(uint *)(iVar2 + 0x7cU & 0xfffffffc);
        if (((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) & 0x2000000) == 0) {
          uVar4 = 5;
        }
        else {
          uVar4 = 4;
        }
        func_02089ef4(uVar4);
        break;
      case 3:
        uVar1 = uVar7 + 0x1c & 3;
        uVar5 = *(uint *)(uVar7 + 0x1c & 0xfffffffc);
        if ((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) == 1) {
          iVar2 = GetDriverEntry((int)*(char *)(uVar7 + 0x62));
          uVar1 = iVar2 + 0x7cU & 3;
          uVar5 = *(uint *)(iVar2 + 0x7cU & 0xfffffffc);
          if (((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) & 0x2000000) == 0) {
            uVar4 = 5;
          }
          else {
            uVar4 = 4;
          }
          func_02089ef4(uVar4);
        }
        break;
      case 4:
        iVar2 = IsRacerFinishedRace((short)*(char *)(uVar7 + 0x62));
        if (iVar2 == 0) {
          uVar1 = 6;
        }
        else {
          uVar1 = (*(uint *)(DAT_020b3ac8 & 0xfffffffc) >> (DAT_020b3ac8 & 3) * 8 |
                  *(uint *)(DAT_020b3ac8 & 0xfffffffc) << (DAT_020b3ac8 & 3) * -8 + 0x20) + 0x4e0;
          uVar5 = uVar1 & 3;
          uVar1 = *(uint *)(uVar1 & 0xfffffffc);
          uVar1 = uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20;
        }
        if (uVar1 != 0) {
          func_02089ef4(7);
        }
        break;
      case 5:
      }
    }
    goto switchD_020b397c_default;
  }
  uVar5 = *(uint *)(DAT_020b3ad0 & 0xfffffffc) >> (DAT_020b3ad0 & 3) * 8 |
          *(uint *)(DAT_020b3ad0 & 0xfffffffc) << (DAT_020b3ad0 & 3) * -8 + 0x20;
  uVar1 = uVar5 + 8;
  uVar7 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  switch(uVar1 >> uVar7 * 8 | uVar1 << uVar7 * -8 + 0x20) {
  case 0:
    goto LAB_020b37f4;
  case 1:
LAB_020b37f4:
    func_02089ef4(3);
    break;
  case 2:
    break;
  case 3:
    goto LAB_020b3800;
  case 4:
    break;
  case 5:
LAB_020b3800:
    uVar5 = uVar5 + 0x1c;
    uVar1 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    if (((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) != 1) &&
       (iVar2 = GetCurrentPlayerRacerId(),
       uVar1 = iVar2 * 0x8c +
               (*(uint *)(DAT_020b3ac8 & 0xfffffffc) >> (DAT_020b3ac8 & 3) * 8 |
               *(uint *)(DAT_020b3ac8 & 0xfffffffc) << (DAT_020b3ac8 & 3) * -8 + 0x20) + 0x14,
       uVar5 = uVar1 & 3, uVar1 = *(uint *)(uVar1 & 0xfffffffc),
       (uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) == 1)) {
      func_02089ef4(3);
    }
  }
  uVar1 = DAT_020b3ad4 + 4U & 3;
  uVar5 = *(uint *)(DAT_020b3ad4 + 4U & 0xfffffffc);
  if (1 < (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) - 2) goto switchD_020b397c_default;
  uVar7 = *(uint *)(DAT_020b3ad0 & 0xfffffffc) >> (DAT_020b3ad0 & 3) * 8 |
          *(uint *)(DAT_020b3ad0 & 0xfffffffc) << (DAT_020b3ad0 & 3) * -8 + 0x20;
  uVar1 = uVar7 + 8 & 3;
  uVar5 = *(uint *)(uVar7 + 8 & 0xfffffffc);
  uVar1 = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
  if (uVar1 == 2) goto switchD_020b397c_default;
  uVar5 = uVar7 + 0xc & 3;
  uVar3 = *(uint *)(uVar7 + 0xc & 0xfffffffc);
  bVar8 = (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) != 1;
  if ((!bVar8) || (uVar1 != 4)) goto LAB_020b38e8;
  switch(*(undefined1 *)(uVar7 + 0x2f)) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    goto LAB_020b38b4;
  case 3:
    break;
  case 4:
    goto LAB_020b38b4;
  case 5:
    break;
  case 6:
    goto LAB_020b38b4;
  case 7:
    break;
  case 8:
    break;
  case 9:
    break;
  case 10:
LAB_020b38b4:
    iVar2 = IsRacerFinishedRace((short)*(char *)(uVar7 + 0x62));
    if (iVar2 == 0) {
      uVar1 = 6;
    }
    else {
      uVar1 = (*(uint *)(DAT_020b3ac8 & 0xfffffffc) >> (DAT_020b3ac8 & 3) * 8 |
              *(uint *)(DAT_020b3ac8 & 0xfffffffc) << (DAT_020b3ac8 & 3) * -8 + 0x20) + 0x4e0;
      uVar5 = uVar1 & 3;
      uVar1 = *(uint *)(uVar1 & 0xfffffffc);
      uVar1 = uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20;
    }
    bVar8 = uVar1 == 0 && bVar8;
    goto LAB_020b38e8;
  }
  bVar8 = false;
LAB_020b38e8:
  if (bVar8) {
    iVar2 = func_020c7148();
    if ((iVar2 == 0) && (iVar2 = GetLastTimeTrialWasRecord(), iVar2 == 0)) {
      iVar2 = GetCurrentPlayerRacerId();
      uVar1 = iVar2 * 0x8c +
              (*(uint *)(DAT_020b3ac8 & 0xfffffffc) >> (DAT_020b3ac8 & 3) * 8 |
              *(uint *)(DAT_020b3ac8 & 0xfffffffc) << (DAT_020b3ac8 & 3) * -8 + 0x20) + 0x14;
      uVar5 = uVar1 & 3;
      uVar1 = *(uint *)(uVar1 & 0xfffffffc);
      if ((uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) == 3) {
        NNSi_MaybeSndPlayerStartSeq(DAT_020b3ad8,0,0x43);
      }
      else {
        NNSi_MaybeSndPlayerStartSeq(DAT_020b3ad8,0,0x42);
      }
    }
    else {
      NNSi_MaybeSndPlayerStartSeq(DAT_020b3ad8,0,0x44);
    }
  }
switchD_020b397c_default:
  uVar7 = *(uint *)(DAT_020b3acc & 0xfffffffc) >> (DAT_020b3acc & 3) * 8 |
          *(uint *)(DAT_020b3acc & 0xfffffffc) << (DAT_020b3acc & 3) * -8 + 0x20;
  uVar1 = uVar7 + 4 & 3;
  uVar5 = *(uint *)(uVar7 + 4 & 0xfffffffc);
  if (uVar5 >> uVar1 * 8 == 0 && uVar5 << uVar1 * -8 + 0x20 == 0) {
    return;
  }
  uVar1 = uVar7 + 8 & 3;
  uVar5 = *(uint *)(uVar7 + 8 & 0xfffffffc);
  uVar1 = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
  *(uint *)(uVar7 + 8) = uVar1 + 1;
  if (uVar1 != 10) {
    return;
  }
  uVar7 = *(uint *)(DAT_020b3ad0 & 0xfffffffc) >> (DAT_020b3ad0 & 3) * 8 |
          *(uint *)(DAT_020b3ad0 & 0xfffffffc) << (DAT_020b3ad0 & 3) * -8 + 0x20;
  uVar1 = uVar7 + 8;
  uVar5 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  switch(uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    iVar2 = IsRacerFinishedRace((short)*(char *)(uVar7 + 0x62));
    if (iVar2 == 0) {
      uVar1 = 6;
    }
    else {
      uVar1 = (*(uint *)(DAT_020b3ac8 & 0xfffffffc) >> (DAT_020b3ac8 & 3) * 8 |
              *(uint *)(DAT_020b3ac8 & 0xfffffffc) << (DAT_020b3ac8 & 3) * -8 + 0x20) + 0x4e0;
      uVar5 = uVar1 & 3;
      uVar1 = *(uint *)(uVar1 & 0xfffffffc);
      uVar1 = uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20;
    }
    if (uVar1 == 0) {
      func_02089ef4(6);
    }
    break;
  case 5:
  }
  *(undefined4 *)
   ((*(uint *)(DAT_020b3acc & 0xfffffffc) >> (DAT_020b3acc & 3) * 8 |
    *(uint *)(DAT_020b3acc & 0xfffffffc) << (DAT_020b3acc & 3) * -8 + 0x20) + 4) = 0;
  return;
}

