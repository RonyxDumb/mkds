/* Decompiled C draft; module arm9; ROM address 02145800. No matching claim. */
#include "types.h"
#include "deps/02145800_Card_IsNotBusy.h"

bool Card_IsNotBusy(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = iRam02145818 + 0x114U & 3;
  uVar2 = *(uint *)(iRam02145818 + 0x114U & 0xfffffffc);
  return ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 4) == 0;
}

