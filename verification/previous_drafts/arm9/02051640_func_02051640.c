/* Decompiled C draft; module arm9; ROM address 02051640. No matching claim. */
#include "types.h"
#include "deps/02051640_func_02051640.h"

void func_02051640(void)

{
  *(undefined4 *)
   ((*(uint *)(uRam02051654 & 0xfffffffc) >> (uRam02051654 & 3) * 8 |
    *(uint *)(uRam02051654 & 0xfffffffc) << (uRam02051654 & 3) * -8 + 0x20) + 0x10) = 0;
  return;
}

