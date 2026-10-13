/* Decompiled C draft; module arm9; ROM address 02110c40. No matching claim. */
#include "types.h"
#include "deps/02110c40_func_02110c40.h"

undefined4 func_02110c40(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  iVar1 = func_02110e58();
  uVar4 = 0xffffffff;
  uVar2 = *(uint *)(uRam02110cbc & 0xfffffffc) >> (uRam02110cbc & 3) * 8 |
          *(uint *)(uRam02110cbc & 0xfffffffc) << (uRam02110cbc & 3) * -8 + 0x20;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 == 0x14) {
    if ((iVar1 == 0) || (uVar4 = uRam02110cc0, iVar1 == 1)) {
      uVar4 = 0x104;
    }
  }
  else if ((uVar3 == 0x19) && ((iVar1 == 0 || (uVar4 = uRam02110cc4, iVar1 == 1)))) {
    uVar4 = 0x19c;
  }
  return uVar4;
}

