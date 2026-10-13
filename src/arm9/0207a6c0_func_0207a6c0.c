/* Decompiled C draft; module arm9; ROM address 0207a6c0. No matching claim. */
#include "types.h"
#include "deps/0207a6c0_func_0207a6c0.h"

void func_0207a6c0(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if ((uint)*(ushort *)(param_1 + 0x74) !=
      (int)*(char *)((*(uint *)(uRam0207a704 & 0xfffffffc) >> (uRam0207a704 & 3) * 8 |
                     *(uint *)(uRam0207a704 & 0xfffffffc) << (uRam0207a704 & 3) * -8 + 0x20) + 0x62)
     ) {
    return;
  }
  uVar1 = param_1 + 0x4cU & 3;
  uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x40) == 0) {
    uVar1 = param_1 + 0x48U & 3;
    uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x20000000) == 0) {
      uVar3 = *(uint *)(uRam0207a708 & 0xfffffffc) >> (uRam0207a708 & 3) * 8 |
              *(uint *)(uRam0207a708 & 0xfffffffc) << (uRam0207a708 & 3) * -8 + 0x20;
      uVar1 = uVar3 + 0xc;
      uVar2 = uVar1 & 3;
      uVar1 = *(uint *)(uVar1 & 0xfffffffc);
      *(uint *)(uVar3 + 0xc) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 1;
    }
    return;
  }
  return;
}

