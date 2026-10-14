/* Decompiled C draft; module arm9; ROM address 0203c8c0. No matching claim. */
#include "types.h"
#include "deps/0203c8c0_func_0203c8c0.h"

undefined2 func_0203c8c0(int param_1)

{
  return *(undefined2 *)
          (param_1 * 0x8c +
           (*(uint *)(uRam0203c8d8 & 0xfffffffc) >> (uRam0203c8d8 & 3) * 8 |
           *(uint *)(uRam0203c8d8 & 0xfffffffc) << (uRam0203c8d8 & 3) * -8 + 0x20) + 0x4e);
}

