/* Decompiled C draft; module arm9; ROM address 020add50. No matching claim. */
#include "types.h"
#include "deps/020add50_NFTR_SomeFn_2.h"

int NFTR_SomeFn_2(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = NFTR_SomeFn_3();
  uVar3 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 8;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  return param_2 * iVar2 + (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 8;
}

