/* Decompiled C draft; module arm9_ov000; ROM address 02197d20. No matching claim. */
#include "types.h"
#include "deps/02197d20_FUN_02197d20.h"

void FUN_02197d20(int *param_1,int param_2,int param_3)

{
  if (param_2 == -1) {
    param_2 = param_1[2] - param_3;
  }
  if (param_1[2] < param_2) {
    func_0x0213442c(DAT_02197d78,DAT_02197d7c,0,0x4f);
  }
  if (param_1[2] - param_2 < param_3) {
    func_0x0213442c(DAT_02197d80,DAT_02197d7c,0,0x50);
  }
  func_0x02134df8((uint *)(uintptr_t)(*param_1 + param_2),(uint *)(uintptr_t)(*param_1 + param_2 + param_3),(param_1[2] - param_2) - param_3);
  param_1[2] = param_1[2] - param_3;
  return;
}

