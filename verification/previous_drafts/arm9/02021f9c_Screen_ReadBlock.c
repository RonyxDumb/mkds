/* Decompiled C draft; module arm9; ROM address 02021f9c. No matching claim. */
#include "types.h"
#include "deps/02021f9c_Screen_ReadBlock.h"

void Screen_ReadBlock(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = Common_FindBlockByMagic(param_1,uRam02021fcc);
  if (iVar1 == 0) {
    *param_2 = 0;
  }
  else {
    *param_2 = iVar1 + 8;
  }
  return;
}

