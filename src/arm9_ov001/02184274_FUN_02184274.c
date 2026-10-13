/* Decompiled C draft; module arm9_ov001; ROM address 02184274. No matching claim. */
#include "types.h"
#include "deps/02184274_FUN_02184274.h"

undefined4 FUN_02184274(int param_1)

{
  int iVar1;
  
  iVar1 = func_0x020d3d48(0);
  if (*(int *)(param_1 + 8) + iVar1 < 0 == SBORROW4(*(int *)(param_1 + 8),-iVar1)) {
    FUN_02187444(param_1,4,0);
    func_0x020d2774(param_1,DAT_021842a8);
    *(undefined4 *)(param_1 + DAT_021842b0) = DAT_021842ac;
  }
  return 0;
}

