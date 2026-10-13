/* Decompiled C draft; module arm9; ROM address 020e2ccc. No matching claim. */
#include "types.h"
#include "deps/020e2ccc_func_020e2ccc.h"

void func_020e2ccc(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar1 = param_1 + 0x38U & 3;
  uVar2 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
  uVar3 = (int)*(char *)((*(uint *)(uRam020e2d54 & 0xfffffffc) >> (uRam020e2d54 & 3) * 8 |
                         *(uint *)(uRam020e2d54 & 0xfffffffc) << (uRam020e2d54 & 3) * -8 + 0x20) +
                        0x62) & 0xffff;
  if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
    return;
  }
  if (7 < uVar3) {
    *(undefined4 *)(param_1 + 0x3c) = 0;
    return;
  }
  uVar3 = uVar3 * 0x210 +
          (*(uint *)(uRam020e2d58 & 0xfffffffc) >> (uRam020e2d58 & 3) * 8 |
          *(uint *)(uRam020e2d58 & 0xfffffffc) << (uRam020e2d58 & 3) * -8 + 0x20) + 0x1f0;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  func_020f3678(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,(int *)(uintptr_t)(param_1 + 0x2c));
  uVar4 = func_020e6b14();
  iVar5 = VecFx32_CrossProduct_0(param_1 + 0x2c,uVar4);
  *(uint *)(param_1 + 0x3c) = (uint)(iVar5 < 0);
  return;
}

