/* Decompiled C draft; module arm7; ROM address 06018844. No matching claim. */
#include "types.h"
#include "deps/06018844_FUN_06018844.h"

void FUN_06018844(int param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = (*(uint *)(DAT_060188a0 & 0xfffffffc) >> (DAT_060188a0 & 3) * 8 |
          *(uint *)(DAT_060188a0 & 0xfffffffc) << (DAT_060188a0 & 3) * -8 + 0x20) + 0x318;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  if (uVar3 != 0) {
    iVar4 = uVar3 + param_1 + -0x2a;
    for (; param_2 != 0; param_2 = param_2 + -1) {
      uVar2 = FUN_060096c4(iVar4);
      iVar4 = iVar4 + 1;
      FUN_060096e4(param_3,uVar2);
      param_3 = param_3 + 1;
    }
  }
  return;
}

