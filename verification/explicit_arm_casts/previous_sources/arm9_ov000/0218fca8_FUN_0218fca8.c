/* Decompiled C draft; module arm9_ov000; ROM address 0218fca8. No matching claim. */
#include "types.h"
#include "deps/0218fca8_FUN_0218fca8.h"

int FUN_0218fca8(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 local_1160;
  undefined4 local_115c;
  undefined4 local_1158;
  undefined4 local_1154;
  int local_1150;
  uint local_114c;
  uint local_1148;
  int local_1144;
  undefined4 local_1140;
  int local_113c;
  undefined4 local_1138;
  int local_1134;
  undefined4 local_1130;
  int local_112c;
  undefined4 local_1128;
  undefined1 auStack_1124 [16];
  undefined1 auStack_1114 [4352];
  
  iVar8 = *param_1;
  iVar1 = FUN_021967b4(param_2,DAT_0219003c,auStack_1114,DAT_02190040);
  if (iVar1 == 0) {
    FUN_021965a0(param_1,1,DAT_02190044);
    FUN_02190f4c(param_1,3,1);
    return 3;
  }
  iVar1 = func_0x0213bf90(auStack_1114);
  iVar2 = FUN_021967b4(param_2,DAT_02190048,auStack_1114,DAT_02190040);
  if (iVar2 == 0) {
    FUN_021965a0(param_1,1,DAT_02190044);
    FUN_02190f4c(param_1,3,1);
    return 3;
  }
  local_1154 = func_0x0213bf90(auStack_1114);
  iVar2 = FUN_021967b4(param_2,DAT_0219004c,auStack_1114,DAT_02190040);
  if (iVar2 == 0) {
    local_1158 = FUN_0218e320(0);
  }
  else {
    local_1158 = func_0x0213bf90(auStack_1114);
  }
  if (iVar1 < 0x65) {
    if (iVar1 < 100) {
      if ((iVar1 < 3) && (0 < iVar1)) {
        if (iVar1 == 1) {
          local_1144 = *(int *)(iVar8 + DAT_02190050);
          local_1140 = *(undefined4 *)(iVar8 + DAT_02190054);
          if (local_1144 != 0) {
            puVar7 = (undefined4 *)FUN_021a3690(0xc);
            if (puVar7 == (undefined4 *)0x0) {
              FUN_02196590(param_1,DAT_02190058);
              return 1;
            }
            iVar1 = FUN_021967b4(param_2,DAT_0219005c,auStack_1114,DAT_02190040);
            if (iVar1 == 0) {
              FUN_021965a0(param_1,1,DAT_02190044);
              FUN_02190f4c(param_1,3,1);
              return 3;
            }
            iVar1 = func_0x0213a434(auStack_1114);
            uVar3 = FUN_021a3690(iVar1 + 1);
            puVar7[2] = uVar3;
            if (puVar7[2] == 0) {
              FUN_02196590(param_1,DAT_02190058);
              return 1;
            }
            func_0x0213a2d0(puVar7[2],auStack_1114);
            *puVar7 = local_1154;
            puVar7[1] = local_1158;
            local_1160 = 0;
            local_115c = 2;
            iVar1 = FUN_02190ed4(param_1,local_1144,local_1140,puVar7);
            if (iVar1 != 0) {
              return iVar1;
            }
          }
        }
        else if (iVar1 == 2) {
          iVar1 = FUN_0219496c(param_1,local_1154);
          if (iVar1 == 0) {
            FUN_02196590(param_1,DAT_02190058);
            return 1;
          }
          iVar2 = FUN_021967b4(param_2,DAT_0219005c,auStack_1114,DAT_02190040);
          if (iVar2 == 0) {
            FUN_021965a0(param_1,1,DAT_02190044);
            FUN_02190f4c(param_1,3,1);
            return 3;
          }
          puVar6 = (undefined1 *)func_0x02139f70(auStack_1114,DAT_02190060);
          if (puVar6 == (undefined1 *)0x0) {
            FUN_021965a0(param_1,1,DAT_02190044);
            FUN_02190f4c(param_1,3,1);
            return 3;
          }
          *puVar6 = 0;
          iVar2 = func_0x0213a434(puVar6 + 8);
          if (iVar2 != 0x20) {
            FUN_021965a0(param_1,1,DAT_02190044);
            FUN_02190f4c(param_1,3,1);
            return 3;
          }
          FUN_021a3668(*(undefined4 *)(iVar1 + 0x10));
          *(undefined4 *)(iVar1 + 0x10) = 0;
          uVar3 = FUN_0218e880(puVar6 + 8);
          *(undefined4 *)(iVar1 + 0x10) = uVar3;
          *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + 1;
          local_112c = *(int *)(iVar8 + DAT_02190064);
          local_1128 = *(undefined4 *)(iVar8 + DAT_02190068);
          if (local_112c != 0) {
            puVar7 = (undefined4 *)FUN_021a3690(DAT_0219006c);
            if (puVar7 == (undefined4 *)0x0) {
              FUN_02196590(param_1,DAT_02190058);
              return 1;
            }
            FUN_02196914(puVar7 + 2,auStack_1114,DAT_02190070);
            *puVar7 = local_1154;
            puVar7[1] = local_1158;
            local_1160 = 0;
            local_115c = 6;
            iVar1 = FUN_02190ed4(param_1,local_112c,local_1128,puVar7);
            if (iVar1 != 0) {
              return iVar1;
            }
          }
        }
      }
    }
    else {
      iVar1 = FUN_0219496c(param_1,local_1154);
      if (iVar1 == 0) {
        FUN_02196590(param_1,DAT_02190058);
        return 1;
      }
      if (*(int *)(iVar1 + 8) == 0) {
        uVar3 = FUN_021a3690(0x18);
        *(undefined4 *)(iVar1 + 8) = uVar3;
        puVar6 = *(undefined1 **)(iVar1 + 8);
        if (puVar6 == (undefined1 *)0x0) {
          FUN_02196590(param_1,DAT_0219044c);
          return 1;
        }
        iVar2 = 0x18;
        do {
          *puVar6 = 0;
          puVar6 = puVar6 + 1;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
        iVar2 = *(int *)(iVar8 + DAT_02190450);
        *(int *)(iVar8 + DAT_02190450) = iVar2 + 1;
        **(int **)(iVar1 + 8) = iVar2;
      }
      puVar7 = *(undefined4 **)(iVar1 + 8);
      iVar1 = FUN_021967b4(param_2,DAT_02190454,auStack_1114,DAT_02190458);
      if (iVar1 == 0) {
        FUN_021965a0(param_1,1,DAT_0219045c);
        FUN_02190f4c(param_1,3,1);
        return 3;
      }
      iVar1 = FUN_021967b4(auStack_1114,DAT_02190460,auStack_1124,0x10);
      if (iVar1 == 0) {
        FUN_021965a0(param_1,1,DAT_0219045c);
        FUN_02190f4c(param_1,3,1);
        return 3;
      }
      uVar3 = func_0x0213bf90(auStack_1124);
      puVar7[1] = uVar3;
      FUN_021a3668(puVar7[2]);
      puVar7[2] = 0;
      iVar1 = FUN_021967b4(auStack_1114,DAT_02190464,(int)&local_1160 + DAT_02190468,DAT_0219046c);
      if (iVar1 == 0) {
        *(undefined1 *)((int)&local_1160 + DAT_02190468) = 0;
      }
      uVar3 = FUN_0218e880((int)&local_1160 + DAT_02190468);
      puVar7[2] = uVar3;
      if (puVar7[2] == 0) {
        FUN_02196590(param_1,DAT_0219044c);
        return 1;
      }
      FUN_021a3668(puVar7[3]);
      puVar7[3] = 0;
      iVar1 = FUN_021967b4(auStack_1114,DAT_02190470,(int)&local_1160 + DAT_02190468,DAT_0219046c);
      if (iVar1 == 0) {
        *(undefined1 *)((int)&local_1160 + DAT_02190468) = 0;
      }
      uVar3 = FUN_0218e880((int)&local_1160 + DAT_02190468);
      puVar7[3] = uVar3;
      if (puVar7[3] == 0) {
        FUN_02196590(param_1,DAT_0219044c);
        return 1;
      }
      iVar1 = FUN_021967b4(auStack_1114,DAT_02190474,auStack_1124,0x10);
      if (iVar1 == 0) {
        puVar7[4] = 0;
      }
      else {
        iVar1 = func_0x0213bf90(auStack_1124);
        local_1150 = func_0x0213bf90(auStack_1124);
        local_114c = func_0x0213bf90(auStack_1124);
        local_1148 = func_0x0213bf90(auStack_1124);
        puVar7[4] = iVar1 << 0x18 & DAT_02190478 |
                    local_1150 << 8 & DAT_0219047c |
                    local_114c >> 0x18 | local_1148 >> 8 & DAT_02190480;
      }
      iVar1 = FUN_021967b4(auStack_1114,DAT_02190484,auStack_1124,0x10);
      if (iVar1 == 0) {
        puVar7[5] = 0;
      }
      else {
        uVar4 = func_0x0213bf90(auStack_1124);
        puVar7[5] = (int)(uVar4 & 0xffff) >> 8 | (uVar4 & 0xffff) << 8 & DAT_02190480 & 0xffff;
      }
      local_1134 = *(int *)(iVar8 + DAT_02190488);
      local_1130 = *(undefined4 *)(iVar8 + DAT_0219048c);
      if (local_1134 != 0) {
        puVar5 = (undefined4 *)FUN_021a3690(0xc);
        if (puVar5 == (undefined4 *)0x0) {
          FUN_02196590(param_1,DAT_0219044c);
          return 1;
        }
        *puVar5 = local_1154;
        puVar5[2] = *puVar7;
        puVar5[1] = local_1158;
        local_1160 = 0;
        local_115c = 5;
        iVar1 = FUN_02190ed4(param_1,local_1134,local_1130);
        if (iVar1 != 0) {
          return iVar1;
        }
      }
    }
  }
  else if ((iVar1 < 0x67) && (100 < iVar1)) {
    if (iVar1 == 0x65) {
      iVar1 = FUN_021967b4(param_2,DAT_02190454,auStack_1114,DAT_02190458);
      if (iVar1 == 0) {
        FUN_021965a0(param_1,1,DAT_0219045c);
        FUN_02190f4c(param_1,3,1);
        return 3;
      }
      iVar1 = func_0x02139f70(auStack_1114,DAT_02190484);
      if (iVar1 == 0) {
        FUN_021965a0(param_1,1,DAT_0219045c);
        FUN_02190f4c(param_1,3,1);
        return 3;
      }
      if (*(char *)(iVar1 + 3) == '\0') {
        FUN_021965a0(param_1,1,DAT_0219045c);
        FUN_02190f4c(param_1,3,1);
        return 3;
      }
      uVar3 = func_0x0213bf90(iVar1 + 3);
      iVar1 = func_0x02139f70(auStack_1114,DAT_02190490);
      if (iVar1 == 0) {
        *(undefined1 *)((int)&local_1160 + DAT_02190468) = 0;
      }
      else {
        FUN_02196914((int)&local_1160 + DAT_02190468,iVar1 + 3,DAT_0219046c);
      }
      local_113c = *(int *)(iVar8 + DAT_02190494);
      local_1138 = *(undefined4 *)(iVar8 + DAT_02190498);
      if (local_113c != 0) {
        puVar7 = (undefined4 *)FUN_021a3690(DAT_0219049c);
        if (puVar7 == (undefined4 *)0x0) {
          FUN_02196590(param_1,DAT_0219044c);
          return 1;
        }
        *puVar7 = local_1154;
        puVar7[1] = uVar3;
        func_0x0213a2d0(puVar7 + 2,(int)&local_1160 + DAT_02190468);
        local_1160 = 0;
        local_115c = 0;
        iVar1 = FUN_02190ed4(param_1,local_113c,local_1138,puVar7);
        if (iVar1 != 0) {
          return iVar1;
        }
      }
    }
    else if (iVar1 == 0x66) {
      iVar1 = FUN_021967b4(param_2,DAT_02190538,auStack_1114,DAT_0219053c);
      if (iVar1 == 0) {
        FUN_021965a0(param_1,1,DAT_02190540);
        FUN_02190f4c(param_1,3,1);
        return 3;
      }
      FUN_0218fb3c(param_1,local_1154,0x67,DAT_02190544);
    }
  }
  return 0;
}

