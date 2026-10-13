/* Decompiled C draft; module arm9; ROM address 02056114. No matching claim. */
#include "types.h"
#include "deps/02056114_func_02056114.h"

void func_02056114(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = uRam02056140;
  uVar3 = uRam0205613c;
  *(undefined4 *)
   (*(uint *)(uRam0205613c & 0xfffffffc) >> (uRam0205613c & 3) * 8 |
   *(uint *)(uRam0205613c & 0xfffffffc) << (uRam0205613c & 3) * -8 + 0x20) = param_1;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    *(undefined4 *)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) = 0;
  }
  return;
}

