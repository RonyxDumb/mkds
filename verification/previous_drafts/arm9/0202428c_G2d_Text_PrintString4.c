/* Decompiled C draft; module arm9; ROM address 0202428c. No matching claim. */
#include "types.h"
#include "deps/0202428c_G2d_Text_PrintString4.h"

void G2d_Text_PrintString4
               (int param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,
               undefined4 param_6,uint param_7,undefined4 param_8)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  if ((param_7 & 0x100) == 0) {
    if ((param_7 & 0x80) != 0) {
      uVar1 = param_1 + 4U & 3;
      uVar3 = *(uint *)(param_1 + 4U & 0xfffffffc);
      uVar2 = param_1 + 0xcU & 3;
      uVar5 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
      iVar4 = NFTR_SomeFn_0(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,
                            uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20,param_8);
      param_3 = param_3 + ((param_5 + 1) / 2 - (iVar4 + 1) / 2);
    }
  }
  else {
    uVar1 = param_1 + 4U & 3;
    uVar3 = *(uint *)(param_1 + 4U & 0xfffffffc);
    uVar2 = param_1 + 0xcU & 3;
    uVar5 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    iVar4 = NFTR_SomeFn_0(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,
                          uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20,param_8);
    param_3 = param_3 + (param_5 - iVar4);
  }
  G2d_Text_SomeFn_0(param_1,param_2,param_3,param_4,param_6,param_7,param_8);
  return;
}

