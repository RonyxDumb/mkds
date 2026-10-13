/* Decompiled C draft; module arm9; ROM address 020cadac. No matching claim. */
#include "types.h"
#include "deps/020cadac_func_020cadac.h"

int func_020cadac(int param_1)

{
  int *piVar1;
  undefined4 extraout_r1;
  int iVar2;
  int iVar3;
  
  piVar1 = (int *)*piRam020cade4;
  iVar2 = piVar1[8];
  if (*piVar1 != 0) {
    iVar3 = piVar1[10];
    if (param_1 != 0) {
      piVar1[9] = 0;
      MaybePlaySomeSseqFromSarc0();
    }
    _s32_div_f(iVar3 + iVar2 + param_1,iVar3);
    *(undefined4 *)(*piRam020cade4 + 0x20) = extraout_r1;
  }
  return iVar2;
}

