/* Decompiled C draft; module arm9_ov000; ROM address 02190aa8. No matching claim. */
#include "types.h"
#include "deps/02190aa8_FUN_02190aa8.h"

undefined4
FUN_02190aa8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5,int *param_6,char *param_7)

{
  int iVar1;
  
  iVar1 = FUN_0218e420(param_2,param_3,param_4,0);
  if (iVar1 == -1) {
    iVar1 = FUN_0218e368(param_2);
    if (((iVar1 != -6) && (iVar1 != -0x1a)) && (iVar1 != -0x4c)) {
      if ((*param_7 == 'P') && (param_7[1] == 'R')) {
        return 3;
      }
      FUN_021965a0((int *)(uintptr_t)(param_1),5,DAT_02190b50);
      FUN_02190f4c((int *)(uintptr_t)(param_1),3,0);
      return 3;
    }
    *param_6 = 0;
    *param_5 = 0;
  }
  else if (iVar1 == 0) {
    FUN_0219690c(param_1,DAT_02190b54,param_7);
    *param_6 = 0;
    *param_5 = 1;
  }
  else {
    *param_6 = iVar1;
    *param_5 = 0;
  }
  return 0;
}

