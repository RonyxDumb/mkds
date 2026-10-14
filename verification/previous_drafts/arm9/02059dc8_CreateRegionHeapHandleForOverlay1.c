/* Decompiled C draft; module arm9; ROM address 02059dc8. No matching claim. */
#include "types.h"
#include "deps/02059dc8_CreateRegionHeapHandleForOverlay1.h"

void CreateRegionHeapHandleForOverlay1(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = *(uint *)(uRam02059e14 & 0xfffffffc) >> (uRam02059e14 & 3) * 8 |
          *(uint *)(uRam02059e14 & 0xfffffffc) << (uRam02059e14 & 3) * -8 + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 1) {
    uVar3 = Mem_Exp_Create(uRam02059e18,0x20800,1);
    *(undefined4 *)
     ((*(uint *)(uRam02059e14 & 0xfffffffc) >> (uRam02059e14 & 3) * 8 |
      *(uint *)(uRam02059e14 & 0xfffffffc) << (uRam02059e14 & 3) * -8 + 0x20) + 0xa4) = uVar3;
    return;
  }
  return;
}

