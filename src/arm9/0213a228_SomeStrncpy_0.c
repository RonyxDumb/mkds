/* Decompiled C draft; module arm9; ROM address 0213a228. No matching claim. */
#include "types.h"
#include "deps/0213a228_SomeStrncpy_0.h"

void SomeStrncpy_0(uint *param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  
  if (param_3 == 0) {
    return;
  }
  do {
    uVar2 = (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
            *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) & 0xff |
            (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
            *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) & 0xffffff00;
    uVar1 = (4 - ((uint)param_1 & 3)) * 8 & 0x1f;
    puVar3 = (uint *)((int)param_1 + 1);
    *param_1 = uVar2 >> uVar1 | uVar2 << 0x20 - uVar1;
    param_2 = param_2 + 1;
    if (((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
         *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) & 0xff) == 0) {
      param_3 = param_3 + -1;
      if (param_3 == 0) {
        return;
      }
      do {
        uVar2 = (*(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
                *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20) & 0xffffff00
        ;
        uVar1 = (4 - ((uint)puVar3 & 3)) * 8 & 0x1f;
        *puVar3 = uVar2 >> uVar1 | uVar2 << 0x20 - uVar1;
        param_3 = param_3 + -1;
        puVar3 = (uint *)((int)puVar3 + 1);
      } while (param_3 != 0);
      return;
    }
    param_3 = param_3 + -1;
    param_1 = puVar3;
  } while (param_3 != 0);
  return;
}

