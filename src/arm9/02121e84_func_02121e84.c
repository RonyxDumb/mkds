/* Decompiled C draft; module arm9; ROM address 02121e84. No matching claim. */
#include "types.h"
#include "deps/02121e84_func_02121e84.h"

void func_02121e84(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = func_0x0219bb50();
  *(undefined4 *)
   (iVar1 * 0x44 +
    (*(uint *)(uRam02121eb0 & 0xfffffffc) >> (uRam02121eb0 & 3) * 8 |
    *(uint *)(uRam02121eb0 & 0xfffffffc) << (uRam02121eb0 & 3) * -8 + 0x20) + 0x1e48) = param_1;
  return;
}

