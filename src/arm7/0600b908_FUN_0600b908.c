/* Decompiled C draft; module arm7; ROM address 0600b908. No matching claim. */
#include "types.h"
#include "deps/0600b908_FUN_0600b908.h"

undefined4 FUN_0600b908(uint param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  if (param_1 < 10) {
    uVar2 = 5;
  }
  else {
    *(short *)((*(uint *)(DAT_0600b9c0 & 0xfffffffc) >> (DAT_0600b9c0 & 3) * 8 |
               *(uint *)(DAT_0600b9c0 & 0xfffffffc) << (DAT_0600b9c0 & 3) * -8 + 0x20) + 0x33c) =
         (short)param_1;
    if (param_2 != 0) {
      *DAT_0600b9c4 = (short)param_1;
    }
    uVar4 = *(uint *)(DAT_0600b9c0 & 0xfffffffc) >> (DAT_0600b9c0 & 3) * 8 |
            *(uint *)(DAT_0600b9c0 & 0xfffffffc) << (DAT_0600b9c0 & 3) * -8 + 0x20;
    if (*(short *)(uVar4 + 0x4a4) != 0) {
      uVar1 = uVar4 + 0x4ac & 3;
      uVar3 = *(uint *)(uVar4 + 0x4ac & 0xfffffffc);
      iVar5 = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x24 +
              (uint)*(ushort *)(uVar4 + 0x3da);
      if (*(short *)(uVar4 + 0x352) == 1) {
        FUN_060096e4((ushort *)(uintptr_t)(iVar5 + 6),param_1 & 0xff);
        FUN_060096e4((ushort *)(uintptr_t)(iVar5 + 7),(int)param_1 >> 8 & 0xff);
      }
      else {
        FUN_060096e4((ushort *)(uintptr_t)(iVar5 + 6),0xff);
        FUN_060096e4((ushort *)(uintptr_t)(iVar5 + 7),0xff);
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}

