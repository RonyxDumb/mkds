/* Decompiled C draft; module arm9_ov000; ROM address 02199614. No matching claim. */
#include "types.h"
#include "deps/02199614_FUN_02199614.h"

undefined4 FUN_02199614(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_20;
  
  uVar1 = FUN_0219a028(param_2,0);
  local_20 = uVar1;
  if (param_3 != 2) {
    if (param_3 != 4) {
      iVar2 = FUN_02199fa4(param_1);
      if (iVar2 == 0) {
        return 0;
      }
      return 1;
    }
    local_20 = FUN_0219a028(param_2,2);
  }
  iVar2 = FUN_0218dc44((undefined4 *)(uintptr_t)(*(undefined4 *)(param_1 + 0x60)));
  iVar5 = 0;
  if (0 < iVar2) {
    do {
      iVar3 = FUN_0218dbf8((int *)(uintptr_t)(*(undefined4 *)(param_1 + 0x60)),iVar5);
      iVar4 = FUN_0219a014(*(undefined2 *)(iVar3 + 8),uVar1);
      if (((-1 < iVar4) && (iVar4 = FUN_0219a014(*(undefined2 *)(iVar3 + 8),local_20), iVar4 < 1))
         && (iVar3 = FUN_02198af4(param_1,(int *)(uintptr_t)(iVar3)), iVar3 == 0)) {
        return 0;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar2);
  }
  return 1;
}

