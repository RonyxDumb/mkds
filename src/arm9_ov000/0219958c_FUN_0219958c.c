/* Decompiled C draft; module arm9_ov000; ROM address 0219958c. No matching claim. */
#include "types.h"
#include "deps/0219958c_FUN_0219958c.h"

undefined4 FUN_0219958c(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x34) == 0) {
    return 1;
  }
  if (param_3 != 8) {
    return 1;
  }
  iVar1 = func_0x02134d30(param_2,DAT_02199608,4);
  if (iVar1 != 0) {
    return 1;
  }
  iVar1 = *(int *)(param_2 + 4);
  iVar2 = FUN_0218e8c4();
  iVar1 = FUN_02198148(param_1,iVar2 - iVar1);
  if (iVar1 != 0) {
    return 1;
  }
  return 0;
}

