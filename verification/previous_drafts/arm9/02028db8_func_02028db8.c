/* Decompiled C draft; module arm9; ROM address 02028db8. No matching claim. */
#include "types.h"
#include "deps/02028db8_func_02028db8.h"

undefined2 func_02028db8(int param_1)

{
  return *(undefined2 *)
          ((*(uint *)(uRam02028dd0 & 0xfffffffc) >> (uRam02028dd0 & 3) * 8 |
           *(uint *)(uRam02028dd0 & 0xfffffffc) << (uRam02028dd0 & 3) * -8 + 0x20) + param_1 * 8 +
          0x1e52);
}

