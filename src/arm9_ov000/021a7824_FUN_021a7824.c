/* Decompiled C draft; module arm9_ov000; ROM address 021a7824. No matching claim. */
#include "types.h"
#include "deps/021a7824_FUN_021a7824.h"

undefined4 FUN_021a7824(int param_1,undefined2 param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  
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
  if ((*(ushort *)(param_1 + 0x70) & 2) != 0) {
    return 0xfffffff9;
  }
  *(undefined2 *)(param_1 + 0x74) = param_2;
  if (*(char *)(param_1 + 0x73) == '\x01') {
    uVar3 = FUN_021a76f4(param_1);
    return uVar3;
  }
  return 0;
}

