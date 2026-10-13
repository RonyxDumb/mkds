/* Decompiled C draft; module arm9_ov000; ROM address 021a836c. No matching claim. */
#include "types.h"
#include "deps/021a836c_FUN_021a836c.h"

undefined4 FUN_021a836c(int param_1)

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
  if (((*(ushort *)(param_1 + 0x70) & 4) == 0) || ((*(ushort *)(param_1 + 0x70) & 8) != 0)) {
    return 0xffffffc8;
  }
  *(ushort *)(param_1 + 0x70) = *(ushort *)(param_1 + 0x70) | 8;
  iVar2 = *(int *)(param_1 + 0x68);
  if ((iVar2 != 0) && (*(int *)(iVar2 + DAT_021a841c) != 0)) {
    iVar3 = FUN_021a7064(DAT_021a8420,*(int *)(iVar2 + DAT_021a841c),(int)*(char *)(param_1 + 0x72))
    ;
    if (iVar3 == 0) {
      return 0xffffffdf;
    }
    uVar4 = FUN_021a6fa8(*(undefined4 *)(iVar2 + DAT_021a841c));
    return uVar4;
  }
  return 0;
}

