/* Decompiled C draft; module arm9_ov000; ROM address 021a8604. No matching claim. */
#include "types.h"
#include "deps/021a8604_FUN_021a8604.h"

undefined4 FUN_021a8604(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1 < 1) {
    return 0xffffffe4;
  }
  iVar2 = FUN_021a8a5c();
  if (iVar2 != 0) {
    return 0xffffffe6;
  }
  iVar2 = FUN_021a8a80(param_1);
  if (iVar2 != 0) {
    return 0;
  }
  bVar1 = false;
  if ((param_1 != 0) && ((*(ushort *)(param_1 + 0x70) & 1) != 0)) {
    bVar1 = true;
  }
  if (!bVar1) {
    return 0xffffffd9;
  }
  if ((*(ushort *)(param_1 + 0x70) & 0x10) != 0) {
    return 0xffffffe6;
  }
  *(ushort *)(param_1 + 0x70) = *(ushort *)(param_1 + 0x70) | 0x18;
  bVar1 = true;
  if ((*(char *)(param_1 + 0x73) != '\0') && (*(char *)(param_1 + 0x73) != '\x04')) {
    bVar1 = false;
  }
  if (bVar1) {
    FUN_021a7008(*(undefined4 *)(param_1 + 0x68),0);
  }
  iVar2 = FUN_021a7064(DAT_021a86b8,param_1,1);
  *(undefined1 *)(iVar2 + 0xd) = 0;
  uVar3 = FUN_021a6f84(param_1);
  return uVar3;
}

