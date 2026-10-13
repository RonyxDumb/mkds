/* Decompiled C draft; module arm9; ROM address 020fd938. No matching claim. */
#include "types.h"
#include "deps/020fd938_func_020fd938.h"

void func_020fd938(int param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = param_1 + 0x1a0U & 3;
  uVar3 = *(uint *)(param_1 + 0x1a0U & 0xfffffffc);
  if (uVar3 >> uVar2 * 8 == 0 && uVar3 << uVar2 * -8 + 0x20 == 0) {
    return;
  }
  if (*(short *)(param_1 + 0x192) != 2) {
    uVar2 = param_1 + 0x174U & 3;
    uVar3 = *(uint *)(param_1 + 0x174U & 0xfffffffc);
    uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
    if ((uVar2 == 0) || (5 < (int)uVar2)) {
      *(undefined2 *)(param_3 + 0x18) = 0;
    }
    else {
      *(undefined2 *)(param_3 + 0x18) = 1;
    }
    func_020ed5c0(param_1,param_3,(undefined4 *)(uintptr_t)(param_2));
    return;
  }
  uVar2 = param_1 + 0x138U & 3;
  uVar3 = *(uint *)(param_1 + 0x138U & 0xfffffffc);
  uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  if (uVar2 != 0) {
    uVar3 = param_1 + 0x74U & 3;
    uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    *(uint *)(uVar2 + 0xb4) =
         (uint)(((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) & 0x10000) == 0);
    return;
  }
  return;
}

