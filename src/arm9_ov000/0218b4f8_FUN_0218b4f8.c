/* Decompiled C draft; module arm9_ov000; ROM address 0218b4f8. No matching claim. */
#include "types.h"
#include "deps/0218b4f8_FUN_0218b4f8.h"

void FUN_0218b4f8(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0218e374(param_2);
  FUN_0218ba10(param_1 + 0x4c,uVar1,param_3 >> 8 & 0xffU | param_3 << 8 & DAT_0218b52c & 0xffff,
               param_4);
  return;
}

