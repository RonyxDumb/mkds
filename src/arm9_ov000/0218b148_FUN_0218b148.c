/* Decompiled C draft; module arm9_ov000; ROM address 0218b148. No matching claim. */
#include "types.h"
#include "deps/0218b148_FUN_0218b148.h"

void FUN_0218b148(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_0218b19c(param_2 + 1,0x5c);
  while (iVar1 != 0) {
    iVar2 = FUN_0218b19c(0,0x5c);
    if (iVar2 == 0) {
      iVar2 = DAT_0218b198;
    }
    iVar3 = FUN_0218b1e0(iVar1);
    if (iVar3 != 0) {
      FUN_0218b380(param_1,iVar1,iVar2);
    }
    iVar1 = FUN_0218b19c(0,0x5c);
  }
  return;
}

