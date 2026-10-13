/* Decompiled C draft; module arm9; ROM address 020d720c. No matching claim. */
#include "types.h"
#include "deps/020d720c_func_020d720c.h"

void func_020d720c(uint param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  uVar2 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  iVar1 = (int)((uint)(((int)(((int)uVar2 >> 0x1f) * uRam020d73e8 +
                              uVar2 * 0xb6 +
                              (int)((ulonglong)uRam020d73e8 * (ulonglong)uVar2 >> 0x20) + 0x800) >>
                       0xc) << 0x10) >> 0x11) >> 4;
  iVar4 = (int)*(short *)(iRam020d73ec + iVar1 * 4);
  iVar3 = (int)*(short *)(iRam020d73ec + (iVar1 * 2 + 1) * 2);
  uVar2 = param_1 + 4 & 3;
  uVar6 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar2 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
  iVar1 = (int)((uint)(((int)(((int)uVar2 >> 0x1f) * uRam020d73e8 +
                              uVar2 * 0xb6 +
                              (int)((ulonglong)uRam020d73e8 * (ulonglong)uVar2 >> 0x20) + 0x800) >>
                       0xc) << 0x10) >> 0x11) >> 4;
  iVar8 = (int)*(short *)(iRam020d73ec + iVar1 * 4);
  iVar7 = (int)*(short *)(iRam020d73ec + (iVar1 * 2 + 1) * 2);
  iVar1 = iVar4 * iVar7 >> 0xc;
  iVar4 = iVar4 * iVar8 >> 0xc;
  iVar8 = iVar3 * iVar8 >> 0xc;
  iVar3 = iVar3 * iVar7 >> 0xc;
  uVar2 = param_1 + 8 & 3;
  uVar6 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar2 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
  iVar7 = (int)((uint)(((int)(((int)uVar2 >> 0x1f) * uRam020d73e8 +
                              uVar2 * 0xb6 +
                              (int)((ulonglong)uRam020d73e8 * (ulonglong)uVar2 >> 0x20) + 0x800) >>
                       0xc) << 0x10) >> 0x11) >> 4;
  iVar5 = (int)*(short *)(iRam020d73ec + iVar7 * 4);
  iVar7 = (int)*(short *)(iRam020d73ec + (iVar7 * 2 + 1) * 2);
  *param_2 = iVar1 * iVar7 + iVar8 * iVar5 >> 0xc;
  param_2[1] = iVar8 * iVar7 - iVar1 * iVar5 >> 0xc;
  param_2[2] = iVar3 * iVar5 + iVar4 * iVar7 >> 0xc;
  param_2[3] = iVar3 * iVar7 - iVar4 * iVar5 >> 0xc;
  return;
}

