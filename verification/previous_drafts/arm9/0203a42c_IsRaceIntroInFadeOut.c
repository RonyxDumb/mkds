/* Decompiled C draft; module arm9; ROM address 0203a42c. No matching claim. */
#include "types.h"
#include "deps/0203a42c_IsRaceIntroInFadeOut.h"

uint IsRaceIntroInFadeOut(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam0203a43c & 0xfffffffc) >> (uRam0203a43c & 3) * 8 |
          *(uint *)(uRam0203a43c & 0xfffffffc) << (uRam0203a43c & 3) * -8 + 0x20) + 0x4d0;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

