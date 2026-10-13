/* Decompiled C draft; module arm9; ROM address 0210d7ac. No matching claim. */
#include "types.h"
#include "deps/0210d7ac_func_0210d7ac.h"

void func_0210d7ac(void)

{
  if (*(uint *)(uRam0210d7d8 & 0xfffffffc) >> (uRam0210d7d8 & 3) * 8 != 0 ||
      *(uint *)(uRam0210d7d8 & 0xfffffffc) << (uRam0210d7d8 & 3) * -8 + 0x20 != 0) {
    func_0210d73c();
  }
  NNS_SndMain();
  return;
}

