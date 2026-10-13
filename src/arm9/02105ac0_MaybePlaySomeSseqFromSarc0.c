/* Decompiled C draft; module arm9; ROM address 02105ac0. No matching claim. */
#include "types.h"
#include "deps/02105ac0_MaybePlaySomeSseqFromSarc0.h"

void MaybePlaySomeSseqFromSarc0(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = uRam02105b08;
  if (*(uint *)((uint)puRam02105b04 & 0xfffffffc) >> ((uint)puRam02105b04 & 3) * 8 == 0 &&
      *(uint *)((uint)puRam02105b04 & 0xfffffffc) << ((uint)puRam02105b04 & 3) * -8 + 0x20 == 0) {
    *puRam02105b04 = 1;
    NNSi_MaybeSndPlayerStartSeq(uVar1,0,param_1);
    return;
  }
  return;
}

