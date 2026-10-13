/* Decompiled C draft; module arm9_ov000; ROM address 0218a898. No matching claim. */
#include "types.h"
#include "deps/0218a898_FUN_0218a898.h"

uint FUN_0218a898(int param_1,uint param_2,int param_3,uint param_4,byte *param_5,uint *param_6)

{
  uint uVar1;
  uint extraout_r1;
  uint uVar2;
  undefined4 local_1c;
  
  if (param_2 == 0) {
    return 0;
  }
  local_1c = 0;
  uVar2 = 1;
  if (1 < param_2) {
    do {
      uVar2 = uVar2 * 2 + 1;
    } while (uVar2 < param_2);
  }
  do {
    uVar1 = *param_6;
    *param_6 = uVar1 + 1;
    *param_5 = *(char *)(param_1 + (uint)*param_5) + *(char *)(param_3 + uVar1);
    if (param_4 <= *param_6) {
      *param_6 = 0;
      *param_5 = *param_5 + (char)param_4;
    }
    uVar1 = uVar2 & *param_5;
    local_1c = local_1c + 1;
    if (0xb < local_1c) {
      func_0x02133274(uVar1,param_2);
      uVar1 = extraout_r1;
    }
  } while (param_2 < uVar1);
  return uVar1 & 0xff;
}

