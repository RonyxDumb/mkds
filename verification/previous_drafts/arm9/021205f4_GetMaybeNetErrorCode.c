/* Decompiled C draft; module arm9; ROM address 021205f4. No matching claim. */
#include "types.h"
#include "deps/021205f4_GetMaybeNetErrorCode.h"

int GetMaybeNetErrorCode(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam0212060c & 0xfffffffc) >> (uRam0212060c & 3) * 8 |
          *(uint *)(uRam0212060c & 0xfffffffc) << (uRam0212060c & 3) * -8 + 0x20) + 0x1f48;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return -(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
}

