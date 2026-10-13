/* Decompiled C draft; module arm9; ROM address 020a16d0. No matching claim. */
#include "types.h"
#include "deps/020a16d0_func_020a16d0.h"

void func_020a16d0(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(uRam020a1724 & 0xfffffffc) >> (uRam020a1724 & 3) * 8 |
          *(uint *)(uRam020a1724 & 0xfffffffc) << (uRam020a1724 & 3) * -8 + 0x20;
  uVar2 = uVar3 + 0x3b4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (-1 < (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20)) {
    return;
  }
  uVar2 = param_1 * 0x70 + uVar3 + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
    MaybeKillDriverDirect();
    func_020a1790();
    return;
  }
  return;
}

