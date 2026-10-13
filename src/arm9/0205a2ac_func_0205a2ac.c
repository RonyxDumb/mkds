/* Decompiled C draft; module arm9; ROM address 0205a2ac. No matching claim. */
#include "types.h"
#include "deps/0205a2ac_func_0205a2ac.h"

uint func_0205a2ac(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(uRam0205a308 & 0xfffffffc) >> (uRam0205a308 & 3) * 8 |
          *(uint *)(uRam0205a308 & 0xfffffffc) << (uRam0205a308 & 3) * -8 + 0x20;
  uVar1 = 0x13;
  if (1 < ((uint)*(ushort *)(uVar2 + param_1 * 0x88 + 0x178) + iRam0205a30c & 0xffff)) {
    uVar1 = uVar2 + param_1 * 0x88 + 0x16c;
    uVar2 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    uVar1 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  }
  return uVar1;
}

