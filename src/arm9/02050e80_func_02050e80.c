/* Decompiled C draft; module arm9; ROM address 02050e80. No matching claim. */
#include "types.h"
#include "deps/02050e80_func_02050e80.h"

void func_02050e80(int param_1)

{
  uint uVar1;
  
  uVar1 = uRam02050ebc;
  *(undefined4 *)
   ((*(uint *)(uRam02050ebc & 0xfffffffc) >> (uRam02050ebc & 3) * 8 |
    *(uint *)(uRam02050ebc & 0xfffffffc) << (uRam02050ebc & 3) * -8 + 0x20) + 0x10) = 0;
  if (*(short *)(param_1 + 2) != 0) {
    *(undefined4 *)
     ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
      *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 8) = 8;
    *(undefined4 *)
     ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
      *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10) = 0;
    return;
  }
  *(undefined4 *)
   (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
   *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) = 0;
  return;
}

