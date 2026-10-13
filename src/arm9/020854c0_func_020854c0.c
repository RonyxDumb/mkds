/* Decompiled C draft; module arm9; ROM address 020854c0. No matching claim. */
#include "types.h"
#include "deps/020854c0_func_020854c0.h"

int func_020854c0(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = *(uint *)(uRam02085524 & 0xfffffffc) >> (uRam02085524 & 3) * 8 |
          *(uint *)(uRam02085524 & 0xfffffffc) << (uRam02085524 & 3) * -8 + 0x20;
  uVar4 = 0;
  if (*(char *)(uVar3 + 0x3d0) != '\0') {
    do {
      uVar2 = (*(uint *)(uRam02085528 & 0xfffffffc) >> (uRam02085528 & 3) * 8 |
              *(uint *)(uRam02085528 & 0xfffffffc) << (uRam02085528 & 3) * -8 + 0x20) + uVar4 * 4 +
              0x40;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      if (param_1 == ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xffff)) {
        return uVar4 + 1;
      }
      uVar4 = uVar4 + 1 & 0xffff;
    } while (uVar4 < *(byte *)(uVar3 + 0x3d0));
  }
  return -1;
}

