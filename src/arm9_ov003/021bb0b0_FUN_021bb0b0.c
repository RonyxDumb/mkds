/* Decompiled C draft; module arm9_ov003; ROM address 021bb0b0. No matching claim. */
#include "types.h"
#include "deps/021bb0b0_FUN_021bb0b0.h"

undefined4 FUN_021bb0b0(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  piVar1 = DAT_021bb14c;
  if (*DAT_021bb148 != 0) {
    iVar4 = *DAT_021bb14c;
    *DAT_021bb150 = 1;
    while ((0 < *piVar1 && (*piVar1 < 6))) {
      func_0x0200dc3c(100);
    }
    func_0x0200dc3c(DAT_021bb154);
    iVar2 = func_0x0200e070(DAT_021bb158);
    uVar3 = DAT_021bb158;
    while (iVar2 == 0) {
      func_0x0200df68(uVar3);
      func_0x0200e084(uVar3);
      iVar2 = func_0x0200e070(uVar3);
    }
    if (*DAT_021bb15c != 0) {
      (*(code *)*DAT_021bb160)();
      *DAT_021bb15c = 0;
    }
    *DAT_021bb148 = 0;
    if (iVar4 != *DAT_021bb14c) {
      FUN_021bb03c();
    }
  }
  if (0 < *DAT_021bb164) {
    uVar3 = FUN_021be3b8();
    *DAT_021bb164 = 0;
    return uVar3;
  }
  return 0xfffffff6;
}

