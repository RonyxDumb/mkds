/* Decompiled C draft; module arm9_ov000; ROM address 021a7534. No matching claim. */
#include "types.h"
#include "deps/021a7534_FUN_021a7534.h"

int FUN_021a7534(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  iVar1 = FUN_021a8a80();
  if (iVar1 != 0) {
    return -0x1c;
  }
  bVar3 = false;
  if ((param_1 != 0) && ((*(ushort *)(param_1 + 0x70) & 1) != 0)) {
    bVar3 = true;
  }
  if (!bVar3) {
    return -0x27;
  }
  if ((*(ushort *)(param_1 + 0x70) & 2) != 0) {
    return -0x1c;
  }
  bVar3 = true;
  if ((*(char *)(param_1 + 0x73) != '\0') && (*(char *)(param_1 + 0x73) != '\x04')) {
    bVar3 = false;
  }
  if (!bVar3) {
    return -0x1c;
  }
  if (*(char *)(param_1 + 0x72) != '\x01') {
    return -6;
  }
  iVar2 = FUN_021a73d8(DAT_021a75f4);
  iVar1 = iVar2;
  if (((-1 < iVar2) && (iVar1 = FUN_021a7824(iVar2,*(undefined2 *)(param_1 + 0x74)), -1 < iVar1)) &&
     (iVar1 = FUN_021a7468(iVar2,param_2,param_3), -1 < iVar1)) {
    iVar1 = iVar2;
  }
  return iVar1;
}

