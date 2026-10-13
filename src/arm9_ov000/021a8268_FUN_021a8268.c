/* Decompiled C draft; module arm9_ov000; ROM address 021a8268. No matching claim. */
#include "types.h"
#include "deps/021a8268_FUN_021a8268.h"

undefined4
FUN_021a8268(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,uint param_6)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = FUN_021a8a80();
  if (iVar2 != 0) {
    return 0xffffffe4;
  }
  bVar1 = false;
  if ((param_1 != 0) && ((*(ushort *)(param_1 + 0x70) & 1) != 0)) {
    bVar1 = true;
  }
  if (!bVar1) {
    return 0xffffffd9;
  }
  bVar1 = true;
  if ((*(char *)(param_1 + 0x73) != '\0') && (*(char *)(param_1 + 0x73) != '\x04')) {
    bVar1 = false;
  }
  if ((bVar1) &&
     (((*(ushort *)(param_1 + 0x70) & 4) == 0 || ((*(ushort *)(param_1 + 0x70) & 8) != 0)))) {
    return 0xffffffc8;
  }
  iVar2 = *(int *)(param_1 + 0x68);
  if (((param_6 & 4) == 0) && (*(char *)(param_1 + 0x72) != '\0')) {
    func_0x0200ed34(iVar2 + 0xe0);
    uVar4 = 1;
  }
  else {
    iVar3 = func_0x0200ec08(iVar2 + 0xe0);
    if (iVar3 == 0) {
      return 0xfffffffa;
    }
    uVar4 = 0;
  }
  uVar4 = FUN_021a81a8(param_1,param_2,param_3,param_4,param_5,uVar4);
  func_0x0200ecc4(iVar2 + 0xe0);
  return uVar4;
}

