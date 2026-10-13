/* Decompiled C draft; module arm9; ROM address 02110640. No matching claim. */
#include "types.h"
#include "deps/02110640_func_02110640.h"

int func_02110640(uint param_1,int param_2)

{
  uint uVar1;
  int iVar3;
  uint uVar2;
  
  uVar2 = param_1 + 4 & 3;
  uVar1 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (param_2 == (int)uVar2 >> 0xc) {
    return -1;
  }
  if (param_2 < (int)uVar2 >> 0xc) {
    iVar3 = uVar2 - (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                    *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20);
    if (iVar3 >> 0xc < param_2) {
      iVar3 = param_2 << 0xc;
    }
  }
  else {
    iVar3 = uVar2 + (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                    *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20);
    if (param_2 < iVar3 >> 0xc) {
      iVar3 = param_2 << 0xc;
    }
  }
  *(int *)(param_1 + 4) = iVar3;
  uVar2 = param_1 + 4 & 3;
  uVar1 = *(uint *)(param_1 + 4 & 0xfffffffc);
  return (int)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) >> 0xc;
}

