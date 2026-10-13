/* Decompiled C draft; module arm9_ov000; ROM address 021aab3c. No matching claim. */
#include "types.h"
#include "deps/021aab3c_FUN_021aab3c.h"

undefined4 FUN_021aab3c(byte *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (0 < param_2) {
    do {
      iVar2 = (uint)*param_1 * 0x100 + (uint)param_1[1];
      if (param_3 == 3) {
        iVar2 = iVar2 * 0x100 + (uint)param_1[2];
      }
      if (iVar2 == param_4) {
        return 1;
      }
      param_1 = param_1 + param_3;
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_2);
  }
  return 0;
}

