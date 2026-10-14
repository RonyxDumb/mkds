/* Decompiled C draft; module arm9; ROM address 0212c5f4. No matching claim. */
#include "types.h"
#include "deps/0212c5f4_func_0212c5f4.h"

void func_0212c5f4(uint param_1)

{
  if (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 != 0 ||
      *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20 != 0) {
    func_0212bcac();
    return;
  }
  return;
}

