/* Decompiled C draft; module arm9; ROM address 0206bab8. No matching claim. */
#include "types.h"
#include "deps/0206bab8_func_0206bab8.h"

undefined4 func_0206bab8(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = func_0206be54(param_1,6);
  if (iVar1 != 0) {
    StructMQRacerEntry_SomeFn(param_1);
    uVar3 = param_1 + 0x7cU & 3;
    uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0x200) != 0) {
      uVar3 = param_1 + 0x514U & 3;
      uVar2 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
      uVar4 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      uVar3 = uVar4 + 0x2c;
      uVar2 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      *(uint *)(uVar4 + 0x2c) = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) ^ 0x20000;
    }
    return 1;
  }
  return 0;
}

