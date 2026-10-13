/* Decompiled C draft; module arm9; ROM address 0204fe1c. No matching claim. */
#include "types.h"
#include "deps/0204fe1c_func_0204fe1c.h"

undefined1 func_0204fe1c(int param_1)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  undefined1 uVar4;
  
  uVar4 = 0;
  uVar3 = *(uint *)(uRam0204fe88 & 0xfffffffc) >> (uRam0204fe88 & 3) * 8 |
          *(uint *)(uRam0204fe88 & 0xfffffffc) << (uRam0204fe88 & 3) * -8 + 0x20;
  if (uVar3 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
  }
  bVar1 = false;
  if (((uVar2 == 2) && (bVar1 = false, *psRam0204fe8c != 2)) &&
     ((int)((uint)*(byte *)(param_1 * 0xe0 + uVar3 + 0x188) << 0x1f) < 0)) {
    bVar1 = true;
  }
  if (bVar1) {
    uVar4 = *(undefined1 *)(param_1 * 0xe0 + uVar3 + 0x186);
  }
  return uVar4;
}

