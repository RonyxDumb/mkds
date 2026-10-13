/* Decompiled C draft; module arm9_ov000; ROM address 0218a6c8. No matching claim. */
#include "types.h"
#include "deps/0218a6c8_FUN_0218a6c8.h"

undefined4 FUN_0218a6c8(undefined4 param_1)

{
  int iVar1;
  undefined1 auStack_20 [32];
  
  FUN_0218a5b0(param_1,auStack_20);
  iVar1 = func_0x02134d30(auStack_20,DAT_0218a6f0,8);
  if (iVar1 == 0) {
    return 1;
  }
  return 0;
}

