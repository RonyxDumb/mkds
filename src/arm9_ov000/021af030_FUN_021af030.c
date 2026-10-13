/* Decompiled C draft; module arm9_ov000; ROM address 021af030. No matching claim. */
#include "types.h"
#include "deps/021af030_FUN_021af030.h"

void FUN_021af030(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;
  
  *(short *)(param_2 + 0x2e) = (short)DAT_021af08c;
  iVar2 = func_0x02133068(*(byte *)(param_1 + 0xc) & 0xf0,4);
  iVar3 = iVar2 + -0x15;
  pbVar4 = (byte *)(param_1 + 0x14);
  if (iVar2 != 0x14) {
    do {
      bVar1 = *pbVar4;
      pbVar5 = pbVar4 + 1;
      if (bVar1 == 0) {
        return;
      }
      if (bVar1 != 1) {
        if (bVar1 == 2) {
          *(ushort *)(param_2 + 0x2e) = CONCAT11(pbVar4[2],pbVar4[3]);
          pbVar5 = pbVar4 + 4;
          iVar3 = iVar3 + -3;
        }
        else {
          iVar3 = iVar3 - (*pbVar5 - 1);
          pbVar5 = pbVar5 + (*pbVar5 - 1);
        }
      }
      bVar6 = iVar3 != 0;
      iVar3 = iVar3 + -1;
      pbVar4 = pbVar5;
    } while (bVar6);
  }
  return;
}

