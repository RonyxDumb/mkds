/* Decompiled C draft; module arm9_ov000; ROM address 0218acf4. No matching claim. */
#include "types.h"
#include "deps/0218acf4_FUN_0218acf4.h"

void FUN_0218acf4(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  
  if ((param_4 != 0) || (*DAT_0218ad40 == 1)) {
    FUN_0218e8b8();
    *param_1 = param_3;
    param_1[1] = param_2;
    param_1[0x10] = 0;
    param_1[0x11] = param_5;
    param_1[0x12] = param_6;
    param_1[10] = 0;
    uVar1 = FUN_0218e554(2,2);
    param_1[8] = uVar1;
    FUN_0218ae5c(param_1 + 5);
    FUN_0218ae5c(param_1 + 2);
  }
  return;
}

