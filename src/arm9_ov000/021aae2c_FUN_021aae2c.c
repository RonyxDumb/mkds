/* Decompiled C draft; module arm9_ov000; ROM address 021aae2c. No matching claim. */
#include "types.h"
#include "deps/021aae2c_FUN_021aae2c.h"

int FUN_021aae2c(char *param_1)

{
  char *pcVar1;
  
  for (pcVar1 = param_1; (*pcVar1 != '.' && (*pcVar1 != '\0')); pcVar1 = pcVar1 + 1) {
  }
  return (int)pcVar1 - (int)param_1;
}

