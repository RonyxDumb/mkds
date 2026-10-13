/* Decompiled C draft; module arm9; ROM address 0207cb0c. No matching claim. */
#include "types.h"
#include "deps/0207cb0c_func_0207cb0c.h"

void func_0207cb0c(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)*(ushort *)(param_2 + 4) * 0x210 +
          (*(uint *)(uRam0207cb64 & 0xfffffffc) >> (uRam0207cb64 & 3) * 8 |
          *(uint *)(uRam0207cb64 & 0xfffffffc) << (uRam0207cb64 & 3) * -8 + 0x20) + 0x60;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 4) {
    (*(code *)(*(uint *)(uRam0207cb68 & 0xfffffffc) >> (uRam0207cb68 & 3) * 8 |
              *(uint *)(uRam0207cb68 & 0xfffffffc) << (uRam0207cb68 & 3) * -8 + 0x20))();
    return;
  }
  (*(code *)(*(uint *)(uRam0207cb6c & 0xfffffffc) >> (uRam0207cb6c & 3) * 8 |
            *(uint *)(uRam0207cb6c & 0xfffffffc) << (uRam0207cb6c & 3) * -8 + 0x20))();
  return;
}

