/* Decompiled C draft; module arm9_ov000; ROM address 0218c744. No matching claim. */
#include "types.h"
#include "deps/0218c744_FUN_0218c744.h"

void FUN_0218c744(int param_1,byte *param_2,int param_3,byte *param_4,byte *param_5)

{
  byte bVar1;
  
  if (4 < param_3) {
    bVar1 = *param_2;
    *param_4 = param_2[1];
    param_4[1] = param_2[2];
    param_4[2] = param_2[3];
    param_4[3] = param_2[4];
    if ((bVar1 & 0x10) == 0) {
      *(undefined2 *)param_5 = *(undefined2 *)(param_1 + DAT_0218c790);
    }
    else if (1 < param_3 + -5) {
      *param_5 = param_2[5];
      param_5[1] = param_2[6];
      return;
    }
  }
  return;
}

