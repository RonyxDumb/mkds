/* Decompiled C draft; module arm7; ROM address 037ff2f4. No matching claim. */
#include "types.h"
#include "deps/037ff2f4_FUN_037ff2f4.h"

void FUN_037ff2f4(void)

{
  int iVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0;
  if (*(uint *)(DAT_037ff390 & 0xfffffffc) >> (DAT_037ff390 & 3) * 8 != 0 ||
      *(uint *)(DAT_037ff390 & 0xfffffffc) << (DAT_037ff390 & 3) * -8 + 0x20 != 0) {
    uVar4 = 0;
    do {
      iVar1 = FUN_037fbbd8(uVar4);
      if (iVar1 != 0) {
        uVar3 = uVar3 | 1 << (uVar4 & 0xff) & 0xffffU;
      }
      uVar4 = uVar4 + 1;
    } while ((int)uVar4 < 0x10);
    iVar1 = FUN_037fc408(0);
    uVar2 = (ushort)(iVar1 != 0);
    iVar1 = FUN_037fc408(1);
    uVar4 = DAT_037ff390;
    if (iVar1 != 0) {
      uVar2 = uVar2 | 2;
    }
    *(short *)((*(uint *)(DAT_037ff390 & 0xfffffffc) >> (DAT_037ff390 & 3) * 8 |
               *(uint *)(DAT_037ff390 & 0xfffffffc) << (DAT_037ff390 & 3) * -8 + 0x20) + 8) =
         (short)uVar3;
    uVar3 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    *(ushort *)((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + 10) = uVar2;
  }
  return;
}

