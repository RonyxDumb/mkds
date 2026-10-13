/* Decompiled C draft; module arm9; ROM address 02050300. No matching claim. */
#include "types.h"
#include "deps/02050300_func_02050300.h"

void func_02050300(void)

{
  uint uVar1;
  
  uVar1 = *(uint *)(uRam0205031c & 0xfffffffc) >> (uRam0205031c & 3) * 8 |
          *(uint *)(uRam0205031c & 0xfffffffc) << (uRam0205031c & 3) * -8 + 0x20;
  *(ushort *)(uVar1 + 0x454) = *(ushort *)(uVar1 + 0x454) | 1;
  return;
}

