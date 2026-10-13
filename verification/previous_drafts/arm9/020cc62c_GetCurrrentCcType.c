/* Decompiled C draft; module arm9; ROM address 020cc62c. No matching claim. */
#include "types.h"
#include "deps/020cc62c_GetCurrrentCcType.h"

uint GetCurrrentCcType(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020cc63c & 0xfffffffc) >> (uRam020cc63c & 3) * 8 |
          *(uint *)(uRam020cc63c & 0xfffffffc) << (uRam020cc63c & 3) * -8 + 0x20) + 0x10;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

