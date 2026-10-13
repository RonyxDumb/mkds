/* Decompiled C draft; module arm9; ROM address 0210174c. No matching claim. */
#include "types.h"
#include "deps/0210174c_func_0210174c.h"

void func_0210174c(int param_1)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  
  uVar5 = param_1 + 0x248U & 3;
  uVar3 = *(uint *)(param_1 + 0x248U & 0xfffffffc);
  if (10 < (int)(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20)) {
    return;
  }
  iVar4 = func_020d849c(param_1 + 0x1a4);
  iVar2 = iRam02101898;
  if (iVar4 != 0) {
    piVar7 = (int *)(param_1 + 0x248);
    do {
      *piVar7 = (*(uint *)((uint)piVar7 & 0xfffffffc) >> ((uint)piVar7 & 3) * 8 |
                *(uint *)((uint)piVar7 & 0xfffffffc) << ((uint)piVar7 & 3) * -8 + 0x20) + 1;
      uVar5 = param_1 + 0x248U & 3;
      uVar3 = *(uint *)(param_1 + 0x248U & 0xfffffffc);
      uVar5 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
      if (10 < (int)uVar5) {
        return;
      }
      iVar4 = func_020f3fa8(param_1 + 0x1a4,uVar5 * 0xc + iVar2);
    } while (iVar4 != 0);
  }
  func_020d8488(param_1 + 0x1a4,&uStack_34);
  func_020d84c0(param_1 + 0x1a4,uStack_30);
  uVar5 = param_1 + 0xd0U & 3;
  uVar3 = *(uint *)(param_1 + 0xd0U & 0xfffffffc);
  if ((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) == param_1 + 0xc4U) {
    uStack_24 = 0;
    uStack_20 = 0;
    uStack_28 = uStack_34;
    uStack_40 = uStack_34;
    uStack_3c = 0;
    uStack_38 = 0;
  }
  else {
    uVar3 = func_020e6b28();
    lVar1 = (longlong)
            (int)(*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                 *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) *
            (longlong)(int)uStack_34;
    uStack_40 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar5 = uVar3 + 4 & 3;
    uVar6 = *(uint *)(uVar3 + 4 & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) *
            (longlong)(int)uStack_34;
    uStack_3c = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar5 = uVar3 + 8 & 3;
    uVar3 = *(uint *)(uVar3 + 8 & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) *
            (longlong)(int)uStack_34;
    uStack_38 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  }
  uStack_3c = uStack_3c + iStack_2c;
  VecFx32_Subtract(&uStack_40,param_1 + 0x16c,&uStack_34);
  VecFx32_AddScale1(uRam0210189c,&uStack_34,param_1 + 0x16c,param_1 + 0x16c);
  return;
}

