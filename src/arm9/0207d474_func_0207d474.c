/* Decompiled C draft; module arm9; ROM address 0207d474. No matching claim. */
#include "types.h"
#include "deps/0207d474_func_0207d474.h"

void func_0207d474(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (((*(ushort *)
         ((uint)*(ushort *)(param_2 + 4) * 0x30 +
          (*(uint *)(uRam0207d4c8 & 0xfffffffc) >> (uRam0207d4c8 & 3) * 8 |
          *(uint *)(uRam0207d4c8 & 0xfffffffc) << (uRam0207d4c8 & 3) * -8 + 0x20) + 0x84) & 1) != 0)
     && (uVar1 = param_1 + 0x20U & 3, uVar2 = *(uint *)(param_1 + 0x20U & 0xfffffffc),
        (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) < 0xc01)) {
    *(undefined4 *)(param_1 + 0x10) = 1;
    return;
  }
  func_0207d3a4();
  return;
}

