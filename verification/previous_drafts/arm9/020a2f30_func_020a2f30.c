/* Decompiled C draft; module arm9; ROM address 020a2f30. No matching claim. */
#include "types.h"
#include "deps/020a2f30_func_020a2f30.h"

void func_020a2f30(int param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  *(undefined4 *)(param_1 + 0xa4) = param_2;
  *(int *)(param_1 + 0xd4) = -param_3;
  uVar1 = param_1 + 0xd0U & 3;
  uVar4 = *(uint *)(param_1 + 0xd0U & 0xfffffffc);
  uVar3 = param_1 + 0xd4U & 3;
  uVar2 = *(uint *)(param_1 + 0xd4U & 0xfffffffc);
  *(uint *)(param_1 + 0xd0) =
       (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) +
       (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
  *(undefined4 *)(param_1 + 0xfc) = 0;
  uVar1 = param_1 + 0xd0U & 3;
  uVar3 = *(uint *)(param_1 + 0xd0U & 0xfffffffc);
  if ((int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) < 1) {
    *(undefined4 *)(param_1 + 0xd8) = 0;
    *(undefined4 *)(param_1 + 0xd0) = 0;
    *(undefined4 *)(param_1 + 0xa4) = 0xffffffff;
    *(undefined4 *)(param_1 + 0xf4) = 1;
    *(undefined4 *)(param_1 + 0xf8) = 0;
    func_020d2398();
    return;
  }
  return;
}

