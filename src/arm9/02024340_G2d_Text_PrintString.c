/* Decompiled C draft; module arm9; ROM address 02024340. No matching claim. */
#include "types.h"
#include "deps/02024340_G2d_Text_PrintString.h"

void G2d_Text_PrintString
               (int param_1,int param_2,int param_3,undefined4 param_4,uint param_5,
               undefined4 param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int local_24;
  int iStack_20;
  
  uVar1 = param_1 + 4U & 3;
  uVar4 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar2 = param_1 + 8U & 3;
  uVar5 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar3 = param_1 + 0xcU & 3;
  uVar6 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  G2d_ComputeMaxWidthHeight
            (&local_24,uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20,
             uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20,
             uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20,param_6);
  if ((param_5 & 0x10) == 0) {
    if ((param_5 & 0x20) != 0) {
      param_2 = param_2 - local_24;
    }
  }
  else {
    param_2 = param_2 - (local_24 + 1) / 2;
  }
  if ((param_5 & 2) == 0) {
    if ((param_5 & 4) != 0) {
      param_3 = param_3 - iStack_20;
    }
  }
  else {
    param_3 = param_3 - (iStack_20 + 1) / 2;
  }
  G2d_Text_SomeFn_0(param_1,param_2,param_3,local_24,param_4,param_5,param_6);
  return;
}

