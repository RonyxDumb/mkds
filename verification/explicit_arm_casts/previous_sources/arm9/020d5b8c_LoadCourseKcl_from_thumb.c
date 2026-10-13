/* Decompiled C draft; module arm9; ROM address 020d5b8c. No matching claim. */
#include "types.h"
#include "deps/020d5b8c_LoadCourseKcl_from_thumb.h"

void LoadCourseKcl_from_thumb(void)

{
  undefined4 uVar1;
  
  uVar1 = FindFileBuffer_CRS_CST_from_thumb(uRam020d5ba4);
  CopyKclHeaderAbsolute_from_thumb(uRam020d5ba8,uVar1);
  return;
}

