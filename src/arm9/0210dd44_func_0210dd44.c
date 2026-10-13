/* Decompiled C draft; module arm9; ROM address 0210dd44. No matching claim. */
#include "types.h"
#include "deps/0210dd44_func_0210dd44.h"

void func_0210dd44(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  uint uVar6;
  int iVar7;
  
  uVar6 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  iVar7 = 0;
  if (0 < (int)uVar6) {
    do {
      uVar2 = param_1 + 4 & 3;
      uVar1 = *(uint *)(param_1 + 4 & 0xfffffffc);
      iVar3 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + iVar7 * 0x10;
      uVar2 = iVar3 + 4U & 3;
      uVar1 = *(uint *)(iVar3 + 4U & 0xfffffffc);
      pcVar5 = (code *)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
      if (pcVar5 == (code *)0x0) break;
      uVar6 = iVar3 + 8U & 3;
      uVar1 = *(uint *)(iVar3 + 8U & 0xfffffffc);
      uVar2 = iVar3 + 0xcU & 3;
      uVar4 = *(uint *)(iVar3 + 0xcU & 0xfffffffc);
      (*pcVar5)(uVar1 >> uVar6 * 8 | uVar1 << uVar6 * -8 + 0x20,
                uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
      uVar6 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
              *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
      iVar7 = iVar7 + 1;
    } while (iVar7 < (int)uVar6);
  }
  iVar7 = 0;
  if (0 < (int)uVar6) {
    do {
      uVar6 = param_1 + 4 & 3;
      uVar2 = *(uint *)(param_1 + 4 & 0xfffffffc);
      *(undefined4 *)((uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) + iVar7 * 0x10) = 0xffffffff
      ;
      uVar6 = param_1 + 4 & 3;
      uVar2 = *(uint *)(param_1 + 4 & 0xfffffffc);
      *(undefined4 *)((uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) + iVar7 * 0x10 + 4) = 0;
      uVar6 = param_1 + 4 & 3;
      uVar2 = *(uint *)(param_1 + 4 & 0xfffffffc);
      *(undefined4 *)((uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) + iVar7 * 0x10 + 8) = 0;
      uVar6 = param_1 + 4 & 3;
      uVar2 = *(uint *)(param_1 + 4 & 0xfffffffc);
      *(undefined4 *)((uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) + iVar7 * 0x10 + 0xc) = 0;
      iVar7 = iVar7 + 1;
    } while (iVar7 < (int)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20));
    return;
  }
  return;
}

