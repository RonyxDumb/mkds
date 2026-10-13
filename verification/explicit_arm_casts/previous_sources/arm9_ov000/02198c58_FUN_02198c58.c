/* Decompiled C draft; module arm9_ov000; ROM address 02198c58. No matching claim. */
#include "types.h"
#include "deps/02198c58_FUN_02198c58.h"

undefined4 FUN_02198c58(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((param_3 < 2) || (iVar1 = func_0x02134d30(param_2,DAT_02198d00,2), iVar1 != 0)) {
    iVar1 = FUN_02198714(param_1,param_2,param_3);
    if (iVar1 == 0) {
      return 0;
    }
    return 1;
  }
  iVar3 = param_3 + 2;
  iVar1 = FUN_02197e58(param_1 + 0x50);
  if (iVar1 < iVar3) {
    return 1;
  }
  iVar2 = *(int *)(param_1 + 0x50);
  iVar1 = *(int *)(param_1 + 0x58);
  FUN_02197d84(param_1 + 0x50,DAT_02198d00,2);
  FUN_02197d84(param_1 + 0x50,param_2,param_3);
  iVar1 = FUN_02198714(param_1,iVar2 + iVar1,iVar3);
  if (iVar1 == 0) {
    return 0;
  }
  FUN_02197d20(param_1 + 0x50,0xffffffff,iVar3);
  return 1;
}

