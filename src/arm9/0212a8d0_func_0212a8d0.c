/* Decompiled C draft; module arm9; ROM address 0212a8d0. No matching claim. */
#include "types.h"
#include "deps/0212a8d0_func_0212a8d0.h"

undefined4 func_0212a8d0(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  uVar2 = *(uint *)(uRam0212a90c & 0xfffffffc) >> (uRam0212a90c & 3) * 8 |
          *(uint *)(uRam0212a90c & 0xfffffffc) << (uRam0212a90c & 3) * -8 + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((-1 < (int)((uint)*(byte *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x31) << 0x1b)
      ) && (iVar3 = func_021213f4(), iVar3 != 0)) {
    uVar4 = 1;
  }
  return uVar4;
}

