/* Decompiled C draft; module arm7; ROM address 06013a50. No matching claim. */
#include "types.h"
#include "deps/06013a50_FUN_06013a50.h"

int FUN_06013a50(undefined4 param_1,int param_2,int param_3)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  iVar2 = FUN_06009138((*(uint *)(DAT_06013bc0 & 0xfffffffc) >> (DAT_06013bc0 & 3) * 8 |
                       *(uint *)(DAT_06013bc0 & 0xfffffffc) << (DAT_06013bc0 & 3) * -8 + 0x20) +
                       0x188,0x60);
  if (iVar2 == 0) {
    FUN_06009360(2);
    iVar6 = 0;
  }
  else {
    *(short *)(iVar2 + 0xc) = (short)DAT_06013bc4;
    iVar6 = iVar2 + 0x10;
    if (param_2 == 0) {
      iVar3 = FUN_0600e9a8(param_1);
      if (iVar3 == 0) {
        param_2 = 0x13;
      }
    }
    else {
      iVar3 = 0;
    }
    uVar4 = FUN_0600e8bc(param_1);
    FUN_0601359c(iVar6,uVar4);
    *(undefined2 *)(iVar2 + 0x3c) =
         *(undefined2 *)
          ((*(uint *)(DAT_06013bc0 & 0xfffffffc) >> (DAT_06013bc0 & 3) * 8 |
           *(uint *)(DAT_06013bc0 & 0xfffffffc) << (DAT_06013bc0 & 3) * -8 + 0x20) + 0x3c0);
    *(short *)(iVar2 + 0x3e) = (short)param_2;
    *(short *)(iVar2 + 0x40) = (short)iVar3;
    if (iVar3 != 0) {
      *(ushort *)(iVar2 + 0x40) = *(ushort *)(iVar2 + 0x40) | 0xc000;
    }
    sVar1 = FUN_060133fc(iVar2 + 0x42);
    *(short *)(iVar2 + 0x16) = sVar1 + 6;
    *(short *)(iVar2 + 0x22) = *(short *)(iVar2 + 0x16) + 0x1c;
    *(undefined2 *)(iVar2 + 0x24) = 0x10;
    iVar2 = iVar2 + 0x24 + (uint)*(ushort *)(iVar2 + 0x22);
    if (param_3 == 0) {
      FUN_060096e4(iVar2,0);
      FUN_060096e4(iVar2 + 1,0);
    }
    else {
      uVar5 = FUN_060096c4(param_3 + 1);
      uVar4 = FUN_060096c4(param_3);
      FUN_060096e4(iVar2,uVar4);
      iVar3 = iVar2 + 2;
      FUN_060096e4(iVar2 + 1,uVar5 & 0xff);
      for (uVar7 = 0; uVar7 < uVar5; uVar7 = uVar7 + 1) {
        uVar4 = FUN_060096c4(param_3 + 2 + uVar7);
        FUN_060096e4(iVar3,uVar4);
        iVar3 = iVar3 + 1;
      }
    }
  }
  return iVar6;
}

