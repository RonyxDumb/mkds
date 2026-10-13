/* Decompiled C draft; module arm9; ROM address 0204a508. No matching claim. */
#include "types.h"
#include "deps/0204a508_func_0204a508.h"

int func_0204a508(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(uRam0204a528 & 0xfffffffc) >> (uRam0204a528 & 3) * 8 |
          *(uint *)(uRam0204a528 & 0xfffffffc) << (uRam0204a528 & 3) * -8 + 0x20;
  uVar2 = uVar4 + 0x10c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 6) {
    iVar3 = -1;
  }
  else {
    iVar3 = (int)*(short *)(uVar4 + 0x104);
  }
  return iVar3;
}

