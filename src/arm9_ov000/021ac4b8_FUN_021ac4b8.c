/* Decompiled C draft; module arm9_ov000; ROM address 021ac4b8. No matching claim. */
#include "types.h"
#include "deps/021ac4b8_FUN_021ac4b8.h"

void FUN_021ac4b8(ushort *param_1,int param_2,int param_3,int param_4)

{
  byte *pbVar1;
  
  func_0x0214d168((uint *)(void *)(param_1),0,param_4 << 1);
  pbVar1 = (byte *)(param_2 + param_3 + -1);
  if (1 < param_3) {
    do {
      *param_1 = (ushort)*pbVar1 + (ushort)pbVar1[-1] * 0x100;
      param_1 = param_1 + 1;
      pbVar1 = pbVar1 + -2;
      param_3 = param_3 + -2;
    } while (1 < param_3);
  }
  if (0 < param_3) {
    *param_1 = (ushort)*pbVar1;
  }
  return;
}

