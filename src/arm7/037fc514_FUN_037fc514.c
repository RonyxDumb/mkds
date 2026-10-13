/* Decompiled C draft; module arm7; ROM address 037fc514. No matching claim. */
#include "types.h"
#include "deps/037fc514_FUN_037fc514.h"

undefined4 FUN_037fc514(int param_1,int param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (*(short *)(param_1 + 0x32) == 0) {
    uVar2 = 0;
  }
  else {
    uVar5 = param_1 + 0x14U & 3;
    uVar3 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
    uVar3 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
    uVar5 = param_1 + 0x18U & 3;
    uVar4 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
    uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    if ((int)uVar3 < (int)uVar5) {
      lVar1 = (longlong)(int)*(short *)(param_1 + 0x32) * (longlong)(int)(uVar5 - uVar3);
      uVar2 = FUN_0380697c((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),uVar5,(int)uVar5 >> 0x1f);
      if ((param_2 != 0) && ((int)((uint)*(byte *)(param_1 + 3) << 0x1d) < 0)) {
        uVar5 = param_1 + 0x14U & 3;
        uVar3 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
        *(uint *)(param_1 + 0x14) = (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) + 1;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}

