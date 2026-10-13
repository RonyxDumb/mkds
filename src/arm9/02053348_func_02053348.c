/* Decompiled C draft; module arm9; ROM address 02053348. No matching claim. */
#include "types.h"
#include "deps/02053348_func_02053348.h"

void func_02053348(int param_1)

{
  uint uVar1;
  
  uVar1 = uRam0205339c;
  *(undefined4 *)
   ((*(uint *)(uRam0205339c & 0xfffffffc) >> (uRam0205339c & 3) * 8 |
    *(uint *)(uRam0205339c & 0xfffffffc) << (uRam0205339c & 3) * -8 + 0x20) + 0x10) = 0;
  if (*(short *)(param_1 + 2) != 0) {
    *(undefined4 *)
     ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
      *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 8) = 1;
    *(undefined4 *)
     ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
      *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10) = 0;
    return;
  }
  func_02053fa8();
  return;
}

