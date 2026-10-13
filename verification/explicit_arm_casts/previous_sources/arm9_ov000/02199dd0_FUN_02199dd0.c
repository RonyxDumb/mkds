/* Decompiled C draft; module arm9_ov000; ROM address 02199dd0. No matching claim. */
#include "types.h"
#include "deps/02199dd0_FUN_02199dd0.h"

undefined4 FUN_02199dd0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0xc) == 5) || (*(int *)(param_1 + 0xc) == 6)) {
    iVar1 = FUN_0218dc44(*(undefined4 *)(param_1 + 0x9c));
    if (iVar1 != 0) {
      iVar1 = FUN_02197fe8(param_1,0,param_2,param_3,1);
      if (iVar1 != 0) {
        return 1;
      }
      return 0;
    }
    iVar1 = FUN_02198258(param_1,param_2,param_3,1);
    if (iVar1 == 0) {
      return 0;
    }
  }
  else {
    iVar1 = FUN_02199fa4();
    if (iVar1 == 0) {
      return 0;
    }
  }
  return 1;
}

