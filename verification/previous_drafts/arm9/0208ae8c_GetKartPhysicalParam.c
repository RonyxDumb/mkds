/* Decompiled C draft; module arm9; ROM address 0208ae8c. No matching claim. */
#include "types.h"
#include "deps/0208ae8c_GetKartPhysicalParam.h"

int GetKartPhysicalParam(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(uRam0208aea4 & 0xfffffffc) >> (uRam0208aea4 & 3) * 8 |
          *(uint *)(uRam0208aea4 & 0xfffffffc) << (uRam0208aea4 & 3) * -8 + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return param_1 * 0x98 + (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
}

