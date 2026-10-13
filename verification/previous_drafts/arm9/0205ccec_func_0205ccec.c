/* Decompiled C draft; module arm9; ROM address 0205ccec. No matching claim. */
#include "types.h"
#include "deps/0205ccec_func_0205ccec.h"

void func_0205ccec(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(uRam0205cd20 & 0xfffffffc) >> (uRam0205cd20 & 3) * 8 |
          *(uint *)(uRam0205cd20 & 0xfffffffc) << (uRam0205cd20 & 3) * -8 + 0x20;
  if (uVar3 == 0) {
    return;
  }
  if ((*(short *)(uVar3 + 0xe) != 4) && (*(short *)(uVar3 + 0xe) != 5)) {
    return;
  }
  uVar1 = uVar3 + 0x728 & 3;
  uVar2 = *(uint *)(uVar3 + 0x728 & 0xfffffffc);
  *(uint *)(uVar3 + 0x728) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 1;
  return;
}

