/* Decompiled C draft; module arm9_ov000; ROM address 0219e138. No matching claim. */
#include "types.h"
#include "deps/0219e138_FUN_0219e138.h"

void FUN_0219e138(undefined4 param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  
  if (param_2 == 0) {
    FUN_0219e134(param_3);
    return;
  }
  if (param_2 != 4) {
    return;
  }
  iVar6 = 0;
  iVar2 = FUN_0218b474();
  if (0 < iVar2) {
    do {
      uVar3 = FUN_0218b480(param_1,iVar6);
      iVar2 = FUN_0219e994();
      if (iVar2 == 0) {
        FUN_0218b4d4(param_1,uVar3);
        iVar6 = iVar6 + -1;
      }
      iVar6 = iVar6 + 1;
      iVar2 = FUN_0218b474(param_1);
    } while (iVar6 < iVar2);
  }
  iVar2 = *(int *)(*DAT_0219e3cc + DAT_0219e3d0);
  if (iVar2 == 2) {
    iVar6 = 0;
    iVar2 = FUN_0218b474(param_1);
    if (0 < iVar2) {
      do {
        uVar3 = FUN_0218b480(param_1,iVar6);
        iVar2 = *DAT_0219e3cc;
        if ((((*(int *)(iVar2 + 0x1c) != 0) &&
             (iVar4 = FUN_0218b27c(), *(int *)(iVar2 + 0x1c) == iVar4)) &&
            (*(short *)(iVar2 + 0x1a) != 0)) &&
           (uVar5 = FUN_0218b260(uVar3), *(ushort *)(*DAT_0219e3cc + 0x1a) == uVar5)) break;
        iVar6 = iVar6 + 1;
        iVar2 = FUN_0218b474(param_1);
      } while (iVar6 < iVar2);
    }
    iVar2 = FUN_0218b474(param_1);
    piVar1 = DAT_0219e3cc;
    if (iVar2 <= iVar6) {
      *(undefined4 *)(*DAT_0219e3cc + 0xe8) = 2;
      uVar7 = func_0x0200f5ac();
      *(undefined8 *)(*DAT_0219e3cc + 0xec) = uVar7;
      return;
    }
    *(undefined4 *)(*DAT_0219e3cc + DAT_0219e3d0) = 3;
    iVar2 = DAT_0219e3d4;
    *(undefined4 *)(*piVar1 + DAT_0219e3d4) = 0;
    FUN_021a0f20(*(undefined4 *)(*piVar1 + iVar2));
    FUN_0219e594();
    return;
  }
  if (iVar2 == 3) {
    FUN_0219dfe4(1);
    iVar2 = FUN_0218b474(param_1);
    if (iVar2 == 0) {
      *(undefined4 *)(*DAT_0219e3cc + 0xe8) = 2;
      uVar7 = func_0x0200f5ac();
      *(undefined8 *)(*DAT_0219e3cc + 0xec) = uVar7;
      return;
    }
    FUN_0219fdc8(0,0);
    iVar2 = FUN_0219fee4();
    piVar1 = DAT_0219e3cc;
    if (iVar2 == 0) {
      *(undefined4 *)(*DAT_0219e3cc + DAT_0219e3d0) = 4;
      *(undefined4 *)(*piVar1 + 0xe8) = 0;
      return;
    }
  }
  else {
    if (iVar2 != 5) {
      return;
    }
    iVar6 = FUN_0218b474(param_1);
    iVar2 = DAT_0219e3d8;
    piVar1 = DAT_0219e3cc;
    while (iVar6 != 0) {
      uVar3 = FUN_0218b480(param_1,0);
      iVar6 = FUN_0218b27c();
      if ((*(int *)(*piVar1 + iVar2) == iVar6) &&
         (uVar5 = FUN_0218b260(uVar3), *(ushort *)(*piVar1 + DAT_0219e3dc) == uVar5)) break;
      FUN_0218b4d4(param_1,uVar3);
      iVar6 = FUN_0218b474(param_1);
    }
    iVar2 = FUN_0218b474(param_1);
    if (iVar2 != 0) {
      uVar3 = FUN_0218b480(param_1,0);
      iVar2 = FUN_0218b2a8(uVar3,DAT_0219e3e0,0);
      if ((*(char *)(*DAT_0219e3cc + 0x15) == '\x01') && (iVar2 == *(int *)(*DAT_0219e3cc + 0xf4)))
      {
        iVar2 = FUN_0219dfe4(0);
        if (iVar2 == 0) {
          FUN_0219fb14(*(undefined4 *)(*DAT_0219e3cc + 0xf4));
          iVar2 = FUN_0219fee4();
          if (iVar2 != 0) {
            return;
          }
          *(undefined4 *)(*DAT_0219e3cc + DAT_0219e3d0) = 4;
          FUN_0219fbec(0,0);
          FUN_0219fee4();
          return;
        }
        if (*(char *)(*DAT_0219e3cc + 0xd) != '\0') {
          FUN_0219f8b0();
          iVar2 = FUN_0219fee4();
          if (iVar2 != 0) {
            return;
          }
        }
      }
      *(undefined4 *)(*DAT_0219e3cc + DAT_0219e3d0) = 6;
      uVar3 = FUN_0218b480(param_1,0);
      FUN_021a0cac(0,0,uVar3);
      FUN_0219e4a0();
      return;
    }
    *(undefined4 *)(*DAT_0219e3cc + 0xe8) = 2;
    uVar7 = func_0x0200f5ac();
    *(undefined8 *)(*DAT_0219e3cc + 0xec) = uVar7;
  }
  return;
}

