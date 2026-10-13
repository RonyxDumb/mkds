/* Decompiled C draft; module arm9; ROM address 02028dd4. No matching claim. */
#include "types.h"
#include "deps/02028dd4_func_02028dd4.h"

undefined2 func_02028dd4(void)

{
  undefined2 uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(uRam02028dfc & 0xfffffffc) >> (uRam02028dfc & 3) * 8 |
          *(uint *)(uRam02028dfc & 0xfffffffc) << (uRam02028dfc & 3) * -8 + 0x20;
  if ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) == 2) {
    uVar1 = *(undefined2 *)(uVar2 + 0x432);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

