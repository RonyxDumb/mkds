/* Decompiled C draft; module arm9; ROM address 02110324. No matching claim. */
#include "types.h"
#include "deps/02110324_func_02110324.h"

bool func_02110324(void)

{
  uint uVar1;
  
  uVar1 = *(uint *)(uRam0211034c & 0xfffffffc) >> (uRam0211034c & 3) * 8 |
          *(uint *)(uRam0211034c & 0xfffffffc) << (uRam0211034c & 3) * -8 + 0x20;
  if (5 < uVar1) {
    return false;
  }
  return (1 << (uVar1 & 0xff) & 0x25U) != 0;
}

