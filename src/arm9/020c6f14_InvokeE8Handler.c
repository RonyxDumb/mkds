/* Decompiled C draft; module arm9; ROM address 020c6f14. No matching claim. */
#include "types.h"
#include "deps/020c6f14_InvokeE8Handler.h"

void InvokeE8Handler(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = (*(uint *)(uRam020c6f7c & 0xfffffffc) >> (uRam020c6f7c & 3) * 8 |
          *(uint *)(uRam020c6f7c & 0xfffffffc) << (uRam020c6f7c & 3) * -8 + 0x20) + 8;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if ((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) == 1) {
    uVar2 = *(uint *)(uRam020c6f80 & 0xfffffffc) >> (uRam020c6f80 & 3) * 8 |
            *(uint *)(uRam020c6f80 & 0xfffffffc) << (uRam020c6f80 & 3) * -8 + 0x20;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    (*(code *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20))();
    uVar3 = uRam020c6f80;
    uVar4 = *(uint *)(uRam020c6f80 & 0xfffffffc) >> (uRam020c6f80 & 3) * 8 |
            *(uint *)(uRam020c6f80 & 0xfffffffc) << (uRam020c6f80 & 3) * -8 + 0x20;
    uVar1 = uVar4 + 0xe4;
    uVar2 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    *(uint *)(uVar4 + 0xe4) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 1;
    uVar1 = uVar3 & 3;
    uVar2 = *(uint *)(uVar3 & 0xfffffffc);
    uVar3 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    uVar1 = uVar3 + 0xe4;
    uVar2 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    if (0x17 < (int)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20)) {
      *(undefined4 *)(uVar3 + 0xe4) = 0;
    }
    return;
  }
  return;
}

