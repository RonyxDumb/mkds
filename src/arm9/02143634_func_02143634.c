/* Decompiled C draft; module arm9; ROM address 02143634. No matching claim. */
#include "types.h"
#include "deps/02143634_func_02143634.h"

int func_02143634(undefined4 param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = Wm_GetGlobal();
  iVar3 = func_02142988(2,7,9);
  if (iVar3 != 0) {
    return iVar3;
  }
  uVar1 = iVar2 + 4U & 3;
  uVar4 = *(uint *)(iVar2 + 4U & 0xfffffffc);
  DC_InvalidateRangeNoClean((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + iRam021436c8,2);
  uVar1 = iVar2 + 4U & 3;
  uVar4 = *(uint *)(iVar2 + 4U & 0xfffffffc);
  if ((uRam021436cc &
      *(ushort *)((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + 0x17e) & param_2) != 0) {
    SetSomeFunctionPtr(0xd,param_1);
    iVar2 = WM_SomeFn(0xd,1,param_2);
    if (iVar2 == 0) {
      iVar2 = 2;
    }
    return iVar2;
  }
  return 7;
}

