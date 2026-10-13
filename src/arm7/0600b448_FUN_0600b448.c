/* Decompiled C draft; module arm7; ROM address 0600b448. No matching claim. */
#include "types.h"
#include "deps/0600b448_FUN_0600b448.h"

undefined4 FUN_0600b448(uint param_1,int param_2)

{
  uint uVar1;
  ushort uVar2;
  bool bVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar5 = *(uint *)(DAT_0600b560 & 0xfffffffc) >> (DAT_0600b560 & 3) * 8 |
          *(uint *)(DAT_0600b560 & 0xfffffffc) << (DAT_0600b560 & 3) * -8 + 0x20;
  bVar3 = false;
  if (param_1 < 0x21) {
    if ((*(short *)(uVar5 + 0x34c) == 0x40) && (*(short *)(uVar5 + 0x32e) == 1)) {
      if (*(ushort *)(uVar5 + 0x362) != param_1) {
        return 6;
      }
      if (*(short *)(uVar5 + 0x3d6) != 0) {
        bVar3 = true;
      }
    }
    for (uVar6 = 0; uVar6 < param_1; uVar6 = uVar6 + 1) {
      uVar4 = FUN_060096c4((ushort *)(uintptr_t)(param_2));
      FUN_060096e4((ushort *)(uintptr_t)(uVar5 + 0x364 + uVar6),uVar4);
      param_2 = param_2 + 1;
    }
    for (; uVar6 < 0x20; uVar6 = uVar6 + 1) {
      FUN_060096e4((ushort *)(uintptr_t)(uVar5 + 0x364 + uVar6),0);
    }
    *(short *)(uVar5 + 0x362) = (short)param_1;
    if (bVar3) {
      uVar6 = (*(uint *)(DAT_0600b560 & 0xfffffffc) >> (DAT_0600b560 & 3) * 8 |
              *(uint *)(DAT_0600b560 & 0xfffffffc) << (DAT_0600b560 & 3) * -8 + 0x20) + 0x4ac;
      uVar1 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      uVar2 = *(ushort *)(uVar5 + 0x3d6);
      for (uVar7 = 0; uVar7 < param_1; uVar7 = uVar7 + 1) {
        uVar4 = FUN_060096c4((ushort *)(uintptr_t)(uVar5 + 0x364 + uVar7));
        FUN_060096e4((ushort *)(uintptr_t)((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) + 0x26 + (uint)uVar2 + uVar7),
                     uVar4);
      }
    }
    uVar4 = 0;
  }
  else {
    uVar4 = 5;
  }
  return uVar4;
}

