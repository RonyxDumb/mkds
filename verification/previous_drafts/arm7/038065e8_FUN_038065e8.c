/* Decompiled C draft; module arm7; ROM address 038065e8. No matching claim. */
#include "types.h"
#include "deps/038065e8_FUN_038065e8.h"

void FUN_038065e8(undefined4 param_1,uint param_2)

{
  int iVar1;
  
  if (param_2 == 0x10000) {
    iVar1 = FUN_0380653c();
    if (iVar1 != 0) {
      return;
    }
    param_2 = 0x10005;
  }
  else if (param_2 == 0x20000) {
    iVar1 = FUN_03806424();
    if (iVar1 != 0) {
      return;
    }
    param_2 = 0x20005;
  }
  else {
    param_2 = param_2 | 7;
  }
  do {
    iVar1 = FUN_037fb5f4(0xf,param_2,0);
  } while (iVar1 < 0);
  return;
}

