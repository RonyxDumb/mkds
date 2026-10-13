/* Decompiled C draft; module arm9; ROM address 0214fe10. No matching claim. */
#include "types.h"
#include "deps/0214fe10_Pm_GetBacklightFlagsImpl.h"

undefined4
Pm_GetBacklightFlagsImpl(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = func_021501d8();
  iVar3 = iRam0214fe84;
  uVar2 = uRam0214fe80;
  iVar1 = iRam0214fe7c;
  if (iVar4 != 0) {
    *(undefined2 *)(iRam0214fe78 + param_1 * 8) = 0;
    *(undefined4 *)(iVar1 + 4) = param_3;
    *(undefined4 *)(iVar1 + 8) = param_4;
    *(undefined4 *)(iVar3 + param_1 * 8) = param_2;
    func_0214fa7c(param_1 & 0xff | uVar2);
    return 0;
  }
  return 1;
}

