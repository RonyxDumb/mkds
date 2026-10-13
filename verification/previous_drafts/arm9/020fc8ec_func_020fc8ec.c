/* Decompiled C draft; module arm9; ROM address 020fc8ec. No matching claim. */
#include "types.h"
#include "deps/020fc8ec_func_020fc8ec.h"

void func_020fc8ec(int param_1)

{
  uint uVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = param_1 + 0x228U & 3;
  uVar5 = *(uint *)(param_1 + 0x228U & 0xfffffffc);
  if (uVar5 >> uVar4 * 8 == 0 && uVar5 << uVar4 * -8 + 0x20 == 0) {
    func_020fcb9c();
    uVar4 = param_1 + 0x228U & 3;
    uVar3 = *(uint *)(param_1 + 0x228U & 0xfffffffc);
    uVar5 = param_1 + 0x74U & 3;
    uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    uVar4 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x1fc;
    uVar3 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    if ((((uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) & 0x40000000) == 0) &&
       (uVar4 = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + 0x48, uVar5 = uVar4 & 3,
       uVar4 = *(uint *)(uVar4 & 0xfffffffc),
       ((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 1) == 0)) {
      uVar2 = 3;
    }
    else {
      uVar2 = 2;
    }
    *(undefined2 *)(param_1 + 0x2f8) = uVar2;
    *(undefined2 *)(param_1 + 0x2fa) = 1;
    return;
  }
  return;
}

