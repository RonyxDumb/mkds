/* Decompiled C draft; module arm9; ROM address 020db4c4. No matching claim. */
#include "types.h"
#include "deps/020db4c4_func_020db4c4.h"

int func_020db4c4(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = func_020d8cac(param_1 + 200);
  uVar4 = param_1 + 0xa0U & 3;
  uVar3 = *(uint *)(param_1 + 0xa0U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if ((int)uVar4 < 4) {
    uVar4 = param_1 + 0xf0U & 3;
    uVar3 = *(uint *)(param_1 + 0xf0U & 0xfffffffc);
    if (uVar3 >> uVar4 * 8 == 0 && uVar3 << uVar4 * -8 + 0x20 == 0) {
      iVar1 = 0x1000;
    }
    else {
      iVar1 = 0;
    }
    return iVar1;
  }
  uVar3 = param_1 + 0xb4U & 3;
  uVar2 = *(uint *)(param_1 + 0xb4U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 != 0) {
    if (uVar3 == 2) {
      iVar1 = 0x1000;
    }
    return iVar1;
  }
  if (uVar4 == 4) {
    return 0x1000 - iVar1;
  }
  if (uVar4 == 5) {
    return 0;
  }
  return iVar1;
}

