/* Decompiled C draft; module arm9; ROM address 021463a4. No matching claim. */
#include "types.h"
#include "deps/021463a4_Card_DefaultRomAccess.h"

void Card_DefaultRomAccess(int param_1)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar5;
  
  puVar3 = puRam021464a0;
  uVar2 = uRam0214649c;
  iVar1 = iRam02146498;
  do {
    while( true ) {
      uVar5 = iVar1 + 0x1cU & 3;
      uVar4 = *(uint *)(iVar1 + 0x1cU & 0xfffffffc);
      uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
      uVar4 = uVar5 & 0xfffffe00;
      if (((uVar4 != uVar5) ||
          (uVar5 = iVar1 + 0x20U & 3, uVar10 = *(uint *)(iVar1 + 0x20U & 0xfffffffc),
          uVar5 = uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20, (uVar5 & 3) != 0)) ||
         (uVar10 = iVar1 + 0x24U & 3, uVar6 = *(uint *)(iVar1 + 0x24U & 0xfffffffc),
         (uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20) < 0x200)) {
        *(uint *)(param_1 + 8) = uVar4;
        uVar5 = param_1 + 0x20;
      }
      Card_WriteRomOperation(uVar4 >> 8 | 0xb7000000,0);
      uVar4 = param_1 + 4U & 3;
      uVar6 = *(uint *)(param_1 + 4U & 0xfffffffc);
      uVar10 = 0;
      *puVar3 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
      do {
        uVar4 = *(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
                *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20;
        if (((uVar4 & 0x800000) != 0) &&
           (uVar6 = uVar2 & 3, uVar8 = *(uint *)(uVar2 & 0xfffffffc), uVar10 < 0x200)) {
          *(uint *)(uVar5 + uVar10 * 4) = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
          uVar10 = uVar10 + 1;
        }
      } while ((uVar4 & 0x80000000) != 0);
      uVar4 = iVar1 + 0x20U & 3;
      uVar10 = *(uint *)(iVar1 + 0x20U & 0xfffffffc);
      if (uVar5 != (uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20)) break;
      uVar5 = iVar1 + 0x1cU & 3;
      uVar9 = *(uint *)(iVar1 + 0x1cU & 0xfffffffc);
      uVar4 = iVar1 + 0x20U & 3;
      uVar8 = *(uint *)(iVar1 + 0x20U & 0xfffffffc);
      uVar10 = iVar1 + 0x24U & 3;
      uVar6 = *(uint *)(iVar1 + 0x24U & 0xfffffffc);
      iVar7 = (uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20) - 0x200;
      *(uint *)(iVar1 + 0x1c) = (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20) + 0x200;
      *(uint *)(iVar1 + 0x20) = (uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20) + 0x200;
      *(int *)(iVar1 + 0x24) = iVar7;
      if (iVar7 == 0) {
        return;
      }
    }
    iVar7 = GlobalSZ_SomeFn(param_1);
  } while (iVar7 != 0);
  return;
}

