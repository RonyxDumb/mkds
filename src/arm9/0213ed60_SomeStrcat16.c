/* Decompiled C draft; module arm9; ROM address 0213ed60. No matching claim. */
#include "types.h"
#include "deps/0213ed60_SomeStrcat16.h"

void SomeStrcat16(short *param_1,short *param_2,int param_3)

{
  short *psVar1;
  short *psVar2;
  
  do {
    psVar2 = param_1;
    param_1 = psVar2 + 1;
  } while (*psVar2 != 0);
  if (param_3 != 0) {
    do {
      psVar1 = psVar2 + 1;
      *psVar2 = *param_2;
      if (*psVar2 == 0) break;
      param_3 = param_3 + -1;
      param_2 = param_2 + 1;
      psVar2 = psVar1;
    } while (param_3 != 0);
  }
  *psVar2 = 0;
  return;
}

