/* Decompiled C draft; module arm9; ROM address 020e6a74. No matching claim. */
#include "types.h"
#include "deps/020e6a74_func_020e6a74.h"

void func_020e6a74(void)

{
  undefined4 local_8 [2];
  
  func_01ff9048(0x17,*(uint *)(uRam020e6ab4 & 0xfffffffc) >> (uRam020e6ab4 & 3) * 8 |
                     *(uint *)(uRam020e6ab4 & 0xfffffffc) << (uRam020e6ab4 & 3) * -8 + 0x20,0xc);
  local_8[0] = 0x1e;
  func_01ff9048(0x13,(undefined4)(uintptr_t)(local_8),1);
  return;
}

