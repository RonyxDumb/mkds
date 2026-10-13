/* Decompiled C draft; module arm9_ov000; ROM address 0218d938. No matching claim. */
#include "types.h"
#include "deps/0218d938_FUN_0218d938.h"

void FUN_0218d938(int *param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == (code *)0x0) {
    func_0x0213442c(DAT_0218d974,DAT_0218d978,0,DAT_0218d97c);
  }
  iVar1 = *param_1;
  while (iVar1 = iVar1 + -1, -1 < iVar1) {
    uVar2 = FUN_0218dbf8(param_1,iVar1);
    (*param_2)(uVar2,param_3);
  }
  return;
}

