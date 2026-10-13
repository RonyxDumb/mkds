/* Decompiled C draft; module arm9_ov003; ROM address 021d1e14. No matching claim. */
#include "types.h"
#include "deps/021d1e14_FUN_021d1e14.h"

void FUN_021d1e14(undefined4 param_1,int param_2)

{
  int iVar1;
  byte local_18 [4];
  char local_14 [8];
  
  local_18[0] = *DAT_021d1ecc;
  local_18[1] = DAT_021d1ecc[1];
  local_18[2] = DAT_021d1ecc[2];
  local_18[3] = DAT_021d1ecc[3];
  local_14[0] = *DAT_021d1ed0;
  local_14[1] = DAT_021d1ed0[1];
  local_14[2] = DAT_021d1ed0[2];
  local_14[3] = DAT_021d1ed0[3];
  *(short *)(param_2 + 4) = *(short *)(param_2 + 4) + 1;
  iVar1 = func_0x02147d30((int)*(short *)(param_2 + 4) << 4,*(undefined2 *)(param_2 + 6));
  if ((local_18[*(byte *)(param_2 + 8)] & 1) != 0) {
    iVar1 = 0x10 - iVar1;
  }
  if ((local_18[*(byte *)(param_2 + 8)] & 0x10) != 0) {
    iVar1 = -iVar1;
  }
  if (param_2 == *DAT_021d1ed4) {
    func_0x0214a348((ushort *)(uintptr_t)(DAT_021d1ed8),iVar1);
  }
  else {
    func_0x0214a348((ushort *)(uintptr_t)(DAT_021d1edc),iVar1);
  }
  if ((int)(uint)*(ushort *)(param_2 + 6) <= (int)*(short *)(param_2 + 4)) {
    if (param_2 == *DAT_021d1ed4) {
      func_0x0214a348((ushort *)(uintptr_t)(DAT_021d1ed8),(int)local_14[*(byte *)(param_2 + 8)]);
    }
    else {
      func_0x0214a348((ushort *)(uintptr_t)(DAT_021d1edc),(int)local_14[*(byte *)(param_2 + 8)]);
    }
    *(undefined1 *)(param_2 + 9) = 0;
    FUN_021d34c8(1,param_1);
  }
  return;
}

