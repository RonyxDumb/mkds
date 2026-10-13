/* Decompiled C draft; module arm9_ov000; ROM address 021a01dc. No matching claim. */
#include "types.h"
#include "deps/021a01dc_FUN_021a01dc.h"

/* WARNING: Type propagation algorithm not settling */

undefined4 FUN_021a01dc(int param_1,int param_2,int param_3,uint param_4,int *param_5,int param_6)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  undefined8 uVar11;
  int local_134;
  uint local_130;
  int local_124;
  undefined1 auStack_120 [2];
  ushort local_11e;
  int local_11c;
  uint local_118 [65];
  
  piVar2 = DAT_021a0528;
  iVar9 = 0;
  iVar10 = *DAT_021a0528;
  if (iVar10 != 0) {
    iVar7 = *(int *)(iVar10 + DAT_021a052c);
    if (iVar7 != 0) {
      switch(param_1) {
      case 1:
      case 0xb:
        iVar10 = FUN_021a0064(param_2,*param_5,param_1 == 0xb);
        local_134 = param_3;
        local_130 = param_4;
        if (iVar10 == 2) {
          if (*(char *)(*DAT_021a0528 + 0x15) != '\0') {
            local_134 = param_5[1];
            local_130 = param_5[2] & 0xffff;
          }
          FUN_0219ff54(param_2,local_134,local_130);
          iVar9 = FUN_0219fee4();
          if (iVar9 != 0) {
            return 0;
          }
          iVar9 = *DAT_021a0528;
          if ((*(char *)(iVar9 + 0x15) == '\x02') && (*(int *)(iVar9 + DAT_021a0530) != 0)) {
            uVar3 = FUN_0219d5e4(param_2);
            (**(code **)(*DAT_021a0528 + DAT_021a0530))(uVar3,*(undefined4 *)(iVar9 + DAT_021a0534))
            ;
          }
          iVar9 = *DAT_021a0528;
          local_118[0] = (uint)*(byte *)(iVar9 + 0x14);
          iVar7 = 1;
          if (*(char *)(iVar9 + 0x14) != '\0') {
            puVar5 = local_118;
            iVar6 = iVar9;
            do {
              puVar5 = puVar5 + 1;
              *puVar5 = *(uint *)(iVar6 + 0xf8);
              iVar7 = iVar7 + 1;
              iVar6 = iVar6 + 4;
            } while (iVar7 <= (int)(uint)*(byte *)(iVar9 + 0x14));
          }
          iVar6 = *DAT_021a0528;
          local_118[iVar7] = *(uint *)(iVar6 + 0x1c);
          iVar9 = iVar7 + 2;
          local_118[iVar7 + 1] = (uint)*(ushort *)(iVar6 + 0x1a);
          *(undefined4 *)(iVar6 + DAT_021a052c) = 0xb;
        }
        if (iVar10 != 0xff) {
          FUN_021a0ae8(iVar10,param_2,local_134,local_130,local_118,iVar9);
          iVar9 = FUN_0219fee4();
          if (iVar9 != 0) {
            return 0;
          }
        }
        break;
      case 2:
        if ((iVar7 == 4) && (param_2 == *(int *)(iVar10 + DAT_021a0538))) {
          *(undefined4 *)(iVar10 + DAT_021a053c) = 0;
          *(undefined1 *)(*piVar2 + DAT_021a0540) = 0;
          *(undefined4 *)(*piVar2 + DAT_021a0544) = 0;
          *(undefined4 *)(*piVar2 + DAT_021a0548) = 0;
          *(int *)(*piVar2 + 0x24) = param_5[*param_5 + 1];
          *(short *)(*piVar2 + 0xa4) = (short)param_5[*param_5 + 2];
          *(int *)(*piVar2 + DAT_021a054c) = param_5[*param_5 + 1];
          *(short *)(*piVar2 + DAT_021a0550) = (short)param_5[*param_5 + 2];
          if (*(char *)(*piVar2 + 0x15) == '\x01') {
            iVar9 = FUN_0219f4c4(param_5 + 1,*param_5);
            if (iVar9 == 0) {
              FUN_0219fb14(param_2);
              iVar9 = FUN_0219fee4();
              if (iVar9 != 0) {
                return 0;
              }
              FUN_0219fbec(0,0);
              iVar9 = FUN_0219fee4();
              if (iVar9 == 0) {
                return 1;
              }
              return 0;
            }
            if (*(char *)(*DAT_021a0528 + 0xd) != '\0') {
              FUN_0219ff0c(param_2,param_5);
            }
          }
          iVar9 = *DAT_021a0528;
          if (*(char *)(iVar9 + 0x15) == '\0') {
            if (*(char *)(iVar9 + 0xd) != '\0') {
              FUN_0219ff0c(param_2,param_5);
              FUN_0219f8b0();
              iVar9 = FUN_0219fee4();
              if (iVar9 != 0) {
                return 0;
              }
            }
            piVar2 = DAT_021a0528;
            *(undefined4 *)(*DAT_021a0528 + DAT_021a052c) = 6;
            uVar3 = FUN_0218b480(*(undefined4 *)(*piVar2 + 0xe4),0);
            FUN_021a0cac(0,0,uVar3);
            iVar9 = FUN_0219e4a0();
            if (iVar9 != 0) {
              return 0;
            }
          }
          else {
            *(undefined4 *)(iVar9 + DAT_021a052c) = 5;
            FUN_021a0f20(param_2);
            iVar9 = FUN_0219e594();
            if (iVar9 != 0) {
              return 0;
            }
          }
        }
        break;
      case 3:
        if ((iVar7 == 4) && (param_2 == *(int *)(iVar10 + DAT_021a0538))) {
          uVar3 = FUN_0219fb48();
          return uVar3;
        }
        break;
      case 4:
        if ((iVar7 == 4) && (param_2 == *(int *)(iVar10 + DAT_021a0538))) {
          uVar11 = func_0x0200f5ac();
          *(int *)(iVar10 + DAT_021a0554) = (int)uVar11;
          *(int *)(iVar10 + DAT_021a0558) = (int)((ulonglong)uVar11 >> 0x20);
          if (((*(int *)(iVar10 + DAT_021a053c) == 0) || (0xf < *(byte *)(iVar10 + DAT_021a0540)))
             && (*(char *)(iVar10 + 0x15) != '\x03')) {
            *(undefined4 *)(iVar10 + DAT_021a053c) = 0;
            piVar2 = DAT_021a0528;
            *(undefined1 *)(*DAT_021a0528 + DAT_021a0540) = 0;
            iVar9 = *piVar2;
            if (*(char *)(iVar9 + 0x15) == '\0') {
              *(undefined4 *)(iVar9 + DAT_021a052c) = 3;
              *(undefined4 *)(*piVar2 + 0xe8) = 1;
              uVar11 = func_0x0200f5ac();
              *(undefined8 *)(*DAT_021a0528 + 0xec) = uVar11;
            }
            else if (*(char *)(iVar9 + 0x15) == '\x01') {
              FUN_0219fbec(1);
            }
          }
          else {
            *(undefined4 *)(iVar10 + DAT_021a0548) = 1;
            iVar9 = *DAT_021a0528;
            uVar11 = func_0x0200f5ac();
            *(int *)(iVar9 + DAT_021a055c) = (int)uVar11;
            *(int *)(iVar9 + DAT_021a0560) = (int)((ulonglong)uVar11 >> 0x20);
            if (*(char *)(iVar9 + 0x15) != '\x03') {
              *(char *)(iVar9 + DAT_021a0540) = *(char *)(iVar9 + DAT_021a0540) + '\x01';
            }
          }
        }
        break;
      case 5:
        if ((*(char *)(iVar10 + 0x17) != '\0') && (param_2 == *(int *)(iVar10 + 0x20))) {
          if ((*(char *)(iVar10 + 0x15) == '\x02') &&
             ((*(char *)(iVar10 + 0xd) == '\x01' && (*(int *)(iVar10 + 0xf8) == param_2)))) {
            FUN_021988e8(**(undefined4 **)(iVar10 + 4));
          }
          iVar9 = FUN_0219f9bc(param_2);
          if (iVar9 == 0) {
            return 0;
          }
        }
        break;
      case 6:
        local_11c = *param_5;
        uVar4 = param_5[1];
        if (iVar7 == 1) {
          *(int *)(iVar10 + DAT_021a052c) = 6;
        }
        else {
          if ((iVar7 != 6) && (iVar7 != 0xb)) {
            return 1;
          }
          if (param_2 != *(int *)(iVar10 + 0x20)) {
            return 1;
          }
        }
        piVar2 = DAT_021a0904;
        *(undefined1 *)(*DAT_021a0904 + DAT_021a0908) = 0xff;
        iVar10 = *piVar2 + 0xf4;
        iVar9 = (*(byte *)(*piVar2 + 0xd) + 1) * 4;
        if (param_2 != *(int *)(iVar10 + iVar9)) {
          *(int *)(iVar10 + iVar9) = param_2;
        }
        piVar2 = DAT_021a0904;
        local_11e = (ushort)((uVar4 & 0xffff) >> 8) |
                    (ushort)((uVar4 & 0xffff) << 8) & (ushort)DAT_021a090c;
        *(undefined1 *)(*DAT_021a0904 + DAT_021a0910) = 1;
        iVar9 = *piVar2;
        uVar3 = FUN_021988d8(**(undefined4 **)(iVar9 + 4));
        FUN_0219db18(0,uVar3,auStack_120,iVar9 + DAT_021a0910);
        iVar9 = *DAT_021a0904;
        *(undefined4 *)(iVar9 + DAT_021a0914) = 0;
        *(undefined4 *)(iVar9 + DAT_021a0918) = 0;
        break;
      case 7:
        local_124 = *param_5;
        iVar9 = param_5[1];
        *(int *)(iVar10 + (*(byte *)(iVar10 + 0x14) + 1) * 4 + 0xf4) = local_124;
        *(char *)(*piVar2 + *(byte *)(*piVar2 + 0x14) + 1 + DAT_021a091c) = (char)iVar9;
        FUN_021a4818(*(undefined4 *)(*piVar2 + 0x10));
        iVar9 = *DAT_021a0904;
        if (*(int *)(iVar9 + DAT_021a0920) != 0) {
          uVar3 = FUN_0219d5e4(local_124);
          (**(code **)(*DAT_021a0904 + DAT_021a0920))(uVar3,*(undefined4 *)(iVar9 + DAT_021a0924));
        }
        break;
      case 8:
        local_124 = *param_5;
        if (local_124 == 0) {
          iVar9 = param_5[1];
          *(char *)(iVar10 + iVar9 + DAT_021a091c) = (char)param_5[2];
          *(undefined4 *)(*piVar2 + iVar9 * 4 + 0xf4) = *(undefined4 *)(*piVar2 + DAT_021a0928);
          FUN_0219f544(3);
        }
        else {
          iVar9 = param_5[1];
          iVar7 = param_5[2];
          iVar6 = iVar9 * 4;
          if ((local_124 == *(int *)(iVar10 + 0xf4 + iVar6)) &&
             (iVar9 == *(byte *)(iVar10 + 0xd) - 1)) {
            FUN_021a0ae8(9,param_2,*(undefined4 *)(iVar10 + 0x24),*(undefined2 *)(iVar10 + 0xa4),
                         &local_124,1);
            iVar9 = FUN_0219fee4();
            if (iVar9 != 0) {
              return 0;
            }
          }
          else {
            *(int *)(iVar10 + 0xf4 + iVar6) = local_124;
            piVar2 = DAT_021a0904;
            *(char *)(*DAT_021a0904 + iVar9 + DAT_021a091c) = (char)iVar7;
            *(int *)(*piVar2 + iVar6 + 0x24) = param_5[3];
            *(short *)(*piVar2 + iVar9 * 2 + 0xa4) = (short)param_5[4];
            *(int *)(*piVar2 + DAT_021a092c) = param_5[3];
            *(short *)(*piVar2 + DAT_021a0930) = (short)param_5[4];
            *(undefined4 *)(*piVar2 + DAT_021a0934) = 5;
            FUN_021a0f20(local_124);
            iVar9 = FUN_0219e594();
            piVar2 = DAT_021a0904;
            if (iVar9 != 0) {
              return 0;
            }
            *(undefined4 *)(*DAT_021a0904 + DAT_021a0938) = 0;
            *(undefined4 *)(*piVar2 + DAT_021a093c) = 0;
          }
        }
        break;
      case 9:
        if (iVar7 == 0xd) {
          iVar9 = *(byte *)(iVar10 + DAT_021a0940) + 1;
          if (*param_5 == *(int *)(iVar10 + iVar9 * 4 + 0xf4)) {
            *(byte *)(iVar10 + DAT_021a0940) = (byte)iVar9;
            FUN_0219f544(0);
          }
        }
        break;
      case 10:
        if ((*(char *)(iVar10 + 0x15) == '\0') ||
           (iVar9 = FUN_0219f4c4(param_5 + 1,*param_5), iVar9 != 0)) {
          piVar2 = DAT_021a0904;
          *(int *)(*DAT_021a0904 + DAT_021a0944) = param_5[1];
          *(undefined1 *)(*piVar2 + DAT_021a0948) = 0;
        }
        else {
          *(undefined4 *)(*DAT_021a0904 + DAT_021a0944) = 0;
        }
        if (*(char *)(*DAT_021a0904 + 0xd) == '\0') {
          iVar9 = FUN_0219f184();
          if (iVar9 != 0) {
            return 0;
          }
        }
        else {
          FUN_021988e8(**(undefined4 **)(*DAT_021a0904 + 4));
        }
        break;
      case 0xc:
        if ((*(char *)(iVar10 + 0x15) == '\0') || (*(char *)(iVar10 + 0x15) == '\x01')) {
          iVar9 = FUN_0219f938(param_2);
          if (iVar9 == 0) {
            return 0;
          }
        }
        else if (*(char *)(iVar10 + 0x15) == '\x03') {
          if (*param_5 == 0) {
            *(int *)(iVar10 + DAT_021a094c) = param_2;
            FUN_0219f0f4();
            FUN_0219f23c(0);
          }
          else {
            FUN_0219f124();
          }
        }
        break;
      case 0xd:
      case 0xe:
      case 0xf:
        iVar9 = FUN_0219ec44(param_2,param_1,*param_5);
        if (iVar9 == 0) {
          return 0;
        }
        break;
      case 0x10:
        if (param_2 != *(int *)(iVar10 + 0xf4)) {
          return 1;
        }
        if (0 < param_6) {
          do {
            iVar10 = FUN_0219e948(*param_5,0);
            if (iVar10 != 0xff) {
              FUN_0219bbac();
            }
            param_5 = param_5 + 1;
            iVar9 = iVar9 + 1;
          } while (iVar9 < param_6);
        }
        break;
      case 0x11:
        pcVar8 = (char *)*DAT_021a0950;
        if (((pcVar8 == (char *)0x0) || (*pcVar8 == '\0')) ||
           (uVar11 = FUN_021a350c(),
           uVar4 = (int)((ulonglong)uVar11 >> 0x20) - *(int *)(pcVar8 + 0x14),
           uVar1 = (uint)((uint)uVar11 < *(uint *)(pcVar8 + 0x10)),
           uVar4 == uVar1 &&
           (uint)(*(uint *)(pcVar8 + 4) <= (uint)uVar11 - *(uint *)(pcVar8 + 0x10)) <= uVar4 - uVar1
           )) {
          local_118[0] = 0;
        }
        else {
          local_118[0] = 1;
        }
        FUN_021a0ae8(0x12,param_2,param_3,param_4,local_118,1);
        iVar9 = FUN_0219fee4();
        if (iVar9 != 0) {
          return 0;
        }
        break;
      case 0x12:
        if ((iVar7 == 0x13) &&
           (uVar4 = FUN_0219e948(param_2,0), piVar2 = DAT_021a0950, uVar4 != 0xff)) {
          uVar4 = 1 << (uVar4 & 0xff);
          *(uint *)(*DAT_021a0950 + 8) = *(uint *)(*DAT_021a0950 + 8) | uVar4;
          if (*param_5 != 0) {
            *(uint *)(*piVar2 + 0xc) = *(uint *)(*piVar2 + 0xc) | uVar4;
          }
        }
        break;
      case 0x13:
        FUN_021a1a38(10,DAT_021a0954);
        return 0;
      }
      return 1;
    }
  }
  return 1;
}

