/* Decompiled C draft; module arm9; ROM address 021003e8. No matching claim. */
#include "types.h"
#include "deps/021003e8_func_021003e8.h"

void func_021003e8(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = DAT_02100458;
  if (3 < param_2) {
    return;
  }
  switch(param_2) {
  case 1:
    *(uint *)(param_1 + 0x264) = param_3;
    return;
  case 2:
    *(int *)(param_1 + 0x254) = (int)param_3 >> 2;
    *(uint *)(param_1 + 600) = param_3 & 3;
    return;
  case 3:
    *(int *)(param_1 + 0x25c) = (int)param_3 >> 2;
    *(uint *)(param_1 + 0x260) = param_3 & 3;
    return;
  }
  *(uint *)(param_1 + 0x250) = param_3;
  uVar2 = uVar1 & 3;
  uVar3 = *(uint *)(uVar1 & 0xfffffffc);
  uVar1 = param_1 + 0x250U & 3;
  uVar4 = *(uint *)(param_1 + 0x250U & 0xfffffffc);
  if ((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) ==
      (int)*(char *)((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + 0x62)) {
    *(undefined4 *)(param_1 + 0x24c) = 1;
  }
  return;
}

