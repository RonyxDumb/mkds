/* Decompiled C draft; module arm9_ov000; ROM address 0218b2a8. No matching claim. */
#include "types.h"
#include "deps/0218b2a8_FUN_0218b2a8.h"

undefined4 FUN_0218b2a8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  byte *pbVar3;
  ushort uVar4;
  
  iVar1 = func_0x0213a074(param_2,DAT_0218b304);
  if (iVar1 == 0) {
    uVar2 = FUN_0218af9c(param_1);
    return uVar2;
  }
  pbVar3 = (byte *)FUN_0218b30c(param_1,param_2,0);
  if (pbVar3 != (byte *)0x0) {
    if (*pbVar3 < 0x80) {
      uVar4 = *(ushort *)(DAT_0218b308 + (uint)*pbVar3 * 2) & 8;
    }
    else {
      uVar4 = 0;
    }
    if (uVar4 != 0) {
      uVar2 = func_0x0213bf90();
      return uVar2;
    }
  }
  return param_3;
}

