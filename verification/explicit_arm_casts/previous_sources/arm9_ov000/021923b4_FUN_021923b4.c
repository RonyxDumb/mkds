/* Decompiled C draft; module arm9_ov000; ROM address 021923b4. No matching claim. */
#include "types.h"
#include "deps/021923b4_FUN_021923b4.h"

int FUN_021923b4(int *param_1,int param_2,char *param_3)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  undefined1 local_110;
  undefined1 local_10f;
  
  iVar3 = *param_1;
  if (param_3 == (char *)0x0) {
    FUN_02196590(param_1,DAT_02192754);
    return 2;
  }
  switch(param_2 - DAT_02192758) {
  case 0:
    if (*param_3 == '\0') {
      FUN_02196590(param_1,DAT_02192754);
      return 2;
    }
    FUN_02196914(&local_110,param_3,0x1f);
    FUN_02196914(iVar3 + DAT_0219275c,&local_110,0x1f);
    iVar3 = FUN_02192d30(param_1,DAT_02192760,&local_110);
    if (iVar3 != 0) {
      return iVar3;
    }
    break;
  case 1:
    if (*param_3 == '\0') {
      FUN_02196590(param_1,DAT_02192754);
      return 2;
    }
    FUN_02196914(&local_110,param_3,0x15);
    FUN_02196914(iVar3 + DAT_02192764,&local_110,0x15);
    iVar3 = FUN_02192d30(param_1,DAT_02192768,&local_110);
    if (iVar3 != 0) {
      return iVar3;
    }
    break;
  case 2:
    if (*param_3 == '\0') {
      FUN_02196590(param_1,DAT_02192754);
      return 2;
    }
    FUN_02196914(&local_110,param_3,0x33);
    FUN_0218e850(&local_110);
    FUN_02196914(iVar3 + DAT_0219276c,&local_110,0x33);
    iVar3 = FUN_02192cfc(param_1,DAT_02192770,&local_110);
    if (iVar3 != 0) {
      return iVar3;
    }
    break;
  case 3:
    if (*param_3 == '\0') {
      FUN_02196590(param_1,DAT_02192754);
      return 2;
    }
    FUN_02196914(&local_110,param_3,0x1f);
    FUN_02196914(iVar3 + DAT_02192774,&local_110,0x1f);
    iVar3 = FUN_02192cfc(param_1,DAT_02192778,&local_110);
    if (iVar3 != 0) {
      return iVar3;
    }
    break;
  case 4:
    FUN_02196914(&local_110,param_3,0x1f);
    iVar3 = FUN_02192d30(param_1,DAT_0219277c,&local_110);
    if (iVar3 != 0) {
      return iVar3;
    }
    break;
  case 5:
    FUN_02196914(&local_110,param_3,0x1f);
    iVar3 = FUN_02192d30(param_1,DAT_02192780,&local_110);
    if (iVar3 != 0) {
      return iVar3;
    }
    break;
  case 6:
    FUN_02196914(&local_110,param_3,DAT_021927a8);
    iVar3 = FUN_02192d30(param_1,DAT_021927ac,&local_110);
    if (iVar3 != 0) {
      return iVar3;
    }
    break;
  case 7:
    FUN_02196914(&local_110,param_3,0x4c);
    iVar3 = FUN_02192d30(param_1,DAT_02192784,&local_110);
    if (iVar3 != 0) {
      return iVar3;
    }
    break;
  case 8:
    FUN_02196914(&local_110,param_3,0xb);
    iVar3 = FUN_02192d30(param_1,DAT_02192788,&local_110);
    if (iVar3 != 0) {
      return iVar3;
    }
    break;
  case 9:
    iVar3 = func_0x0213a434(param_3);
    if (iVar3 != 2) {
      FUN_02196590(param_1,DAT_0219278c);
      return 2;
    }
    FUN_02196914(&local_110,param_3,3);
    iVar3 = FUN_02192d30(param_1,DAT_02192790,&local_110);
    if (iVar3 != 0) {
      return iVar3;
    }
    break;
  default:
    FUN_02196590(param_1,DAT_02192968);
    return 2;
  case 0xb:
    cVar2 = *param_3;
    iVar3 = (int)cVar2;
    if ((-1 < iVar3) && (iVar3 < 0x80)) {
      cVar2 = *(char *)(DAT_02192794 + iVar3);
    }
    if (cVar2 == 'M') {
      local_110 = *DAT_02192798;
      local_10f = DAT_02192798[1];
    }
    else if (cVar2 == 'F') {
      local_110 = *DAT_0219279c;
      local_10f = DAT_0219279c[1];
    }
    else {
      local_110 = *DAT_021927a0;
      local_10f = DAT_021927a0[1];
    }
    iVar3 = FUN_02192d30(param_1,DAT_021927a4,&local_110);
    if (iVar3 != 0) {
      return iVar3;
    }
    break;
  case 0xd:
    uVar1 = func_0x0213bf90(param_3);
    iVar3 = FUN_0219296c(param_1,DAT_021927b0,uVar1);
    if (iVar3 != 0) {
      return iVar3;
    }
    break;
  case 0xe:
    uVar1 = func_0x0213bf90(param_3);
    iVar3 = FUN_0219296c(param_1,DAT_021927b4,uVar1);
    if (iVar3 != 0) {
      return iVar3;
    }
    break;
  case 0xf:
    FUN_02196914(&local_110,param_3,DAT_021927a8);
    iVar3 = FUN_02192d30(param_1,DAT_021927b8,&local_110);
    if (iVar3 != 0) {
      return iVar3;
    }
    break;
  case 0x10:
    uVar1 = func_0x0213bf90(param_3);
    iVar3 = FUN_0219296c(param_1,DAT_021927bc,uVar1);
    if (iVar3 != 0) {
      return iVar3;
    }
    break;
  case 0x11:
    FUN_02196914(&local_110,param_3,DAT_021927a8);
    iVar3 = FUN_02192d30(param_1,DAT_021927c0,&local_110);
    if (iVar3 != 0) {
      return iVar3;
    }
    break;
  case 0x12:
    uVar1 = func_0x0213bf90(param_3);
    iVar3 = FUN_0219296c(param_1,DAT_021927c4,uVar1);
    if (iVar3 != 0) {
      return iVar3;
    }
    break;
  case 0x14:
    uVar1 = func_0x0213bf90(param_3);
    iVar3 = FUN_0219296c(param_1,DAT_021927c8,uVar1);
    if (iVar3 != 0) {
      return iVar3;
    }
    break;
  case 0x15:
    uVar1 = func_0x0213bf90(param_3);
    iVar3 = FUN_0219296c(param_1,DAT_0219293c,uVar1);
    if (iVar3 != 0) {
      return iVar3;
    }
    break;
  case 0x16:
    FUN_02196914(&local_110,param_3,DAT_02192940);
    iVar3 = FUN_02192d30(param_1,DAT_02192944,&local_110);
    if (iVar3 != 0) {
      return iVar3;
    }
    break;
  case 0x17:
    FUN_02196914(&local_110,param_3,0x33);
    iVar3 = FUN_02192d30(param_1,DAT_02192948,&local_110);
    if (iVar3 != 0) {
      return iVar3;
    }
    break;
  case 0x18:
    FUN_02196914(&local_110,param_3,DAT_02192940);
    iVar3 = FUN_02192d30(param_1,DAT_0219294c,&local_110);
    if (iVar3 != 0) {
      return iVar3;
    }
    break;
  case 0x19:
    FUN_02196914(&local_110,param_3,DAT_02192940);
    iVar3 = FUN_02192d30(param_1,DAT_02192950,&local_110);
    if (iVar3 != 0) {
      return iVar3;
    }
    break;
  case 0x1a:
    FUN_02196914(&local_110,param_3,DAT_02192940);
    iVar3 = FUN_02192d30(param_1,DAT_02192954,&local_110);
    if (iVar3 != 0) {
      return iVar3;
    }
    break;
  case 0x1b:
    FUN_02196914(&local_110,param_3,DAT_02192940);
    iVar3 = FUN_02192d30(param_1,DAT_02192958,&local_110);
    if (iVar3 != 0) {
      return iVar3;
    }
    break;
  case 0x1c:
    FUN_02196914(&local_110,param_3,DAT_02192940);
    iVar3 = FUN_02192d30(param_1,DAT_0219295c,&local_110);
    if (iVar3 != 0) {
      return iVar3;
    }
    break;
  case 0x1d:
    FUN_02196914(&local_110,param_3,DAT_02192940);
    iVar3 = FUN_02192d30(param_1,DAT_02192960,&local_110);
    if (iVar3 != 0) {
      return iVar3;
    }
    break;
  case 0x1e:
    FUN_02196914(&local_110,param_3,DAT_02192940);
    iVar3 = FUN_02192d30(param_1,DAT_02192964,&local_110);
    if (iVar3 != 0) {
      return iVar3;
    }
  }
  return 0;
}

