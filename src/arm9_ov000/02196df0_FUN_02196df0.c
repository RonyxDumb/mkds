/* Decompiled C draft; module arm9_ov000; ROM address 02196df0. No matching claim. */
#include "types.h"
#include "deps/02196df0_FUN_02196df0.h"

char * FUN_02196df0(char *param_1,int param_2)

{
  char *pcVar1;
  
  pcVar1 = param_1;
  if (0 < param_2 + -6) {
    do {
      if ((((*pcVar1 == '\\') && (pcVar1[1] == 'f')) && (pcVar1[2] == 'i')) &&
         (((pcVar1[3] == 'n' && (pcVar1[4] == 'a')) && ((pcVar1[5] == 'l' && (pcVar1[6] == '\\')))))
         ) {
        return pcVar1;
      }
      pcVar1 = pcVar1 + 1;
    } while ((int)pcVar1 - (int)param_1 < param_2 + -6);
  }
  return (char *)0x0;
}

