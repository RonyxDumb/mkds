/* Decompiled C draft; module arm9; ROM address 020f91fc. No matching claim. */
#include "types.h"
#include "deps/020f91fc_func_020f91fc.h"

void func_020f91fc(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iStack_18;
  int iStack_14;
  undefined4 uStack_10;
  uint uStack_c;
  
  if (param_2 == 1) {
    return;
  }
  uVar1 = param_1 + 0xd4U & 3;
  uVar3 = *(uint *)(param_1 + 0xd4U & 0xfffffffc);
  uVar4 = iRam020f9288 + 0x44U & 3;
  uVar2 = *(uint *)(iRam020f9288 + 0x44U & 0xfffffffc);
  if ((int)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x3fffffe0) <
      (int)(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20)) {
    if (param_2 != 1) {
      uStack_10 = *(undefined4 *)(iRam020f928c + 8);
      iStack_14 = param_1 + 0x50;
      uVar1 = param_1 + 0xd4U & 3;
      uVar4 = *(uint *)(param_1 + 0xd4U & 0xfffffffc);
      uStack_c = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 0x3fffffe0;
      iStack_18 = param_2;
      func_0210b7a8(&iStack_18);
      return;
    }
    return;
  }
  return;
}

