/* Decompiled C draft; module arm9; ROM address 02061768. No matching claim. */
#include "types.h"
#include "deps/02061768_func_02061768.h"

undefined4 func_02061768(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = (*(uint *)(uRam02061784 & 0xfffffffc) >> (uRam02061784 & 3) * 8 |
          *(uint *)(uRam02061784 & 0xfffffffc) << (uRam02061784 & 3) * -8 + 0x20) + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 4) {
    uVar3 = 0x2d;
  }
  else {
    uVar3 = 0x1e;
  }
  return uVar3;
}

