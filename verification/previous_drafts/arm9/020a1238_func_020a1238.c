/* Decompiled C draft; module arm9; ROM address 020a1238. No matching claim. */
#include "types.h"
#include "deps/020a1238_func_020a1238.h"

undefined2 func_020a1238(void)

{
  return *(undefined2 *)
          ((*(uint *)(uRam020a124c & 0xfffffffc) >> (uRam020a124c & 3) * 8 |
           *(uint *)(uRam020a124c & 0xfffffffc) << (uRam020a124c & 3) * -8 + 0x20) + 0x3a0);
}

