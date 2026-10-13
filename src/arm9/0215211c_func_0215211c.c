/* Decompiled C draft; module arm9; ROM address 0215211c. No matching claim. */
#include "types.h"
#include "deps/0215211c_func_0215211c.h"

ulonglong func_0215211c(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  uint local_28;
  byte local_24;
  byte bStack_23;
  undefined1 uStack_22;
  byte bStack_21;
  byte local_20 [12];
  
  iVar7 = 0;
  param_1 = param_1 & uRam02152234;
  uVar2 = param_1 >> 5;
  local_24 = (byte)uVar2 | (byte)((param_2 & uRam02152238) >> 0x1d);
  uVar1 = param_1 << 0x1b | (param_2 & uRam02152238) << 3 | param_4 & 3 | (param_3 & 1) << 2;
  local_28 = uVar1;
  bStack_23 = (byte)(uVar2 >> 8);
  uStack_22 = (undefined1)(uVar2 >> 0x10);
  bStack_21 = (byte)(param_1 >> 0x1d);
  puVar3 = &local_28;
  do {
    *(byte *)puVar3 = (byte)*puVar3 ^ 0xd6;
    puVar3 = (uint *)((int)puVar3 + 1);
    iVar7 = iVar7 + 1;
  } while (iVar7 < 6);
  iVar7 = 0;
  puVar3 = &local_28;
  do {
    *(byte *)puVar3 =
         *(char *)(iRam0215223c + ((int)(uint)(byte)*puVar3 >> 4)) << 4 |
         *(byte *)(iRam0215223c + ((byte)*puVar3 & 0xf));
    puVar3 = (uint *)((int)puVar3 + 1);
    iVar7 = iVar7 + 1;
  } while (iVar7 < 5);
  Mem_CpuCopy8(&local_28,local_20,8,0xf,uVar1);
  iVar7 = 0;
  pbVar8 = local_20;
  puVar3 = &local_28;
  pbVar5 = pbRam02152240;
  do {
    *(byte *)((int)puVar3 + (uint)*pbVar5) = *pbVar8;
    pbVar8 = pbVar8 + 1;
    pbVar5 = pbVar5 + 1;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 5);
  iVar7 = 0;
  iVar6 = (uint)(CONCAT11(bStack_23,local_24) & 0x7ff) << 1;
  local_24 = (byte)iVar6 | (byte)(local_28 >> 0x1f);
  iVar4 = local_28 << 1;
  bStack_23 = (byte)((uint)iVar6 >> 8);
  uStack_22 = 0;
  bStack_21 = 0;
  MKDS_SLICE_1(local_28,0) = (byte)iVar4;
  local_28 = CONCAT31((int3)((uint)iVar4 >> 8),(byte)local_28 | (byte)((int)(uint)bStack_23 >> 3));
  do {
    *(byte *)puVar3 = (byte)*puVar3 ^ 0x67;
    puVar3 = (uint *)((int)puVar3 + 1);
    iVar7 = iVar7 + 1;
  } while (iVar7 < 6);
  return (ulonglong)(CONCAT15(bStack_23,CONCAT14(local_24,local_28)) & 0x7ffffffffff);
}

