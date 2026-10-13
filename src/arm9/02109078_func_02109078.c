/* Decompiled C draft; module arm9; ROM address 02109078. No matching claim. */
#include "types.h"
#include "deps/02109078_func_02109078.h"

void func_02109078(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  if (((*(uint *)(uRam021090c0 & 0xfffffffc) >> (uRam021090c0 & 3) * 8 |
       *(uint *)(uRam021090c0 & 0xfffffffc) << (uRam021090c0 & 3) * -8 + 0x20) & 1) != 0) {
    func_0210c610(param_1,0,param_2,param_3);
    return;
  }
  return;
}

