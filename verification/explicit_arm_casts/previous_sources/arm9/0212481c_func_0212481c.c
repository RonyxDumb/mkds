/* Decompiled C draft; module arm9; ROM address 0212481c. No matching claim. */
#include "types.h"
#include "deps/0212481c_func_0212481c.h"

void func_0212481c(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
                  int param_7,undefined4 param_8,int param_9)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int local_28;
  char local_24 [16];
  
  puVar2 = (ushort *)
           CellBank_GetMetatileEntry(param_2,*(uint *)(param_5 + param_1 * 8 + 0xc) & 0xffff);
  iVar3 = CellBank_GetMetatileEntry(param_8,*(uint *)(param_9 + param_7 * 8 + 0xc) & 0xffff);
  uVar1 = *puVar2;
  iVar6 = 0;
  pcVar5 = local_24;
  local_28 = 0;
  do {
    *pcVar5 = '\0';
    pcVar5 = pcVar5 + 1;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0x10);
  iVar6 = local_28;
  if (uVar1 != 0) {
    do {
      iVar4 = *(int *)(puVar2 + 2) + iVar6;
      uVar9 = (uint)*(ushort *)(iVar4 + 4);
      iVar7 = (*(ushort *)(*(int *)(iVar3 + 4) + iVar6 + 4) & uRam02124964) << 5;
      iVar8 = (uint)*(byte *)(((*(ushort *)(*(int *)(puVar2 + 2) + iVar6) & uRam0212496c) >> 0xe) *
                              4 + iRam02124970 +
                                  (((uint)*(ushort *)(iVar4 + 2) << 0x10 & uRam02124968) >> 0x1e)) *
              0x20;
      iVar4 = *(int *)(param_3 + 0x14) + (uVar9 & uRam02124964) * 0x20;
      Arm_FlushRange(iVar4,iVar8);
      if (param_6 == 0) {
        AllocateReserveTEQSub(0x13,iVar7,iVar4,iVar8);
      }
      else {
        AllocateReserveTEQSub(0x23,iVar7,iVar4,iVar8);
      }
      uVar9 = (uVar9 & uRam02124974) >> 0xc;
      local_24[uVar9] = '\x01';
      iVar4 = *(int *)(iVar3 + 4) + iVar6;
      *(ushort *)(iVar4 + 4) = *(ushort *)(iVar4 + 4) & (ushort)uRam02124978;
      iVar4 = *(int *)(iVar3 + 4) + iVar6;
      *(ushort *)(iVar4 + 4) = *(ushort *)(iVar4 + 4) | (ushort)(uVar9 << 0xc);
      local_28 = local_28 + 1;
      iVar6 = iVar6 + 6;
    } while (local_28 < (int)(uint)uVar1);
  }
  iVar6 = 0;
  iVar3 = 0;
  iVar4 = 0;
  pcVar5 = local_24;
  do {
    if ((*pcVar5 == '\0') || (0xe < iVar6 + iVar3)) {
      if (iVar3 < 1) {
        iVar6 = iVar4 + 1;
      }
      else {
        iVar6 = iVar6 * 0x20;
        iVar7 = *(int *)(param_4 + 0xc) + iVar6;
        if (param_6 == 0) {
          AllocateReserveTEQSub(0xe,iVar6,iVar7,iVar3 << 5);
        }
        else {
          AllocateReserveTEQSub(0x1e,iVar6,iVar7,iVar3 << 5);
        }
        iVar6 = iVar4 + 1;
        iVar3 = 0;
      }
    }
    else {
      iVar3 = iVar3 + 1;
    }
    pcVar5 = pcVar5 + 1;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x10);
  return;
}

