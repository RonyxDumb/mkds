/* Decompiled C draft; module arm9_ov000; ROM address 0218fbe0. No matching claim. */
#include "types.h"
#include "deps/0218fbe0_FUN_0218fbe0.h"

undefined4 FUN_0218fbe0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 auStack_dc8 [3508];
  
  iVar1 = *param_1;
  FUN_02196914(auStack_dc8,param_4,DAT_0218fc88);
  FUN_02190b80(param_1,iVar1 + DAT_0218fc8c,DAT_0218fc90);
  FUN_02190b58(param_1,iVar1 + DAT_0218fc8c,param_3);
  FUN_02190b80(param_1,iVar1 + DAT_0218fc8c,DAT_0218fc94);
  FUN_02190b58(param_1,iVar1 + DAT_0218fc8c,*(undefined4 *)(iVar1 + DAT_0218fc98));
  FUN_02190b80(param_1,iVar1 + DAT_0218fc8c,DAT_0218fc9c);
  FUN_02190b58(param_1,iVar1 + DAT_0218fc8c,param_2);
  FUN_02190b80(param_1,iVar1 + DAT_0218fc8c,DAT_0218fca0);
  FUN_02190b80(param_1,iVar1 + DAT_0218fc8c,auStack_dc8);
  FUN_02190b80(param_1,iVar1 + DAT_0218fc8c,DAT_0218fca4);
  return 0;
}

