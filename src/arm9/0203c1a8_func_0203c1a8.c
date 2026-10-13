/* Decompiled C draft; module arm9; ROM address 0203c1a8. No matching claim. */
#include "types.h"
#include "deps/0203c1a8_func_0203c1a8.h"

void func_0203c1a8(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int aiStack_10 [2];
  
  iVar2 = func_0204176c(param_1,aiStack_10);
  if (iVar2 == 0) {
    return;
  }
  if (aiStack_10[0] != 0) {
    uVar3 = (*(uint *)(uRam0203c23c & 0xfffffffc) >> (uRam0203c23c & 3) * 8 |
            *(uint *)(uRam0203c23c & 0xfffffffc) << (uRam0203c23c & 3) * -8 + 0x20) + 8;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    if ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) == 4) {
      func_0x021816fc();
    }
    uVar3 = (*(uint *)(uRam0203c23c & 0xfffffffc) >> (uRam0203c23c & 3) * 8 |
            *(uint *)(uRam0203c23c & 0xfffffffc) << (uRam0203c23c & 3) * -8 + 0x20) + 8;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    if ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) == 4) {
      func_0203e788(param_2,0);
      return;
    }
    return;
  }
  func_0203e788(param_2,6);
  return;
}

