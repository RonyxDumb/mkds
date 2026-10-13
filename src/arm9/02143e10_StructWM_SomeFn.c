/* Decompiled C draft; module arm9; ROM address 02143e10. No matching claim. */
#include "types.h"
#include "deps/02143e10_StructWM_SomeFn.h"

int StructWM_SomeFn(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = Wm_Initialize(param_1,param_3);
  if (iVar2 == 0) {
    SetSomeFunctionPtr(0,param_2);
    uVar3 = Wm_GetGlobal();
    uVar1 = uVar3 + 4 & 3;
    uVar4 = *(uint *)(uVar3 + 4 & 0xfffffffc);
    iVar2 = WM_SomeFn(0,3,*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20,
                      uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
    if (iVar2 == 0) {
      iVar2 = 2;
    }
    return iVar2;
  }
  return iVar2;
}

