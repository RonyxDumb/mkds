/* Decompiled C draft; module arm7; ROM address 06009dc0. No matching claim. */
#include "types.h"
#include "deps/06009dc0_FUN_06009dc0.h"

void FUN_06009dc0(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint local_20 [2];
  
  iVar3 = 100;
  uVar1 = 0;
  local_20[0] = 0;
  uVar2 = 0;
  do {
    FUN_06018844(iVar3,1,local_20);
    if (uVar2 == 1) {
      local_20[0] = local_20[0] & 0x80;
    }
    uVar1 = FUN_060095d0(local_20[0] & 0xff,uVar1);
    iVar3 = iVar3 + 1;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x69);
  return;
}

