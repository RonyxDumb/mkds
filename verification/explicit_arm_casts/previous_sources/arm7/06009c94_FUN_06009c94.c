/* Decompiled C draft; module arm7; ROM address 06009c94. No matching claim. */
#include "types.h"
#include "deps/06009c94_FUN_06009c94.h"

void FUN_06009c94(void)

{
  int iVar1;
  uint uVar2;
  undefined4 local_18;
  
  *DAT_06009d00 = 0x100;
  iVar1 = 100;
  uVar2 = 0;
  local_18 = 0;
  do {
    FUN_06018844(iVar1,1,&local_18);
    FUN_06009e58(uVar2,local_18);
    iVar1 = iVar1 + 1;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x69);
  FUN_06009e58(0x5a,2);
  return;
}

