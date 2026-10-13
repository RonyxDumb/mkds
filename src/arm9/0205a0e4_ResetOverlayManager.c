/* Decompiled C draft; module arm9; ROM address 0205a0e4. No matching claim. */
#include "types.h"
#include "deps/0205a0e4_ResetOverlayManager.h"

void ResetOverlayManager(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = uRam0205a104;
  *(undefined4 *)
   (*(uint *)(uRam0205a104 & 0xfffffffc) >> (uRam0205a104 & 3) * 8 |
   *(uint *)(uRam0205a104 & 0xfffffffc) << (uRam0205a104 & 3) * -8 + 0x20) = 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  *(undefined4 *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 4) = 0;
  return;
}

