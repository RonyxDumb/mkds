/* Decompiled C draft; module arm9; ROM address 0204f8a0. No matching claim. */
#include "types.h"
#include "deps/0204f8a0_func_0204f8a0.h"

void func_0204f8a0(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  bVar1 = false;
  uVar3 = *(uint *)(uRam0204f930 & 0xfffffffc) >> (uRam0204f930 & 3) * 8 |
          *(uint *)(uRam0204f930 & 0xfffffffc) << (uRam0204f930 & 3) * -8 + 0x20;
  if ((*(ushort *)(uVar3 + 0x454) & 0x40) != 0) {
    if (uVar3 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
    }
    bVar4 = true;
    if ((uVar2 != 1) && (*psRam0204f934 != 2)) {
      bVar4 = false;
    }
    if (bVar4) {
      bVar1 = true;
    }
  }
  if (bVar1) {
    if (uVar3 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
    }
    if (uVar3 == 1) {
      func_0204bcb4();
      return;
    }
    return;
  }
  return;
}

