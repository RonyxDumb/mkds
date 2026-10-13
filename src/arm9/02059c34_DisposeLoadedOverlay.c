/* Decompiled C draft; module arm9; ROM address 02059c34. No matching claim. */
#include "types.h"
#include "deps/02059c34_DisposeLoadedOverlay.h"

void DisposeLoadedOverlay(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = (*(uint *)(uRam02059ce4 & 0xfffffffc) >> (uRam02059ce4 & 3) * 8 |
          *(uint *)(uRam02059ce4 & 0xfffffffc) << (uRam02059ce4 & 3) * -8 + 0x20) + 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  if ((uVar2 != 1) && (uVar2 != 2)) {
    return;
  }
  uVar2 = *(uint *)(uRam02059ce4 & 0xfffffffc) >> (uRam02059ce4 & 3) * 8 |
          *(uint *)(uRam02059ce4 & 0xfffffffc) << (uRam02059ce4 & 3) * -8 + 0x20;
  uVar2 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
          *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) * 0xc + uVar2 + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  iVar3 = Fs_UnloadOverlay(0,uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  uVar2 = uRam02059ce4;
  if (iVar3 == 0) {
    return;
  }
  *(undefined4 *)
   (*(uint *)(uRam02059ce4 & 0xfffffffc) >> (uRam02059ce4 & 3) * 8 |
   *(uint *)(uRam02059ce4 & 0xfffffffc) << (uRam02059ce4 & 3) * -8 + 0x20) = 4;
  *(undefined4 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 4) = 0;
  uVar2 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
          *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0xa4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    Mem_Exp_Finalize();
    *(undefined4 *)
     ((*(uint *)(uRam02059ce4 & 0xfffffffc) >> (uRam02059ce4 & 3) * 8 |
      *(uint *)(uRam02059ce4 & 0xfffffffc) << (uRam02059ce4 & 3) * -8 + 0x20) + 0xa4) = 0;
    return;
  }
  return;
}

