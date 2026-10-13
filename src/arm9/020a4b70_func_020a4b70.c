/* Decompiled C draft; module arm9; ROM address 020a4b70. No matching claim. */
#include "types.h"
#include "deps/020a4b70_func_020a4b70.h"

void func_020a4b70(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  iVar1 = func_020a2378();
  if (param_2 == 0) {
    return;
  }
  iVar2 = func_020a2204(param_1);
  iVar3 = func_020a1154(param_1);
  iVar3 = iVar3 + (uint)(iVar2 != 0);
  iVar2 = 0;
  if (0 < iVar3) {
    do {
      uVar7 = param_1 * 0x38 + iVar1 + iVar2 * 4 + 0x10;
      uVar5 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      uVar8 = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20;
      iVar2 = iVar2 + 1;
      uVar7 = uVar8 + 4 & 3;
      uVar5 = *(uint *)(uVar8 + 4 & 0xfffffffc);
      *(uint *)(uVar8 + 4) =
           (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) +
           (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
           *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20);
      uVar7 = uVar8 + 8 & 3;
      uVar6 = *(uint *)(uVar8 + 8 & 0xfffffffc);
      uVar5 = param_2 + 4 & 3;
      uVar4 = *(uint *)(param_2 + 4 & 0xfffffffc);
      *(uint *)(uVar8 + 8) =
           (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) +
           (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
      uVar7 = uVar8 + 0xc & 3;
      uVar6 = *(uint *)(uVar8 + 0xc & 0xfffffffc);
      uVar5 = param_2 + 8 & 3;
      uVar4 = *(uint *)(param_2 + 8 & 0xfffffffc);
      *(uint *)(uVar8 + 0xc) =
           (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) +
           (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
    } while (iVar2 < iVar3);
    return;
  }
  return;
}

