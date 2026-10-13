/* Decompiled C draft; module arm9_ov001; ROM address 0218547c. No matching claim. */
#include "types.h"
#include "deps/0218547c_FUN_0218547c.h"

void FUN_0218547c(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(DAT_0218548c & 0xfffffffc) >> (DAT_0218548c & 3) * 8 |
    *(uint *)(DAT_0218548c & 0xfffffffc) << (DAT_0218548c & 3) * -8 + 0x20) + 4) = param_1;
  return;
}

