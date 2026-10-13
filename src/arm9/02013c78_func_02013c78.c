/* Decompiled C draft; module arm9; ROM address 02013c78. No matching claim. */
#include "types.h"
#include "deps/02013c78_func_02013c78.h"

undefined4 func_02013c78(uint *param_1,int param_2,int param_3,uint param_4)

{
  short sVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  int iVar5;
  ushort *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  if ((param_4 & 0x8000) == 0) {
    param_4 = param_4 & uRam02013e04;
    iVar5 = param_3 + param_4 * 10;
    sVar1 = *(short *)(iVar5 + 8);
    param_1[4] = (int)sVar1 >> 3;
    uVar7 = (uint)*(short *)(param_3 + param_4 * 10);
    *param_1 = (int)uVar7 >> 3;
    sVar2 = *(short *)(iVar5 + 2);
    param_1[1] = (int)sVar2 >> 3;
    sVar3 = *(short *)(iVar5 + 4);
    param_1[2] = (int)sVar3 >> 3;
    uVar4 = *(ushort *)(iVar5 + 6);
    param_1[3] = (int)(short)uVar4 >> 3;
    param_1[5] = ((int)(short)(uVar4 & 7 |
                              (ushort)((int)(((int)sVar3 & 7U |
                                             (int)(((int)sVar2 & 7U |
                                                   (int)((uVar7 & 7 |
                                                         (int)(((int)sVar1 & 7U) << 0x10) >> 0xd) <<
                                                        0x10) >> 0xd) << 0x10) >> 0xd) << 0x10) >>
                                      0xd)) << 0x13) >> 0x13;
    return 1;
  }
  param_1[8] = 0;
  uVar10 = uRam02013e04;
  uVar7 = (uint)(param_1 + 8) & 3;
  uVar8 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
  param_1[7] = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
  uVar7 = (uint)(param_1 + 7) & 3;
  uVar8 = *(uint *)((uint)(param_1 + 7) & 0xfffffffc);
  param_1[6] = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
  uVar7 = (uint)(param_1 + 6) & 3;
  uVar8 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
  param_1[5] = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
  uVar7 = (uint)(param_1 + 5) & 3;
  uVar8 = *(uint *)((uint)(param_1 + 5) & 0xfffffffc);
  param_1[4] = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
  uVar7 = (uint)(param_1 + 4) & 3;
  uVar8 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
  param_1[3] = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
  uVar7 = (uint)(param_1 + 3) & 3;
  uVar8 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
  puVar6 = (ushort *)(param_2 + (param_4 & uVar10) * 6);
  param_1[2] = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
  uVar7 = (uint)(param_1 + 2) & 3;
  uVar8 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  param_1[1] = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
  uVar7 = (uint)(param_1 + 1) & 3;
  uVar8 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  *param_1 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
  uVar9 = (uint)*(short *)(param_2 + (param_4 & uVar10) * 6);
  uVar10 = (uint)(short)puVar6[1];
  uVar7 = (uint)(short)puVar6[2];
  uVar8 = uVar9 & 0xf;
  if ((uVar9 & 0x10) == 0) {
    uVar9 = 0x1000;
  }
  else {
    uVar9 = 0xfffff000;
  }
  param_1[uVar8] = uVar9;
  iVar5 = iRam02013e0c;
  param_1[*(byte *)(iRam02013e08 + uVar8 * 4)] = uVar10;
  param_1[*(byte *)(iVar5 + uVar8 * 4)] = uVar7;
  if ((*puVar6 & 0x20) != 0) {
    uVar7 = -uVar7;
  }
  param_1[*(byte *)(iRam02013e10 + uVar8 * 4)] = uVar7;
  if ((*puVar6 & 0x40) != 0) {
    uVar10 = -uVar10;
  }
  param_1[*(byte *)(iRam02013e14 + uVar8 * 4)] = uVar10;
  return 0;
}

