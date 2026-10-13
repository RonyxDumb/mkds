/* Decompiled C draft; module arm9; ROM address 020c77a0. No matching claim. */
#include "types.h"
#include "deps/020c77a0_func_020c77a0.h"

undefined4 func_020c77a0(void)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined2 local_18 [4];
  
  uVar4 = 0;
  local_18[0] = *puRam020c7818;
  local_18[1] = puRam020c7818[1];
  do {
    uVar1 = local_18[uVar4];
    iVar2 = func_021000d0(uVar1);
    if (iVar2 != 0) {
      uVar3 = func_020c0c2c(uRam020c781c,uVar1);
      return uVar3;
    }
    uVar4 = uVar4 + 1 & 0xffff;
  } while (uVar4 < 2);
  return 0;
}

