/* Decompiled C draft; module arm9_ov000; ROM address 0218a6f4. No matching claim. */
#include "types.h"
#include "deps/0218a6f4_FUN_0218a6f4.h"

void FUN_0218a6f4(undefined4 param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < param_3) {
    do {
      uVar1 = FUN_0218a71c(param_1,*(undefined1 *)(param_2 + iVar2));
      *(undefined1 *)(param_2 + iVar2) = uVar1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_3);
  }
  return;
}

