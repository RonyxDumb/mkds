/* Decompiled C draft; module arm7; ROM address 038009ec. No matching claim. */
#include "types.h"
#include "deps/038009ec_FUN_038009ec.h"

void FUN_038009ec(int param_1)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar5;
  
  puVar3 = DAT_03800ae0;
  uVar2 = DAT_03800adc;
  iVar1 = DAT_03800ad8;
  do {
    while( true ) {
      uVar5 = iVar1 + 0x20U & 3;
      uVar4 = *(uint *)(iVar1 + 0x20U & 0xfffffffc);
      uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
      uVar4 = uVar5 & 0xfffffe00;
      if (((uVar4 != uVar5) ||
          (uVar5 = iVar1 + 0x24U & 3, uVar9 = *(uint *)(iVar1 + 0x24U & 0xfffffffc),
          uVar5 = uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20, (uVar5 & 3) != 0)) ||
         (uVar9 = iVar1 + 0x28U & 3, uVar6 = *(uint *)(iVar1 + 0x28U & 0xfffffffc),
         (uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20) < 0x200)) {
        *(uint *)(param_1 + 8) = uVar4;
        uVar5 = param_1 + 0x20;
      }
      FUN_03800ae4(uVar4 >> 8 | 0xb7000000,0);
      uVar9 = 0;
      uVar4 = param_1 + 4U & 3;
      uVar6 = *(uint *)(param_1 + 4U & 0xfffffffc);
      *puVar3 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
      do {
        uVar4 = *(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
                *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20;
        if (((uVar4 & 0x800000) != 0) &&
           (uVar6 = uVar2 & 3, uVar8 = *(uint *)(uVar2 & 0xfffffffc), uVar9 < 0x200)) {
          *(uint *)(uVar5 + uVar9 * 4) = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
          uVar9 = uVar9 + 1;
        }
      } while ((uVar4 & 0x80000000) != 0);
      uVar4 = iVar1 + 0x24U & 3;
      uVar9 = *(uint *)(iVar1 + 0x24U & 0xfffffffc);
      if (uVar5 != (uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20)) break;
      uVar5 = iVar1 + 0x20U & 3;
      uVar4 = *(uint *)(iVar1 + 0x20U & 0xfffffffc);
      *(uint *)(iVar1 + 0x20) = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x200;
      uVar5 = iVar1 + 0x24U & 3;
      uVar4 = *(uint *)(iVar1 + 0x24U & 0xfffffffc);
      *(uint *)(iVar1 + 0x24) = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x200;
      uVar5 = iVar1 + 0x28U & 3;
      uVar4 = *(uint *)(iVar1 + 0x28U & 0xfffffffc);
      iVar7 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) - 0x200;
      *(int *)(iVar1 + 0x28) = iVar7;
      if (iVar7 == 0) {
        return;
      }
    }
    iVar7 = FUN_03800b84(param_1);
  } while (iVar7 != 0);
  return;
}

