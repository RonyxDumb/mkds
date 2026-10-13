/* Decompiled C draft; module arm9_ov000; ROM address 0218f268. No matching claim. */
#include "types.h"
#include "deps/0218f268_FUN_0218f268.h"

undefined4 FUN_0218f268(int *param_1)

{
  undefined4 uVar1;
  
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    if (*(int *)(*param_1 + DAT_0218f29c) != 0) {
      return 0;
    }
    uVar1 = FUN_0218f2e8(param_1,0);
    return uVar1;
  }
  return 2;
}

