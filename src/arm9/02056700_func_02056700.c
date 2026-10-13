/* Decompiled C draft; module arm9; ROM address 02056700. No matching claim. */
#include "types.h"
#include "deps/02056700_func_02056700.h"

void func_02056700(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  bVar1 = false;
  uVar2 = GetCourseIdFromInternalId();
  iVar4 = *(int *)(*piRam0205674c + 0x14);
  if (uVar2 == 0xffffffff) {
    bVar1 = true;
  }
  else {
    iVar3 = MaybeHasPersonalGhostForCourse_from_thumb(uVar2 & 0xff);
    if (iVar3 == 0) {
      bVar1 = true;
    }
  }
  if (bVar1) {
    *(uint *)(iVar4 + 8) = *(uint *)(iVar4 + 8) & 0xfffffffe;
    return;
  }
  ReadSaveDataSection_PersonalGhost_from_thumb(uVar2 & 0xff,iVar4);
  return;
}

