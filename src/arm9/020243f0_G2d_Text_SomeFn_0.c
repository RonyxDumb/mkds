/* Decompiled C draft; module arm9; ROM address 020243f0. No matching claim. */
#include "types.h"
#include "deps/020243f0_G2d_Text_SomeFn_0.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void G2d_Text_SomeFn_0(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,
                      uint param_6,int param_7)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar1 = param_1 + 4U & 3;
  uVar6 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar6 = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
  uVar1 = uVar6 & 3;
  uVar7 = *(uint *)(uVar6 & 0xfffffffc);
  uVar6 = param_1 + 0xcU & 3;
  uVar8 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  cVar2 = *(char *)((uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) + 1);
  if (param_7 != 0) {
    do {
      if ((param_6 & 0x800) == 0) {
        iVar4 = param_2;
        if ((param_6 & 0x400) != 0) {
          uVar1 = param_1 + 4U & 3;
          uVar3 = *(uint *)(param_1 + 4U & 0xfffffffc);
          uVar7 = param_1 + 8U & 3;
          uVar5 = *(uint *)(param_1 + 8U & 0xfffffffc);
          iVar4 = NFTR_GetStringWidth(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,
                                      uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20,param_7,0);
          iVar4 = param_2 + ((param_4 + 1) / 2 - (iVar4 + 1) / 2);
        }
      }
      else {
        uVar1 = param_1 + 4U & 3;
        uVar3 = *(uint *)(param_1 + 4U & 0xfffffffc);
        uVar7 = param_1 + 8U & 3;
        uVar5 = *(uint *)(param_1 + 8U & 0xfffffffc);
        iVar4 = NFTR_GetStringWidth(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,
                                    uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20,param_7,0);
        iVar4 = param_2 + (param_4 - iVar4);
      }
      G2d_Text_PutChars(param_1,iVar4,param_3,param_5);
      param_3 = param_3 + (uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) + (int)cVar2;
    } while (param_7 != 0);
    return;
  }
  return;
}

