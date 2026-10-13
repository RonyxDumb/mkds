/* Decompiled C draft; module arm9; ROM address 02111144. No matching claim. */
#include "types.h"
#include "deps/02111144_GetSomeCXSseqId.h"

uint GetSomeCXSseqId(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = iRam02111154 + 8U & 3;
  uVar1 = *(uint *)(iRam02111154 + 8U & 0xfffffffc);
  uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 0x14;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

