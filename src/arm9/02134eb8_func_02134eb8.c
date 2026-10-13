/* Decompiled C draft; module arm9; ROM address 02134eb8. No matching claim. */
#include "types.h"
#include "deps/02134eb8_func_02134eb8.h"

void func_02134eb8(uint *param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  if (param_3 != 0) {
    do {
      uVar2 = (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
              *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) & 0xff |
              (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
              *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) & 0xffffff00
      ;
      uVar1 = (4 - ((uint)param_1 & 3)) * 8 & 0x1f;
      param_2 = param_2 + 1;
      *param_1 = uVar2 >> uVar1 | uVar2 << 0x20 - uVar1;
      param_3 = param_3 + -1;
      param_1 = (uint *)((int)param_1 + 1);
    } while (param_3 != 0);
    return;
  }
  return;
}

