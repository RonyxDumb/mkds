/* Decompiled C draft; module arm9; ROM address 02043a20. No matching claim. */
#include "types.h"
#include "deps/02043a20_func_02043a20.h"

undefined2 func_02043a20(void)

{
  return *(undefined2 *)
          ((*(uint *)(uRam02043a30 & 0xfffffffc) >> (uRam02043a30 & 3) * 8 |
           *(uint *)(uRam02043a30 & 0xfffffffc) << (uRam02043a30 & 3) * -8 + 0x20) + 2);
}

