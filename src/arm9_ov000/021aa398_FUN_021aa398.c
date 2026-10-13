/* Decompiled C draft; module arm9_ov000; ROM address 021aa398. No matching claim. */
#include "types.h"
#include "deps/021aa398_FUN_021aa398.h"

void FUN_021aa398(int param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = (char *)(param_1 + param_2);
  iVar2 = 0;
  if (0 < param_2) {
    do {
      pcVar1 = pcVar1 + -1;
      *pcVar1 = *pcVar1 + '\x01';
      if (*pcVar1 != '\0') {
        return;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_2);
  }
  return;
}

