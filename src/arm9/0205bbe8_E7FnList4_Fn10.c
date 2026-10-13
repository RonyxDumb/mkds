/* Decompiled C draft; module arm9; ROM address 0205bbe8. No matching claim. */
#include "types.h"
#include "deps/0205bbe8_E7FnList4_Fn10.h"

void E7FnList4_Fn10(void)

{
  uint uVar1;
  
  uVar1 = *(uint *)(uRam0205bc04 & 0xfffffffc) >> (uRam0205bc04 & 3) * 8 |
          *(uint *)(uRam0205bc04 & 0xfffffffc) << (uRam0205bc04 & 3) * -8 + 0x20;
  *(ushort *)(uVar1 + 0x75c) = *(ushort *)(uVar1 + 0x75c) & 0xfeff;
  return;
}

