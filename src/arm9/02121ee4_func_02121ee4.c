/* Decompiled C draft; module arm9; ROM address 02121ee4. No matching claim. */
#include "types.h"
#include "deps/02121ee4_func_02121ee4.h"

void func_02121ee4(void)

{
  int iVar1;
  
  iVar1 = func_0x0219bb50();
  *(undefined4 *)
   (iVar1 * 0x44 +
    (*(uint *)(uRam02121f18 & 0xfffffffc) >> (uRam02121f18 & 3) * 8 |
    *(uint *)(uRam02121f18 & 0xfffffffc) << (uRam02121f18 & 3) * -8 + 0x20) + 0x1e40) = 0xffffffff;
  return;
}

