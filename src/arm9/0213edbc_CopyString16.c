/* Decompiled C draft; module arm9; ROM address 0213edbc. No matching claim. */
#include "types.h"
#include "deps/0213edbc_CopyString16.h"

void CopyString16(short *param_1,short *param_2,int param_3)

{
  short *psVar1;
  
  if (param_3 == 0) {
    return;
  }
  do {
    psVar1 = param_1 + 1;
    *param_1 = *param_2;
    if (*param_1 == 0) {
      param_3 = param_3 + -1;
      if (param_3 == 0) {
        return;
      }
      do {
        *psVar1 = 0;
        param_3 = param_3 + -1;
        psVar1 = psVar1 + 1;
      } while (param_3 != 0);
      return;
    }
    param_3 = param_3 + -1;
    param_2 = param_2 + 1;
    param_1 = psVar1;
  } while (param_3 != 0);
  return;
}

