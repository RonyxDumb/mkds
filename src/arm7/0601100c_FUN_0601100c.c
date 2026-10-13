/* Decompiled C draft; module arm7; ROM address 0601100c. No matching claim. */
#include "types.h"
#include "deps/0601100c_FUN_0601100c.h"

undefined4 FUN_0601100c(undefined4 param_1,int param_2)

{
  short sVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  if (1 < *(ushort *)(param_2 + 2)) {
    *(undefined2 *)(param_2 + 6) =
         *(undefined2 *)
          ((*(uint *)(DAT_060110ec & 0xfffffffc) >> (DAT_060110ec & 3) * 8 |
           *(uint *)(DAT_060110ec & 0xfffffffc) << (DAT_060110ec & 3) * -8 + 0x20) + 0x3e4);
  }
  uVar6 = *(uint *)(DAT_060110ec & 0xfffffffc) >> (DAT_060110ec & 3) * 8 |
          *(uint *)(DAT_060110ec & 0xfffffffc) << (DAT_060110ec & 3) * -8 + 0x20;
  uVar5 = (uint)*(ushort *)(uVar6 + 0x3e4);
  iVar4 = *(ushort *)(param_2 + 2) - 2;
  uVar3 = iVar4 * 2;
  if (uVar5 == uVar3 || (int)(uVar5 + iVar4 * -2) < 0 != SBORROW4(uVar5,uVar3)) {
    if (*(ushort *)(param_2 + 6) != 0) {
      if ((*(ushort *)(uVar6 + 0x3e6) & 1) == 0) {
        uVar3 = uVar6 + 0x3e0 & 3;
        uVar5 = *(uint *)(uVar6 + 0x3e0 & 0xfffffffc);
        thunk_FUN_037fb230(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20,param_2 + 8,
                           *(ushort *)(param_2 + 6) + 1);
      }
      else {
        uVar3 = uVar6 + 0x3e0 & 3;
        uVar5 = *(uint *)(uVar6 + 0x3e0 & 0xfffffffc);
        uVar3 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
        iVar4 = param_2 + 8;
        for (uVar5 = 0; uVar3 = uVar3 + 1, uVar5 < *(ushort *)(param_2 + 6); uVar5 = uVar5 + 1) {
          uVar2 = FUN_060096c4((ushort *)(uintptr_t)(uVar3));
          FUN_060096e4((ushort *)(uintptr_t)(iVar4),uVar2);
          iVar4 = iVar4 + 1;
        }
      }
    }
    sVar1 = thunk_FUN_03806b2c(*(ushort *)(param_2 + 6) + 1,2);
    *(short *)(param_2 + 2) = sVar1 + 2;
    uVar2 = 0;
  }
  else {
    uVar2 = 4;
  }
  return uVar2;
}

