/* Decompiled C draft; module arm9; ROM address 020a2ebc. No matching claim. */
#include "types.h"
#include "deps/020a2ebc_func_020a2ebc.h"

void func_020a2ebc(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  *(undefined4 *)(param_1 + 0xa0) = 0x1e;
  *(undefined4 *)(param_1 + 0xa4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xf4) = 1;
  *(undefined4 *)(param_1 + 0xf8) = 0;
  iVar2 = iRam020a2f08;
  if (param_2 == 0) {
    return;
  }
  *(uint *)(param_1 + 4) =
       *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
       *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
  uVar1 = param_2 + 4 & 3;
  uVar3 = *(uint *)(param_2 + 4 & 0xfffffffc);
  *(uint *)(param_1 + 8) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + iVar2;
  uVar1 = param_2 + 8 & 3;
  uVar3 = *(uint *)(param_2 + 8 & 0xfffffffc);
  *(uint *)(param_1 + 0xc) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  return;
}

