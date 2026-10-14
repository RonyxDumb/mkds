/* Decompiled C draft; module arm9; ROM address 020a10d4. No matching claim. */
#include "types.h"
#include "deps/020a10d4_func_020a10d4.h"

undefined2 func_020a10d4(int param_1)

{
  return *(undefined2 *)
          (param_1 * 0x70 +
           (*(uint *)(uRam020a10ec & 0xfffffffc) >> (uRam020a10ec & 3) * 8 |
           *(uint *)(uRam020a10ec & 0xfffffffc) << (uRam020a10ec & 3) * -8 + 0x20) + 0x50);
}

