/* Decompiled C draft; module arm9; ROM address 0207d3ec. No matching claim. */
#include "types.h"
#include "deps/0207d3ec_func_0207d3ec.h"

void func_0207d3ec(short *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (((*(ushort *)
         ((uint)*(ushort *)(param_2 + 4) * 0x30 +
          (*(uint *)(uRam0207d470 & 0xfffffffc) >> (uRam0207d470 & 3) * 8 |
          *(uint *)(uRam0207d470 & 0xfffffffc) << (uRam0207d470 & 3) * -8 + 0x20) + 0x84) & 1) != 0)
     && (uVar1 = (uint)(param_1 + 0x10) & 3, uVar2 = *(uint *)((uint)(param_1 + 0x10) & 0xfffffffc),
        (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) < 0x401)) {
    param_1[8] = 1;
    param_1[9] = 0;
    return;
  }
  *param_1 = *param_1 + -1;
  if (0 < *param_1) {
    return;
  }
  *param_1 = 0;
  func_0207cd74();
  return;
}

