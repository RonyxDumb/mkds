/* Decompiled C draft; module arm9_ov000; ROM address 02198af4. No matching claim. */
#include "types.h"
#include "deps/02198af4_FUN_02198af4.h"

undefined4 FUN_02198af4(int param_1,int *param_2)

{
  int iVar1;
  
  FUN_0219a01c(*(undefined4 *)(param_1 + 0x50),*param_2 + 5,*(undefined2 *)(param_1 + 0x66));
  iVar1 = FUN_02198714((undefined4 *)(uintptr_t)(param_1),*(int *)(param_1 + 0x50) + *param_2,param_2[1]);
  if (iVar1 == 0) {
    return 0;
  }
  param_2[3] = *(int *)(param_1 + 0x88);
  if (*(char *)(*(int *)(param_1 + 0x50) + *param_2 + 2) == '\x02') {
    *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(param_1 + 0x88);
  }
  return 1;
}

