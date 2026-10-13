/* Decompiled C draft; module arm9; ROM address 01ff85d0. No matching claim. */
#include "types.h"
#include "deps/01ff85d0_func_01ff85d0.h"

void func_01ff85d0(int *param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar4;
  uint uVar3;
  
  uVar3 = (uint)(param_1 + 2) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if ((((uVar3 & 0x200) == 0) && ((uVar3 & 1) != 0)) && ((uVar3 & 2) == 0)) {
    uVar3 = (uint)(param_1 + 0x37) & 3;
    uVar2 = *(uint *)((uint)(param_1 + 0x37) & 0xfffffffc);
    uVar4 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    uVar3 = (uint)*(ushort *)(uVar4 + *(ushort *)(uVar4 + 6)) *
            (uint)*(byte *)((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                            *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20
                            ) + 1) + uVar4 + *(ushort *)(uVar4 + 6) + 4;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar1 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
    uVar3 = iRam01ff8644 + (uint)*(ushort *)(uVar4 + uVar1) * 4;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    (*(code *)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20))(param_1,param_2,uVar4 + uVar1);
  }
  *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
             *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 2;
  return;
}

