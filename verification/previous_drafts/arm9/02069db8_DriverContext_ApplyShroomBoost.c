/* Decompiled C draft; module arm9; ROM address 02069db8. No matching claim. */
#include "types.h"
#include "deps/02069db8_DriverContext_ApplyShroomBoost.h"

void DriverContext_ApplyShroomBoost(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  DriverContext_MaybeApplyBoost(param_1,0,0x5a);
  uVar1 = param_1 + 0x48U & 3;
  uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  *(uint *)(param_1 + 0x48) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 0x100000;
  uVar2 = uRam02069e0c;
  *(undefined2 *)(param_1 + 0x538) = 0x5a;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar1 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 8;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if ((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) == 2) {
    func_020a1ddc(*(undefined2 *)(param_1 + 0x74));
    return;
  }
  return;
}

