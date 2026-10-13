/* Decompiled C draft; module arm7; ROM address 03804dd0. No matching claim. */
#include "types.h"
#include "deps/03804dd0_FUN_03804dd0.h"

int FUN_03804dd0(uint param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar1 = 0;
  while( true ) {
    if (7 < (int)uVar1) {
      uVar1 = 0;
      iVar2 = 1;
      do {
        iVar3 = iVar2 * (param_1 >> ((uVar1 & 0x3f) << 2) & 0xf) + iVar3;
        uVar1 = uVar1 + 1;
        iVar2 = iVar2 * 10;
      } while ((int)uVar1 < 8);
      return iVar3;
    }
    if (9 < (param_1 >> ((uVar1 & 0x3f) << 2) & 0xf)) break;
    uVar1 = uVar1 + 1;
  }
  return 0;
}

