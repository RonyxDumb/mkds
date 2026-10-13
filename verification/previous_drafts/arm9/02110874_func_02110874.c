/* Decompiled C draft; module arm9; ROM address 02110874. No matching claim. */
#include "types.h"
#include "deps/02110874_func_02110874.h"

void func_02110874(void)

{
  uint uVar1;
  
  uVar1 = *(uint *)((uint)puRam021108a8 & 0xfffffffc) >> ((uint)puRam021108a8 & 3) * 8 |
          *(uint *)((uint)puRam021108a8 & 0xfffffffc) << ((uint)puRam021108a8 & 3) * -8 + 0x20;
  if (uVar1 == 7) {
    uVar1 = 6;
  }
  func_021108bc(uVar1);
  *puRam021108a8 = 7;
  return;
}

