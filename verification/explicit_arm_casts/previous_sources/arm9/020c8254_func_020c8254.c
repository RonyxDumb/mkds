/* Decompiled C draft; module arm9; ROM address 020c8254. No matching claim. */
#include "types.h"
#include "deps/020c8254_func_020c8254.h"

undefined4 func_020c8254(void)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined2 local_18 [4];
  
  local_18[0] = *puRam020c82d4;
  local_18[1] = puRam020c82d4[1];
  local_18[2] = puRam020c82d4[2];
  uVar4 = 0;
  do {
    uVar1 = local_18[uVar4];
    iVar2 = func_021000d0(uVar1);
    if (iVar2 != 0) {
      uVar3 = func_020c0c2c(uRam020c82d8,uVar1);
      return uVar3;
    }
    uVar4 = uVar4 + 1 & 0xffff;
  } while (uVar4 < 3);
  return 0;
}

