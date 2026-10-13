/* Decompiled C draft; module arm9_ov001; ROM address 02181124. No matching claim. */
#include "types.h"
#include "deps/02181124_func_ov001_02181124.h"

undefined4 func_ov001_02181124(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 local_18;
  
  piVar1 = piRam02181170;
  iVar3 = 0;
  local_18 = 0;
  piVar2 = (int *)*piRam02181170;
  if (0 < *piVar2 * *piVar2) {
    do {
      if (*(char *)(piVar2[8] + iVar3) != *(char *)(param_1 + iVar3)) {
        local_18 = 1;
        func_ov001_021811c8();
        *(undefined1 *)(*(int *)(*piVar1 + 0x20) + iVar3) = *(undefined1 *)(param_1 + iVar3);
      }
      iVar3 = iVar3 + 1;
      piVar2 = (int *)*piVar1;
    } while (iVar3 < *piVar2 * *piVar2);
  }
  return local_18;
}

