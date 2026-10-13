/* Decompiled C draft; module arm9_ov000; ROM address 0219c1e4. No matching claim. */
#include "types.h"
#include "deps/0219c1e4_FUN_0219c1e4.h"

void FUN_0219c1e4(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 int param_6,int param_7,undefined4 param_8,undefined4 param_9)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  *DAT_0219c350 = param_1;
  FUN_0219c3b0();
  piVar1 = DAT_0219c350;
  *(undefined4 *)*DAT_0219c350 = 0;
  *(undefined4 *)(*piVar1 + 4) = DAT_0219c354;
  *(undefined4 *)(*piVar1 + 8) = DAT_0219c358;
  *(undefined4 *)(*piVar1 + 0xc) = DAT_0219c35c;
  *(undefined4 *)(*piVar1 + 0x10) = DAT_0219c360;
  if (param_6 == 0) {
    param_6 = DAT_0219c364;
  }
  *(int *)(*DAT_0219c350 + 0x14) = param_6;
  piVar1 = DAT_0219c350;
  if (param_7 == 0) {
    param_7 = DAT_0219c364;
  }
  *(int *)(*DAT_0219c350 + 0x18) = param_7;
  *(undefined4 *)(*piVar1 + 0x1c) = 0;
  *(int *)(*piVar1 + 0x20) = param_2;
  *(undefined4 *)(*piVar1 + 0x24) = 0;
  *(undefined4 *)(*piVar1 + 0x28) = 0;
  *(undefined1 *)(*piVar1 + 0x2c) = 0;
  *(undefined1 *)(*piVar1 + 0x2d) = 0;
  *(undefined2 *)(*piVar1 + 0x2e) = 0;
  *(undefined4 *)(*piVar1 + 0x30) = 0;
  *(int *)(*piVar1 + 0x54) = DAT_0219c368;
  *(int *)(*piVar1 + 0x58) = DAT_0219c36c;
  *(undefined4 *)(*piVar1 + 0x5c) = 0;
  *(undefined4 *)(*piVar1 + 0x60) = 0;
  *(undefined4 *)(*piVar1 + 100) = 0;
  *(undefined4 *)(*piVar1 + 0x68) = 0;
  *(undefined4 *)(*piVar1 + 0x6c) = 0;
  *(undefined4 *)(*piVar1 + 0x70) = 0;
  *(undefined4 *)(*piVar1 + 0x74) = 0;
  *(undefined4 *)(*piVar1 + 0x78) = 0;
  *(undefined4 *)(*piVar1 + 0x7c) = 0;
  *(undefined4 *)(*piVar1 + 0x80) = 0;
  FUN_0219b964();
  FUN_0219caac(*DAT_0219c350 + 0x84,param_2,*DAT_0219c350 + 0x1c,param_3,
               *(undefined4 *)(param_2 + 0x24),DAT_0219c370,0);
  iVar3 = *DAT_0219c350;
  FUN_0219d8c8(iVar3 + DAT_0219c374,iVar3 + 0x1c,iVar3 + 0x34,param_8,param_9);
  iVar3 = *DAT_0219c350;
  FUN_021a2870(iVar3 + DAT_0219c378,iVar3 + 0x1c,iVar3,iVar3 + 4,DAT_0219c368,DAT_0219c36c,param_8,
               param_9);
  FUN_021a31a4(*DAT_0219c350 + DAT_0219c37c);
  uVar2 = func_0x0213a434(param_4);
  if (uVar2 < DAT_0219c380) {
    iVar3 = func_0x0213a434(param_4);
  }
  else {
    iVar3 = 0xff;
  }
  func_0x0214d1fc(param_4,DAT_0219c368,iVar3);
  *(undefined1 *)(DAT_0219c368 + iVar3) = 0;
  uVar2 = func_0x0213a434(param_5);
  if (uVar2 < DAT_0219c380) {
    iVar3 = func_0x0213a434(param_5);
  }
  else {
    iVar3 = 0xff;
  }
  func_0x0214d1fc(param_5,DAT_0219c36c,iVar3);
  *(undefined1 *)(DAT_0219c36c + iVar3) = 0;
  return;
}

