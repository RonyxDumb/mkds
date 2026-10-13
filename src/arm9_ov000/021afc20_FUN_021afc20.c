/* Decompiled C draft; module arm9_ov000; ROM address 021afc20. No matching claim. */
#include "types.h"
#include "deps/021afc20_FUN_021afc20.h"

int FUN_021afc20(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint local_18;
  
  uVar3 = 0;
  local_18 = 0;
  do {
    FUN_021afc5c(param_1);
    uVar2 = local_18;
    do {
      func_0x0200dc3c(100);
      iVar1 = FUN_021afd00(param_1);
      if (iVar1 != 0) {
        return iVar1;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < 0x14);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 8);
  return 0;
}

