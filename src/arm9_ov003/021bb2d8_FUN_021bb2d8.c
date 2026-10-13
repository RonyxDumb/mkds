/* Decompiled C draft; module arm9_ov003; ROM address 021bb2d8. No matching claim. */
#include "types.h"
#include "deps/021bb2d8_FUN_021bb2d8.h"

int FUN_021bb2d8(char *param_1,uint param_2)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  pcVar1 = param_1;
  uVar2 = (int)(param_2 & 0xf0) >> 4;
  do {
    if (uVar2 < 10) {
      *pcVar1 = (char)uVar2 + '0';
    }
    else {
      *pcVar1 = (char)uVar2 + '7';
    }
    pcVar1 = pcVar1 + 1;
    iVar3 = iVar3 + 1;
    uVar2 = param_2 & 0xf;
  } while (iVar3 < 2);
  *pcVar1 = '\0';
  return (int)pcVar1 - (int)param_1;
}

