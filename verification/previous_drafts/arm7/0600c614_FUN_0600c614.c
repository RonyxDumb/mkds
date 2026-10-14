/* Decompiled C draft; module arm7; ROM address 0600c614. No matching claim. */
#include "types.h"
#include "deps/0600c614_FUN_0600c614.h"

void FUN_0600c614(void)

{
  uint uVar1;
  uint uVar2;
  short *psVar3;
  bool bVar4;
  
  psVar3 = (short *)((*(uint *)(DAT_0600c6e0 & 0xfffffffc) >> (DAT_0600c6e0 & 3) * 8 |
                     *(uint *)(DAT_0600c6e0 & 0xfffffffc) << (DAT_0600c6e0 & 3) * -8 + 0x20) +
                    DAT_0600c6e4);
  bVar4 = false;
  FUN_06014708(2);
  FUN_06014708(1);
  FUN_06014708(0);
  if ((psVar3[0x14] != 0) &&
     (uVar1 = (uint)(psVar3 + 0x18) & 3, uVar2 = *(uint *)((uint)(psVar3 + 0x18) & 0xfffffffc),
     bVar4 = *(short *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) != 0, !bVar4)) {
    psVar3[0x14] = (ushort)bVar4;
  }
  if (psVar3[10] != 0) {
    uVar1 = (uint)(psVar3 + 0xe) & 3;
    uVar2 = *(uint *)((uint)(psVar3 + 0xe) & 0xfffffffc);
    if (*(short *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 0) {
      psVar3[10] = 0;
    }
    else {
      bVar4 = true;
    }
  }
  if (*psVar3 != 0) {
    uVar1 = (uint)(psVar3 + 4) & 3;
    uVar2 = *(uint *)((uint)(psVar3 + 4) & 0xfffffffc);
    if (*(short *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 0) {
      *psVar3 = 0;
    }
    else {
      bVar4 = true;
    }
  }
  if (bVar4) {
    FUN_06008a8c(0,0xe);
  }
  FUN_06008a8c(0,0x14);
  return;
}

