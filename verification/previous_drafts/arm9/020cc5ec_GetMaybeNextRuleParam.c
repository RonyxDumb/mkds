/* Decompiled C draft; module arm9; ROM address 020cc5ec. No matching claim. */
#include "types.h"
#include "deps/020cc5ec_GetMaybeNextRuleParam.h"

undefined2 GetMaybeNextRuleParam(void)

{
  return *(undefined2 *)
          ((*(uint *)(uRam020cc600 & 0xfffffffc) >> (uRam020cc600 & 3) * 8 |
           *(uint *)(uRam020cc600 & 0xfffffffc) << (uRam020cc600 & 3) * -8 + 0x20) + 0x3d8);
}

