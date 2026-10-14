/* Decompiled C draft; module arm9; ROM address 02144514. No matching claim. */
#include "types.h"
#include "deps/02144514_func_02144514.h"

int func_02144514(undefined4 param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = Wm_GetGlobal();
  iVar2 = func_02142988(1,8);
  if (iVar2 != 0) {
    return iVar2;
  }
  uVar4 = iVar1 + 4U & 3;
  uVar3 = *(uint *)(iVar1 + 4U & 0xfffffffc);
  DC_InvalidateRangeNoClean((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x10,4);
  uVar4 = iVar1 + 4U & 3;
  uVar3 = *(uint *)(iVar1 + 4U & 0xfffffffc);
  uVar4 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x10;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if ((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) == 1) {
    return 3;
  }
  if (param_3 < 0x10) {
    return 6;
  }
  if (param_2 != 0) {
    DC_SomeClean(param_2,param_3);
    SetSomeFunctionPtr(0x11,param_1);
    iVar1 = WM_SomeFn(0x11,2,param_2,param_3);
    if (iVar1 == 0) {
      iVar1 = 2;
    }
    return iVar1;
  }
  return 6;
}

