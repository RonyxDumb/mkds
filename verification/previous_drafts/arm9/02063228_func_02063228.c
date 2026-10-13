/* Decompiled C draft; module arm9; ROM address 02063228. No matching claim. */
#include "types.h"
#include "deps/02063228_func_02063228.h"

void func_02063228(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = iRam02063260 + 4U & 3;
  uVar1 = *(uint *)(iRam02063260 + 4U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 != 0) {
    func_020849f8(uVar2,uRam02063264,uRam02063268);
    return;
  }
  return;
}

