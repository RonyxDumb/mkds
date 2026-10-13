/* Decompiled C draft; module arm9; ROM address 02056fdc. No matching claim. */
#include "types.h"
#include "deps/02056fdc_Task_ReadNonGhostSaveData_from_thumb.h"

void Task_ReadNonGhostSaveData_from_thumb(void)

{
  int *piVar1;
  int iVar2;
  ushort uVar3;
  
  piVar1 = piRam02057124;
  uVar3 = 0;
  *(undefined4 *)(*piRam02057124 + 0x2c) = 0;
  ReadSaveDataSection_Header_from_thumb(*(undefined4 *)*piVar1);
  if (*(int *)(*piRam02057128 + 0xc) != 0) {
    func_02145d38();
  }
  piVar1 = piRam02057124;
  if (*(int *)(*piRam02057128 + 4) != 0) {
    if (*(int *)(*piRam02057128 + 4) == 4) {
      *(short *)(*piRam02057124 + 0x2a) = (short)uRam0205712c;
      *(undefined4 *)(*piVar1 + 0x2c) = 4;
      ResetSaveDataHolderTaskPendingFlag_from_thumb();
      return;
    }
    uVar3 = 1;
  }
  ReadSaveDataSection_Emblem_from_thumb(*(undefined4 *)(*piRam02057124 + 4));
  if (*(int *)(*piRam02057128 + 0xc) != 0) {
    func_02145d38();
  }
  if (*(int *)(*piRam02057128 + 4) != 0) {
    uVar3 = uVar3 | 2;
  }
  ReadSaveDataSection_GrandPrix_from_thumb(*(undefined4 *)(*piRam02057124 + 8));
  if (*(int *)(*piRam02057128 + 0xc) != 0) {
    func_02145d38();
  }
  if (*(int *)(*piRam02057128 + 4) != 0) {
    uVar3 = uVar3 | 4;
  }
  ReadSaveDataSection_TimeTrial_from_thumb(*(undefined4 *)(*piRam02057124 + 0xc));
  if (*(int *)(*piRam02057128 + 0xc) != 0) {
    func_02145d38();
  }
  if (*(int *)(*piRam02057128 + 4) != 0) {
    uVar3 = uVar3 | 8;
  }
  ReadSaveDataSection_MissionRun_from_thumb(*(undefined4 *)(*piRam02057124 + 0x10));
  if (*(int *)(*piRam02057128 + 0xc) != 0) {
    func_02145d38();
  }
  if (*(int *)(*piRam02057128 + 4) != 0) {
    uVar3 = uVar3 | 0x10;
  }
  ReadSaveDataSection_FriendList_from_thumb(*(undefined4 *)(*piRam02057124 + 0x20));
  if (*(int *)(*piRam02057128 + 0xc) != 0) {
    func_02145d38();
  }
  if (*(int *)(*piRam02057128 + 4) != 0) {
    uVar3 = uVar3 | 0x20;
  }
  iVar2 = *piRam02057124;
  if (*(int *)(iVar2 + 0x2c) == 0) {
    if (uVar3 == 0) {
      *(undefined4 *)(iVar2 + 0x2c) = 0;
    }
    else {
      *(undefined4 *)(iVar2 + 0x2c) = 3;
    }
  }
  *(ushort *)(*piRam02057124 + 0x2a) = uVar3;
  ResetSaveDataHolderTaskPendingFlag_from_thumb();
  return;
}

