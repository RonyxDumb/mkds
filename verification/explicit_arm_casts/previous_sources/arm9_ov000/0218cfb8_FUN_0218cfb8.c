/* Decompiled C draft; module arm9_ov000; ROM address 0218cfb8. No matching claim. */
#include "types.h"
#include "deps/0218cfb8_FUN_0218cfb8.h"

void FUN_0218cfb8(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,int param_7,undefined4 param_8)

{
  if (param_1 == (undefined4 *)0x0) {
    func_0x0213442c(DAT_0218d080,DAT_0218d084,0,DAT_0218d088);
  }
  if ((param_6 != 0) || (*DAT_0218d08c == 1)) {
    *param_1 = 1;
    FUN_0218d180(param_1);
    FUN_0218b3f4(param_1);
    func_0x0213a2d0(param_1 + 3,param_2);
    func_0x0213a2d0(param_1 + 0xc,param_3);
    func_0x0213a2d0(param_1 + 0x15,param_4);
    *(int *)((int)param_1 + DAT_0218d090) = param_7;
    *(undefined4 *)((int)param_1 + DAT_0218d094) = 0;
    if (param_7 == 0) {
      func_0x0213442c(DAT_0218d098,DAT_0218d084,0,DAT_0218d09c);
    }
    *(undefined4 *)((int)param_1 + DAT_0218d0a0) = param_8;
    *(undefined4 *)((int)param_1 + DAT_0218d0a8) = DAT_0218d0a4;
    *(undefined4 *)((int)param_1 + DAT_0218d0ac) = 0;
    *(undefined4 *)((int)param_1 + DAT_0218d0b0) = 0xffffffff;
    param_1[0x1f] = 0;
    param_1[0x20] = 0;
    param_1[2] = 0;
    *(undefined4 *)((int)param_1 + DAT_0218d0b4) = 0xffffffff;
    *(undefined4 *)((int)param_1 + DAT_0218d0b8) = 0;
    *(undefined4 *)((int)param_1 + DAT_0218d0bc) = 0;
    *(undefined4 *)((int)param_1 + DAT_0218d0c0) = param_5;
    FUN_0218c45c(param_1);
    *(undefined4 *)((int)param_1 + DAT_0218d0c4) = 0;
    FUN_0218e8c4();
    func_0x021384cc();
    FUN_0218e8b8();
  }
  return;
}

