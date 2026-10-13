/* Decompiled C draft; module arm7; ROM address 037fefc0. No matching claim. */
#include "types.h"
#include "deps/037fefc0_FUN_037fefc0.h"

void FUN_037fefc0(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = param_1 + param_2 * 8 + 0x18;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  if ((uVar2 != 0) &&
     (uVar1 = uVar2 + 0x38 & 3, uVar3 = *(uint *)(uVar2 + 0x38 & 0xfffffffc),
     param_3 < (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20))) {
    FUN_037ff128(uVar2,param_3);
  }
  return;
}

