/* Decompiled C draft; module arm9; ROM address 0212e9cc. No matching claim. */
#include "types.h"
#include "deps/0212e9cc_CheckMaybeLoadSseqOk.h"

bool CheckMaybeLoadSseqOk(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = NNSi_SndArcLoadSeq(param_1,0xff,param_2,1,0);
  return iVar1 == 0;
}

