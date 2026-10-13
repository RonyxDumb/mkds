/* Decompiled C draft; module arm9; ROM address 020169a4. No matching claim. */
#include "types.h"
#include "deps/020169a4_func_020169a4.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 func_020169a4(uint *param_1,uint *param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint local_14;
  uint uVar2;
  
  local_14 = param_3 + param_4;
  uVar2 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  uVar5 = param_3;
  while (uVar3 = uVar2, uVar3 != 0) {
    uVar7 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
    uVar2 = uVar3 + 0xc & 3;
    uVar1 = *(uint *)(uVar3 + 0xc & 0xfffffffc);
    uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    if (uVar7 == param_3 + param_4) {
      uVar1 = uVar3 + 4 & 3;
      uVar4 = *(uint *)(uVar3 + 4 & 0xfffffffc);
      local_14 = uVar7 + (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
      uVar1 = uVar3 + 8 & 3;
      uVar7 = *(uint *)(uVar3 + 8 & 0xfffffffc);
      uVar1 = uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20;
      if (uVar1 == 0) {
        *param_1 = uVar2;
      }
      else {
        *(uint *)(uVar1 + 0xc) = uVar2;
      }
      if (uVar2 != 0) {
        *(uint *)(uVar2 + 8) = uVar1;
      }
      uVar1 = *(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
              *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20;
      if (uVar1 != 0) {
        *(uint *)(uVar1 + 8) = uVar3;
      }
      *(uint *)(uVar3 + 0xc) =
           *(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
           *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20;
      *(undefined4 *)(uVar3 + 8) = 0;
      *param_2 = uVar3;
    }
    uVar7 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
    uVar1 = uVar3 + 4 & 3;
    uVar4 = *(uint *)(uVar3 + 4 & 0xfffffffc);
    if (param_3 == uVar7 + (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20)) {
      uVar5 = uVar3 + 8 & 3;
      uVar1 = *(uint *)(uVar3 + 8 & 0xfffffffc);
      uVar4 = uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20;
      uVar5 = uVar3 + 0xc & 3;
      uVar1 = *(uint *)(uVar3 + 0xc & 0xfffffffc);
      uVar5 = uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20;
      if (uVar4 == 0) {
        *param_1 = uVar5;
      }
      else {
        *(uint *)(uVar4 + 0xc) = uVar5;
      }
      if (uVar5 != 0) {
        *(uint *)(uVar5 + 8) = uVar4;
      }
      uVar5 = *(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
              *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20;
      if (uVar5 != 0) {
        *(uint *)(uVar5 + 8) = uVar3;
      }
      *(uint *)(uVar3 + 0xc) =
           *(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
           *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20;
      *(undefined4 *)(uVar3 + 8) = 0;
      *param_2 = uVar3;
      uVar5 = uVar7;
    }
  }
  puVar6 = (uint *)(*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
                   *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20);
  if (puVar6 != (uint *)0x0) {
    uVar2 = (uint)(puVar6 + 3) & 3;
    uVar3 = *(uint *)((uint)(puVar6 + 3) & 0xfffffffc);
    *param_2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
    *puVar6 = uVar5;
    puVar6[1] = local_14 - uVar5;
    puVar6[2] = 0;
    puVar6[3] = 0;
    uVar5 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
            *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
    if (uVar5 != 0) {
      *(uint **)(uVar5 + 8) = puVar6;
    }
    puVar6[3] = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
    puVar6[2] = 0;
    *param_1 = (uint)puVar6;
    return 1;
  }
  return 0;
}

