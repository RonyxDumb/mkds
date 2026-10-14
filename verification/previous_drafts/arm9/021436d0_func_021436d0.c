/* Decompiled C draft; module arm9; ROM address 021436d0. No matching claim. */
#include "types.h"
#include "deps/021436d0_func_021436d0.h"

int func_021436d0(undefined4 param_1,uint param_2)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  short *psVar6;
  
  iVar3 = Wm_GetGlobal();
  iVar4 = func_02142988(5,7,9,8);
  if (iVar4 != 0) {
    return iVar4;
  }
  uVar1 = iVar3 + 4U & 3;
  uVar5 = *(uint *)(iVar3 + 4U & 0xfffffffc);
  psVar6 = (short *)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20);
  sVar2 = *psVar6;
  if ((sVar2 == 7) || (sVar2 == 9)) {
    if ((param_2 == 0) || (0xf < param_2)) {
      return 6;
    }
    DC_InvalidateRangeNoClean((int)psVar6 + iRam021437d4,2);
    uVar1 = iVar3 + 4U & 3;
    uVar5 = *(uint *)(iVar3 + 4U & 0xfffffffc);
    if (((uint)*(ushort *)((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + 0x17e) &
        1 << (param_2 & 0xff)) == 0) {
      return 7;
    }
  }
  else if (param_2 != 0) {
    return 6;
  }
  SetSomeFunctionPtr(0xd,param_1);
  iVar3 = WM_SomeFn(0xd,1,1 << (param_2 & 0xff));
  if (iVar3 == 0) {
    iVar3 = 2;
  }
  return iVar3;
}

