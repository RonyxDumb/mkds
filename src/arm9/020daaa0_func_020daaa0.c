/* Decompiled C draft; module arm9; ROM address 020daaa0. No matching claim. */
#include "types.h"
#include "deps/020daaa0_func_020daaa0.h"

void func_020daaa0(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  uVar1 = param_1 + 0x78U & 3;
  uVar2 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 4) == 0) {
    uVar1 = param_1 + 0x70U & 3;
    uVar2 = *(uint *)(param_1 + 0x70U & 0xfffffffc);
    uVar3 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    uVar1 = iRam020dab24 + 0x68U & 3;
    uVar2 = *(uint *)(iRam020dab24 + 0x68U & 0xfffffffc);
    if (uVar3 == (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20)) {
      local_10 = 2;
    }
    else {
      uVar1 = iRam020dab24 + 0x8cU & 3;
      uVar2 = *(uint *)(iRam020dab24 + 0x8cU & 0xfffffffc);
      if (uVar3 == (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20)) {
        local_10 = 3;
      }
      else {
        local_10 = 4;
      }
    }
    local_14 = param_1 + 4;
    local_18 = uRam020dab28;
    local_c = func_020d4ef4();
    func_0210b7a8((uint)(uintptr_t)(&local_18));
  }
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xfffe;
  *(undefined4 *)(param_1 + 200) = 0;
  return;
}

