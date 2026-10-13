/* Decompiled C draft; module arm9; ROM address 0207a2d4. No matching claim. */
#include "types.h"
#include "deps/0207a2d4_func_0207a2d4.h"

void func_0207a2d4(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  
  puVar1 = puRam0207a308;
  uVar2 = *(uint *)((uint)piRam0207a304 & 0xfffffffc) >> ((uint)piRam0207a304 & 3) * 8 |
          *(uint *)((uint)piRam0207a304 & 0xfffffffc) << ((uint)piRam0207a304 & 3) * -8 + 0x20;
  if ((-1 < (int)uVar2) && ((int)uVar2 <= param_1)) {
    return;
  }
  *piRam0207a304 = param_1;
  *puVar1 = 1;
  return;
}

