/* Decompiled C draft; module arm9_ov001; ROM address 02187cd4. No matching claim. */
#include "types.h"
#include "deps/02187cd4_FUN_02187cd4.h"

void FUN_02187cd4(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  *(undefined4 *)(param_1 + DAT_02187d04) = param_2;
  *(undefined4 *)(param_1 + DAT_02187d08) = 3;
  piVar1 = (int *)(param_1 + DAT_02187d0c);
  *(int *)(*(int *)(*piVar1 + 0x10) + 0x2c) = param_1;
  func_0x020109c4(*(undefined4 *)(*piVar1 + 0x10),DAT_02187d10,0,6,3);
  return;
}

