/* Decompiled C draft; module arm9; ROM address 02017c58. No matching claim. */
#include "types.h"
#include "deps/02017c58_Mem_Exp_ConvertFreeBlockToUsedBlock.h"

int Mem_Exp_ConvertFreeBlockToUsedBlock
              (int param_1,undefined4 param_2,int param_3,int param_4,ushort param_5)

{
  uint uVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  
  Mem_GetMemoryBlockRegion(&local_38);
  local_2c = local_34;
  local_30 = param_4 + param_3;
  local_34 = param_3 + -0x10;
  uVar3 = Mem_ExpHeapMemoryBlockList_Remove(param_1,param_2);
  iVar6 = local_38;
  if (0xf < (uint)(local_34 - local_38)) {
    uVar4 = Mem_Exp_InitializeMemoryBlock(&local_38,uRam02017de4);
    uVar3 = Mem_ExpHeapMemoryBlockList_Insert(param_1,uVar4,uVar3);
    iVar6 = local_34;
  }
  local_34 = iVar6;
  iVar6 = local_2c;
  if (0xf < (uint)(local_2c - local_30)) {
    uVar4 = Mem_Exp_InitializeMemoryBlock(&local_30,uRam02017de4);
    Mem_ExpHeapMemoryBlockList_Insert(param_1,uVar4,uVar3);
    iVar6 = local_30;
  }
  local_30 = iVar6;
  uVar1 = param_1 - 4U & 3;
  uVar5 = *(uint *)(param_1 - 4U & 0xfffffffc);
  if (((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) & 1) != 0) {
    local_20 = 0;
    MIi_CpuClear32(0,local_34,local_30 - local_34);
  }
  local_24 = local_30;
  local_28 = param_3 + -0x10;
  iVar6 = Mem_Exp_InitializeMemoryBlock(&local_28,uRam02017de8);
  *(ushort *)(iVar6 + 2) = *(ushort *)(iVar6 + 2) & 0x7fff;
  *(ushort *)(iVar6 + 2) = *(ushort *)(iVar6 + 2) | (ushort)((param_5 & 1) << 0xf);
  *(ushort *)(iVar6 + 2) = *(ushort *)(iVar6 + 2) & 0x80ff;
  *(ushort *)(iVar6 + 2) = *(ushort *)(iVar6 + 2) | (ushort)((iVar6 - local_34 & 0x7fU) << 8);
  uVar2 = *(ushort *)(param_1 + 0x10);
  *(ushort *)(iVar6 + 2) = *(ushort *)(iVar6 + 2) & 0xff00;
  *(ushort *)(iVar6 + 2) = *(ushort *)(iVar6 + 2) | uVar2 & 0xff;
  uVar1 = param_1 + 0xcU & 3;
  uVar5 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  Mem_ExpHeapMemoryBlockList_Insert
            (param_1 + 8,iVar6,uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20);
  return param_3;
}

