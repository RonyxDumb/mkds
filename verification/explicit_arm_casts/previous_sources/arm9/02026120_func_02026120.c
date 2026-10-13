/* Decompiled C draft; module arm9; ROM address 02026120. No matching claim. */
#include "types.h"
#include "deps/02026120_func_02026120.h"

int func_02026120(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  bool bVar9;
  bool bVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  
  iVar14 = 0;
  iVar4 = GetDirectInputUnitIndex();
  piVar3 = DAT_02026480;
  iVar12 = *DAT_02026480;
  switch(*(undefined4 *)(iVar12 + 0x6c)) {
  case 0:
    iVar4 = Bright_IsBothScreensFadedIn();
    if (iVar4 != 0) {
      *(undefined4 *)(*DAT_02026480 + 0x6c) = 1;
    }
    break;
  case 1:
    if (*(int *)(iVar12 + 0x68) == 0) {
      func_0202734c(1);
    }
    piVar3 = DAT_02026480;
    *(int *)(*DAT_02026480 + 0x68) = *(int *)(*DAT_02026480 + 0x68) + 1;
    iVar4 = *piVar3;
    if (*(int *)(iVar4 + 0x68) < 10) {
      uVar7 = _s32_div_f(*(int *)(iVar4 + 0x68) << 0xc,10);
      *(undefined4 *)(iVar4 + 0x70) = uVar7;
    }
    else {
      *(undefined4 *)(iVar4 + 0x70) = DAT_02026484;
      *(undefined4 *)(*piVar3 + 0x68) = 0;
      if (*DAT_02026488 == 2) {
        uVar7 = 2;
      }
      else {
        uVar7 = 3;
      }
      *(undefined4 *)(*DAT_02026480 + 0x6c) = uVar7;
    }
    func_02027084();
    break;
  case 2:
    *(undefined4 *)(iVar12 + 0xf0) = 0xc;
    *(undefined4 *)(*piVar3 + 0xf4) = 0x24;
    *(undefined4 *)(*piVar3 + 0x68) = 0;
    *(undefined4 *)(*piVar3 + 0x8c) = 1;
    iVar4 = GetGlobalCA_from_thumb();
    if (*(int *)(iVar4 + 200) == 3) {
      if (*(int *)(*DAT_0202648c + 4) == 8) {
        *(byte *)(*DAT_0202648c + DAT_02026490) = (byte)*(undefined4 *)(*DAT_02026480 + 0xf0) | 0x40
        ;
      }
      func_02027424(1);
      *(undefined4 *)(*DAT_02026480 + 0x6c) = 8;
    }
    else {
      iVar4 = GetGlobalCA_from_thumb();
      if (*(int *)(iVar4 + 200) == 2) {
        if (*(int *)(*DAT_0202648c + 4) == 8) {
          *(byte *)(*DAT_0202648c + DAT_02026490) =
               (byte)*(undefined4 *)(*DAT_02026480 + 0xf0) | 0xc0;
        }
        *(undefined4 *)(*DAT_02026480 + 0x6c) = 6;
      }
    }
    break;
  case 3:
    iVar6 = *(int *)(iVar12 + 0x60);
    bVar10 = false;
    bVar9 = false;
    iVar13 = iVar4 * 0x5c;
    if ((*(short *)(DAT_02026494 + iVar13) == 0) && (*(ushort *)(DAT_02026498 + iVar13) < 5)) {
      bVar9 = true;
    }
    if (((!bVar9) && (*(short *)(DAT_0202649c + iVar13) == 0)) &&
       (*(short *)(DAT_02026494 + iVar13) != 0)) {
      bVar10 = true;
    }
    if (bVar10) {
      uVar1 = *(undefined2 *)(DAT_020264a0 + iVar13);
      uVar2 = *(undefined2 *)(DAT_020264a4 + iVar13);
      iVar4 = func_0201ea84(*(undefined4 *)(iVar12 + 0x2c),uVar1,uVar2);
      if (iVar4 < 0) {
        if ((*(int *)(*DAT_02026480 + 0x80) == 0) &&
           (iVar4 = func_02128210(uVar1,uVar2), iVar4 != 0)) {
          func_020273c0();
        }
      }
      else {
        iVar11 = 0;
        iVar5 = *DAT_02026480;
        iVar13 = DAT_020264a8;
        if (0 < *(int *)(iVar5 + 0x7c)) {
          do {
            if (iVar4 == *(short *)(iVar13 + 6)) {
              *(int *)(iVar5 + 0x60) = iVar11;
              break;
            }
            iVar11 = iVar11 + 1;
            iVar13 = iVar13 + 8;
          } while (iVar11 < *(int *)(iVar5 + 0x7c));
        }
        func_020270fc(iVar6);
        uVar7 = func_02025eb0(*(undefined4 *)(*DAT_02026480 + 0xf0));
        func_021106a8(uVar7,0);
        piVar3 = DAT_02026480;
        *(undefined4 *)(*DAT_02026480 + 0x68) = 0;
        *(undefined4 *)(*piVar3 + 0x6c) = 5;
      }
    }
    else {
      iVar5 = func_020270d0();
      piVar3 = DAT_02026480;
      if (iVar5 == 0) {
        if ((*(ushort *)(DAT_020264ac + iVar13) & 1) == 0) {
          if ((*(int *)(*DAT_02026480 + 0x80) == 0) &&
             ((*(ushort *)(DAT_020264ac + iVar13) & 2) != 0)) {
            func_020273c0();
          }
          else {
            iVar13 = func_020ae408(iVar4,0x40);
            if (iVar13 == 0) {
              iVar13 = func_020ae408(iVar4,0x80);
              if (iVar13 == 0) {
                iVar13 = func_020ae408(iVar4,0x10);
                if (iVar13 == 0) {
                  iVar4 = func_020ae408(iVar4,0x20);
                  if (iVar4 != 0) {
                    iVar4 = (int)*(short *)(*DAT_02026480 + 0x8a);
                    if (iVar4 != -1) {
                      *(int *)(*DAT_02026480 + 0x60) = iVar4;
                    }
                  }
                }
                else {
                  iVar4 = (int)*(short *)(*DAT_02026480 + 0x88);
                  if (iVar4 != -1) {
                    *(int *)(*DAT_02026480 + 0x60) = iVar4;
                  }
                }
              }
              else {
                iVar4 = (int)*(short *)(*DAT_02026480 + 0x86);
                if (iVar4 != -1) {
                  *(int *)(*DAT_02026480 + 0x60) = iVar4;
                }
              }
            }
            else {
              iVar4 = (int)*(short *)(*DAT_02026480 + 0x84);
              if (iVar4 != -1) {
                *(int *)(*DAT_02026480 + 0x60) = iVar4;
              }
            }
            if (*(int *)(*DAT_02026480 + 0x60) != iVar6) {
              func_02110698();
              func_020270fc(iVar6);
              *(undefined4 *)(*DAT_02026480 + 0x6c) = 4;
            }
          }
        }
        else {
          *(undefined4 *)(*DAT_02026480 + 0x68) = 0;
          *(undefined4 *)(*piVar3 + 0x6c) = 5;
          func_02027188();
          uVar7 = func_02025eb0(*(undefined4 *)(*DAT_02026480 + 0xf0));
          func_021106a8(uVar7,0);
        }
      }
      else {
        *(undefined4 *)(*DAT_02026480 + 0x68) = 0;
        *(undefined4 *)(*piVar3 + 0x8c) = 3;
        *(undefined4 *)(*piVar3 + 0x6c) = 6;
        uVar7 = func_02025eb0(*(undefined4 *)(*piVar3 + 0xf0));
        func_021106a8(uVar7,0);
        func_02077f48(1);
        iVar4 = *DAT_02026480;
        if (*(int *)(iVar4 + 0x80) == 1) {
          if (*(int *)(*DAT_0202648c + 4) == 8) {
            *(byte *)(*DAT_0202648c + DAT_02026490) = (byte)*(undefined4 *)(iVar4 + 0xf0) | 0xc0;
          }
        }
        else if (*(int *)(iVar4 + 0x80) == 2) {
          func_02121f1c(*(undefined4 *)(iVar4 + 0xf0));
          func_02121eb4(*(undefined4 *)(*DAT_02026480 + 0xf4));
        }
      }
    }
    break;
  case 4:
    *(int *)(iVar12 + 0x68) = *(int *)(iVar12 + 0x68) + 1;
    if (5 < *(int *)(*piVar3 + 0x68)) {
      func_020272ec();
      piVar3 = DAT_02026840;
      *(undefined4 *)(*DAT_02026840 + 0x68) = 0;
      *(undefined4 *)(*piVar3 + 0x6c) = 3;
    }
    break;
  case 5:
    *(int *)(iVar12 + 0x68) = *(int *)(iVar12 + 0x68) + 1;
    if (5 < *(int *)(*piVar3 + 0x68)) {
      *(undefined4 *)(*piVar3 + 0x68) = 0;
      *(undefined4 *)(*piVar3 + 0x8c) = 1;
      func_020272ec();
      iVar6 = *DAT_02026840;
      iVar4 = *(int *)(iVar6 + 0x80);
      if (iVar4 == 0) {
        iVar4 = GetGlobalCA_from_thumb();
        *(undefined4 *)(iVar4 + *(int *)(*DAT_02026840 + 0x78) * 0x18) =
             *(undefined4 *)(iVar6 + 0xf0);
        iVar4 = GetGlobalCA_from_thumb();
        *(undefined4 *)(iVar4 + *(int *)(*DAT_02026840 + 0x78) * 0x18 + 4) =
             *(undefined4 *)(*DAT_02026840 + 0xf4);
        func_02116fb0();
        iVar4 = GetGlobalCA_from_thumb();
        if (*(int *)(iVar4 + 200) == 2) {
          iVar4 = GetGlobalCA_from_thumb();
          *(undefined4 *)(iVar4 + *(int *)(*DAT_02026840 + 0x78) * 0x18 + 0x14) = 1;
          func_02077f48(1);
          *(undefined4 *)(*DAT_02026840 + 0x6c) = 7;
          func_02117060();
          func_02116ec0();
        }
        else {
          func_02027424(1);
          func_02077f5c();
          piVar3 = DAT_02026840;
          *(undefined4 *)(*DAT_02026840 + 0x6c) = 8;
          func_02025f14(*piVar3 + DAT_02026844,2);
        }
      }
      else if (iVar4 == 1) {
        iVar4 = GetGlobalCA_from_thumb();
        if (*(int *)(iVar4 + 200) == 3) {
          if (*(int *)(*DAT_02026848 + 4) == 8) {
            *(byte *)(*DAT_02026848 + DAT_0202684c) =
                 (byte)*(undefined4 *)(*DAT_02026840 + 0xf0) | 0x40;
          }
          func_02025f14(*DAT_02026840 + DAT_02026844,2);
          func_02027424(1);
          *(undefined4 *)(*DAT_02026840 + 0x6c) = 8;
          func_02077f5c();
        }
        else {
          iVar4 = GetGlobalCA_from_thumb();
          if (*(int *)(iVar4 + 200) == 2) {
            if (*(int *)(*DAT_02026848 + 4) == 8) {
              *(byte *)(*DAT_02026848 + DAT_0202684c) =
                   (byte)*(undefined4 *)(*DAT_02026840 + 0xf0) | 0xc0;
            }
            func_02077f48(1);
            *(undefined4 *)(*DAT_02026840 + 0x6c) = 6;
          }
        }
      }
      else if (iVar4 == 2) {
        func_02121f1c(*(undefined4 *)(iVar6 + 0xf0));
        func_02025f14(*DAT_02026840 + DAT_02026844,2);
        func_02027424(1);
        *(undefined4 *)(*DAT_02026840 + 0x6c) = 8;
        func_02077f5c();
      }
    }
    break;
  case 6:
    if (((*(int *)(iVar12 + 0x80) == 1) && (iVar4 = func_0202b888(), iVar4 != 0)) ||
       ((*(int *)(*DAT_02026840 + 0x80) == 2 && (iVar4 = func_02121d0c(), iVar4 != 0)))) {
      if (*(int *)(*DAT_02026840 + 0x80) == 2) {
        func_021219cc();
      }
      iVar4 = GetGlobalCA_from_thumb();
      if ((*(int *)(iVar4 + 200) == 2) || (iVar4 = func_020270d0(), iVar4 != 0)) {
        *(undefined4 *)(*DAT_02026840 + 0x6c) = 7;
      }
      else {
        func_02027424(1);
        func_02025f14(*DAT_02026840 + DAT_02026844,2);
        *(undefined4 *)(*DAT_02026840 + 0x6c) = 8;
      }
    }
    break;
  case 7:
    *(int *)(iVar12 + 0x68) = *(int *)(iVar12 + 0x68) + 1;
    if (0x3c < *(int *)(*piVar3 + 0x68)) {
      if (*(int *)(*piVar3 + 0x80) == 2) {
        func_02027424(3);
      }
      else {
        func_02027424(2);
      }
      func_02025f14(*DAT_02026840 + DAT_02026844,2);
      if (*DAT_02026850 == 2) {
        iVar4 = GetGlobalCA_from_thumb();
        if (*(int *)(iVar4 + 200) == 2) {
          func_0211f378();
        }
      }
      else {
        func_020789d4();
      }
      piVar3 = DAT_02026840;
      *(undefined4 *)(*DAT_02026840 + 0x68) = 0;
      *(undefined4 *)(*piVar3 + 0x6c) = 8;
    }
    break;
  case 8:
    *(int *)(iVar12 + 0x68) = *(int *)(iVar12 + 0x68) + 1;
    iVar4 = *piVar3;
    if (*(int *)(iVar4 + 0x68) < 10) {
      uVar7 = _s32_div_f((10 - *(int *)(iVar4 + 0x68)) * 0x1000);
      *(undefined4 *)(iVar4 + 0x70) = uVar7;
    }
    else {
      iVar6 = GetGlobalCA_from_thumb();
      *(undefined4 *)(iVar6 + *(int *)(*DAT_02026840 + 0x78) * 0x18) = *(undefined4 *)(iVar4 + 0xf0)
      ;
      iVar4 = GetGlobalCA_from_thumb();
      piVar3 = DAT_02026840;
      *(undefined4 *)(iVar4 + *(int *)(*DAT_02026840 + 0x78) * 0x18 + 4) =
           *(undefined4 *)(*DAT_02026840 + 0xf4);
      *(undefined4 *)(*piVar3 + 0x6c) = 9;
    }
    *(short *)(*DAT_02026840 + 0x74) = *(short *)(*DAT_02026840 + 0x74) + (short)DAT_02026854;
    func_02027084();
    break;
  case 9:
    iVar14 = *(int *)(iVar12 + 0x8c);
  }
  func_02025edc(*DAT_02026840 + 0xf8);
  func_02025edc(*DAT_02026840 + DAT_02026844);
  func_02025edc(*DAT_02026840 + DAT_02026858);
  func_02025ebc(*DAT_02026840 + 0xf8);
  func_0202728c();
  uVar7 = func_02025ebc(*DAT_02026840 + DAT_02026844);
  uVar8 = func_02025ebc(*DAT_02026840 + DAT_02026858);
  func_020272c0(uVar7,uVar8);
  if (*DAT_02026850 != 2) {
    if (*(int *)(*DAT_02026840 + 0x8c) != 2) {
      func_02078a9c(*(undefined4 *)(*DAT_02026840 + 0xf0));
      func_02078a34(*(undefined4 *)(*DAT_02026840 + 0xf4));
    }
    iVar4 = GetGlobalCA_from_thumb();
    func_02078420(*(undefined4 *)(iVar4 + 0xd8));
  }
  if (*(int *)(*DAT_02026840 + DAT_0202685c) == 0) {
    func_02124c30(*(undefined4 *)(iVar12 + 0xc),*(undefined4 *)(iVar12 + 8),0,
                  *(undefined4 *)(*DAT_02026840 + 0x54),*(undefined4 *)(iVar12 + 0x18));
  }
  else {
    func_0202bb80();
  }
  if (*DAT_02026850 == 2) {
    iVar4 = GetGlobalCA_from_thumb();
    if (*(int *)(iVar4 + 200) == 2) {
      func_0211f39c();
    }
  }
  else {
    func_02124bf0(*(undefined4 *)(iVar12 + 0x28),*(undefined4 *)(iVar12 + 0x24),0,
                  *(undefined4 *)(*DAT_02026904 + 0x58),*(undefined4 *)(iVar12 + 0x34));
    func_020ae5d4(*(undefined4 *)(*DAT_02026904 + 0x58));
  }
  if (*DAT_02026908 != 2) {
    func_020780f4();
  }
  if (iVar14 == 1) {
    iVar4 = GetGlobalCA_from_thumb();
    if (*(int *)(iVar4 + 200) == 2) {
      iVar4 = GetGlobalCA_from_thumb();
      *(undefined4 *)(iVar4 + DAT_0202690c) = 0;
    }
    else {
      iVar4 = GetGlobalCA_from_thumb();
      *(undefined4 *)(iVar4 + DAT_0202690c) = 1;
    }
  }
  else if (iVar14 == 2) {
    if (*DAT_02026908 != 2) {
      func_02078a9c(0xffffffff);
      func_02078a34(0xffffffff);
    }
    iVar4 = GetGlobalCA_from_thumb();
    *(undefined4 *)(iVar4 + DAT_0202690c) = 0;
  }
  return iVar14;
}

