/* Decompiled C draft; module arm7; ROM address 0380076c. No matching claim. */
#include "types.h"
#include "deps/0380076c_FUN_0380076c.h"

bool FUN_0380076c(ushort *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  ushort *puVar4;
  
  iVar3 = (uint)*DAT_038007bc - (uint)*param_1;
  if (iVar3 != 0) {
    *param_1 = *DAT_038007bc;
    puVar4 = param_1 + 2;
    uVar1 = (uint)(param_1 + 2) & 3;
    uVar2 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    *(uint *)(param_1 + 2) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) - iVar3;
    if (iVar3 < 0) {
      *(uint *)puVar4 =
           (*(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
           *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20) - DAT_038007c0;
    }
  }
  uVar1 = (uint)(param_1 + 2) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  return 0 < (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
}

