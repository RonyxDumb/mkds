/* Decompiled C draft; module arm9; ROM address 0207bd6c. No matching claim. */
#include "types.h"
#include "deps/0207bd6c_func_0207bd6c.h"

void func_0207bd6c(int param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  
  uVar1 = *(ushort *)(param_2 + 0x40);
  uVar8 = (*(uint *)(uRam0207be3c & 0xfffffffc) >> (uRam0207be3c & 3) * 8 |
          *(uint *)(uRam0207be3c & 0xfffffffc) << (uRam0207be3c & 3) * -8 + 0x20) + 8;
  uVar2 = uVar8 & 3;
  uVar5 = *(uint *)(uVar8 & 0xfffffffc);
  uVar8 = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  iVar7 = (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) + (uint)uVar1 * 4;
  uVar2 = (uint)*(ushort *)(iVar7 + 2);
  if (3 < uVar2) {
    *(uint *)(param_1 + 0x38) = uVar2 - 1;
    uVar2 = 2;
    *(undefined4 *)(param_1 + 0x34) = 2;
    do {
      puVar3 = (undefined4 *)
               GetLoadedNkmPathEntryPOIT(*(undefined2 *)(param_2 + 0x40),uVar2 & 0xffff);
      uVar5 = uVar8 & 0xffff;
      uVar8 = (int)((uVar8 + 1) * 0x10000) >> 0x10;
      puVar9 = (undefined4 *)(uVar5 * 0xc + param_1);
      uVar4 = puVar3[1];
      uVar6 = puVar3[2];
      *puVar9 = *puVar3;
      puVar9[1] = uVar4;
      puVar9[2] = uVar6;
      uVar2 = (int)((uVar2 - 1) * 0x10000) >> 0x10;
    } while ((int)uVar8 < 3);
    puVar3 = (undefined4 *)
             GetLoadedNkmPathEntryPOIT(*(undefined2 *)(param_2 + 0x40),*(short *)(iVar7 + 2) + -1);
    uVar4 = puVar3[1];
    uVar6 = puVar3[2];
    *(undefined4 *)(param_1 + 0x24) = *puVar3;
    *(undefined4 *)(param_1 + 0x28) = uVar4;
    *(undefined4 *)(param_1 + 0x2c) = uVar6;
    return;
  }
  return;
}

