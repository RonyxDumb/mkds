/* Decompiled C draft; module arm9; ROM address 020fd83c. No matching claim. */
#include "types.h"
#include "deps/020fd83c_func_020fd83c.h"

void func_020fd83c(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar1 = param_1 + 0x74U & 3;
  uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x80000) != 0) {
    return;
  }
  StateDualHandler_Create(param_1 + 0x184,uRam020fd8a4,4,param_1);
  uVar2 = uRam020fd8ac;
  uVar1 = param_1 + 0x74U & 3;
  uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x180000) == 0) {
    *(undefined4 *)(param_1 + 0x120) = uRam020fd8a8;
  }
  *(undefined2 *)(param_1 + 0x194) = 1;
  *(undefined2 *)(param_1 + 0x196) = 1;
  *(undefined4 *)(param_1 + 0x180) = uVar2;
  *(undefined4 *)(param_1 + 0x130) = 0;
  *(undefined4 *)(param_1 + 300) = 0;
  return;
}

