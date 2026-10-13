/* Decompiled C draft; module arm9_ov000; ROM address 021ae87c. No matching claim. */
#include "types.h"
#include "deps/021ae87c_FUN_021ae87c.h"

void FUN_021ae87c(int param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  
  iVar2 = FUN_021b0138(param_2,param_3,param_1,6);
  if (iVar2 == 0) {
    iVar2 = func_0x02133068(*(byte *)(param_2 + 0xc) & 0xf0,4);
    param_3 = param_3 - iVar2;
    bVar1 = *(byte *)(param_2 + 0xd);
    bVar3 = bVar1 & 0x17;
    if (bVar3 < 0x11) {
      if (0xf < bVar3) {
LAB_021ae906:
        FUN_021aea34(param_1,param_2,param_3);
        return;
      }
      if ((bVar3 < 3) && ((bVar1 & 0x17) != 0)) {
        if (bVar3 == 1) {
          FUN_021ae984(param_1,param_2,param_3);
          return;
        }
        if (bVar3 == 2) {
          if ((bVar1 & 0x28) != 0) {
            return;
          }
          FUN_021aed3c(param_1,param_2,param_3);
          return;
        }
      }
    }
    else if ((bVar3 < 0x13) && (0x10 < bVar3)) {
      if (bVar3 == 0x11) goto LAB_021ae906;
      if (bVar3 == 0x12) {
        if ((bVar1 & 0x28) != 0) {
          return;
        }
        FUN_021aec84(param_1,param_2,param_3);
        return;
      }
    }
    if ((bVar1 & 4) != 0) {
      FUN_021ae958(param_1,param_2);
      return;
    }
    FUN_021aeed8(param_1,param_2,param_3,(ushort)*(byte *)(param_1 + 5) * 0x100 + 0x17);
  }
  return;
}

