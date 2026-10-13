/* Decompiled C draft; module arm9; ROM address 0204a928. No matching claim. */
#include "types.h"
#include "deps/0204a928_func_0204a928.h"

void func_0204a928(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 8 & 3;
  uVar2 = *(uint *)(param_1 + 8 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 1) {
    *(uint *)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
             *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) =
         (uint)*(ushort *)(param_1 + 4) << 1;
    *(undefined4 *)(param_1 + 8) = 0;
    DC_SomeClean(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                 *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20,uRam0204a974);
    return;
  }
  return;
}

