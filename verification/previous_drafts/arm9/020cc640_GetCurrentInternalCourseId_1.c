/* Decompiled C draft; module arm9; ROM address 020cc640. No matching claim. */
#include "types.h"
#include "deps/020cc640_GetCurrentInternalCourseId_1.h"

uint GetCurrentInternalCourseId_1(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(uRam020cc650 & 0xfffffffc) >> (uRam020cc650 & 3) * 8 |
          *(uint *)(uRam020cc650 & 0xfffffffc) << (uRam020cc650 & 3) * -8 + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

