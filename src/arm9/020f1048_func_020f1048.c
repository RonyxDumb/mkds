/* Decompiled C draft; module arm9; ROM address 020f1048. No matching claim. */
#include "types.h"
#include "deps/020f1048_func_020f1048.h"

void func_020f1048(uint param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  uint uVar1;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  uint uVar2;
  
  uVar3 = param_1 + 0x10 & 3;
  uVar5 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
  uVar2 = param_1 + 8 & 3;
  uVar1 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  iVar4 = (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) + param_2;
  if (((int)uVar2 < iVar4) && ((int)uVar2 < iVar4)) {
    do {
      uVar3 = param_1 + 0x14 & 3;
      uVar2 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
      if (0 < (int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
        uVar3 = param_1 + 4 & 3;
        uVar2 = *(uint *)(param_1 + 4 & 0xfffffffc);
        uVar2 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
        uVar3 = uVar2 & 3;
        uVar2 = *(uint *)(uVar2 & 0xfffffffc);
        func_020f0f70(param_1,uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
      }
      uVar3 = param_1 + 0x10 & 3;
      uVar5 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
      uVar2 = param_1 + 8 & 3;
      uVar1 = *(uint *)(param_1 + 8 & 0xfffffffc);
    } while ((int)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) <
             (int)((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) + param_2));
  }
  iVar4 = 0;
  if (0 < param_2) {
    piVar6 = (int *)(param_1 + 0x10);
    do {
      uVar3 = param_1 + 0x10 & 3;
      uVar5 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
      *piVar6 = (*(uint *)((uint)piVar6 & 0xfffffffc) >> ((uint)piVar6 & 3) * 8 |
                *(uint *)((uint)piVar6 & 0xfffffffc) << ((uint)piVar6 & 3) * -8 + 0x20) + 1;
      uVar2 = param_1 + 4 & 3;
      uVar1 = *(uint *)(param_1 + 4 & 0xfffffffc);
      uVar3 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) +
              (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) * 4;
      uVar2 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      *(uint *)(param_3 + iVar4 * 4) = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
      uVar3 = param_3 + iVar4 * 4;
      uVar2 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      func_020f99b8(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20,
                    *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                    *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20,param_4,(undefined4 *)(uintptr_t)(param_5));
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_2);
    return;
  }
  return;
}

