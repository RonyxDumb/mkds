/* Decompiled C draft; module arm9; ROM address 0212c554. No matching claim. */
#include "types.h"
#include "deps/0212c554_func_0212c554.h"

void func_0212c554(uint param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  if (uVar1 != 0) {
    func_02020d0c(*(undefined1 *)(uVar1 + 0x3c),param_2,(int)*(short *)(iRam0212c590 + param_3 * 2))
    ;
    return;
  }
  return;
}

