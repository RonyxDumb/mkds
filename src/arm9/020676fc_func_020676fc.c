/* Decompiled C draft; module arm9; ROM address 020676fc. No matching claim. */
#include "types.h"
#include "deps/020676fc_func_020676fc.h"

undefined4 func_020676fc(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  func_02083f6c(0,param_1);
  uVar4 = param_1 + 0x48U & 3;
  uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  if (((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0x10000) == 0) {
    uVar2 = param_1 + 0x3e4U & 3;
    uVar3 = *(uint *)(param_1 + 0x3e4U & 0xfffffffc);
    uVar4 = (*(uint *)(uRam02067774 & 0xfffffffc) >> (uRam02067774 & 3) * 8 |
            *(uint *)(uRam02067774 & 0xfffffffc) << (uRam02067774 & 3) * -8 + 0x20) + 8;
    uVar1 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar4 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
    if ((uVar4 == 2) || (uVar4 == 4)) {
      func_020705fc(param_1,(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0xffff);
    }
    else {
      uVar4 = param_1 + 0x48U & 3;
      uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
      *(uint *)(param_1 + 0x48) = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20 | 0x10000;
      DriverContext_SomeFn_1(param_1,0);
    }
  }
  return 9;
}

