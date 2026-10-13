/* Decompiled C draft; module arm9; ROM address 02046c74. No matching claim. */
#include "types.h"
#include "deps/02046c74_ResetGlobal59C4.h"

void ResetGlobal59C4(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)((uint)puRam02046ca4 & 0xfffffffc) >> ((uint)puRam02046ca4 & 3) * 8 |
          *(uint *)((uint)puRam02046ca4 & 0xfffffffc) << ((uint)puRam02046ca4 & 3) * -8 + 0x20) +
          0x3c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  Maybe_helper_10f114(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  *puRam02046ca4 = 0;
  return;
}

