/* Decompiled C draft; module arm7; ROM address 0600c5a8. No matching claim. */
#include "types.h"
#include "deps/0600c5a8_FUN_0600c5a8.h"

void FUN_0600c5a8(void)

{
  short sVar1;
  short *psVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar3 = thunk_FUN_037f8850(0x1000000);
  psVar2 = DAT_0600c60c;
  sVar1 = *DAT_0600c60c;
  *DAT_0600c610 = 0x1000;
  iVar4 = 100;
  while ((iVar4 != 0 && (sVar1 == *psVar2))) {
    iVar4 = iVar4 + -1;
  }
  *DAT_0600c610 = 0;
  FUN_0600ca18();
  thunk_FUN_037f888c(uVar3);
  return;
}

