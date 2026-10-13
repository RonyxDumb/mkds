/* Decompiled C draft; module arm9_ov000; ROM address 021a7468. No matching claim. */
#include "types.h"
#include "deps/021a7468_FUN_021a7468.h"

undefined4 FUN_021a7468(int param_1,undefined4 param_2,undefined4 param_3)

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
    return 0xffffffe4;
  }
  bVar1 = true;
  if ((*(char *)(param_1 + 0x73) != '\0') && (*(char *)(param_1 + 0x73) != '\x04')) {
    bVar1 = false;
  }
  if (!bVar1) {
    return 0xffffffe4;
  }
  if (*(char *)(param_1 + 0x72) != '\x01') {
    return 0xfffffffa;
  }
  if (*(short *)(param_1 + 0x74) == 0) {
    return 0xffffffe4;
  }
  iVar2 = FUN_021a7064(DAT_021a7530,param_1);
  *(undefined2 *)(iVar2 + 0x10) = *(undefined2 *)(param_1 + 0x74);
  *(undefined4 *)(iVar2 + 0x14) = param_2;
  *(undefined4 *)(iVar2 + 0x18) = param_3;
  *(ushort *)(param_1 + 0x70) = *(ushort *)(param_1 + 0x70) | 2;
  uVar3 = FUN_021a6fb4(param_1);
  return uVar3;
}

