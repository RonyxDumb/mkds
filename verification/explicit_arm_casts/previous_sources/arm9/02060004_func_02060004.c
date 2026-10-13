/* Decompiled C draft; module arm9; ROM address 02060004. No matching claim. */
#include "types.h"
#include "deps/02060004_func_02060004.h"

void func_02060004(undefined4 param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined1 auStack_40 [36];
  
  uVar2 = GetCourseIdFromInternalId();
  if (uVar2 == 0xffffffff) {
    return;
  }
  iVar3 = MaybeHasPersonalGhostForCourse_from_thumb(uVar2 & 0xff);
  if (iVar3 != 0) {
    func_020573e0(uVar2 & 0xff);
  }
  bVar1 = 0;
  do {
    Mem_CpuFill8(auStack_40,0,0x20);
    TimeTrialCopyToSaveData_from_thumb(param_1,bVar1,auStack_40);
    bVar1 = bVar1 + 1;
  } while (bVar1 < 6);
  if (iVar3 == 0) {
    WriteTimeTrialsSaveDataSection_from_thumb();
    return;
  }
  WriteTimeTrialsSaveDataSectionAndHeader_from_thumb();
  return;
}

