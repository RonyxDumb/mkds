/* Decompiled C draft; module arm9; ROM address 02056bc0. No matching claim. */
#include "types.h"
#include "deps/02056bc0_TimeTrialRecord_CopyFrom_from_thumb.h"

bool TimeTrialRecord_CopyFrom_from_thumb(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = GetCourseIdFromInternalId();
  if (iVar1 != -1) {
    TimeTrialRecord_CopyFromImpl_from_thumb
              ((uint *)(uintptr_t)(*(int *)(*piRam02056c04 + 0xc) + 4 + iRam02056c08 * param_2 + iVar1 * 0x1c),(ushort *)(uintptr_t)(param_3));
  }
  else {
    *(undefined1 *)(param_3 + 0x18) = 0;
  }
  return iVar1 != -1;
}

