/* Decompiled C draft; module arm9; ROM address 0212e1ec. No matching claim. */
#include "types.h"
#include "deps/0212e1ec_Sound_PrepareSwarData.h"

int Sound_PrepareSwarData(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = Sound_MaybeGetRawFilePointer();
  if (iVar1 == 0) {
    if (param_3 != 0) {
      Sound_GetActiveSdat();
    }
    iVar1 = Sound_AllocateReadEntireFile(param_1,uRam0212e264);
    if ((param_3 != 0) && (iVar1 != 0)) {
      Sound_SetFileFatDynamicOffsetField(param_1,iVar1);
    }
  }
  return iVar1;
}

