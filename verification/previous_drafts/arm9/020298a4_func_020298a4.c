/* Decompiled C draft; module arm9; ROM address 020298a4. No matching claim. */
#include "types.h"
#include "deps/020298a4_func_020298a4.h"

void func_020298a4(undefined4 param_1)

{
  *(undefined4 *)
   ((*(uint *)(uRam020298b4 & 0xfffffffc) >> (uRam020298b4 & 3) * 8 |
    *(uint *)(uRam020298b4 & 0xfffffffc) << (uRam020298b4 & 3) * -8 + 0x20) + 0x204) = param_1;
  return;
}

