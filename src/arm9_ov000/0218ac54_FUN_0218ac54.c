/* Decompiled C draft; module arm9_ov000; ROM address 0218ac54. No matching claim. */
#include "types.h"
#include "deps/0218ac54_FUN_0218ac54.h"

void FUN_0218ac54(int param_1,int param_2,int param_3,int param_4)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)(param_2 + 0x14);
  *(byte *)(param_2 + 0x14) = *(byte *)(param_2 + 0x14) & 0xc3;
  if (param_4 == 0) {
    *pbVar1 = *pbVar1 | 4;
  }
  else if (param_4 == 1) {
    *pbVar1 = *pbVar1 | 8;
  }
  else if (param_4 == 2) {
    return;
  }
  if (*(int *)(param_1 + 4) <= *(int *)(param_1 + 0x10)) {
    if (param_3 == 0) {
      FUN_0218aedc(param_1 + 0x14);
      return;
    }
    FUN_0218aec4(param_1 + 0x14);
    return;
  }
  FUN_0218ad44();
  return;
}

