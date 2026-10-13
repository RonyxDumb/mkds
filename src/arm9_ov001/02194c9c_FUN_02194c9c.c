/* Decompiled C draft; module arm9_ov001; ROM address 02194c9c. No matching claim. */
#include "types.h"
#include "deps/02194c9c_FUN_02194c9c.h"

uint FUN_02194c9c(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  uVar2 = 0;
  switch(param_1) {
  case 0:
  case 1:
  case 4:
  case 5:
    return 1;
  case 2:
  case 3:
  case 6:
  case 7:
    iVar4 = 0;
    puVar3 = (undefined4 *)(DAT_02194d00 + param_1 * 0xc);
    do {
      uVar1 = func_0x02056dec(*puVar3);
      uVar2 = uVar2 | uVar1;
      puVar3 = puVar3 + 1;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 3);
    uVar1 = FUN_02194d04(param_1);
    uVar2 = uVar2 | uVar1;
  }
  return uVar2;
}

