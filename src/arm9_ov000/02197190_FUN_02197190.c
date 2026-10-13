/* Decompiled C draft; module arm9_ov000; ROM address 02197190. No matching claim. */
#include "types.h"
#include "deps/02197190_FUN_02197190.h"

void FUN_02197190(undefined4 param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  
  func_0x02135014(param_2,DAT_021971c4,param_1);
  cVar1 = *param_2;
  pcVar2 = param_2;
  while (cVar1 != '\0') {
    *pcVar2 = *pcVar2 + '\x11' + ((char)pcVar2 - (char)param_2);
    pcVar2 = pcVar2 + 1;
    cVar1 = *pcVar2;
  }
  return;
}

