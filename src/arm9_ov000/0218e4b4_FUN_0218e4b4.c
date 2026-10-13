/* Decompiled C draft; module arm9_ov000; ROM address 0218e4b4. No matching claim. */
#include "types.h"
#include "deps/0218e4b4_FUN_0218e4b4.h"

void FUN_0218e4b4(undefined4 param_1,undefined1 *param_2,undefined1 param_3)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 local_18 [12];
  
  puVar4 = local_18;
  iVar3 = 8;
  do {
    uVar1 = *param_2;
    param_2 = param_2 + 1;
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  local_18[0] = param_3;
  uVar2 = FUN_021a911c(param_1,(int)(uintptr_t)(local_18));
  FUN_0218e56c(uVar2,0xffffffff);
  return;
}

