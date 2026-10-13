/* Decompiled C draft; module arm9; ROM address 02121eb4. No matching claim. */
#include "types.h"
#include "deps/02121eb4_func_02121eb4.h"

void func_02121eb4(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = func_0x0219bb50();
  *(undefined4 *)
   (iVar1 * 0x44 +
    (*(uint *)(uRam02121ee0 & 0xfffffffc) >> (uRam02121ee0 & 3) * 8 |
    *(uint *)(uRam02121ee0 & 0xfffffffc) << (uRam02121ee0 & 3) * -8 + 0x20) + 0x1e44) = param_1;
  return;
}

