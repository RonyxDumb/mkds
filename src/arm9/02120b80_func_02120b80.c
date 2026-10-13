/* Decompiled C draft; module arm9; ROM address 02120b80. No matching claim. */
#include "types.h"
#include "deps/02120b80_func_02120b80.h"

undefined4 func_02120b80(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = func_0x021a2a88(param_1,(*(uint *)(uRam02120c24 & 0xfffffffc) >> (uRam02120c24 & 3) * 8 |
                                  *(uint *)(uRam02120c24 & 0xfffffffc) <<
                                  (uRam02120c24 & 3) * -8 + 0x20) + iRam02120c28,5);
  uVar2 = func_0x021a2a88(param_1,(*(uint *)(uRam02120c24 & 0xfffffffc) >> (uRam02120c24 & 3) * 8 |
                                  *(uint *)(uRam02120c24 & 0xfffffffc) <<
                                  (uRam02120c24 & 3) * -8 + 0x20) + iRam02120c2c,3);
  if ((iVar1 == 5) || (uVar2 == 3)) {
    return 0;
  }
  if ((iVar1 == 3) &&
     ((*(byte *)((*(uint *)(uRam02120c24 & 0xfffffffc) >> (uRam02120c24 & 3) * 8 |
                 *(uint *)(uRam02120c24 & 0xfffffffc) << (uRam02120c24 & 3) * -8 + 0x20) + 0x450) &
      0xf) == uVar2)) {
    return 1;
  }
  return 0;
}

