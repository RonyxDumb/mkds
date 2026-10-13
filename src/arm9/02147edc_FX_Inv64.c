/* Decompiled C draft; module arm9; ROM address 02147edc. No matching claim. */
#include "types.h"
#include "deps/02147edc_FX_Inv64.h"

undefined8 FX_Inv64(void)

{
  uint uVar1;
  uint uVar2;
  
  FX_InvAsync();
  do {
  } while ((*puRam02147f10 & 0x8000) != 0);
  uVar1 = uRam02147f14 + 4 & 3;
  uVar2 = *(uint *)(uRam02147f14 + 4 & 0xfffffffc);
  return CONCAT44(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,
                  *(uint *)(uRam02147f14 & 0xfffffffc) >> (uRam02147f14 & 3) * 8 |
                  *(uint *)(uRam02147f14 & 0xfffffffc) << (uRam02147f14 & 3) * -8 + 0x20);
}

