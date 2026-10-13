/* Decompiled C draft; module arm9; ROM address 020fe9d0. No matching claim. */
#include "types.h"
#include "deps/020fe9d0_func_020fe9d0.h"

void func_020fe9d0(undefined4 param_1,undefined4 param_2,char param_3,undefined4 param_4,int param_5
                  )

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  
  bVar1 = *pbRam020fea70;
  uVar4 = (uint)bVar1;
  if (uVar4 != 0xff) {
    iVar5 = iRam020fea74 + uVar4 * 0x20;
    *(undefined4 *)(iVar5 + 0x14) = param_1;
    *(undefined4 *)(iVar5 + 0x18) = param_2;
    *(int *)(iVar5 + 0x1c) = param_5;
    Mem_CpuCopy8(param_4,iVar5,0x14);
    iVar5 = iRam020fea78;
    pbVar3 = pbRam020fea70;
    bVar2 = *pbRam020fea7c;
    bVar6 = param_5 != 0;
    *pbRam020fea70 = *(byte *)(iRam020fea78 + uVar4 * 2);
    *(byte *)(iVar5 + uVar4 * 2) = bVar2;
    if (bVar6) {
      pbVar3 = pbRam020fea80;
    }
    if (bVar6) {
      param_5 = 4;
    }
    if (bVar6) {
      pbVar3[uVar4 * 2] = (byte)param_5;
    }
    else {
      pbRam020fea80[uVar4 * 2] = -param_3;
    }
    *pbRam020fea7c = bVar1;
    return;
  }
  return;
}

