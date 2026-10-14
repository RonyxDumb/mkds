/* Decompiled C draft; module arm9; ROM address 020b2e64. No matching claim. */
#include "types.h"
#include "deps/020b2e64_func_020b2e64.h"

void func_020b2e64(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = IsRaceOptionMenuOn_from_thumb();
  iVar2 = func_020b29c4();
  if (iVar2 != 0) {
    func_020b2f88(param_1);
  }
  iVar2 = IsRaceOptionMenuOn_from_thumb();
  if ((iVar1 == 0) && (iVar2 != 0)) {
    func_02105d70();
  }
  return;
}

