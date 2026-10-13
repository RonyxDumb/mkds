/* Decompiled C draft; module arm9_ov000; ROM address 021a9200. No matching claim. */
#include "types.h"
#include "deps/021a9200_FUN_021a9200.h"

void FUN_021a9200(undefined1 param_1)

{
  int iVar1;
  
  func_0x02000b44(DAT_021a9220);
  iVar1 = *(int *)(*(int *)(DAT_021a9224 + 4) + 0xa4);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 9) = param_1;
  }
  return;
}

