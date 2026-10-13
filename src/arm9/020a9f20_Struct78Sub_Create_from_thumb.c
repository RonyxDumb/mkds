/* Decompiled C draft; module arm9; ROM address 020a9f20. No matching claim. */
#include "types.h"
#include "deps/020a9f20_Struct78Sub_Create_from_thumb.h"

void Struct78Sub_Create_from_thumb
               (char *param_1,char param_2,char param_3,char param_4,char param_5)

{
  if (param_1 != (char *)0x0) {
    *param_1 = param_2;
    param_1[1] = param_3;
    param_1[2] = param_4 - param_2;
    param_1[3] = param_5 - param_3;
    param_1[4] = '\0';
    param_1[5] = '\0';
    *(short *)(param_1 + 6) = (short)uRam020a9f3c;
  }
  return;
}

