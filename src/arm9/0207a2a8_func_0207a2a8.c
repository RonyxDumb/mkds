/* Decompiled C draft; module arm9; ROM address 0207a2a8. No matching claim. */
#include "types.h"
#include "deps/0207a2a8_func_0207a2a8.h"

bool func_0207a2a8(uint *param_1)

{
  bool bVar1;
  
  bVar1 = *(uint *)(uRam0207a2cc & 0xfffffffc) >> (uRam0207a2cc & 3) * 8 != 0 ||
          *(uint *)(uRam0207a2cc & 0xfffffffc) << (uRam0207a2cc & 3) * -8 + 0x20 != 0;
  if (bVar1) {
    *param_1 = *(uint *)(uRam0207a2d0 & 0xfffffffc) >> (uRam0207a2d0 & 3) * 8 |
               *(uint *)(uRam0207a2d0 & 0xfffffffc) << (uRam0207a2d0 & 3) * -8 + 0x20;
  }
  return bVar1;
}

