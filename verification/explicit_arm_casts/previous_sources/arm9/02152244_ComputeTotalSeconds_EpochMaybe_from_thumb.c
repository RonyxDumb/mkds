/* Decompiled C draft; module arm9; ROM address 02152244. No matching claim. */
#include "types.h"
#include "deps/02152244_ComputeTotalSeconds_EpochMaybe_from_thumb.h"

longlong ComputeTotalSeconds_EpochMaybe_from_thumb(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  
  iVar1 = func_021522a0();
  if (iVar1 == -1) {
    return -1;
  }
  iVar2 = ComputeTimeSeconds_from_thumb(param_2);
  lVar3 = Multiply64(iVar1,iVar1 >> 0x1f,uRam02152288,0);
  return lVar3 + iVar2;
}

