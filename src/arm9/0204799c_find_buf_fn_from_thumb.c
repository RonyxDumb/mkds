/* Decompiled C draft; module arm9; ROM address 0204799c. No matching claim. */
#include "types.h"
#include "deps/0204799c_find_buf_fn_from_thumb.h"

int find_buf_fn_from_thumb(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FormatGetPathMountBuffer_from_thumb(*(undefined4 *)(iRam02047a14 + 0x14),(char *)(uintptr_t)(param_1));
  if (iVar1 == 0) {
    if (*(int *)(*piRam02047a18 + iRam02047a1c) != 0) {
      iVar1 = FormatGetPathMountBuffer_from_thumb(*(undefined4 *)(iRam02047a14 + 0x24),(char *)(uintptr_t)(param_1));
    }
  }
  iVar2 = GetCurrentSceneId();
  if (iVar2 == 2) {
    if ((iVar1 == 0) && (*(int *)(*piRam02047a18 + iRam02047a20) != 0)) {
      iVar1 = FormatGetPathMountBuffer_from_thumb(*(undefined4 *)(iRam02047a14 + 0x2c),(char *)(uintptr_t)(param_1));
    }
    if ((iVar1 == 0) && (*(int *)(*piRam02047a18 + iRam02047a24) != 0)) {
      iVar1 = FormatGetPathMountBuffer_from_thumb(*(undefined4 *)(iRam02047a14 + 0x30),(char *)(uintptr_t)(param_1));
    }
  }
  return iVar1;
}

