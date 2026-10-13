/* Decompiled C draft; module arm9; ROM address 020aeb7c. No matching claim. */
#include "types.h"
#include "deps/020aeb7c_func_020aeb7c.h"

/* WARNING: Removing unreachable block (ram,0x020af59c) */

void func_020aeb7c(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  ulonglong uVar12;
  
  func_020c525c();
  uVar9 = DAT_020af654;
  uVar10 = *(uint *)(DAT_020af650 & 0xfffffffc) >> (DAT_020af650 & 3) * 8 |
           *(uint *)(DAT_020af650 & 0xfffffffc) << (DAT_020af650 & 3) * -8 + 0x20;
  uVar6 = uVar10 + 0xc;
  uVar4 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar6 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
  if (uVar6 - 3 < 4) {
    return;
  }
  uVar2 = *(uint *)(DAT_020af654 & 0xfffffffc) >> (DAT_020af654 & 3) * 8 |
          *(uint *)(DAT_020af654 & 0xfffffffc) << (DAT_020af654 & 3) * -8 + 0x20;
  uVar4 = uVar2 + 0x898 & 3;
  uVar8 = *(uint *)(uVar2 + 0x898 & 0xfffffffc);
  if (uVar8 >> uVar4 * 8 == 0 && uVar8 << uVar4 * -8 + 0x20 == 0) {
    return;
  }
  uVar10 = uVar10 + 8;
  uVar4 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  switch(uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20) {
  case 0:
    GetCurrentPlayerRacerId();
    iVar3 = IsRacerFinishedRace();
    uVar6 = DAT_020af654;
    if ((iVar3 == 0) ||
       (uVar9 = *(uint *)(DAT_020af654 & 0xfffffffc) >> (DAT_020af654 & 3) * 8 |
                *(uint *)(DAT_020af654 & 0xfffffffc) << (DAT_020af654 & 3) * -8 + 0x20,
       uVar10 = uVar9 + 0x8dc & 3, uVar4 = *(uint *)(uVar9 + 0x8dc & 0xfffffffc),
       uVar4 >> uVar10 * 8 != 0 || uVar4 << uVar10 * -8 + 0x20 != 0)) {
      bVar1 = false;
      bVar11 = false;
      uVar6 = (*(uint *)(DAT_020af650 & 0xfffffffc) >> (DAT_020af650 & 3) * 8 |
              *(uint *)(DAT_020af650 & 0xfffffffc) << (DAT_020af650 & 3) * -8 + 0x20) + 0xc;
      uVar10 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      uVar6 = uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20;
      bVar5 = false;
      if ((uVar6 != 1) && (uVar6 != 4)) {
        bVar5 = true;
      }
      if ((bVar5) && (iVar3 = func_020b32ec(), iVar3 == 0)) {
        bVar11 = true;
      }
      if (bVar11) {
        bVar11 = true;
        iVar3 = GetDirectInputUnitIndex();
        if ((*(ushort *)(DAT_020af658 + iVar3 * 0x5c) & 0x800) == 0) {
          bVar5 = false;
          iVar3 = func_020b2e98();
          if ((iVar3 == 0) &&
             (iVar3 = GetDirectInputUnitIndex(), *(short *)(DAT_020af65c + iVar3 * 0x5c) == 5)) {
            bVar5 = true;
          }
          if (!bVar5) {
            bVar11 = false;
          }
        }
        if (bVar11) {
          bVar1 = true;
        }
      }
      uVar6 = DAT_020af654;
      if (bVar1) {
        *(undefined4 *)
         ((*(uint *)(DAT_020af654 & 0xfffffffc) >> (DAT_020af654 & 3) * 8 |
          *(uint *)(DAT_020af654 & 0xfffffffc) << (DAT_020af654 & 3) * -8 + 0x20) + 0x82c) = 1;
        uVar7 = DAT_020af660;
        uVar10 = uVar6 & 3;
        uVar6 = *(uint *)(uVar6 & 0xfffffffc);
        uVar4 = uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20;
        uVar6 = uVar4 + 0x828 & 3;
        uVar10 = *(uint *)(uVar4 + 0x828 & 0xfffffffc);
        uVar6 = uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20;
        if (uVar6 == 0) {
          *(undefined4 *)(uVar4 + 0x828) = 1;
          NNSi_MaybeSndPlayerStartSeq(uVar7,0,0x18);
        }
        else if (uVar6 == 1) {
          *(undefined4 *)(uVar4 + 0x828) = 0;
          NNSi_MaybeSndPlayerStartSeq(uVar7,0,0x17);
        }
      }
      else {
        *(undefined4 *)
         ((*(uint *)(DAT_020af654 & 0xfffffffc) >> (DAT_020af654 & 3) * 8 |
          *(uint *)(DAT_020af654 & 0xfffffffc) << (DAT_020af654 & 3) * -8 + 0x20) + 0x82c) = 0;
      }
    }
    else {
      uVar10 = (*(uint *)(DAT_020af650 & 0xfffffffc) >> (DAT_020af650 & 3) * 8 |
               *(uint *)(DAT_020af650 & 0xfffffffc) << (DAT_020af650 & 3) * -8 + 0x20) + 0xc;
      uVar4 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      if (uVar10 >> uVar4 * 8 == 0 && uVar10 << uVar4 * -8 + 0x20 == 0) {
        uVar10 = uVar9 + 0x83c & 3;
        uVar4 = *(uint *)(uVar9 + 0x83c & 0xfffffffc);
        if (uVar4 >> uVar10 * 8 == 0 && uVar4 << uVar10 * -8 + 0x20 == 0) {
          *(undefined4 *)(uVar9 + 0x82c) = 1;
          *(undefined4 *)
           ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x828) = 4;
          *(undefined4 *)
           ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x83c) = 1;
          *(undefined4 *)
           ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x840) = 1;
          *(undefined4 *)
           ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x850) = 0xc;
        }
        else {
          *(undefined4 *)(uVar9 + 0x82c) = 0;
        }
      }
      else {
        uVar10 = uVar9 + 0x83c & 3;
        uVar4 = *(uint *)(uVar9 + 0x83c & 0xfffffffc);
        if (uVar4 >> uVar10 * 8 == 0 && uVar4 << uVar10 * -8 + 0x20 == 0) {
          *(undefined4 *)(uVar9 + 0x83c) = 1;
          *(undefined4 *)
           ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x840) = 1;
          *(undefined4 *)
           ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x850) = 0xc;
        }
      }
    }
    break;
  case 1:
    uVar10 = (*(uint *)(DAT_020af664 & 0xfffffffc) >> (DAT_020af664 & 3) * 8 |
             *(uint *)(DAT_020af664 & 0xfffffffc) << (DAT_020af664 & 3) * -8 + 0x20) + 0x4cc;
    uVar4 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    if ((uVar10 >> uVar4 * 8 == 0 && uVar10 << uVar4 * -8 + 0x20 == 0) ||
       (uVar10 = uVar2 + 0x8dc & 3, uVar4 = *(uint *)(uVar2 + 0x8dc & 0xfffffffc),
       uVar4 >> uVar10 * 8 != 0 || uVar4 << uVar10 * -8 + 0x20 != 0)) {
      bVar11 = false;
      if ((uVar6 != 1) && ((uVar6 != 4 && (iVar3 = func_020b32ec(), iVar3 == 0)))) {
        bVar1 = true;
        iVar3 = GetDirectInputUnitIndex();
        if ((*(ushort *)(DAT_020af658 + iVar3 * 0x5c) & 0x800) == 0) {
          bVar5 = false;
          iVar3 = func_020b2e98();
          if ((iVar3 == 0) &&
             (iVar3 = GetDirectInputUnitIndex(), *(short *)(DAT_020af65c + iVar3 * 0x5c) == 5)) {
            bVar5 = true;
          }
          if (!bVar5) {
            bVar1 = false;
          }
        }
        if (bVar1) {
          bVar11 = true;
        }
      }
      uVar10 = DAT_020af654;
      uVar6 = DAT_020af650;
      if (bVar11) {
        *(undefined4 *)
         ((*(uint *)(DAT_020af654 & 0xfffffffc) >> (DAT_020af654 & 3) * 8 |
          *(uint *)(DAT_020af654 & 0xfffffffc) << (DAT_020af654 & 3) * -8 + 0x20) + 0x82c) = 1;
        uVar7 = DAT_020af660;
        uVar4 = uVar6 & 3;
        uVar6 = *(uint *)(uVar6 & 0xfffffffc);
        uVar6 = (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) + 0xc;
        uVar4 = uVar6 & 3;
        uVar6 = *(uint *)(uVar6 & 0xfffffffc);
        if ((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) == 2) {
          uVar4 = *(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
                  *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20;
          uVar6 = uVar4 + 0x828 & 3;
          uVar10 = *(uint *)(uVar4 + 0x828 & 0xfffffffc);
          uVar6 = uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20;
          if (uVar6 == 0) {
            *(undefined4 *)(uVar4 + 0x828) = 1;
            NNSi_MaybeSndPlayerStartSeq(uVar7,0,0x18);
          }
          else if (uVar6 == 1) {
            *(undefined4 *)(uVar4 + 0x828) = 2;
            NNSi_MaybeSndPlayerStartSeq(uVar7,0,0x17);
          }
          else if (uVar6 == 2) {
            *(undefined4 *)(uVar4 + 0x828) = 0;
            NNSi_MaybeSndPlayerStartSeq(uVar7,0,0x17);
          }
        }
        else {
          uVar4 = *(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
                  *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20;
          uVar6 = uVar4 + 0x828 & 3;
          uVar10 = *(uint *)(uVar4 + 0x828 & 0xfffffffc);
          uVar6 = uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20;
          if (uVar6 == 0) {
            *(undefined4 *)(uVar4 + 0x828) = 1;
            NNSi_MaybeSndPlayerStartSeq(uVar7,0,0x18);
          }
          else if (uVar6 == 1) {
            *(undefined4 *)(uVar4 + 0x828) = 0;
            NNSi_MaybeSndPlayerStartSeq(uVar7,0,0x17);
          }
        }
      }
      else {
        *(undefined4 *)
         ((*(uint *)(DAT_020af654 & 0xfffffffc) >> (DAT_020af654 & 3) * 8 |
          *(uint *)(DAT_020af654 & 0xfffffffc) << (DAT_020af654 & 3) * -8 + 0x20) + 0x82c) = 0;
      }
    }
    else {
      uVar6 = uVar2 + 0x83c & 3;
      uVar10 = *(uint *)(uVar2 + 0x83c & 0xfffffffc);
      if (uVar10 >> uVar6 * 8 == 0 && uVar10 << uVar6 * -8 + 0x20 == 0) {
        *(undefined4 *)(uVar2 + 0x83c) = 1;
        *(undefined4 *)
         ((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
          *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 0x840) = 1;
        *(undefined4 *)
         ((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
          *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 0x850) = 0xc;
      }
    }
    break;
  case 2:
    iVar3 = func_020a128c();
    uVar6 = DAT_020af654;
    if (iVar3 == 0) {
      bVar1 = false;
      bVar11 = false;
      uVar6 = (*(uint *)(DAT_020af650 & 0xfffffffc) >> (DAT_020af650 & 3) * 8 |
              *(uint *)(DAT_020af650 & 0xfffffffc) << (DAT_020af650 & 3) * -8 + 0x20) + 0xc;
      uVar10 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      uVar6 = uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20;
      bVar5 = false;
      if ((uVar6 != 1) && (uVar6 != 4)) {
        bVar5 = true;
      }
      if ((bVar5) && (iVar3 = func_020b32ec(), iVar3 == 0)) {
        bVar11 = true;
      }
      if (bVar11) {
        bVar11 = true;
        iVar3 = GetDirectInputUnitIndex();
        if ((*(ushort *)(DAT_020af658 + iVar3 * 0x5c) & 0x800) == 0) {
          bVar5 = false;
          iVar3 = func_020b2e98();
          if ((iVar3 == 0) &&
             (iVar3 = GetDirectInputUnitIndex(), *(short *)(DAT_020af65c + iVar3 * 0x5c) == 5)) {
            bVar5 = true;
          }
          if (!bVar5) {
            bVar11 = false;
          }
        }
        if (bVar11) {
          bVar1 = true;
        }
      }
      uVar6 = DAT_020af654;
      if (bVar1) {
        *(undefined4 *)
         ((*(uint *)(DAT_020af654 & 0xfffffffc) >> (DAT_020af654 & 3) * 8 |
          *(uint *)(DAT_020af654 & 0xfffffffc) << (DAT_020af654 & 3) * -8 + 0x20) + 0x82c) = 1;
        uVar7 = DAT_020af660;
        uVar10 = uVar6 & 3;
        uVar6 = *(uint *)(uVar6 & 0xfffffffc);
        uVar4 = uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20;
        uVar6 = uVar4 + 0x828 & 3;
        uVar10 = *(uint *)(uVar4 + 0x828 & 0xfffffffc);
        uVar6 = uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20;
        if (uVar6 == 0) {
          *(undefined4 *)(uVar4 + 0x828) = 1;
          NNSi_MaybeSndPlayerStartSeq(uVar7,0,0x18);
        }
        else if (uVar6 == 1) {
          *(undefined4 *)(uVar4 + 0x828) = 0;
          NNSi_MaybeSndPlayerStartSeq(uVar7,0,0x17);
        }
      }
      else {
        *(undefined4 *)
         ((*(uint *)(DAT_020af654 & 0xfffffffc) >> (DAT_020af654 & 3) * 8 |
          *(uint *)(DAT_020af654 & 0xfffffffc) << (DAT_020af654 & 3) * -8 + 0x20) + 0x82c) = 0;
      }
    }
    else {
      uVar9 = *(uint *)(DAT_020af654 & 0xfffffffc) >> (DAT_020af654 & 3) * 8 |
              *(uint *)(DAT_020af654 & 0xfffffffc) << (DAT_020af654 & 3) * -8 + 0x20;
      uVar10 = uVar9 + 0x83c & 3;
      uVar4 = *(uint *)(uVar9 + 0x83c & 0xfffffffc);
      if (uVar4 >> uVar10 * 8 == 0 && uVar4 << uVar10 * -8 + 0x20 == 0) {
        *(undefined4 *)(uVar9 + 0x82c) = 1;
        *(undefined4 *)
         ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
          *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x828) = 4;
        *(undefined4 *)
         ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
          *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x83c) = 1;
        *(undefined4 *)
         ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
          *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x840) = 1;
        *(undefined4 *)
         ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
          *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x850) = 0x8c;
      }
      else {
        *(undefined4 *)(uVar9 + 0x82c) = 0;
      }
    }
    break;
  case 3:
    goto LAB_020af0f4;
  case 4:
    iVar3 = func_0203c174();
    uVar6 = DAT_020af654;
    if (iVar3 == 0) {
      uVar6 = (*(uint *)(DAT_020af664 & 0xfffffffc) >> (DAT_020af664 & 3) * 8 |
              *(uint *)(DAT_020af664 & 0xfffffffc) << (DAT_020af664 & 3) * -8 + 0x20) + 0x4cc;
      uVar10 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      if (uVar6 >> uVar10 * 8 != 0 || uVar6 << uVar10 * -8 + 0x20 != 0) {
        iVar3 = IsRacerFinishedRace((short)*(char *)((*(uint *)(DAT_020af650 & 0xfffffffc) >>
                                                      (DAT_020af650 & 3) * 8 |
                                                     *(uint *)(DAT_020af650 & 0xfffffffc) <<
                                                     (DAT_020af650 & 3) * -8 + 0x20) + 0x62));
        if (iVar3 == 0) {
          uVar6 = 6;
        }
        else {
          uVar6 = (*(uint *)(DAT_020af664 & 0xfffffffc) >> (DAT_020af664 & 3) * 8 |
                  *(uint *)(DAT_020af664 & 0xfffffffc) << (DAT_020af664 & 3) * -8 + 0x20) + 0x4e0;
          uVar10 = uVar6 & 3;
          uVar6 = *(uint *)(uVar6 & 0xfffffffc);
          uVar6 = uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20;
        }
        if (uVar6 != 0) {
          *(undefined4 *)
           ((*(uint *)(DAT_020af654 & 0xfffffffc) >> (DAT_020af654 & 3) * 8 |
            *(uint *)(DAT_020af654 & 0xfffffffc) << (DAT_020af654 & 3) * -8 + 0x20) + 0x84c) = 1;
        }
      }
    }
    else {
      uVar9 = *(uint *)(DAT_020af654 & 0xfffffffc) >> (DAT_020af654 & 3) * 8 |
              *(uint *)(DAT_020af654 & 0xfffffffc) << (DAT_020af654 & 3) * -8 + 0x20;
      uVar10 = uVar9 + 0x83c;
      uVar4 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      if (uVar10 >> uVar4 * 8 == 0 && uVar10 << uVar4 * -8 + 0x20 == 0) {
        *(undefined4 *)(uVar9 + 0x83c) = 1;
        uVar4 = DAT_020af650;
        uVar10 = uVar6 & 3;
        uVar6 = *(uint *)(uVar6 & 0xfffffffc);
        *(undefined4 *)((uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20) + 0x840) = 1;
        uVar6 = uVar4 & 3;
        uVar10 = *(uint *)(uVar4 & 0xfffffffc);
        iVar3 = IsRacerFinishedRace((short)*(char *)((uVar10 >> uVar6 * 8 |
                                                     uVar10 << uVar6 * -8 + 0x20) + 0x62));
        if (iVar3 == 0) {
          uVar6 = 6;
        }
        else {
          uVar6 = (*(uint *)(DAT_020af664 & 0xfffffffc) >> (DAT_020af664 & 3) * 8 |
                  *(uint *)(DAT_020af664 & 0xfffffffc) << (DAT_020af664 & 3) * -8 + 0x20) + 0x4e0;
          uVar10 = uVar6 & 3;
          uVar6 = *(uint *)(uVar6 & 0xfffffffc);
          uVar6 = uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20;
        }
        if (uVar6 == 0) {
          *(undefined4 *)
           ((*(uint *)(DAT_020af654 & 0xfffffffc) >> (DAT_020af654 & 3) * 8 |
            *(uint *)(DAT_020af654 & 0xfffffffc) << (DAT_020af654 & 3) * -8 + 0x20) + 0x850) = 0xaf;
        }
      }
    }
    iVar3 = GetDirectInputUnitIndex();
    if ((*(ushort *)(DAT_020af658 + iVar3 * 0x5c) & 0x800) != 0) {
      NNSi_MaybeSndPlayerStartSeq(DAT_020af660,0,0x19);
    }
    *(undefined4 *)
     ((*(uint *)(DAT_020af654 & 0xfffffffc) >> (DAT_020af654 & 3) * 8 |
      *(uint *)(DAT_020af654 & 0xfffffffc) << (DAT_020af654 & 3) * -8 + 0x20) + 0x82c) = 0;
    break;
  case 5:
