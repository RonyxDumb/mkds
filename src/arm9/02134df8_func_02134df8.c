/* Decompiled C draft; module arm9; ROM address 02134df8. No matching claim. */
#include "types.h"
#include "deps/02134df8_func_02134df8.h"

void func_02134df8(uint *param_1,uint *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 <= param_2) {
    if (param_3 != 0) {
      do {
        uVar2 = (*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
                *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20) & 0xff |
                (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) &
                0xffffff00;
        uVar3 = (4 - ((uint)param_1 & 3)) * 8 & 0x1f;
        param_2 = (uint *)((int)param_2 + 1);
        *param_1 = uVar2 >> uVar3 | uVar2 << 0x20 - uVar3;
        param_3 = param_3 + -1;
        param_1 = (uint *)((int)param_1 + 1);
      } while (param_3 != 0);
      return;
    }
    return;
  }
  uVar3 = (int)param_2 + param_3;
  param_1 = (uint *)((int)param_1 + param_3);
  if (param_3 != 0) {
    do {
      uVar3 = uVar3 - 1;
      param_1 = (uint *)((int)param_1 + -1);
      uVar1 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) & 0xff |
              (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
              *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) & 0xffffff00
      ;
      uVar2 = (4 - ((uint)param_1 & 3)) * 8 & 0x1f;
      *param_1 = uVar1 >> uVar2 | uVar1 << 0x20 - uVar2;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
    return;
  }
  return;
}

