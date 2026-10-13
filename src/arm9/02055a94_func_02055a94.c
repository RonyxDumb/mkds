/* Decompiled C draft; module arm9; ROM address 02055a94. No matching claim. */
#include "types.h"
#include "deps/02055a94_func_02055a94.h"

void func_02055a94(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  bVar1 = false;
  uVar4 = *(uint *)(uRam02055af4 & 0xfffffffc) >> (uRam02055af4 & 3) * 8 |
          *(uint *)(uRam02055af4 & 0xfffffffc) << (uRam02055af4 & 3) * -8 + 0x20;
  if (uVar4 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
            *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
  }
  if ((uVar2 != 0) &&
     (uVar2 = uVar4 + 4 & 3, uVar3 = *(uint *)(uVar4 + 4 & 0xfffffffc),
     (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) != 0xd)) {
    bVar1 = true;
  }
  if (bVar1) {
    if (uVar4 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
              *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
    }
    if (uVar4 != 1) {
      return;
    }
  }
  uVar4 = *(uint *)(uRam02055af8 & 0xfffffffc) >> (uRam02055af8 & 3) * 8 |
          *(uint *)(uRam02055af8 & 0xfffffffc) << (uRam02055af8 & 3) * -8 + 0x20;
  *(ushort *)(uVar4 + 8) = *(ushort *)(uVar4 + 8) | 8;
  return;
}

