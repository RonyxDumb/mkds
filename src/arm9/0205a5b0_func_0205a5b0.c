/* Decompiled C draft; module arm9; ROM address 0205a5b0. No matching claim. */
#include "types.h"
#include "deps/0205a5b0_func_0205a5b0.h"

void func_0205a5b0(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = uRam0205a628;
  iVar3 = param_1 * 0x88 +
          (*(uint *)(uRam0205a624 & 0xfffffffc) >> (uRam0205a624 & 3) * 8 |
          *(uint *)(uRam0205a624 & 0xfffffffc) << (uRam0205a624 & 3) * -8 + 0x20) + 0x16c;
  if (*(short *)(iVar3 + 0xc) == 0) {
    *(undefined4 *)(iVar3 + 4) = 0x13;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    func_020f4718((undefined4 *)(uintptr_t)(((int)*(char *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + param_1 + 6) &
                  0xffffU) * 0x210 +
                  (*(uint *)(uRam0205a62c & 0xfffffffc) >> (uRam0205a62c & 3) * 8 |
                  *(uint *)(uRam0205a62c & 0xfffffffc) << (uRam0205a62c & 3) * -8 + 0x20) + 0x30));
    return;
  }
  return;
}

