/* Decompiled C draft; module arm9; ROM address 0211f6cc. No matching claim. */
#include "types.h"
#include "deps/0211f6cc_func_0211f6cc.h"

void func_0211f6cc(int param_1,undefined1 param_2)

{
  *(undefined1 *)
   ((*(uint *)(uRam0211f6e4 & 0xfffffffc) >> (uRam0211f6e4 & 3) * 8 |
    *(uint *)(uRam0211f6e4 & 0xfffffffc) << (uRam0211f6e4 & 3) * -8 + 0x20) + param_1 + 0x1cc0) =
       param_2;
  return;
}

