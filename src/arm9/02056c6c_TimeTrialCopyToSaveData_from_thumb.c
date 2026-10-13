/* Decompiled C draft; module arm9; ROM address 02056c6c. No matching claim. */
#include "types.h"
#include "deps/02056c6c_TimeTrialCopyToSaveData_from_thumb.h"

void TimeTrialCopyToSaveData_from_thumb(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = GetCourseIdFromInternalId();
  if (iVar1 != -1) {
    TimeTrialRecordCopyTo_from_thumb
              ((uint *)(uintptr_t)(*(int *)(*piRam02056ca4 + 0xc) + 4 + iRam02056ca8 * param_2 + iVar1 * 0x1c),(ushort *)(uintptr_t)(param_3));
  }
  return;
}

