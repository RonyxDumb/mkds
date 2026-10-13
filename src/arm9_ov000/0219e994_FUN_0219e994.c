/* Decompiled C draft; module arm9_ov000; ROM address 0219e994. No matching claim. */
#include "types.h"
#include "deps/0219e994_FUN_0219e994.h"

undefined4 FUN_0219e994(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0218b2a8(param_1,DAT_0219ea30,0xffffffff);
  if (iVar1 == -1) {
    return 0;
  }
  iVar1 = FUN_0218b2a8(param_1,DAT_0219ea34);
  if (iVar1 == -1) {
    return 0;
  }
  iVar1 = FUN_0218b2a8(param_1,DAT_0219ea38);
  if (iVar1 == -1) {
    return 0;
  }
  iVar1 = FUN_0218b2a8(param_1,DAT_0219ea3c);
  if ((iVar1 == -1) && (iVar1 = FUN_0218b2a8(param_1,DAT_0219ea3c), iVar1 == 0)) {
    return 0;
  }
  iVar1 = FUN_0218b2a8(param_1,DAT_0219ea40,0xffffffff);
  if (iVar1 == -1) {
    return 0;
  }
  uVar2 = FUN_0218b2a8(param_1,DAT_0219ea44);
  return uVar2;
}

