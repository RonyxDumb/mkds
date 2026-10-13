/* Decompiled C draft; module arm7; ROM address 06013290. No matching claim. */
#include "types.h"
#include "deps/06013290_FUN_06013290.h"

int FUN_06013290(int param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar3 = *(uint *)(DAT_060133ac & 0xfffffffc) >> (DAT_060133ac & 3) * 8 |
          *(uint *)(DAT_060133ac & 0xfffffffc) << (DAT_060133ac & 3) * -8 + 0x20;
  FUN_060096e4((ushort *)(uintptr_t)(param_1),0xdd);
  FUN_060096e4((ushort *)(uintptr_t)(param_1 + 1),
               *(short *)((*(uint *)(DAT_060133ac & 0xfffffffc) >> (DAT_060133ac & 3) * 8 |
                          *(uint *)(DAT_060133ac & 0xfffffffc) << (DAT_060133ac & 3) * -8 + 0x20) +
                         0x3e4) + 8U & 0xff);
  FUN_060096e4((ushort *)(uintptr_t)(param_1 + 2),0);
  FUN_060096e4((ushort *)(uintptr_t)(param_1 + 3),9);
  FUN_060096e4((ushort *)(uintptr_t)(param_1 + 4),0xbf);
  FUN_060096e4((ushort *)(uintptr_t)(param_1 + 5),0);
  FUN_060096e4((ushort *)(uintptr_t)(param_1 + 6),*(ushort *)(uVar3 + 0x33c) & 0xff);
  FUN_060096e4((ushort *)(uintptr_t)(param_1 + 7),(int)(uint)*(ushort *)(uVar3 + 0x33c) >> 8);
  uVar1 = *DAT_060133b0;
  FUN_060096e4((ushort *)(uintptr_t)(param_1 + 8),uVar1 & 0xff);
  FUN_060096e4((ushort *)(uintptr_t)(param_1 + 9),uVar1 >> 8);
  iVar4 = 10;
  if (*(short *)(uVar3 + 0x3e4) != 0) {
    uVar6 = uVar3 + 0x3e0 & 3;
    uVar5 = *(uint *)(uVar3 + 0x3e0 & 0xfffffffc);
    uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    if ((*(ushort *)(uVar3 + 0x3e6) & 1) != 0) {
      uVar6 = uVar6 + 1;
    }
    for (uVar5 = 0; uVar5 < *(ushort *)(uVar3 + 0x3e4); uVar5 = uVar5 + 1) {
      uVar2 = FUN_060096c4((ushort *)(uintptr_t)(uVar6));
      FUN_060096e4((ushort *)(uintptr_t)(param_1 + iVar4),uVar2);
      iVar4 = iVar4 + 1;
      uVar6 = uVar6 + 1;
    }
  }
  return iVar4;
}

