/* Decompiled C draft; module arm9_ov000; ROM address 021a6974. No matching claim. */
#include "types.h"
#include "deps/021a6974_FUN_021a6974.h"

uint FUN_021a6974(undefined4 param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = func_0x0200fca0();
  iVar2 = FUN_021a5b30();
  if (iVar2 == 0) {
    func_0x0200fcb4(uVar1);
    return 0xffffffff;
  }
  func_0x0200ed34(DAT_021a6a84);
  iVar2 = FUN_021a5b30();
  if (iVar2 == 0) {
    func_0x0200ecc4(DAT_021a6a84);
    func_0x0200fcb4(uVar1);
    return 0xffffffff;
  }
  if ((*(int *)(iVar2 + DAT_021a6a88) == 9) && (*(char *)(iVar2 + DAT_021a6a8c) != '\x01')) {
    func_0x0214d1fc(param_2,iVar2 + DAT_021a6a90,param_3);
    uVar3 = func_0x02144438(DAT_021a6a94,param_1,iVar2 + DAT_021a6a90,param_3 & 0xffff);
    switch(uVar3) {
    default:
      func_0x0200ecc4(DAT_021a6a84);
      func_0x0200fcb4(uVar1);
      return 0xfffffffb;
    case 2:
      goto switchD_021a6a1a_caseD_2;
    }
  }
  func_0x0200ecc4(DAT_021a6a84);
  func_0x0200fcb4(uVar1);
  return 0xfffffffc;
switchD_021a6a1a_caseD_2:
  func_0x0200e01c(DAT_021a6a98);
  if (*(int *)(DAT_021a6a9c + 0x24) != 0) {
    func_0x0200ecc4(DAT_021a6a84);
    func_0x0200fcb4(uVar1);
    return 0xfffffffb;
  }
  func_0x0200ecc4(DAT_021a6a84);
  func_0x0200fcb4(uVar1);
  return param_3;
}

