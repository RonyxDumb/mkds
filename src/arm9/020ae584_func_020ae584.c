/* Decompiled C draft; module arm9; ROM address 020ae584. No matching claim. */
#include "types.h"
#include "deps/020ae584_func_020ae584.h"

undefined4 func_020ae584(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_48 [15];
  
  puVar4 = local_48;
  iVar3 = 7;
  puVar5 = puRam020ae5c0;
  do {
    uVar1 = *puVar5;
    uVar2 = puVar5[1];
    puVar5 = puVar5 + 2;
    *puVar4 = uVar1;
    puVar4[1] = uVar2;
    puVar4 = puVar4 + 2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *puVar4 = *puVar5;
  if (param_1 < 0) {
    uVar1 = 0;
  }
  else if (param_1 < 0xf) {
    uVar1 = local_48[param_1];
  }
  else {
    uVar1 = 0xffffffd8;
  }
  return uVar1;
}

