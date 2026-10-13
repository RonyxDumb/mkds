/* Decompiled C draft; module arm9; ROM address 020b4e5c. No matching claim. */
#include "types.h"
#include "deps/020b4e5c_GetCurrentInternalCourseId_0.h"

uint GetCurrentInternalCourseId_0(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(uRam020b4e6c & 0xfffffffc) >> (uRam020b4e6c & 3) * 8 |
          *(uint *)(uRam020b4e6c & 0xfffffffc) << (uRam020b4e6c & 3) * -8 + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

