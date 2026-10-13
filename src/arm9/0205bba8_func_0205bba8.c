/* Decompiled C draft; module arm9; ROM address 0205bba8. No matching claim. */
#include "types.h"
#include "deps/0205bba8_func_0205bba8.h"

undefined4 func_0205bba8(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = 0;
  uVar4 = *(uint *)(uRam0205bbe4 & 0xfffffffc) >> (uRam0205bbe4 & 3) * 8 |
          *(uint *)(uRam0205bbe4 & 0xfffffffc) << (uRam0205bbe4 & 3) * -8 + 0x20;
  uVar3 = uVar4 + 0x758;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  if (uVar3 == 3) {
    return 9;
  }
  if (uVar3 != 5) {
    return uVar2;
  }
  if ((*(ushort *)(uVar4 + 0x75c) & 0x100) != 0) {
    uVar2 = 2;
  }
  return uVar2;
}

