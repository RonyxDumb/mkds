/* Decompiled C draft; module arm9; ROM address 02050034. No matching claim. */
#include "types.h"
#include "deps/02050034_func_02050034.h"

void func_02050034(undefined1 param_1)

{
  *(undefined1 *)
   ((*(uint *)(uRam02050060 & 0xfffffffc) >> (uRam02050060 & 3) * 8 |
    *(uint *)(uRam02050060 & 0xfffffffc) << (uRam02050060 & 3) * -8 + 0x20) + 0x15f6) = param_1;
  func_02050080();
  func_02058b10();
  return;
}

