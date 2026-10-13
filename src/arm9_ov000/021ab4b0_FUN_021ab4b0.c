/* Decompiled C draft; module arm9_ov000; ROM address 021ab4b0. No matching claim. */
#include "types.h"
#include "deps/021ab4b0_FUN_021ab4b0.h"

void FUN_021ab4b0(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar2 = param_1;
  if (*param_1 != '\0') {
    do {
      pcVar3 = pcVar2;
      pcVar2 = pcVar3 + 1;
    } while (*pcVar2 != '\0');
    if (0xfe < (int)pcVar2 - (int)param_1) {
      return;
    }
    *pcVar2 = ',';
    pcVar2 = pcVar3 + 3;
    pcVar3[2] = ' ';
  }
  for (; (param_3 != 0 && ((int)pcVar2 - (int)param_1 < 0xff)); pcVar2 = pcVar2 + 1) {
    cVar1 = *param_2;
    param_2 = param_2 + 1;
    *pcVar2 = cVar1;
    param_3 = param_3 + -1;
  }
  *pcVar2 = '\0';
  return;
}

