/* Decompiled C draft; module arm9; ROM address 0203c174. No matching claim. */
#include "types.h"
#include "deps/0203c174_func_0203c174.h"

bool func_0203c174(void)

{
  return *(ushort *)
          ((*(uint *)(uRam0203c1a4 & 0xfffffffc) >> (uRam0203c1a4 & 3) * 8 |
           *(uint *)(uRam0203c1a4 & 0xfffffffc) << (uRam0203c1a4 & 3) * -8 + 0x20) + 0x38) <
         *(ushort *)
          ((*(uint *)(uRam0203c1a0 & 0xfffffffc) >> (uRam0203c1a0 & 3) * 8 |
           *(uint *)(uRam0203c1a0 & 0xfffffffc) << (uRam0203c1a0 & 3) * -8 + 0x20) + 0x4fa);
}

