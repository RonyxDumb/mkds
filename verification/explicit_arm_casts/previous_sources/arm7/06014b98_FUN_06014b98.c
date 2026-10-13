/* Decompiled C draft; module arm7; ROM address 06014b98. No matching claim. */
#include "types.h"
#include "deps/06014b98_FUN_06014b98.h"

void FUN_06014b98(short *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined2 *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  ushort uVar7;
  int *piVar8;
  uint uVar9;
  short *psVar10;
  
  uVar6 = *(uint *)(DAT_0601507c & 0xfffffffc) >> (DAT_0601507c & 3) * 8 |
          *(uint *)(DAT_0601507c & 0xfffffffc) << (DAT_0601507c & 3) * -8 + 0x20;
  psVar10 = (short *)(uVar6 + DAT_06015080);
  piVar8 = (int *)(uVar6 + DAT_06015084);
  uVar9 = (uint)(ushort)param_1[1];
  if ((param_1[4] & 2U) == 0) {
    *piVar8 = (*(uint *)((uint)piVar8 & 0xfffffffc) >> ((uint)piVar8 & 3) * 8 |
              *(uint *)((uint)piVar8 & 0xfffffffc) << ((uint)piVar8 & 3) * -8 + 0x20) + 1;
    if ((param_1[0xc] & 1U) == 0) {
      uVar4 = (uint)(piVar8 + 4) & 3;
      uVar1 = *(uint *)((uint)(piVar8 + 4) & 0xfffffffc);
      piVar8[4] = (uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) + 1;
    }
    else {
      uVar4 = (uint)(piVar8 + 5) & 3;
      uVar1 = *(uint *)((uint)(piVar8 + 5) & 0xfffffffc);
      piVar8[5] = (uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) + 1;
    }
    iVar2 = FUN_0600e8d8(uVar9);
    if ((iVar2 != 0) && ((param_1[10] & 0x2000U) == 0)) {
      FUN_0600eb00(uVar9);
    }
  }
  else {
    uVar4 = (uint)(piVar8 + 1) & 3;
    uVar1 = *(uint *)((uint)(piVar8 + 1) & 0xfffffffc);
    piVar8[1] = (uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) + 1;
  }
  if ((int)((uint)(ushort)param_1[10] << 0x11) < 0) {
    uVar4 = (uint)(piVar8 + 6) & 3;
    uVar1 = *(uint *)((uint)(piVar8 + 6) & 0xfffffffc);
    piVar8[6] = (uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) + 1;
  }
  uVar4 = (uint)(piVar8 + 2) & 3;
  uVar1 = *(uint *)((uint)(piVar8 + 2) & 0xfffffffc);
  piVar8[2] = (uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) + ((ushort)param_1[6] & 0xff);
  uVar4 = DAT_0601507c;
  uVar7 = param_1[10] & 0xfc;
  if (uVar7 < 0xa1) {
    if (uVar7 < 0xa0) {
      if (uVar7 < 0x11) {
        if (uVar7 != 0x10) goto LAB_0601502c;
      }
      else if (uVar7 != 0x30) goto LAB_0601502c;
      if (uVar9 != 0) {
        if ((param_1[4] & 2U) == 0) {
          if (param_1[0x17] == 0) {
            FUN_0600ebbc(uVar9,0x40);
            if (uVar7 == 0x10) {
              FUN_0600f908(param_1 + 0xc,param_1[0x18],(int)param_1 + (ushort)param_1[9] + 0x14);
            }
            else {
              FUN_0600f818(param_1 + 0xc,param_1[0x18],(int)param_1 + (ushort)param_1[9] + 0x14);
            }
          }
        }
        else {
          FUN_0600e934(uVar9);
          puVar3 = (undefined2 *)FUN_0601364c(param_1 + 0xc,1);
          if (puVar3 != (undefined2 *)0x0) {
            *puVar3 = 2;
            if (param_2 == 0) {
              FUN_06014338();
            }
            else {
              FUN_060143ac();
            }
          }
        }
      }
    }
    else {
      if (*(short *)(uVar6 + 0x350) == 1) {
        if (uVar9 == 0) {
          if ((param_1[0xc] & 1U) != 0) {
            for (uVar9 = 1;
                uVar9 < *(ushort *)
                         ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x322);
                uVar9 = uVar9 + 1) {
              uVar1 = FUN_0600e918(uVar9);
              if (0x30 < uVar1) {
                FUN_0600ebbc(uVar9 & 0xffff,0x30);
              }
            }
          }
        }
        else {
          uVar4 = FUN_0600e918(uVar9);
          if (0x30 < uVar4) {
            FUN_0600ebbc(uVar9,0x30);
          }
        }
      }
      else if (0x30 < *(ushort *)(uVar6 + 0x34c)) {
        FUN_0600a970(0x30);
        FUN_0600aa54();
      }
      if (*psVar10 == 0x71) {
        if ((param_1[4] & 2U) == 0) {
          uVar9 = (uint)(psVar10 + 0xe) & 3;
          uVar4 = *(uint *)((uint)(psVar10 + 0xe) & 0xfffffffc);
          *(undefined2 *)((uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) + 4) = 0;
        }
        else {
          uVar9 = (uint)(psVar10 + 0xe) & 3;
          uVar4 = *(uint *)((uint)(psVar10 + 0xe) & 0xfffffffc);
          *(undefined2 *)((uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) + 4) = 0xc;
        }
        *psVar10 = 0;
        FUN_0600fafc();
      }
    }
  }
  else if (uVar7 < 0xb1) {
    if (((uVar7 == 0xb0) && (uVar9 != 0)) && ((param_1[4] & 2U) == 0)) {
      if (((param_1[0x16] == 0) && (param_1[0x17] == 2)) && (param_1[0x18] == 0)) {
        FUN_0600ebbc(uVar9,0x30);
        FUN_0600fa80(param_1 + 0xc,param_1[0x16]);
      }
      else if (((param_1[0x16] == 1) && (param_1[0x17] == 4)) && (param_1[0x18] == 0)) {
        FUN_0600ebbc(uVar9,0x30);
        FUN_0600fa80(param_1 + 0xc,param_1[0x16]);
      }
    }
  }
  else if (uVar7 == 0xc0) {
    if (*(short *)(uVar6 + 0x350) == 1) {
      if (uVar9 == 0) {
        if ((param_1[0xc] & 1U) != 0) {
          for (uVar1 = 1;
              uVar1 < *(ushort *)
                       ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                        *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x322);
              uVar1 = uVar1 + 1) {
            uVar5 = FUN_0600e918(uVar1);
            if (0x20 < uVar5) {
              FUN_0600ebbc(uVar1 & 0xffff,0x20);
            }
          }
        }
      }
      else {
        uVar4 = FUN_0600e918(uVar9);
        if (0x20 < uVar4) {
          FUN_0600ebbc(uVar9,0x20);
        }
      }
    }
    else if (0x20 < *(ushort *)(uVar6 + 0x34c)) {
      FUN_0600a970(0x20);
      FUN_0600aa54();
    }
    if (*psVar10 == 0x41) {
      if ((param_1[4] & 2U) == 0) {
        uVar4 = (uint)(psVar10 + 0xe) & 3;
        uVar1 = *(uint *)((uint)(psVar10 + 0xe) & 0xfffffffc);
        *(undefined2 *)((uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) + 4) = 0;
      }
      else {
        uVar4 = (uint)(psVar10 + 0xe) & 3;
        uVar1 = *(uint *)((uint)(psVar10 + 0xe) & 0xfffffffc);
        *(undefined2 *)((uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) + 4) = 0xc;
      }
      *psVar10 = 0;
      FUN_0600fafc();
    }
    if (*param_1 == 1) {
      if (uVar9 != 0) {
        uVar4 = *(uint *)(DAT_0601507c & 0xfffffffc) >> (DAT_0601507c & 3) * 8 |
                *(uint *)(DAT_0601507c & 0xfffffffc) << (DAT_0601507c & 3) * -8 + 0x20;
        *(ushort *)(uVar4 + 0x534) = *(ushort *)(uVar4 + 0x534) & ~(ushort)(1 << (uVar9 & 0xff));
        FUN_0600e47c(uVar9);
      }
      FUN_0600fa04(param_1 + 0xc,1);
    }
    else if (*param_1 == 2) {
      FUN_0600fa04(param_1 + 0xc,1);
    }
  }
LAB_0601502c:
  FUN_0600ec88(param_1);
  FUN_060090b4(uVar6 + 0x1a0,param_1 + -8);
  *(undefined2 *)
   ((*(uint *)(DAT_0601507c & 0xfffffffc) >> (DAT_0601507c & 3) * 8 |
    *(uint *)(DAT_0601507c & 0xfffffffc) << (DAT_0601507c & 3) * -8 + 0x20) + 0x440) = 0;
  if ((param_2 != 0) && (*(short *)(uVar6 + 0x1a8) != 0)) {
    FUN_0601536c(1);
  }
  return;
}

