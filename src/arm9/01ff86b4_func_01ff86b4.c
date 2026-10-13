/* Decompiled C draft; module arm9; ROM address 01ff86b4. No matching claim. */
#include "types.h"
#include "deps/01ff86b4_func_01ff86b4.h"

void func_01ff86b4(int *param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar3;
  uint uVar2;
  uint uVar4;
  
  uVar2 = (uint)(param_1 + 2) & 3;
  uVar1 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (((uVar2 & 0x200) == 0) &&
     (((uVar1 = (uint)*(byte *)((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                                *(uint *)((uint)param_1 & 0xfffffffc) <<
                                ((uint)param_1 & 3) * -8 + 0x20) + 1), (uVar2 & 1) != 0 ||
       ((uVar2 & 8) == 0)) || (uVar1 != *(byte *)((int)param_1 + 0xad))))) {
    uVar2 = (uint)(param_1 + 0x36) & 3;
    uVar3 = *(uint *)((uint)(param_1 + 0x36) & 0xfffffffc);
    uVar4 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
    uVar2 = *(ushort *)(uVar4 + 4 + (uint)*(ushort *)(uVar4 + 10)) * uVar1 +
            uVar4 + 4 + (uint)*(ushort *)(uVar4 + 10) + 4;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar3 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    uVar2 = iRam01ff8734 + (uint)*(ushort *)(uVar4 + uVar3) * 4;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    (*(code *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20))(param_1,param_2,uVar4 + uVar3);
  }
  *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
             *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 2;
  return;
}

