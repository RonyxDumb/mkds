/* Decompiled C draft; module arm9; ROM address 02143fbc. No matching claim. */
#include "types.h"
#include "deps/02143fbc_func_02143fbc.h"

int func_02143fbc(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = Wm_GetGlobal();
  iVar2 = func_02142988(2,9,10);
  if (iVar2 != 0) {
    return iVar2;
  }
  uVar4 = iVar1 + 4U & 3;
  uVar3 = *(uint *)(iVar1 + 4U & 0xfffffffc);
  DC_InvalidateRangeNoClean((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0xc,4);
  uVar4 = iVar1 + 4U & 3;
  uVar3 = *(uint *)(iVar1 + 4U & 0xfffffffc);
  uVar4 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0xc;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if (uVar4 >> uVar3 * 8 != 0 || uVar4 << uVar3 * -8 + 0x20 != 0) {
    SetSomeFunctionPtr(0x10,param_1);
    iVar1 = WM_SomeFn(0x10,0);
    if (iVar1 == 0) {
      iVar1 = 2;
    }
    return iVar1;
  }
  return 3;
}

