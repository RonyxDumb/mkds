/* Decompiled C draft; module arm9_ov003; ROM address 021b7efc. No matching claim. */
#include "types.h"
#include "deps/021b7efc_func_ov003_021b7efc.h"

void func_ov003_021b7efc(undefined4 param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  byte *pbVar1;
  int iVar2;
  int extraout_r1;
  int iVar3;
  int iVar4;
  
  iVar2 = func_0x02133068(param_3,2);
  func_0x02133068(param_1,param_5);
  iVar3 = 0;
  iVar4 = extraout_r1;
  if (0 < iVar2) {
    do {
      *(char *)(param_2 + iVar3) = (char)iVar3;
      pbVar1 = (byte *)(param_4 + iVar4);
      iVar4 = iVar4 + 1;
      *(byte *)(param_2 + iVar3) = *(byte *)(param_2 + iVar3) ^ *pbVar1;
      if (param_5 <= iVar4) {
        iVar4 = 0;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  return;
}

