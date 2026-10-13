/* Decompiled C draft; module arm9; ROM address 020e55b4. No matching claim. */
#include "types.h"
#include "deps/020e55b4_func_020e55b4.h"

void func_020e55b4(void)

{
  uint local_8 [2];
  
  local_8[0] = (uint)*(ushort *)
                      ((*(uint *)(uRam020e5630 & 0xfffffffc) >> (uRam020e5630 & 3) * 8 |
                       *(uint *)(uRam020e5630 & 0xfffffffc) << (uRam020e5630 & 3) * -8 + 0x20) +
                      0x1c);
  func_01ff9048(0x2b,local_8,1);
  func_01ff9048(0x2a,(*(uint *)(uRam020e5630 & 0xfffffffc) >> (uRam020e5630 & 3) * 8 |
                     *(uint *)(uRam020e5630 & 0xfffffffc) << (uRam020e5630 & 3) * -8 + 0x20) + 0x14,
                1);
  func_01ff9048(0x30,(*(uint *)(uRam020e5630 & 0xfffffffc) >> (uRam020e5630 & 3) * 8 |
                     *(uint *)(uRam020e5630 & 0xfffffffc) << (uRam020e5630 & 3) * -8 + 0x20) + 4,1);
  func_01ff9048(0x31,(*(uint *)(uRam020e5630 & 0xfffffffc) >> (uRam020e5630 & 3) * 8 |
                     *(uint *)(uRam020e5630 & 0xfffffffc) << (uRam020e5630 & 3) * -8 + 0x20) + 8,1);
  return;
}

