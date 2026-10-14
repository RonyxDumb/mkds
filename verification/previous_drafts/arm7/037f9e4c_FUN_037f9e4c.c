/* Decompiled C draft; module arm7; ROM address 037f9e4c. No matching claim. */
#include "types.h"
#include "deps/037f9e4c_FUN_037f9e4c.h"

int FUN_037f9e4c(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  int *piVar8;
  uint uVar7;
  
  FUN_037faf70();
  uVar6 = DAT_037f9ef0 + param_1 * 4;
  uVar1 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar7 = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
  puVar5 = (undefined4 *)(param_2 + 0x1fU & 0xffffffe0);
  iVar4 = 0;
  uVar6 = uVar7 + 4;
  uVar1 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  while( true ) {
    if ((int)(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) <= iVar4) {
      FUN_037faf84();
      return -1;
    }
    uVar3 = uVar7 + 0x10;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar3 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
    piVar8 = (int *)(uVar3 + iVar4 * 0xc);
    uVar3 = uVar3 + iVar4 * 0xc;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    if ((int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) < 0) break;
    iVar4 = iVar4 + 1;
  }
  *piVar8 = (param_3 & 0xffffffe0) - (int)puVar5;
  *puVar5 = 0;
  puVar5[1] = 0;
  puVar5[2] = *(uint *)((uint)piVar8 & 0xfffffffc) >> ((uint)piVar8 & 3) * 8 |
              *(uint *)((uint)piVar8 & 0xfffffffc) << ((uint)piVar8 & 3) * -8 + 0x20;
  piVar8[1] = (int)puVar5;
  piVar8[2] = 0;
  FUN_037faf84();
  return iVar4;
}

