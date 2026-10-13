/* Decompiled C draft; module arm9; ROM address 020476ac. No matching claim. */
#include "types.h"
#include "deps/020476ac_func_020476ac.h"

void func_020476ac(void)

{
  undefined4 uVar1;
  
  uVar1 = GetCurrentSceneId();
  Arc_DisposeArchive_from_thumb(10);
  SetActiveExecutionContextHeapGroupId_from_thumb(0);
  Arc_MountArchive_from_thumb(1,uVar1);
  Arc_MountArchive_from_thumb(5,uVar1);
  Arc_MountArchive_from_thumb(0xe,uVar1);
  Arc_MountArchive_from_thumb(0x10,uVar1);
  SetActiveExecutionContextHeapGroupId_from_thumb(9);
  return;
}

