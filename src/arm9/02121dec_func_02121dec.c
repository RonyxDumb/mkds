/* Decompiled C draft; module arm9; ROM address 02121dec. No matching claim. */
#include "types.h"
#include "deps/02121dec_func_02121dec.h"

void func_02121dec(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 2;
  }
  else {
    uVar2 = 1;
  }
  iVar1 = func_0x0219bb50();
  *(undefined4 *)
   (iVar1 * 0x44 +
    (*(uint *)(uRam02121e20 & 0xfffffffc) >> (uRam02121e20 & 3) * 8 |
    *(uint *)(uRam02121e20 & 0xfffffffc) << (uRam02121e20 & 3) * -8 + 0x20) + 0x1e50) = uVar2;
  return;
}

