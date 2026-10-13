/* Decompiled C draft; module arm7; ROM address 0600abac. No matching claim. */
#include "types.h"
#include "deps/0600abac_FUN_0600abac.h"

undefined4 FUN_0600abac(uint param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar2 = *(uint *)(DAT_0600abf4 & 0xfffffffc) >> (DAT_0600abf4 & 3) * 8 |
          *(uint *)(DAT_0600abf4 & 0xfffffffc) << (DAT_0600abf4 & 3) * -8 + 0x20;
  if (param_1 < 0x81) {
    uVar4 = uVar2 + 0x3e0;
    uVar1 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    thunk_FUN_037fb230(param_2,uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20,param_1 + 1);
    *(short *)(uVar2 + 0x3e4) = (short)param_1;
    uVar3 = 0;
  }
  else {
    uVar3 = 4;
  }
  return uVar3;
}

