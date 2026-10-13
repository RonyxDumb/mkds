/* Decompiled C draft; module arm9_ov000; ROM address 0219db18. No matching claim. */
#include "types.h"
#include "deps/0219db18_FUN_0219db18.h"

void FUN_0219db18(int param_1,undefined4 param_2,int param_3,char *param_4)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  undefined1 auStack_20 [12];
  
  if (((*(int *)(*DAT_0219dd10 + DAT_0219dd14) == 6) ||
      (*(int *)(*DAT_0219dd10 + DAT_0219dd14) == 0xb)) && (param_4 != (char *)0x0)) {
    if (param_1 == 0) {
      param_4[8] = '\0';
      piVar2 = DAT_0219dd10;
      param_4[9] = '\0';
      param_4[10] = '\0';
      param_4[0xb] = '\0';
      *(char *)(*DAT_0219dd10 + 0x14) = *(char *)(*DAT_0219dd10 + 0x14) + '\x01';
      iVar4 = *piVar2;
      uVar1 = (uint)*(byte *)(iVar4 + 0x14);
      if (*param_4 == '\0') {
        if (param_3 != 0) {
          *(undefined4 *)(iVar4 + (uVar1 - 1) * 4 + DAT_0219dd18) = *(undefined4 *)(param_3 + 4);
          *(ushort *)(*piVar2 + (uVar1 - 1) * 2 + DAT_0219dd20) =
               *(ushort *)(param_3 + 2) >> 8 | *(ushort *)(param_3 + 2) << 8 & (ushort)DAT_0219dd1c;
        }
        iVar4 = *DAT_0219dd10;
        uVar6 = FUN_021a350c();
        *(int *)(iVar4 + DAT_0219dd40) = (int)uVar6;
        *(int *)(iVar4 + DAT_0219dd44) = (int)((ulonglong)uVar6 >> 0x20);
        *(undefined4 *)(iVar4 + DAT_0219dd14) = 7;
        return;
      }
      *(undefined4 *)(iVar4 + uVar1 * 4 + DAT_0219dd18) = *(undefined4 *)(param_3 + 4);
      *(ushort *)(*piVar2 + uVar1 * 2 + DAT_0219dd20) =
           *(ushort *)(param_3 + 2) >> 8 | *(ushort *)(param_3 + 2) << 8 & (ushort)DAT_0219dd1c;
      *(undefined1 *)(*piVar2 + DAT_0219dd24) = 0;
      *(undefined4 *)(*piVar2 + DAT_0219dd28) = 0;
      iVar4 = *piVar2;
      *(undefined4 *)(iVar4 + DAT_0219dd2c) = 0;
      *(undefined4 *)(iVar4 + DAT_0219dd30) = 0;
      piVar2 = (int *)(iVar4 + DAT_0219dd14);
      if (*piVar2 == 0xb) {
        *piVar2 = 0xc;
      }
      else {
        *piVar2 = 7;
      }
      piVar2 = DAT_0219dd10;
      *(undefined1 *)(*DAT_0219dd10 + 0xc) = 0;
      func_0x0200d9e0(auStack_20,0xc,DAT_0219dd34,*(undefined4 *)(*piVar2 + DAT_0219dd38));
      iVar4 = *DAT_0219dd10;
      uVar3 = FUN_0219a760(*(undefined4 *)(iVar4 + uVar1 * 4 + DAT_0219dd18),
                           *(undefined2 *)(iVar4 + uVar1 * 2 + DAT_0219dd20),0);
      FUN_02198968(**(undefined4 **)(*DAT_0219dd10 + 4),0,uVar3,auStack_20,0xffffffff,DAT_0219dd3c,
                   *(undefined4 *)(iVar4 + 8),0);
      FUN_0219e3e4();
      return;
    }
    if ((*(int *)(param_4 + 8) != 0) && ((iVar4 = FUN_0219e45c(), iVar4 == 2 || (iVar4 == 1)))) {
      if (*param_4 == '\0') {
        if ((iVar4 != 1) && ((iVar4 != 2 || (param_4[1] == '\0')))) {
          param_4[1] = param_4[1] + '\x01';
          FUN_021a0c30(param_4);
          FUN_0219e4a0();
          return;
        }
        param_4[8] = '\0';
        param_4[9] = '\0';
        param_4[10] = '\0';
        param_4[0xb] = '\0';
        iVar4 = FUN_0219dabc();
        if (iVar4 != 0) {
          FUN_0219f938(*(undefined4 *)
                        (*DAT_0219dd10 + (uint)*(byte *)(*DAT_0219dd10 + 0xd) * 4 + 0xf4));
          return;
        }
      }
      else {
        iVar5 = *DAT_0219dd10;
        uVar6 = FUN_021a350c();
        *(int *)(iVar5 + DAT_0219dd2c) = (int)uVar6;
        *(int *)(iVar5 + DAT_0219dd30) = (int)((ulonglong)uVar6 >> 0x20);
        if ((iVar4 == 1) || ((iVar4 == 2 && (*(char *)(iVar5 + DAT_0219dd24) != '\0')))) {
          param_4[8] = '\0';
          param_4[9] = '\0';
          param_4[10] = '\0';
          param_4[0xb] = '\0';
          iVar4 = FUN_0219dabc();
          piVar2 = DAT_0219dd10;
          if (iVar4 != 0) {
            *(undefined1 *)(*DAT_0219dd10 + DAT_0219dd24) = 0;
            *(undefined4 *)(*piVar2 + DAT_0219dd28) = 0;
            iVar4 = *piVar2;
            *(undefined4 *)(iVar4 + DAT_0219dd2c) = 0;
            *(undefined4 *)(iVar4 + DAT_0219dd30) = 0;
            FUN_0219f9bc(*(undefined4 *)(iVar4 + (*(byte *)(iVar4 + 0xd) + 1) * 4 + 0xf4));
          }
        }
      }
    }
  }
  return;
}

