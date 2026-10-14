/* Decompiled C draft; module arm9; ROM address 020dd230. No matching claim. */
#include "types.h"
#include "deps/020dd230_func_020dd230.h"

undefined1 func_020dd230(int param_1,undefined4 param_2,char *param_3,undefined1 *param_4)

{
  uint uVar1;
  uint uVar2;
  
  if ((*param_3 == '\x01') &&
     ((*(short *)(param_1 + 0x8e) != 2 ||
      (uVar1 = param_1 + 0x14U & 3, uVar2 = *(uint *)(param_1 + 0x14U & 0xfffffffc),
      (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) < 0x4000)))) {
    *(undefined2 *)(param_1 + 0x90) = 2;
    *(undefined2 *)(param_1 + 0x92) = 1;
    func_020d26f8();
  }
  return *param_4;
}

