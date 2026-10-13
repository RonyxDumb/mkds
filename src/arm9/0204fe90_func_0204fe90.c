/* Decompiled C draft; module arm9; ROM address 0204fe90. No matching claim. */
#include "types.h"
#include "deps/0204fe90_func_0204fe90.h"

undefined4 func_0204fe90(int param_1)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = 0;
  uVar4 = *(uint *)(uRam0204ff0c & 0xfffffffc) >> (uRam0204ff0c & 3) * 8 |
          *(uint *)(uRam0204ff0c & 0xfffffffc) << (uRam0204ff0c & 3) * -8 + 0x20;
  if (uVar4 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
            *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
  }
  bVar1 = false;
  if (((uVar3 == 2) && (bVar1 = false, *psRam0204ff10 != 2)) &&
     ((int)((uint)*(byte *)(param_1 * 0xe0 + uVar4 + 0x188) << 0x1f) < 0)) {
    bVar1 = true;
  }
  if ((bVar1) && ((int)((uint)*(byte *)(param_1 * 0xe0 + uVar4 + 0x188) << 0x1a) < 0)) {
    uVar2 = 1;
  }
  return uVar2;
}

