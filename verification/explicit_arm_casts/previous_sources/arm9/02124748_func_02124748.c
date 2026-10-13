/* Decompiled C draft; module arm9; ROM address 02124748. No matching claim. */
#include "types.h"
#include "deps/02124748_func_02124748.h"

void func_02124748(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
                  undefined4 param_7,int param_8)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_24;
  
  puVar2 = (ushort *)
           CellBank_GetMetatileEntry(param_2,*(uint *)(param_4 + param_1 * 8 + 0xc) & 0xffff);
  iVar3 = CellBank_GetMetatileEntry(param_7,*(uint *)(param_8 + param_6 * 8 + 0xc) & 0xffff);
  local_24 = 0;
  uVar1 = *puVar2;
  if (uVar1 != 0) {
    iVar5 = 0;
    do {
      iVar7 = (*(ushort *)(*(int *)(iVar3 + 4) + iVar5 + 4) & uRam0212480c) * 0x20;
      iVar4 = *(int *)(puVar2 + 2) + iVar5;
      iVar6 = (uint)*(byte *)(((*(ushort *)(*(int *)(puVar2 + 2) + iVar5) & uRam02124814) >> 0xe) *
                              4 + iRam02124818 +
                                  (((uint)*(ushort *)(iVar4 + 2) << 0x10 & uRam02124810) >> 0x1e)) *
              0x20;
      iVar4 = *(int *)(param_3 + 0x14) + (*(ushort *)(iVar4 + 4) & uRam0212480c) * 0x20;
      Arm_FlushRange(iVar4,iVar6);
      if (param_5 == 0) {
        AllocateReserveTEQSub(0x13,iVar7,iVar4,iVar6);
      }
      else {
        AllocateReserveTEQSub(0x23,iVar7,iVar4,iVar6);
      }
      iVar5 = iVar5 + 6;
      local_24 = local_24 + 1;
    } while (local_24 < (int)(uint)uVar1);
  }
  return;
}

