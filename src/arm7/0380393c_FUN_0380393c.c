/* Decompiled C draft; module arm7; ROM address 0380393c. No matching claim. */
#include "types.h"
#include "deps/0380393c_FUN_0380393c.h"

void FUN_0380393c(uint param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_03803960;
  iVar2 = 0;
  do {
    if ((param_1 & 1) != 0) {
      *(undefined4 *)(iVar1 + iVar2 * 4) = param_2;
    }
    param_1 = param_1 >> 1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x19);
  return;
}

