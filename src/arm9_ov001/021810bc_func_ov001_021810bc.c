/* Decompiled C draft; module arm9_ov001; ROM address 021810bc. No matching claim. */
#include "types.h"
#include "deps/021810bc_func_ov001_021810bc.h"

undefined4 func_ov001_021810bc(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 local_18;
  
  iVar2 = 0;
  local_18 = 0;
  piVar1 = (int *)*piRam02181120;
  if (0 < *piVar1 * *piVar1) {
    do {
      if (((int)(uint)*(byte *)(param_1 + iVar2) < piVar1[2]) &&
         ((ushort)*(byte *)(piVar1[8] + iVar2) !=
          (*(ushort *)(param_2 + (uint)*(byte *)(param_1 + iVar2) * 2) & 0xff))) {
        local_18 = 1;
        func_ov001_021811c8();
        *(char *)(*(int *)(*piRam02181120 + 0x20) + iVar2) =
             (char)*(undefined2 *)(param_2 + (uint)*(byte *)(param_1 + iVar2) * 2);
      }
      iVar2 = iVar2 + 1;
      piVar1 = (int *)*piRam02181120;
    } while (iVar2 < *piVar1 * *piVar1);
  }
  return local_18;
}

