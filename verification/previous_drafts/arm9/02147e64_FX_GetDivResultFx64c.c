/* Decompiled C draft; module arm9; ROM address 02147e64. No matching claim. */
#include "types.h"
#include "deps/02147e64_FX_GetDivResultFx64c.h"

undefined8 FX_GetDivResultFx64c(void)

{
  uint uVar1;
  uint uVar2;
  
  do {
  } while ((*puRam02147e84 & 0x8000) != 0);
  uVar1 = uRam02147e88 + 4 & 3;
  uVar2 = *(uint *)(uRam02147e88 + 4 & 0xfffffffc);
  return CONCAT44(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,
                  *(uint *)(uRam02147e88 & 0xfffffffc) >> (uRam02147e88 & 3) * 8 |
                  *(uint *)(uRam02147e88 & 0xfffffffc) << (uRam02147e88 & 3) * -8 + 0x20);
}

