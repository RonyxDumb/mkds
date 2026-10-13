/* Decompiled C draft; module arm9_ov001; ROM address 02188260. No matching claim. */
#include "types.h"
#include "deps/02188260_FUN_02188260.h"

undefined4 FUN_02188260(int param_1)

{
  if (*(int *)(*DAT_021882b4 + 8) == 4) {
    func_ov001_021817e0();
  }
  *(int *)(param_1 + 0xac) = *(int *)(param_1 + 0xac) + 1;
  if (**(int **)(param_1 + 0xa0) <= *(int *)(param_1 + 0xac)) {
    *(int *)(param_1 + 0xac) = **(int **)(param_1 + 0xa0);
    if (*(int *)(*DAT_021882b4 + 8) == 4) {
      func_0x020a12b8();
    }
    return 1;
  }
  return 0;
}

