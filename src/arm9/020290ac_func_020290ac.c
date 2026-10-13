/* Decompiled C draft; module arm9; ROM address 020290ac. No matching claim. */
#include "types.h"
#include "deps/020290ac_func_020290ac.h"

byte func_020290ac(int param_1)

{
  int iVar1;
  int extraout_r1;
  byte bVar2;
  
  bVar2 = 0;
  if (*(int *)(*piRam020290f0 + iRam020290f4) == param_1) {
    iVar1 = *(int *)(*piRam020290f0 + iRam020290f8);
    bVar2 = 0;
    if ((0x3b < iVar1) && (_s32_div_f(iVar1 + -0x3c,0xf), extraout_r1 == 0)) {
      bVar2 = 1;
    }
    bVar2 = iVar1 == 0 | bVar2;
  }
  return bVar2;
}

