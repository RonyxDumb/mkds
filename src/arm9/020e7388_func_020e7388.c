/* Decompiled C draft; module arm9; ROM address 020e7388. No matching claim. */
#include "types.h"
#include "deps/020e7388_func_020e7388.h"

undefined2 func_020e7388(int param_1)

{
  return *(undefined2 *)
          ((*(uint *)(uRam020e739c & 0xfffffffc) >> (uRam020e739c & 3) * 8 |
           *(uint *)(uRam020e739c & 0xfffffffc) << (uRam020e739c & 3) * -8 + 0x20) + param_1 * 2);
}

