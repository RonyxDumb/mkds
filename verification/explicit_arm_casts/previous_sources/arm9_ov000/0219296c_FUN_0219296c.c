/* Decompiled C draft; module arm9_ov000; ROM address 0219296c. No matching claim. */
#include "types.h"
#include "deps/0219296c_FUN_0219296c.h"

int FUN_0219296c(undefined4 param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_18 [16];
  
  switch(param_2 - DAT_02192c88) {
  case 0:
    func_0x02135014(auStack_18,DAT_02192c90);
    iVar2 = FUN_02192d30(param_1,DAT_02192cb8,auStack_18);
    if (iVar2 != 0) {
      return iVar2;
    }
    break;
  default:
    FUN_02196590(param_1,DAT_02192cf8);
    return 2;
  case 2:
    if (param_3 < 0) {
      FUN_02196590(param_1,DAT_02192c8c);
      return 2;
    }
    func_0x02135014(auStack_18,DAT_02192c90);
    iVar2 = FUN_02192d30(param_1,DAT_02192c94,auStack_18);
    if (iVar2 != 0) {
      return iVar2;
    }
    break;
  case 5:
    if (param_3 == DAT_02192c98) {
      iVar2 = FUN_02192d30(param_1,DAT_02192ca4,DAT_02192ca8);
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    else if (param_3 == DAT_02192c9c) {
      iVar2 = FUN_02192d30(param_1,DAT_02192ca4,DAT_02192cac);
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    else {
      if (param_3 != DAT_02192ca0) {
        FUN_02196590(param_1,DAT_02192cb4);
        return 2;
      }
      iVar2 = FUN_02192d30(param_1,DAT_02192ca4,DAT_02192cb0);
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    break;
  case 6:
    func_0x02135014(auStack_18,DAT_02192c90);
    iVar2 = FUN_02192cfc(param_1,DAT_02192cbc,auStack_18);
    if (iVar2 != 0) {
      return iVar2;
    }
    break;
  case 7:
    func_0x02135014(auStack_18,DAT_02192c90);
    iVar2 = FUN_02192cfc(param_1,DAT_02192cc0,auStack_18);
    if (iVar2 != 0) {
      return iVar2;
    }
    break;
  case 8:
    uVar1 = func_0x02133068(param_3,0x10);
    func_0x02135014(auStack_18,DAT_02192c90,uVar1);
    iVar2 = FUN_02192cfc(param_1,DAT_02192cc4,auStack_18);
    if (iVar2 != 0) {
      return iVar2;
    }
    break;
  case 10:
    uVar1 = func_0x02133068(param_3,4);
    func_0x02135014(auStack_18,DAT_02192c90,uVar1);
    iVar2 = FUN_02192cfc(param_1,DAT_02192cc8,auStack_18);
    if (iVar2 != 0) {
      return iVar2;
    }
    break;
  case 0xc:
    uVar1 = func_0x02133068(param_3,4);
    func_0x02135014(auStack_18,DAT_02192c90,uVar1);
    iVar2 = FUN_02192cfc(param_1,DAT_02192ccc,auStack_18);
    if (iVar2 != 0) {
      return iVar2;
    }
    break;
  case 0xd:
    func_0x02135014(auStack_18,DAT_02192c90);
    iVar2 = FUN_02192cfc(param_1,DAT_02192cd0,auStack_18);
    if (iVar2 != 0) {
      return iVar2;
    }
    break;
  case 0xe:
    func_0x02135014(auStack_18,DAT_02192c90);
    iVar2 = FUN_02192cfc(param_1,DAT_02192cd4,auStack_18);
    if (iVar2 != 0) {
      return iVar2;
    }
    break;
  case 0xf:
    if (param_3 != 0) {
      param_3 = 1;
    }
    func_0x02135014(auStack_18,DAT_02192c90,param_3);
    iVar2 = FUN_02192cfc(param_1,DAT_02192cd8,auStack_18);
    if (iVar2 != 0) {
      return iVar2;
    }
    break;
  case 0x12:
    func_0x02135014(auStack_18,DAT_02192c90);
    iVar2 = FUN_02192d30(param_1,DAT_02192cdc,auStack_18);
    if (iVar2 != 0) {
      return iVar2;
    }
    break;
  case 0x13:
    func_0x02135014(auStack_18,DAT_02192c90);
    iVar2 = FUN_02192d30(param_1,DAT_02192ce0,auStack_18);
    if (iVar2 != 0) {
      return iVar2;
    }
    break;
  case 0x14:
    func_0x02135014(auStack_18,DAT_02192c90);
    iVar2 = FUN_02192d30(param_1,DAT_02192ce4,auStack_18);
    if (iVar2 != 0) {
      return iVar2;
    }
    break;
  case 0x15:
    func_0x02135014(auStack_18,DAT_02192c90);
    iVar2 = FUN_02192d30(param_1,DAT_02192ce8,auStack_18);
    if (iVar2 != 0) {
      return iVar2;
    }
    break;
  case 0x16:
    func_0x02135014(auStack_18,DAT_02192c90);
    iVar2 = FUN_02192d30(param_1,DAT_02192cec,auStack_18);
    if (iVar2 != 0) {
      return iVar2;
    }
    break;
  case 0x17:
    func_0x02135014(auStack_18,DAT_02192c90);
    iVar2 = FUN_02192d30(param_1,DAT_02192cf0,auStack_18);
    if (iVar2 != 0) {
      return iVar2;
    }
    break;
  case 0x18:
    func_0x02135014(auStack_18,DAT_02192c90);
    iVar2 = FUN_02192d30(param_1,DAT_02192cf4,auStack_18);
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  return 0;
}