LAB_020af0f4:
    uVar10 = (*(uint *)(DAT_020af664 & 0xfffffffc) >> (DAT_020af664 & 3) * 8 |
             *(uint *)(DAT_020af664 & 0xfffffffc) << (DAT_020af664 & 3) * -8 + 0x20) + 0x4cc;
    uVar4 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    if ((uVar10 >> uVar4 * 8 == 0 && uVar10 << uVar4 * -8 + 0x20 == 0) || (uVar6 != 0)) {
      GetCurrentPlayerRacerId();
      iVar3 = IsRacerFinishedRace();
      uVar6 = DAT_020af654;
      if ((iVar3 == 0) ||
         (uVar10 = (*(uint *)(DAT_020af650 & 0xfffffffc) >> (DAT_020af650 & 3) * 8 |
                   *(uint *)(DAT_020af650 & 0xfffffffc) << (DAT_020af650 & 3) * -8 + 0x20) + 0xc,
         uVar4 = uVar10 & 3, uVar10 = *(uint *)(uVar10 & 0xfffffffc),
         uVar10 >> uVar4 * 8 != 0 || uVar10 << uVar4 * -8 + 0x20 != 0)) {
        bVar1 = false;
        bVar11 = false;
        uVar6 = (*(uint *)(DAT_020af650 & 0xfffffffc) >> (DAT_020af650 & 3) * 8 |
                *(uint *)(DAT_020af650 & 0xfffffffc) << (DAT_020af650 & 3) * -8 + 0x20) + 0xc;
        uVar10 = uVar6 & 3;
        uVar6 = *(uint *)(uVar6 & 0xfffffffc);
        uVar6 = uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20;
        bVar5 = false;
        if ((uVar6 != 1) && (uVar6 != 4)) {
          bVar5 = true;
        }
        if ((bVar5) && (iVar3 = func_020b32ec(), iVar3 == 0)) {
          bVar11 = true;
        }
        if (bVar11) {
          bVar11 = true;
          iVar3 = GetDirectInputUnitIndex();
          if ((*(ushort *)(DAT_020af658 + iVar3 * 0x5c) & 0x800) == 0) {
            bVar5 = false;
            iVar3 = func_020b2e98();
            if ((iVar3 == 0) &&
               (iVar3 = GetDirectInputUnitIndex(), *(short *)(DAT_020af65c + iVar3 * 0x5c) == 5)) {
              bVar5 = true;
            }
            if (!bVar5) {
              bVar11 = false;
            }
          }
          if (bVar11) {
            bVar1 = true;
          }
        }
        uVar6 = DAT_020af654;
        if (bVar1) {
          *(undefined4 *)
           ((*(uint *)(DAT_020af654 & 0xfffffffc) >> (DAT_020af654 & 3) * 8 |
            *(uint *)(DAT_020af654 & 0xfffffffc) << (DAT_020af654 & 3) * -8 + 0x20) + 0x82c) = 1;
          uVar7 = DAT_020af660;
          uVar10 = uVar6 & 3;
          uVar6 = *(uint *)(uVar6 & 0xfffffffc);
          uVar4 = uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20;
          uVar6 = uVar4 + 0x828 & 3;
          uVar10 = *(uint *)(uVar4 + 0x828 & 0xfffffffc);
          uVar6 = uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20;
          if (uVar6 == 0) {
            *(undefined4 *)(uVar4 + 0x828) = 1;
            NNSi_MaybeSndPlayerStartSeq(uVar7,0,0x18);
          }
          else if (uVar6 == 1) {
            *(undefined4 *)(uVar4 + 0x828) = 0;
            NNSi_MaybeSndPlayerStartSeq(uVar7,0,0x17);
          }
        }
        else {
          *(undefined4 *)
           ((*(uint *)(DAT_020af654 & 0xfffffffc) >> (DAT_020af654 & 3) * 8 |
            *(uint *)(DAT_020af654 & 0xfffffffc) << (DAT_020af654 & 3) * -8 + 0x20) + 0x82c) = 0;
        }
      }
      else {
        uVar9 = *(uint *)(DAT_020af654 & 0xfffffffc) >> (DAT_020af654 & 3) * 8 |
                *(uint *)(DAT_020af654 & 0xfffffffc) << (DAT_020af654 & 3) * -8 + 0x20;
        uVar10 = uVar9 + 0x83c;
        uVar4 = uVar10 & 3;
        uVar10 = *(uint *)(uVar10 & 0xfffffffc);
        if (uVar10 >> uVar4 * 8 == 0 && uVar10 << uVar4 * -8 + 0x20 == 0) {
          *(undefined4 *)(uVar9 + 0x82c) = 1;
          *(undefined4 *)
           ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x828) = 0;
          *(undefined4 *)
           ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x83c) = 1;
          *(undefined4 *)
           ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x840) = 1;
          *(undefined4 *)
           ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x850) = 0x8c;
        }
        else {
          bVar11 = false;
          iVar3 = func_020b32ec();
          if (iVar3 == 0) {
            bVar1 = true;
            iVar3 = GetDirectInputUnitIndex();
            if ((*(ushort *)(DAT_020af658 + iVar3 * 0x5c) & 0x800) == 0) {
              bVar5 = false;
              iVar3 = func_020b2e98();
              if ((iVar3 == 0) &&
                 (iVar3 = GetDirectInputUnitIndex(), *(short *)(DAT_020af65c + iVar3 * 0x5c) == 5))
              {
                bVar5 = true;
              }
              if (!bVar5) {
                bVar1 = false;
              }
            }
            if (bVar1) {
              bVar11 = true;
            }
          }
          uVar6 = DAT_020af654;
          if (bVar11) {
            *(undefined4 *)
             ((*(uint *)(DAT_020af654 & 0xfffffffc) >> (DAT_020af654 & 3) * 8 |
              *(uint *)(DAT_020af654 & 0xfffffffc) << (DAT_020af654 & 3) * -8 + 0x20) + 0x82c) = 1;
            uVar7 = DAT_020af660;
            uVar10 = uVar6 & 3;
            uVar6 = *(uint *)(uVar6 & 0xfffffffc);
            uVar4 = uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20;
            uVar6 = uVar4 + 0x828 & 3;
            uVar10 = *(uint *)(uVar4 + 0x828 & 0xfffffffc);
            uVar6 = uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20;
            if (uVar6 == 0) {
              *(undefined4 *)(uVar4 + 0x828) = 3;
              NNSi_MaybeSndPlayerStartSeq(uVar7,0,0x18);
            }
            else if (uVar6 == 3) {
              *(undefined4 *)(uVar4 + 0x828) = 0;
              NNSi_MaybeSndPlayerStartSeq(uVar7,0,0x17);
            }
          }
          else {
            *(undefined4 *)
             ((*(uint *)(DAT_020af654 & 0xfffffffc) >> (DAT_020af654 & 3) * 8 |
              *(uint *)(DAT_020af654 & 0xfffffffc) << (DAT_020af654 & 3) * -8 + 0x20) + 0x82c) = 0;
          }
        }
      }
    }
    else {
      uVar6 = uVar2 + 0x838 & 3;
      uVar10 = *(uint *)(uVar2 + 0x838 & 0xfffffffc);
      if (uVar10 >> uVar6 * 8 == 0 && uVar10 << uVar6 * -8 + 0x20 == 0) {
        *(undefined4 *)(uVar2 + 0x82c) = 1;
        *(undefined4 *)
         ((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
          *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 0x828) = 4;
        *(undefined4 *)
         ((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
          *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 0x838) = 1;
        uVar4 = *(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20;
        uVar6 = uVar4 + 0x83c;
        uVar10 = uVar6 & 3;
        uVar6 = *(uint *)(uVar6 & 0xfffffffc);
        if (uVar6 >> uVar10 * 8 == 0 && uVar6 << uVar10 * -8 + 0x20 == 0) {
          *(undefined4 *)(uVar4 + 0x83c) = 1;
          *(undefined4 *)
           ((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
            *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 0x840) = 1;
          *(undefined4 *)
           ((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
            *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 0x850) = 0x8c;
        }
      }
      else {
        *(undefined4 *)(uVar2 + 0x82c) = 0;
      }
    }
  }
  uVar10 = *(uint *)(DAT_020af654 & 0xfffffffc) >> (DAT_020af654 & 3) * 8 |
           *(uint *)(DAT_020af654 & 0xfffffffc) << (DAT_020af654 & 3) * -8 + 0x20;
  uVar6 = uVar10 + 0x82c;
  uVar4 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if (uVar6 >> uVar4 * 8 == 0 && uVar6 << uVar4 * -8 + 0x20 == 0) goto switchD_020af524_default;
  uVar10 = uVar10 + 0x828;
  uVar6 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  switch(uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20) {
  case 0:
    func_020be9d4();
    break;
  case 1:
    goto LAB_020af550;
  case 2:
    goto LAB_020af550;
  case 3:
LAB_020af550:
    func_020be9d4();
    func_020c43c4();
    break;
  case 4:
    goto LAB_020af55c;
  case 5:
LAB_020af55c:
    func_020c31c0();
    break;
  case 6:
    InvokeE8Handler();
  }
switchD_020af524_default:
  uVar6 = (*(uint *)(DAT_020af654 & 0xfffffffc) >> (DAT_020af654 & 3) * 8 |
          *(uint *)(DAT_020af654 & 0xfffffffc) << (DAT_020af654 & 3) * -8 + 0x20) + 0x90c;
  uVar10 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if (uVar6 >> uVar10 * 8 != 0 || uVar6 << uVar10 * -8 + 0x20 != 0) {
    return;
  }
  uVar4 = *(uint *)(DAT_020af650 & 0xfffffffc) >> (DAT_020af650 & 3) * 8 |
          *(uint *)(DAT_020af650 & 0xfffffffc) << (DAT_020af650 & 3) * -8 + 0x20;
  uVar6 = uVar4 + 8;
  uVar10 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar6 = uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20;
  if (uVar6 == 4) {
    bVar11 = *(char *)(uVar4 + 0x55) == '\t';
  }
  else {
    bVar11 = false;
  }
  if (bVar11) {
    if (uVar6 == 4) {
      uVar12 = func_020a128c();
    }
    else {
      uVar12 = (ulonglong)uVar6 << 0x20;
    }
    if ((int)uVar12 != 0) {
      uVar6 = (*(uint *)(DAT_020af650 & 0xfffffffc) >> (DAT_020af650 & 3) * 8 |
              *(uint *)(DAT_020af650 & 0xfffffffc) << (DAT_020af650 & 3) * -8 + 0x20) + 8;
      uVar10 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      if ((uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20) == 4) {
        GetCurrentPlayerRacerId();
        uVar12 = func_020a1084();
      }
      else {
        uVar12 = uVar12 & 0xffffffff00000000;
      }
      uVar7 = (undefined4)(uVar12 >> 0x20);
      if ((int)uVar12 == 0) {
        uVar6 = (*(uint *)(DAT_020af654 & 0xfffffffc) >> (DAT_020af654 & 3) * 8 |
                *(uint *)(DAT_020af654 & 0xfffffffc) << (DAT_020af654 & 3) * -8 + 0x20) + 0x910;
        uVar10 = uVar6 & 3;
        uVar6 = *(uint *)(uVar6 & 0xfffffffc);
        bVar11 = uVar6 >> uVar10 * 8 != 0;
        bVar1 = uVar6 << uVar10 * -8 + 0x20 != 0;
        if (!bVar11 && !bVar1) {
          uVar7 = 1;
        }
        if (bVar11 || bVar1) {
          uVar7 = 0;
        }
        *(undefined4 *)
         ((*(uint *)(DAT_020af668 & 0xfffffffc) >> (DAT_020af668 & 3) * 8 |
          *(uint *)(DAT_020af668 & 0xfffffffc) << (DAT_020af668 & 3) * -8 + 0x20) + 0x10) = uVar7;
      }
      else {
        *(undefined4 *)
         ((*(uint *)(DAT_020af668 & 0xfffffffc) >> (DAT_020af668 & 3) * 8 |
          *(uint *)(DAT_020af668 & 0xfffffffc) << (DAT_020af668 & 3) * -8 + 0x20) + 0x10) = 0;
      }
      *(undefined4 *)
       ((*(uint *)(DAT_020af654 & 0xfffffffc) >> (DAT_020af654 & 3) * 8 |
        *(uint *)(DAT_020af654 & 0xfffffffc) << (DAT_020af654 & 3) * -8 + 0x20) + 0x90c) = 1;
      return;
    }
    return;
  }
  return;
}

