/* Decompiled C draft; module arm9; ROM address 02060268. No matching claim. */
#include "types.h"
#include "deps/02060268_CourseTimeTrialRecordsEmpty.h"

undefined4 CourseTimeTrialRecordsEmpty(undefined4 param_1)

{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  undefined1 auStack_40 [24];
  char cStack_28;
  
  uVar3 = GetCourseIdFromInternalId();
  if (uVar3 == 0xffffffff) {
    return 1;
  }
  iVar4 = MaybeHasPersonalGhostForCourse_from_thumb(uVar3 & 0xff);
  if (iVar4 != 0) {
    bVar2 = 0;
    while( true ) {
      iVar4 = TimeTrialRecord_CopyFrom_from_thumb(param_1,bVar2,auStack_40);
      if ((iVar4 == 0) || (bVar1 = true, cStack_28 == '\0')) {
        bVar1 = false;
      }
      if (bVar1) break;
      bVar2 = bVar2 + 1;
      if (5 < bVar2) {
        return 1;
      }
    }
    return 0;
  }
  return 1;
}

