/* Decompiled C draft; module arm9; ROM address 0214245c. No matching claim. */
#include "types.h"
#include "deps/0214245c_func_0214245c.h"

undefined4 func_0214245c(undefined4 param_1,int param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = *(uint *)((uint)param_3 & 0xfffffffc) >> ((uint)param_3 & 3) * 8 |
          *(uint *)((uint)param_3 & 0xfffffffc) << ((uint)param_3 & 3) * -8 + 0x20;
  uVar5 = 0;
  if (uVar4 != 0) {
    do {
      uVar1 = Semihost_Op7();
      puVar3 = (uint *)(param_2 + uVar5);
      uVar2 = uVar1 & 0xff |
              (*(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
              *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20) & 0xffffff00;
      uVar1 = (4 - ((uint)puVar3 & 3)) * 8 & 0x1f;
      *puVar3 = uVar2 >> uVar1 | uVar2 << 0x20 - uVar1;
      uVar1 = param_2 + uVar5 & 3;
      uVar2 = *(uint *)(param_2 + uVar5 & 0xfffffffc);
      uVar1 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xff;
      if ((uVar1 == 0xd) || (uVar1 == 10)) {
        *param_3 = uVar5 + 1;
        return 0;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar4);
  }
  return 0;
}

