/* Decompiled C draft; module arm9; ROM address 020566a8. No matching claim. */
#include "types.h"
#include "deps/020566a8_func_020566a8.h"

void func_020566a8(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(*piRam020566f8 + 0x18);
  *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) & 0xfffffffe | 1;
  Mem_CpuCopy8(param_2,uVar2,uRam020566fc);
  WriteSaveDataSection_DownloadGhost_from_thumb(param_1,uVar2);
  iVar1 = func_020573c8(param_1);
  if (iVar1 == 0) {
    MaybeSetPersonalGhostForCoursePresent_from_thumb(param_1,*(int *)*piRam020566f8 + 0x2a,2);
    WriteSaveDataHeader_from_thumb();
  }
  return;
}

