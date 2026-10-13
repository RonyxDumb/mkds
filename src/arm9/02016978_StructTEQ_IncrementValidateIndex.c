/* Decompiled C draft; module arm9; ROM address 02016978. No matching claim. */
#include "types.h"
#include "deps/02016978_StructTEQ_IncrementValidateIndex.h"

uint StructTEQ_IncrementValidateIndex(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint extraout_r1;
  
  uVar1 = param_1 + 4U & 3;
  uVar2 = *(uint *)(param_1 + 4U & 0xfffffffc);
  MaybeBoundsCheck(param_2 + 1,uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  return extraout_r1 & 0xffff;
}

