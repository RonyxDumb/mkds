/* Decompiled C draft; module arm9; ROM address 02059d80. No matching claim. */
#include "types.h"
#include "deps/02059d80_DisposeOverlayManagerHeap.h"

void DisposeOverlayManagerHeap(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam02059dc4 & 0xfffffffc) >> (uRam02059dc4 & 3) * 8 |
          *(uint *)(uRam02059dc4 & 0xfffffffc) << (uRam02059dc4 & 3) * -8 + 0x20) + 0xa4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    Mem_Exp_Finalize();
    *(undefined4 *)
     ((*(uint *)(uRam02059dc4 & 0xfffffffc) >> (uRam02059dc4 & 3) * 8 |
      *(uint *)(uRam02059dc4 & 0xfffffffc) << (uRam02059dc4 & 3) * -8 + 0x20) + 0xa4) = 0;
    return;
  }
  return;
}

