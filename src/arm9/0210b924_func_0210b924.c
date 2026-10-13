/* Decompiled C draft; module arm9; ROM address 0210b924. No matching claim. */
#include "types.h"
#include "deps/0210b924_func_0210b924.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_0210b924(undefined4 param_1,undefined4 param_2)

{
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  local_20 = *puRam0210b984;
  uStack_18 = puRam0210b984[2];
  if (((*(uint *)(uRam0210b988 & 0xfffffffc) >> (uRam0210b988 & 3) * 8 |
       *(uint *)(uRam0210b988 & 0xfffffffc) << (uRam0210b988 & 3) * -8 + 0x20) & 1) != 0) {
    local_1c = param_1;
    local_14 = param_2;
    func_0210bf24(0,local_20,param_1,&local_20);
    return;
  }
  return;
}

