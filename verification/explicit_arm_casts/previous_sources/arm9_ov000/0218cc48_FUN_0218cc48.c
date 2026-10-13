/* Decompiled C draft; module arm9_ov000; ROM address 0218cc48. No matching claim. */
#include "types.h"
#include "deps/0218cc48_FUN_0218cc48.h"

int FUN_0218cc48(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 1;
  do {
    iVar3 = iVar3 + -1;
    iVar1 = FUN_0218e420(*(undefined4 *)(param_1 + DAT_0218ccb8),param_2,param_3,0);
    if ((0 < iVar1) || (iVar3 < 0)) break;
    FUN_0218c980(param_1);
    iVar2 = FUN_0218ca58(param_1,0,0,2,0);
    if (iVar2 != 0) {
      FUN_0218cf30(param_1);
      return iVar2;
    }
  } while (-1 < iVar3);
  if (iVar1 < 1) {
    return 3;
  }
  return 0;
}

