/* Decompiled C draft; module arm9; ROM address 0212463c. No matching claim. */
#include "types.h"
#include "deps/0212463c_func_0212463c.h"

void func_0212463c(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
                  int param_7,undefined4 param_8,int param_9)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_28;
  
  puVar2 = (ushort *)
           CellBank_GetMetatileEntry((ushort *)(uintptr_t)(param_2),*(uint *)(param_5 + param_1 * 8 + 0xc) & 0xffff);
  iVar3 = CellBank_GetMetatileEntry((ushort *)(uintptr_t)(param_8),*(uint *)(param_9 + param_7 * 8 + 0xc) & 0xffff);
  local_28 = 0;
  uVar1 = *puVar2;
  if (uVar1 != 0) {
    iVar6 = 0;
    do {
      iVar8 = (*(ushort *)(*(int *)(iVar3 + 4) + iVar6 + 4) & uRam02124734) * 0x20;
      iVar5 = *(int *)(puVar2 + 2) + iVar6;
      iVar7 = (uint)*(byte *)(((*(ushort *)(*(int *)(puVar2 + 2) + iVar6) & uRam0212473c) >> 0xe) *
                              4 + iRam02124740 +
                                  (((uint)*(ushort *)(iVar5 + 2) << 0x10 & uRam02124738) >> 0x1e)) *
              0x20;
      iVar5 = *(int *)(param_3 + 0x14) + (*(ushort *)(iVar5 + 4) & uRam02124734) * 0x20;
      Arm_FlushRange(iVar5,iVar7);
      if (param_6 == 0) {
        AllocateReserveTEQSub(0x13,iVar8,iVar5,iVar7);
      }
      else {
        AllocateReserveTEQSub(0x23,iVar8,iVar5,iVar7);
      }
      iVar6 = iVar6 + 6;
      local_28 = local_28 + 1;
    } while (local_28 < (int)(uint)uVar1);
  }
  if (param_6 == 0) {
    uVar4 = 0xe;
  }
  else {
    uVar4 = 0x1e;
  }
  AllocateReserveTEQSub
            (uVar4,((*(ushort *)(*(int *)(iVar3 + 4) + 4) & uRam02124744) >> 0xc) << 5,
             *(int *)(param_4 + 0xc) +
             ((*(ushort *)(*(int *)(puVar2 + 2) + 4) & uRam02124744) >> 0xc) * 0x20,0x20);
  return;
}

