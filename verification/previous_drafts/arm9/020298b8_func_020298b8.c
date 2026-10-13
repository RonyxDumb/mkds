/* Decompiled C draft; module arm9; ROM address 020298b8. No matching claim. */
#include "types.h"
#include "deps/020298b8_func_020298b8.h"

void func_020298b8(undefined1 param_1)

{
  *(undefined1 *)
   ((*(uint *)(uRam020298c8 & 0xfffffffc) >> (uRam020298c8 & 3) * 8 |
    *(uint *)(uRam020298c8 & 0xfffffffc) << (uRam020298c8 & 3) * -8 + 0x20) + 0x240) = param_1;
  return;
}

