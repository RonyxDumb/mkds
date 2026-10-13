/* Decompiled C draft; module arm9; ROM address 02032280. No matching claim. */
#include "types.h"
#include "deps/02032280_func_02032280.h"

undefined4 func_02032280(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  bool bVar3;
  bool bVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  int local_1c;
  
  piVar5 = DAT_020325d0;
  uVar14 = 0;
  iVar13 = *DAT_020325d0;
  switch(*(undefined4 *)(iVar13 + 0x54)) {
  case 3:
    func_020328c8(1);
    func_020328f8(1);
    piVar5 = DAT_020325d0;
    *(int *)(*DAT_020325d0 + 0x58) = *(int *)(*DAT_020325d0 + 0x58) + 1;
    iVar10 = *(int *)(*piVar5 + 0x58);
    if (iVar10 < 10) {
      uVar8 = ComputeValueInterpolation_from_thumb(1,0xee,0,iVar10,10);
      piVar5 = DAT_020325d0;
      *(undefined4 *)(*DAT_020325d0 + 0x5c) = uVar8;
      uVar8 = ComputeValueInterpolation_from_thumb
                        (1,0xffffff40,0,*(undefined4 *)(*piVar5 + 0x58),10);
      *(undefined4 *)(*DAT_020325d0 + 0x60) = uVar8;
    }
    else {
      *(undefined4 *)(*piVar5 + 0x58) = 0;
      *(undefined4 *)(*piVar5 + 0x5c) = 0;
      *(undefined4 *)(*piVar5 + 0x60) = 0;
      *(undefined4 *)(*piVar5 + 0x54) = 4;
    }
    func_02032940();
    break;
  case 4:
    iVar10 = *(int *)(iVar13 + 0x44);
    uVar11 = 0xffffffff;
    local_1c = 0;
    bVar4 = false;
    bVar3 = false;
    if ((*(short *)(DAT_020325d4 + 0x2e0) == 0) && (*(ushort *)(DAT_020325d8 + 0x2e0) < 5)) {
      bVar3 = true;
    }
    if (((!bVar3) && (*(short *)(DAT_020325dc + 0x2e0) == 0)) &&
       (*(short *)(DAT_020325d4 + 0x2e0) != 0)) {
      bVar4 = true;
    }
    if (bVar4) {
      uVar1 = *(undefined2 *)(DAT_020325e0 + 0x2e0);
      uVar2 = *(undefined2 *)(DAT_020325e4 + 0x2e0);
      local_1c = func_02128210(uVar1,uVar2);
      uVar11 = func_0201ea84(*(undefined4 *)(iVar13 + 0x2c),uVar1,uVar2);
    }
    piVar5 = DAT_020325d0;
    if ((*(ushort *)(DAT_020325e8 + 0x2e0) & 1) == 0) {
      if ((int)uVar11 < 0) {
        if (((*(ushort *)(DAT_020325e8 + 0x2e0) & 2) == 0) && (local_1c == 0)) {
          iVar6 = func_020ae408(8,0x40);
          if (iVar6 == 0) {
            iVar6 = func_020ae408(8,0x80);
            if (iVar6 != 0) {
              iVar6 = *DAT_020325d0;
              if (*(int *)(iVar6 + 0x44) == *(int *)(iVar6 + 0x48) + -1) {
                if (*(int *)(iVar6 + 0x68) == 1) {
                  *(undefined4 *)(iVar6 + 0x44) = 0;
                }
              }
              else {
                *(int *)(iVar6 + 0x44) = *(int *)(iVar6 + 0x44) + 1;
              }
            }
          }
          else {
            iVar6 = *DAT_020325d0;
            if (*(int *)(iVar6 + 0x44) == 0) {
              if (*(int *)(iVar6 + 0x68) == 1) {
                *(int *)(iVar6 + 0x44) = *(int *)(iVar6 + 0x48) + -1;
              }
            }
            else {
              *(int *)(iVar6 + 0x44) = *(int *)(iVar6 + 0x44) + -1;
            }
          }
        }
        else {
          iVar6 = *DAT_020325d0;
          if (*(int *)(iVar6 + 0x68) == 0) {
            *(undefined4 *)(iVar6 + 100) = 2;
            *(undefined4 *)(*piVar5 + 0x54) = 9;
          }
          else {
            uVar8 = DAT_020325f0;
            uVar7 = DAT_020325ec;
            if (*DAT_020325f4 != 2) {
              uVar7 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar6 + 0x50),0x14);
              uVar8 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*DAT_020325d0 + 0x50),0x16)
              ;
            }
            func_021277f8(uVar7,uVar8,0);
            *(undefined4 *)(*DAT_020325d0 + 0x54) = 7;
            func_020329dc(0);
          }
          func_02128310(0);
        }
      }
      else {
        iVar12 = 0;
        iVar6 = *DAT_020325d0;
        if (0 < *(int *)(iVar6 + 0x48)) {
          iVar9 = *(int *)(iVar6 + 0x4c);
          do {
            if (uVar11 == *(ushort *)(iVar9 + 4)) {
              func_020328f8(*(int *)(iVar6 + 0x44) != iVar12);
              *(int *)(*DAT_020325d0 + 0x44) = iVar12;
              func_02032a20();
              break;
            }
            iVar9 = iVar9 + 6;
            iVar12 = iVar12 + 1;
          } while (iVar12 < *(int *)(iVar6 + 0x48));
        }
      }
    }
    else {
      func_020328f8(0);
      func_02032a20();
    }
    if (((int)uVar11 < 0) && (iVar10 != *(int *)(*DAT_020325d0 + 0x44))) {
      func_020328f8(1);
      NNSi_MaybeSndPlayerStartSeq(DAT_020325f8,0,0);
    }
    break;
  case 5:
    *(int *)(iVar13 + 0x58) = *(int *)(iVar13 + 0x58) + 1;
    if (4 < *(int *)(*piVar5 + 0x58)) {
      *(undefined4 *)(*piVar5 + 0x58) = 0;
      *(undefined4 *)(*piVar5 + 0x54) = 6;
      func_020328f8(1);
    }
    break;
  case 6:
    *(int *)(iVar13 + 0x58) = *(int *)(iVar13 + 0x58) + 1;
    if (*(int *)(*piVar5 + 0x58) < 10) {
      uVar8 = func_020ae488();
      *(undefined4 *)(*DAT_020325d0 + 0x5c) = uVar8;
    }
    else {
      *(undefined4 *)(*piVar5 + 0x58) = 0;
      *(undefined4 *)(*piVar5 + 0x54) = 9;
      if (*(int *)(*piVar5 + 0x68) != 0) {
        func_021282c8();
      }
    }
    func_020329a0();
    break;
  case 7:
    iVar10 = func_02127788();
    if (iVar10 != 0) {
      iVar10 = func_02127794();
      if ((iVar10 == 0) || (iVar10 = func_02127794(), iVar10 == -1)) {
        *(undefined4 *)(*DAT_020325d0 + 0x54) = 4;
      }
      else {
        *(ushort *)(*DAT_020325fc + DAT_02032600) = *(ushort *)(*DAT_020325fc + DAT_02032600) | 0x80
        ;
        piVar5 = DAT_020325d0;
        *(undefined4 *)(*DAT_020325d0 + 100) = 3;
        *(undefined4 *)(*piVar5 + 0x54) = 8;
      }
      func_020329dc(1);
      func_021277e4();
    }
    break;
  case 8:
    iVar10 = func_02054f58();
    if (iVar10 == 1) {
      uVar14 = *(undefined4 *)(*DAT_020325d0 + 100);
      *(undefined4 *)(*DAT_020325d0 + 0x54) = 0xb;
    }
    break;
  case 9:
    *(int *)(iVar13 + 0x58) = *(int *)(iVar13 + 0x58) + 1;
    iVar10 = *(int *)(*piVar5 + 0x58);
    if (iVar10 < 10) {
      uVar8 = ComputeValueInterpolation_from_thumb(1,0,0xee,iVar10,10);
      piVar5 = DAT_020325d0;
      *(undefined4 *)(*DAT_020325d0 + 0x5c) = uVar8;
      uVar8 = ComputeValueInterpolation_from_thumb
                        (1,0,0xffffff40,*(undefined4 *)(*piVar5 + 0x58),10);
      *(undefined4 *)(*DAT_020325d0 + 0x60) = uVar8;
    }
    else {
      *(undefined4 *)(*piVar5 + 0x5c) = 0;
      *(undefined4 *)(*piVar5 + 0x60) = 0;
      *(undefined4 *)(*piVar5 + 0x54) = 10;
    }
    func_02032940();
    break;
  case 10:
    uVar14 = *(undefined4 *)(iVar13 + 100);
  }
  if (*(int *)(*DAT_020325d0 + 0x54) != 10) {
    if (*DAT_0203264c != 2) {
      func_02124c30(*(undefined4 *)(iVar13 + 0xc),*(undefined4 *)(iVar13 + 8),
                    *(undefined4 *)(iVar13 + 0x14),*(undefined4 *)(*DAT_020325d0 + 0x38),
                    *(undefined4 *)(iVar13 + 0x18));
    }
    func_02124c30(*(undefined4 *)(iVar13 + 0x28),*(undefined4 *)(iVar13 + 0x24),
                  *(undefined4 *)(iVar13 + 0x30),*(undefined4 *)(*DAT_02032650 + 0x3c),
                  *(undefined4 *)(iVar13 + 0x34));
  }
  return uVar14;
}

