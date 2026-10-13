/* Decompiled C draft; module arm9; ROM address 02105980. No matching claim. */
#include "types.h"
#include "deps/02105980_func_02105980.h"

void func_02105980(int param_1,undefined4 param_2)

{
  if ((*(uint *)(uRam021059d4 & 0xfffffffc) >> (uRam021059d4 & 3) * 8 |
      *(uint *)(uRam021059d4 & 0xfffffffc) << (uRam021059d4 & 3) * -8 + 0x20) - 1 < 2) {
    func_0212c6f0(uRam021059d8);
  }
  if (param_1 == 3) {
    func_0212c6f0(uRam021059dc,param_2);
    return;
  }
  return;
}

