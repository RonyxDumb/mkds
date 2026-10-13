/* Decompiled C draft; module arm9; ROM address 0204465c. No matching claim. */
#include "types.h"
#include "deps/0204465c_ResetRacersForTimeTrial.h"

void ResetRacersForTimeTrial(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar2 = uRam020446dc;
  uVar4 = *(uint *)(uRam020446dc & 0xfffffffc) >> (uRam020446dc & 3) * 8 |
          *(uint *)(uRam020446dc & 0xfffffffc) << (uRam020446dc & 3) * -8 + 0x20;
  uVar3 = uVar4 + 0x1f0;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) == 1) {
    *(undefined4 *)(uVar4 + 500) = 0;
    uVar3 = 1;
    do {
      iVar5 = uVar3 * 0x30;
      *(uint *)((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + iVar5 + 0x250) = uVar3;
      *(uint *)((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + iVar5 + 0x254) = uVar3;
      *(undefined4 *)
       ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
        *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + iVar5 + 600) = 4;
      *(uint *)((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + iVar5 + 0x264) = uVar3;
      uVar3 = uVar3 + 1 & 0xffff;
    } while (uVar3 < 8);
    return;
  }
  return;
}

