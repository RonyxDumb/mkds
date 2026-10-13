/* Decompiled C draft; module arm9; ROM address 0214544c. No matching claim. */
#include "types.h"
#include "deps/0214544c_func_0214544c.h"

int func_0214544c(undefined4 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
                 undefined2 param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined2 *puVar5;
  
  iVar2 = Wm_GetGlobal();
  iVar3 = func_02142988(1,2);
  if (iVar3 == 0) {
    SetSomeFunctionPtr(0x1e,param_1);
    uVar1 = iVar2 + 0xcU & 3;
    uVar4 = *(uint *)(iVar2 + 0xcU & 0xfffffffc);
    puVar5 = (undefined2 *)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
    *puVar5 = 0x1e;
    puVar5[1] = param_2;
    puVar5[2] = param_3;
    puVar5[3] = param_4;
    puVar5[4] = param_5;
    iVar2 = WM_SomeFn(0x1e,0);
    if (iVar2 == 0) {
      iVar2 = 2;
    }
    return iVar2;
  }
  return iVar3;
}

