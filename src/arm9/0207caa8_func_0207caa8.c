/* Decompiled C draft; module arm9; ROM address 0207caa8. No matching claim. */
#include "types.h"
#include "deps/0207caa8_func_0207caa8.h"

void func_0207caa8(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)*(ushort *)(param_2 + 4) * 0x210 +
          (*(uint *)(uRam0207cb00 & 0xfffffffc) >> (uRam0207cb00 & 3) * 8 |
          *(uint *)(uRam0207cb00 & 0xfffffffc) << (uRam0207cb00 & 3) * -8 + 0x20) + 0x60;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 3) {
    (*(code *)(*(uint *)(uRam0207cb04 & 0xfffffffc) >> (uRam0207cb04 & 3) * 8 |
              *(uint *)(uRam0207cb04 & 0xfffffffc) << (uRam0207cb04 & 3) * -8 + 0x20))();
    return;
  }
  (*(code *)(*(uint *)(uRam0207cb08 & 0xfffffffc) >> (uRam0207cb08 & 3) * 8 |
            *(uint *)(uRam0207cb08 & 0xfffffffc) << (uRam0207cb08 & 3) * -8 + 0x20))();
  return;
}

