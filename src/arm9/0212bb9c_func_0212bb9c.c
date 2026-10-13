/* Decompiled C draft; module arm9; ROM address 0212bb9c. No matching claim. */
#include "types.h"
#include "deps/0212bb9c_func_0212bb9c.h"

int func_0212bb9c(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 1;
  iVar1 = 0;
  do {
    if (((*(uint *)((uint)puRam0212bbdc & 0xfffffffc) >> ((uint)puRam0212bbdc & 3) * 8 |
         *(uint *)((uint)puRam0212bbdc & 0xfffffffc) << ((uint)puRam0212bbdc & 3) * -8 + 0x20) &
        uVar2) == 0) {
      *puRam0212bbdc =
           *(uint *)((uint)puRam0212bbdc & 0xfffffffc) >> ((uint)puRam0212bbdc & 3) * 8 |
           *(uint *)((uint)puRam0212bbdc & 0xfffffffc) << ((uint)puRam0212bbdc & 3) * -8 + 0x20 |
           uVar2;
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    uVar2 = uVar2 << 1;
  } while (iVar1 < 8);
  return -1;
}

