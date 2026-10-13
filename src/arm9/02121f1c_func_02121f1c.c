/* Decompiled C draft; module arm9; ROM address 02121f1c. No matching claim. */
#include "types.h"
#include "deps/02121f1c_func_02121f1c.h"

void func_02121f1c(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = func_0x0219bb50();
  *(undefined4 *)
   (iVar1 * 0x44 +
    (*(uint *)(uRam02121f48 & 0xfffffffc) >> (uRam02121f48 & 3) * 8 |
    *(uint *)(uRam02121f48 & 0xfffffffc) << (uRam02121f48 & 3) * -8 + 0x20) + 0x1e40) = param_1;
  return;
}

