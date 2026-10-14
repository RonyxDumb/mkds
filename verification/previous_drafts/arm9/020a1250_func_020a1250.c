/* Decompiled C draft; module arm9; ROM address 020a1250. No matching claim. */
#include "types.h"
#include "deps/020a1250_func_020a1250.h"

undefined2 func_020a1250(int param_1)

{
  return *(undefined2 *)
          (param_1 * 0x70 +
           (*(uint *)(uRam020a1268 & 0xfffffffc) >> (uRam020a1268 & 3) * 8 |
           *(uint *)(uRam020a1268 & 0xfffffffc) << (uRam020a1268 & 3) * -8 + 0x20) + 0x48);
}

