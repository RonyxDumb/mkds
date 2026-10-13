/* Decompiled C draft; module arm9_ov000; ROM address 0218b1e0. No matching claim. */
#include "types.h"
#include "deps/0218b1e0_FUN_0218b1e0.h"

undefined4 FUN_0218b1e0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 local_18 [2];
  
  puVar2 = local_18;
  local_18[0] = *DAT_0218b21c;
  local_18[1] = DAT_0218b21c[1];
  uVar3 = 0;
  do {
    iVar1 = func_0x0213a074(param_1,*puVar2);
    if (iVar1 == 0) {
      return 0;
    }
    puVar2 = puVar2 + 1;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 2);
  return 1;
}

