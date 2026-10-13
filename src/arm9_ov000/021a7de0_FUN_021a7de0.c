/* Decompiled C draft; module arm9_ov000; ROM address 021a7de0. No matching claim. */
#include "types.h"
#include "deps/021a7de0_FUN_021a7de0.h"

undefined4
FUN_021a7de0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,uint param_6)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  int iVar5;
  
  iVar1 = FUN_021a8a80();
  if (iVar1 != 0) {
    return 0xffffffe4;
  }
  if (((param_6 & 4) == 0) && (*(char *)(param_1 + 0x72) != '\0')) {
    iVar1 = func_0x0200fcf8();
    if (iVar1 == 0x12) {
      return 0xffffffe4;
    }
    iVar1 = 1;
  }
  else {
    if (*(char *)(param_1 + 0x73) == '\x04') {
      return 0xffffffe4;
    }
    iVar1 = 0;
  }
  bVar4 = false;
  if ((param_1 != 0) && ((*(ushort *)(param_1 + 0x70) & 1) != 0)) {
    bVar4 = true;
  }
  if (!bVar4) {
    return 0xffffffd9;
  }
  bVar4 = true;
  if ((*(char *)(param_1 + 0x73) != '\0') && (*(char *)(param_1 + 0x73) != '\x04')) {
    bVar4 = false;
  }
  if ((bVar4) &&
     (((*(ushort *)(param_1 + 0x70) & 4) == 0 || ((*(ushort *)(param_1 + 0x70) & 8) != 0)))) {
    return 0xffffffc8;
  }
  iVar5 = *(int *)(param_1 + 100);
  if (iVar1 == 0) {
    iVar2 = func_0x0200ec08(iVar5 + 0xe0);
    if (iVar2 == 0) {
      return 0xfffffffa;
    }
  }
  else {
    func_0x0200ed34(iVar5 + 0xe0);
  }
  uVar3 = FUN_021a7d68(param_1,param_2,param_3,param_4,param_5,iVar1,param_6);
  func_0x0200ecc4(iVar5 + 0xe0);
  return uVar3;
}

