/* Decompiled C draft; module arm9; ROM address 0212d10c. No matching claim. */
#include "types.h"
#include "deps/0212d10c_func_0212d10c.h"

void func_0212d10c(void)

{
  uint uVar1;
  uint uVar2;
  
  if (*(uint *)(uRam0212d150 & 0xfffffffc) >> (uRam0212d150 & 3) * 8 == 0 &&
      *(uint *)(uRam0212d150 & 0xfffffffc) << (uRam0212d150 & 3) * -8 + 0x20 == 0) {
    return;
  }
  uVar1 = uRam0212d150 + 4 & 3;
  uVar2 = *(uint *)(uRam0212d150 + 4 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 1) {
    func_0212cbd8();
    return;
  }
  return;
}

