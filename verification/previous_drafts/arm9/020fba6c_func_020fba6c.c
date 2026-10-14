/* Decompiled C draft; module arm9; ROM address 020fba6c. No matching claim. */
#include "types.h"
#include "deps/020fba6c_func_020fba6c.h"

void func_020fba6c(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  *(undefined4 *)(param_1 + 0x264) = 0x5000;
  *(undefined2 *)(param_1 + 0x288) = 1000;
  VecFx32_Subtract(param_1 + 0x238,param_1 + 0x298,(int *)(uintptr_t)(param_1 + 0x28c));
  uVar1 = param_1 + 0x26cU & 3;
  uVar2 = *(uint *)(param_1 + 0x26cU & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    func_0208eb10();
    *(undefined4 *)(param_1 + 0x26c) = 0;
  }
  uVar1 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x8000000) != 0) {
    uVar1 = param_1 + 0x228U & 3;
    uVar2 = *(uint *)(param_1 + 0x228U & 0xfffffffc);
    func_020fe71c(5,*(undefined2 *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x1f8),
                  (int)*(short *)(param_1 + 0x4e));
    return;
  }
  return;
}

