/* Decompiled C draft; module arm9; ROM address 020eb760. No matching claim. */
#include "types.h"
#include "deps/020eb760_func_020eb760.h"

undefined1 func_020eb760(uint param_1,int param_2,byte *param_3,undefined1 *param_4)

{
  uint uVar1;
  uint uVar2;
  
  if (*param_3 - 1 < 2) {
    func_020ebef8(param_1,param_2 + 0x5c);
    if ((*(uint *)((uint)puRam020eb7dc & 0xfffffffc) >> ((uint)puRam020eb7dc & 3) * 8 |
        *(uint *)((uint)puRam020eb7dc & 0xfffffffc) << ((uint)puRam020eb7dc & 3) * -8 + 0x20) ==
        param_1) {
      *puRam020eb7dc = 0;
    }
    *(undefined2 *)(param_1 + 0x90) = 1;
    *(undefined2 *)(param_1 + 0x92) = 1;
    uVar1 = param_1 + 0x78 & 3;
    uVar2 = *(uint *)(param_1 + 0x78 & 0xfffffffc);
    if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 3) == 0) {
      func_0208b7bc(0x31,param_1 + 4);
      func_0208b7bc(0x32,param_1 + 4);
    }
  }
  return *param_4;
}

