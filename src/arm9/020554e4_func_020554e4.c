/* Decompiled C draft; module arm9; ROM address 020554e4. No matching claim. */
#include "types.h"
#include "deps/020554e4_func_020554e4.h"

undefined4 func_020554e4(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = uRam02055560;
  uVar4 = *(uint *)(uRam02055560 & 0xfffffffc) >> (uRam02055560 & 3) * 8 |
          *(uint *)(uRam02055560 & 0xfffffffc) << (uRam02055560 & 3) * -8 + 0x20;
  uVar3 = uVar4 + 0x10 & 3;
  uVar2 = *(uint *)(uVar4 + 0x10 & 0xfffffffc);
  if (uVar2 >> uVar3 * 8 != 0 || uVar2 << uVar3 * -8 + 0x20 != 0) {
    return 0;
  }
  uVar3 = uVar4 + 0xc & 3;
  uVar2 = *(uint *)(uVar4 + 0xc & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 == 0xb) {
    if ((*(byte *)(uVar4 + 0x8b) & 8) != 0) {
      func_02051658();
    }
  }
  else if (uVar3 == 0xf) {
    *(byte *)(uVar4 + 0x8b) = *(byte *)(uVar4 + 0x8b) & 0xf7;
    uVar3 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    *(undefined4 *)((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) + 0xc) = 0xb;
  }
  return 0;
}

