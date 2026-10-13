/* Decompiled C draft; module arm9; ROM address 020d3d10. No matching claim. */
#include "types.h"
#include "deps/020d3d10_func_020d3d10.h"

undefined4 func_020d3d10(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = *(uint *)(uRam020d3d44 & 0xfffffffc) >> (uRam020d3d44 & 3) * 8 |
          *(uint *)(uRam020d3d44 & 0xfffffffc) << (uRam020d3d44 & 3) * -8 + 0x20;
  if ((uVar1 != 0) &&
     ((int)(param_1 -
           (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
           *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20)) < -0x32000)) {
    uVar2 = 1;
  }
  return uVar2;
}

