/* Decompiled C draft; module arm9; ROM address 0208ae60. No matching claim. */
#include "types.h"
#include "deps/0208ae60_GetUnknownPhysicalParamValue.h"

uint GetUnknownPhysicalParamValue(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam0208ae70 & 0xfffffffc) >> (uRam0208ae70 & 3) * 8 |
          *(uint *)(uRam0208ae70 & 0xfffffffc) << (uRam0208ae70 & 3) * -8 + 0x20) + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

