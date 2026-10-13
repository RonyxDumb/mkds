/* Decompiled C draft; module arm9; ROM address 020abff4. No matching claim. */
#include "types.h"
#include "deps/020abff4_func_020abff4.h"

undefined2 func_020abff4(int param_1,uint param_2)

{
  undefined2 uVar1;
  
  uVar1 = 0;
  if (param_1 == 1) {
    if (((param_2 & 0x20) == 0) && ((param_2 & 0x10) == 0)) {
      if ((param_2 & 0x40) == 0) {
        if ((param_2 & 0x80) != 0) {
          uVar1 = *(undefined2 *)(iRam020ac0a4 + *(int *)(*piRam020ac09c + 0x4c) * 8);
        }
      }
      else {
        uVar1 = *(undefined2 *)(iRam020ac0a0 + *(int *)(*piRam020ac09c + 0x4c) * 8);
      }
    }
    else {
      uVar1 = 2;
    }
  }
  else if (param_1 == 2) {
    if (((param_2 & 0x20) == 0) && ((param_2 & 0x10) == 0)) {
      if ((param_2 & 0x40) == 0) {
        if ((param_2 & 0x80) != 0) {
          uVar1 = *(undefined2 *)(iRam020ac0ac + *(int *)(*piRam020ac09c + 0x4c) * 8);
        }
      }
      else {
        uVar1 = *(undefined2 *)(iRam020ac0a8 + *(int *)(*piRam020ac09c + 0x4c) * 8);
      }
    }
    else {
      uVar1 = 1;
    }
  }
  MaybePlaySomeSseqFromSarc0(uRam020ac0b0);
  return uVar1;
}

