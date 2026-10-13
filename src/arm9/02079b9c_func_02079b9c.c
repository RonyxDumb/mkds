/* Decompiled C draft; module arm9; ROM address 02079b9c. No matching claim. */
#include "types.h"
#include "deps/02079b9c_func_02079b9c.h"

void func_02079b9c(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar4 = param_1 + 0x14U & 3;
  uVar2 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  if (param_2 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = 0x1f;
  }
  uVar4 = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + 4;
  uVar2 = uVar4 & 3;
  uVar3 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = (*(uint *)(uRam02079bc4 & 0xfffffffc) >> (uRam02079bc4 & 3) * 8 |
          *(uint *)(uRam02079bc4 & 0xfffffffc) << (uRam02079bc4 & 3) * -8 + 0x20) + 0xc;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
                    /* WARNING: Could not recover jumptable at 0x02079bc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02079bc8)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20,
                   uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20,uVar5);
  return;
}

