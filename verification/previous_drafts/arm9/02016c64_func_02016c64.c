/* Decompiled C draft; module arm9; ROM address 02016c64. No matching claim. */
#include "types.h"
#include "deps/02016c64_func_02016c64.h"

undefined4 func_02016c64(undefined4 *param_1,uint *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)
           (*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
           *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20);
  if (puVar3 == (undefined4 *)0x0) {
    return 0;
  }
  uVar1 = (uint)(puVar3 + 3) & 3;
  uVar2 = *(uint *)((uint)(puVar3 + 3) & 0xfffffffc);
  *param_2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  *puVar3 = param_3;
  puVar3[1] = param_4;
  puVar3[2] = 0;
  puVar3[3] = 0;
  uVar1 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  if (uVar1 != 0) {
    *(undefined4 **)(uVar1 + 8) = puVar3;
  }
  puVar3[3] = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
              *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  puVar3[2] = 0;
  *param_1 = puVar3;
  return 1;
}

