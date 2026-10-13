/* Decompiled C draft; module arm9; ROM address 02050064. No matching claim. */
#include "types.h"
#include "deps/02050064_func_02050064.h"

undefined2 func_02050064(int param_1)

{
  return *(undefined2 *)
          ((*(uint *)(uRam0205007c & 0xfffffffc) >> (uRam0205007c & 3) * 8 |
           *(uint *)(uRam0205007c & 0xfffffffc) << (uRam0205007c & 3) * -8 + 0x20) + param_1 * 2 +
          0x1e9c);
}

