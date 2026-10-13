/* Decompiled C draft; module arm9; ROM address 02148934. No matching claim. */
#include "types.h"
#include "deps/02148934_SetDispcntSubBgMode.h"

void SetDispcntSubBgMode(uint param_1)

{
  *puRam0214894c =
       (*(uint *)((uint)puRam0214894c & 0xfffffffc) >> ((uint)puRam0214894c & 3) * 8 |
       *(uint *)((uint)puRam0214894c & 0xfffffffc) << ((uint)puRam0214894c & 3) * -8 + 0x20) &
       0xfffffff8 | param_1;
  return;
}

