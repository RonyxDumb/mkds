/* Decompiled C draft; module arm9; ROM address 0212e3dc. No matching claim. */
#include "types.h"
#include "deps/0212e3dc_Sound_AllocateReadEntireFile.h"

int Sound_AllocateReadEntireFile
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = Sound_GetFileSize();
  if (iVar1 == 0) {
    return 0;
  }
  if (param_5 == 0) {
    return 0;
  }
  iVar2 = Sound_Context_Allocate(param_5,iVar1 + 0x20,param_2,param_3);
  if (iVar2 == 0) {
    return 0;
  }
  iVar3 = Sound_ReadFile(param_1,iVar2,iVar1,0);
  if (iVar1 == iVar3) {
    DC_SomeClean(iVar2,iVar1);
    return iVar2;
  }
  return 0;
}

