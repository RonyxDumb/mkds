/* Decompiled C draft; module arm9; ROM address 020b36a4. No matching claim. */
#include "types.h"
#include "deps/020b36a4_MaybeClearGlobalB358.h"

void MaybeClearGlobalB358(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = uRam020b36c4;
  *(undefined4 *)
   (*(uint *)(uRam020b36c4 & 0xfffffffc) >> (uRam020b36c4 & 3) * 8 |
   *(uint *)(uRam020b36c4 & 0xfffffffc) << (uRam020b36c4 & 3) * -8 + 0x20) = 0;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  *(undefined4 *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 8) = 0xffffff88;
  return;
}

