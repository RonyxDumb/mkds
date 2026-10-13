/* Decompiled C draft; module arm9_ov000; ROM address 02194370. No matching claim. */
#include "types.h"
#include "deps/02194370_FUN_02194370.h"

undefined4 FUN_02194370(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int local_18;
  
  if (param_2[0xc] != 0) {
    return 0;
  }
  iVar1 = FUN_0218dc44((undefined4 *)(uintptr_t)(param_2[0xe]));
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = FUN_0218dbf8((int *)(uintptr_t)(param_2[0xe]),0);
    iVar2 = FUN_021906e4(param_1,param_2[2],(int *)(uintptr_t)(iVar1),&local_18,0,DAT_021943ec);
    if ((local_18 != 0) || (iVar2 != 0)) break;
    if (*(int *)(iVar1 + 0xc) != *(int *)(iVar1 + 8)) {
      return 0;
    }
    FUN_0218da5c((int *)(uintptr_t)(param_2[0xe]),0);
    iVar1 = FUN_0218dc44((undefined4 *)(uintptr_t)(param_2[0xe]));
  }
  *param_2 = 0x6a;
  return 0;
}

