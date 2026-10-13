/* Decompiled C draft; module arm9; ROM address 020ae114. No matching claim. */
#include "types.h"
#include "deps/020ae114_IsRacerPlayerOrGhostOrNet.h"

undefined4 IsRacerPlayerOrGhostOrNet(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = GetRacerType();
  if (((iVar1 == 0) || (iVar1 = GetRacerType(param_1), iVar1 == 2)) ||
     (iVar1 = GetRacerType(param_1), iVar1 == 3)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

